#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char s[24];
}String;

//返回数组长度
int getArrayLen(char buf[]) 
{
    int idx = 0;

    while(buf[idx++] != '\0')
        ;
    
    return idx;
}

//拆分buf-> map<idx, value>
void split(char buf[], int bufLen, char value[], int *valueLen, char idxBuf[], int *idxLen)
{
    int i;

    //分解出value
    for(i=0; i<bufLen; i++) {
        if(buf[i] == '@') {
            break;
        } else {
            value[i] = buf[i];
        }
    }
    value[i] = '\0';
    *valueLen = ++i;

    //分解成idxBuf
    for(; i<bufLen; i++) {
        idxBuf[i-*valueLen] = buf[i];
    }
    *idxLen = i-*valueLen;
}

//判断是否有@
int hasFlag(char buf[], int bufLen)
{
    for(int i=0; i<bufLen; i++) {
        if(buf[i] == '@') {
            return 1;
        } 
    }
    return 0;
}

//将idxBuf十六进制字符串转换为十进制
int transformIdxBuf(char idxBuf[])
{
    int idx;
    sscanf(idxBuf, "%x", &idx);

    return idx;
}

//把value内容拷贝到map[idx]
void assign(char value[], int valueLen, String *map, int idx)
{
    for(int i=0; i<valueLen; i++) {
        map[idx].s[i] = value[i];
    }
}

//扫描 & 处理  
void scanIntoMap(char fileName[], String *map)
{
    FILE *in = fopen(fileName, "r");

    char buf[30];
    int bufLen = 0;
    char value[20];
    int valueLen = 0;
    char idxBuf[10];
    int idxLen = 0;
    int no = 1;
    int maxIdx = -1;

    while(1) {
        if(fscanf(in, "%s", buf) == EOF) break;
        
        //获取buf长度
        bufLen = getArrayLen(buf);
        // printf("%s-%d\n", buf, bufLen);
        //判断是否有@
        if(!hasFlag(buf, bufLen)) continue;
       
        //拆分buf-> map<idx, value>
        split(buf, bufLen, value, &valueLen, idxBuf, &idxLen);

        // printf("%d\n", idxLen);
        //如果@之后的地址不等于8位（长度为9），则丢掉
        if(idxLen != 9) continue;

        int idx = transformIdxBuf(idxBuf);
        
        if(maxIdx < idx) maxIdx = idx;
        printf("%d:%s@%d\n", no++, value, idx);
        
        //把value内容拷贝到map[idx]
        assign(value, valueLen, map, idx);
        
    }
    // printf("maxIndx..%d\n", maxIdx);
    fclose(in);
}

//value是否为null
int valueIsNull(char s[])
{
    if(s[0]=='n' && s[1]=='u' && s[2]=='l' && s[3]=='l') {
        return 1;
    } else {
        return 0;
    }
}

//输出到指定文件
void putIntoFile(char fileName[], String *map, int mapLen)
{
    FILE *out = fopen(fileName, "w");

    for(int i=0; i<mapLen; i++) {
        if(!valueIsNull(map[i].s)) {
            fprintf(out, "%s@%x\n", map[i].s, i);
        }
    }   

    fclose(out);
}

//初始化map
void initMap(String *map, int mapLen)
{
    for(int i=0; i<mapLen; i++) {
        map[i].s[0] = 'n';
        map[i].s[1] = 'u';
        map[i].s[2] = 'l';
        map[i].s[3] = 'l';
    }   
}

//打印map 用于测试
void printMap(String *map, int mapLen)
{
    int no = 0;

    for(int i=0; i<mapLen; i++) {
        if(!valueIsNull(map[i].s)) {
            printf("%d:%s\n", no++, map[i].s);
        }
    }    
}

int main()
{
    String *map;
    int mapLen = 1024*1024*8;

    map = (String *)malloc(sizeof(String)*mapLen);

    char *inFileName = "kv04.txt";
    char *outFileName = "out.txt";

    //初始化map
    initMap(map, mapLen);

    //扫描 & 处理
    scanIntoMap(inFileName, map);

    // printMap(map, mapLen);

    //输出到指定文件
    putIntoFile(outFileName, map, mapLen);

    return 0;
}