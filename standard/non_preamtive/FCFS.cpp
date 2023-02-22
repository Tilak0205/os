#include<stdio.h>
int findmin_arrival(int n,int arr[][6],int vist[])
{
	int min = 10000,ind;
	for(int i=1;i<=n;i++)
	{
		if(vist[i]==-1 and arr[i][1]<min)
		{
			min = arr[i][1];
			ind=i;
		}
	}
	return ind;
}
int main()
{
	int n;
	printf("Enter the no of processes:");
	scanf("%d",&n);
	int arr[n+1][6],vist[n+1];
	printf("Enter the  AT and BT");
	for(int i=1;i<=n;i++)
	{
		vist[i]=-1;
		arr[i][0]=i;
		printf("\nEnter %d process:",i);
		scanf("%d %d",&arr[i][1],&arr[i][2]);
	}
	//1st
	int p=-1,l=0,k=0,ct=0;//k no of processes
	int gant_chart[100];
	
	for(int i=1;i<=n;i++)
	{
		if(arr[i][1]==0)
		{
			p=i;
			break;//because first id priority..
		}
	}
	//2nd
	if(p==-1)
	{
		gant_chart[l++]=-1;
		p=findmin_arrival(n,arr,vist);
		gant_chart[l++]=p;
		vist[p]=1;
		k++;
		arr[p][3]=arr[p][2]+arr[p][1];
		ct=arr[p][3];
	}
	else
	{
		gant_chart[l++]=p;
		vist[p]=1;
		k++;
		arr[p][3]=0+arr[p][2];
		ct=arr[p][3];	
	}
	//3rd
	while(k!=n)
	{
		p=findmin_arrival(n,arr,vist);
		if(ct < arr[p][1])
		{
			gant_chart[l++]=-1;
			ct=arr[p][1];//ideal condition
		}
		gant_chart[l++]=p;
		vist[p]=1;
		k++;
		arr[p][3]=ct+arr[p][2];
		ct = arr[p][3];
	}
	//////////////normal
	for(int i=1;i<=n;i++)
	{
		arr[i][4]=arr[i][3]-arr[i][1];
		arr[i][5]=arr[i][4]-arr[i][2];
	}
	printf("\n");
	for(int i=0;i<l;i++)
	{
		if(gant_chart[i]==-1)
		{
			printf(" IDLE ");
		}
		else
		{
			printf(" P%d ",gant_chart[i]);
		}
	}
	printf("\n");
	printf("P\tAT\tBT\tCT\tTAT\tWT\n");
	for(int i=1;i<=n;i++)
	{
		
		printf("P%d\t%d\t%d\t%d\t%d\t%d\n",arr[i][0],arr[i][1],arr[i][2],arr[i][3],arr[i][4],arr[i][5]);
	}
	
	float avg_tat=0,avg_wt=0;
	for(int i=1;i<=n;i++)
	{
		avg_tat +=arr[i][4];
		avg_wt += arr[i][5];
	}
	printf("Average turn_around time:= %f\n",(avg_tat)/n);
	printf("Average waiting-time := %f\n",(avg_wt)/n);
}

/*
IDLE  P1  P2  P4  P5  P3
P       AT      BT      CT      TAT     WT
P1      2       2       4       2       0
P2      4       3       7       3       0
P3      7       5       28      21      16
P4      5       7       14      9       2
P5      6       9       23      17      8
Average turn_around time:= 10.400000
Average waiting-time := 5.200000
*/
