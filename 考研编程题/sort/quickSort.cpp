//快速排序

//a为待排数组，left为数组左端下标，right为数组右端下标
int partition(int a[],int left,int right)
{	
	int pivot = a[left];          //主元

    while(left < right) {   
        while(left<right && a[right]>=pivot)        //从后往前，滤过>pivot的数
            right--;
        if(left < right)    a[left++] = a[right];   //停下来与前面交换
        while(left<right && a[left]<=pivot)         //从前往后，滤过<pivot的数
            left++;     
        if(left < right)    a[right--] = a[left];   //停下来与后面交换
    }
    a[left] = pivot;                                //主元归位
    return left;                                    //返回主元下标
}

void quickSort(int a[],int left,int right)
{
    if(left < right) {
        int pos = partition(a,left,right);          //确定主元位置
        quickSort(a,left,pos-1);                    //给左半边排序
        quickSort(a,pos+1,right);                   //给右半边排序
    }
}