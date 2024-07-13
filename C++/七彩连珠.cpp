////////////////////////////////////////////
// 程序：七彩连珠
// 作者：古风<394527551@qq.com>
// 编译环境：Visual Studio 2022，EasyX_20220901
// 编写日期：2023-5-16
#include <graphics.h>
#include <ctime>
#include <conio.h>
const int MAX_VERTEX_NUM = 81;

// 彩球属性
struct Ball
{
	COLORREF color;	// 彩球颜色
	int		num;	// 编号
	int		x;		// 位置 x
	int		y; 		// 位置 y
};

// 图属性
struct Graph
{
	int				vertexnum;									// 顶点数
	unsigned short vertex[MAX_VERTEX_NUM];						// 所有顶点
	unsigned short weight[MAX_VERTEX_NUM][MAX_VERTEX_NUM];		// 权
	unsigned short shortpath[MAX_VERTEX_NUM][MAX_VERTEX_NUM];	// 最短路径
	unsigned short matrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];		// 顶点矩阵
};

class Border
{
private:
	static const int GRAP_WIDTH		= 490;
	static const int GRAP_HEIGHT	= 336;
public:
	static const int BORDER_WIDTH	= 315; 									// 游戏界面宽度
	static const int BORDER_HEIGHT	= BORDER_WIDTH; 						// 游戏界面高度
	static const int UNIT_RECT_SIZE = BORDER_WIDTH / 9; 					// 单元格大小
	static const int BORDER_START_X = (GRAP_HEIGHT - BORDER_HEIGHT) / 2;	// 游戏界面开始位置 x
	static const int BORDER_START_Y = BORDER_START_X; 						// 游戏界面开始位置 y

	void drawBorder(); // 画游戏界面
};

class QiCaiLianZhu
{
private:
	const COLORREF SHADE_COLOR = RGB(128, 128, 105);	// 小球阴影颜色
	static const int COLOR_NUM = 7;						// 小球颜色总数
	static const int ROW = 9;							// 棋盘行数
	static const int COL = ROW;							// 棋盘列数
	const	int MAX_VALUE = 65535;
	int		curballcounter;								// 当前棋盘上剩余球的数量即空格数
	int		curcolornum;								// 当前颜色种数
	int		v1;											// 用来标记起始位置的球
	int		score;										// 得分
	int		removeballnum;								// 相同颜色连成一条线球的数量
	int		allball[MAX_VERTEX_NUM];					// 所有球的编号
	Ball	ball[ROW][COL], b;
	Ball	removeball[9];
	Graph* g;
	COLORREF nextcolor[3];
	COLORREF ballcolor[COLOR_NUM];

	void addEdge(int v1, int v2, const int weig);		// 添加边
	void createGraph();									// 创建图
	void delEdge(int v1, int v2);
	void delEdge(int vertex);							// 删除边
	void searchShortPath();								// 搜索两点间的最短路径
	bool searchRemoveBall(Ball bal);					// 查找是否有消除的小球
	void removeBall();									// 擦除小球
	void removeAddEdge(int vertex);						// 添加擦除小球后该位置的边
	bool isMoveBall(int start, int endd);
	Ball getBall(int num);								// 返回编号 num 的小球
	bool printBall();									// 随机打印三个小球
	void drawBall(const COLORREF color, const int x, const int y)
	{
		setlinecolor(SHADE_COLOR);						// 设置小球的阴影颜色
		setfillcolor(SHADE_COLOR);
		for (int i = 1; i <= 2; i++)					// 画小球的阴影部分
			fillcircle(x + i, y + i, Border::UNIT_RECT_SIZE / 2 - 5);
		setlinecolor(color);
		setfillcolor(color);
		fillcircle(x, y, Border::UNIT_RECT_SIZE / 2 - 5);
		FlushBatchDraw();
	}
public:
	QiCaiLianZhu();
	void startGame();
	~QiCaiLianZhu()
	{
		delete g;
	}
};

// 画界面
void Border::drawBorder()
{
	initgraph(GRAP_WIDTH, GRAP_HEIGHT);
	BeginBatchDraw();
	setbkcolor(RGB(235, 142, 85));
	cleardevice();

	setfillcolor(RGB(190, 190, 190));
	solidrectangle(BORDER_START_X, BORDER_START_Y, BORDER_START_X + BORDER_WIDTH, BORDER_START_Y + BORDER_HEIGHT);
	setlinecolor(RGB(128, 158, 80));
	for (size_t i = 0; i < 8; i++)
		line(BORDER_START_X, BORDER_START_Y + UNIT_RECT_SIZE * (i + 1),
			BORDER_START_X + BORDER_WIDTH, BORDER_START_Y + UNIT_RECT_SIZE * (i + 1));
	for (size_t i = 0; i < 8; i++)
		line(BORDER_START_X + UNIT_RECT_SIZE * (i + 1), BORDER_START_Y,
			BORDER_START_X + UNIT_RECT_SIZE * (i + 1), BORDER_START_Y + BORDER_HEIGHT);

	settextcolor(BLACK);
	settextstyle(20, 0, _T("宋体"));
	outtextxy(BORDER_START_X + BORDER_WIDTH + 20, BORDER_START_Y, _T("得分:"));
	setlinecolor(RGB(190, 190, 190));
	setfillcolor(RGB(190, 190, 190));
	solidrectangle(BORDER_START_X + BORDER_WIDTH + 20, BORDER_START_Y + 25,
		BORDER_START_X + BORDER_WIDTH + 20 + 120, BORDER_START_Y + 25 + 28);
	settextcolor(RGB(139, 26, 26));
	setbkmode(TRANSPARENT);
	outtextxy(BORDER_START_X + BORDER_WIDTH + 30, BORDER_START_Y + 30, _T("0"));

	settextcolor(BLACK);
	settextstyle(20, 0, _T("宋体"));
	outtextxy(BORDER_START_X + BORDER_WIDTH + 20, BORDER_START_Y + 70, _T("当前颜色数:"));
	setlinecolor(RGB(190, 190, 190));
	setfillcolor(RGB(190, 190, 190));
	solidrectangle(BORDER_START_X + BORDER_WIDTH + 20, BORDER_START_Y + 70 + 25,
		BORDER_START_X + BORDER_WIDTH + 20 + 120, BORDER_START_Y + 70 + 25 + 28);

	settextcolor(BLACK);
	settextstyle(30, 0, _T("宋体"));
	outtextxy(BORDER_START_X + BORDER_WIDTH + 20, 210, _T("下一组"));
	setfillcolor(RGB(190, 190, 190));
	fillcircle(BORDER_START_X + BORDER_WIDTH + 40, 275, 23);
	solidrectangle(BORDER_START_X + BORDER_WIDTH + 40, 252, BORDER_START_X + BORDER_WIDTH + 40 + 80, 298);
	fillcircle(BORDER_START_X + BORDER_WIDTH + 40 + 80, 275, 23);
}

// 默认构造函数用于初始化游戏数据
QiCaiLianZhu::QiCaiLianZhu()
{
	ballcolor[0] = RGB(0, 0, 255);		// 蓝色
	ballcolor[1] = RGB(0, 255, 255);	// 青色
	ballcolor[2] = RGB(0, 255, 0);		// 绿色
	ballcolor[3] = RGB(255, 0, 0);		// 红色
	ballcolor[4] = RGB(255, 0, 255);	// 深红色
	ballcolor[5] = RGB(255, 255, 0);	// 黄色
	ballcolor[6] = RGB(160, 82, 45);	// 赤色
	g = new Graph;
	curballcounter = MAX_VERTEX_NUM;
	curcolornum = 3;
	removeballnum = 0;
	score = 0;
	v1 = -1;
	createGraph();
	TCHAR colornum[2];
	_itot_s(curcolornum, colornum, 10);
	settextstyle(20, 0, _T("宋体"));
	settextcolor(RGB(139, 26, 26));
	outtextxy(Border::BORDER_START_X + Border::BORDER_WIDTH + 30, Border::BORDER_START_Y + 70 + 30, colornum);
	int i, j, k;
	// 初始化棋盘
	for (i = 0; i < 9; i++)
		for (j = i * 9, k = 0; j < i * 9 + 9; j++, k++)
		{
			ball[i][k].num = j;
			ball[i][k].x = k;
			ball[i][k].y = i;
			ball[i][k].color = BLACK;
		}
	for (i = 0; i < MAX_VERTEX_NUM; i++)
		allball[i] = i; // 初始化所有小球编号
	srand((unsigned)time(nullptr));
	for (i = 0; i < 3; i++)
	{
		drawBall(ballcolor[rand() % curcolornum], Border::BORDER_START_X + Border::BORDER_WIDTH + 40 * (i + 1), 275);
		nextcolor[i] = ballcolor[rand() % curcolornum];
	}
	printBall();
}

// 删除边
void QiCaiLianZhu::delEdge(int v1, int v2)
{
	size_t i, j;
	for (i = 0; v1 != g->vertex[i] && i < g->vertexnum; i++);
	for (j = 0; v2 != g->vertex[j] && j < g->vertexnum; j++);
	g->matrix[i][j] = MAX_VALUE;
}
void QiCaiLianZhu::delEdge(int vertex)
{
	if (vertex == 0)						// 左上角
	{
		delEdge(9, vertex);
		delEdge(1, vertex);
	}
	else if (vertex >= 1 && vertex <= 7)	// 上边
	{
		delEdge(vertex + 1, vertex);
		delEdge(vertex - 1, vertex);
		delEdge(vertex + 9, vertex);
	}
	else if (vertex == 8)					// 右上角
	{
		delEdge(7, vertex);
		delEdge(17, vertex);
	}
	else if (vertex >= 9 && vertex <= 71)	// 左边
	{
		delEdge(vertex + 1, vertex);
		delEdge(vertex - 1, vertex);
		delEdge(vertex + 9, vertex);
		delEdge(vertex - 9, vertex);
	}
	else if (vertex == 72)					// 左下角
	{
		delEdge(63, vertex);
		delEdge(73, vertex);
	}
	else if (vertex >= 73 && vertex <= 79)	// 右边
	{
		delEdge(vertex + 1, vertex);
		delEdge(vertex - 1, vertex);
		delEdge(vertex - 9, vertex);
	}
	else									// 右下角(80)
	{
		delEdge(71, vertex);
		delEdge(79, vertex);
	}
}

// 添加边
void QiCaiLianZhu::addEdge(int v1, int v2, const int weig)
{
	size_t i, j;
	for (i = 0; v1 != g->vertex[i] && i < g->vertexnum; i++);
	for (j = 0; v2 != g->vertex[j] && j < g->vertexnum; j++);
	g->matrix[i][j] = weig;
}

// 创建图
void QiCaiLianZhu::createGraph()
{
	size_t i, j;
	g->vertexnum = MAX_VERTEX_NUM;
	for (i = 0; i < g->vertexnum; i++)
		g->vertex[i] = i;
	for (i = 0; i < g->vertexnum; i++)
		for (j = 0; j < g->vertexnum; j++)
			g->matrix[i][j] = MAX_VALUE;
	for (i = 0; i < 9; i++)
		for (j = i * 9; j < i * 9 + 8; j++)
		{
			addEdge(j, j + 1, 1);
			addEdge(j + 1, j, 1);
		}
	for (i = 0; i < 9; i++)
		for (j = i; j < i + 72; j += 9)
		{
			addEdge(j, j + 9, 1);
			addEdge(j + 9, j, 1);
		}
}

// 用弗洛伊德算法搜索两点间的最短路径
void QiCaiLianZhu::searchShortPath()
{
	size_t i, j, k;

	for (i = 0; i < g->vertexnum; i++)
		for (j = 0; j < g->vertexnum; j++)
		{
			g->weight[i][j] = g->matrix[i][j];
			g->shortpath[i][j] = j;
		}
	for (i = 0; i < g->vertexnum; i++)
		for (j = 0; j < g->vertexnum; j++)
			for (k = 0; k < g->vertexnum; k++)
				if (g->weight[j][k] > g->weight[j][i] + g->weight[i][k])
				{
					g->weight[j][k] = g->weight[j][i] + g->weight[i][k];
					g->shortpath[j][k] = g->shortpath[j][i];
				}
}

// 是否移动成功，即两点间是否连通，连通返回：true，否则返回：false
bool QiCaiLianZhu::isMoveBall(int start, int endd)
{
	size_t i, j, k;
	bool connected = false; // 两点间是否连通标志
	Ball b1;

	searchShortPath();
	for (i = 0; start != g->vertex[i] && i < g->vertexnum; i++);
	for (j = 0; endd != g->vertex[j] && j < g->vertexnum; j++);
	k = g->shortpath[i][j];
	while (k != j)
	{
		connected = true;
		k = g->shortpath[k][j];
	}
	if (connected || g->matrix[i][j] == 1)
	{
		setfillcolor(RGB(235, 142, 85));
		solidrectangle(343, 160, 480, 190);	// 有路径连通擦除之前的提示
		b1 = getBall(start);
		setfillcolor(RGB(190, 190, 190));
		solidrectangle(Border::BORDER_START_X + Border::UNIT_RECT_SIZE * b1.x + 1,
			Border::BORDER_START_Y + Border::UNIT_RECT_SIZE * b1.y + 1,
			Border::BORDER_START_X + Border::UNIT_RECT_SIZE * b1.x + Border::UNIT_RECT_SIZE - 1,
			Border::BORDER_START_Y + Border::UNIT_RECT_SIZE * b1.y + Border::UNIT_RECT_SIZE - 1);
		ball[b1.y][b1.x].color = BLACK;
		allball[curballcounter++] = b1.num;
		removeAddEdge(b1.num);
		FlushBatchDraw();
		Sleep(50);
		k = g->shortpath[i][j];
		b = getBall(k);
		while (k != j) // 开始将小球移动到目标位置
		{
			drawBall(b1.color, Border::BORDER_START_X + Border::UNIT_RECT_SIZE * b.x + Border::UNIT_RECT_SIZE / 2,
				Border::BORDER_START_Y + Border::UNIT_RECT_SIZE * b.y + Border::UNIT_RECT_SIZE / 2);
			FlushBatchDraw();
			Sleep(50);
			setfillcolor(RGB(190, 190, 190));
			solidrectangle(Border::BORDER_START_X + Border::UNIT_RECT_SIZE * b.x + 1,
				Border::BORDER_START_Y + Border::UNIT_RECT_SIZE * b.y + 1,
				Border::BORDER_START_X + Border::UNIT_RECT_SIZE * b.x + Border::UNIT_RECT_SIZE - 1,
				Border::BORDER_START_Y + Border::UNIT_RECT_SIZE * b.y + Border::UNIT_RECT_SIZE - 1);
			FlushBatchDraw();
			k = g->shortpath[k][j];
			b = getBall(k);
		}
		b = getBall(endd);
		drawBall(b1.color, Border::BORDER_START_X + Border::UNIT_RECT_SIZE * b.x + Border::UNIT_RECT_SIZE / 2,
			Border::BORDER_START_Y + Border::UNIT_RECT_SIZE * b.y + Border::UNIT_RECT_SIZE / 2);
		ball[b.y][b.x].color = b.color = b1.color;
		for (i = 0; i < curballcounter; i++)
			if (allball[i] == b.num)
			{
				allball[i] = allball[--curballcounter];
				break;
			}
		delEdge(b.num);
		v1 = -1;
		FlushBatchDraw();
		Sleep(100);
		if (!searchRemoveBall(b))
		{
			if (!printBall())
				return false;
		}
		b.color = BLACK;
	}
	else
	{
		settextstyle(25, 0, _T("宋体"));
		outtextxy(343, 160, _T(" 无路径"));
	}
	return true;
}

// 返回编号为 num 的小球属性
Ball QiCaiLianZhu::getBall(int num)
{
	for (size_t j = 0; j < 9; j++)
		for (size_t k = 0; k < 9; k++)
			if (ball[j][k].num == num)
				return ball[j][k];
}

// 添加移除小球后，小球所在顶点的边，让其它球可以移动到此处
void QiCaiLianZhu::removeAddEdge(int vertex)
{
	if (vertex == 0)						// 棋盘左上角
	{
		addEdge(9, vertex, 1);
		addEdge(1, vertex, 1);
	}
	else if (vertex == 8)					// 棋盘右上角
	{
		addEdge(7, vertex, 1);
		addEdge(17, vertex, 1);
	}
	else if (vertex == 72)					// 左下角
	{
		addEdge(63, vertex, 1);
		addEdge(73, vertex, 1);
	}
	else if (vertex == 80)					// 右下角
	{
		addEdge(79, vertex, 1);
		addEdge(71, vertex, 1);
	}
	else if (vertex >= 1 && vertex <= 7)	// 上边
	{
		addEdge(vertex + 1, vertex, 1);
		addEdge(vertex - 1, vertex, 1);
		addEdge(vertex + 9, vertex, 1);
	}
	else if (vertex % 9 == 0)				// 左边
	{
		addEdge(vertex + 9, vertex, 1);
		addEdge(vertex - 9, vertex, 1);
		addEdge(vertex + 1, vertex, 1);
	}
	else if (vertex >= 73 && vertex <= 79)	// 下边
	{
		addEdge(vertex + 1, vertex, 1);
		addEdge(vertex - 1, vertex, 1);
		addEdge(vertex - 9, vertex, 1);
	}
	else if (vertex == 17 || vertex == 26 || vertex == 35 ||
		vertex == 44 || vertex == 53 || vertex == 62 || vertex == 71) // 右边
	{
		addEdge(vertex + 9, vertex, 1);
		addEdge(vertex - 1, vertex, 1);
		addEdge(vertex - 9, vertex, 1);
	}
	else									// 棋盘除四条边外的空格
	{
		addEdge(vertex + 1, vertex, 1);
		addEdge(vertex - 1, vertex, 1);
		addEdge(vertex + 9, vertex, 1);
		addEdge(vertex - 9, vertex, 1);
	}
}

// 擦除小球，并更新分数，和当前颜色数
void QiCaiLianZhu::removeBall()
{
	for (size_t i = 0; i < removeballnum; i++)
	{
		setfillcolor(RGB(190, 190, 190));
		solidrectangle(Border::BORDER_START_X + Border::UNIT_RECT_SIZE * removeball[i].x + 1,
			Border::BORDER_START_Y + Border::UNIT_RECT_SIZE * removeball[i].y + 1,
			Border::BORDER_START_X + Border::UNIT_RECT_SIZE * removeball[i].x + Border::UNIT_RECT_SIZE - 1,
			Border::BORDER_START_Y + Border::UNIT_RECT_SIZE * removeball[i].y + Border::UNIT_RECT_SIZE - 1);
		ball[removeball[i].y][removeball[i].x].color = BLACK;
		removeAddEdge(removeball[i].num);
		allball[curballcounter++] = removeball[i].num;
	}

	// 更新分数
	score = score + 2 * removeballnum * removeballnum;

	// 更新当前小球颜色种数
	score < 2000 ? curcolornum = 3 : curcolornum < COLOR_NUM ? curcolornum = score / 500 : curcolornum = COLOR_NUM;

	// 更新显示分数
	TCHAR sco[10];
	_itot_s(score, sco, 10);
	setfillcolor(RGB(190, 190, 190));
	solidrectangle(Border::BORDER_START_X + Border::BORDER_WIDTH + 20, Border::BORDER_START_Y + 25,
		Border::BORDER_START_X + Border::BORDER_WIDTH + 20 + 120, Border::BORDER_START_Y + 53);
	settextcolor(RGB(139, 26, 26));
	settextstyle(20, 0, _T("宋体"));
	setbkmode(TRANSPARENT);
	outtextxy(Border::BORDER_START_X + Border::BORDER_WIDTH + 30, Border::BORDER_START_Y + 30, sco);

	// 更新当前颜色种数
	TCHAR colornum[3];
	_itot_s(curcolornum, colornum, 10);
	setfillcolor(RGB(190, 190, 190));
	solidrectangle(Border::BORDER_START_X + Border::BORDER_WIDTH + 20, Border::BORDER_START_Y + 70 + 25,
		Border::BORDER_START_X + Border::BORDER_WIDTH + 20 + 120, Border::BORDER_START_Y + 70 + 25 + 28);
	settextstyle(20, 0, _T("宋体"));
	settextcolor(RGB(139, 26, 26));
	outtextxy(Border::BORDER_START_X + Border::BORDER_WIDTH + 30, Border::BORDER_START_Y + 70 + 30, colornum);
	FlushBatchDraw();
	removeballnum = 0;
}

// 检测是否有相同小球各个方向连线成五个或以上
bool QiCaiLianZhu::searchRemoveBall(Ball bal)
{
	size_t i, j;
	removeballnum = 0;
	for (i = 0; i < 9; i++)
	{
		if (ball[bal.y][i].color == bal.color)
			removeball[removeballnum++] = ball[bal.y][i];
		else if (removeballnum >= 5)
		{
			removeBall(); // 行消除
			return true;
		}
		else
			removeballnum = 0;
	}
	if (removeballnum >= 5)
	{
		removeBall(); // 行消除
		return true;
	}

	removeballnum = 0;
	for (i = 0; i < 9; i++) // 列消除
	{
		if (ball[i][bal.x].color == bal.color)
			removeball[removeballnum++] = ball[i][bal.x];
		else if (removeballnum >= 5)
		{
			removeBall();
			return true;
		}
		else
			removeballnum = 0;
	}
	if (removeballnum >= 5)
	{
		removeBall();
		return true;
	}

	removeballnum = 0;
	for (i = bal.y, j = bal.x; j >= 0 && i >= 0; i--, j--)
	{
		if (ball[i][j].color == bal.color)
			removeball[removeballnum++] = ball[i][j];
		else
			break;
	}
	for (i = bal.y + 1, j = bal.x + 1; i < 9 && j < 9; i++, j++)
	{
		if (ball[i][j].color == bal.color)
			removeball[removeballnum++] = ball[i][j];
		else
			break;
	}
	if (removeballnum >= 5)
	{
		removeBall(); // \斜消除
		return true;
	}

	removeballnum = 0;
	for (i = bal.y, j = bal.x; j >= 0 && i < 9; i++, j--)
	{
		if (ball[i][j].color == bal.color)
			removeball[removeballnum++] = ball[i][j];
		else
			break;
	}
	for (i = bal.y - 1, j = bal.x + 1; i >= 0 && j < 9; i--, j++)
	{
		if (ball[i][j].color == bal.color)
			removeball[removeballnum++] = ball[i][j];
		else
			break;
	}
	if (removeballnum >= 5)
	{
		removeBall(); // /斜消除
		return true;
	}
	return false;
}

// 随机打印三个彩球
bool QiCaiLianZhu::printBall()
{
	Ball bal;
	size_t i, num, index;
	for (i = 0; i < 3; i++)
	{
		index = rand() % curballcounter;
		num = allball[index];
		delEdge(num);
		allball[index] = allball[--curballcounter];
		bal = getBall(num);
		ball[bal.y][bal.x].color = bal.color = nextcolor[i];
		drawBall(nextcolor[i], Border::BORDER_START_X + Border::UNIT_RECT_SIZE / 2 + Border::UNIT_RECT_SIZE * bal.x,
			Border::BORDER_START_Y + Border::UNIT_RECT_SIZE / 2 + Border::UNIT_RECT_SIZE * bal.y);
		Sleep(30);
		searchRemoveBall(bal);
		// 当前剩余球的数量为 0 时游戏结束
		if (curballcounter <= 0)
		{
			settextcolor(RED);
			settextstyle(25, 0, _T("宋体"));
			outtextxy(343, 160, _T("游戏结束"));
			FlushBatchDraw();
			return false;
		}
	}
	for (i = 0; i < 3; i++) // 随机生成下一组小球的颜色
	{
		nextcolor[i] = ballcolor[rand() % curcolornum];
		drawBall(nextcolor[i], Border::BORDER_START_X + Border::BORDER_WIDTH + 40 * (i + 1), 275);
		Sleep(20);
	}
	return true;
}

void QiCaiLianZhu::startGame()
{
	ExMessage mg;
	Ball b1;
	int num = -1, x, y;
	bool f = false;
	b.color = b1.color = BLACK;
	while (true)
	{
		peekmessage(&mg, EX_MOUSE);
		if (mg.lbutton) // 鼠标按下
			f = true;
		if (mg.message == WM_LBUTTONUP && mg.x >= Border::BORDER_START_X && mg.x <= Border::BORDER_START_X + Border::BORDER_WIDTH &&
			mg.y >= Border::BORDER_START_Y && mg.y <= Border::BORDER_START_Y + Border::BORDER_HEIGHT && f)
		{
			x = (mg.x - Border::BORDER_START_X) % Border::UNIT_RECT_SIZE;
			x = mg.x - Border::BORDER_START_X + Border::UNIT_RECT_SIZE - x;
			x = x / Border::UNIT_RECT_SIZE - 1;
			y = (mg.y - Border::BORDER_START_X) % Border::UNIT_RECT_SIZE;
			y = mg.y - Border::BORDER_START_X + Border::UNIT_RECT_SIZE - y;
			y = y / Border::UNIT_RECT_SIZE - 1;
			num = x + y * 9;
			b1 = getBall(num);
			
			if (b1.color != BLACK)		// 设置小球选中状态
			{
				if (b.color != BLACK)	// 选择其它小球时将上一个小球恢复为正常状态
				{
					setfillcolor(RGB(190, 190, 190));
					solidrectangle(Border::BORDER_START_X + Border::UNIT_RECT_SIZE * b.x + 1,
						Border::BORDER_START_Y + Border::UNIT_RECT_SIZE * b.y + 1,
						Border::BORDER_START_X + Border::UNIT_RECT_SIZE * b.x + Border::UNIT_RECT_SIZE - 1,
						Border::BORDER_START_Y + Border::UNIT_RECT_SIZE * b.y + Border::UNIT_RECT_SIZE - 1);

					drawBall(b.color, Border::BORDER_START_X + Border::UNIT_RECT_SIZE * b.x + Border::UNIT_RECT_SIZE / 2,
						Border::BORDER_START_Y + Border::UNIT_RECT_SIZE * b.y + Border::UNIT_RECT_SIZE / 2);
				}
				setfillcolor(RGB(176, 225, 230));
				solidrectangle(Border::BORDER_START_X + Border::UNIT_RECT_SIZE * b1.x + 1,
					Border::BORDER_START_Y + Border::UNIT_RECT_SIZE * b1.y + 1,
					Border::BORDER_START_X + Border::UNIT_RECT_SIZE * b1.x + Border::UNIT_RECT_SIZE - 1,
					Border::BORDER_START_Y + Border::UNIT_RECT_SIZE * b1.y + Border::UNIT_RECT_SIZE - 1);

				drawBall(b1.color, Border::BORDER_START_X + Border::UNIT_RECT_SIZE * b1.x + Border::UNIT_RECT_SIZE / 2,
					Border::BORDER_START_Y + Border::UNIT_RECT_SIZE * b1.y + Border::UNIT_RECT_SIZE / 2);
				v1 = num;
				b = b1;
				setfillcolor(RGB(235, 142, 85));
				solidrectangle(343, 160, 480, 190); // 擦除提示信息
			}
			else if (v1 == -1 || b1.color != BLACK)
			{
				settextstyle(25, 0, _T("宋体"));
				outtextxy(343, 160, _T("请单击彩球"));
			}
			// 开始移动所选择的小球到目标位置，并检测棋盘是否已满，棋盘已满返回 false 游戏结束
			else if (!isMoveBall(v1, num))
				break;
			f = false;
		}
		FlushBatchDraw();
		Sleep(10);
	}
}
int main()
{
	Border border;
	border.drawBorder();
	SetWindowText(GetHWnd(), _T("七彩连珠"));
	QiCaiLianZhu qclz;
	qclz.startGame();
	_getch(); // 游戏结束时，按任意键退出
	EndBatchDraw();
	closegraph();
	return 0;
}
