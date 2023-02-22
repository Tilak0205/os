#include<stdio.h>
int main(){
	int n,r;
	printf("enter number of processes");
	scanf("%d",&n);
	int p[n],i,j,ex=0,rem[5];
	for(i=0;i<n;i++){
			scanf("%d",&p[i]);
	}
		printf("enter number of memories");
	scanf("%d",&r);
	int m[r];
		for(i=0;i<r;i++)
		{
			scanf("%d",&m[i]);
     	}
	int in=0;
	for(i=0;i<n;i++){
		int f=0;
		for(j=0;j<r;j++)
		{
		if(p[i]<=m[j]){
		in=in+m[j]-p[i];
			printf("%d in %d",p[i],m[j]);
		m[j]=p[i]=0;
		//		i++;
        f=1;
		break;	
	}
//	else{
//		
//		m[i]=m[i];
//    	ex=ex+m[j];
//		printf("in sufficient memory for %d < %d",p[i],m[j]);
//    	rem[count]=m[j];
//		count++;
//	}
}
if(f==0){
	printf("%d cannot fit in any memory",p[i]);	
}
	}
	
//	printf("\n");
	for(i=0;i<r;i++){
		if(m[i]!=0 && p[i]!=0){
		ex=ex+m[i]	;
		}
	
	}
		printf("external memory :%d\t",ex);
	
//		printf("\nexternal memory %d",ex);
//	int total=in+ex;
//	printf("\n");
//	printf("remaining processes:");
//	for( i=0;i<count;i++){
//		printf("%d\t",rem[i]);
//	}
//	
//	
int pp=0;
for(i=0;i<n;i++){
	if(p[i]!=0){
		pp=pp+p[i];
	}
}
	if(pp<ex){
		printf("\texternal fragmentation\t");
	}
		else{
			printf("no external fragmentation\t");
		}
	

	printf("\ninternal memory %d",in);
	

}
