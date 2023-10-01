#include<iostream>
#include<conio.h>
#include<Windows.h>
#include"windowsetting.h"
#include"playground.h"
#include"graphics.h"
#include"lobby.h"
#include"windowsetting.h"


using namespace std;

int kiemtrathangX(int a[65][33])
{
	for (int i = 4; i <= 48; i += 4) {
		for (int j = 2; j <= 24; j += 2) {
			if (a[i][j] == 1 && a[i + 4][j] == 1 && a[i + 8][j] == 1 && a[i + 12][j] == 1 && a[i + 16][j] == 1) return 1;
			if (a[i][j] == 1 && a[i][j + 2] == 1 && a[i][j + 4] == 1 && a[i][j + 6] == 1 && a[i][j + 8] == 1) return 1;
			if (a[i][j] == 1 && a[i + 4][j+2] == 1 && a[i + 8][j+4] == 1 && a[i + 12][j+6] == 1 && a[i + 16][j+8] == 1) return 1;
		}
	}
	for (int i = 20; i <= 64; i += 4) {
		for (int j = 2; j <= 24; j += 2) {
			if (a[i][j] == 1 && a[i - 4][j+2] == 1 && a[i - 8][j+4] == 1 && a[i - 12][j+6] == 1 && a[i - 16][j+8] == 1) return 1;
		}
	}
}
int kiemtrathangO(int a[65][33])
{
	for (int i = 4; i <= 48; i += 4) {
		for (int j = 2; j <= 24; j += 2) {
			if (a[i][j] == 2 && a[i + 4][j] == 2 && a[i + 8][j] == 2 && a[i + 12][j] == 2 && a[i + 16][j] == 2) return 2;
			if (a[i][j] == 2 && a[i][j + 2] == 2 && a[i][j + 4] == 2 && a[i][j + 6] == 2 && a[i][j + 8] == 2) return 2;
			if (a[i][j] == 2 && a[i + 4][j + 2] == 2 && a[i + 8][j + 4] == 2 && a[i + 12][j + 6] == 2 && a[i + 16][j + 8] == 2) return 2;
		}
	}
	for (int i = 20; i <= 64; i += 4) {
		for (int j = 2; j <= 24; j += 2) {
			if (a[i][j] == 2 && a[i - 4][j + 2] == 2 && a[i - 8][j + 4] == 2 && a[i - 12][j + 6] == 2 && a[i - 16][j + 8] == 2) return 2;
		}
	}
}

void danhXO()
{
	int xet[65][33] = { 0 };
	char c;
	int flag = 0;
	int x = 4, y = 2;
	GoTo(x, y);
	while (true) {
		c = _getch();
		if (c == 'a' && x > 4) GoTo(x -= 4, y); 
		if (c == 'd' && x < 4 + 4 * 15) GoTo(x += 4, y);
		if (c == 's' && y < 2 + 2 * 15) GoTo(x, y += 2);
		if (c == 'w' && y > 2) GoTo(x, y -= 2);
		if ((c == char(13) && flag == 0) && xet[x][y] == 0) {
			set_color(244); 
			cout << "X"; 
			flag++; GoTo(x, y); 
			xet[x][y] = 1;
			if (kiemtrathangX(xet) == 1) cout << "X thang";
			continue; 
		}
		if ((c == char(13) && flag == 1) && xet[x][y] == 0) {
			set_color(242); 
			cout << "O";  
			flag--; 
			GoTo(x, y); 
			xet[x][y] = 2;
			if (kiemtrathangO(xet) == 2) cout << "O thang";
		}

	}
}

int main()
{
	SetConsoleTitle(L"CO CARO");
	system("color f0"); // nhu cai ve nen 
	FixConsoleWindow();
	DisableCtrButton(0, 0, 1);
	resizeConsole(1070, 620);
	ShowScrollBar(GetConsoleWindow(), SB_BOTH, FALSE);
	//ShowCur(0);
	DisableSelection();
	//lobby();
	playground();
	danhXO();
	_getch();
	return 0;
}
