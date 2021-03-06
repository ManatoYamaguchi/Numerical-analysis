#include<stdio.h>

double get_y1 (double x1)
{
	return(1 / x1);
}

double get_y2 (double x2)
{
	return(1 / x2);
}

double get_y3 (double x3)
{
	return(1 / x3);
}

int main()
{
	double x1, x2, x3, y1, y2, y3, n, difx, sumy, dfx;

	printf("f(x) = 1 / x [1,2] をシンプソン法を用いて積分します。\n");
	printf("積分区間をn等分にします。\n");
	printf("nの値を入力してください。\n");
	printf("n = ");
	//積分区間を何等分にするかを決定

	scanf("%lf", &n);

	difx = 1 / n;
	x1 = 1;
	x3 = 1 + difx;
	x2 = (x1 + x3) / 2;
	sumy = 0;
	//各変数の初期値を決定

	while(1)
	{
		y1 = get_y1(x1);
		y2 = get_y2(x2);
		y3 = get_y3(x3);

		sumy = sumy + y1 + (4 * y2) + y3;

		if(x3 >= 2)
		{
			break;
		}

		x1 = x1 + difx;
		x3 = x3 + difx;
		x2 = (x1 + x3) / 2;
	}
	//yの合計を導出

	dfx = difx * sumy / 6;
	//解を導出

	printf("deltax = %lf\n", difx);
	printf("解 = %lf\n", dfx);

	return 0;
}
