//��������
//����ս��ʱ�ڣ�����ƽԭ�ĵص�ս��������Ҫ���á�
//
//�ص��Ķ��վ�����ͨ�����ӣ��γ����Ӵ�����硣��Ҳ�������������˷�����ĳ��վ�������վ��������˻�ʧȥ��ϵ��
//
//����������һ��Σ��ϵ��DF(x,y)��
//
//��������վ��x��y (x != y), ������ҵ�һ��վ��z����z�������ƻ���x��y����ͨ����ô���ǳ�zΪ����x,y�Ĺؼ��㡣
//��Ӧ�ģ���������һ��վ��x��y��Σ��ϵ��DF(x,y)�ͱ�ʾΪ������֮��Ĺؼ��������
//
//����������ǣ���֪����ṹ������վ��֮���Σ��ϵ����
//
//�����ʽ
//�������ݵ�һ�а���2������n(2 <= n <= 1000), m(0 <= m <= 2000),�ֱ����վ������ͨ������
//
//������m�У�ÿ���������� u,v (1 <= u, v <= n; u != v)����һ��ͨ����
//
//���1�У�������u,v������ѯ������֮���Σ��ϵ��DF(u, v)��
//
//�����ʽ
//һ�����������ѯ�ʵ����㲻��ͨ�����-1.
//��������
//7 6
//1 3
//2 3
//3 4
//3 5
//4 5
//5 6
//1 6
//�������
//2
#include<iostream>
#include<vector>
using namespace std;

int N,M;								//Nվ����,Mͨ����	 
int map[1001][1001];					//�ڽӾ���
vector<int> v;							//��¼���ʹ��ĵ� 
vector<vector<int> > path(100);			//��¼·��
 
void dfs(int x,int y,int vis[],int pNum)
{
	if(x == y) {
		v.push_back(y);
		return;
	}
	if(vis[x] == 0) {
		vis[x] = 1;		//���ʵ�x�ŵ� 
		v.push_back(x);
	}
	for(int i=1; i<=pNum; i++) {
		if(vis[i]==0 && map[x][i]!=0) {		//û�б����ʹ������ܵ��� 
			dfs(i,y,vis,pNum);
			vis[i] = 0;						//����!!! 
		}
	}
	//�������������,-1�Ǵ�·��ͨ���ź� 
	v.push_back(-1);
}
int main()
{
	freopen("12.txt","r",stdin);
	cin >> N >> M;
	//��ʼ���ڽӾ��� 
	for(int i=1; i<=N; i++) {
		for(int j=1; j<=N; j++) {
			map[i][j] = 0;
		}
	}
	//����� 
	for(int i=0; i<M; i++) {
		int s,e;				//s���,e�յ� 
		cin >> s >> e;
		map[s][e] = 1;
		map[e][s] = 1;
	}
	int x,y;					//DF(x,y)
	cin >> x >> y;
	int vis[N+1] = {0};			//���趼û�з��ʹ� 
	dfs(x,y,vis,N); 
	//����·��
	vector<int>::iterator it,it2;
	int k=0;					//��һ��·��,path�������±� 
	vector<int> vt;				//��ջ,�ݴ洦�����·�� 
	for(it=v.begin(); it!=v.end(); it++) {
		if(*it != -1) {			//��û����������ͬ 
			vt.push_back(*it);
		} else {				//���� 
			for(it2=vt.begin(); it2!=vt.end(); it2++) {
//				cout << *it2 << " ";
				path[k].push_back(*it2);
			}
			k++;
			//ջ�����յ� 
			if(vt.back() == y) {
				vt.pop_back();
			}
			vt.pop_back();
		}
	}
	int df[N+1] = {0}; 					//��¼ÿ������ֵĴ��� 
	int wayNum = 0;						//��¼ͨ���յ������ 
	//������άvector 
	for(int i=0; i<k; i++) {
		if(*(path[i].end()-1) == y) {	//����·��ͨ���յ�� 
			wayNum++;
			for(it=path[i].begin(); it!=path[i].end(); it++) {
				cout << *it << " ";
				if(*it!=x && *it!=y) {
					df[*it]++;
				}
			}
			cout << " " << endl;
		}
	}
	int cnt = 0;						//����� 
	for(int i=1; i<=N; i++) {
		if(df[i] == wayNum) {			
			cnt++;						//ͳ��ÿ��ͨ���յ��·�������ֵĵ� 
		}
	}
	cout << cnt << endl;
	return 0;
}
