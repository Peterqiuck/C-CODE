#if 0
#include<graphics.h>
#include<time.h>
#include<deque>
#include<windows.h>
using namespace std;

//bug,如果沿着蛇前进的方向再按前进，系统也会记录这个前进指令，这时如果换其他方向则不能立刻执行，
//但是系统也会记录换向指令，只能等这个前进指令完成,系统才会执行换向指令
#define WIDTH 640//宽度
#define HEIGHT 480//长度
#define SIZE 20//蛇头以及食物大小
#define DELAY 200//蛇移动的速度
//蛇移动方向
enum Direction{
	UP,
	DOWN,
	LEFT,
	RIGHT
};
struct Snake{
	int x;
	int y;
	Direction dir;
};
//食物
struct Food{
	int x;
	int y;
};
//绘制蛇身
void drawSnake(deque<Snake>& snake) {
	setfillcolor(GREEN);
    //遍历蛇身绘制
	for (const auto& body : snake) {
		//用20x20矩形框表示蛇身,左上角和右下角坐标
		fillrectangle(body.x * SIZE, body.y * SIZE, (body.x + 1) * SIZE, (body.y + 1) * SIZE);
	}
	//控制蛇移动的速度
	Sleep(DELAY);
}
//判断游戏是否结束
void ifOver(deque<Snake>& snake) {
	for (auto iter = snake.begin()+1; iter != snake.end(); iter++) {
		if ((snake.front().x == iter->x && snake.front().y == iter->y) //蛇头撞到蛇身
			|| snake.front().x<0 || snake.front().x>=WIDTH/SIZE         //蛇头左右越界
			|| snake.front().y<0 || snake.front().y>=HEIGHT/SIZE   )    //蛇头上下越界
		{
			settextcolor(RED);//设置当前文字颜色
			settextstyle(100, 0, _T("Consolas"));//设置字体样式，指定高度100，宽度0为自适应
			TCHAR endStr[16];
			_stprintf_s(endStr, _T("GAME OVER!!!"));
			outtextxy(WIDTH / SIZE, HEIGHT / SIZE, endStr);//指定位置输出字符串
			Sleep(3000);//设置游戏结束画面停留3s
			closegraph();
			exit(0);//游戏结束直接退出
		}
	}
}
//蛇移动
void moveSnake(deque<Snake>& snake, bool grow = false){
	Snake newHead = snake.front();//获取新蛇头，设置初始位置
	switch (newHead.dir)//判断蛇移动方向
	{
	case UP:newHead.y--;
		break;
	case DOWN:newHead.y++;
		break;
	case LEFT:newHead.x--;
		break;
	case RIGHT:newHead.x++;
	}
	//将新位置作为蛇头,此时蛇身变长
	snake.push_front(newHead);
	//每次移动都要判断游戏是否结束
	ifOver(snake);
	//grow=ture表示吃到了食物，grow=false表示普通移动
	if (!grow){
		//没吃到食物，将蛇身最后一个元素矩形框清除,左上和右下坐标
		clearrectangle(snake.back().x * SIZE, snake.back().y * SIZE, (snake.back().x + 1) * SIZE, (snake.back().y + 1) * SIZE);
		snake.pop_back();
	}
	//绘制蛇身
	drawSnake(snake);
}
//更改蛇的移动方向
void changeDirection(deque<Snake>& snake) {
	ExMessage msg = { 0 };//定义消息变量
	peekmessage(&msg, EX_KEY);//捕获键盘消息
	bool stop = false;
	if (msg.message == WM_KEYDOWN) {
		switch (msg.vkcode) {
		case 'w':
		case VK_UP:
		case 'W':
			if (snake.front().dir != DOWN)
				snake.front().dir = UP;
			break;
		case 's':
		case VK_DOWN:
		case 'S':
			if (snake.front().dir != UP)
				snake.front().dir = DOWN;
			break;
		case 'a':
		case VK_LEFT:
		case 'A':
			if (snake.front().dir != RIGHT)
				snake.front().dir = LEFT;
			break;
		case 'd':
		case VK_RIGHT:
		case 'D':
			if (snake.front().dir != LEFT)
				snake.front().dir = RIGHT;
			break;
		case VK_SPACE:
				system("pause");
				break;	
		}
	}
}
//生成食物，不能在蛇身上
void generateFood(Food& food, deque<Snake>& snake) {
	while (true) {
		food.x = rand() % (WIDTH / SIZE);
		food.y = rand() % (HEIGHT / SIZE);
		bool overlap = false;//用一个变量储存是否与蛇身重合
		//遍历蛇身
		for (const auto& body : snake) {
			if (food.x == body.x && food.y == body.y) {
				overlap = true;
				//与蛇身重合直接跳出for循环
				break;
			}
		}
		if (!overlap) {
			//与蛇身不重合则跳出while循环
			break;
		}
	}
}
//检查碰撞，是否吃到食物
bool checkcollision(Food& food, deque<Snake>& snake){
	//检测蛇头是否与食物重合
	if (snake.front().x == food.x && snake.front().y == food.y) {
		return true;
	}
	//检测蛇身是否与食物重合，可以不用，因为蛇头没有经过的位置，蛇身必然不会经过
	for (auto iter = snake.begin() + 1; iter != snake.end(); iter++) {
		if (iter->x == food.x && iter->y == food.y) {
			return true;
		}	
	}
	return false;
}
int main(){
	initgraph(WIDTH, HEIGHT);
	setbkcolor(0x7c5731);//设置背景颜色为藏青色
	cleardevice();//清除原背景底色（黑色）
	deque<Snake>snake;		//定义一条蛇，蛇头坐标为矩形左上角
	snake.push_front({ WIDTH / SIZE/2,HEIGHT / SIZE/2,RIGHT });//蛇头(16,12,右)初始向右
	srand((unsigned int)time(NULL));//设置时间戳
	Food food;
	generateFood(food, snake);//生成随机位置食物
	//绘制食物，颜色为红色
	setfillcolor(RED);
	fillrectangle(food.x * SIZE, food.y * SIZE, (food.x + 1) * SIZE, (food.y + 1) * SIZE);

	//drawSnake(snake);
	int score = 0;//分数初始化为0
	while (true) {
		moveSnake(snake,false);//移动蛇
		changeDirection(snake);//更改移动方向
		if (checkcollision(food, snake)) {
			//吃到了食物
			score++;
			//重新生成食物
			generateFood(food, snake);
			//增加蛇的长度
			moveSnake(snake, true);
			//绘制食物，颜色为红色
			setfillcolor(RED);
			fillrectangle(food.x * SIZE, food.y * SIZE, (food.x + 1) * SIZE, (food.y + 1) * SIZE);
		}
		settextcolor(YELLOW);//设置当前文字颜色为黄色
		//设置当前文字样式，指定高度20，宽度0为自适应，_T支持Unicode编码Consolas表示字体
		settextstyle(20, 0, _T("Consolas"));
		TCHAR strScore[16];
		_stprintf_s(strScore, _T("Score: %d"),score);
		outtextxy(10, 10, strScore);//指定位置输出字符串
	}
	//_getch();
	closegraph();
	return 0;
}

#endif
