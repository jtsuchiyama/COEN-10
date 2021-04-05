#define ITERATIONS 10

#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int main ()
{
	int number1, number2, guess, correct, actual;

	srand ((int) time(NULL));

	for (int i = 0; i<10; i++)	{
		number1 = rand()%13;
		number2 = rand()%13;
		printf("%d x %d \n",number1,number2);
		actual=number1*number2;		

		scanf("%d", &guess);
		if (guess == number1*number2)	{
			printf("Correct! \n");
			correct+=10;

}

		else
			printf("Incorrect... \nThe correct answer is %d\n",actual);
		
}

printf("You got %d%% correct \n", correct);

}
