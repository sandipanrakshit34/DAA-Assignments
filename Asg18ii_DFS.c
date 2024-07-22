#include<stdio.h>
int g[100][100],visited[100],n;
void DFS(int v){
	int w;
	visited[v]=1;
	printf("%d  ",v);
	for(w=1; w<=n; w++){
		if(g[v][w]==1 && visited[w]==0){
			DFS(w);
		}
	}
}
void DFT(){
    int i;
    for(i=1; i<=n; i++){ 
        visited[i] = 0;
	}
    for(i=1; i<=n; i++){
        if(visited[i] == 0){ 
            DFS(i);
		}
	}
}
int main(){
	int i,j;
	printf("Enter The Number of Vertices: ");
	scanf("%d",&n);
	printf("Enter The Adjacency Matrix:\n");
	for(i=1; i<=n; i++){
		for(j=1; j<=n; j++){
			scanf("%d",&g[i][j]);
		}
	}
	printf("\nThe DFS result is: ");
	DFT();
	return 0;
}

/*
Enter The Number of Vertices: 8
Enter The Adjacency Matrix:
0 1 1 0 0 0 0 0
1 0 0 1 1 0 0 0
1 0 0 0 0 1 1 0
0 1 0 0 0 0 0 1
0 1 0 0 0 0 0 1
0 0 1 0 0 0 0 1
0 0 1 0 0 0 0 1
0 0 0 1 1 1 1 0

The DFS result is: 1  2  4  8  5  6  3  7
*/