//选择排序

void swap(int & a,int & b)
{
    int t;
    t = a,a = b,b = t;
}

void select_sort(int a[],int aLen)
{
    for(int i=0; i<aLen; i++) {
        int min = i;
        for(int j=i; j<aLen; j++) {
            if(a[j] < a[min]) {
                min = j;
            }
        }
        swap(a[i],a[min]);
    }
}
