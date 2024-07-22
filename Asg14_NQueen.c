#include <stdio.h>
#include <stdlib.h>

int x[100];
int Place(int k,int i){
    int j;
    for(j=1;j<=k-1;j++){
        if(x[j]==i||abs(x[j]-i)==abs(j-k)){
            return 0;
        }
    }
    return 1;
}

void NQueens(int k,int n){
    int i,j,l,m;
    for(i=1;i<=n;i++){
        if(Place(k,i)){
            x[k]=i;
            if(k==n){
                printf("Queen Position: ");
                for(j=1;j<=n;j++){
                    printf("%d\t",x[j]);
                }
                printf("\nThe ChessBoard is:\n");
                for(l=1;l<=n;l++){
                    for(m=1;m<=n;m++){
                        if(m==x[l]){
                            printf("|Q%d| ",l);
                        }
                        else{
                            printf("|_| ");
                        }
                    }
                    printf("\n");
                }
            }
            else{
                NQueens(k+1,n);
            }
        }
    }
}

int main(){
    int n;
    printf("Enter The Number of Queens: ");
    scanf("%d",&n);
    NQueens(1,n);
    return 0;
}

/*
Enter The Number of Queens: 4
Queen Position: 2       4       1       3
The ChessBoard is:
|_| |Q1| |_| |_| 
|_| |_| |_| |Q2| 
|Q3| |_| |_| |_| 
|_| |_| |Q4| |_| 
Queen Position: 3       1       4       2
The ChessBoard is:
|_| |_| |Q1| |_|
|Q2| |_| |_| |_|
|_| |_| |_| |Q3|
|_| |Q4| |_| |_|
*/