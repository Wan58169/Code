//��������
//�����������һ��ͼ�ľŹ����У����� 1~8 �����ֿ�Ƭ������һ�����ӿ��š���ո������ڵĸ����еĿ�Ƭ�����ƶ����ո��С�
//	  �������ɴ��ƶ��������γɵڶ���ͼ��ʾ�ľ��档
//		1 2 3       1 2 3
// 		4 5 6       0 4 6
//		7 8 0       7 5 8
//�������ǰѵ�һ��ͼ�ľ����Ϊ��12345678.
//�����ѵڶ���ͼ�ľ����Ϊ��123.46758
//������Ȼ�ǰ����ϵ��£������ҵ�˳���¼���֣��ո��Ϊ��㡣
//��������Ŀ����������֪�Ź��ĳ�̬����̬�������پ������ٲ����ƶ����Ե��������۶��ٲ����޷���������-1��
//�����ʽ
//���������һ�а����Ź��ĳ�̬���ڶ��а����Ź�����̬��
//�����ʽ
//����������ٵĲ�������������ڷ����������-1��
//��������
//12345678.
//123.46758
//�������
//3
//��������
//13524678.
//46758123.
//�������
//22
#include<iostream>
#include<set>
#include<queue>
using namespace std;

struct status {
	string des;			//״̬���� 
	int pos;			//�ո�λ�� 
	int step;			//�����״̬�Ĳ��� 
	
	status(string s) {
		step = 0;
		des = s;
		for(int i=0; i<des.length(); i++) {
			if(des[i] == '.') {
				des[i] = '0';
				pos = i;
				break;
			}
		}
	}
	status(const status & t) {
		des = t.des;
		pos = t.pos;
		step = t.step;
	}
	bool operator<(const status & s) const {			//��������<,����set 
		int ret = des.compare(s.des);
		if(ret >= 0)
			return false;
		else if(ret < 0)
			return true;
	}
	status operator=(const status & s) {				//��������=,���ڽṹ�帳ֵ 
		des = s.des;
		pos = s.pos;
		step = s.step;
		return s;
	}
	bool operator==(const status &s) const {			//��������==,���ڽṹ��Ƚ� 
		if(des == s.des)
			return true;
		else 
		 	return false;
	}
};
set<status> s;			//����s�������� 
queue<status> q;        //����q����bfs 

status move(int dir,const status & t)
{
	status ret(t);
	
	switch(dir) {
		case 1 : {		//�� 
			if(t.pos>2 && t.pos<=8) {
				ret.des[t.pos] = t.des[t.pos-3],ret.des[t.pos-3] = '0';
				ret.step++,ret.pos = t.pos-3; 
			}
			break;
		}
		case 2 : {		//�� 
			if(t.pos<6 && t.pos>=0) {
				ret.des[t.pos] = t.des[t.pos+3],ret.des[t.pos+3] = '0';
				ret.step++,ret.pos = t.pos+3; 	
			}
			break;
		}
		case 3 : {		//�� 
			if(t.pos!=0 && t.pos!=3 && t.pos!=6) {
				ret.des[t.pos] = t.des[t.pos-1],ret.des[t.pos-1] = '0';
				ret.step++,ret.pos = t.pos-1; 
			}
			break;
		}
		case 4 : {		//�� 
			if(t.pos!=2 && t.pos!=5 && t.pos!=8) {
				ret.des[t.pos] = t.des[t.pos+1],ret.des[t.pos+1] = '0';
				ret.step++,ret.pos = t.pos+1; 
			}
			break;
		}
	}	
	if(s.find(ret) == s.end()) 
		s.insert(ret),q.push(ret);
	return ret;
}
int main()
{
	freopen("19.txt","r",stdin);
	//������ʼ����ֹ״̬ 
	string s1,s2;
	cin >> s1 >> s2;
	//״̬��� 
	status start(s1),end(s2);
	status now(""),next("");
	//bfs
	s.insert(start),q.push(start);
	while(!q.empty()) {
		now = q.front();
		q.pop();
		//��������������̽ 
		for(int i=1; i<=4; i++) {
			next = move(i,now);
			if(next == end) {				//�������ֹ״̬ 
				cout << next.step << endl;
				return 0;
			}
		}
	}
	cout << -1 << endl;
	return 0;
}
