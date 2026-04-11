#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX 100

int main()
{
	int i, j, n, k, x, m, c;
	int num, pos, size;
	int found, count;
	int best_start, best_len, cur_len;
	int min_val, max_val, min_idx, max_idx;
	int sum, target, rank;
	int b_start, b_len, b_dir, c_start, c_len, c_dir, dir;

	/*1 Find the longest plateau (run of equal elements) in a sorted ascending array,
	print its starting index and length*/

	int a[MAX];
	printf("Enter N: "); scanf("%d", &n);
	for (i = 0; i < n; i++) scanf("%d", &a[i]);

	best_start = 0;
	best_len = 1;
	cur_len = 1;

	for (i = 1; i < n; i++)
	{
		if (a[i] == a[i - 1])
		{
			cur_len++;
			if (cur_len > best_len)
			{
				best_len = cur_len;
				best_start = i - cur_len + 1;
			}
		}
		else
		{
			cur_len = 1;
		}
	}
	printf("Longest plateau: start=%d, length=%d\n", best_start, best_len);
	

	/* 2 Check zigzag relation: a0 < a1 > a2 < a3 > ...

	int a[MAX];
	printf("Enter N: "); scanf("%d", &n);
	for (i = 0; i < n; i++) scanf("%d", &a[i]);

	int ok = 1;
	for (i = 0; i < n - 1 && ok; i++)
	{
		if (i % 2 == 0 && !(a[i] < a[i + 1])) ok = 0;
		if (i % 2 == 1 && !(a[i] > a[i + 1])) ok = 0;
	}
	if (ok)
		printf("YES - zigzag holds\n");
	else
		printf("NO - zigzag does not hold\n");
	*/

	/* 3 Receive an array of N elements and reverse the order of the elements, print the new array

	int a[MAX];
	printf("Enter N: "); scanf("%d", &n);
	for (i = 0; i < n; i++) scanf("%d", &a[i]);

	for (i = 0; i < n / 2; i++)
	{
		int tmp = a[i];
		a[i] = a[n - 1 - i];
		a[n - 1 - i] = tmp;
	}

	printf("Reversed: ");
	for (i = 0; i < n; i++) printf("%d ", a[i]);
	printf("\n");
	*/

	/* 4 Receive an array of N integers then a whole number K, shift all elements of the array
	by K positions using the rule for wrapping (element at last position goes to first)

	int a[MAX], tmp[MAX];
	printf("Enter N: "); scanf("%d", &n);
	for (i = 0; i < n; i++) scanf("%d", &a[i]);
	printf("Enter K: "); scanf("%d", &k);
	k %= n;

	for (i = 0; i < n; i++) tmp[i] = a[(i + k) % n];

	printf("After rotating left by %d: ", k);
	for (i = 0; i < n; i++) printf("%d ", tmp[i]);
	printf("\n");
	*/

	/* 5 Given a sequence of N integers, find the K-th largest element.

	int a[MAX];
	printf("Enter N: "); scanf("%d", &n);
	for (i = 0; i < n; i++) scanf("%d", &a[i]);
	printf("Enter K: "); scanf("%d", &k);

	found = 0;
	for (i = 0; i < n && !found; i++)
	{
		rank = 1;
		for (j = 0; j < n; j++)
			if (a[j] > a[i]) rank++;
		if (rank == k)
		{
			printf("The %d-th largest element is %d\n", k, a[i]);
			found = 1;
		}
	}
	if (!found) printf("Not found (check K).\n");
	*/

	/* 6 For a given sequence of numbers find and print the longest increasing
	or decreasing subsequence

	int a[MAX];
	printf("Enter N: "); scanf("%d", &n);
	for (i = 0; i < n; i++) scanf("%d", &a[i]);

	b_start = 0; b_len = 1; b_dir = 0;
	c_start = 0; c_len = 1; c_dir = 0;

	for (i = 1; i < n; i++)
	{
		dir = (a[i] > a[i - 1]) ? 1 : (a[i] < a[i - 1]) ? -1 : 0;
		if (dir != 0 && dir == c_dir)
		{
			c_len++;
		}
		else
		{
			c_start = i - 1;
			c_len = 2;
			c_dir = dir;
		}
		if (dir != 0 && c_len > b_len)
		{
			b_len = c_len;
			b_start = c_start;
			b_dir = c_dir;
		}
	}

	if (b_dir >= 0)
		printf("Longest increasing subsequence (len=%d): ", b_len);
	else
		printf("Longest decreasing subsequence (len=%d): ", b_len);

	for (i = b_start; i < b_start + b_len; i++) printf("%d ", a[i]);
	printf("\n");
	*/

	/* 7 Write a program that finds a sequence of numbers in an array whose sum equals
	a number entered by the user.


	int a[MAX];
	printf("Enter N: "); scanf("%d", &n);
	for (i = 0; i < n; i++) scanf("%d", &a[i]);
	printf("Enter target sum: "); scanf("%d", &target);

	found = 0;
	for (i = 0; i < n && !found; i++)
	{
		sum = 0;
		for (j = i; j < n && !found; j++)
		{
			sum += a[j];
			if (sum == target)
			{
				printf("Found: ");
				for (k = i; k <= j; k++) printf("%d ", a[k]);
				printf("\n");
				found = 1;
			}
		}
	}
	if (!found) printf("No such subsequence found.\n");
	*/

	/* 8 The user fills 10 numbers in an array of 20 elements, then enters numbers where
	each entered number specifies the index where that number should be inserted. Stops at input 0 or when array is full.


	int a[20];
	size = 10;
	printf("Enter 10 initial numbers: ");
	for (i = 0; i < 10; i++) scanf("%d", &a[i]);

	while (size < 20)
	{
		printf("Enter number and position (0 to stop): ");
		scanf("%d", &num);
		if (num == 0) break;
		scanf("%d", &pos);
		for (i = size; i > pos; i--) a[i] = a[i - 1];
		a[pos] = num;
		size++;
	}

	printf("Result: ");
	for (i = 0; i < size; i++) printf("%d ", a[i]);
	printf("\n");
	*/

	/* 9 Write a program that finds the maximum row of consecutive equal elements in an
	array and prints them


	int a[MAX];
	printf("Enter N: "); scanf("%d", &n);
	for (i = 0; i < n; i++) scanf("%d", &a[i]);

	best_start = 0;
	best_len = 1;
	cur_len = 1;

	for (i = 1; i < n; i++)
	{
		if (a[i] == a[i - 1])
		{
			cur_len++;
			if (cur_len > best_len)
			{
				best_len = cur_len;
				best_start = i - cur_len + 1;
			}
		}
		else
		{
			cur_len = 1;
		}
	}

	printf("Longest equal run: ");
	for (i = best_start; i < best_start + best_len; i++) printf("%d ", a[i]);
	printf("\n");
	*/

	/* 10 Given a sequence of integers a0, a1, a2, ... an-1 (n>1) and a whole number x,
	write a program that finds how many times x appears in the sequence.
	The count and values are entered from the keyboard.

	int a[MAX];
	printf("Enter N: "); scanf("%d", &n);
	for (i = 0; i < n; i++) scanf("%d", &a[i]);
	printf("Enter X: "); scanf("%d", &x);

	count = 0;
	for (i = 0; i < n; i++)
		if (a[i] == x) count++;

	printf("X=%d appears %d time(s).\n", x, count);
	*/

	/* 11 Write a program that in an array of up to 100 elements finds the smallest
	and largest element and their indices. The size and values are entered from the keyboard.

	int a[MAX];
	printf("Enter N (<=100): "); scanf("%d", &n);
	for (i = 0; i < n; i++) scanf("%d", &a[i]);

	min_val = a[0]; max_val = a[0];
	min_idx = 0;    max_idx = 0;

	for (i = 1; i < n; i++)
	{
		if (a[i] < min_val) { min_val = a[i]; min_idx = i; }
		if (a[i] > max_val) { max_val = a[i]; max_idx = i; }
	}

	printf("Min = %d at index %d\n", min_val, min_idx);
	printf("Max = %d at index %d\n", max_val, max_idx);
	*/

	/* 12 Write a program that receives two numbers (multiplier and count). It should
	create an array of the given count that contains only positive integers that are
	multiples of the given multiplier, sorted in ascending order starting from the multiplier.


	int a[MAX];
	printf("Enter multiplier and count: "); scanf("%d %d", &m, &c);
	for (i = 0; i < c; i++) a[i] = m * (i + 1);

	printf("Array: ");
	for (i = 0; i < c; i++) printf("%d ", a[i]);
	printf("\n");
	*/

	return 0;
}
