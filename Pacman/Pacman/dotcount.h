
/***********フィールドの餌をカウント***********/
int getDotCount() {
	int dotCount = 0;
	for (int y = 0; y < MAZE_HEIGHT; y++)
		for (int x = 0; x < MAZE_WIDTH; x++) {
			switch (cells[y][x]) {
			case CELL_DOT:
			case CELL_POWER:
				dotCount++;
				break;
			}
		}
	return dotCount;
}