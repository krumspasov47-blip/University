#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int is_prime(int n)
{
	if (n < 2) return 0;
	for (int i = 2; i * i <= n; i++)
		if (n % i == 0) return 0;
	return 1;
}

int main()
{
	int i, j, n, m;
	int min_r, max_r, min_v, max_v;
	int best_sum, bi, bj, s;
	int rows_ok, cols_ok;
	int has_neg, found;
	int num, pos, cap, sz;

	/* 1 Given a 2D NxM array filled with integers, check whether every row contains
	numbers sorted in ascending order and every column contains numbers in descending order

	int a[MAX][MAX];
	printf("Enter N M: "); scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			scanf("%d", &a[i][j]);

	rows_ok = 1; cols_ok = 1;

	for (i = 0; i < n && rows_ok; i++)
		for (j = 0; j < m - 1 && rows_ok; j++)
			if (a[i][j] >= a[i][j + 1]) rows_ok = 0;

	for (j = 0; j < m && cols_ok; j++)
		for (i = 0; i < n - 1 && cols_ok; i++)
			if (a[i][j] <= a[i + 1][j]) cols_ok = 0;

	printf("Rows ascending: %s\n", rows_ok ? "YES" : "NO");
	printf("Columns descending: %s\n", cols_ok ? "YES" : "NO");
	*/


	/* 2 Given a NxM matrix filled with integers, swap the rows containing
	the greatest and smallest element

	int a[MAX][MAX];
	printf("Enter N M: "); scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			scanf("%d", &a[i][j]);

	min_r = 0; max_r = 0;
	min_v = a[0][0]; max_v = a[0][0];

	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
		{
			if (a[i][j] < min_v) { min_v = a[i][j]; min_r = i; }
			if (a[i][j] > max_v) { max_v = a[i][j]; max_r = i; }
		}

	for (j = 0; j < m; j++)
	{
		int tmp = a[min_r][j];
		a[min_r][j] = a[max_r][j];
		a[max_r][j] = tmp;
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++) printf("%4d", a[i][j]);
		printf("\n");
	}
	*/


	/* 3 Naum is writing software for small children which has the following commands:
	1: add(x)      - adds element X to the existing ones
	2: delete(x)   - deletes all occurrences of element X
	3: smallest(x) - prints the smallest number from available ones
	Help Naum write his software knowing X is an integer. Use dynamic memory.

	cap = 10; sz = 0;
	int *arr = (int *)malloc(cap * sizeof(int));

	printf("Commands: 1=add(x)  2=delete(x)  3=smallest  0=quit\n");
	int cmd;
	while (scanf("%d", &cmd) == 1 && cmd != 0)
	{
		if (cmd == 1)
		{
			int x; scanf("%d", &x);
			if (sz == cap) { cap *= 2; arr = (int *)realloc(arr, cap * sizeof(int)); }
			int p = sz;
			while (p > 0 && arr[p - 1] > x) { arr[p] = arr[p - 1]; p--; }
			arr[p] = x;
			sz++;
		}
		else if (cmd == 2)
		{
			int x; scanf("%d", &x);
			int w = 0;
			for (i = 0; i < sz; i++)
				if (arr[i] != x) arr[w++] = arr[i];
			sz = w;
		}
		else if (cmd == 3)
		{
			if (sz == 0) printf("Empty set.\n");
			else         printf("Smallest: %d\n", arr[0]);
		}
	}
	free(arr);
	*/

	/* 4 Create a dynamic array of integers with n elements where n and the values are read
	from the keyboard. Delete the prime numbers from this array and create a second dynamic
	array where you store them. Print both arrays.

	printf("Enter N: "); scanf("%d", &n);
	int *all    = (int *)malloc(n * sizeof(int));
	int *primes = (int *)malloc(n * sizeof(int));
	int p_count = 0;

	for (i = 0; i < n; i++) scanf("%d", &all[i]);

	int w = 0;
	for (i = 0; i < n; i++)
	{
		if (is_prime(all[i])) primes[p_count++] = all[i];
		else                   all[w++] = all[i];
	}

	printf("Non-primes: ");
	for (i = 0; i < w; i++) printf("%d ", all[i]);
	printf("\nPrimes: ");
	for (i = 0; i < p_count; i++) printf("%d ", primes[i]);
	printf("\n");

	free(all); free(primes);
	*/

	/* 5 Write a program that creates a rectangular matrix of size n by m.
	The size and values are entered from the keyboard. Find the 3x3 submatrix
	with the minimum sum. Print the submatrix.

	int a[MAX][MAX];
	printf("Enter N M (>=3): "); scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			scanf("%d", &a[i][j]);

	best_sum = 2147483647; bi = 0; bj = 0;

	for (i = 0; i <= n - 3; i++)
	{
		for (j = 0; j <= m - 3; j++)
		{
			s = 0;
			for (int di = 0; di < 3; di++)
				for (int dj = 0; dj < 3; dj++)
					s += a[i + di][j + dj];
			if (s < best_sum) { best_sum = s; bi = i; bj = j; }
		}
	}

	printf("Min 3x3 submatrix (sum=%d) at [%d][%d]:\n", best_sum, bi, bj);
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++) printf("%4d", a[bi + i][bj + j]);
		printf("\n");
	}
	*/


	/* 6 Write a program that finds the sum of the elements for every column of a matrix
	with integers and prints it

	int a[MAX][MAX];
	printf("Enter N M: "); scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			scanf("%d", &a[i][j]);

	for (j = 0; j < m; j++)
	{
		s = 0;
		for (i = 0; i < n; i++) s += a[i][j];
		printf("col%d = %d\n", j, s);
	}
	*/

	/* 7 Given a matrix A[n][n], compose a program to transform it into a new matrix B[n][n]
	by the rule: if at least one of the elements in the last row of matrix A is negative,
	assign value 1 to the elements on the main diagonal of matrix B, otherwise assign value -1
	to the elements on the secondary diagonal of matrix B. Print matrices A and B in a table.

	int a[MAX][MAX], b[MAX][MAX];
	printf("Enter N: "); scanf("%d", &n);
	printf("Enter matrix A (%dx%d):\n", n, n);
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			scanf("%d", &a[i][j]);

	has_neg = 0;
	for (j = 0; j < n; j++)
		if (a[n - 1][j] < 0) { has_neg = 1; break; }

	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			b[i][j] = 0;

	if (has_neg)
		for (i = 0; i < n; i++) b[i][i] = 1;
	else
		for (i = 0; i < n; i++) b[i][n - 1 - i] = -1;

	printf("Matrix A:\n");
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++) printf("%4d", a[i][j]);
		printf("\n");
	}
	printf("Matrix B:\n");
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++) printf("%4d", b[i][j]);
		printf("\n");
	}
	*/


	return 0;
}
