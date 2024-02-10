#include <bits/stdc++.h>
using namespace std;

/*
Given an integer N, find and return the count of minimum numbers required
to represent N as a sum of squares.

That is, if N is 4, then we can represent it as : {1^2 + 1^2 + 1^2 + 1^2} 
and {2^2}. The output will be 1, as 1 is the minimum count of numbers required 
to represent N as sum of squares.
*/

int minCount(int n)
{
    if(n == 0)
        return 0;
    else
    {
        int *arr = new int[n+1];
        
        arr[0] = 0;
            
        int res;
        int cur;
        
        for(int i = 1; i < n+1; i++)
        {
            res = INT_MAX;
            
            for(int j = 1; j <= sqrt(i); j++)
        	{
            	cur = 1 + arr[i-(j*j)] ;
            	if(cur <= res)
                	res = cur;
        	}
            
            arr[i] = res;
        }
        
        return arr[n];
    }
}

int main()
{
	int n;
	cin >> n;
	cout << minCount(n);
}