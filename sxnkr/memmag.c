#include<stdio.h>
#include<stdlib.h>

void implimentFirstFit(int blockSize[], int blocks, int processSize[], int processes)
{
    int allocate[processes];
    int occupied[blocks];
    for(int i = 0; i < processes; i++)
	{
		allocate[i] = -1;
	}
	
	for(int i = 0; i < blocks; i++){
        occupied[i] = 0;
    }

    for (int i = 0; i < processes; i++)
    {
        for (int j = 0; j < blocks; j++) 
        { 
        if (!occupied[j] && blockSize[j] >= processSize[i])
            {
 
                allocate[i] = j;
                occupied[j] = 1;
 
                break;
            }
        }
    }

    printf("\nProcess No.\tProcess Size\tBlock no.\n");
    for (int i = 0; i < processes; i++)
    {
        printf("%d \t\t\t %d \t\t\t", i+1, processSize[i]);
        if (allocate[i] != -1)
            printf("%d\n",allocate[i] + 1);
        else
            printf("Not Allocated\n");
    }
}

void implimentBestFit(int blockSize[], int blocks, int processSize[], int proccesses)
{
 
    int allocation[proccesses];
    int occupied[blocks];
    for(int i = 0; i < proccesses; i++){
        allocation[i] = -1;
    }
    
    for(int i = 0; i < blocks; i++){
        occupied[i] = 0;
    }
    for (int i = 0; i < proccesses; i++)
    {
        
        int indexPlaced = -1;
        for (int j = 0; j < blocks; j++) { 
            if (blockSize[j] >= processSize[i] && !occupied[j])
            {
               if (indexPlaced == -1)
                    indexPlaced = j;

                else if (blockSize[j] < blockSize[indexPlaced])
                    indexPlaced = j;
            }
        }
 

        if (indexPlaced != -1)
        {

            allocation[i] = indexPlaced;

            occupied[indexPlaced] = 1;
        }
    }
 
    printf("\nProcess No.\tProcess Size\tBlock no.\n");
    for (int i = 0; i < proccesses; i++)
    {
        printf("%d \t\t\t %d \t\t\t", i+1, processSize[i]);
        if (allocation[i] != -1)
            printf("%d\n",allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }
}
 

void implimentWorstFit(int blockSize[], int blocks, int processSize[], int processes)
{

    int allocation[processes];
    int occupied[blocks];

    for(int i = 0; i < processes; i++){
        allocation[i] = -1;
    }
    
    for(int i = 0; i < blocks; i++){
        occupied[i] = 0;
    }
 
    for (int i=0; i < processes; i++)
    {
	int indexPlaced = -1;
	for(int j = 0; j < blocks; j++)
	{

	    if(blockSize[j] >= processSize[i] && !occupied[j])
            {

                if (indexPlaced == -1)
                    indexPlaced = j;
      
                else if (blockSize[indexPlaced] < blockSize[j])
                    indexPlaced = j;
            }
        }
 
        if (indexPlaced != -1)
        {
  
            allocation[i] = indexPlaced;
         
            occupied[indexPlaced] = 1;
 
            blockSize[indexPlaced] -= processSize[i];
        }
    }
 
    printf("\nProcess No.\tProcess Size\tBlock no.\n");
    for (int i = 0; i < processes; i++)
    {
        printf("%d \t\t\t %d \t\t\t", i+1, processSize[i]);
        if (allocation[i] != -1)
            printf("%d\n",allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }
}

void main()
{
    int m;
    printf("Enter the block size:");
    scanf("%d",&m);
    int blockSize[m];
    printf("Enter the blocks:");
    for(int z=0;z<m;z++)
    {
        scanf("%d",&blockSize[z]);
    }
    
    int n;
    printf("Enter the number of processes:");
    scanf("%d",&n);
    int processSize[n];
    printf("Enter the processes:");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&processSize[i]);
    }
  
    do
    {
        int choice;
        printf("\n 1.First Fit\t 2.Best Fit\t3.Worst Fit\t4.EXIT");
        printf("\nEnter your choice :- ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            implimentFirstFit(blockSize, m, processSize, n);
            break;
            case 2:
            implimentBestFit(blockSize, m, processSize, n);
            break;
            case 3:
            implimentWorstFit(blockSize, m, processSize, n);
            break;
            case 4:
            break;
        }
               
        }
}

