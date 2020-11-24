#include<stdio.h>

double get_y1 (double x1)
{
	return(1 / x1);
}

double get_y2 (double x2)
{
	return(1 / x2);
}

int main()
{
	double x1, x2, y1, y2, n, difx, sumy, dfx; 

	printf("f(x) = 1 / x [1,2] を台形法を用いて積分します。\n");
	printf("積分区間をn等分にします。\n");
	printf("nの値を入力してください。\n");
	printf("n = ");
	//積分区間を何等分するかを決定

	scanf("%lf", &n);

	difx = 1 / n;
	x1 = 1;
	x2 = 1 + difx;
	sumy = 0;
	//各変数の初期値を決定

	while(1)
	{
		y1 = get_y1(x1);
		y2 = get_y2(x2);

		sumy = sumy + y1 + y2;

		if(x2 >= 2)
		{
			break;
		}

		x1 = x1 + difx;
		x2 = x2 + difx;
	}
	//yの合計を導出

	dfx = difx * sumy / 2;
	//解を導出

	printf("deltax = %f\n", difx);
	printf("解 = %lf\n", dfx);

	return 0;
}
