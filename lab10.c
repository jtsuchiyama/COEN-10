#include <stdio.h>
#include <string.h>

void schedule();
void cancel();
void list();
void firstletter();
void groupsizes();
int countletter();
void priority();
void badinput();

int apts=0;

int gsizes[5];
char names[5][20];
char contacts[5][20];

int main ()
{
	int option, number;
	int pflag=0;
	char letter;
	while (1)	
	{
		printf ("Menu \n 1 - Schedule a lesson \n 2 - Delete \n 3 - List \n 4 - Groups with given letter \n 5 - Groups with given group size \n 6 - Priority \n 7 - Count letters \n 9 - Quit \n Enter an option:");
		scanf("%d",&option);
		switch(option)	
		{
			case 1:
				schedule();			
				break;				

			case 2:
				cancel();			
				break;				

			case 3:
				list();
				break;	

			case 4:
				firstletter();
				break;

			case 5:
				groupsizes();
				break;			

			case 6:
				if (pflag==0)
				{
					priority();
					pflag=1;
				}
				else
					printf("You have already used your priority \n");
				break;
			
			case 7:
				printf("Which letter are you searching for? \n");
				scanf(" %c", &letter);		
				countletter();
				number=countletter(letter);
				printf("Found %d occurances of the letter %c \n", number, letter);	
				break;

			case 9:
				return 0;

			default:
				badinput();
				break;

		}
	}
}
			
void schedule()
{
	int i;
	int gsize=0;
	char name[20];
	char contact[20];
	if (apts==5)	
	{
		printf("We're busy today. Come back tomorrow \n");
	}	
	else	
	{
		int found=0;
		printf("What is your name? \n");
		scanf(" %s", name);
		for (i=0; i<5; i++)
		{
			if(strcmp(name,names[i])==0)
			{
				found=1;
				printf("There is already a lesson scheduled under that name \n");
				break;	
			}
		}
		if (found==0)
		{
			printf("What is your phone number \n");	
			scanf(" %s", contact);
		
			printf("How many people are in your group \n");
			scanf(" %d", &gsize);
			if (gsize>0 && gsize<5)
			{
				gsizes[apts]=gsize;
				printf("%s, your lesson is scheduled for %d pm, and the size of the group is %d \n", name, apts+1, gsize);
				strcpy(names[apts], name);
				strcpy(contacts[apts],contact);
				gsizes[apts]=gsize;
				apts++;
			}
			else
			{
				printf("The group size must be between 1 and 4. Please enter a valid group number. \n");
			}
		}		
	}			
}

void cancel ()
{	
	int found=0;
	int i, j;
	char name[20];	
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
			if (strcmp(names[i],name)==0)
			{
				names[i][0]='\0';
				printf("Your lesson at %d pm for %d people has been canceled, %s \n", i+1, gsizes[i],  name);
				for(j=0; j<5; j++)
				{
					if(names[j][0]=='\0')
					{
						if(names[j+1][0]!='\0')
						{
							printf("The time changed for %s, %s, with a group size of %d, from %d pm to %d pm \n", names[j+1], contacts[j+1], gsizes[j+1], j+2, j+1);
						}
						strcpy(names[j],names[j+1]);
						names[j+1][0]='\0';
						strcpy(contacts[j],contacts[j+1]);
						contacts[j+1][0]='\0';
						gsizes[j]=gsizes[j+1];
						gsizes[j+1]=0;
						found=1;
					}
				}
				apts--;										
				break;	
			}
		}
		if(found==0)
		{
		printf("There are no lessons under that name \n");
		}
	}
}

void list ()
{
	int i;
	for(i=0; i<5; i++)	
	{
		if(names[i][0]=='\0')	
		{
			printf("%d: Free \n", i+1);						
		}			
		else	
		{		
			printf("%d: %s, Phone Number: %s, Group Size: %d \n", i+1, names[i], contacts[i], gsizes[i]);
		}
	}
}			

void firstletter ()
{
	int i;
	char letter;
	if(apts!=0)
	{
		printf("What is the letter that you want to search for \n");
		scanf(" %c", &letter);
		for (i=0; i<5; i++)
		{
			if(letter==names[i][0])
			{
				printf("%s at %d pm \n", names[i], i+1);
			}
		}
	}
	else
	{
		printf("There are no lessons scheduled \n");
	}
}	

void groupsizes()
{
	int i;
	int gsize=0;
	if (apts!=0)
	{
		printf("What is the group size that you want to search for \n");
		scanf(" %d", &gsize);
		for (i=0; i<5; i++)
		{
			if(gsize==gsizes[i])
				printf("%s at %d pm \n", names[i], i+1);
		}
	}
	else
	{
		printf("There are no lessons scheduled \n");
	}
}

void priority()
{
	int i=0;
	int j;
	int gsize=0;
	int found=0;
	char name[20];
	char contact[20];
	printf("What is your name \n");
	scanf(" %s", name);
	for (j=0; j<5; j++)
	{
		if(strcmp(name,names[j])==0)
		{
			found=1;
			printf("There is already a lesson scheduled under that name \n");
			break;
		}
	}
	if(found==0)
	{
		printf("What is your phone number \n");
		scanf(" %s", contact);
		printf("What is your group size \n");
		scanf(" %d", &gsize);
		while(names[i][0]!='\0')
		{
			i++;
		}
		if(apts==5)
		{
			printf("Canceling %s at 5pm, Phone Number: %s, Group Size: %d \n", names[4], contacts[4], gsizes[4]);	
			i-=2;
		}
		else
		{
			i--;
			apts++;
		}
		while(i>=0)
		{
			strcpy(names[i+1],names[i]);
			strcpy(contacts[i+1],contacts[i]);
			gsizes[i+1]=gsizes[i];
			printf("The time changed for %s, %s, with a group size of %d, from %d pm to %d pm \n", names[i], contacts[i], gsizes[i], i+1, i+2);
			i--;	
		}
		strcpy(names[0],name);
		strcpy(contacts[0],contact);
		gsizes[0]=gsize;
	}
	
}


int countletter(letter)
{
	int i;
	int counter=0;
	char *p;
	for(i=0;i<apts; i++)
	{
		p=&names[i][0];
		while(*p!='\0')
		{
			if(*p==letter)
				counter++;
			p++;
		}
	}
	return counter;
}

void badinput ()	
{ 
	printf("Bad input! \n");
}
			
