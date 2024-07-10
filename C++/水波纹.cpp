#include<graphics.h>
#include<stdlib.h>
#include<windows.h>

#define WIDTH 1180
#define HIGH 435

#define ELEM(array,row,col) (array[(row)*(WIDTH)+(col)])

short* wave1;//��ǰʱ��
short* wave2;//��һʱ��
IMAGE bkCur;
IMAGE bkNext;

void init() {
	initgraph(WIDTH, HIGH);
	loadimage(&bkCur,_T("res/bj.jpg"));
	//loadimage(&bk,L"res/bj.jpg");
	//putimage(0, 0, &bk);
	bkNext.Resize(WIDTH, HIGH);//������һ�����ڵĴ�С

	wave1 = (short*)malloc(sizeof(short) * WIDTH * HIGH);//һά�����ָ��
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
				//��ʯͷ��Բ�η�Χ֮��	
				//wave1[posy][posx] += stoneWeight;
				wave1[posy * WIDTH + posx] += stoneWeight;
			}
		}
	}
}

void userClickMove() {
	ExMessage msg;
	while (peekmessage(&msg, EM_MOUSE)) {
		if (msg.message == WM_MOUSEMOVE) {//����ƶ�
			putStone(msg.x,msg.y,3,256);//Сʯͷ
		}
		else if (msg.message == WM_LBUTTONDOWN) {//���������
			putStone(msg.x, msg.y, 10, 2500);//��ʯͷ
		}
	}
}

void nextWaveDate() {
	//������������м���
	for (int i = 1; i < HIGH-1; i++)
	{//�����ĸ���Ĳ�����x1,x2,x3,x4
		//���Ե�ȡһ�룬���ݵ����ĵ�
		for (int j = 1; j < WIDTH-1; j++)
		{
			//wave2[i * WIDTH + j];
			ELEM(wave2, i, j) =
				(ELEM(wave1, i - 1, j) + ELEM(wave1, i + 1, j) +
					ELEM(wave1, i, j - 1) + ELEM(wave1, i, j + 1)) / 2
				- ELEM(wave2, i, j);

			//ʱ���ϣ���Ҫ��һ��˥��
			ELEM(wave2, i, j) -= ELEM(wave2, i, j) >> 5;//�൱�ڳ���32
		}
	}
	//����wave1��wave2
	short* tmp = wave1;
	wave1 = wave2;
	wave2 = tmp;
}

void calcImage() {
	//��ȡͼƬ�������ڴ�
	DWORD* p1=GetImageBuffer(&bkCur);
	//��ͼƬ
	DWORD* p2 = GetImageBuffer(&bkNext);

	int i = 0;
	for (int y = 0; y < HIGH; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{//�򵥰汾
			//��y�У���x���ܵ�������Ӱ�죬����ƫ��
			//��Ҫ����ƫ��֮����б꣬�б�

			//ƫ�ƺ���б�
			int a = x * (1 - wave1[i] / 1000.0);
			//�б�
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
	BeginBatchDraw();//˫���壬���⻭�濨��

	putimage(0, 0, &bkNext);

	EndBatchDraw();
}

int main() {
	init();

	while (1) {
		//�û�����
		userClickMove();

		//������һ��ʱ�̣���һ֡������������
		nextWaveDate();

		//�����ܵ�������Ӱ�죬�����µĻ���
		calcImage();

		//���µĻ�����Ⱦ����
		showImage();

		Sleep(1);
	}

	return 0;
}