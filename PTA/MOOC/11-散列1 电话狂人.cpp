//11-ɢ��1 �绰������ˣ�25 �֣�
//���������ֻ��û�ͨ����¼���ҳ�����ͨ����������������ˡ�
//
//�����ʽ:
//
//�������ȸ���������N<=100000Ϊͨ����¼������
//���N�У�ÿ�и���һ��ͨ����¼�������������ֻ�г��������ͽ��շ���11λ���ֹ��ɵ��ֻ����룬�����Կո�ָ���
//
//�����ʽ:
//
//��һ���и���������˵��ֻ����뼰��ͨ������������Կո�ָ�������������˲�Ψһ���������������С�ĺ��뼰��ͨ�����������Ҹ��Ӹ������п��˵�������
//
//��������:
//
//4
//13005711862 13588625832
//13505711862 13088625832
//13588625832 18087925832
//15005713862 13588625832
//�������:
//
//13588625832 3
#include<iostream>
#include<map>
using namespace std;

map<string,int> m;

int main()
{
	freopen("11-1.txt","r",stdin);
	int N;
	map<string,int>::iterator it;
	
	cin >> N;
	cin.get();
	while(N--) {
		string number1,number2;
		cin >> number1 >> number2;
		//����number1 
		it = m.find(number1);
		if(it == m.end()) {
			m.insert(pair<string,int>(number1,1));
		} else {
			(*it).second++;
		}
		//����number2
		it = m.find(number2);
		if(it == m.end()) {
			m.insert(pair<string,int>(number2,1));
		} else {
			(*it).second++;
		} 
	}
	//�����
	int max = 0;
	for(it=m.begin(); it!=m.end(); it++) {
		if(max <= (*it).second) {
			max = (*it).second;
		}
	}
	//��ӡ��С�绰���� 
	int cnt = 0;
	string minNumber;
	//�ҵ���һ��������� 
	for(it=m.begin(); it!=m.end(); it++) {
		if((*it).second == max) {
			minNumber = (*it).first;
			cnt++;
			break;
		}
	}
	it++;
	//�ҳ���С�绰���� �� ��һ��������˵ĸ��� 
	for(; it!=m.end(); it++) {
		if((*it).second == max) {
			if((*it).first < minNumber) {
				minNumber = (*it).first;
			}
			cnt++;
		}
	}
	if(cnt == 1) 
		cout << minNumber << " " << max << endl;
	else
 		cout << minNumber << " " << max << " " << cnt << endl;
	return 0;
}








