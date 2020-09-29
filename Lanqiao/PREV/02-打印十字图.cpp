//小明为某机构设计了一个十字型的徽标（并非红十字会啊），如下所示：
//
//..$$$$$$$$$$$$$..
//..$...........$..
//$$$.$$$$$$$$$.$$$
//$...$.......$...$
//$.$$$.$$$$$.$$$.$
//$.$...$...$...$.$
//$.$.$$$.$.$$$.$.$
//$.$.$...$...$.$.$
//$.$.$.$$$$$.$.$.$
//$.$.$...$...$.$.$
//$.$.$$$.$.$$$.$.$
//$.$...$...$...$.$
//$.$$$.$$$$$.$$$.$
//$...$.......$...$
//$$$.$$$$$$$$$.$$$
//..$...........$..
//..$$$$$$$$$$$$$..
//对方同时也需要在电脑dos窗口中以字符的形式输出该标志，并能任意控制层数。
//
//输入格式
//一个正整数 n (n<30) 表示要求打印图形的层数。
//输出格式
//对应包围层数的该标志。
//样例输入1
//1
//样例输出1
//..$$$$$..
//..$...$..
//$$$.$.$$$
//$...$...$
//$.$$$$$.$
//$...$...$
//$$$.$.$$$
//..$...$..
//..$$$$$..
//样例输入2
//3
//样例输出2
//..$$$$$$$$$$$$$..
//..$...........$..
//$$$.$$$$$$$$$.$$$
//$...$.......$...$
//$.$$$.$$$$$.$$$.$
//$.$...$...$...$.$
//$.$.$$$.$.$$$.$.$
//$.$.$...$...$.$.$
//$.$.$.$$$$$.$.$.$
//$.$.$...$...$.$.$
//$.$.$$$.$.$$$.$.$
//$.$...$...$...$.$
//$.$$$.$$$$$.$$$.$
//$...$.......$...$
//$$$.$$$$$$$$$.$$$
//..$...........$..
//..$$$$$$$$$$$$$..
//提示
//请仔细观察样例，尤其要注意句点的数量和输出位置。

#include<iostream>
using namespace std;

char map[150][150]; //图案 
int N;	//第几层 
int H;  //图案的边长
int center; //中心点 

int main()
{
	cin >> N;
	//计算图案的边长 
	if(N == 1) {
		H  = 9;		
	} else {
		H = 9+(N-1)*4;
	}
	//初始化图案内容
	for(int i=1; i<=H; i++) {
		for(int j=1; j<=H; j++) {
			map[i][j] = '.';
		}
	} 
	//在图案中心画5x5的十字架
	center = H/2+1;
	for(int i=center-2; i<=center+2; i++) { //先画一竖 
		map[i][center] = '$';
	}
	for(int i=center-2; i<=center+2; i++) { //再画一横
		map[center][i] = '$';
	}
	//画横着的$ 
	//从上至下
	int cnt_$ = H-4; //$的个数 
	int row = 1; 	 //行号的定位 
	int col_begin = 3;	//列的开始位置 
	int col_end = col_begin+cnt_$-1;	//列的结束位置 
	while(row < center-2) {	 
		map[row+1][col_begin] = '$';	//开始时竖着的一角 
		map[row+2][col_begin] = '$';	//第二角 
		for(int i=col_begin; i<=col_end; i++) {
			map[row][i] = '$';
		}
		map[row+1][col_end] = '$';	//结束时竖着的一角 
		map[row+2][col_end] = '$';	//第二角
		row += 2;
		cnt_$ -= 4;
		col_begin += 2;
		col_end = col_begin+cnt_$-1;
	}
	//从下至上 
	cnt_$ = H-4;
	row = H;
	col_begin = 3;
	col_end = col_begin+cnt_$-1;
	while(row > center+2) {
		map[row-1][col_begin] = '$';	//开始时竖着的一角 
		map[row-2][col_begin] = '$';	//第二角 
		for(int i=col_begin; i<=col_end; i++) {
			map[row][i] = '$';
		}
		map[row-1][col_end] = '$';	//结束时竖着的一角 
		map[row-2][col_end] = '$';	//第二角 
		row -= 2;
		cnt_$ -= 4;
		col_begin += 2;
		col_end = col_begin+cnt_$-1;
	}
	//画竖着的$
	//从左往右
	cnt_$ = H-4;
	int col = 1;	//列号的定位 
	int row_begin = 3; //行的开始位置 
	int row_end =  row_begin+cnt_$-1; //行的结束位置
	while(col < center-2) {
		map[row_begin][col+1] = '$';	//开始时横着的一角 
		for(int i=row_begin; i<=row_end; i++) {
			map[i][col] = '$';
		}
		map[row_end][col+1] = '$';	//结束时横着的一角 
		col += 2;
		cnt_$ -= 4;
		row_begin += 2;
		row_end = row_begin+cnt_$-1;
	} 
	//从右往左
	cnt_$ = H-4;
	col = H;
	row_begin = 3;
	row_end = row_begin+cnt_$-1;
	while(col > center+2) {
		map[row_begin][col-1] = '$';	//开始时横着的一角 
		for(int i=row_begin; i<=row_end; i++) {
			map[i][col] = '$';
		}
		map[row_end][col-1] = '$';	//结束时横着的一角 
		col -= 2;
		cnt_$ -= 4;
		row_begin += 2;
		row_end = row_begin+cnt_$-1;
	} 
	//打印图案
	for(int i=1; i<=H; i++) {
		for(int j=1; j<=H; j++) {
			cout << map[i][j];
		}
		cout << " " << endl;
	} 
	return 0;
}
