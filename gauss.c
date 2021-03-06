#include<stdio.h>

double get_x1(double x2, double x3)
{
	return((10.0 - x2 - x3) / 5.0);
}

double get_x2(double x1, double x3)
{
	return((12.0 - x1 - x3) / 4.0);
}

double get_x3(double x1, double x2)
{
	return((13.0 - 2.0 * x1 -x2) / 3.0);
}

int main()
{
	double x1, x2, x3, xx1, xx2, xx3, difx1, difx2, difx3;
	int i;

	x1 = x2 = x3 = 1.0;
	xx1 = xx2 = xx3 = 0.0;
	difx1 = difx2 = difx3 = 0.0; //double型の変数に初期値を入れる 

	for(i = 0; i < 20; i++)
	{

		x1 = get_x1(x2, x3);
		x2 = get_x2(x1, x3);
		x3 = get_x3(x1, x2);

		difx1 = x1 - xx1;
		difx2 = x2 - xx2;
		difx3 = x3 - xx3;//n回目とn-1回目の変数の差をdif変数に入れる

		printf("[i=%d] x1 = %.10f, x2 = %.10f, x3 = %.10f\n", i+1, x1, x2, x3);

		if((difx1 > -0.00001) && (difx1 < 0.00001) &&
			     	(difx2 > -0.00001) && (difx2 < 0.00001) && (difx3 > -0.00001) && (difx3 < 0.00001))
		{
			printf("収束しました。\n");
			//if内の条件を満たしたときに「収束しました。」と表示してループを終了する
			i = 20;
		}

		xx1 = x1;
		xx2 = x2;
		xx3 = x3;//n-1回目の変数をn回目の変数に更新する
	}
	
	return 0;
}	
