#include <stdio.h>
#include <errno.h>

int main()
{
	FILE *in,*out;
	char line[80];

	if ((in = fopen("input", "r")) == NULL)
		perror("fopen:");
	if ((out = fopen("output", "w")) == NULL)
		perror("fopen:");

	while ((fgets(line, 80, in)) != NULL)
		fputs(line, out);
}

