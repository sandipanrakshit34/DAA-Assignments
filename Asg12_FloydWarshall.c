#include<stdio.h>
#define INF 9999
int cost[50][50],D[50][50],n;

void floyd(){
	int i,j,k;
	for(k=1;k<=n;k++){
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				if(D[i][j]>D[i][k]+D[k][j]){
					D[i][j]=D[i][k]+D[k][j];
				}
			}
		}
	}
}

int main(){
	int i,j;
	printf("Enter the no of vertices: ");
	scanf("%d",&n);
	printf("\nEnter the cost matrix:\n");
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			scanf("%d",&cost[i][j]);
			if((i!=j) && cost[i][j]==0){
				cost[i][j]=INF;
			}
			D[i][j]=cost[i][j];
		}
	}
	floyd();
	printf("\nThe shortest distance matrix:\n");
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			printf("%d ",D[i][j]);
		}
		printf("\n");
	}
	return 0;
}

/*
Enter the no of vertices: 4

Enter the cost matrix:
0 8 0 1
0 0 1 0
4 0 0 0
0 2 9 0

The shortest distance matrix:
0 3 4 1
5 0 1 6
4 7 0 5
7 2 3 0
*/