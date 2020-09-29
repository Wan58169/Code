#include <stdio.h>
#include <string.h>

void trim(char *s, int sLen)
{
    for(int i=0; i<sLen; i++) {
        if(s[i] == '\n') {
            s[i] = '\0';
        }
    }
}

int main()
{
    FILE *fp = fopen("4.1-grep.txt", "r");

    int rowNum;
    char target[12];
    char buf[128];
    int targetLen, bufLen;

    rowNum = 0;
    targetLen = sizeof(target)/sizeof(char);
    bufLen = sizeof(buf)/sizeof(char);

    fgets(target, targetLen, fp);
    trim(target, targetLen);

    while( fgets(buf, bufLen, fp) ) {
        rowNum++;
        char *idx = strstr(buf, target);
        // printf("%s", rowNum, buf);
        if( idx ) {
            printf("%d:%s", rowNum, buf);
        }
    }

    return 0;
}