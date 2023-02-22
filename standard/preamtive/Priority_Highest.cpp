#include <stdio.h>

int findmin1(int n,int arr[][7],int vis[]){
	int min = 10000,ind=-1;
	for(int i=1;i<=n;i++){
		if(min > arr[i][1] && vis[i]==-1){
			min = arr[i][1];
			ind = i;
		}
	}
	return ind;
}

int findmin(int n,int arr[][7],int vis[],int ct){
	int min = 0,ind = -1;
	for(int i=1;i<=n;i++){
		if(vis[i]==-1 && ct >= arr[i][1] && (min < arr[i][3] || (min == arr[i][3] && arr[ind][1] > arr[i][1]))){
			min = arr[i][3];
			ind = i;
		}
	}
	return ind;
}

int main(){
	int n;
	printf("enter no of processes: ");
	scanf("%d",&n);
	int arr[n+1][7],vis[n+1],bt[n+1];
	printf("enter at and bt and pt:\n");
	for(int i=1;i<=n;i++){
		vis[i]=-1;
		arr[i][0] = i;
		arr[i][4]=0;
		printf("\nenter %d process: ",i);
		scanf("%d %d %d",&arr[i][1],&arr[i][2],&arr[i][3]);
		bt[i]=arr[i][2];
	}
	
	int l=0,k=0,p=-1,ct=0,min=0;
	int gant_chat[100];
	for(int i=1;i<=n;i++){
		if(arr[i][1]<min || (min == arr[i][1] && arr[i][3]> arr[p][3])){
			min = arr[i][1];
			p = i;
		}
	}
	arr[p][2]--;
	if(min != 0){
		gant_chat[l++]=-1;
		gant_chat[l++]=p;
		arr[p][4]++;
		ct = arr[p][4];
	}
	else{
		gant_chat[l++]=p;
		arr[p][4]++;
		ct=arr[p][4];
	}
	if(arr[p][2] == 0){
		vis[p]=1;
		k++;
	}
	
	while(k != n){
		p = findmin(n,arr,vis,ct);
		if(p == -1){
			gant_chat[l++]=-1;
			p = findmin1(n,arr,vis);
			ct = arr[p][1];
			p = findmin(n,arr,vis,ct);
		}
		arr[p][2]--;
		if(gant_chat[l-1]==p){
			ct++;
			arr[p][4] = ct;
		}
		else{
			gant_chat[l++]=p;
			ct++;
			arr[p][4] = ct;
		}
		if(arr[p][2]==0){
			vis[p]=1;
			k++;
		}
	}
	
	for(int i=1;i<=n;i++){
		arr[i][5] = arr[i][4]-arr[i][1];
		arr[i][6] = arr[i][5]-bt[i];
	}
	
	printf("\n Gant chat:\n");
	for(int i=0;i<l;i++){
		if(gant_chat[i]==-1){
			printf("idle  ");
		}
		else{
			printf("P%d  ",gant_chat[i]);
		}
	}
	
	printf("\n");
	printf("p\tat\tbt\tpr\tct\ttat\twt\n");
	for(int i=1;i<=n;i++){
		printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",arr[i][0],arr[i][1],bt[i],arr[i][3],arr[i][4],arr[i][5],arr[i][6]);
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
 Gant chat:
P1  P2  P3  P4  P5  P6  P3  P2  P1
p       at      bt      pr      ct      tat     wt
1       0       4       4       18      18      14
2       1       2       5       15      14      12
3       2       3       6       14      12      9
4       3       1       10      4       1       0
5       4       2       9       6       2       0
6       5       6       7       12      7       1
Average turn_around time:= 9.000000
Average waiting-time := 6.000000
*/
