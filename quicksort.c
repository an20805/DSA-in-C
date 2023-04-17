#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int arr[], int a, int b)
{
	int temp=arr[a];
	arr[a]=arr[b];
	arr[b]=temp;
	}

int partition(int arr[], int p, int r, int pivot)
{
	int i=p-1;
	for(int j=p;j<=r-1;j++)
	{
		if(arr[j]<=pivot)
		{
			i++;
			swap(arr,i,j); 		
			}
		}
	return i+1;
	}
		
void random_quick_sort(int arr[], int p, int r)
{
	if(p<r)
	{
		int pivot_ind=p+rand()%(r-p+1);
		int pivot=arr[pivot_ind];
		swap(arr,pivot_ind,r);
		int q=partition(arr,p,r,pivot);
		swap(arr,q,r);
		random_quick_sort(arr,p,q-1);
		random_quick_sort(arr,q+1,r);
		}
	}
		
int main()
{
	srand(time(NULL));
	int n=20;
	int arr[n];
	
		for(int i=0;i<n;i++)
			arr[i]=rand()%1000;
		
		random_quick_sort(arr,0,n-1);
		
		for(int i=0;i<n;i++)
			printf("%d ",arr[i]);
	}
