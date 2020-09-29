#include<stdio.h>

static void printArray(int a[],int aLen)
{
	int i;

	for(i=0; i<aLen; i++) {
		printf("%d ",a[i]);
	}
	printf("\n");
}

static int maxItem(int a[],int aLen)
{
	int i;
	int max = -1.0e5;

	for(i=0; i<aLen; i++) {
		if(a[i] > max) {
			max = a[i];
		}
	}
	return max;
}

static void myMemset(int c[],int cLen)
{
	int i;

	for(i=0; i<cLen; i++) {
		c[i] = 0;
	}
}

static void myCopy(int a[],int b[],int aLen)
{
	int i;

	for(i=0; i<aLen; i++) {
		a[i] = b[i+1];
	}
}
/********************************************
** �Ƚ��м�����ͳ��ÿ��Item���ֵĴ��� 		*
** �õ�Ƶ�ʱ������ɵ�ַ��,�̶�ά����ַ��  *
** example: 								*
**   0	1	2 	3 	4 	5	6	7 			*
** A:2	5	3	0	2	3	0	3 			*
** C:2	0	2	3	0	1 					*
**C':2	2	4	7	7	8 					*
** B:										*
** Ϊ�˱�֤������ȶ��ԣ�i��A�����β����ʼ *
********************************************/
void cntSort(int a[],int aLen)
{
	int cLen = maxItem(a,aLen)+1;
	int c1[cLen],c2[cLen];
	int i;

	myMemset(c1,cLen);
	//ͳ��Ƶ�ʣ��õ�Ƶ�ʱ�
	for(i=0; i<aLen; i++) {
		c1[a[i]]++;
	}
	//�����ɵ�ַ��
	c2[0] = c1[0];
	for(i=1; i<cLen; i++) {
		c2[i] = c2[i-1]+c1[i]; 
	}
	//��ӡ����������
	int b[aLen+1];
	for(i=0; i<aLen; i++) {
		b[c2[a[i]]] = a[i];
		c2[a[i]]--;
	}
	//�ѽ�����ص�ԭ������
	myCopy(a,b,aLen);
}

int main()
{
	int a[] = {9,7,8,5,6,3,4,1,2,0};
//	int a[] = {2,5,3,0,2,3,0,3};
	int aLen = sizeof(a)/sizeof(a[0]);

	printArray(a,aLen);
	cntSort(a,aLen);
	printArray(a,aLen);

	return 0;
}

