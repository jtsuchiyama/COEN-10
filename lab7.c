#include <stdio.h>
#include <string.h>
int main()	
{
	int option, i, j, found;
	int flag=0;
	int apts = 0;
	char name[20];
	char letter;
	char schedule[5][20];
	
	for(i=0; i<5; i++) 
	{
		schedule[i][0] = '\0';	
	}
	
	while (flag==0)	
	{
		printf ("Menu \n 1 - Schedule a lesson \n 2 - Delete \n 3 - List \n 4 - Names with given letter \n 9 - Quit \n Enter an option:");
		scanf("%d",&option);
		switch(option)	
		{
			case 1:
				if (apts==5)	
				{
					printf("We're busy today. Come back tomorrow \n");
				}	
				else	
				{
					printf("What is your name? \n");
					scanf("%s", name);
					strcpy(schedule[apts],name);
					apts++;
					printf("%s, Your lesson is scheduled for %d pm \n", name, apts);
				}
				break;		

			case 2:		
				found=0;
				if (apts==0)
				{
					printf("There are no reserved lessons \n");
				}
				else
				{
					printf("What is your name? \n");
					scanf("%s",name);
					for(i=0; i<5; i++)
					{
						if (strcmp(schedule[i],name)==0)
						{
							schedule[i][0]='\0';
							printf("Your lesson at %d pm has been canceled, %s \n", i+1, name);
							apts--;
							for(j=0; j<5; j++)
							{
								if(schedule[j][0]=='\0')
								{
									strcpy(schedule[j],schedule[j+1]);
									schedule[j+1][0]='\0';
									found=1;
								}
							}							
							
							break;	
						}
					}
					
					if(found==0)
					{
						printf("There are no lessons under that name \n");
					}
				}
				break;

			case 3:
				for(i=0; i<5; i++)	
				{
					if(schedule[i][0]=='\0')	
					{
						printf("%d: Free \n", i+1);						}			
					else	
					{		
						printf("%d: %s \n", i+1, schedule[i]);
					}
				}
				break;
			
			case 4:
				printf("What is the first letter of your name? \n");
				scanf(" %c", &letter);
				for (i=0; i<5; i++)
				{
					if(letter==schedule[i][0])
					{
						printf("%s \n", schedule[i]);
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

