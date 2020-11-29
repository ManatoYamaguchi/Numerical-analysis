#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
	srand((unsigned int)time(NULL));

	int  alph, count, maxnum, randnum;
	FILE *infile, *outfile;

	if(!(infile = fopen("outalph.txt", "r")) || (!(outfile = fopen("strgene.txt", "w"))))
	{
		printf("ファイルの読み込みに失敗\n");		//テキストファイルの読み込み＆エラー表示
		return 1;
	}

	maxnum = 0;

	while((alph = fgetc(infile)) != EOF)			//テキストファイルから一文字ずつ読み込み
	{
		maxnum++;					//テキストファイル全体の字数をカウント
	}

	rewind(infile);						//テキストファイルのファイル位置を先頭に戻す

	char str[maxnum];

	for(count = 0; count < maxnum; count++)
	{
		fscanf(infile, "%c", &str[count]);		//テキストファイルから一文字ずつ配列に格納
	}

	for(count = 0; count < 100; count++)
	{
		randnum = rand()%maxnum;			//乱数の生成
		fprintf(outfile, "%c", str[randnum]);		//配列の乱数番目の要素を入力
	}

	fclose(infile);						//テキストファイルを閉じる
	fclose(outfile);

	return 0;
}

