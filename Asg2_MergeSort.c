#include <stdio.h>
int a[50];
int Merge(int low,int mid,int high){
    int i=low,j=mid+1,k=low,b[20],l;
    while(i<=mid && j<=high){
        if (a[i]<a[j]){
            b[k++]=a[i++];
        }
		else{
            b[k++]=a[j++];
        }
    }
    while(i<=mid){
        b[k++] = a[i++];
    }
    while(j<=high){
        b[k++] = a[j++];
    }
    for(l=low;l<=high;l++){
        a[l] = b[l];
    }
}

int MergeSort(int low, int high) {
    int mid;
    if(low<high){
        mid = (low+high)/2;
        MergeSort(low,mid);
        MergeSort(mid+1,high);
        Merge(low,mid,high);
    }
}

int main() {
    int n,i;
    printf("Enter the size of array: ");
    scanf("%d", &n);
    printf("\nEnter %d elements: ", n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    MergeSort(0,n-1);
    printf("\nSorted array: ");
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    return 0;
}

/*
Enter the size of array: 5

Enter 5 elements: 67 98 24 1 45

Sorted array: 1 24 45 67 98
*/