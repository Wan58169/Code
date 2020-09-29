#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

char *earthStrings[] = {"tret",
						"jan", "feb", "mar", "apr",
	 					"may", "jun", "jly", "aug",
						"sep", "oct", "nov", "dec"};
char *marsStrings[] = {"tam", "hel", "maa", "huh",
						"tou", "kes", "hei", "elo",
						"syy", "lok", "mer", "jou"};

int findPos(char *s,char *array[],int len)
{
	for(int i=0; i<len; i++) {
		if(strcmp(s,array[i]) == 0) {
			return i;
		}
	}

	return -1;
}

void numberIntoString(char *buf,int *high,int *low)
{
	int org = atoi(buf);

	if(org < 13) {
		printf("%s\n",earthStrings[org]);
	} else {
		*low = org%13;
		*high = org/13;
		if(*low == 0)
			printf("%s\n",marsStrings[*high-1]);
		else 
			printf("%s %s\n",marsStrings[*high-1],earthStrings[*low]);
	}

}

void stringIntoNumber(char *buf,int *high,int *low)
{
	char *lowString,*highString;
	
	highString = strtok(buf," ");
	lowString = strtok(NULL,"");
	if(lowString != NULL) {
		*low = findPos(lowString,earthStrings,13);
		*high = findPos(highString,marsStrings,12)+1;
	} else if(lowString == NULL) {
		if(findPos(highString,marsStrings,12) != -1) {
			*high = findPos(highString,marsStrings,12)+1;
			*low = 0;
		} else if(findPos(highString,earthStrings,13) != -1) {
			*high = 0;
			*low = findPos(highString,earthStrings,13);
		}
	}
	int sum = (*high)*13 + *low;
	printf("%d\n",sum);

}

int main()
{
	int n;

	scanf("%d",&n);
	getchar();
	for(int i=0; i<n; i++) {
		char buf[256];
		fgets(buf,sizeof(buf),stdin);
		buf[strlen(buf)-1] = '\0';
		int high,low,org;
		if(isdigit(buf[0])) 
			numberIntoString(buf,&high,&low);
		else if(isalpha(buf[0])) 
			stringIntoNumber(buf,&high,&low);
	}
	
	return 0;
}
