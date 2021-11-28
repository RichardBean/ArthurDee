#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char c[] = "abcdefghiklmnopqrstuwxyz";

char p[12][24] = {
	"abcdefghiklmnopqrstuwxyz", // ab
	"abcdefghiklmopqrstuwxyzn", // cd
	"abcdefghiklmpqrstuwxyzno", // ef
	"abcdefghiklmqrstuwxyznop", // gh 
	"abcdefghiklmrstuwxyznopq", // ik
	"abcdefghiklmstuwxyznopqr", // lm
	"abcdefghiklmtuwxyznopqrs", // no
	"abcdefghiklmuwxyznopqrst", // pq
	"abcdefghiklmwxyznopqrstu", // rs
	"abcdefghiklmxyznopqrstuw", // tu
	"abcdefghiklmyznopqrstuwx", // wx
	"abcdefghiklmznopqrstuwxy"  // yz
};


char pt[1500];

void *portaDecipher (char *key, char *out)
{
	int i;
	int period = strlen(key);
	int len = strlen(pt);

	for (i = 0; i < len; i++)
	{
		int j = (strchr(c, key[i % period])-c) / 2; // 0 to 11
		int k = (strchr(p[j], pt[i])-p[j]); // 0 to 23
		// now 0 to 11 goes to 12 to 23; 12 to 23 goes to 0 to 11
		if (k < 12) k+= 12; else k-=12;
		out[i] = p[j][k];
	}
	out[len] = 0;
}

main(int argc, char **argv)
{
	char key[52],out[1500];
	int i;

	if (argc != 3) exit (1);

	strcpy(pt,argv[1]);
	strcpy(key,argv[2]);

	for (i = 0; i < strlen(pt); i++) { if (pt[i] == 'j') pt[i] = 'i'; if (pt[i] == 'v') pt[i] = 'u'; }
	for (i = 0; i < strlen(key); i++) { if (key[i] == 'j') key[i] = 'i'; if (key[i] == 'v') key[i] = 'u'; }

	portaDecipher(key, out);
	printf("%s\n", out);
	fflush(stdout);
}
