#include<stdio.h>
int findmin_arrival(int n,int arr[][7],int vist[])
{
	int min = 10000,ind;
	for(int i=1;i<=n;i++)
	{
		if(arr[i][1]<min && vist[i]==-1)
		{
			min = arr[i][1];
			ind= i;
		}
	}
	return ind;
}
int findmin_priority(int n,int arr[][7],int vist[],int ct)
{
	int min =0,ind=-1;
	for(int i=1;i<=n;i++)
	{
		if(vist[i]==-1 && arr[i][1]<=ct && (arr[i][3]>min || (arr[i][3]==min && arr[i][1]<arr[ind][1])))
		{
			min = arr[i][3];
			ind=i;
		}
	}
	return ind;
}
int main()
{
	int n;
	printf("Enter the no of processes:\n");
	scanf("%d",&n);
	int arr[n+1][7],vist[n+1];
	printf("\nEnter the At and Bt and Priority:\n");
	for(int i=1;i<=n;i++)
	{
		vist[i]=-1;
		arr[i][0]=i;
		printf("Enter the %d  process:  ",i);
		scanf("%d %d %d",&arr[i][1],&arr[i][2],&arr[i][3]);
	}
	
	int p=-1,l=0,k=0,ct=0;
	int gant_chart[100];
	
	int min = 0;
	for(int i=1;i<=n;i++)
	{
		if(arr[i][1]<min || (arr[i][1]==min && arr[i][3]>arr[p][3]))
		{
			min = arr[i][1];
			p=i;
		}
	}
	
	if(min!=0)
	{
		gant_chart[l++]=-1;
		gant_chart[l++]=p;
		k++;
		vist[p]=1;
		arr[p][4]=arr[p][1]+arr[p][2];
		ct = arr[p][4];
	}
	else
	{
		gant_chart[l++]=p;
		k++;
		vist[p]=1;
		arr[p][4]=0+arr[p][2];
		ct = arr[p][4];
	}
	while(k!=n)
	{
		p = findmin_priority(n,arr,vist,ct);
		if(p==-1)
		{
			gant_chart[l++]=-1;
			p=findmin_arrival(n,arr,vist);
			ct=arr[p][1];
			p=findmin_priority(n,arr,vist,ct);
		}
		gant_chart[l++]=p;
		vist[p]=1;
		k++;
		arr[p][4]=ct + arr[p][2];
		ct= arr[p][4];
	}
	
	for(int i=1;i<=n;i++)
	{
		arr[i][5]=arr[i][4]-arr[i][1];
		arr[i][6]=arr[i][5]-arr[i][2];
	}
		printf("\n Gant chart:\n");
	for(int i=0;i<l;i++){
		if(gant_chart[i]==-1){
			printf(" idle  ");
		}
		else{
			printf(" P%d  ",gant_chart[i]);
		}
	}
	
	printf("\n");
	printf("p\tat\tbt\tpt\tct\ttat\twt\n");
	for(int i=1;i<=n;i++){
		printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",arr[i][0],arr[i][1],arr[i][2],arr[i][3],arr[i][4],arr[i][5],arr[i][6]);
	}
	float avg_tat=0,avg_wt=0;
	for(int i=1;i<=n;i++)
	{
		avg_tat +=arr[i][5];
		avg_wt += arr[i][6];
	}
	printf("Average turn_around time:= %f\n",(avg_tat)/n);
	printf("Average waiting-time := %f\n",(avg_wt)/n);
}


/*
 Gant chart:
 P1   P4   P5   P6   P3   P2
p       at      bt      pt      ct      tat     wt
P1      0       4       4       4       4       0
P2      1       2       5       18      17      15
P3      2       3       6       16      14      11
P4      3       1       10      5       2       1
P5      4       2       9       7       3       1
P6      5       6       7       13      8       2
Average turn_around time:= 8.000000
Average waiting-time := 5.000000
*/


