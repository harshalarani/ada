 #include<stdio.h>
#include<time.h>
#include<stdlib.h>
void conquor(int arr[], int s,int mid,int e)
{
    int merged[e-s+1];
    int i1=s;
    int i2=mid+1;
    int x=0;
    while(i1<=mid && i2<=e)
    {
        if(arr[i1]<=arr[i2])
        {
            merged[x]=arr[i1];
            x++;
            i1++;
        }
        else
        {
            merged[x]=arr[i2];
            x++;
            i2++;
        }
    }
    while(i1<=mid)
    {
        merged[x]=arr[i1];
        x++;
        i1++;
    }
    while(i2<=e)
    {
        merged[x]=arr[i2];
        x++;
        i2++;
    }
    for(int i=0;i<x;i++)
    {
        arr[i+s]=merged[i];
    }

}
void divide(int arr[], int s, int e)
{
    if(s>=e)
    return;
    int mid=s+(e-s)/2;
    divide(arr,s,mid);
    divide(arr,mid+1,e);
    conquor(arr,s,mid,e);
}
void main()
{
    clock_t st,et;
    double ts;
    int n= rand()%100+50; // General formala is: rand()%range+min
    printf("Size of array:%d\n",n);
    int arr[n];
    for(long i=0;i<n;i++)
    {
        arr[i]=rand()%100+1;//random number from 1 to 100
    }
    /*printf("Original array:\n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");*/
    st=clock();
    divide(arr,0,n-1);
    et=clock();
    ts=(double)((et-st)/CLOCKS_PER_SEC);
    printf("Sorted array:\n");
    for(long i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\nThe time taken for merge sort is: %f\n",ts);
}
