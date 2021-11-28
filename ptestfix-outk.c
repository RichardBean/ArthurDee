#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/time.h>
#include <math.h>

char c[] = "abcdefghiklmnopqrstuwxyz";

char p[12][25] = {
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

/* void *portaDecipher (char *key, char *out)
{
	int i;
	int period = strlen(key);
	int len = strlen(ct);

	for (i = 0; i < len; i++)
	{
		int j = (strchr(c, key[i % period])-c) / 2; // 0 to 11
		int k = (strchr(p[j], ct[i])-p[j]); // 0 to 23
		// now 0 to 11 goes to 12 to 23; 12 to 23 goes to 0 to 11
		if (k < 12) k+= 12; else k-=12;
		out[i] = p[j][k];
	}
	out[len] = 0;
} */

main(int argc, char **argv)
{

	char ct[20];
	if (argc != 2) exit (1);

	strcpy(ct,argv[1]);

	while (1)
	{
		char pt[20],px[20];
		int i,len,poss=0;

		fscanf(stdin,"%s",pt);
		if (feof(stdin)) break;
		if (strlen(pt)!=strlen(ct)) continue;

		len = strlen(pt);

		for (i = 0; i < len; i++)
		{
			int s1,s2,a,good=0;
			for (a = 0; a < 12; a++)
			{
				/* s1 = (strchr(p[a], pt[i]) - p[a])/12;
				s2 = (strchr(p[a], ct[i]) - p[a])/12;
				if (s1 != s2) good = 1; */

				s1 = (strchr(p[a], pt[i]) - p[a]);
				s2 = (strchr(p[a], ct[i]) - p[a]);
				if (s1/12 != s2/12 && s1 % 12 == s2 % 12) good = a+1; 
			}
			if (good > 0) { poss++; px[i] = c[(good-1)*2]; }
		}
		if (poss == len) { 
			int k;
			//printf("%s %s ",ct,pt); 
			for (k = 0; k < 1<<len; k++)
			{
			 for (i = 0; i < len; i++) 
			 	printf("%c",px[i]+((k & (1<<i))?1:0)); printf("\n");  }
		}
	}
}
