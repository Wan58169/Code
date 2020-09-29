#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

//定义1个输入文件和8个输出文件
FILE *inFile;
FILE *bufFiles[8];
FILE *outFiles[8];

//十六进制字符串转为十进制
int SixTeenCHarToTenInt(char *s)
{   
    int ret;
    
    sscanf(s,"%x",&ret);

    return ret;
}

//将连续的各段分别写入不同的文件中
void writeInToFile(FILE *fp,char *s)
{
    //写入语句
    fprintf(fp,"%s",s);
}

//trim(s)
void fixString(char *s,int sLen)
{
    //在;后面添上'\n'
    for(int i=0; i<sLen; i++) {
        if(s[i] == ';') {
            s[i+1] = '\n';
            s[i+2] = '\0';
            break;
        }
    }
}

//取'/'前字符串
void getFormerString(char *s,char *t,int *formerLen)
{
    int idx = 0;

    while(1) {
        if(s[idx] == '/') {
            break;
        } else {
            t[idx] = s[idx];
            idx++;
        }
    }
    t[idx] = '\0';
    *formerLen = idx;
}

//拆分原始文件
void splitFile()
{
    char s[16];                         //读行
    int preRet = -1;                    //上一行前7位的十进制结果
    int fileNo = 0;                     //文件编号

    while(1) {
        if(fscanf(inFile,"%s",s) == EOF) break;
        
        //trim(s)
        fixString(s,strlen(s));

        //取'/'前字符串
        char t[16];
        int tLen = strlen(s);
        getFormerString(s,t,&tLen);
        int ret = SixTeenCHarToTenInt(t);

        if(preRet+1 != ret) {           //如果不连续
            fileNo++;
            writeInToFile(bufFiles[fileNo],s);
        } else if(preRet == ret) {
            break;
        } else {
            writeInToFile(bufFiles[fileNo],s);
        }
        preRet = ret;
    }
}

//读取文件数据并处理
void scanAndprocess(FILE *inFile,FILE *outFile)
{   
    char s[14];                         //读行
    char buf[33];
    int bufIdx = 0;

    while(!feof(inFile)) {
        fscanf(inFile,"%s",s);
        // printf("%s\n",s);
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
}

int main()
{
    //只需修改这两处即可
    char src[6] = "Sim";
    inFile = fopen("sim.txt","r");

    //打开newxxx.txt，设置只写
    for(int i=0; i<8; i++) {
        char fileName[14];
        sprintf(fileName,"new%s%d.txt",src,i+1);
        bufFiles[i] = fopen(fileName,"w");
    }
    
    //拆分文件
    splitFile();

    //关闭newxxx.txt
    for(int i=0; i<8; i++) {
        fclose(bufFiles[i]);
    }
    
    //打开newxxx.txt，设置只读
    for(int i=0; i<8; i++) {
        char fileName[14];
        sprintf(fileName,"new%s%d.txt",src,i+1);
        bufFiles[i] = fopen(fileName,"r");
    }
    
    //打开utxxx.txt，设置只写
    for(int i=0; i<8; i++) {
        char fileName[14];
        sprintf(fileName,"ut%s%d.txt",src,i+1);
        outFiles[i] = fopen(fileName,"w");
    }
    
    //处理utxxx.txt
    for(int i=0; i<8; i++) {
        scanAndprocess(bufFiles[i],outFiles[i]);
    }

    //关闭newxxx.txt
    for(int i=0; i<8; i++) {
        fclose(outFiles[i]);
    }
    
    return 0;
}
