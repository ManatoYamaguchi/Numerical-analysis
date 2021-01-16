#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define count 10000000					//試行回数

int main()
{
	int i;
	double x, y, xrand, yrand, rr, difx, dify, pi, area, n;
	
	srand(time(NULL));				//乱数の初期化

	n = 0;

	for(i = 0; i < count; i++)				//ループ
	{
		x = (double)rand() / RAND_MAX;		//乱数を生成
		y = (double)rand() / RAND_MAX;

		difx = (x - 0.5) * (x - 0.5);		//変数の値を定義
		dify = (y - 0.5) * (y - 0.5);
		rr = 0.5 * 0.5;

		if(difx + dify <= rr)			//座標が円内ならば＋１
		{
			n = n + 1;
		}
	}

	area = n / count;				//確率から面積を導出

	pi = area / rr;					//円周率の導出

	printf("pi = %f\n", pi);			//円周率の表示

	return 0;
}
