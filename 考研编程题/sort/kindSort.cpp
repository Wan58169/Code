//分类排序

void swap(int & a,int & b)
{
    int t;

    t = a, a = b, b = t;
}
void kindSort(int a[],int length)
{
    int left = 0;
    int right = length-1;

    while(left < right) {
        while(left<right && a[right]>0) {
            right--;
        }
        while(left<right && a[left]<0) {
            left++;
        }
        swap(a[left],a[right]);
    }
}


