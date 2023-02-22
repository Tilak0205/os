#include<stdio.h>
#include<stdlib.h>

#define MAX_PROCESSES 10
#define MAX_RESOURCES 10

int n, m;
int available[MAX_RESOURCES];
int max[MAX_PROCESSES][MAX_RESOURCES];
int allocation[MAX_PROCESSES][MAX_RESOURCES];
int need[MAX_PROCESSES][MAX_RESOURCES];
int sequence[MAX_PROCESSES];
int used[MAX_PROCESSES];
int count = 0;

void backtrack(int step) {
    if(step == n) {
        int work[m], finish[n], i, j, k;
        for(i=0;i<m;i++) {
            work[i] = available[i];
        }
        for(i=0;i<n;i++) {
            finish[i] = 0;
        }
        for(i=0;i<n;i++) {
            int process = sequence[i];
            int safe = 1;
            for(j=0;j<m;j++) {
                if(need[process][j] > work[j]) {
                    safe = 0;
                    break;
                }
            }
            if(safe == 1) {
                for(k=0;k<m;k++) {
                    work[k] += allocation[process][k];
                }
                finish[process] = 1;
            }
            else {
                break;
            }
        }
        if(i == n) {
            printf("Safe sequence %d: ", count++);
            for(i=0;i<n;i++) {
                printf("%d ", sequence[i]+1);
            }
            printf("\n");
        }
        return;
    }
    int i;
    for(i=0;i<n;i++) {
        if(used[i] == 0) {
            used[i] = 1;
            sequence[step] = i;
            backtrack(step+1);
            used[i] = 0;
        }
    }
}

int main() {
    int i, j;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the number of resources: ");
    scanf("%d", &m);

    for(i=0;i<n;i++) {
        printf("Enter maximum resources required for process %d: ", i+1);
        for(j=0;j<m;j++) {
            scanf("%d", &max[i][j]);
        }
    }
    for(i=0;i<n;i++) {
        printf("Enter allocated resources for process %d: ", i+1);
        for(j=0;j<m;j++) {
            scanf("%d", &allocation[i][j]);
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }
    printf("Enter the available resources: ");
    for(i=0;i<m;i++) {
        scanf("%d", &available[i]);
    }

    backtrack(0);

    return 0;
}
/*
Enter the number of processes: 5
Enter the number of resources: 4
Enter maximum resources required for process 1: 0 0 1 2
Enter maximum resources required for process 2: 1 7 5 0
Enter maximum resources required for process 3: 2 3 5 6
Enter maximum resources required for process 4: 0 6 5 4
Enter maximum resources required for process 5: 0 6 5 6
Enter allocated resources for process 1: 0 0 1 2
Enter allocated resources for process 2: 1 0 0 0
Enter allocated resources for process 3: 1 3 5 4
Enter allocated resources for process 4: 0 6 3 2
Enter allocated resources for process 5: 0 0 1 4
Enter the available resources: 1 5 2 0
Safe sequence 0: 1 3 2 4 5
Safe sequence 1: 1 3 2 5 4
Safe sequence 2: 1 3 4 2 5
Safe sequence 3: 1 3 4 5 2
Safe sequence 4: 1 3 5 2 4
Safe sequence 5: 1 3 5 4 2
Safe sequence 6: 1 4 2 3 5
Safe sequence 7: 1 4 2 5 3
Safe sequence 8: 1 4 3 2 5
Safe sequence 9: 1 4 3 5 2
Safe sequence 10: 1 4 5 2 3
Safe sequence 11: 1 4 5 3 2

*/
