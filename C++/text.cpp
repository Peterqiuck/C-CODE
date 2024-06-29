#if 0
#include<graphics.h>
#include<time.h>
#include<deque>
#include<windows.h>
using namespace std;

//bug,���������ǰ���ķ����ٰ�ǰ����ϵͳҲ���¼���ǰ��ָ���ʱ���������������������ִ�У�
//����ϵͳҲ���¼����ָ�ֻ�ܵ����ǰ��ָ�����,ϵͳ�Ż�ִ�л���ָ��
#define WIDTH 640//���
#define HEIGHT 480//����
#define SIZE 20//��ͷ�Լ�ʳ���С
#define DELAY 200//���ƶ����ٶ�
//���ƶ�����
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
//ʳ��
struct Food{
	int x;
	int y;
};
//��������
void drawSnake(deque<Snake>& snake) {
	setfillcolor(GREEN);
    //�����������
	for (const auto& body : snake) {
		//��20x20���ο��ʾ����,���ϽǺ����½�����
		fillrectangle(body.x * SIZE, body.y * SIZE, (body.x + 1) * SIZE, (body.y + 1) * SIZE);
	}
	//�������ƶ����ٶ�
	Sleep(DELAY);
}
//�ж���Ϸ�Ƿ����
void ifOver(deque<Snake>& snake) {
	for (auto iter = snake.begin()+1; iter != snake.end(); iter++) {
		if ((snake.front().x == iter->x && snake.front().y == iter->y) //��ͷײ������
			|| snake.front().x<0 || snake.front().x>=WIDTH/SIZE         //��ͷ����Խ��
			|| snake.front().y<0 || snake.front().y>=HEIGHT/SIZE   )    //��ͷ����Խ��
		{
			settextcolor(RED);//���õ�ǰ������ɫ
			settextstyle(100, 0, _T("Consolas"));//����������ʽ��ָ���߶�100�����0Ϊ����Ӧ
			TCHAR endStr[16];
			_stprintf_s(endStr, _T("GAME OVER!!!"));
			outtextxy(WIDTH / SIZE, HEIGHT / SIZE, endStr);//ָ��λ������ַ���
			Sleep(3000);//������Ϸ��������ͣ��3s
			closegraph();
			exit(0);//��Ϸ����ֱ���˳�
		}
	}
}
//���ƶ�
void moveSnake(deque<Snake>& snake, bool grow = false){
	Snake newHead = snake.front();//��ȡ����ͷ�����ó�ʼλ��
	switch (newHead.dir)//�ж����ƶ�����
	{
	case UP:newHead.y--;
		break;
	case DOWN:newHead.y++;
		break;
	case LEFT:newHead.x--;
		break;
	case RIGHT:newHead.x++;
	}
	//����λ����Ϊ��ͷ,��ʱ����䳤
	snake.push_front(newHead);
	//ÿ���ƶ���Ҫ�ж���Ϸ�Ƿ����
	ifOver(snake);
	//grow=ture��ʾ�Ե���ʳ�grow=false��ʾ��ͨ�ƶ�
	if (!grow){
		//û�Ե�ʳ����������һ��Ԫ�ؾ��ο����,���Ϻ���������
		clearrectangle(snake.back().x * SIZE, snake.back().y * SIZE, (snake.back().x + 1) * SIZE, (snake.back().y + 1) * SIZE);
		snake.pop_back();
	}
	//��������
	drawSnake(snake);
}
//�����ߵ��ƶ�����
void changeDirection(deque<Snake>& snake) {
	ExMessage msg = { 0 };//������Ϣ����
	peekmessage(&msg, EX_KEY);//���������Ϣ
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
//����ʳ�������������
void generateFood(Food& food, deque<Snake>& snake) {
	while (true) {
		food.x = rand() % (WIDTH / SIZE);
		food.y = rand() % (HEIGHT / SIZE);
		bool overlap = false;//��һ�����������Ƿ��������غ�
		//��������
		for (const auto& body : snake) {
			if (food.x == body.x && food.y == body.y) {
				overlap = true;
				//�������غ�ֱ������forѭ��
				break;
			}
		}
		if (!overlap) {
			//�������غ�������whileѭ��
			break;
		}
	}
}
//�����ײ���Ƿ�Ե�ʳ��
bool checkcollision(Food& food, deque<Snake>& snake){
	//�����ͷ�Ƿ���ʳ���غ�
	if (snake.front().x == food.x && snake.front().y == food.y) {
		return true;
	}
	//��������Ƿ���ʳ���غϣ����Բ��ã���Ϊ��ͷû�о�����λ�ã������Ȼ���ᾭ��
	for (auto iter = snake.begin() + 1; iter != snake.end(); iter++) {
		if (iter->x == food.x && iter->y == food.y) {
			return true;
		}	
	}
	return false;
}
int main(){
	initgraph(WIDTH, HEIGHT);
	setbkcolor(0x7c5731);//���ñ�����ɫΪ����ɫ
	cleardevice();//���ԭ������ɫ����ɫ��
	deque<Snake>snake;		//����һ���ߣ���ͷ����Ϊ�������Ͻ�
	snake.push_front({ WIDTH / SIZE/2,HEIGHT / SIZE/2,RIGHT });//��ͷ(16,12,��)��ʼ����
	srand((unsigned int)time(NULL));//����ʱ���
	Food food;
	generateFood(food, snake);//�������λ��ʳ��
	//����ʳ���ɫΪ��ɫ
	setfillcolor(RED);
	fillrectangle(food.x * SIZE, food.y * SIZE, (food.x + 1) * SIZE, (food.y + 1) * SIZE);

	//drawSnake(snake);
	int score = 0;//������ʼ��Ϊ0
	while (true) {
		moveSnake(snake,false);//�ƶ���
		changeDirection(snake);//�����ƶ�����
		if (checkcollision(food, snake)) {
			//�Ե���ʳ��
			score++;
			//��������ʳ��
			generateFood(food, snake);
			//�����ߵĳ���
			moveSnake(snake, true);
			//����ʳ���ɫΪ��ɫ
			setfillcolor(RED);
			fillrectangle(food.x * SIZE, food.y * SIZE, (food.x + 1) * SIZE, (food.y + 1) * SIZE);
		}
		settextcolor(YELLOW);//���õ�ǰ������ɫΪ��ɫ
		//���õ�ǰ������ʽ��ָ���߶�20�����0Ϊ����Ӧ��_T֧��Unicode����Consolas��ʾ����
		settextstyle(20, 0, _T("Consolas"));
		TCHAR strScore[16];
		_stprintf_s(strScore, _T("Score: %d"),score);
		outtextxy(10, 10, strScore);//ָ��λ������ַ���
	}
	//_getch();
	closegraph();
	return 0;
}

#endif
