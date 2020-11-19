#include<stdio.h>

double get_y1 (double x1)
{
	return(x1*x1*x1*x1 - 2 * x1*x1*x1 + x1*x1 - 3 * x1 + 1);
}

double get_y2 (double x2)
{
	return(x2*x2*x2*x2 - 2 * x2*x2*x2 + x2*x2 - 3 * x2 + 1);
}

int main()
{
	double x1, x2, y1, y2, n, difx, sumy, dfx; 

	printf("f(x) = x^4 - 2x^3 + x^2 - 3x + 1 [0,3] を台形法を用いて積分します。\n");
	printf("積分区間をn等分にします。\n");
	printf("nの値を入力してください。\n");
	printf("n = ");

	scanf("%lf", &n);

	difx = 3 / n;
	x1 = 0;
	x2 = difx;
	sumy = 0;

	while(1)
	{
		y1 = get_y1(x1);
		y2 = get_y2(x2);

		sumy = sumy + y1 + y2;

		if(x2 >= 3)
		{
			break;
		}

		x1 = x1 + difx;
		x2 = x2 + difx;
	}

	dfx = difx * sumy / 2;

	printf("deltax = %f\n", difx);
	printf("解 = %lf\n", dfx);

	return 0;
}
