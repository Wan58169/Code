#include <stdio.h>

#define IN 0    //单词内
#define OUT 1   //单词外

int main()
{
    int c, nc, nl, nw, state;

    state = OUT;    //默认开始时在单词外
    nc = nl = nw = 0;

    while( (c=getchar()) != EOF) {
        nc++;
        if(c == '\n') {
            nl++;
        }
        if(c=='\n' || c=='\t' || c==' ') {
            state = OUT;
        } else if (state == OUT) {
            state = IN;
            nw++;
        }
    }
    printf("行数为%d，单词数为%d\n", nl++, nw++);

    return 0;
}
