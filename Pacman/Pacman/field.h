
/***********�t�B�[���h�ǂݍ���***********/
char data[] = "\
#####################\
#ooooooooo#ooooooooo#\
#o###o###o#o###o###o#\
#0  #o# #o#o  #o# #0#\
#o###o# #o#o###o# #o#\
#o#  o# #ooo#  o# #o#\
#o###o###o#o###o###o#\
#ooooooooo#ooooooooo#\
#o###o###o#o###o###o#\
#####o###o#o###o#####\
    #o#   r   #o#    \
    #o# ##### #o#    \
#####o# #bpy# #o#####\
     o  #   #  o     \
#####o# ##### #o#####\
    #o#       #o#    \
    #o# ##### #o#    \
#####o# ##### #o#####\
#ooooooooo#ooooooooo#\
#o###o###o#o###o###o#\
#0oo#ooo#o@o#ooo#oo0#\
###o#o#o#o#o#o#o#o###\
###o#o#o#o#o#o#o#o###\
#ooooo#ooo#ooo#ooooo#\
#o#####o#####o#####o#\
#ooooooooooooooooooo#\
#####################";

/***********�t�B�[���h��̃p�[�c��`***********/
enum {
	CELL_NONE,
	CELL_WALL,
	CELL_DOT,
	CELL_POWER,
	CELL_MAX
};

/***********�c�E���̕���`***********/
#define MAZE_WIDTH 21
#define MAZE_HEIGHT 27

/***********�t�B�[���h�p�[�c�̃A�X�L�[�ݒ�**********/
char cellAA[][2 + 1] = {
	"�@", //CELL_NONE
	"��", //CELL_WALL
	"�E", //CELL_DOT
	"�O", //CELL_POWER
};

/***********�c�E���̒l��z��Ɋi�[***********/
int cells[MAZE_HEIGHT][MAZE_WIDTH];
