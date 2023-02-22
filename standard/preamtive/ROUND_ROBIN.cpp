#include <stdio.h>
#include <stdlib.h>

struct node{
	int pno;
	int at;
	int bt;
	struct node* next;
};

struct node* front = NULL;

void readyqueue(int pno,int at,int bt){
	struct node* nn = (struct node*)malloc(sizeof(struct node));
	nn->pno = pno;
	nn->at = at;
	nn->bt = bt;
	nn->next = NULL;
	if(front == NULL || at < front->at){
		nn->next = front;
		front = nn;
	}
	else{
		struct node* temp = front;
		while(temp->next != NULL && temp->next->at <= at){
			temp = temp->next;
		}
		nn->next = temp->next;
		temp->next = nn;
	}
}

void roundrobin(int at[],int bt[],int ct[],int n,int timequantum){
	for(int i=0;i< n;i++){
		readyqueue(i,at[i],bt[i]);
	}
	struct node* temp = front;
	int time = 0;
	while(temp != NULL){
		if(time < temp->at){
			printf("%d idle %d || ",time,temp->at);
			time = temp->at;//   IDLE case
		}
		if(temp->bt > timequantum){
			printf("%d P%d %d || ",time,temp->pno+1,time+timequantum);
			time = time+timequantum;
			readyqueue(temp->pno,time,temp->bt-timequantum);
		}
		else{
			printf("%d P%d %d || ",time,temp->pno+1,time+temp->bt);
			time = time+temp->bt;
			ct[temp->pno] = time;
		}
		temp = temp->next;
	}
}

int main(){
	int n,timequantum;
	printf("enter no of processes: ");
	scanf("%d",&n);
	printf("enter timequantum: ");
	scanf("%d",&timequantum);
	int at[n],bt[n],ct[n],tat[n],wt[n];
	for(int i=0;i< n;i++){
		printf("\nenter arrival and burst time of processor %d: ",i);
		scanf("%d %d",&at[i],&bt[i]);
	}
	roundrobin(at,bt,ct,n,timequantum);
	for(int i=0;i< n;i++){
		tat[i] = ct[i]-at[i];
	}
	for(int i=0;i< n;i++){
		wt[i] = tat[i]-bt[i];
	}
	
	printf("\npno\tat\tbt\tct\ttat\twt\t\n\n");
	for(int i=0;i<n;i++){
		printf("%d\t%d\t%d\t%d\t%d\t%d\n",i+1,at[i],bt[i],ct[i],tat[i],wt[i]);
	}
	float avg_tat=0,avg_wt=0;
	for(int i=0;i<n;i++)
	{
		avg_tat +=tat[i];
		avg_wt += wt[i];
	}
	printf("Average turn_around time:= %f\n",(avg_tat)/n);
	printf("Average waiting-time := %f\n",(avg_wt)/n);
}
/*
0 P1 2 || 2 P2 4 || 4 P3 6 || 6 P1 8 || 8 P4 10 || 10 P5 11 || 11 P2 13 || 13 P6 15 || 15 P3 17 || 17 P4 18 || 18 P2 19 || 19 P6 21 || 21 P3 23 ||
pno     at      bt      ct      tat     wt

1       0       4       8       8       4
2       1       5       19      18      13
3       2       6       23      21      15
4       3       3       18      15      12
5       4       1       11      7       6
6       5       4       21      16      12
Average turn_around time:= 14.166667
Average waiting-time := 10.333333
*/



