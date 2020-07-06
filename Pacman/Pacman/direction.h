
/***********方向の定義***********/
enum {
	DIRECTION_NORTH,
	DIRECTION_WEST,
	DIRECTION_SOUTH,
	DIRECTION_EAST,
	DIRECTION_MAX
};

/***********方向ベクトルの定義**********/
int directions[][2] = {
	{ 0, -1 }, //DIRECTION_NORTH
	{ -1, 0 }, //DIRECTION_WEST
	{ 0, 1 },  //DIRECTION_SOUTH
	{ 1, 0 },  //DIRECTION_EAST
};