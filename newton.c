#include<stdio.h>

int main()
{
	double x, y, a, fa, dfa, difx;
	int i;

	a = 2;

	y = 0;

	for(i = 0; i < 10; i++)
	{
		fa = 3 * a * a + 2 * a - 5;

		dfa = 6 * a + 2;

		x = (y - fa) / dfa + a;

		difx = a - x;   //解との差を導出

		printf("a=%f,x=%f,差=%f\n", a, x, difx);

		if((-0.0001 < difx) && (difx < 0.0001))   //収束条件を設定
		{
			printf("解=%f,収束しました。\n", x);

			i = 11;
		}

		
		if(i == 10)  //発散条件を設定
		{
			printf("収束しませんでした。\n");
		}

		a = x;  //aの値を更新

	}
	return 0;
}

