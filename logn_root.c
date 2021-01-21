//Computing the kth root of a number n,
/*This program tries to compute the kth root of a number n in the log n time order. 
*/

#include<stdio.h>

//An important consideration here is that we dont use any math library functions()
/* The logic here is to use the binary search method to find kth root of the number, as in
   binary search we try to find the root only in a partial sequence of roots i.e either in the
   first half or the second half recursively. This algorthim hence takes log n time 
*/

int Find_kth_root(int num,int k,int first,int last)
{
	
	if(first<=last)                  
	{
		int mid = (first + last)/2;
		if(Findpower(mid,k)<=num && Findpower(mid+1,k)>num)    
		{
			return mid;
		}
		
		else if(Findpower(mid,k)>num)            //Search in the first half
		{
			return Find_kth_root(num,k,first,mid-1);
		}
		else
		{
			return Find_kth_root(num,k,mid+1,last);       //Search in second half
		}
	}
	
}

int Findpower(int num1,int num2)      //Power Function to find the power of num1^num2
{
	if(num2 == 0)
	return 1;
	
	int temp = Findpower(num1,num2/2);
	
	if(num2%2==0)
	return temp * temp;
	
	else
	return num1 * temp * temp;
}

int main()
{
	int num,k,testCases;
	
	scanf("%d",&testCases);
	
	while(testCases!=0)
	{
		scanf("%d %d",&num,&k);
		
		printf("%d\n",Find_kth_root(num,k,0,num));
		testCases--;
	}
	
	return 0;
}
