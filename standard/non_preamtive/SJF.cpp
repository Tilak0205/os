#include<stdio.h>
int findmin_arrival(int n,int arr[][6],int vist[])
{
	int min = 10000,ind;
	for(int i=1;i<=n;i++)
	{
		if(arr[i][1]<min && vist[i]==-1)
		{
			min = arr[i][1];
			ind  = i;
		}
	}
	return ind;
}
int findmin_burst(int n,int arr[][6],int vist[],int ct)
{
	int min = 10000,ind=-1;
	for(int i=1;i<=n;i++)
	{
		if(vist[i]==-1 && arr[i][1]<=ct && (arr[i][2]<min || (min==arr[i][2] )&& arr[i][1]<arr[ind][1]))
		{
			min = arr[i][2];
			ind = i;
		}
	}
	return ind;
}
int main()
{
	int n;
	printf("Enter the no of process:\n");
	scanf("%d",&n);
	int arr[n+1][6],vist[n+1];
	printf("Enter the AT and BT\n");	
	for(int i=1;i<=n;i++)
	{
		vist[i]=-1;
		arr[i][0]=i;
		printf("\nEnter the process %d: ",i);
		scanf("%d %d",&arr[i][1],&arr[i][2]);
	}
	int p=-1,l=0,k=0,ct=0;
	int gant_chart[100];
	
	int min = 10000;
	for(int i=1;i<=n;i++)
	{
		if(arr[i][1]<min  ||  (arr[i][1]==min and arr[i][2]<arr[p][2]))
		{
			min = arr[i][1];
			p = i;
		}
	}
	if(min==0)
	{
		gant_chart[l++]=p;
		vist[p]=1;
		k++;
		arr[p][3]=0+arr[p][2];
		ct = arr[p][3];
	}
	else
	{
		gant_chart[l++]=-1;
		gant_chart[l++]=p;
		vist[p]=1;
		k++;
		arr[p][3]=arr[p][1] + arr[p][2];
		ct = arr[p][3];
	}
	
	while(k!=n)
	{
		p = findmin_burst(n,arr,vist,ct);
		if(p==-1)
		{
			gant_chart[l++]=-1;
			p=findmin_arrival(n,arr,vist);
			ct = arr[p][1];
			p=findmin_burst(n,arr,vist,ct);
		}
		gant_chart[l++]=p;
		vist[p]=1;
		k++;
		arr[p][3]=ct+arr[p][2];
		ct=arr[p][3];
	}
	for(int i=1;i<=n;i++)
	{
		arr[i][4] = arr[i][3]-arr[i][1];
		arr[i][5] = arr[i][4]-arr[i][2];
	}
	
	printf("\n Gant chat:\n");
	for(int i=0;i<l;i++){
		if(gant_chart[i]==-1){
			printf(" idle  ");
		}
		else{
			printf(" P%d  ",gant_chart[i]);
		}
	}
	printf("\n");
	printf("p\tat\tbt\tct\ttat\twt\n");
	for(int i=1;i<=n;i++){
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
 Gant chat:
 idle   P7   P6   P2   P1   P5   P3   P4
p       at      bt      ct      tat     wt
P1      8       2       13      5       3
P2      3       2       11      8       6
P3      6       5       21      15      10
P4      2       8       29      27      19
P5      5       3       16      11      8
P6      4       1       9       5       4
P7      2       6       8       6       0
Average turn_around time:= 11.000000
Average waiting-time := 7.142857
*/
