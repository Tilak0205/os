#include<stdio.h>
#include<math.h>
int n,a[100],G[100],S[100],v[100],in,end,s=0,st,h=0,k=0,sm=0,gr=0,minv;
void check();
void sort();
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
	minv=st;
	for(int i=0;i<n;i++){
		v[i]=0;
	}
	sort();
	check();
}
void sort(){
	int temp;
	for(int i=0;i<n;i++){
		for(int j=0;j<n-1-i;j++){
			if(a[j]>a[j+1]){
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
    }
		printf("after sorting :");
		for(int i=0;i<n;i++){
			printf("%d ",a[i]);
		}
}
void check(){
	int i;
	for(i=0;i<n;i++){
		if(a[i]>st){
			G[gr]=a[i];
			gr++;
		}
		else{
			S[sm]=a[i];
			sm++;
		}
	}
	printf("\nGreater array :");
	for(i=0;i<gr;i++){
		printf("%d ",G[i]);
	}
	printf("\n");
	printf("Smaller array :");
	for(i=sm-1;i>=0;i--){
		printf("%d ",S[i]);
	}
	printf("\n");
	printf("order of sequence :");
	printf("%d ",minv);
	for(int i=0;i<gr;i++){
		printf("%d ",G[i]);
	}
	for( i=0;i<sm;i++){
		printf("%d ",S[i]);
	}
	for( i=0;i<gr;i++){
		h=h+abs(minv-G[i]);
		minv=G[i];
	}
	for( i=0;i<sm;i++){
		h=h+abs(minv-S[i]);
		minv=S[i];
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
after sorting :16 24 43 82 140 170 190
Greater array :82 140 170 190
Smaller array :43 24 16
order of sequence :50 82 140 170 190 16 24 43
number of heads moments:  341
*/
	
