#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>



void swap(int *num1Ptr, int *num2Ptr);
void maxOfThere(int *num1Ptr, int *num2Ptr, int *num3Ptr);
double avgLowerDigit(int num, int digit, int *countPtr);
double calIntegral(double *c, double x, double *n);
int biggestOfTowNumArr(int *arr, int n);
int sumSmallerK(int *arr, int n, int key, int *firstPtr, int *seconedPtr);
int isPalindrom(int *arr, int n);
int isPalindrom_Rec(int *arr, int n);
double avgArray_rec(int *arr, int num);
int sortArray_rec(double *arr, int n);
int isSuperAscending(int *arr, int n);
int isSuperAscending_rec(int *arr, int n);
//int *input_array(int n);

/* ***1***

void main()
{
	int n1, n2 ,n3;
	n1 = 6;
	n2 = 9;
	n3 = 1;
	maxOfThere(&n1, &n2, &n3);
	printf("n1 = %d, n2 = %d\n", n1, n2);
	printf("num1 = %d, num2= %d, num3 = %d\n", n1, n2, n3);
}

void swap(int *num1Ptr, int *num2Ptr)
{
	int temp;
	temp = *num1Ptr;
	*num1Ptr = *num2Ptr;
	*num2Ptr = temp;
}

void maxOfThere(int *num1Ptr, int *num2Ptr, int *num3Ptr)
{
	if (*num1Ptr > *num2Ptr)
	{
		if (*num1Ptr > *num3Ptr)
		{
			if (*num2Ptr < *num3Ptr)
			{
				swap(num3Ptr, num2Ptr);
			}
		}
		else
		{
			swap(num3Ptr, num1Ptr);
			swap(num3Ptr, num2Ptr);
		}
	}
	
	if (*num2Ptr > *num3Ptr)
	{
		if (*num1Ptr > *num3Ptr)
		{
			swap(num2Ptr, num1Ptr);
		}

		else
		{
			swap(num2Ptr, num1Ptr);
			swap(num3Ptr, num2Ptr);
		}
	}
	else
	{
		swap(num3Ptr, num1Ptr);
	}
}*/

/* ***2***
void main()
{
	int n = -154;
	int digit = 7;
	int count;
	double result = avgLowerDigit(n, digit, &count);
	printf("%.2lf, %d", result, count);
}

double avgLowerDigit(int num, int digit, int *countPtr)
{
	double avg = 0.0;
	if (num == 0)
	{
		*countPtr = 1;
		return 0;
	}
	if (num < 0)
	{
		num = num * -1;
	}
	*countPtr = 0;
	while (num > 0)
	{
		if (num % 10 < digit)
		{
			avg += num % 10;
			(*countPtr)++;
		}
		num /= 10;
	}
	if ((*countPtr) != 0)
	{
		avg = avg / *countPtr;
		return avg;
	}
	else
	{
		return 0;
	}
}*/

/* ***3***
void main()
{
	double ans,x1, x2, x3;
	x1 = 4;
	x2 = 2;
	x3 = 3;
	ans = calIntegral(&x1, x2, &x3);
	printf("the answer is: %.2lf, val of c is: %.2lf, val of n is: %.2lf \n", ans, x1, x3);

}
double calIntegral(double *c, double x, double *n)
{
	*c = (*c) * (*n);
	(*n) = (*n) - 1;
	return *c * pow(x, (*n));
}*/

/* ***4***
void main()
{
	int arr[9] = { 3, 8, 12, 5, -7, 11, 9, 2, 13 };
	int ans = biggestOfTowNumArr(arr, 9);
	printf("the ans is: %d \n", ans);
}

int biggestOfTowNumArr(int *arr, int n)
{
	int max = arr[0] + arr[1];
	int i;
	for (i = 1; i < n - 1; i++)
	{
		if (arr[i] + arr[i + 1] > max)
		{
			max = arr[i] + arr[i + 1];
		}
	}
	return max;
}*/

/***5***
void main()
{
	int ans;
	int arr[5] = { 1,6,2,4,3 };
	int n = 5;
	int key = 3;
	int ptr1, ptr2;
	ans = sumSmallerK(arr, n, key,&ptr1,&ptr2);
	printf("The res is: %d, val 1: %d, val 2: %d\n", ans, ptr1, ptr2);
}

int sumSmallerK(int *arr, int n, int key, int *firstPtr, int *seconedPtr)
{
	int min1, min2, i;
	if (arr[0] < arr[1])
	{
		min1 = arr[0];
	}
	else
	{
		min1 = arr[1];
	}
	if (arr[0] < arr[1])
	{
		min2 = arr[1];
	}
	else
	{
		min2 = arr[0];
	}
	for (i = 2; i < n; i++)
	{
		if (arr[i] < min1)
		{
			min2 = min1;
			min1 = arr[i];
		}
		else if (arr[i] < min2)
		{
			min2 = arr[i];
		}
	}
	if (min1 + min2 < key)
	{
		*firstPtr = min1;
		*seconedPtr = min2;
		return 1;
	}
	else
	{
		*firstPtr = *seconedPtr = -1;
		return 0;
	}
}*/

/* ***7***
void main()
{
	int arr[4] = { 1, 3, 2, 3};
	int ans = isPalindrom_Rec(&arr, 4);
	printf("The res is: %d", ans);

}

int isPalindrom(int *arr, int n)
{
	int i;
	for (i = 0; i < n / 2; i++)
	{
		if (arr[i] != arr[n - 1 - i])
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}
}

int isPalindrom_Rec(int *arr, int n)
{
	if (n <= 1)
		return 1;
	if (arr[0] != arr[n - 1])
		return 0;
	else
	{
		return isPalindrom_Rec(arr + 1, n - 2);
	}
}*/

/* ***8***
void main()
{}
void printRegArr_Rec(int *arr, int n)
{
	if (n > 0)
	{
		print("%d ", arr[0]);
		printRegArr_Rec(arr + 1, n - 1);
	}
}
void printDownArr_Rec(int *arr, int n)
{
	if (n > 0)
	{
		print("%d ", arr[n - 1]);
		printDownArr_Rec(arr, n - 1);
	}
}*/

/* ***9***
void main()
{
	int arr[] = { 1, 3, 5, 2, 4 };
	int n = 5;
	printf("The avg of array is : %.2lf", avgArray_rec(arr, n));
}

double avgArray_rec(int *arr, int num)
{
	double avg = 0;
	if (num == 1)
		return 1;
	avg = avgArray_rec(arr, num - 1);
	avg = avg * (num - 1);
	return (avg + arr[num - 1]) / num;
}*/

/* ***10***
void main()
{
	double arr[] = { 1.7, 2.65, 2.7, 4.1 };
	int n = 4;
	if (sortArray_rec(arr, n) == 1)
		printf("The array is sort!\n");
	else
		printf("The array is not sort!\n");

}

int sortArray_rec(double *arr, int n)
{
	if (n == 1)
		return 1;
	if ((int)(arr[n - 1] >= (int)(arr[n - 2])) && ((arr[n - 1] - (int)(arr[n - 1])) <= (arr[n - 2] - (int)(arr[n - 2]))))
	{
		return sortArray_rec(arr, n - 1);
	}
	else
		return 0;
}*/

/* ***11***
void main()
{
	int arr[] = { 1,2,5,9,20,40 };
	int n = 6;
	if (isSuperAscending_rec(arr, n) == 1)
		printf("The array is super ascending ! \n");
	else
		printf("Not super ascending ! \n");
}

int isSuperAscending(int *arr, int n)
{
	int i;
	for  (i = 1; i < n; i++)
	{
		if (arr[i] <= arr[i - 1])
			return 0;
		arr[i] += arr[i - 1];
	}
	return 1;
}

int isSuperAscending_rec(int *arr, int n)
{
	int result;
	if (n == 1)
		return 1;
	result = isSuperAscending_rec(arr, n - 1);
	if (result && arr[n - 1] > arr[n - 2])
	{
		arr[n - 1] += arr[n - 2];
		return 1;
	}
	return 0;
}*/
