#include <u.h>
#include <libc.h>

/* Bad part - warning

	We're missing a `void` in the function declaration's arguments.
	
	The compiler is right, ret1 is not declared as we use it.
	
	Internally, ret1() and ret1(void) are different signatures. 
*/

int
ret1(/*void*/)
{
	return 1;
}

void
main(int, char*[])
{
	print("%d\n", ret1());

	exits(nil);
}
