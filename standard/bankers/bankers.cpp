#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n, m, i, j, k;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the number of resources: ");
    scanf("%d", &m);

    int available[m], max[n][m], allocation[n][m], need[n][m], request[m], work[m], finish[n];
    for(i=0;i<n;i++)
    {
        printf("Enter maximum resources required for process %d: ", i+1);
        for(j=0;j<m;j++)
        {
            scanf("%d", &max[i][j]);
        }
    }
    for(i=0;i<n;i++)
    {
        printf("Enter allocated resources for process %d: ", i+1);
        for(j=0;j<m;j++)
        {
            scanf("%d", &allocation[i][j]);
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }
    printf("Enter the available resources: ");
    for(i=0;i<m;i++)
    {
        scanf("%d", &available[i]);
    }

    for(i=0;i<m;i++)
    {
        work[i] = available[i];
    }
    for(i=0;i<n;i++)
    {
        finish[i] = 0;
    }

    int count = 0, safeSequence[n];
    while(count < n)
    {
        int found = 0;
        for(i=0;i<n;i++)
        {
            if(finish[i] == 0)
            {
                int safe = 1;
                for(j=0;j<m;j++)
                {
                    if(need[i][j] > work[j])
                    {
                        safe = 0;
                        break;
                    }
                }
                if(safe == 1)
                {
                    for(k=0;k<m;k++)
                    {
                        work[k] += allocation[i][k];
                    }
                    safeSequence[count] = i;
                    finish[i] = 1;
                    count++;
                    found = 1;
                }
            }
        }
        if(found == 0)
        {
            printf("System is not in safe state.");
            exit(0);
        }
    }
    printf("System is in safe state.\nSafe sequence: ");
    for(i=0;i<n;i++)
    {
        printf("%d ", safeSequence[i]+1);
    }
    printf("\n");
    return 0;
}
/*
Enter the number of processes: 5
Enter the number of resources: 3
Enter maximum resources required for process 1: 7 5 3
Enter maximum resources required for process 2: 3 2 2
Enter maximum resources required for process 3: 9 0 2
Enter maximum resources required for process 4: 2 2 2
Enter maximum resources required for process 5: 4 3 3
Enter allocated resources for process 1: 0 1 0
Enter allocated resources for process 2: 2 0 0
Enter allocated resources for process 3: 3 0 2
Enter allocated resources for process 4: 2 1 1
Enter allocated resources for process 5: 0 0 2
Enter the available resources: 3 3 2
System is in safe state.
Safe sequence: 2 4 5 1 3
				1 3 4 0 2
*/


