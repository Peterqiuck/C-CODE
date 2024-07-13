#include<graphics.h>
#include<time.h>
#define WIDTH 720
#define HIGH 750

char c;
char str[HIGH / 15][WIDTH / 10];

void init() {
	initgraph(WIDTH,HIGH);
	
	//ÐÐ50£¬ÁÐ72
	memset(str, 0, sizeof(char) * 72 * 50);
}

void print() {
	for (int i = 0; i < HIGH; i++)
	{
		int x = (rand() % 72) *10;//0-710
		int y = (rand() % 50) *15;//0-735
		c = rand() % 26 + 65;//65-90
		if (str[y / 15][x / 10] == 0) {
			settextcolor(GREEN);
			settextstyle(15, 10, _T("Courier"));
			outtextxy(x, y, c);
		}
		setlinecolor(BLACK);
		line(0, i, WIDTH, i);
		if (i >= HIGH-1)i =-1;
		Sleep(10);
	}
}

int main() {
	srand((unsigned int)time(NULL));
	init();
	print();

	return 0;
}