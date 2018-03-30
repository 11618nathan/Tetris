
// 헤더파일 선업
#include <stdio.h>

#include <Windows.h>

#include<conio.h>

#include <stdlib.h>

#include <time.h>

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

void main()
{
	title();
}

