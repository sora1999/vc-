
/***********�����X�^�[��`**********/
enum {
	MONSTER_PAC,
	MONSTER_ENEMY1,
	MONSTER_ENEMY2,
	MONSTER_ENEMY3,
	MONSTER_ENEMY4,
	MONSTER_MAX
};

/***********�����X�^�[�̍\����**********/
typedef struct Monster {
	int x, y;
	int direction;
	int def;
}MONSTER;

MONSTER monsters[MONSTER_MAX];

/***********�����X�^�[�̃A�X�L�[�ݒ�**********/
char monsterAA[][2 + 1] = {
	"��", //MONSTER_PAC
	"��", //MONSTER_ENEMY1
	"��", //MONSTER_ENEMY2
	"��", //MONSTER_ENEMY3
	"��", //MONSTER_ENEMY4
};

/***********�����X�^�[�擾**********/
int getMonster(int _x, int _y) {
	for (int i = 0; i < MONSTER_MAX; i++)
		if ((monsters[i].x == _x) && (monsters[i].y == _y))
			return i;
	return -1;
}

/***********���G���Ԓ�`***********/
#define INVINCIBLE_TIME 40
int invincibleTime;

/***********�����X�^�[��ʕ\��**********/
void display() {
	system("cls");
	for (int y = 0; y < MAZE_HEIGHT; y++) {
		for (int x = 0; x < MAZE_WIDTH; x++) {
			int monster = getMonster(x, y);
			if (monster >= 0) {
				if ((monster > MONSTER_PAC) && (invincibleTime > 0))
					printf("%s", (invincibleTime < INVINCIBLE_TIME / 4) ? "��" : "��");
				else
					printf(monsterAA[monster]);
			}
			else
				printf(cellAA[cells[y][x]]);
		}
		printf("\n");
	}
}
