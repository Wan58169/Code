#include<iostream>
using namespace std;

int N;
const int MAXLEN = 16;
int a[MAXLEN][MAXLEN];
enum direction {Right,Down,Left,Up};

void f(int row,int col,int n)
{
	enum direction dir = Right;	
	int max = n-1;
	int min = 0;

	for(int i=0; i<n*n; i++) {
		a[row][col] = i+1;
		//判断是否要改变方向
		if(col==max && row==min) 
			dir = Down;
		else if(col==min && row==max) 
			dir = Up;
		else if(row==max && col==max) 
			dir = Left;
		else if(row==min+1 && col==min) {
			dir = Right;
			min++;
			max--;
		}
		//按方向前进
		switch(dir) {
			case Right:
				col++;
				break;
			case Down:
				row++;
				break;
			case Left:
				col--;
				break;
			case Up:
				row--;
				break;
		}
	}
}

void traverse(int n)
{
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			cout.width(3);
			cout << a[i][j] << " ";
		}
		cout << " " << endl;
	}
}

int main()
{
	cin >> N;
	
	f(0,0,N);
	traverse(N);
	
	return 0;
}

