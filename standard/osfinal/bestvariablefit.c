#include<stdio.h>
void swap(int *a,int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
}
int main(){
	int n,m,i,j;
	printf("enter the no of processess:");
	scanf("%d",&n);
	int p[n];
	for(i=0;i<n;i++){
		scanf("%d",&p[i]);
	}
		printf("enter the no of blocks:");
	scanf("%d",&m);
	int b[m];
	for(i=0;i<m;i++){
		scanf("%d",&b[i]);
	}
	for(i=0;i<n;i++){
		for(j=0;j<n-1-i;j++){
			if(p[j]>p[j+1]){
				swap(&p[j],&p[j+1]);
			}
		}
	}
	for(i=0;i<m;i++){
		for(j=0;j<m-1-i;j++){
			if(b[j]>b[j+1]){
				swap(&b[j],&b[j+1]);
			}
		}
	}
	printf("\nascending order processes:");
	for(i=0;i<m;i++){
		printf("%d",b[i]);
	}
	int k[m];
		for(i=0;i<m;i++){
		k[i]=b[i];
	}
	for(i=0;i<n;i++){
	
		for(j=0;j<m;j++){
			if(p[i]<=k[j])
			{
			printf("\n%d in %d",p[i],b[j]);
			k[j]=k[j]-p[i];	
			break;
			}
		}
	
	}
		printf("\array k:");
	for(i=0;i<m;i++){
		printf("\t%d",k[i]);
	}
	int ex=0;
	for(i=0;i<m;i++){
	if(k[i]==b[i]){
		ex=ex+b[i];
	}
	}
	printf("external:%d",ex);
	
}
