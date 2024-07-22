#include<stdio.h>
int max, min, a[50];
int maxmin(int i, int j) {
    int max1, min1;
    if(i == j){
        max = a[i];
        min = a[i];
    }
    else if(i == j-1) {
        if(a[j] > a[i]){
            max = a[j];
            min = a[i];
        }
        else {
            max = a[i];
            min = a[j];
        }
    }
    else {
        int mid = (i + j) / 2;
        maxmin(i,mid);
        max1 = max;
        min1 = min;
        maxmin(mid+1, j);
        if(max1 > max)
            max = max1;
        if(min1 < min)
            min = min1;
    }
}
int main() {
    int i, n;
    printf("Enter The Number of Elements: ");
    scanf("%d", &n);
    printf("Enter Array Elements: ");
    for(i=0; i<n; i++) {
        scanf("%d", &a[i]);
    }
    maxmin(0, n-1);
    printf("Maximum element is: %d\n", max);
    printf("Minimum element is: %d\n", min);
    return 0;
}

/*
Enter The Number of Elements: 5
Enter Array Elements: 67 98 24 1 45
Maximum element is: 98
Minimum element is: 1
*/