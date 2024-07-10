#include<graphics.h>
#include<stdlib.h>
#include<windows.h>

#define WIDTH 1180
#define HIGH 435

#define ELEM(array,row,col) (array[(row)*(WIDTH)+(col)])

short* wave1;//当前时刻
short* wave2;//上一时刻
IMAGE bkCur;
IMAGE bkNext;

void init() {
	initgraph(WIDTH, HIGH);
	loadimage(&bkCur,_T("res/bj.jpg"));
	//loadimage(&bk,L"res/bj.jpg");
	//putimage(0, 0, &bk);
	bkNext.Resize(WIDTH, HIGH);//设置下一个窗口的大小

	wave1 = (short*)malloc(sizeof(short) * WIDTH * HIGH);//一维数组的指针
	wave2 = (short*)malloc(sizeof(short) * WIDTH * HIGH);

	memset(wave1, 0, sizeof(short) * WIDTH * HIGH);
	memset(wave2, 0, sizeof(short) * WIDTH * HIGH);
}

void putStone(int x,int y,int stoneSize,int stoneWeight) {
	if (x >= WIDTH - stoneSize || x < stoneSize ||
		y >= HIGH - stoneSize || y < stoneSize) {
		return;
	}
	for (int posx = x-stoneSize; posx < x+stoneSize; posx++){
		for (int posy = y - stoneSize; posy < y + stoneSize; posy++) {
			if ((posx-x) * ( posx-x) + (posy-y) * (posy-y) < stoneSize * stoneSize) {
				//在石头的圆形范围之内	
				//wave1[posy][posx] += stoneWeight;
				wave1[posy * WIDTH + posx] += stoneWeight;
			}
		}
	}
}

void userClickMove() {
	ExMessage msg;
	while (peekmessage(&msg, EM_MOUSE)) {
		if (msg.message == WM_MOUSEMOVE) {//鼠标移动
			putStone(msg.x,msg.y,3,256);//小石头
		}
		else if (msg.message == WM_LBUTTONDOWN) {//鼠标左键点击
			putStone(msg.x, msg.y, 10, 2500);//大石头
		}
	}
}

void nextWaveDate() {
	//对整个画面进行计算
	for (int i = 1; i < HIGH-1; i++)
	{//四周四个点的波幅，x1,x2,x3,x4
		//粗略的取一半，传递到中心点
		for (int j = 1; j < WIDTH-1; j++)
		{
			//wave2[i * WIDTH + j];
			ELEM(wave2, i, j) =
				(ELEM(wave1, i - 1, j) + ELEM(wave1, i + 1, j) +
					ELEM(wave1, i, j - 1) + ELEM(wave1, i, j + 1)) / 2
				- ELEM(wave2, i, j);

			//时间上，还要进一步衰减
			ELEM(wave2, i, j) -= ELEM(wave2, i, j) >> 5;//相当于除以32
		}
	}
	//交换wave1和wave2
	short* tmp = wave1;
	wave1 = wave2;
	wave2 = tmp;
}

void calcImage() {
	//获取图片的像素内存
	DWORD* p1=GetImageBuffer(&bkCur);
	//新图片
	DWORD* p2 = GetImageBuffer(&bkNext);

	int i = 0;
	for (int y = 0; y < HIGH; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{//简单版本
			//第y行，第x列受到波幅的影响，发生偏移
			//需要计算偏移之后的行标，列标

			//偏移后的列标
			int a = x * (1 - wave1[i] / 1000.0);
			//行标
			int b = y * (1 - wave1[i] / 1000.0);

			if (a >= WIDTH)a = WIDTH - 1;
			if (a < 0)a = 0;
			if (b >= HIGH)b = HIGH - 1;
			if (b < 0)b = 0;

			p2[i] = ELEM(p1, b, a);
			i++;

		}
	}

}

void showImage() {
	BeginBatchDraw();//双缓冲，避免画面卡顿

	putimage(0, 0, &bkNext);

	EndBatchDraw();
}

int main() {
	init();

	while (1) {
		//用户操作
		userClickMove();

		//计算下一个时刻（下一帧）波幅的数据
		nextWaveDate();

		//根据受到波幅的影响，计算新的画面
		calcImage();

		//把新的画面渲染出来
		showImage();

		Sleep(1);
	}

	return 0;
}