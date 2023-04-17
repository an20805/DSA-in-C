#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void m_sort(int* arr, int n)
{
    if(n==1)
        return;
    else if(n==2)
    {
        if(arr[0]>arr[1])
        {
            int temp=arr[0];
            arr[0]=arr[1];
            arr[1]=temp;
        }
        return;
    }
    else
    {
        int lsize=n/2, rsize=n-n/2;
        int *left=(int *)malloc(lsize*sizeof(int));
        int *right=(int *)malloc(rsize*sizeof(int));

        for(int i=0;i<n;i++)
        {
            if(i<n/2)
                left[i]=arr[i];
            else
                right[i-n/2]=arr[i];
        }
        m_sort(left, lsize);
        m_sort(right, rsize);

        //________merge_________

        int l=0, r=0;

        for(int i=0;i<n;i++)
        {
            if(l<n/2 && r<n-n/2)
            {
                if(left[l]<right[r])
                {
                    arr[i]=left[l];
                    l++;
                }
                else
                {
                    arr[i]=right[r];
                    r++;
                }
            }
            else if(l>=n/2)
            {
                arr[i]=right[r];
                r++;
            }
            else if(r>=n-n/2)
            {
                arr[i]=left[l];
                l++;
            }
        }
        free(left);
        free(right);
        
    }
}

int main()
{
	srand(time(NULL));    
    int n=20;
    
	    int * arr;
	    arr=(int *)malloc(n*sizeof(int));
	    if(arr==NULL)
	    {
	    	printf("Out of Memory\n");
	    	exit(1);
	    	}
	    	
	    for(int i=0;i<n;i++)
		arr[i]=rand()%1000;

	    m_sort(arr,n);
	    for(int i=0;i<n;i++)
			printf("%d ",arr[i]);
	    free(arr); 
    
}
