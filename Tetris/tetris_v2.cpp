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
};//블럭 방향별 모양

void map_set();//맵초기화
void move_block();//블럭 이동
void spawn_block();//블럭 생성
void copy_block();//블럭 찍어주는 함수
int check_block();//벽과 충돌 체크
void remove_block();//기존 블럭 제거
void line_check();//채워진 줄 체크
void tetris_main();//테트리스 메인
void BufferPrintMap();//더블버퍼형식으로 맵을 프린트
void moveCursorTo(const int x, const int y);//커서 이동
void CursorView(char show);//커서 깜빡임 제거
void ScreenLine();// 게임 줄 채우기
void StartScreen();//시작화면


void map_set() {//맵 초기화
	for (int i = 0; i < MAP_Y; i++) {
		for (int j = 0; j < MAP_X; j++) {
			map[i][j] = 0;
			buffer_map[i][j] = 0;
		}
	}
}

void move_block() { /*블럭 이동*/
	key = 0;
	key = _getch();

	/* 방향키 입력에 대하여
		UP = 224, 72
		DOWN = 224, 80
		LEFT = 224, 75
		RIGHT = 224, 77
		위 처럼 두 값을 받아와서 먼저 224의 값을 반환 후에 각 뒤의 값을 반환
		72 = H
		80 = P
		75 = K
		77 = M
		뒤의 값은 위와 같기 때문에 혼동이 올수도 있음
		또 224의 키값을 먼저 반환하기 때문에 딜레이가 생겨서 앞의 224의 키값을 버려줄 필요가 있음
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
			if (check_block() == false) {//바닥면 인지
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

void spawn_block() {/*블럭 생성*/
	b_x = MAP_X / 2;//블럭 x좌표 초기화
	b_y = 0;//블럭 y좌표 초기화
	f_shape = s_shape;//second 블럭 first 블럭으로
	s_shape = rand() % 7;//second 블럭 랜덤 대입
	turn = 0;//블럭 방향 초기화

	/*블럭 충동 체크 후 블럭 카피*/
	if (check_block() == true) copy_block();
	else gameover = 1;//블럭이 생성되지 못하는 경우 gameover
}

int check_block() {/*블럭 충돌 체크*/
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			/*블럭 배열검사 후 블럭이 있는경우 && 
			(블럭 검사를 실행하는 위치에 블럭이 있는경우 || 맵의 위 보다 위인 경우 || 왼벽보다 왼쪽일 경우 || 맵 바닥보다 아래인 경우 || 맵 오른벽 보다 오른쪽일 경우)
			벽 충돌 = false 반환*/
			if (block[f_shape][turn][i][j] == 1 && (map[b_y + i][b_x + j - 2] != 0 || b_y + i < 0 || b_x + j - 2 < 0 || b_y + i > MAP_Y - 1 || b_x + j - 2 > MAP_X - 1))return false;
		}
	}
	return true;
}

void copy_block() {/*블럭 찍기*/
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			/*블럭 배열 검사후 블럭이 있으면 찍기*/
			if (block[f_shape][turn][i][j] == 1) {
				map[b_y + i][b_x + j - 2] = block[f_shape][turn][i][j];
			}
		}
	}
}

void remove_block() {/*블럭 제거*/
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			/*블럭 배열 검사후 블럭이 있으면 제거*/
			if (block[f_shape][turn][i][j] == 1) {
				map[b_y + i][b_x + j - 2] = 0;
			}
		}
	}
}

void line_check() {/*채워진 라인 제거후 윗 라인 내리기*/
	int high = 0, stack = 0, k = 0;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			/*내려온 블럭의 높이 체크*/
			if (block[f_shape][turn][i][j] == 1)high = i;
		}
	}
	high++;

	for (int i = b_y; i < b_y + high; i++) {
		for (int j = 0; j < MAP_X; j++) {
			/*내려온 블럭의 제일 낮은 곳 부터 라인체크*/
			if (map[i][j] == 1)stack++;
		}

		/*라인체크 시 라인이 채워져있으면 제거 후 한칸씩 내리기*/
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

void BufferPrintMap() { /*맵출력*/
	cout << endl;
	for (int i = 0; i < MAP_Y; i++) {
		for (int j = 0; j < MAP_X; j++) {
			/*기존 맵과 버퍼 맵을 비교하여 다른경우만 출력*/
			if (map[i][j] != buffer_map[i][j]) {
				if (map[i][j] == 1) {
					moveCursorTo(j+1, i+1);
					cout << "□"; 
				}
				else if (map[i][j] == 0) {
					moveCursorTo(j+1, i+1);
					cout << "  ";
				}
			}
		}
		moveCursorTo(MAP_X + 1, i+1);
		cout << "■";
	}

	/*버퍼맵 최신화*/
	for (int i = 0; i < MAP_Y; i++) {
		for (int j = 0; j < MAP_X; j++) {
			buffer_map[i][j] = map[i][j];
		}
	}

	/*다음에 나올 블럭 표시*/
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (block[s_shape][0][i][j] == 1) {
				moveCursorTo(MAP_X + 3+j, i+1);
				cout << "□";
			}
			else {
				moveCursorTo(MAP_X + 3 + j, i + 1);
				cout << "  ";
			}
		}
	}
	moveCursorTo(MAP_X + 3, 6);
	cout << "SCORE : " << score;//점수표시
}

void moveCursorTo(const int x, const int y) {//커서이동함수
	const COORD pos = { 2*x+1, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void tetris_main() {
	gameover = 0;//게임 오버 체크 변수 초기화
	ScreenLine();//게임 테두리
	StartScreen();//게임 초기화면
	map_set();//맵초기화
	s_shape = rand() % 7;//second 블럭 랜덤 대입
	spawn_block();//블럭생성
	BufferPrintMap();//화면 출력
	while (gameover == 0) {
		remove_block();//블럭제거
		for (int l = 0; l < 3; l++) {
			if (_kbhit()) {//키값이 들어오면 실행
				move_block();
			}
			copy_block();//블럭 카피
			BufferPrintMap();//화면 출력
			remove_block();//블럭 제거
			Sleep(200);//속도 제어
		}

		b_y++;//블럭 하강
		if (check_block() == false) {
			/*블럭이 더이상 내려가지 못할때*/
			b_y--;
			copy_block();//블럭 카피
			line_check();//블럭의 높이 만큼 라인체크
			spawn_block();//블럭 생성
		}

		copy_block();//블럭 카피
		BufferPrintMap();//화면 출력
	}
	moveCursorTo(MAP_X / 2-1, MAP_Y / 2);
	cout << "GAME  OVER";//게임 오버가 된경우
	key = _getch();//키값이 들어오기전 까지 대기
	tetris_main();//첫화면으로 전송
}

void CursorView(char show) {//커서 숨기기
	HANDLE hConsole;
	CONSOLE_CURSOR_INFO ConsoleCursor;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	ConsoleCursor.bVisible = show;
	ConsoleCursor.dwSize = 1;

	SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}

void ScreenLine() {//테두리 라인
	for (int i = 0; i < MAP_X * 2+2; i++) {
		moveCursorTo(i, 0);
		cout << "■";
	}

	for (int i = 1; i < MAP_Y + 2; i++) {
		moveCursorTo(0, i);
		cout << "■";
		for (int j = 1; j < MAP_X * 2+2; j++) {
			moveCursorTo(j, i);
			cout << "  ";
		}
		moveCursorTo(MAP_X * 2+1, i);
		cout << "■";

	}
	for (int i = 0; i < MAP_X * 2 + 2; i++) {
		moveCursorTo(i, MAP_Y+1);
		cout << "■";
	}
}

void StartScreen() {//초기화면
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
		cout << "■■■■■■■■■■■■■■■■■■";
		moveCursorTo(2, 3);
		cout << "  ■  ■      ■  ■  ■  ■  ■    ";
		moveCursorTo(2, 4);
		cout << "  ■  ■■■  ■  ■■■  ■  ■■■";
		moveCursorTo(2, 5);
		cout << "  ■  ■      ■  ■■    ■      ■";
		moveCursorTo(2, 6);
		cout << "  ■  ■■■  ■  ■  ■■■■■■■";
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
		cout << "↑ : 방향전환";
		moveCursorTo(MAP_X + 2, 11);
		cout << "↓ : 아래로";
		moveCursorTo(MAP_X + 2, 12);
		cout << "← : 왼쪽으로";
		moveCursorTo(MAP_X + 2, 13);
		cout << "→ : 오른쪽으로";
		moveCursorTo(MAP_X + 2, 14);
		cout << "space : 바닥으로";
}

void main() {
	srand(time(NULL));
	CursorView(false);

	tetris_main();

	moveCursorTo(0, 25);
}