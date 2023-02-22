#include<stdio.h>
int pagefound(int page,int frames[],int l)
{
	int i;
	for(i=0;i<l;i++)
	{
		if(frames[i]==page)
		{
			return 1;
		}
	}
	return  0;
}
void print(int l,int frames[])
{
	int i;
	for(i=0;i<l;i++)
	{
		printf("%d  ",frames[i]);
	}
}
int main()
{
	int n;
	printf("enter the number of pages: ");
	scanf("%d",&n);
	int pages[n];
	printf("enter the pages: \n");
	int i;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&pages[i]);
	}
	printf("enter the number of frames: ");
	int f;
	scanf("%d",&f);
	int frames[f];
	int empty=f;
	int hit=0,fault=0;
	int l=0,top=0;
	printf("\n\n");
	for(i=1;i<=n;i++)
	{
		printf("%d  Frames: ",pages[i]);
		if(empty!=0)
		{
			if(pagefound(pages[i],frames,l)==0)
			{
				frames[l]=pages[i];
				fault++;
				l++;
				empty--;
			}
			else
			{
				hit++;
			}
		}
		else{
			
			if(pagefound(pages[i],frames,l)==0)
			{
				int j;
				frames[top]=pages[i];
				fault++;
				top=(top+1)%f;
			}
			else
			{
				hit++;
			}
		}
		print(l,frames);
		printf("\n");
	}
	printf("\n\n");
	printf("hit==%d\nfault==%d",hit,fault);
	printf("\n");
	printf("Hit Ratio==%f\nMiss Ratio==%f",(float)hit/n,(float)fault/n);
}

//4 7 6 1 7 6 1 2 7 2

/*
enter the number of pages: 7
enter the pages:
1
3
0
3
5
6
3
enter the number of frames: 3


1  Frames: 1
3  Frames: 1  3
0  Frames: 1  3  0
3  Frames: 1  3  0
5  Frames: 5  3  0
6  Frames: 5  6  0
3  Frames: 5  6  3


hit==1
fault==6
Hit Ratio==0.142857
Miss Ratio==0.857143
*/
