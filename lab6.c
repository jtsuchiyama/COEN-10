#define SIZE 5
#include <stdio.h>
int main()	{

int option, i;
int delete = 0;
int flag=0;
int apts = 0;
int schedule[SIZE] = {0, 0, 0, 0, 0};
while (flag==0)	{
	printf ("Menu \n 1 - Schedule a lesson \n 2 - Delete \n 3 - List \n 9 - Quit \n Enter an option:");
	scanf("%d",&option);
	switch(option)	{
		
		case 1:
			if (apts==5)	{
				printf("We're busy today. Come back tomorrow \n");
			}
			else	{
				for (i=0; i<5; i++)	{
					if(schedule[i]==0)	{
						schedule[i]=1;
						apts ++;
						printf("Your appointment is scheduled for %d pm \n", i+1);
						break;
					}
			}	
			}
			break;		

		case 2:		
			printf("What time slot do you want to delete? \n");
			scanf("%d",&delete);
				if(schedule[delete-1]==1)	{
					schedule[delete-1]=0;
					apts --;
					printf("Your %d pm lesson is deleted \n", delete); 
				}
				else	{
					printf("There is no lesson scheduled at %d pm \n", delete);
}
				break;
		case 3:
			for(i=0; i<5; i++)	{
				if(schedule[i]==0)	{
					printf("%d: Free \n", i+1);								}			
				else	{		
					printf("%d: Lesson \n", i+1);
					}
					}
				break;
				
		case 9:
			flag=1;
			break;

		default: 
			printf("Bad input! \n");
			break;
}
}
}
