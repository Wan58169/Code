//���⣺ȫ���ů
//
//����һ��ĳ����NxN���ص���Ƭ����.����ʾ���󡢡�#����ʾ½�أ�������ʾ��
//
//.......
//.##....
//.##....
//....##.
//..####.
//...###.
//.......
//
//���С��������ҡ��ĸ�����������һ���һƬ½�����һ�����졣������ͼ����2�����졣
//
//����ȫ���ů�����˺�����������ѧ��Ԥ��δ����ʮ�꣬�����Եһ�����صķ�Χ�ᱻ��ˮ��û��������˵���һ��½�������뺣������(���������ĸ������������к���)�����ͻᱻ��û��
//
//������ͼ�еĺ���δ�������������ӣ�
//
//.......
//.......
//.......
//.......
//....#..
//.......
//.......
//
//������㣺���տ�ѧ�ҵ�Ԥ�⣬��Ƭ���ж��ٵ���ᱻ��ȫ��û��
//
//�������ʽ��
//��һ�а���һ������N��  (1 <= N <= 1000)
//����N��N�д���һ�ź�����Ƭ��
//
//��Ƭ��֤��1�С���1�С���N�С���N�е����ض��Ǻ���
//
//�������ʽ��
//һ��������ʾ�𰸡�

//������������
//7
//.......
//.##....
//.##....
//....##.
//..####.
//...###.
//.......
//
//�����������
//1
#include<iostream>
using namespace std;

const int pixelNum = 100;		//��ͼ��Ԥ�Ƴߴ�
//�Զ����ͼ����
typedef struct {
	char c;
	int isVisited;
} MAP;

MAP mapA[pixelNum][pixelNum];
MAP mapB[pixelNum][pixelNum];

void dfs(MAP map[][pixelNum],int x,int y,int n,int groupId)
{
	//Խ��
	if(x<0 || y<0 || x>n || y>n)
		return;
	//����Ǻ�������Ѿ������ʹ� 
	if(map[x][y].c=='.' || map[x][y].c=='#'&&map[x][y].isVisited!=0)
		return; 
	map[x][y].isVisited = groupId;
	//�������ҷ��� 
	if(map[x-1][y].c=='#' && map[x-1][y].isVisited==0) {
		dfs(map,x-1,y,n,groupId);
	}
	if(map[x+1][y].c=='#' && map[x+1][y].isVisited==0) {
		dfs(map,x+1,y,n,groupId);
	}
	if(map[x][y-1].c=='#' && map[x][y-1].isVisited==0) {
		dfs(map,x,y-1,n,groupId);
	}
	if(map[x][y+1].c=='#' && map[x][y+1].isVisited==0) {
		dfs(map,x,y+1,n,groupId);
	}
}

int main()
{
	freopen("09.txt","r",stdin);
	int N;								//������N,��ͼ�ߴ� 
	int groupANum,groupBNum;			//��ͼA,B�ĵ��� 
	
	cin >> N;
	//��ʼ����ͼA
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			mapA[i][j].isVisited = 0;
			mapB[i][j].isVisited = 0;
		}
	}
	//�����ͼA
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			cin >> mapA[i][j].c;
			mapB[i][j].c = mapA[i][j].c;
		}
	} 
	//����,����Ч��ͼB 
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			//����õ���½�� 
			if(mapA[i][j].c == '#') {
				//�ж����������Ƿ��Ǻ��� 
				if(mapA[i-1][j].c=='.' || mapA[i+1][j].c=='.' || mapA[i][j-1].c=='.' || mapA[i][j+1].c=='.') {
					mapB[i][j].c = '.';
				}
			}
		}
	}
	//��ӡ��ͼA
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			cout << mapA[i][j].c;
		}
		cout << " " << endl;
	}
	//�����ͼA�ĵ���
	groupANum = 1;
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			if(mapA[i][j].c=='#' && mapA[i][j].isVisited==0) {
				dfs(mapA,i,j,N,groupANum);
				groupANum++;
			}
		}
	}
	groupANum--;
	cout << groupANum << endl;
	cout << "----------------" << endl;
	//��ӡЧ��ͼB
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			cout << mapB[i][j].c;
		}
		cout << " " << endl;
	}
	//����Ч��ͼB�ĵ���
	groupBNum = 1;
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			if(mapB[i][j].c=='#' && mapB[i][j].isVisited==0) {
				dfs(mapB,i,j,N,groupBNum);
				groupBNum++;
			}
		}
	}
	groupBNum--;
	cout << groupBNum << endl;
	cout << "----------------" << endl;
	cout << groupANum-groupBNum << endl;
	return 0;
}
