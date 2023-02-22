#include<stdio.h>
#include<math.h>
int n,a[100],in,end,s=0,st,h=0;
void check();
int main(){	
	printf("enter number of tracks");
	scanf("%d",&n);
	printf("starting track position");
	scanf("%d",&in);
	printf("ending track position");
	scanf("%d",&end);
	while(s<n){
		printf("enter %d track",s+1);
		scanf("%d",&a[s]);
		if(a[s]>in&&a[s]<end){
			s++;
		}
		
	}
	printf("head track");
	scanf("%d",&st);
	check();
}
void check(){
	printf("order of sequence :");
	printf("%d ",st);
	for(int i=0;i<n;i++){
		printf("%d ",a[i]);
	}
	for(int i=0;i<n;i++){
		h=h+abs(st-a[i]);
		st=a[i];
	}

	printf("\nnumber of heads moments:  ");
	printf("%d ",h);
}
/*
enter number of tracks7
starting track position0
ending track position199
enter 1 track82
enter 2 track170
enter 3 track43
enter 4 track140
enter 5 track24
enter 6 track16
enter 7 track190
head track50
order of sequence :50 82 170 43 140 24 16 190
number of heads moments:  642
*/
	
	
