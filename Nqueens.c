#include<stdio.h>
#include<stdlib.h>
int board[40];
int count=0;


void print(int n){
    printf("\nSolution %d:\n",++count);
    for(int i=1;i<=n;i++)
    
    printf("\t%d",i);
        for(int i=1;i<=n;i++){
printf("\n\n%d",i);
    for(int j=1;j<=n;j++){
        if(board[i]==j)
        printf("\tQ");
        else
        printf("\t_");
    }
}
}



int place(int r,int c){
    for(int i=1;i<r;i++){
        if(board[i]==c)
        return 0;
         if(abs(board[i]-c)==abs(i-r))
        return 0;
    }
    return 1;
}
void queen(int row, int n){
int column;
for(column=1;column<=n;column++){
    if(place(row,column)==1){
        board[row]=column;
        if(row==n)
        print(n);
        else
        queen(row+1,n);
     
    }
    
}
}

void main(){
    int n;
    printf("Enter the no of queens");
    scanf("%d",&n);
    queen(1,n);
    
}
