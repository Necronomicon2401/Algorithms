#include <iostream>
#include <time.h>

using namespace std;

long consistentSearch(long a[], long n, long element)
{
	for (long i = 0; i < n; i++) {
		if (a[i] == element) {
			return i;
		}
	}
	return -1;
}

long binarySearch(long a[], long left, long right, long element)
{
	long mid;

	while (1)
	{
		mid = (left + right) / 2;

		if (element < a[mid]) {
			right = mid - 1;
		}
		else {
			if (element > a[mid]) {
				left = mid + 1;
			}
			else {
				return mid;
			}
			if (left > right) {
				return -1;
			}
		}
	}
}

long interpolationSearch(long a[], long left, long right, long element)
{

	while (a[left] <= element && a[right] >= element)
	{
		long long mid = left + ((element - a[left]) / (a[right] - a[left]) * (right - left));
		if (a[mid] < element) left = mid + 1;
		else if (a[mid] > element) right = mid - 1;
		else return mid;
	}
	if (a[left] == element) return left;
	else return -1;
}



int main()
{
	long* a = new long[1048576];
	for (long i = 0; i < 1048576; i++) {
		a[i] = i;
	}

	clock_t start = clock();
	cout << binarySearch(a, 0, 1048575, 1000000) << endl;
	clock_t end = clock();

	double seconds = (double)(end - start) / (CLOCKS_PER_SEC * 1000);
	printf("The time of binary search for array: %f milliseconds\n", seconds);

	start = clock();
	cout << interpolationSearch(a, 0, 1048575, 1000000) << endl;
	end = clock();

	seconds = (double)(end - start) / (CLOCKS_PER_SEC * 1000);
	printf("The time of interpolation search for array: %f milliseconds\n", seconds);

	start = clock();
	cout << consistentSearch(a, 1048575, 1000000) << endl;
	end = clock();

	seconds = (double)(end - start) / (CLOCKS_PER_SEC * 1000);
	printf("The time of consistent search for array: %f milliseconds\n", seconds);

	system("pause");
	return 0;
}