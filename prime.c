#include <stdio.h>
#include <time.h> 

int check_prime(int x);
int get_int(void);
char get_char(void);

int main(void)
{
	//check execution time
	double time_spent = 0.0;
 
    clock_t time_begin = clock();
	
	//User Inputs
	printf("Starting number of the range: \n");
	int range_start = get_int();
	printf("Ending number of the range: \n");
	int range_end = get_int();
	printf("Display the list of prime numbers?[y/n)] \n");
	char display_list = get_char();
	printf("\n");

	//Looping through the range
	int prime_counter = 0;
	
	for (int i = range_start; i <=range_end; ++i)
	{
		//checkin for prime numbers
		int ans = check_prime(i);
		
		//couting prime number
		if (ans == 1)
		{
			prime_counter++;

			//list display
			if (display_list == 'y' || display_list == 'Y')
			{
				printf("%i", i);

				if (prime_counter % 15 == 0)
				{
					printf("\n");
				}
				else
				{
					printf("\t");
				}
			}
		}
	}

	printf("\nNumber of prime numbers = %i\n", prime_counter);
	clock_t time_end = clock();
	time_spent += (double)(time_end - time_begin) / CLOCKS_PER_SEC;
	printf("\nThe elapsed time is %f seconds\n", time_spent);
}

//Function to check prime
int check_prime(int x)
{
	int n = 1;
	int r, m;
	
	//Dividing n by all numbers from 2 to n until remainder is 0 
	do
	{
		n++;
		r = x % n;		

	} while (r != 0 && x != 1);

	//checking is n is equal to x
	if (x == n)
		return 1;
	else
		return 0;
}

//Function to get int as a user Input 
int get_int(void)
{
	int x;
	scanf("%d", &x);
	return x;
}

//Function to get int as a user Input 
char get_char(void)
{
	char c;
	scanf(" %c", &c);
	return c;
}
