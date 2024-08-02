#include<stdlib.h>
#include<graphics.h>
#include<mmsystem.h>
#include<time.h>
#include<math.h>
#pragma comment(lib,"winmm.lib")
//��gettickcount()����timeGetTime(����
//��Щ�����ᱨ��������windows�Դ��ģ�����С��
//��Ӧ�Ƚ�Ѹ��
#define WIDTH 1200
#define HEIGHT 800
#define NUM 11//�̻�����
#define MAXR 120//���ըԲ�뾶
//�̻���
struct Jet {
	int x, y;//��ǰλ��
	int hx, hy;//��ߵ�
	DWORD t1, t2, dt;//�������ٶ�
	IMAGE img[2];
	bool isshoot;
	byte n : 1;
}jet[NUM];

struct Fire {
	int x, y;
	int r;//Բ��ǰ�뾶
	DWORD t1, t2, dt;//��ը�ٶ�
	int Circle[240][240];
	bool isBoom;
	bool isDraw;
}fire[NUM];

void Init(int i) {
	jet[i].t1 = timeGetTime();
	jet[i].dt = 10;
	//jet[i].dt = rand() % 20 + 1;
	jet[i].n = 1;
	jet[i].isshoot = false;
	fire[i].r = 0;
	fire[i].t1 = timeGetTime();
	fire[i].dt = 5;
	fire[i].isBoom = false;
	fire[i].isDraw = false;
}
//��ʼ��11��img����
//��ʼ��11��imgs����
void Loading() {
	IMAGE imgJet;
	IMAGE imgFire;
	loadimage(&imgJet, "res/10.png", 280, 50);
	loadimage(&imgFire, "res/11.png", 2640, 240);
	SetWorkingImage(&imgJet);
	int n;
	for (int i = 0; i < NUM; i++)
	{
		n = rand() % 5;
		getimage(&jet[i].img[1], 28 * n, 0, 28,50);
		getimage(&jet[i].img[0], 28 * (n + 5), 0, 28, 50);
	}
	SetWorkingImage();
	IMAGE imgs;
	for (int a = 0; a < NUM; a++)
	{
		SetWorkingImage(&imgFire);
		getimage(&imgs, 240 * a, 0, 240, 240);
		SetWorkingImage(&imgs);
		for (int i = 0; i < 240; i++)
		{
			for (int j = 0; j < 240; j++)
			{
				fire[a].Circle[i][j] = getpixel(i, j);
			}
		}
	}
	SetWorkingImage();
}
//׼���̻���
void Choice(DWORD &t1) {
	DWORD t2 = timeGetTime();
	//�̻�����Ҫͬʱ���֣�100ms��һ��
	if (t2 - t1 > 150) { 
		int n = rand() % NUM;//11�������ȡ��һ��
		if (jet[n].isshoot == false&&fire[n].isBoom==false) //����4��û��дisBoom��������
		{
			jet[n].x = rand() % 1173 + 14;
			jet[n].y = rand() % 100 + 600;
			jet[n].hx = jet[n].x;
			jet[n].hy = rand() % 400;
			jet[n].isshoot = true;
			putimage(jet[n].x, jet[n].y, &jet[n].img[jet[n].n], SRCINVERT);
		}
		t1 = t2;
	}
}
//����
void Fly() {
	for (int i = 0; i < NUM; i++){
		jet[i].t2 = timeGetTime();
		if (jet[i].t2 - jet[i].t1 > jet[i].dt && jet[i].isshoot == true) 
		{
			putimage(jet[i].x, jet[i].y, &jet[i].img[jet[i].n], SRCINVERT);
			if (jet[i].y >=jet[i].hy) {
				jet[i].y -= 5;
				jet[i].n++;	
			}
			putimage(jet[i].x, jet[i].y, &jet[i].img[jet[i].n], SRCINVERT);
			if (jet[i].y <= jet[i].hy) {
				jet[i].isshoot = false;//����3���Ⱥ�д��==
				fire[i].isBoom = true;
				putimage(jet[i].x, jet[i].y, &jet[i].img[jet[i].n], SRCINVERT);
				fire[i].x = jet[i].x;
				fire[i].y = jet[i].y;
			}
			jet[i].t1 = jet[i].t2;
		}
	}
}

//��ը�̻�
void Draw(DWORD*pMem) {
	int drt[12] = { 5,5,5,6,6,8,8,10,10,20,30,50};
	for (int i = 0; i < NUM; i++)
	{
		fire[i].t2 = timeGetTime();
		if (fire[i].t2 - fire[i].t1 > fire[i].dt && fire[i].isBoom == true) {
			if (fire[i].r < MAXR) {
				fire[i].r++;
				fire[i].dt = drt[fire[i].r / 10];
				fire[i].isDraw = true;
			}
			if (fire[i].r >= MAXR-1) {//����2��û�м�һ,��Խ����
				//r�������120���ͻ����drt[12],��drt���һ��Ԫ��Ϊdrt[11](drt[0]--drt[11])��12��Ԫ��
				//����r���ֵΪ119
				Init(i);
			}	
			fire[i].t1 = fire[i].t2;
		}

		if (fire[i].isDraw == true) {
			for (double a = 0; a < 6.24; a += 0.01)
			{
				//ͼƬһȦԲ������
				int xx = int(MAXR + fire[i].r * cos(a));//����1��cosд��sin
				int yy = int(MAXR - fire[i].r * sin(a));
				if (xx>0&&xx < 240 && yy>0&&yy < 240) 
				{
					int b = fire[i].Circle[xx][yy] & 0xff;
					int g = fire[i].Circle[xx][yy]>>8 & 0xff;
					int r = fire[i].Circle[xx][yy] >> 16;
					//����һȦԲ������
					int x1 = int(fire[i].x + fire[i].r * cos(a));
					int y1 = int(fire[i].y - fire[i].r * sin(a));
					if (b > 0x20 && g > 0x20 && r > 0x20 && 
						x1 > 0 && x1 < WIDTH && y1>0 && y1 < HEIGHT)
						pMem[y1 * WIDTH + x1] =BGR(fire[i].Circle[xx][yy]);
				}
			}
		}
	}
}
void Style(DWORD& st1)
{
	DWORD st2 = timeGetTime();

	if (st2 - st1 > 20000)  //20s
	{
		int  x[NUM] = { 60, 75, 91, 100, 95, 75, 60, 45, 25, 15, 25 };// , 41, 60 };
		int  y[NUM] = { 65, 53, 40, 22, 5, 4, 20, 4, 5, 22, 40 };// , 53, 65 };
		cleardevice();
		for (int i = 0; i < NUM; i++)
		{
			jet[i].x = x[i] * 10;
			jet[i].y = (y[i] + 75) * 12;
			jet[i].hx = jet[i].x;
			jet[i].hy = y[i] * 12;

			//jet[i].height = jet[i].y - jet[i].hy;
			jet[i].isshoot = true;
			jet[i].dt = 7;
			putimage(jet[i].x, jet[i].y, &jet[i].img[jet[i].n], SRCINVERT);

			fire[i].x = jet[i].x + 10;
			fire[i].y = jet[i].hy;
			fire[i].isBoom = false;
			fire[i].r = 0;
		}
		st1 = st2;
	}
}

int main() {
	initgraph(WIDTH, HEIGHT);
	srand((unsigned)time(0));
	mciSendString("open 22.mp3 alias music", 0, 0, 0);
	mciSendString("play music repeat", 0, 0, 0);

	DWORD t1 = timeGetTime();
	DWORD st1 = timeGetTime();
	DWORD* pMem = GetImageBuffer();

	//��ʼ��11���ṹ���е�img[2]
	Loading();
	//��ʼ��11���ṹ���г�img[2]�������
	for (int i = 0; i < NUM; i++){
		Init(i);
	}

	BeginBatchDraw();
	
	while (1) { 
		//for (int i = 0; i < 1500; i++)
		//{
		//	//for (int j = 0; j <2; j++)
		//	//{
		//	int x = rand() % WIDTH;
		//	int y = rand() % HEIGHT;
		//	if (y < 790)
		//		//pMem[y * WIDTH + x] = pMem[y * WIDTH + x + 1] = BLACK;
		//		pMem[y * WIDTH + x] = BLACK;
		//     //}
		//}

	   Choice(t1);
	 
		Fly();
		Draw(pMem);
		Style(st1);
		FlushBatchDraw();
	}

	EndBatchDraw();
	return 0;
}