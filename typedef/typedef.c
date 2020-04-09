#include <u.h>
#include <libc.h>

/* Bad part - error

	We're missing the `typedef` line for `uint64`. 

	The function is not able to be declared as the type was not defined. 
	
	Note that the variable declaration typedef.c:24 does not show an error. 
*/

/*typedef unsigned long long uint64;*/

uint64
twice(uint64 n)
{
	return 2*n;
}

void
main(int, char*[])
{
	uint64 n = 2;

	print("%ulld\n", twice(n));

	exits(nil);
}
