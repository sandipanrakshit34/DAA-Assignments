#include<stdio.h>
int x[20],g[20][20],count=0;
void nextValue(int k,int n){
	int i,m=n-1;
	while(1){
		x[k]=(x[k]+1)%(m+1);
		if(x[k]==0){
		    return;
		}
		for (i=1;i<=n;i++){
		    if(g[i][k]!=0 && x[k]==x[i]){
		        break;
			}
        }
		if(i==n+1){
		    break;
		}
	}
}

void mcolouring(int k,int n){
	int i;
	while(1){
		nextValue(k,n);
		if(x[k]==0){
		    return;
		}
		if(k==n){
			count++;
			printf("\nGraph coloring = ");
	        for (i=1;i<=n;i++){
		        printf("%d\t",x[i]);
	        }
		}
		else{
		    mcolouring(k+1,n);
		}
	}
}
int main(){
	int n,i,j;
	printf("Enter the number of vertices:");
	scanf("%d",&n);
	printf("Enter the adjacency matrix of the graph:\n");
	for (i=1;i<=n;i++){
		for (j=1;j<=n;j++){
		    scanf("%d",&g[i][j]);
        }
		g[i][i]=0;
	}
	printf("The possible solution vector are:");
	mcolouring(1,n);
	printf("\nThe total number of solution:%d",count);
	return 0;
}

/*
Enter the number of vertices:4
Enter the adjacency matrix of the graph:
0 1 1 0
1 0 1 1
1 1 0 1
0 1 1 0
The possible solution vector are:
Graph coloring = 1      2       3       1
Graph coloring = 1      3       2       1
Graph coloring = 2      1       3       2
Graph coloring = 2      3       1       2
Graph coloring = 3      1       2       3
Graph coloring = 3      2       1       3
The total number of solution:6
*/