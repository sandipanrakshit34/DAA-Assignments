#include<stdio.h>
int a[50];
int partition(int low, int high){
    int pivot = a[low], start = low, end= high,t;
    while(start<end){
        while(a[start]<=pivot)
            start++;
        while(a[end]>pivot)
            end--;
        if(start<end){
            t = a[start];
			a[start] = a[end];
			a[end] = t;
        }
    }
    t = a[end];
	a[end] = a[low];
	a[low] = t;
    return end;
}

int QuickSort(int low, int high){
    int loc;
    if(low<high){
        loc = partition(low,high);
        QuickSort(low,loc-1);
        QuickSort(loc+1,high);
    }
}

int main() {
    int n,i;
    printf("Enter the size of array: ");
    scanf("%d", &n);
    printf("\nEnter %d elements: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    QuickSort(0, n - 1);
    printf("\nSorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}

/*
Enter the size of array: 5

Enter 5 elements: 67 98 24 1 45

Sorted array: 1 24 45 67 98
*/