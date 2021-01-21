//Program for finding finding inversions in n log n time
/*This program tries to find the inversion pair count for an array in n log n time order.. 
*/

#include<stdio.h>

/* The mergeSort function that calls the merge recursively on the left and right sub halves 
   Inversions are counted during the process of merging at each recursive call, we know that 
   merge sort runs in n log n time */

int mergeSort(signed int *arr, int first,int last)        
{                                                  
	int mid,inversions=0;
	if(first<last)
	{
		mid = (first+last)/2;
		inversions+=mergeSort(arr,first,mid);
        inversions+=mergeSort(arr,mid+1,last);
		inversions+=mergeAndCount(arr,first,mid,last);
	}
	
	return inversions;
} 

/* 
    The mergeAndCount method is the main method of the program that basically counts the inversions
    as the sublists are merged */
int mergeAndCount(signed int *arr, int first, int mid, int last)
{
	int inversions=0;
	int lars,rars,i,j,k;
	lars = mid-1;
	rars = last-mid;
	
	signed int l_arr[(mid-first)+1], r_arr[last-mid];    //sublists to store the partitions
	
	for(i=0;i<(mid-first)+1;i++)
	l_arr[i] = arr[first+i];
	
	for(j=0;j<last-mid;j++)
	r_arr[j] = arr[(mid+1)+j];
	
	i = 0; j = 0; k = first;
	
	while(i<(mid-first)+1 && j<last-mid)
	{
		if(l_arr[i]<=r_arr[j])
		{
			arr[k] = l_arr[i];
			i++;
		}
		else
		{
			arr[k] = r_arr[j];
			j++;
			inversions = inversions + (mid - i+1);
		}
		k++;
	}
	
	while(i<(mid-first)+1)
	{
		arr[k] = l_arr[i];
		i++;
		k++;
	}
	
	while(j<last-mid)
	{
		arr[k] = r_arr[j];
		j++;
		k++;
	}
	
	return inversions;
}

int main()
{
	long int n,i;

	scanf("%d",&n);
	
	signed int array[n];       //We take signed integer for negative integer values
	
	for(i=0;i<n;i++)
	scanf("%ud",&array[i]);
	
	
	printf("\n%d", mergeSort(array,0,n-1));
	
	return 0;
}
