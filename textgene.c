#include <stdio.h>
#include <ctype.h>
 
int main()
{
	FILE *lf,*sf;
	int c;
 
	if(!(lf=fopen("inalph.txt","r")) || (!(sf=fopen("outalph.txt","w"))))
	{
		printf(" ファイルオープンエラー\n");
		return -1;
	}
 
	while((c=fgetc(lf))!=EOF)
	{
	
		if(isalpha(c))
		{
			if('A' <= c && c <= 'Z')
			{
				c = c + ('a' - 'A');
				fputc(c,sf);
			} else {
				fputc(c,sf);
			}
		} else if(c == ' ') {
			fputc(c,sf);
		} else if(c == '\n') {
			fputc(c,sf);
		} else {
			fputc(' ',sf);
		}
	}
 
	fclose(sf);
	fclose(lf);
 
	return 0;
}
