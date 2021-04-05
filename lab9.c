#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main();
void input();
void reverse();
void convert();
void info();
void output();

char words[10][20];
int length[10];
int counter=0;
int i, j;

int main ()
{
	input();
	reverse();
	convert();
	info();

	return 1;
}

void input()
{
	printf("Enter up to 10 words: \n");
	int flag=0;
	char input[20];
	while (flag==0)
	{
		if(counter<10)
		{
			if(scanf("%s", input)!=1)
			{	
				break;
			}
			else
			{
				for(i=0; i<counter; i++)
				{
					if(strcmp(input,words[i])<0)
					{
						break;
					}
				}
				for(j=counter-1; j>=i; j--)
				{
					strcpy(words[j+1], words[j]);
				}
				strcpy(words[i],input);
				counter++;
			}
		}
		else
		{
			break;
		}
	}
	printf("In order: \n");
	output();	
}	

void reverse()
{
	char temp[20];
	j=counter-1;
	for(i=0; i<counter/2; i++, j--)
	{
		strcpy(temp,words[i]);
		strcpy(words[i],words[j]);
		strcpy(words[j],temp);
	}
	printf("Reversed: \n");
	output();
	
}

void convert() 
{
	char *p;
	for (i=0; i<counter; i++)
	{
		int size=0;
		p=&words[i][0];
		while(*p!='\0')
		{
			size++;
			p++;
		}
		length[i]=size;
		for(j=0; j<length[i]; j++)
		{
			p=&words[i][j];
			if((islower(*p))!=0)
			{
				*p=toupper(*p);			
			}
		}
	}
	printf("Converted: \n");
	output();
}

void info()
{	
	int *p=length;
	p++;
	int i=1;
	int shrt=0;
	int lng=0;
	int *sptr=length;
	int *lptr=length;


	int *r=length;
	char *q;
	int sum=0;
	while(*p!='\0')
	{
		if(*p<*sptr)
			{
				shrt=i;
				sptr=p;	
			}
		if(*p>*lptr)
			{
				lng=i;	
				lptr=p;
			}
		i++;
		p++;			
	}
	while(*r!='\0')
	{
		sum+=*r;
		r++;
	}
	printf("The shortest string is %s \n", words[shrt]);
	printf("The longest string is %s \n", words[lng]);
	printf("The average string length is %d \n", sum/counter);
	printf("Words not starting with a letter \n");
	
	for(i=0;i<counter;i++)
	{
		char q=words[i][0];
		if((isalpha(q))==0)
		{
			printf("%s \n", words[i]);
		}
	}

}

void output()
{
	for(i=0; i<counter; i++)
	{	
		printf("%s \n", words[i]);
	}
}
