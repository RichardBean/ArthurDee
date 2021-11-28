#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/time.h>
#include <math.h>

char c[] = "abcdefghiklmnopqrstuwxyz";

main(int argc, char **argv)
{

	char ct[20];
	if (argc != 2) exit (1);

	strcpy(ct,argv[1]);
	int len = strlen(ct),i;

			int k;
			for (k = 0; k < 1<<len; k++)
			{
			 for (i = 0; i < len; i++) 
			 	printf("%c",ct[i]+((k & (1<<i))?1:0)); printf("\n");  
			}
}
