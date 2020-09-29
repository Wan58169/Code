#include<stdio.h>
#include<string.h>

#define LEN 100

//计算位数
int cal_weishu(int n)
{
	int weishu = 0;

	while(n != 0) {
		weishu++;
		n /= 10;
	}
	return weishu;
}

int main()
{
	char buf[LEN+1] = "";	//存储自然数
	int len;				//自然数的长度
	int sum = 0;			//自然数的各位之和

	scanf("%s",buf);
	len = strlen(buf);

	for(int i=0; i<len; i++)
		sum += buf[i]-'0';
	
	char* pinyin[] = {"ling","yi","er","san","si","wu",
						"liu","qi","ba","jiu","shi"};
	int weishu = cal_weishu(sum);
	char* ret[weishu];
	//进行赋值
	for(int i=weishu-1; i>=0; i--) {
		ret[i] = pinyin[sum%10];
		sum /= 10;
	}
	//打印
	for(int j=0; j<weishu-1; j++) {
		printf("%s ",ret[j]);
	}
	printf("%s",ret[weishu-1]);
	return 0;
}
