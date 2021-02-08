#include <iostream>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#define MAP_X 9
#define MAP_Y 16
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define SPACE 32

using namespace std;

class tetris {
private: 
	int i, j, l, x, y, key, shape, turn, score, map[MAP_Y][MAP_X];
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
	};
public:
	tetris();
	void map_reset();
	void print_map();
	void move_block();
	void spawn_block();
	void copy_block();
	int check_block();
	void remove_block();
	void line_check();
	void tetris_main();
};

tetris::tetris() {
	i = 0;
	j = 0;
	x = MAP_X / 2;
	y = 0;
	shape = 0;
	turn = 0;
	score = 0;
}

void tetris::map_reset() {
	for (i = 0; i < MAP_Y; i++) {
		for (j = 0; j < MAP_X; j++) {
			map[i][j] = 0;
		}
	}
}

void tetris::print_map() { /*맵출력*/
	system("cls");
	cout << endl;
	for (i = 0; i < MAP_Y; i++) {
		cout << "■";
		for (j = 0; j < MAP_X; j++) {
			if (map[i][j] == 0) {
				cout << "  ";
			}
			else if (map[i][j] == 1) {
				cout << "□";
			}
		}
		cout << "■" << endl;
		
	}
	for (j = 0; j < MAP_X+2; j++) {
	cout << "■" ;
	}
	cout << endl << "SCORE : " << score;
}

void tetris::move_block() { /*블럭 이동*/
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
			y++;
			if (check_block() == false) {//바닥면 인지
				y--;
				copy_block();
				line_check();
				spawn_block();
			}
		}
		else if (key == LEFT) {
			x--;
			if (check_block() == false)x++;
		}
		else if (key == RIGHT) {
			x++;
			if (check_block() == false)x--;
		}
	}
	else {
		if (key == SPACE) {
			while (check_block() == true) {
				y++;
			}
			y--;
			copy_block();
			line_check();
			spawn_block();
		}
	}

}

void tetris::spawn_block() {/*블럭 생성*/
	x = MAP_X/ 2;
	y = 0;
	shape = rand() % 7;
	turn = 0;

	if (check_block() == true) copy_block();
}

int tetris::check_block() {/*블럭 충돌 체크*/
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			if (block[shape][turn][i][j] == 1 && (map[y + i][x + j - 2] != 0 || y + i < 0 || x + j - 2 < 0 || y + i > MAP_Y - 1 || x + j - 2 > MAP_X - 1))return false;
		}
	}
	return true;
}

void tetris::copy_block() {/*블럭 찍기*/
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			if (block[shape][turn][i][j] == 1) {
				map[y + i][x + j -2] = block[shape][turn][i][j];
			}
		}
	}
}

void tetris::remove_block() {/*블럭 제거*/
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			if (block[shape][turn][i][j] == 1) {
				map[y + i][x + j - 2] = 0;
			}
		}
	}
}  

void tetris::line_check() {/*채워진 라인 제거후 윗 라인 내리기*/
	int high = 0, stack = 0, k = 0;
	
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			if (block[shape][turn][i][j] == 1)high = i;
		}
	}
	high++;

	for (i = y; i < y + high; i++) {
		for (j = 0; j < MAP_X; j++) {
			if (map[i][j] == 1)stack++;
		}

		if (stack == MAP_X) {
			score += 100;
			for (j = 0; j < MAP_X; j++) {
				map[i][j] = 0;
			}

			for (j = i; j > 0; j--) {
				for (k = 0; k < MAP_X; k++) {
					if (j - 1 > 0)map[j][k] = map[j - 1][k];
				}
			}
		}
		stack = 0;
	}


}

void tetris::tetris_main() {
	map_reset();
	spawn_block();
	print_map();
	while (1) {
		remove_block();
		for (l = 0; l < 3; l++) {
			if (_kbhit()) {
				move_block();
				copy_block();
				print_map();
				remove_block();
			}

			Sleep(100);
		}


		y++;
		if (check_block() == false) {
			y--;
			copy_block();
			line_check();
			spawn_block();
		}
		
		copy_block();
		print_map();
	}
}


int main() {
	tetris t;
	
	srand(time(NULL));

	t.tetris_main();

	return 0;
}