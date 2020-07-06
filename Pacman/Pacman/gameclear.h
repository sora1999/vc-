
/***********ゲームクリア判定**********/
void gameClear() {
	int x = monsters[MONSTER_PAC].x;
	int y = monsters[MONSTER_PAC].y;
	monsters[MONSTER_PAC].x = x;
	monsters[MONSTER_PAC].y = y;
	display();
	printf("GAME CLEAR\a");
	printf("   スコア　%d点  素晴らしい！！最高得点だ！！   ", cnt);
	_getch();

	//ファイルオープン
	FILE* fp;
	errno_t error = fopen_s(&fp, "結果.txt", "w");

	//ファイル書き込み
	char s_buf[BUFFSIZE];
	sprintf_s(s_buf, "スコア %d点\n\n満点おめでとうございます！！", cnt);
	fputs(s_buf, fp);
	//ファイルクローズ
	fclose(fp);
	exit(0);
}