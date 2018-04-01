
// 헤더파일 선업
#include <stdio.h>

#include <Windows.h>

#include<conio.h>

#include <stdlib.h>

#include <time.h>


// define 
#define BROAD_X 12 //게임판 가로크기 
#define BROAD_Y 24 //게임판 세로크기 
#define BROAD_X_W 3 //게임판 위치조정 
#define BROAD_Y_W 1 //게임판 위치조정 


// 전역 변수
int best_score = 0;
int level = 0;
int score = 0;
int level_goal = 1000;
int key = 0;
int crush = 0;
int cnt = 0;
int speed = 1000;

// 블록 전역 변수
int block_type;
int block_rotation;
int block_type_next;

int blocks[7][4][4][4] = {
	{ { 0,0,0,0,0,1,1,0,0,1,1,0,0,0,0,0 },
	{ 0,0,0,0,0,1,1,0,0,1,1,0,0,0,0,0 },
	{ 0,0,0,0,0,1,1,0,0,1,1,0,0,0,0,0 },
	{ 0,0,0,0,0,1,1,0,0,1,1,0,0,0,0,0 } },
	{ { 0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0 }
	,{ 0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0 },
	{ 0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0 },
	{ 0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0 } },
	{ { 0,0,0,0,1,1,0,0,0,1,1,0,0,0,0,0 }
	,{ 0,0,0,0,0,0,1,0,0,1,1,0,0,1,0,0 },
	{ 0,0,0,0,1,1,0,0,0,1,1,0,0,0,0,0 },
	{ 0,0,0,0,0,0,1,0,0,1,1,0,0,1,0,0 } },
	{ { 0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,0 },{ 0,0,0,0,1,0,0,0,1,1,0,0,0,1,0,0 },
	{ 0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,0 },{ 0,0,0,0,1,0,0,0,1,1,0,0,0,1,0,0 } },
	{ { 0,0,0,0,0,0,1,0,1,1,1,0,0,0,0,0 },{ 0,0,0,0,1,1,0,0,0,1,0,0,0,1,0,0 },
	{ 0,0,0,0,0,0,0,0,1,1,1,0,1,0,0,0 },{ 0,0,0,0,0,1,0,0,0,1,0,0,0,1,1,0 } },
	{ { 0,0,0,0,1,0,0,0,1,1,1,0,0,0,0,0 },{ 0,0,0,0,0,1,0,0,0,1,0,0,1,1,0,0 },
	{ 0,0,0,0,0,0,0,0,1,1,1,0,0,0,1,0 },{ 0,0,0,0,0,1,1,0,0,1,0,0,0,1,0,0 } },
	{ { 0,0,0,0,0,1,0,0,1,1,1,0,0,0,0,0 },{ 0,0,0,0,0,1,0,0,0,1,1,0,0,1,0,0 },
	{ 0,0,0,0,0,0,0,0,1,1,1,0,0,1,0,0 },{ 0,0,0,0,0,1,0,0,1,1,0,0,0,1,0,0 } }
};

// 함수 정의부
void reset_main();
void draw_map();
void draw_main();
void new_block();
void new_block();


// MAIN 함수
int main()
{
	title();
	reset();

}


// X,Y 좌표 지정 함수
void gotoxy(int x, int y)
{
	COORD pos = { 2 * x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}


// 시작 화면
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


// 게임 초기화
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


//	블록 생성 함수
void new_block()
{
	int i, j;
	
}
