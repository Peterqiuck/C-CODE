// ���뻷����Visual C++ 6.0~2022��EasyX_2023�����
// https://easyx.cn
//
#include <graphics.h>

int main()
{
	// ��ʼ��ͼ�δ���
	initgraph(640, 480);

	ExMessage m;		// ������Ϣ����

	while (true)
	{
		// ��ȡһ�����򰴼���Ϣ
		m = getmessage(EX_MOUSE | EX_KEY);
		//peekmessage(&m,EX_MOUSE|EX_KEY);//һ����

		switch (m.message)
		{
		case WM_MOUSEMOVE:
			// ����ƶ���ʱ�򻭺�ɫ��С��
			putpixel(m.x, m.y, RED);
			break;

		case WM_LBUTTONDOWN:
			// ����������ͬʱ������ Ctrl ��
			if (m.ctrl)
				// ��һ���󷽿�
				rectangle(m.x - 10, m.y - 10, m.x + 10, m.y + 10);
			else
				// ��һ��С����
				rectangle(m.x - 5, m.y - 5, m.x + 5, m.y + 5);
			break;

		case WM_KEYDOWN:
			if (m.vkcode == VK_ESCAPE)
				return 0;	// �� ESC ���˳�����
		}
	}

	// �ر�ͼ�δ���
	closegraph();
	return 0;
}
