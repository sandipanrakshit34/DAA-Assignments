#include <stdio.h>
float p[20],w[20],r[20],x[20],m;
void knapsack(int n) {
    int i;
    float capacity;
    for(i=1;i<=n;i++){
        x[i]=0.0;
    }
    capacity=m;                  // u = weight of the bag
    for (i=1;i<=n;i++){
        if (w[i] > capacity)
            break;
        x[i] = 1.0;                        // x[i] = 1.0 means the total weight of the item is selected
        capacity -= w[i];                    // subtract the weight of the item from u (total weight)
    }
    if (i<=n) {
        x[i] = capacity/w[i];                  // if the weight of the next item exceeds this capacity: 
    }                                           // divide the remaining capacity by the weight of the next item
}

void sort(int n) {
    int i, j;
    float temp;
    for (i=1;i<=n-1;i++) {
        for (j=1;j<=n-i;j++) {
            if (r[j]<r[j+1]) {
                temp = r[j];
                r[j] = r[j+1];
                r[j+1] = temp;

                temp = p[j];
                p[j] = p[j+1];                 // sort in decreasing order
                p[j+1] = temp;

                temp = w[j];
                w[j] = w[j+1];
                w[j+1] = temp;
            }
        }
    }
}

int main() {
    int i,n;
    float total=0;
    printf("\nEnter the number of items: ");
    scanf("%d",&n);
    printf("\nEnter the knapsack capacity: ");
    scanf("%f",&m);
    printf("\nEnter the profit and corresponding weight: \n");
    for(i=1;i<=n;i++){
        scanf("%f%f",&p[i],&w[i]);
    }
    for(i=1;i<=n;i++){
        r[i]=p[i]/w[i];
    }
    sort(n);
    printf("\nThe new profit array is: ");
    for (i=1;i<=n;i++) {
        printf("%.3f\t",p[i]);
    }
    printf("\nThe new weight array is: ");
    for (i=1;i<=n;i++) {
        printf("%.3f\t",w[i]);
    }
    printf("\nThe new ratio array is:");
    for (i=1;i<=n;i++) {                             // r[i] = (profit/weight) of each item
        printf("%.3f\t", r[i]);                        // w[i] = (total capacity/weight of the next item)
    }
    knapsack(n);

    printf("\nThe solution vector of the object is: ");
    for (i=1;i<=n;i++) {
        printf("%.3f\t",x[i]);
    }
    for (i=1;i<=n;i++) {
        total += p[i]*x[i];
    }
    printf("\nThe Total profit is: %.3f",total);
    return 0;
}

/*
Enter the number of items: 3

Enter the knapsack capacity: 20

Enter the profit and corresponding weight:
25 18
24 15
15 10

The new profit array is:24.000  15.000  25.000
The new weight array is:15.000  10.000  18.000
The new ratio array is:1.600    1.500   1.389
The solution vector of the object is: 1.000     0.500   0.000
The Total profit is: 31.500
*/