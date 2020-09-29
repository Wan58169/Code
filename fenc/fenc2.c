#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

//读取文件数据并处理
void scanAndprocess(FILE *inFile,FILE *outFile)
{   
    char s[14];                         //读行
    char buf[33];
    int bufIdx = 0;

    while(!feof(inFile)) {
        fscanf(inFile,"%s",s);
        //取后4个字符
        for(int i=0; i<4; i++) {
            buf[bufIdx++] = s[i+8];
        }
        if(bufIdx == 16) {
            while(bufIdx >= 4) {
                int d = 4;      //增量
                for(int i=bufIdx-d; i<bufIdx; i++) {    //倒着输出
                    fprintf(outFile,"%c",buf[i]);
                }
                bufIdx -= d;
            }
            fprintf(outFile,"\n");
        }
    }
    //当读完最后一行时
    while(bufIdx >= 4) {
        int d = 4;              //增量
        for(int i=bufIdx-d; i<bufIdx; i++) {
            fprintf(outFile,"%c",buf[i]);
        }
        bufIdx -= d;
    }
}

int main()
{
    FILE *inFile1 = fopen("newFenc1.txt","r");
    FILE *inFile2 = fopen("newFenc2.txt","r");
    FILE *inFile3 = fopen("newFenc3.txt","r");
    FILE *outFile1 = fopen("utFenc1.txt","w");
    FILE *outFile2 = fopen("utFenc2.txt","w");
    FILE *outFile3 = fopen("utFenc3.txt","w");
    
    int rowNum1 = 12288;                //newFenc1.txt文件行数
    int rowNum2 = 76032;                //newFenc2.txt文件行数
    int rowNum3 = 76032;                //newFenc3.txt文件行数

    scanAndprocess(inFile1,outFile1);
    scanAndprocess(inFile2,outFile2);
    scanAndprocess(inFile3,outFile3);

    fclose(inFile1);
    fclose(inFile2);
    fclose(inFile3);
    fclose(outFile1);
    fclose(outFile2);
    fclose(outFile3);
    
    return 0;
}
