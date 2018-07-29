#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <buffers.h>

void print_prime_factors(long to_find)
{
	long i;
	for(i = to_find/2; i > 1; i--)
	{
		if( to_find % i == 0 )
		{
			print_prime_factors(i);
			print_prime_factors((to_find / i));
			return;
		}
	}
	if(i == 1)
	{
		printf("Prime Factor: %lu\n", to_find);
	}
}

int main(int argc, char ** argv)
{
	if(argc <= 1)
	{
		printf("Usage:\n[number] - finds all prime factors\n");
		return 1;
	}
	long to_pfactor;
	char * end_ptr;
	to_pfactor = strtol(argv[1], &end_ptr, 10);
	if(errno != 0)
	{
		printf("Failed to prime factorize: %s\n", strerror(errno));
		return 1;
	}
	printf("Finding prime factors: %ld\nThrown away: %s\n", to_pfactor, end_ptr);
	print_prime_factors(to_pfactor);
	return 0;
}
