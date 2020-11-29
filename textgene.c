#include <stdio.h>
#include <ctype.h>
 
int main()
{
	int alph, prechar;
	FILE *infile,*outfile;
 
	if(!(infile = fopen("inalph.txt","r")) || (!(outfile = fopen("outalph.txt","w"))))
	{
		printf(" ファイルの読み込みに失敗\n");		//テキストファイルの読み込み＆エラー表示
		return -1;
	}	

	while((alph = fgetc(infile)) != EOF)			//テキストファイルから一文字ずつ読み込み＆終了
	{
		if(isalpha(alph))
		{
			if('A' <= alph && alph <= 'Z')		//アルファベットの場合
			{
				alph = alph + ('a' - 'A');	//大文字は小文字に変換して入力
				fprintf(outfile, "%c", alph);

			} else {
				fprintf(outfile, "%c", alph);	//小文字の入力

			}
		} else if(alph == ' ') {			//spaceの場合
			if(prechar == ' ')			//前の文字がspaceの場合は今の文字を削除
			{
			} else {
				fprintf(outfile, "%c", alph);	//前の文字がspace以外の場合はそのまま入力

			}
		} else if(alph == '\n') {			//改行の場合そのまま入力
			fprintf(outfile, "%c", alph);

		} else {					//アルファベット、space、改行以外の場合
			if(prechar == ' ')			//前の文字がspaceの場合は今の文字をspaceに変換＆削除
			{
				alph = ' ';
			} else {
				alph = ' ';			//前の文字がspaceの場合は今の文字をspaceに変換＆入力
				fprintf(outfile, "%c", alph);

			}
		}

		prechar = alph;					//今の文字を他の変数に上書き
	}
 
	fclose(infile);						//テキストファイルを閉じる
	fclose(outfile);
 
	return 0;
}
