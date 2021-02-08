#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <stdbool.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_X 10
#define MAP_Y 20
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define SPACE 32


using namespace std;

int b_x,b_y, key, f_shape, s_shape, turn, score, gameover, map[MAP_Y][MAP_X], buffer_map[MAP_Y][MAP_X];
int block[7][4][4][4] = {
	{ {/*shape = 0, turn = 0*/
	0, 0, 0, 0,
	0, 1, 1, 0,
	0, 1, 1, 0,
	0, 0, 0, 0
	},{/*shape = 0, turn = 1*/
	0, 0, 0, 0,
	0, 1, 1, 0,
	0, 1, 1, 0,
	0, 0, 0, 0
	},{/*shape = 0, turn = 2*/
	0, 0, 0, 0,
	0, 1, 1, 0,
	0, 1, 1, 0,
	0, 0, 0, 0
	},{/*shape = 0, turn = 3*/
	0, 0, 0, 0,
	0, 1, 1, 0,
	0, 1, 1, 0,
	0, 0, 0, 0
	}},
   { {/*shape = 1, turn = 0*/
	0, 0, 0, 0,
	1, 1, 1, 1,
	0, 0, 0, 0,
	0, 0, 0, 0
	},{/*shape = 1, turn = 1*/
	0, 0, 1, 0,
	0, 0, 1, 0,
	0, 0, 1, 0,
	0, 0, 1, 0
	},{/*shape = 1, turn = 2*/
	0, 0, 0, 0,
	1, 1, 1, 1,
	0, 0, 0, 0,
	0, 0, 0, 0
	},{/*shape = 1, turn = 3*/
	0, 0, 1, 0,
	0, 0, 1, 0,
	0, 0, 1, 0,
	0, 0, 1, 0
	}},
	{ {/*shape = 2, turn = 0*/
	0, 0, 0, 0,
	0, 0, 1, 1,
	0, 1, 1, 0,
	0, 0, 0, 0
	},{/*shape = 2, turn = 1*/
	0, 0, 1, 0,
	0, 0, 1, 1,
	0, 0, 0, 1,
	0, 0, 0, 0
	},{/*shape = 2, turn = 2*/
	0, 0, 0, 0,
	0, 0, 1, 1,
	0, 1, 1, 0,
	0, 0, 0, 0
	},	{/*shape = 2, turn = 3*/
	0, 0, 1, 0,
	0, 0, 1, 1,
	0, 0, 0, 1,
	0, 0, 0, 0
	}},
	{ {/*shape = 3, turn = 0*/
	0, 0, 0, 0,
	0, 1, 1, 0,
	0, 0, 1, 1,
	0, 0, 0, 0
	},{/*shape = 3, turn = 1*/
	0, 0, 0, 1,
	0, 0, 1, 1,
	0, 0, 1, 0,
	0, 0, 0, 0
	},{/*shape = 3, turn = 2*/
	0, 0, 0, 0,
	0, 1, 1, 0,
	0, 0, 1, 1,
	0, 0, 0, 0
	},{/*shape = 3, turn = 3*/
	0, 0, 0, 1,
	0, 0, 1, 1,
	0, 0, 1, 0,
	0, 0, 0, 0
	}},
	{ {/*shape = 4, turn = 0*/
	0, 0, 0, 1,
	0, 1, 1, 1,
	0, 0, 0, 0,
	0, 0, 0, 0
	},{/*shape = 4, turn = 1*/
	0, 0, 1, 0,
	0, 0, 1, 0,
	0, 0, 1, 1,
	0, 0, 0, 0
	},{/*shape = 4, turn = 2*/
	0, 0, 0, 0,
	0, 1, 1, 1,
	0, 1, 0, 0,
	0, 0, 0, 0
	},{/*shape = 4, turn = 3*/
	0, 1, 1, 0,
	0, 0, 1, 0,
	0, 0, 1, 0,
	0, 0, 0, 0
	}},
	{ {/*shape = 5, turn = 0*/
	0, 1, 0, 0,
	0, 1, 1, 1,
	0, 0, 0, 0,
	0, 0, 0, 0
	},{/*shape = 5, turn = 1*/
	0, 0, 1, 1,
	0, 0, 1, 0,
	0, 0, 1, 0,
	0, 0, 0, 0
	},{/*shape = 5, turn = 2*/
	0, 0, 0, 0,
	0, 1, 1, 1,
	0, 0, 0, 1,
	0, 0, 0, 0
	},{/*shape = 5, turn = 3*/
	0, 0, 1, 0,
	0, 0, 1, 0,
	0, 1, 1, 0,
	0, 0, 0, 0
	}},
	{ {/*shape = 6, turn = 0*/
	0, 0, 1, 0,
	0, 1, 1, 1,
	0, 0, 0, 0,
	0, 0, 0, 0
	},{/*shape = 6, turn = 1*/
	0, 0, 1, 0,
	0, 0, 1, 1,
	0, 0, 1, 0,
	0, 0, 0, 0
	},{/*shape = 6, turn = 2*/
	0, 0, 0, 0,
	0, 1, 1, 1,
	0, 0, 1, 0,
	0, 0, 0, 0
	},{/*shape = 6, turn = 3*/
	0, 0, 1, 0,
	0, 1, 1, 0,
	0, 0, 1, 0,
	0, 0, 0, 0
	} }
};//�� ���⺰ ���

void map_set();//���ʱ�ȭ
void move_block();//�� �̵�
void spawn_block();//�� ����
void copy_block();//�� ����ִ� �Լ�
int check_block();//���� �浹 üũ
void remove_block();//���� �� ����
void line_check();//ä���� �� üũ
void tetris_main();//��Ʈ���� ����
void BufferPrintMap();//��������������� ���� ����Ʈ
void moveCursorTo(const int x, const int y);//Ŀ�� �̵�
void CursorView(char show);//Ŀ�� ������ ����
void ScreenLine();// ���� �� ä���
void StartScreen();//����ȭ��


void map_set() {//�� �ʱ�ȭ
	for (int i = 0; i < MAP_Y; i++) {
		for (int j = 0; j < MAP_X; j++) {
			map[i][j] = 0;
			buffer_map[i][j] = 0;
		}
	}
}

void move_block() { /*�� �̵�*/
	key = 0;
	key = _getch();

	/* ����Ű �Է¿� ���Ͽ�
		UP = 224, 72
		DOWN = 224, 80
		LEFT = 224, 75
		RIGHT = 224, 77
		�� ó�� �� ���� �޾ƿͼ� ���� 224�� ���� ��ȯ �Ŀ� �� ���� ���� ��ȯ
		72 = H
		80 = P
		75 = K
		77 = M
		���� ���� ���� ���� ������ ȥ���� �ü��� ����
		�� 224�� Ű���� ���� ��ȯ�ϱ� ������ �����̰� ���ܼ� ���� 224�� Ű���� ������ �ʿ䰡 ����
	*/
	if (key == 224) {
		key = _getch();
		if (key == UP) {
			turn++;
			if (turn == 4)turn = 0;
			else if (check_block() == false)turn--;
		}
		else if (key == DOWN) {
			b_y++;
			if (check_block() == false) {//�ٴڸ� ����
				b_y--;
				copy_block();
				line_check();
				spawn_block();
			}
		}
		else if (key == LEFT) {
			b_x--;
			if (check_block() == false)b_x++;
		}
		else if (key == RIGHT) {
			b_x++;
			if (check_block() == false)b_x--;
		}
	}
	else {
		if (key == SPACE) {
			while (check_block() == true) {
				b_y++;
			}
			b_y--;
			copy_block();
			line_check();
			spawn_block();
		}
	}

}

void spawn_block() {/*�� ����*/
	b_x = MAP_X / 2;//�� x��ǥ �ʱ�ȭ
	b_y = 0;//�� y��ǥ �ʱ�ȭ
	f_shape = s_shape;//second �� first ������
	s_shape = rand() % 7;//second �� ���� ����
	turn = 0;//�� ���� �ʱ�ȭ

	/*�� �浿 üũ �� �� ī��*/
	if (check_block() == true) copy_block();
	else gameover = 1;//���� �������� ���ϴ� ��� gameover
}

int check_block() {/*�� �浹 üũ*/
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			/*�� �迭�˻� �� ���� �ִ°�� && 
			(�� �˻縦 �����ϴ� ��ġ�� ���� �ִ°�� || ���� �� ���� ���� ��� || �޺����� ������ ��� || �� �ٴں��� �Ʒ��� ��� || �� ������ ���� �������� ���)
			�� �浹 = false ��ȯ*/
			if (block[f_shape][turn][i][j] == 1 && (map[b_y + i][b_x + j - 2] != 0 || b_y + i < 0 || b_x + j - 2 < 0 || b_y + i > MAP_Y - 1 || b_x + j - 2 > MAP_X - 1))return false;
		}
	}
	return true;
}

void copy_block() {/*�� ���*/
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			/*�� �迭 �˻��� ���� ������ ���*/
			if (block[f_shape][turn][i][j] == 1) {
				map[b_y + i][b_x + j - 2] = block[f_shape][turn][i][j];
			}
		}
	}
}

void remove_block() {/*�� ����*/
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			/*�� �迭 �˻��� ���� ������ ����*/
			if (block[f_shape][turn][i][j] == 1) {
				map[b_y + i][b_x + j - 2] = 0;
			}
		}
	}
}

void line_check() {/*ä���� ���� ������ �� ���� ������*/
	int high = 0, stack = 0, k = 0;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			/*������ ���� ���� üũ*/
			if (block[f_shape][turn][i][j] == 1)high = i;
		}
	}
	high++;

	for (int i = b_y; i < b_y + high; i++) {
		for (int j = 0; j < MAP_X; j++) {
			/*������ ���� ���� ���� �� ���� ����üũ*/
			if (map[i][j] == 1)stack++;
		}

		/*����üũ �� ������ ä���������� ���� �� ��ĭ�� ������*/
		if (stack == MAP_X) {
			score += 100;
			for (int j = 0; j < MAP_X; j++) {
				map[i][j] = 0;
			}

			for (int j = i; j > 0; j--) {
				for (int k = 0; k < MAP_X; k++) {
					if (j - 1 > 0)map[j][k] = map[j - 1][k];
				}
			}
		}
		stack = 0;
	}


}

void BufferPrintMap() { /*�����*/
	cout << endl;
	for (int i = 0; i < MAP_Y; i++) {
		for (int j = 0; j < MAP_X; j++) {
			/*���� �ʰ� ���� ���� ���Ͽ� �ٸ���츸 ���*/
			if (map[i][j] != buffer_map[i][j]) {
				if (map[i][j] == 1) {
					moveCursorTo(j+1, i+1);
					cout << "��"; 
				}
				else if (map[i][j] == 0) {
					moveCursorTo(j+1, i+1);
					cout << "  ";
				}
			}
		}
		moveCursorTo(MAP_X + 1, i+1);
		cout << "��";
	}

	/*���۸� �ֽ�ȭ*/
	for (int i = 0; i < MAP_Y; i++) {
		for (int j = 0; j < MAP_X; j++) {
			buffer_map[i][j] = map[i][j];
		}
	}

	/*������ ���� �� ǥ��*/
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (block[s_shape][0][i][j] == 1) {
				moveCursorTo(MAP_X + 3+j, i+1);
				cout << "��";
			}
			else {
				moveCursorTo(MAP_X + 3 + j, i + 1);
				cout << "  ";
			}
		}
	}
	moveCursorTo(MAP_X + 3, 6);
	cout << "SCORE : " << score;//����ǥ��
}

void moveCursorTo(const int x, const int y) {//Ŀ���̵��Լ�
	const COORD pos = { 2*x+1, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void tetris_main() {
	gameover = 0;//���� ���� üũ ���� �ʱ�ȭ
	ScreenLine();//���� �׵θ�
	StartScreen();//���� �ʱ�ȭ��
	map_set();//���ʱ�ȭ
	s_shape = rand() % 7;//second �� ���� ����
	spawn_block();//������
	BufferPrintMap();//ȭ�� ���
	while (gameover == 0) {
		remove_block();//������
		for (int l = 0; l < 3; l++) {
			if (_kbhit()) {//Ű���� ������ ����
				move_block();
			}
			copy_block();//�� ī��
			BufferPrintMap();//ȭ�� ���
			remove_block();//�� ����
			Sleep(200);//�ӵ� ����
		}

		b_y++;//�� �ϰ�
		if (check_block() == false) {
			/*���� ���̻� �������� ���Ҷ�*/
			b_y--;
			copy_block();//�� ī��
			line_check();//���� ���� ��ŭ ����üũ
			spawn_block();//�� ����
		}

		copy_block();//�� ī��
		BufferPrintMap();//ȭ�� ���
	}
	moveCursorTo(MAP_X / 2-1, MAP_Y / 2);
	cout << "GAME  OVER";//���� ������ �Ȱ��
	key = _getch();//Ű���� �������� ���� ���
	tetris_main();//ùȭ������ ����
}

void CursorView(char show) {//Ŀ�� �����
	HANDLE hConsole;
	CONSOLE_CURSOR_INFO ConsoleCursor;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	ConsoleCursor.bVisible = show;
	ConsoleCursor.dwSize = 1;

	SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}

void ScreenLine() {//�׵θ� ����
	for (int i = 0; i < MAP_X * 2+2; i++) {
		moveCursorTo(i, 0);
		cout << "��";
	}

	for (int i = 1; i < MAP_Y + 2; i++) {
		moveCursorTo(0, i);
		cout << "��";
		for (int j = 1; j < MAP_X * 2+2; j++) {
			moveCursorTo(j, i);
			cout << "  ";
		}
		moveCursorTo(MAP_X * 2+1, i);
		cout << "��";

	}
	for (int i = 0; i < MAP_X * 2 + 2; i++) {
		moveCursorTo(i, MAP_Y+1);
		cout << "��";
	}
}

void StartScreen() {//�ʱ�ȭ��
	//x = 0~21, y = 0 ~ 21
	int ch = 13;
	moveCursorTo(MAP_X + 3, 10);
	cout << "             ";
	moveCursorTo(MAP_X + 3, 11);
	cout << "           ";
	moveCursorTo(MAP_X + 3, 12);
	cout << "             ";
	moveCursorTo(MAP_X + 3, 13);
	cout << "              ";
	moveCursorTo(MAP_X + 3, 14);
	cout << "                ";
		moveCursorTo(2, 2);
		cout << "�������������������";
		moveCursorTo(2, 3);
		cout << "  ��  ��      ��  ��  ��  ��  ��    ";
		moveCursorTo(2, 4);
		cout << "  ��  ����  ��  ����  ��  ����";
		moveCursorTo(2, 5);
		cout << "  ��  ��      ��  ���    ��      ��";
		moveCursorTo(2, 6);
		cout << "  ��  ����  ��  ��  ��������";
		moveCursorTo(10, 13);
		cout << "START";
		moveCursorTo(10, 15);
		cout << "EXIT";
		moveCursorTo(9, ch);
		cout << ">";
		while (1) {
			key = _getch();
			moveCursorTo(9, ch);
			cout << "  ";
			if (key == UP) {
				if (ch == 15)ch = 13;
				else ch = 13;
			}
			else if (key == DOWN) {
				if (ch == 13)ch = 15;
				else ch = 13;
			}

			else if (key == SPACE) {
				if (ch == 13)break;
				else if (ch == 15) {
					moveCursorTo(0, 25); 
					exit(0); 
				}
			}

			moveCursorTo(9, ch);
			cout << ">";
		}
		moveCursorTo(10, 13);
		cout << "     ";
		moveCursorTo(10, 15);
		cout << "    ";
		moveCursorTo(9, ch);
		cout << " ";
		moveCursorTo(2, 2);
		cout << "                                    ";
		moveCursorTo(2, 3);
		cout << "                                    ";
		moveCursorTo(2, 4);
		cout << "                                    ";
		moveCursorTo(2, 5);
		cout << "                                    ";
		moveCursorTo(2, 6);
		cout << "                                    ";

		moveCursorTo(MAP_X + 2, 10);
		cout << "�� : ������ȯ";
		moveCursorTo(MAP_X + 2, 11);
		cout << "�� : �Ʒ���";
		moveCursorTo(MAP_X + 2, 12);
		cout << "�� : ��������";
		moveCursorTo(MAP_X + 2, 13);
		cout << "�� : ����������";
		moveCursorTo(MAP_X + 2, 14);
		cout << "space : �ٴ�����";
}

void main() {
	srand(time(NULL));
	CursorView(false);

	tetris_main();

	moveCursorTo(0, 25);
}