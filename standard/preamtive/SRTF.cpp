#include<stdio.h>
// 7 5 1 2 1 4 3 1 10 3 4 1 8 2 6
int find_index(int at[],int bt[],int visit[],int time,int n)
{
	int min=10000,index=-1;
	for(int i=0;i<n;i++)
	{
		if(bt[i]<min &&at[i]<=time && visit[i]==0 )
		{   
			min=bt[i];
			index=i;
		}
	}
	
	if(index!=-1)
	{ int minarr=1000;
	   for(int i=0;i<n;i++)
	    {   
	    	if(bt[i]==min && at[i]<minarr)
	    	{   minarr=at[i];
	    		index=i;
			}
		}
		return index;
	}
	else
	{   int minarrival=1000,minbt=10000;
		for(int i=0;i<n;i++)
		{
			if(at[i]<minarrival && at[i]>time && visit[i]==0)
			{ minarrival=at[i];
			  index=i;
			}
		}
	   for(int i=0;i<n;i++)
	    {   
	    	if(at[i]==minarrival && bt[i]<minbt)
	    	{   minbt=bt[i];
	    		index=i;
			}
		}
		
		return index;
	}
	
}
bool completed(int bt[],int n)
{
	for(int i=0;i<n;i++)
	{
		if(bt[i]!=0)
		   return false;
	}
	return true;
}
int sjf(int at[],int bt[],int ct[],int n)
{   int visit[n];
    for(int i=0;i<n;i++)
    {
    	visit[i]=0;
	}
	int time=0;
	int a;
	while(!completed( bt,n))
	{ a=find_index(at,bt,visit,time,n);
	  visit[a]=1;
	  if(at[a]>time)
	  {
	  	printf(" %d idle %d ||",time,at[a]);
	  	time=at[a];
	  }
	  printf(" %d P%d  %d ||",time,a+1,time+1);
	  time=time+1;
	  bt[a]--;
	  if(bt[a]==0)
	  {ct[a]=time;
      }
      else
      {
      	visit[a]=0;
	  }
	}
}

int main()
{
	int n;
	printf("enter no of process:\n");
	scanf("%d",&n);
	int at[n],bt[n],ct[n],att[n],btt[n];
	printf("Enter the AT and BT:\n");
	for(int i=0;i<n;i++)
	{
		printf("\nEnter Process: %d : ",i+1);
		scanf("%d%d",&at[i],&bt[i]);
		att[i]=at[i];
		btt[i]=bt[i];
	}
	sjf(att,btt,ct,n);
	int total_turnaround_time=0;
	int tat[n];
	for(int i=0;i<n;i++)
	{
		tat[i]=ct[i]-at[i];
		total_turnaround_time+=tat[i];
	}
	int total_waiting_time=0;
	int wt[n];
	for(int i=0;i<n;i++)
	{
		wt[i]=tat[i]-bt[i];
		total_waiting_time+=wt[i];
	}
	
	printf("\n\n\n");
	printf("pr\tat\tbt\tct\ttat\twt \n");
	for(int i=0;i<n;i++)
	{
	  printf("p:%d\t%d\t%d\t%d\t%d\t%d\n",i+1,at[i],bt[i],ct[i],tat[i],wt[i]);	
	}
	
	printf("avg turnaround time is %f  \n",float(total_turnaround_time)/float(n));
	printf("avg waiting time is %f \n",float(total_waiting_time)/float(n));
}

/*
 0 idle 1 || 1 P6  2 || 2 P2  3 || 3 P5  4 || 4 P5  5 || 5 P1  6 || 6 P5  7 || 7 P5  8 || 8 P3  9 || 9 P3  10 || 10 P3  11 || 11 P7  12 || 12 P7  13 || 13 P7  14 || 14 P7  15 || 15 P7  16 || 16 P7  17 || 17 P6  18 || 18 P6  19 || 19 P6  20 || 20 P6  21 || 21 P6  22 || 22 P6  23 || 23 P6  24 || 24 P4  25 || 25 P4  26 || 26 P4  27 || 27 P4  28 || 28 P4  29 || 29 P4  30 || 30 P4  31 || 31 P4  32 || 32 P4  33 || 33 P4  34 ||


pr      at      bt      ct      tat     wt
p:1     5       1       6       1       0
p:2     2       1       3       1       0
p:3     4       3       11      7       4
p:4     1       10      34      33      23
p:5     3       4       8       5       1
p:6     1       8       24      23      15
p:7     2       6       17      15      9
avg turnaround time is 12.142858
avg waiting time is 7.428571
*/


