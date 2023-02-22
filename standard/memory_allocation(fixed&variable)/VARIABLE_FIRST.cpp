#include <stdio.h>
#include <stdlib.h>

int main(){
	int p;
	printf("enter no of processors: ");
	scanf("%d",&p);
	int pr[p];
	int visp[p];
	printf("enter processors: ");
	for(int i=0;i< p;i++){
		scanf("%d",&pr[i]);
		visp[i]=0;
	}	
	int m;
	printf("enter no of memory blocks: ");
	scanf("%d",&m);
	int mem[m];
	int vism[m];
	int internal = 0;
	int external = 0;
	int flag=0;
	printf("enter memory blocks: ");
	for(int i=0;i< m;i++){
		scanf("%d",&mem[i]);
		vism[i]=0;
	}

	for(int i=0;i< p;i++){
		int j;
		for(j=0;j< m;j++){
			if(pr[i] <= mem[j]){
				printf("processor(%d) in %d memory_block(%d)\n",pr[i],j+1,mem[j]);
				mem[j] = mem[j]-pr[i];
				vism[j]=1;
				visp[i]=1;
				break;
			}
		}
		if(j == m){
			printf("%d is not allocated\n",pr[i]);
		}
	}
	
	for(int i=0;i< m;i++){
		if(vism[i]==1){
			internal += mem[i];
		}
		else{
			external += mem[i];
		}
	}
	for(int i=0;i< p;i++){
		if(visp[i]==0 && pr[i] <= external){
			flag = 1;
			break;
		}
	}
	if(flag == 1){
		printf("External fragmentation: %d\n",external+internal);
	}
	else{
		printf("External fragmentation: 0\n");
	}
	
//	printf("\nInternal fragmentation: %d\n",internal);
}

/*
enter no of processors: 4
enter processors: 212
417
112
425
enter no of memory blocks: 5
enter memory blocks: 100
500
200
300
600
processor(212) in 2 memory_block(500)
processor(417) in 5 memory_block(600)
processor(112) in 2 memory_block(288)
425 is not allocated
External fragmentation: 959
*/
