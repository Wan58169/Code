#include<iostream>
using namespace std;

string pre,in;
//preL为前序序列的第一个结点，inL为中序,postL为后序,n为序列长度
void f(int preL,int inL,int postL,int n,string & post)
{
    int i;
    char root;

    if(n == 0) return;
    
    //在后序序列中安放根结点
    root = pre[preL];
    post[postL+n-1] = root;
    //在中序序列中确定根结点位置
    for(i=0; i<n; i++) {
        if(in[inL+i] == root) break;
    }
    //L为左子树个数，R为右子树个数
    int L = i,R = n-i-1;
    f(preL+1,inL,postL,L,post);                   //左子树
    f(preL+i+1,inL+i+1,postL+i,R,post);           //右子树
}

int main(int argc, char const *argv[])
{
    cin >> pre >> in;

    string post(pre.length(),'x');
    
    f(0,0,0,pre.length(),post);

    cout << post << endl;

    return 0;
}
