#include<iostream>
#include<set>
using namespace std;
//���⣺��������
//
//С����������һ����ʷ���ס���Щ��ʷ�����г����˺ܶ����ڡ�С��֪����Щ���ڶ���1960��1��1����2059��12��31�ա���С��ͷ�۵��ǣ���Щ���ڲ��õĸ�ʽ�ǳ���ͳһ���в�����/��/�յģ��в�����/��/��ģ����в�����/��/��ġ������鷳���ǣ����Ҳ��ʡ����ǰ��λ��ʹ�������ϵ�һ�����ڣ����ںܶ���ܵ����������Ӧ��  
//
//����02/03/04��������2002��03��04�ա�2004��02��03�ջ�2004��03��02�ա�  
//
//����һ�������ϵ����ڣ����ܰ���С���ж�����Щ���ܵ����ڶ����Ӧ��
//
//����
//----
//һ�����ڣ���ʽ��"AA/BB/CC"��  (0 <= A, B, C <= 9)  
//
//���
//----
//������ɸ�����ͬ�����ڣ�ÿ������һ�У���ʽ��"yyyy-MM-dd"��������ڰ����絽�����С�  
//
//��������
//----
//02/03/04  
//
//�������
//----
//2002-03-04  
//2004-02-03  
//2004-03-02  


int md[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

class Date {
private:
	int year;
	int month;
	int day;
public:
	Date(int y,int m,int d) {
		year = y;
		month = m;
		day = d;
	}
	bool operator < (Date obj2)const{
        if(year == obj2.year) {
			if(month == obj2.month) {
				return day<obj2.day;
			} else {
				return month<obj2.month;
			}
		} 
		return year<obj2.year;
    }
    //�ж��Ƿ�Ϊ���� 
    bool isLeap(int y) {
		if(y%400==0 || year%4==0&&year%100!=0) {
			return true;
		}
		return false;
	}
	//�ж������Ƿ�Ϸ� 
    bool isLegal() {
    	if(year<1960 || year>2059) {
			return false;
		} 
		if(month == 2) {
			if(isLeap(year)) {
				return day<=29;
			} else {
				return day<=28;
			}
		} 
		if(month > 12) {
			return false;
		} else if(month>=1 && month<=12) {
			return day<=md[month];
		}
	}
	void print() const {
		printf("%d-%02d-%02d\n",year,month,day);
	}
};

set<Date> ds;

void add(int y,int m,int d)
{
	Date obj(y,m,d);
	
	if(obj.isLegal()) {
		ds.insert(obj);
	}
}
int main()
{
	int a,b,c;
	//xx-xx-xx
	//a  b  c
	scanf("%d/%d/%d",&a,&b,&c);
	//������
	add(1900+a,b,c);
	add(2000+a,b,c);
	//������
	add(1900+c,a,b);
	add(2000+c,a,b);
	//������
	add(1900+c,b,a);
	add(2000+c,b,a);	
	//������
	set<Date>::iterator it;
	for(it=ds.begin(); it != ds.end(); it++) {
		it->print();
	} 
	return 0;
}
