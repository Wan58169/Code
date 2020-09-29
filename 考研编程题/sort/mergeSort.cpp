//归并排序 递归
//L=左边起始位置，R=右边起始位置，RightEnd=右边终点位置
void merge(int A[],int TmpA[],int L,int R,int RightEnd)
{
	int LeftEnd = R-1;
	int Tmp = L;
	int NumOfElements = RightEnd-L+1;

	while(L<=LeftEnd && R<=RightEnd) { /* 归并 */
		if(A[L] < A[R])
			TmpA[Tmp++] = A[L++];
		else 
			TmpA[Tmp++] = A[R++];
	}
	while(L <= LeftEnd) {	/* 左剩余 */
		TmpA[Tmp++] = A[L++];
	}
	while(R <= RightEnd) {	/* 右剩余 */
		TmpA[Tmp++] = A[R++];
	}
	for(int i=0; i<NumOfElements; i++)
		A[i] = TmpA[i];
}

void mergeSort(int A[],int TmpA[],int L,int RightEnd)
{
    int Center;
	
    if(L < RightEnd) {
		Center = (L+RightEnd)/2;
		mergeSort(A,TmpA,L,Center);
        mergeSort(A,TmpA,Center+1,RightEnd);
		merge(A,TmpA,L,Center+1,RightEnd);
	}
}