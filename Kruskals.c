#include<stdio.h>
int find(int i,int parent[]){
    if(i!=parent[i])
    i=parent[i];
    return i;
}

void union1(int i,int j,int parent[]){
    if(i<j)
    parent[j]=i;
    else
    parent[i]=j;
}

void kruskal(int n,int a[][50]){
    int i,j,u,v,min;
    int k=0,count=0,sum=0;
    int t[50][50],parent[50];
    for(i=0;i<n;i++){
        parent[i]=i;
    }
    while(count!=n-1){
        min=999;
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                if(a[i][j]<min){
                    min=a[i][j];
                    u=i;
                    v=j;
                }
            }
        }
        
        i=find(u,parent);
        j=find(v,parent);
        
        if(i!=j){
            union1(i,j,parent);
            t[k][0]=u;
            t[k][1]=v;
            count++;
            k++;
            sum=sum+a[u][v];
        }
        a[u][v]=a[v][u]=999;
    }
    if(count==n-1){
        
        printf("\nSpanning tree : ");
        for(i=0;i<n-1;i++)
        printf("%d  %d\n",t[i][0],t[i][1] );
        printf("Cost of spanning tree : %d",sum);
    }
    else
    printf("Spanning tree does not exist");
}





void main(){
    int n,a[50][50];
    printf("Enter the no of vertices");
    scanf("%d",&n);
    printf("Enter adjacency matrix");
    for(int i=0;i<n;i++)
    {
    for(int j=0;j<n;j++)
    {
    scanf("%d",&a[i][j]);
    }    
    }
   kruskal(n,a);
}
