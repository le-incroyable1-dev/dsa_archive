#include <iostream>
using namespace std;

void swap(int &n, int &m)
{
    int temp = m;
    m = n;
    n = temp;
}

int gcd(int n, int m) 
{

    if(n == 0)
    return m;
    else if(m==0)
    return n;

    if (n%m ==0) return m;
    if (n < m) swap(n, m);
    while (m > 0) {
        n = n%m;
        swap(n, m);
    }
    
    return n;
}
