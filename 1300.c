#include <stdio.h>

#define MOD %

int main (int argc, char **argv)
{

	int n;
	while (scanf("%d", &n) != EOF)
		printf("%c\n", !(n MOD 6) ? 'Y' : 'N');

	return 0;

}
