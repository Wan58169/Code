#include<stdio.h>
#include<string.h>

int cnt = 0;

int calVerifyTime(char pwd[],int pwdLen)
{
	int i,index;
	int ret;

	for(i=0; pwd[i]!=' '; i++) 
			;
	index = i+1;
	if(pwd[index+1] == '0') {
		ret = 10;
	} else {
		ret = pwd[index]-'0';
	}
	pwd[i] = '\0';
//	printf("%s|\n",pwd);
	return ret;
}

void f(char pwd[],int verifyTime)
{
	char buf[30];

	while(1) {
		scanf("%s",buf);
		if(buf[0] != '#') {
			cnt++;
		} else {
			break;
		}
		if(cnt <= verifyTime) {
			if(strcmp(pwd,buf) == 0) {
				printf("Welcome in\n");
				break;
			} else {
				printf("Wrong password: %s\n",buf);
			}
			if(cnt == verifyTime) {
				printf("Account locked\n");
				break;
			}
		}
		
	}

}

int main()
{
	freopen("1067.txt","r",stdin);
	char pwd[30];
	int verifyTime;

	fgets(pwd,30,stdin);
	pwd[strlen(pwd)-1] = '\0';
	verifyTime = calVerifyTime(pwd,strlen(pwd));
	f(pwd,verifyTime);

	return 0;
}
