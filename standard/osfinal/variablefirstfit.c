#include<stdio.h>

int main(){
	int n,m,i,j;
	printf("enter no of processes:");
	scanf("%d",&n);
	int p[n];
	for(i=0;i<n;i++){
		scanf("%d",&p[i]);
	}
		printf("enter no of blocks:");
	scanf("%d",&m);
	int b[m],k[m];
	for(i=0;i<m;i++){
		scanf("%d",&b[i]);
	}
	for(i=0;i<m;i++){
		k[i]=b[i];
	}
	int f,ex=0;

		for(i=0;i<m;i++){
		k[i]=b[i];
	}

	for(i=0;i<n;i++){
		f=0;
		for(j=0;j<m;j++){
		
		if(p[i]<=k[j]){
			printf("\n%d in %d",p[i],b[j]);
			k[j]=k[j]-p[i];
			f=1;
			break;
		}
}
	}
	for(i=0;i<m;i++){
	if(k[i]==b[i]){
		ex=ex+b[i];
	}
	}
	printf("external:%d",ex);
}
