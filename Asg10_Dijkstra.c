#include<stdio.h>
#define INF 9999
int cost[50][50],dist[50],status[50],n,v;

void dijkstra(){
	int i,j,w,u,min,count;
	for(i=1;i<=n;i++){
		status[i]=0;
		dist[i]=cost[v][i];
	}
	dist[v]=0;
	for(count=2;count<=n;count++){
		min=INF;
		for(w=1;w<=n;w++){
			if((dist[w]<min) && (status[w]==0)){
				min = dist[w];
				u=w;
	        } 
	    }
	    status[u]=1;
	    for(w=1;w<=n;w++){
	    	if((dist[u]+cost[u][w]<dist[w]) && (status[w]==0)){
	    		dist[w]=dist[u]+cost[u][w];
			}
		}
	}
	printf("\nThe shortest path from the source vertex %d is:",v);
	for(i=1;i<=n;i++){
		if(i!=v){
			printf("\n%d->%d=%d",v,i,dist[i]);
		}
	}
}

int main(){
	int i,j;
	printf("Enter the no. of vertices: ");
	scanf("%d",&n);
	printf("\nEnter the adjacency matrix: \n ");
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			scanf("%d",&cost[i][j]);
			if(cost[i][j]==0){
				cost[i][j]=INF;
			}
		}
	}
	printf("\nEnter the source vertex: ");
	scanf("%d",&v);
	dijkstra();
	return 0;
}

/*
Enter the no. of vertices: 5

Enter the adjacency matrix:
0 10 0 0 5
0 0 1 0 2
0 0 0 4 0
7 0 6 0 0
0 3 9 2 0

Enter the source vertex: 1

The shortest path from the source vertex 1 is:
1->2=8
1->3=9
1->4=7
1->5=5
*/