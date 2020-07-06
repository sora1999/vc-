// Pacman.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include <conio.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "direction.h"
#include "field.h"
#include "monster.h"

#define BUFFSIZE 100
int cnt = 0;

#include "gameover.h"
#include "gameclear.h"
#include "dotcount.h"

/***********メインメソッド**********/
int main() {
	char s_currentDir[_MAX_PATH];
	GetCurrentDirectory(sizeof(s_currentDir), s_currentDir);
	// ファイルパスの作成(iniファイルから読み込み)
	char s_inifile[_MAX_PATH];
	sprintf_s(s_inifile, "%s\\Pac.ini", s_currentDir);

	//構造体にiniファイルのデータを格納
	//sakura
	struct Monster enemy;
	enemy.def = GetPrivateProfileInt("enemy", "def", -1, s_inifile);

	srand((unsigned int)time(NULL));
	for (int y = 0; y < MAZE_HEIGHT; y++)
		for (int x = 0; x < MAZE_WIDTH; x++) {
			char c = data[MAZE_WIDTH*y + x];
			int cell = CELL_NONE;

			//フィールドの文字取得
			switch (c) {
			case '#': cell = CELL_WALL;  break;
			case 'o': cell = CELL_DOT;   break;
			case '0': cell = CELL_POWER; break;
			default:
			{
				int monster = enemy.def;

				//フィールドのモンスター取得
				switch (c) {
				case '@': monster = MONSTER_PAC;    break;
				case '1': monster = MONSTER_ENEMY1;	break;
				case '2': monster = MONSTER_ENEMY2; break;
				case '3': monster = MONSTER_ENEMY3; break;
				case '4': monster = MONSTER_ENEMY4; break;
				}
				if (monster >= 0) {
					monsters[monster].x = x;
					monsters[monster].y = y;
				}
			}
			break;
			}
			cells[y][x] = cell;
		}

	int dotCountMax = getDotCount();

	while (1) {
		display();
		
		//パックマンの操作定義
		int x = monsters[MONSTER_PAC].x;
		int y = monsters[MONSTER_PAC].y;
		switch (_getch()) {
		case 'w': y-- ; break;
		case 's': y++ ; break;
		case 'a': x-- ; break;
		case 'd': x++ ; break;
		}
		x = (MAZE_WIDTH + x) % MAZE_WIDTH;
			
			//モンスターがパックマンに衝突した場合の処理
			if (getMonster(x, y) > MONSTER_PAC) {
				if (invincibleTime > 0) {
					int monster = getMonster(x, y);
					monsters[monster].x = 10;
					monsters[monster].y = 10;
				}
				else
				gameOver();
		}

		if (cells[y][x] == CELL_WALL) {
		}
		else {
			if (cells[y][x] == CELL_POWER)
				invincibleTime = INVINCIBLE_TIME;

			cells[y][x] = CELL_NONE;
			cnt++;
			int dotCount = getDotCount();
			int monster = enemy.def;

			//クリア判定
			if (dotCount <= 0) {
				gameClear();
			}

			//餌の残数による敵の増加設定
			else if (dotCount == dotCountMax * 3 / 4)
				monster = MONSTER_ENEMY2;
			else if (dotCount == dotCountMax * 2 / 4)
				monster = MONSTER_ENEMY3;
			else if (dotCount == dotCountMax * 1 / 4)
				monster = MONSTER_ENEMY4;

			if (monster >= 0) {
				monsters[monster].x = 10;
				monsters[monster].y = 10;
			}

			monsters[MONSTER_PAC].x = x;
			monsters[MONSTER_PAC].y = y;
		}

		//パックマンがモンスターに衝突した場合の処理
		for (int i = MONSTER_PAC + 1; i < MONSTER_MAX; i++) {
			int x = monsters[i].x + directions[monsters[i].direction][0];
			int y = monsters[i].y + directions[monsters[i].direction][1];
			int monster = getMonster(x, y);
			if (monster == MONSTER_PAC) {
				if (invincibleTime > 0) {
					monsters[i].x = 10;
					monsters[i].y = 10;
				}
				else {
					monsters[i].x = x;
					monsters[i].y = y;
					gameOver();
				}
			}
			else if ((cells[y][x] == CELL_WALL) || (monster > MONSTER_PAC)) {
				monsters[i].direction = rand() % DIRECTION_MAX;
			}
			else {
				monsters[i].x = x;
				monsters[i].y = y;
			}
		}
		if (invincibleTime > 0)
			invincibleTime--;
	}
} 