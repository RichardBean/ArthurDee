#include <stdio.h>
#include <string.h>
#include <stdlib.h>

main(int argc, char **argv)
{
	FILE *f;

	if (argc!=3) exit(1);

	// word file

	f = fopen(argv[2],"r");
	while(1)
	{
		char s[200];
		int i,j=0;
		fscanf(f,"%s",s);
		if (feof(f)) break;
		for (i = 0; i < strlen(s); i++)
			if (argv[1][i] != s[i]) j++;
		printf("%d %s\n",j,s);
	}
	fclose(f);
			
	

}
