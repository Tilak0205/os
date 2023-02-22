#include <stdio.h>
#include <stdlib.h>

int main(){
	int p;
	printf("enter no of processors: ");
	scanf("%d",&p);
	int pr[p];
	printf("enter processors: ");
	for(int i=0;i< p;i++){
		scanf("%d",&pr[i]);
	}
	int m;
	printf("enter no of memory blocks: ");
	scanf("%d",&m);
	int mem[m];
	int vis[m];
	int internal = 0;
	int external = 0;
	printf("enter memory blocks: ");
	for(int i=0;i< m;i++){
		scanf("%d",&mem[i]);
		vis[i]=0;
	}
	for(int i=0;i< p;i++){
		int j;
		for(j=0;j< m;j++){
			if(vis[j]==0 && pr[i] <= mem[j]){
				printf("processor(%d) and memory_block(%d) \n",pr[i],mem[j]);
				internal = internal + mem[j]-pr[i];
				vis[j]=1;
				break;
			}
		}
		if(j == m){
			printf("processort(%d) is not allocated\n",pr[i]);
		}
	}
	for(int i=0;i< m;i++){
		if(vis[i]==0){
			external += mem[i];
		}
	}
	
	printf("Internal fragmentation: %d\n",internal);
	printf("External fragmentation: %d\n",external);
}


/*
enter no of processors: 4
enter processors: 212
417
112
426
enter no of memory blocks: 5
enter memory blocks: 100
500
200
300
600
processor(212) and memory_block(500)
processor(417) and memory_block(600)
processor(112) and memory_block(200)
processort(426) is not allocated
Internal fragmentation: 559
External fragmentation: 400
*/
