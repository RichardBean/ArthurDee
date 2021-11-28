#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int
main(int argc, char **argv)
{
	char		s         [74];
	int		c = 0,l;
	if (argc!=2) exit(1);
	l = atoi(argv[1]);
	s[l] = 0;
	while (1) {
		char s[200],ch;
		if (feof(stdin))
			break;
		ch = getc(stdin);
		if (ch >= 'A' && ch <= 'Z') { ch -= 'A'; ch+='a'; }
		if (ch < 'a' || ch > 'z') continue;
		if (c < l) s[c] = ch;
		c++;
		if (c == l) {
			int j;
			s[l] = 0;
			printf("%s\n",s);
			for (j = 0; j < l-1; j++) s[j] = s[j+1];	
			c--;
			}
	}
}


