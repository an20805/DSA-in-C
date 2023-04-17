#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void max_heapify(int arr[],int n, int i)
{
	if(i<n/2)
	{
		int max_ind;
		if(n%2==0 && i==n/2-1)
			max_ind=n-1;
		else
		{
			if(arr[2*i+1]>arr[2*i+2])
				max_ind=2*i+1;
			else 
				max_ind=2*i+2;
			}
		
		if(arr[i]<arr[max_ind])
		{
			int temp=arr[i];
			arr[i]=arr[max_ind];
			arr[max_ind]=temp;
			}
		max_heapify(arr,n,max_ind);
		}
	}


void build_maxheap(int arr[], int n)
{
	for(int i=n/2-1;i>=0;i--)
		max_heapify(arr,n,i);
	}
	
void heap_sort(int arr[],int n)
{
	build_maxheap(arr,n);
	
	for(int i=n-1;i>=1;i--)
	{
		int temp=arr[0];
		arr[0]=arr[i];
		arr[i]=temp;
		
		max_heapify(arr,i,0);
		}
	}
			


int main()
{
	srand(time(NULL));
	
	
		
		int n=20;
		int arr[n];
		for(int i=0;i<n;i++)
			arr[i]=rand()%1000;
		
		 heap_sort(arr,n);
		 for(int i=0;i<n;i++)
			printf("%d ",arr[i]);
		 
	 }
    
