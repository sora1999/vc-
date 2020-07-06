
/***********ゲームオーバー判定***********/
void gameOver() {
	monsters[MONSTER_PAC].x = -1;
	monsters[MONSTER_PAC].y = -1;
	display();
	printf("GAME OVER\a");
	printf("   スコア %d点   ", cnt);
	_getch();

	//ファイルオープン
	FILE* fp;
	errno_t error = fopen_s(&fp, "Result.txt", "w");

	//ファイル書き込み
	char s_buf[BUFFSIZE];
	sprintf_s(s_buf, "スコア %d点\n\n残念！次は満点目指して頑張ってください！！", cnt);
	fputs(s_buf, fp);
	//ファイルクローズ
	fclose(fp);
	exit(0);
}