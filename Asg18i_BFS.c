#include<stdio.h>
int g[100][100],visited[100],Q[100],n,front=-1,rear=-1;
int AddQ(int val){
    if(front == -1 && rear == -1){
        front = rear = 0;
	}
    else{ 
        rear++;
	}
    Q[rear] = val;
}
int DelQ(){
    int val = Q[front];
    if (front == rear){
        front = rear = -1;
	}
    else{
        front++;
	}
    return val;
}
int EmptyQ(){
    if(front == -1 && rear == -1){
        return 1;
	}
    return 0;
}
void BFS(int v){
	int u, w;
	visited[v] = 1;
	u = v;
	while(1){
		printf("%d  ",u);
		for(w=1; w<=n; w++){
			if(g[u][w] == 1 && visited[w] == 0){
				AddQ(w);
				visited[w] = 1;
			}
		}
		if(EmptyQ()){
			return;
		}
		u = DelQ();
	}
}
void BFT(){
    int i;
    for(i=1; i<=n; i++){
        visited[i] = 0;
	}
    for(i=1; i<=n; i++){
        if(visited[i] == 0){ 
            BFS(i);
		}
	}
}
int main(){
	int i, j;
	printf("Enter the number of Vertices in the graph: ");
	scanf("%d", &n);
	printf("Enter the Adjacency Matrix:\n");
	for(i=1; i<=n; i++){
		for(j=1; j<=n; j++){
			scanf("%d", &g[i][j]);
		}
	}
	printf("\nThe BFS result is: ");
	BFT();
	return 0;
}

/*
Enter the number of Vertices in the graph: 8
Enter the Adjacency Matrix:
0 1 1 0 0 0 0 0
1 0 0 1 1 0 0 0
1 0 0 0 0 1 1 0
0 1 0 0 0 0 0 1
0 1 0 0 0 0 0 1
0 0 1 0 0 0 0 1
0 0 1 0 0 0 0 1
0 0 0 1 1 1 1 0

The BFS result is: 1  2  3  4  5  6  7  8
*/
