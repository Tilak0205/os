#include <stdio.h>
 
int findLRU(int time[], int n)
{
   int i, minimum = time[0], pos = 0;
 
   for (i = 1; i < n; ++i)
   {
      if (time[i] < minimum)
      {
         minimum = time[i];
         pos = i;
      }
   }
 
   return pos;
}

int main()
{
   int np,nf,counter = 0, time[10], flag1, flag2, i, j, pos, faults = 0;
   printf("Enter number of frames: ");
   scanf("%d", &nf);
 
   printf("Enter number of pages: ");
   scanf("%d", &np);
   int frames[nf],pages[np];
 
   printf("Enter the pages: ");
 
   for (i = 0; i < np; ++i)
   {
      scanf("%d", &pages[i]);
   }
 
   for (i = 0; i < nf; ++i)
   {
      frames[i] = -1;
   }
 
 	printf("\n\n");
   for (i = 0; i < np; ++i)
   {
   	  printf("%d  Frames: ",pages[i]);
      flag1 = flag2 = 0;
 
      for (j = 0; j < nf; ++j)
      {
         if (frames[j] == pages[i])
         {
            counter++;
            time[j] = counter;
            flag1 = flag2 = 1;
            break;
         }
      }
 
      if (flag1 == 0)
      {
         for (j = 0; j < nf; ++j)
         {
            if (frames[j] == -1)
            {
               counter++;
               faults++;
               frames[j] = pages[i];
               time[j] = counter;
               flag2 = 1;
               break;
            }
         }
      }
 
      if (flag2 == 0)
      {
         pos = findLRU(time, nf);
         counter++;
         faults++;
         frames[pos] = pages[i];
         time[pos] = counter;
      }
      for (j = 0; j < nf; ++j)
      {
         printf("%d  ", frames[j]);
      }
      printf("\n");
   }
 	int hit=np-faults;
   printf("\nTotal Page Faults = %d", faults);
   printf("\nTotal page Hits = %d", hit);
   printf("\nHit Ratio: %.2f\nFault Ratio: %.2f",(float)hit/np,(float)faults/np);
 
   return 0;
}

/*
Enter number of frames: 4
Enter number of pages: 14
Enter the pages: 7
0
1
2
0
3
0
4
2
3
0
3
2
3


7  Frames: 7  -1  -1  -1
0  Frames: 7  0  -1  -1
1  Frames: 7  0  1  -1
2  Frames: 7  0  1  2
0  Frames: 7  0  1  2
3  Frames: 3  0  1  2
0  Frames: 3  0  1  2
4  Frames: 3  0  4  2
2  Frames: 3  0  4  2
3  Frames: 3  0  4  2
0  Frames: 3  0  4  2
3  Frames: 3  0  4  2
2  Frames: 3  0  4  2
3  Frames: 3  0  4  2

Total Page Faults = 6
Total page Hits = 8
Hit Ratio: 0.57
Fault Ratio: 0.43
*/

