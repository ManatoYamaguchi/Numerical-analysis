#include<stdio.h>

int main()
{
	int count, num, alph, freqnum[27] = {0}; 
	FILE *infile, *outfile;

	if(!(infile = fopen("outalph.txt","r")) || (!(outfile = fopen("alphfreq.txt", "w"))))
	{
		printf("ファイルの読み込みに失敗\n");
		return 1;
	}

	while((alph = fgetc(infile)) != EOF)
	{
		if(alph == ' ')
		{
			freqnum[26] = freqnum[26] + 1;
		} else if(alph >= 97 && alph <= 122) {
			freqnum[alph - 97] = freqnum[alph - 97] + 1;
		}
	}

	for(count = 0; count < 27; count++)
	{
		if(count == 26)
		{
			fprintf(outfile, "%d : space\n", freqnum[26]);
		} else {
			fprintf(outfile, "%d : %c\n", freqnum[count], count + 97);
		}
	}	


	fclose(outfile);
	fclose(infile);

	return 0;
}

