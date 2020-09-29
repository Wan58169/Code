//11-ɢ��3 QQ�ʻ����������½
//ʵ��QQ���ʻ���������ʻ���½�ļ򻯰湦�ܡ������ս�ǣ���˵���ڵ�QQ�����Ѿ���10λ���ˡ�
//
//�����ʽ
//�������ȸ���һ��������N��������N��ָ�ÿ��ָ��ĸ�ʽΪ������������ո�QQ���루�ո����롱��
//���������Ϊ��N��������New��ʱ��ʾҪ������һ��QQ�ţ����������ʻ��ĺ�������룻
//�����Ϊ��L��������Login��ʱ��ʾ�����ʻ���½�������ǵ�½��Ϣ��
//QQ����Ϊһ��������10λ��������1000����˵QQ���ܵĺ�����1001����������
//����Ϊ��С��6λ��������16λ���Ҳ������ո���ַ����� 
//
//�����ʽ 
//���ÿ��ָ�������Ӧ����Ϣ��
//
//1�����������ʻ��ɹ����������New: OK����
//2����������ĺ����Ѿ����ڣ��������ERROR: Exist����
//3�������ʻ���½�ɹ����������Login: OK����
//4�������ʻ�QQ���벻���ڣ��������ERROR: Not Exist����
//5�������ʻ���������������ERROR: Wrong PW����
//
//��������
//
//L 1234567890 myQQ@qq.com
//N 1234567890 myQQ@qq.com
//N 1234567890 myQQ@qq.com
//L 1234567890 myQQ@qq
//L 1234567890 myQQ@qq.com
//
//�������
//ERROR: Not Exist
//New: OK
//ERROR: Exist
//ERROR: Wrong PW
//Login: OK 
#include<iostream>
#include<map>
using namespace std;

map<string,string> m;

int main()
{
	//freopen("11-3.txt","r",stdin);
	int N;
	string order,user,pwd;
	
	cin >> N;
	cin.get();
	while(N--) {
		cin >> order >> user >> pwd;
		map<string,string>::iterator it;
		it = m.find(user);
		if(order == "N") {									//�������� 
			if(it == m.end()) {						//�û������� 
				m.insert(pair<string,string>(user,pwd));
				cout << "New: OK" << endl;	
			} else {
				cout << "ERROR: Exist" << endl;	
			}
		} else {											//��¼���� 
			if(it == m.end()) {								//�û������� 
				cout << "ERROR: Not Exist" << endl; 
			} else {										//��ȡ�û����� 
				string tpwd = (*it).second;
				if(tpwd == pwd) {							//������ȷ 
					cout << "Login: OK" << endl;
				} else {
					cout << "ERROR: Wrong PW" << endl;
				}
			}
		}
	}
	return 0;
}
