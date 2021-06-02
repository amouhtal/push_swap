//C++ code to compare performance of sorting algorithms
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#define MAX_ELEMENT_IN_ARRAY 1000000001

int cmpfunc (const void * a, const void * b)
{
	// Compare function used by qsort
	return ( *(int*)a - *(int*)b );
}

int* generate_random_array(int n)
{
	srand(time(NULL));
	int *a = malloc(sizeof(int) * n), i;
	for(i = 0; i < n; ++i)
		a[i] = rand() % MAX_ELEMENT_IN_ARRAY;
	return a;
}

int* copy_array(int a[], int n)
{
	int *arr = malloc(sizeof(int) * n);
	int i;
	for(i = 0; i < n ;++i)
		arr[i] = a[i];
	return arr;
}

//Code for Insertion Sort
void insertion_sort_asc(int a[], int start, int end)
{
	int i;
	for(i = start + 1; i <= end ; ++i)
	{
		int key = a[i];
		int j = i - 1;
		while(j >= start && a[j] > key)
		{
			a[j + 1] = a[j];
			--j;
		}
		a[j + 1] = key;
	}
}

//Code for Merge Sort
void merge(int a[], int start, int end, int mid)
{
	int i = start, j = mid + 1, k = 0;
	int *aux = malloc(sizeof(int) * (end - start + 1));
	while(i <= mid && j <= end)
	{
		if(a[i] <= a[j])
			aux[k++] = a[i++];
		else
			aux[k++] = a[j++];
	}
	while(i <= mid)
		aux[k++] = a[i++];
	while(j <= end)
		aux[k++] = a[j++];
	j = 0;
	for(i = start;i <= end;++i)
		a[i] = aux[j++];
	free(aux);
}

void _merge_sort(int a[],int start,int end)
{
	if(start < end)
	{
		int mid = start + (end - start) / 2;
		_merge_sort(a,start,mid);
		_merge_sort(a,mid + 1,end);
		merge(a,start,end,mid);
	}
}
void merge_sort(int a[],int n)
{
	return _merge_sort(a,0,n - 1);
}


void insertion_and_merge_sort_combine(int a[], int start, int end, int k)
{
	// Performs insertion sort if size of array is less than or equal to k
	// Otherwise, uses mergesort
	if(start < end)
	{
		int size = end - start + 1;
		
		if(size <= k)
		{
			//printf("Performed insertion sort- start = %d and end = %d\n", start, end);
			return insertion_sort_asc(a,start,end);
		}
		int mid = start + (end - start) / 2;
		insertion_and_merge_sort_combine(a,start,mid,k);
		insertion_and_merge_sort_combine(a,mid + 1,end,k);
		merge(a,start,end,mid);
	}
}

void test_sorting_runtimes(int size,int num_of_times)
{
	// Measuring the runtime of the sorting algorithms
	int number_of_times = num_of_times;
	int t = number_of_times;
	int n = size;
	double insertion_sort_time = 0, merge_sort_time = 0;
	double merge_sort_and_insertion_sort_mix_time = 0, qsort_time = 0;
	while(t--)
	{
		clock_t start, end;
		
		int *a = generate_random_array(n);
		int *b = copy_array(a,n);
		start = clock();
		insertion_sort_asc(b,0,n-1);
		end = clock();
		insertion_sort_time += ((double) (end - start)) / CLOCKS_PER_SEC;
		free(b);
		int *c = copy_array(a,n);
		start = clock();
		merge_sort(c,n);
		end = clock();
		merge_sort_time += ((double) (end - start)) / CLOCKS_PER_SEC;
		free(c);
		int *d = copy_array(a,n);
		start = clock();
		insertion_and_merge_sort_combine(d,0,n-1,40);
		end = clock();
		merge_sort_and_insertion_sort_mix_time+=((double) (end - start))/CLOCKS_PER_SEC;
		free(d);
		start = clock();
		qsort(a,n,sizeof(int),cmpfunc);
		end = clock();
		qsort_time += ((double) (end - start)) / CLOCKS_PER_SEC;
		free(a);
	}
	
	insertion_sort_time /= number_of_times;
	merge_sort_time /= number_of_times;
	merge_sort_and_insertion_sort_mix_time /= number_of_times;
	qsort_time /= number_of_times;
	printf("\nTime taken to sort:\n"
			"%-35s %f\n"
			"%-35s %f\n"
			"%-35s %f\n"
			"%-35s %f\n\n",
			"(i)Insertion sort: ",
			insertion_sort_time,
			"(ii)Merge sort: ",
			merge_sort_time,
			"(iii)Insertion-mergesort-hybrid: ",
			merge_sort_and_insertion_sort_mix_time,
			"(iv)Qsort library function: ",
			qsort_time);
}

int main(int argc, char const *argv[])
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int size, num_of_times;
		scanf("%d %d", &size, &num_of_times);
		test_sorting_runtimes(size,num_of_times);
	}
	return 0;
}
