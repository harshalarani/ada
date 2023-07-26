#include<stdio.h>
#include<time.h>
#include<stdlib.h>
void swap(int *a,int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
int partition(int arr[],int l,int r)
{
    //ascending order
    int pivot=arr[r];
    int i=l-1,j;
    for(j=l;j<=r-1;j++)
    {
        if(arr[j]<pivot)
        {
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[r]);
    return (i+1);

}
void quicksort(int arr[],int l,int r)
{
    int split;
    if(l<r)
    {
        split=partition(arr,l,r);
        quicksort(arr,l,split-1);
        quicksort(arr,split+1,r);
    }
}
void print(int arr[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }
}
void main()
{
    int arr[200000],n,i;
    clock_t st,et;
    float ts;
    printf("Enter the size of the array\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        arr[i]=rand();
    }
    if(n<=20)
    {
    	printf("before sorting \n");
        print(arr,n);
	}
    st=clock();
    //print(arr,n);
    quicksort(arr,0,n-1);
    et=clock();
    ts=(float)(et-st)/CLOCKS_PER_SEC;
    if(n<=20)
    {
    	printf("\nafter sorting using quicksort\n");
        print(arr,n);
	}
   
    printf("\nTime taken \t %f ",ts);


}
