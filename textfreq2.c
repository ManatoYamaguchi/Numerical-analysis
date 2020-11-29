#include<stdio.h>

int main()
{
	int count, num, alph, prealph, freqnum[728] = {0}; 
	FILE *infile, *outfile;

	if(!(infile = fopen("outalph.txt","r")) || (!(outfile = fopen("alphfreq2.txt", "w"))))
	{
		printf("ファイルの読み込みに失敗\n");		//テキストファイルの読み込み＆エラー表示
		return 1;
	}

	prealph = fgetc(infile);
	num = 0;

	while((alph = fgetc(infile)) != EOF)			//テキストファイルから一文字ずつ読み込み
	{
		if((alph == ' ') || (alph == '\n'))		//spaceの場合２７番目の要素を＋１
		{
			alph = 26;
			num = prealph + alph;
			freqnum[num]++;
		} else if(alph >= 97 && alph <= 122)		
		{
			alph = alph - 97;
			num = prealph + alph;
			freqnum[num]++;
			prealph = alph * 26;
		}

		prealph = alph * 27;
	}

	for(count = 0; count < 728; count++)
	{
		if((count >= 702) && (count <= 728))
		{
			fprintf(outfile, "%d : '_%c'\n", freqnum[count], count - 605);
		} else if((count % 27) == 26) 
		{
			fprintf(outfile, "%d : '%c_'\n", freqnum[count], count / 27 + 97);
		} else
		{
			fprintf(outfile, "%d : '%c%c'\n", freqnum[count], count / 27 + 97, count % 27 + 97);
		}
	}	


	fclose(outfile);					//テキストファイルを閉じる
	fclose(infile);

	return 0;
}

