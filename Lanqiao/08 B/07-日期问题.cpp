#include<iostream>
#include<set>
using namespace std;
//标题：日期问题
//
//小明正在整理一批历史文献。这些历史文献中出现了很多日期。小明知道这些日期都在1960年1月1日至2059年12月31日。令小明头疼的是，这些日期采用的格式非常不统一，有采用年/月/日的，有采用月/日/年的，还有采用日/月/年的。更加麻烦的是，年份也都省略了前两位，使得文献上的一个日期，存在很多可能的日期与其对应。  
//
//比如02/03/04，可能是2002年03月04日、2004年02月03日或2004年03月02日。  
//
//给出一个文献上的日期，你能帮助小明判断有哪些可能的日期对其对应吗？
//
//输入
//----
//一个日期，格式是"AA/BB/CC"。  (0 <= A, B, C <= 9)  
//
//输出
//----
//输出若干个不相同的日期，每个日期一行，格式是"yyyy-MM-dd"。多个日期按从早到晚排列。  
//
//样例输入
//----
//02/03/04  
//
//样例输出
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
    //判断是否为闰年 
    bool isLeap(int y) {
		if(y%400==0 || year%4==0&&year%100!=0) {
			return true;
		}
		return false;
	}
	//判断日期是否合法 
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
	//年月日
	add(1900+a,b,c);
	add(2000+a,b,c);
	//月日年
	add(1900+c,a,b);
	add(2000+c,a,b);
	//日月年
	add(1900+c,b,a);
	add(2000+c,b,a);	
	//输出结果
	set<Date>::iterator it;
	for(it=ds.begin(); it != ds.end(); it++) {
		it->print();
	} 
	return 0;
}
