#include <stdio.h>
int arr[20];
int binarySearch(int low, int high, int key){
    if(low <= high){
        int mid = low+(high-low)/2;
        if (arr[mid] == key){
            return mid;
        }
        else if(arr[mid]>key){
            return binarySearch(low,mid-1,key);
        }
        else{
            return binarySearch(mid+1,high,key);
        }
    }
    else{
        return -1;
    }
}
int main() {
    int i,n,key;
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    printf("Enter the elements in the array: ");
    for(i=0; i<n; i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter the element to search: ");
    scanf("%d", &key);
    int result = binarySearch(0, n - 1, key);
    if(result != -1){
        printf("Element %d is present at index %d.\n", key, result+1);
    }
    else{
        printf("Element %d is not present in the array.\n", key);
    }
    return 0;
}

/*
Enter the size of the array: 5
Enter the elements in the array: 1 5 6 7 8
Enter the element to search: 5
Element 5 is present at index 2.
*/