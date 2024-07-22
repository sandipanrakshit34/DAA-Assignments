#include <stdio.h>
int id[50],p[50],d[50],s[50],dmax;
int jobSequence(int n){
    int c=0,k,sump=0,i;
    dmax = d[0];
    for (i=0; i<n; i++){
        if(d[i] > dmax){
            dmax = d[i];  //max deadline
        }
    }
	printf("\nMax Deadline = %d",dmax);
    for(i=1; i<=n; i++){
        s[i] = -1;
    }
    for(i=0; i<n; i++){
        if(d[i] < dmax){
            k = d[i];
        }                 //selection
        else{
            k = dmax;
        }
        while (k > 0){
            if(s[k] == -1){
                s[k] = i;
                sump += p[i];    //sequence
                c++;
                break;
            }
            k--; 
        }
        if(c == dmax){    //deadline reached
            break;
        }
    }
    return sump;
}

void sort(int n){
    int i,j,temp;
    for (i=0; i<n-1; i++){
        for (j=0; j<n-i-1; j++){
            if (p[j] < p[j+1]){
                temp = p[j];
                p[j] = p[j+1];
                p[j + 1] = temp;

                temp = d[j];
                d[j] = d[j+1];
                d[j + 1] = temp;

                temp = id[j];
                id[j] = id[j+1];
                id[j+1] = temp;
            }
        }
    }
}

int main(){
    int i,n,maxp;
    printf("Enter the no. of jobs : ");
    scanf("%d",&n);
    for (i=0; i<n; i++){
        printf("\nEnter the job id, profit and deadline of job[%d]: ",i+1);
        scanf("%d%d%d",&id[i],&p[i],&d[i]);
    }
    sort(n);
    printf("\nSorted jobs are:\n");
    for(i=0; i<n; i++){
        printf("Job Id=%d, Deadline=%d, Profit=%d\n",id[i],d[i],p[i]);
    }
    maxp = jobSequence(n);
    printf("\nMax Profit = %d\n",maxp);
    printf("\nSolution vector:\n");
    for(i=1; i<=dmax; i++){
        if(s[i] != -1){
            printf("Job-%d\t", id[s[i]]);
        }
    }
    return 0;
}

/*
Enter the no. of jobs : 4

Enter the job id, profit and deadline of job[1]: 1 100 2

Enter the job id, profit and deadline of job[2]: 2 10 1

Enter the job id, profit and deadline of job[3]: 3 15 2

Enter the job id, profit and deadline of job[4]: 4 27 1

Sorted jobs are:
Job Id=1, Deadline=2, Profit=100
Job Id=4, Deadline=1, Profit=27
Job Id=3, Deadline=2, Profit=15
Job Id=2, Deadline=1, Profit=10

Max Deadline = 2
Max Profit = 127

Solution vector:
Job-4   Job-1
*/