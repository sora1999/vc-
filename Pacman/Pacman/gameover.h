
/***********�Q�[���I�[�o�[����***********/
void gameOver() {
	monsters[MONSTER_PAC].x = -1;
	monsters[MONSTER_PAC].y = -1;
	display();
	printf("GAME OVER\a");
	printf("   �X�R�A %d�_   ", cnt);
	_getch();

	//�t�@�C���I�[�v��
	FILE* fp;
	errno_t error = fopen_s(&fp, "Result.txt", "w");

	//�t�@�C����������
	char s_buf[BUFFSIZE];
	sprintf_s(s_buf, "�X�R�A %d�_\n\n�c�O�I���͖��_�ڎw���Ċ撣���Ă��������I�I", cnt);
	fputs(s_buf, fp);
	//�t�@�C���N���[�Y
	fclose(fp);
	exit(0);
}