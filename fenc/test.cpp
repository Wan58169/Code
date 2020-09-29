#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

using namespace std;

int SixTeenCHarToTenInt(char *s,int n)
{   
    int sum = 0;
    int idx = 0;

    for(int i=n-1; i>=0; i--) {
        if(s[i]>='a' && s[i]<='f') {
            sum += (s[i]-'a'+10)*pow(16,idx);
        } else {
            sum += (s[i]-'0')*pow(16,idx);
        }
        idx++;
    }
    return sum;
}

int myPow(int basic,int x)
{
    int ret = 1;

    for(int i=0; i<x; i++) {
        ret *= basic;
    }

    return ret;
}

//读取文件数据并处理
void scanAndprocess(FILE *inFile,FILE *outFile,int rowNum)
{   
    char s[15];                         //读行
    char buf[33];
    int bufIdx = 0;

    while(!feof(inFile)) {
        fscanf(inFile,"%s",s);
        // fgets(s,13,inFile);
        s[13] = '\n';
        s[14] = '\0';
        fprintf(outFile,"%s",s);
        // fputs(s,outFile);
        
        // printf("rowNum..%d\n",rowNum);
        // printf("%s",s);
        //取后4个字符
        // char t2[4];
        // for(int i=0; i<4; i++) {
        //     t2[i] = s[i+8];
        // }
        // for(int i=0; i<4; i++) {
        //     buf[bufIdx++] = t2[i];
        // }
        // if(bufIdx == 16) {
        //     while(bufIdx >= 4) {
        //         int d = 4;
        //         for(int i=bufIdx-d; i<bufIdx; i++) {
        //             printf("%c",buf[i]);
        //         }
        //         bufIdx -= d;
        //     }
        //     printf("\n");
        // }
    }
    //当读完最后一行时
    // while(bufIdx >= 4) {
    //     int d = 4;
    //     for(int i=bufIdx-d; i<bufIdx; i++) {
    //         printf("%c",buf[i]);
    //     }
    //     bufIdx -= d;
    // }
    // printf("\n");
}

int main()
{
    FILE *inFile1 = fopen("newFenc1.txt","r");
    FILE *outFile1 = fopen("utFenc1.txt","w");
    
    int rowNum1 = 12288;                //newFenc1.txt文件行数
    int rowNum2 = 76032;                //newFenc2.txt文件行数
    int rowNum3 = 76032;                //newFenc3.txt文件行数

    scanAndprocess(inFile1,outFile1,rowNum1);

    fclose(inFile1);
    fclose(outFile1);
    
    return 0;
}

// int main()
// {
//     char s[7];

//     scanf("%s",s);
//     cout <<SixTeenCHarToTenInt(s,strlen(s)) << endl;
//     // int fileNo = 5;
//     // char fileName[14];
//     // //封装文件名
//     // sprintf(fileName,"utFenc%d.txt",fileNo);
//     // cout << fileName << endl;
//     // cout << myPow(16,3) << endl;
    

//     return 0;
// }