#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#define MIN 1

int main()
{

FILE *e6 = fopen("latin_hex.txt","r");

   //   26 english_monograms.txt
   //  676 english_bigrams.txt
   // 17556 english_trigrams.txt
   // 389373 english_quadgrams.txt
   // 4354914 english_qulonggrams.txt


long *c6 = malloc(26*26*26*26*26*26*  sizeof(long));

	long t6=0,t5=0,t1=0,t2=0,t3=0,t4=0;

	while (1)
	{
		char s[7];
		long c;
		if (feof(e6)) break;
    		fscanf(e6,"%s %ld",s,&c);
		c6[(s[0]-'A')+26*(s[1]-'A')+26*26*(s[2]-'A')+26*26*26*(s[3]-'A')+26*26*26*26*(s[4]-'A')+26*26*26*26*26*(s[5]-'A')] = c;
		t6 += c;
	}

	while (1)
	{
		char s[1000];
		long i; double s1=0.0,s2=0.0,s3=0.0,s4=0.0,s5=0.0,s6=0.0;
		if (feof(stdin)) break;
		scanf("%s",s);
		if (strlen(s) < 6) break;
		for (i = 0; i < strlen(s)-5; i++)
		{
			long a;
			a = c6[s[i]-'a'+26*(s[i+1]-'a')+676*(s[i+2]-'a')+26*26*26*(s[i+3]-'a')+26*26*26*26*(s[i+4]-'a')+26*26*26*26*26*(s[i+5]-'a')];
			if (a>0) s6 += log10((double)a/(double)t6);else s6+= log10(MIN/(double)t6);
		}
		printf("%lf %s\n",s6,s);
			
			
	}
	//printf("%ld %ld %ld %ld %ld %ld\n",t1,t2,t3,t4,t5,t6);
	return 0;
}
