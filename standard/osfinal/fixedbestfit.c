#include<stdio.h>
int main(){
	int n,r;
	printf("enter no of processes:");
	scanf("%d",&n);
	int i,j,p[n];
	for(i=0;i<n;i++){
		scanf("%d",&p[i]);
	}
	
	printf("enter no of memories:");
	scanf("%d",&r);
	int m[r];
	for(j=0;j<r;j++){
		scanf("%d",&m[j]);
	}
	for(i=0;i<n;i++){
		int temp;
		for(j=0;j<n-1;j++){
			if(p[j]>p[j+1]){
				temp=p[j];
				p[j]=p[j+1];
				p[j+1]=temp;
			}
		}
	}
		for(i=0;i<r;i++){
		int temp;
		for(j=0;j<r-1;j++){
			if(m[j]>m[j+1]){
				temp=m[j];
				m[j]=m[j+1];
				m[j+1]=temp;
			}
		}
	}
		for(i=0;i<n;i++){
		printf("%d\t",p[i]);
	}
	printf("\n");
		for(i=0;i<r;i++){
		printf("%d\t",m[i]);
	}
		printf("\n");
		int in=0;
	for(i=0;i<n;i++){
		int f=0;
		for(j=0;j<r;j++){
			if(p[i]<=m[j]){
				printf("\n%d in %d",p[i],m[j]);
					in=in+m[j]-p[i];
				m[j]=p[i]=0;
			
				f=1;
				break;	
			}
//		else if(p[i]<m[j]){
//				printf("%d in %d",p[i],m[j]);
//				m[j]=p[i]=0;
//				f=1;
//				break;
//			}
		}
		if(f==0){
			printf("\n%d has no sufficient place:",p[i]);
		}
	}
	int ex=0;
		for(i=0;i<r;i++){
		if(m[i]!=0 && p[i]!=0){
		ex=ex+m[i]	;
		}
	
	}
		printf("external memory :%d\t",ex);
	int pp=0;
for(i=0;i<n;i++){
	if(p[i]!=0){
		pp=pp+p[i];
	}
}

		if(pp<=ex){
		printf("\texternal fragmentation\t");
	}
		else{
			printf("not external fragmentation\t");
		}
	

	printf("\ninternal memory %d",in);
}
