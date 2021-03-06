#include <stdio.h>
#include <string.h>

#define LEN 4
#define MAX_STR_LEN 4096

char* strnsub (char *p, int n);

int main()
{
	char line[] = "His textbook was bought from that bookstore";
	char *p1, *p2;

	//set p1 to the beginning of string line;
	p1 = line;

	while ( *p1 != '\0' )
	{
		//set p2 to the position immediately after p1
		p2 = p1 + 1;

		while ( *p2 != '\0' )
		{
			if ( strncmp(p1, p2, LEN) == 0 )	// use strncmp() to compare
				goto done;

			// advance p2 to the next position
			p2++;
		}

		// advance p1 to the next position
		p1++;
	}

done:	printf ("the first substring: %s\n", strnsub(p1, LEN));
	printf ("the second substring: %s\n", strnsub(p2, LEN));

	return 0;
}


// returns a string with the first n characters of string p
char* strnsub (char *p, int n)
{
	//*(p + n) = '\0';
	//return p;
	static char str[MAX_STR_LEN];
	int i;
	for(i = 0; i < strlen(p) && i < n; ++i){
		str[i] = p[i];
	}
	str[i] = '\0';
	
	return str;
}
