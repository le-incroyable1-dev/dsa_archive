#include <iostream>
#include <vector>

using namespace std;

bool isPrime(int n)
{
    // Corner case
    if (n <= 1)
        return false;
  
    // Check from 2 to n-1
    for (int i = 2; i < n; i++)
        if (n % i == 0)
            return false;
  
    return true;
}

vector<int> primesum(int A) {

    int n1;
    int n2;

    vector<int> res;

    for(int i = A-2; i >= 2; i--)
    {
        if(isPrime(i))
        {
            if(isPrime(A-i))
            {
                n1 = A-i;
                n2 = i;
                break;
            }
        }
    }

    res.push_back(n1);
    res.push_back(n2);
    
    return res;
}
