#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
	freopen("data.txt","r",stdin);

	char buf1[100];
	char buf2[100];
	char buf3[100];
	char buf4[100];

	//获取信息
	fgets(buf1,100,stdin);
	buf1[strlen(buf1)-1] = '\0'; 
	fgets(buf2,100,stdin);
	buf2[strlen(buf2)-1] = '\0';
	fgets(buf3,100,stdin);
	buf3[strlen(buf3)-1] = '\0';
	fgets(buf4,100,stdin);
	buf4[strlen(buf4)-1] = '\0';

	int i = 0;
	int j = 0;
	int flag = 1;
	char day[3];
	int hour = 0;

	//处理day和hour
	while(buf1[i]!='\0' && buf2[j]!='\0') {
		if(buf1[i] == buf2[j]) {
			if(flag == 1) {
				switch(buf1[i]) {
					case 'A': strcpy(day,"MON"); flag++; break;
					case 'B': strcpy(day,"TUE"); flag++; break;
					case 'C': strcpy(day,"WED"); flag++; break;
					case 'D': strcpy(day,"THU"); flag++; break;
					case 'E': strcpy(day,"FRI"); flag++; break;
					case 'F': strcpy(day,"SAT"); flag++; break;
					case 'G': strcpy(day,"SUN"); flag++; break;
					default : break;
				}
			} else if(flag == 2) {
				if(buf1[i]>='0' && buf1[i]<='9') {
					hour = buf1[i]-'0';
					break;
				}
				else if(buf1[i]>='A' && buf1[i]<='N') {
					hour = buf1[i]-55;	
					break;
				}
			}
		} 
		i++;
		j++;
	}
	//处理mintue
	i = 0;
	j = 0;
	int minute = 0;
	
	while(buf3[i]!='\0' && buf4[j]!='\0') {
		if(buf3[i]==buf4[j] && ((buf3[i]>='A'&&buf3[i]<='Z')||(buf3[i]>='a'&&buf3[i]<='z')) ) {
			minute = i;
			break;
		}
		i++;
		j++;
	}
	
	printf("%s ",day);
	
	if(hour<=9) printf("0%d:",hour);
	else printf("%d:",hour);
	
	if(minute<=9) printf("0%d",minute);
	else printf("%d",minute);
	
	return 0;
}
