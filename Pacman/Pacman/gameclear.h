
/***********�Q�[���N���A����**********/
void gameClear() {
	int x = monsters[MONSTER_PAC].x;
	int y = monsters[MONSTER_PAC].y;
	monsters[MONSTER_PAC].x = x;
	monsters[MONSTER_PAC].y = y;
	display();
	printf("GAME CLEAR\a");
	printf("   �X�R�A�@%d�_  �f���炵���I�I�ō����_���I�I   ", cnt);
	_getch();

	//�t�@�C���I�[�v��
	FILE* fp;
	errno_t error = fopen_s(&fp, "����.txt", "w");

	//�t�@�C����������
	char s_buf[BUFFSIZE];
	sprintf_s(s_buf, "�X�R�A %d�_\n\n���_���߂łƂ��������܂��I�I", cnt);
	fputs(s_buf, fp);
	//�t�@�C���N���[�Y
	fclose(fp);
	exit(0);
}