#include<stdio.h>
#define INF 9999
int G[20][20],n;

void prims(){
	int i,j,k,visited[20],v1,v2,mincost=0,min;
	printf("\nEdges\tcost");
	for(i=1;i<=n;i++){
		visited[i]=0;
	}
	visited[1]=1;
	for(k=1;k<=n-1;k++){
		min=INF;
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				if((G[i][j] != INF) && (visited[i]==1) && (visited[j] == 0)){
					if(G[i][j]<min){
						min=G[i][j];
						v1=i;
						v2=j;
					}
				}
	        } 
	    }
	    visited[v1]=visited[v2]=1;
	    mincost += min;
	    printf("\n%d -> %d = %d",v1,v2,min);
	}
	printf("\nThe minimum cost is: %d",mincost);
}

int main(){
	int i,j;
	printf("Enter the no. of vertices: ");
	scanf("%d",&n);
	printf("\nEnter the adjacency matrix: \n ");
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			scanf("%d",&G[i][j]);
			if(G[i][j]==0){
				G[i][j]=INF;
			}
		}
	}
	prims();
	return 0;
}

/*
Enter the no. of vertices: 6

Enter the adjacency matrix:
0 8 1 5 0 0
8 0 5 0 3 0
1 5 0 5 6 4
5 0 5 0 0 2
0 3 6 0 0 6
0 0 4 2 6 0

Edges cost
1 -> 3 = 1
3 -> 6 = 4
6 -> 4 = 2
3 -> 2 = 5
2 -> 5 = 3
The minimum cost is: 15
*/