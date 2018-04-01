
// 헤더파일 선업
#include <stdio.h>

#include <Windows.h>

#include<conio.h>

#include <stdlib.h>

#include <time.h>

int best_score = 0;
int level = 0;
int score = 0;
int level_goal = 1000;
int key = 0;
int crush = 0;
int cnt = 0;
int speed = 1000;

void reset_main();
void draw_map();
void draw_main();

void block_type_next();
void new_block();


int main()
{
	title();
	reset();

}

void gotoxy(int x, int y)
{
	COORD pos = { 2 * x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void title(void)
{
	// x 좌표
	int x = 5;

	// y 좌표
	int y = 5;

	// 타이틀 프레임을 세는 변수
	int cnt;

	gotoxy(x, y + 0); printf("□□□□□□□□□□□□□□□□□□□□□□□□□");
	gotoxy(x, y + 1); printf("□■■■□■■■□■■■□■■■□■■■□■■■□");
	gotoxy(x, y + 2); printf("□□■□□■□□□□■□□■□■□□■□□■□□□");
	gotoxy(x, y + 3); printf("□□■□□■■■□□■□□■■■□□■□□■■■□");
	gotoxy(x, y + 4); printf("□□■□□■□□□□■□□■□■□□■□□□□■□");
	gotoxy(x, y + 5); printf("□□■□□■■■□□■□□■□■□■■■□■■■□");
	gotoxy(x, y + 6); printf("□□□□□□□□□□□□□□□□□□□□□□□□□");
	gotoxy(x, y + 7); printf("");
	gotoxy(x + 5, y + 8); printf("Please Enter Any Key to Start!");
	gotoxy(x, y + 8); printf(" ");
	gotoxy(x, y + 8); printf(" ");
	gotoxy(x, y + 8); printf(" ");
	gotoxy(x, y + 8); printf(" ");
	gotoxy(x, y + 8); printf(" ");
	puts("");
}

void reset()
{
	FILE *file = fopen("score.dat", "rt");

	if (file == 0)
	{
		best_score = 0;
	}
	else
	{
		fscanf(file, "%d", &best_score);
		fclose(file);
	}
	level = 1;
	score = 0;
	level_goal = 1000;
	key = 0;
	crush = 0;
	cnt = 0;
	speed = 1000;

	system("cls");

	reset_main();
	draw_map();
	draw_main();

	block_type_next = rand() % 7;
	new_block();
}
