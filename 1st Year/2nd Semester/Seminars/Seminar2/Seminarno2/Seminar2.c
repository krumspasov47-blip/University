#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/* 1
int max(int a, int b)
{
	if (a > b)
	{
		return a;
	}
	else
	{
		return b;
	}
}
int min(int a, int b)
{
	if (a < b)
	{
		return a;
	}
	else
	{
		return b;
	}
}
*/
int main()
{

	/* 1 find the biggest and smallest of a list of numbers entered by a user, input 0 for the end of the list
	int num, biggest, smallest;
	while (1) {
		printf("Enter number::");
		scanf("%d", &num);
		if (num == 0)
		{
			break;
		}
		biggest = max(biggest, num);
		smallest = min(smallest, num);
	}
	*/

	/* 2 Program which reads hours and minutes, then outputs them in format hh:mm
	int h, m;
	printf("Enter hour:");
	scanf("%d", &h);
	printf("Enter minutes:");
	scanf("%d", &m);

	m += 15;

	if (m >= 60)
	{
		m -= 60;
		h += 1;
	}

	if (h >= 24)
	{
		h -= 24;
	}
	printf("Hour is: %d:%d", h ,m)
	*/

	/* 3 Check if 3 numbers are the same
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	if (a == b && b == c)
	{
		printf("Yes");
	}
	else
	{
		printf("No");
	}
	*/

	/* 4 Given a number of points, add bonus points, if number >= 100 add 5, if number > 100 add 20% of the number, 
	if number > 100 add 10% if the number, additionaly if number is even add 1 and if it ends on 5 add 2 points
	
	float points, bonus;
	printf("Points:");
	scanf("%f", &points);
	if (points <= 100)
	{
		bonus += 5;
	}
	else if (points > 100)
	{
		bonus += points * 0.20;
	}
	else if (points > 1000)
	{
		bonus += points * 0.10;
	}

	if (points % 2 == 0)
	{
		bonus += 1;
	}

	if (points % 10 == 5)
	{
		bonus += 2;
	}
	printf("%f", bonus);
	printf("%f", points+bonus);

	*/

	/* 5 Enter the second in which 3 runners have finished, print the result in format mm:ss 
	int a, b, c, total, minutes, seconds;
	scanf("%d%d%d", a, b, c);
	total = a + b + c;
	minutes = total / 60;
	seconds = total % 60;
	printf("Total time: %d:%02d", minutes, seconds);
	*/

	/* 6 Check if a point{x, y} is inside a rectangle{x1, y1} - {x2, y2}
	float x1, x2, y1, y2, x, y;
	if (x >= x1)
	{
		if (x <= x2)
		{
			if (y >= y1)
			{
				if (y <= y2)
				{
					printf("Inside");
					return;
				}
			}
		}
	}
	printf("Outside")
	*/

	/* 7 Calculate the cheapest transport, depending on the time of day and distance
	float n;
	char pday;
	float taxi, bus, train = 0;

	scanf("%d", &n);
	scanf("%c", &pday);

	if (pday == 'D')
	{
		taxi = 0.70 + 0.79 * n;
	}
	else if (pday == 'N')
	{
		taxi = 0.70 + 0.90 * n;
	}

	if (n >= 20)
	{
		bus = 0.09 * n;
	}

	if (n >= 100)
	{
		train = 0.06 * n;
	}

	if (train < bus && train < taxi)
	{
		if (train != 0)
		{
			printf("Train: %.2f", train);
		}
	}

	else if (bus < taxi && bus != 0)
	{
		printf("Bus: %.2f", bus);
	}
	else
	{
		printf("Taxi: %.2f", taxi);
	}
	*/

	/* 8 If a pool has volume and two tubes that fill it, in what condition will the pool be if the worker turns on the tubes
	on an empty pool and leaves for n hours
	float V, d1, d2, n;
	printf("Volume: "); scanf("%f", &V);
	printf("Debit 1st tube: "); scanf("%f", &d1);
	printf("Debit 2nd tube: "); scanf("%f", &d2);
	printf("Hours: "); scanf("%f", &n);

	float filling = (d1 + d2) * n;

	if (V <= filling)
	{
		printf("Pool is full");
	}
	else
	{
		printf("Pool is not full");
	}
	*/
	
	/* 9 How much wine is produced and whether thats enough, if it is the extra wine is given to the workers
	float x, y, z;
	int workers;
	scanf("%f", &x);
	scanf("%f", &y);
	scanf("%f", &z);
	scanf("%d", &workers);

	float grapes = x * y * 0.40;
	float wine = grapes / 2.5;

	if (wine >= z)
	{
		float leftover = wine - z;
		float per_worker = wine / workers;
	}
	else
	{
		printf("Wine is not enough");
	}
	*/

	/* 10
	int n;
	printf("n: ");
	scanf("%d", &n);

	int rows = 2 * (n - 2) + 1;
	int mid = rows / 2;
	int wing = n - 2;

	for (int r = 0; r < rows; r++) {
		if (r == mid) {
			for (int i = 0; i < wing; i++) printf(" ");
			printf(" @\n");
	}
	if (r != mid && r < mid) {
		if (r % 2 == 0) {
			for (int i = 0; i < wing; i++) printf("*");
			printf("\\ /");
			for (int i = 0; i < wing; i++) printf("*");
			printf("\n");
		}
	if (r % 2 != 0) {
				for (int i = 0; i < wing; i++) printf("-");
				printf("\\ /");
				for (int i = 0; i < wing; i++) printf("-");
				printf("\n");
		}
	}
		if (r != mid && r > mid) {
			if (r % 2 == 0) {
				for (int i = 0; i < wing; i++) printf("*");
				printf("/ \\");
				for (int i = 0; i < wing; i++) printf("*");
				printf("\n");
			}
			if (r % 2 != 0) {
				for (int i = 0; i < wing; i++) printf("-");
				printf("/ \\");
				for (int i = 0; i < wing; i++) printf("-");
				printf("\n");
			}
		}
	}
	*/
	return 0;
}
