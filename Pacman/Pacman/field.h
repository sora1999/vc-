
/***********フィールド読み込み***********/
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

/***********フィールド上のパーツ定義***********/
enum {
	CELL_NONE,
	CELL_WALL,
	CELL_DOT,
	CELL_POWER,
	CELL_MAX
};

/***********縦・横の幅定義***********/
#define MAZE_WIDTH 21
#define MAZE_HEIGHT 27

/***********フィールドパーツのアスキー設定**********/
char cellAA[][2 + 1] = {
	"　", //CELL_NONE
	"■", //CELL_WALL
	"・", //CELL_DOT
	"０", //CELL_POWER
};

/***********縦・横の値を配列に格納***********/
int cells[MAZE_HEIGHT][MAZE_WIDTH];
