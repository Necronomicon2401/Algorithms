#include <iostream>
#include <time.h> 
#include <cstdlib> 

using namespace std;


void bubbleSort(int *a, int n) {
	for (int i = 0; i < n; i++) {
		int f = 0;
		for (int j = 0; j < n - 1 - i; j++) {
			if (a[j] > a[j + 1]) {
				f = a[j+1];
				a[j + 1] = a[j];
				a[j] = f;
			}
		}
	}
}


void insertionSort(int* a, int n) {
	for (int j = 0; j < n; j++) {
		int key = a[j];
		int i = j - 1;
		while (i >= 0 and a[i] > key){
			a[i + 1] = a[i];
			i = i - 1;
			}
		a[i + 1] = key;
	}
}

void quickSort(int* mas, int size) {
	int i = 0;
	int j = size - 1;

	int mid = mas[size / 2];

	do {
		while (mas[i] < mid) {
			i++;
		}
		while (mas[j] > mid) {
			j--;
		}

		if (i <= j) {
			int tmp = mas[i];
			mas[i] = mas[j];
			mas[j] = tmp;

			i++;
			j--;
		}
	} while (i <= j);


	if (j > 0) {
		quickSort(mas, j + 1);
	}
	if (i < size) {
		quickSort(&mas[i], size - i);
	}
}

void mergeSort(int* a, int n)
{
	int mid = n / 2; 
	if (n % 2 == 1)
		mid++;
	int h = 1; 

	int* c = (int*)malloc(n * sizeof(int));
	int step;
	while (h < n)
	{
		step = h;
		int i = 0;   
		int j = mid; 
		int k = 0;   
		while (step <= mid)
		{
			while ((i < step) && (j < n) && (j < (mid + step)))
			{ 
				if (a[i] < a[j])
				{
					c[k] = a[i];
					i++; k++;
				}
				else {
					c[k] = a[j];
					j++; k++;
				}
			}
			while (i < step)
			{
				c[k] = a[i];
				i++; k++;
			}
			while ((j < (mid + step)) && (j < n))
			{
				c[k] = a[j];
				j++; k++;
			}
			step = step + h; 
		}
		h = h * 2;
		for (i = 0; i < n; i++)
			a[i] = c[i];
	}
}

 void countingSort(int* array, int n, int k) {
	 int *c = new int[k];
	 for (int i = 0; i < k; i++) {
		 c[i] = 0;
	 }
	 for (int i = 0; i < n; i++) {
		 c[array[i]] = c[array[i]] + 1;
	 }

	 int b = 0;
	 for (int i = 0; i < k; i++) {
		 for (int j = 0; j < c[i]; j++) {
			 array[b] = i;
			 b = b + 1;
		 }
	 }
 }

 void gibridSort(int* mas, int size) {
	 int i = 0;
	 int j = size - 1;

	 int mid = mas[size / 2];

	 do {
		 while (mas[i] < mid) {
			 i++;
		 }
		 while (mas[j] > mid) {
			 j--;
		 }

		 if (i <= j) {
			 int tmp = mas[i];
			 mas[i] = mas[j];
			 mas[j] = tmp;

			 i++;
			 j--;
		 }
	 } while (i <= j);


	 if (j > 0) {
		 insertionSort(mas, j + 1);
	 }
	 if (i < size) {
		 insertionSort(&mas[i], size - i);
	 }
 }

int main() {
	int* test1 = new int[256];
	for (int i = 0; i < 256; i++) {
		test1[i] = rand();
	}

	int* test2 = new int[131072];
	for (int i = 0; i < 131072; i++) {
		test2[i] = rand();
	}

	int* test3 = new int[131072];
	for (int i = 0; i < 131072; i++) {
		test3[i] = rand() % (i+1);
	}

	int* test4 = new int[131072];
	for (int i = 0; i < 131072; i++) {
		test4[i] = rand() % 100;
	}

	//insertion
	clock_t start = clock();
	insertionSort(test1, 256);
	clock_t end = clock();
	
	double seconds = (double)(end - start) / CLOCKS_PER_SEC;
	printf("The time of insertion sort for 1 array: %f seconds\n", seconds);

	start = clock();
	insertionSort(test2, 131072);
	end = clock();

	seconds = (double)(end - start) / CLOCKS_PER_SEC;
	printf("The time of insertion sort for 2 array: %f seconds\n", seconds);

	start = clock();
	insertionSort(test3, 131072);
	end = clock();

	seconds = (double)(end - start) / CLOCKS_PER_SEC;
	printf("The time of insertion sort for 3 array: %f seconds\n", seconds);

	start = clock();
	insertionSort(test4, 131072);
	end = clock();

	seconds = (double)(end - start) / CLOCKS_PER_SEC;
	printf("The time of insertion sort for 4 array: %f seconds\n", seconds);
	//

	//quick
	start = clock();
	quickSort(test1, 256);
	end = clock();

	seconds = (double)(end - start) / CLOCKS_PER_SEC;
	printf("The time of quick sort for 1 array: %f seconds\n", seconds);

	start = clock();
	quickSort(test2, 131072);
	end = clock();

	seconds = (double)(end - start) / CLOCKS_PER_SEC;
	printf("The time of quick sort for 2 array: %f seconds\n", seconds);

	start = clock();
	quickSort(test3, 131072);
	end = clock();

	seconds = (double)(end - start) / CLOCKS_PER_SEC;
	printf("The time of quick sort for 3 array: %f seconds\n", seconds);

	start = clock();
	quickSort(test4, 131072);
	end = clock();

	seconds = (double)(end - start) / CLOCKS_PER_SEC;
	printf("The time of quick sort for 4 array: %f seconds\n", seconds);
	//

	//counting
	start = clock();
	countingSort(test1, 256, RAND_MAX + 2);
	end = clock();

	seconds = (double)(end - start) / CLOCKS_PER_SEC;
	printf("The time of counting sort for 1 array: %f seconds\n", seconds);

	start = clock();
	countingSort(test2, 131072, RAND_MAX + 2);
	end = clock();

	seconds = (double)(end - start) / CLOCKS_PER_SEC;
	printf("The time of counting sort for 2 array: %f seconds\n", seconds);

	start = clock();
	countingSort(test3, 131072, 131074);
	end = clock();

	seconds = (double)(end - start) / CLOCKS_PER_SEC;
	printf("The time of counting sort for 3 array: %f seconds\n", seconds);

	start = clock();
	countingSort(test4, 131072, 102);
	end = clock();

	seconds = (double)(end - start) / CLOCKS_PER_SEC;
	printf("The time of counting sort for 4 array: %f seconds\n", seconds);
	//

	//merge
	start = clock();
	mergeSort(test1, 256);
	end = clock();

	seconds = (double)(end - start) / CLOCKS_PER_SEC;
	printf("The time of merge sort for 1 array: %f seconds\n", seconds);

	start = clock();
	mergeSort(test2, 131072);
	end = clock();

	seconds = (double)(end - start) / CLOCKS_PER_SEC;
	printf("The time of merge sort for 2 array: %f seconds\n", seconds);

	start = clock();
	mergeSort(test3, 131072);
	end = clock();

	seconds = (double)(end - start) / CLOCKS_PER_SEC;
	printf("The time of merge sort for 3 array: %f seconds\n", seconds);

	start = clock();
	mergeSort(test4, 131072);
	end = clock();

	seconds = (double)(end - start) / CLOCKS_PER_SEC;
	printf("The time of merge sort for 4 array: %f seconds\n", seconds);
	//

	//bubble
	start = clock();
	bubbleSort(test1, 256);
	end = clock();

	seconds = (double)(end - start) / CLOCKS_PER_SEC;
	printf("The time of bubble sort for 1 array: %f seconds\n", seconds);

	start = clock();
	bubbleSort(test2, 131072);
	end = clock();

	seconds = (double)(end - start) / CLOCKS_PER_SEC;
	printf("The time of bubble sort for 2 array: %f seconds\n", seconds);

	start = clock();
	bubbleSort(test3, 131072);
	end = clock();

	seconds = (double)(end - start) / CLOCKS_PER_SEC;
	printf("The time of bubble sort for 3 array: %f seconds\n", seconds);

	start = clock();
	bubbleSort(test4, 131072);
	end = clock();

	seconds = (double)(end - start) / CLOCKS_PER_SEC;
	printf("The time of bubble sort for 4 array: %f seconds\n", seconds);
	//

	//gibrid
	start = clock();
	gibridSort(test1, 256);
	end = clock();

	seconds = (double)(end - start) / CLOCKS_PER_SEC;
	printf("The time of gibrid sort for 1 array: %f seconds\n", seconds);

	start = clock();
	gibridSort(test2, 131072);
	end = clock();

	seconds = (double)(end - start) / CLOCKS_PER_SEC;
	printf("The time of gibrid sort for 2 array: %f seconds\n", seconds);

	start = clock();
	gibridSort(test3, 131072);
	end = clock();

	seconds = (double)(end - start) / CLOCKS_PER_SEC;
	printf("The time of gibrid sort for 3 array: %f seconds\n", seconds);

	start = clock();
	gibridSort(test4, 131072);
	end = clock();

	seconds = (double)(end - start) / CLOCKS_PER_SEC;
	printf("The time of gibrid sort for 4 array: %f seconds\n", seconds);
	//

	system("pause");
}