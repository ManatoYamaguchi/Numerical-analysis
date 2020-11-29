#include<stdio.h>

int main()
{
	int count, alph, freqnum[27] = {0}; 
	FILE *infile, *outfile;

	if(!(infile = fopen("outalph.txt","r")) || (!(outfile = fopen("alphfreq.txt", "w"))))
	{
		printf("ファイルの読み込みに失敗\n");		//テキストファイルの読み込み＆エラー表示
		return 1;
	}

	while((alph = fgetc(infile)) != EOF)			//テキストファイルから一文字ずつ読み込み
	{
		if(alph == ' ')					//spaceの場合２７番目の要素を＋１
		{
			freqnum[26] = freqnum[26] + 1;
		} else if(alph >= 97 && alph <= 122) {		//アルファベットの場合それぞれの要素に＋１
			freqnum[alph - 97] = freqnum[alph - 97] + 1;
		}
	}

	for(count = 0; count < 27; count++)
	{
		if(count == 26)					//２６番目(space)の時の入力
		{
			fprintf(outfile, "%d : '_'\n", freqnum[26]);
		} else {					//２６番目(space)以外の時の入力
			fprintf(outfile, "%d : '%c'\n", freqnum[count], count + 97);
		}
	}	


	fclose(outfile);					//テキストファイルを閉じる
	fclose(infile);

	return 0;
}

