#include <iostream>
#include <string>

using namespace std;

string convertToTitle(int n) {

    string ans;
    
    while (n) 
    {
        ans = char ((n - 1) % 26 + 'A') + ans;
        n = (n - 1) / 26;
    }

    return ans;
}

/*
Note that taking n-1 ensures that A is taken as 1 when interconverting b/w the title and the number
which means
AB would be considered as 1*(26^1) + 2*(26^0)

Suppose I want to take A as 2. I will use n-2 instead
which means
AB would be considered as 2*(26^1) + 3*(26^0)

Suppose I want to take A as 0. I will use n instead
which means
AB would be considered as 0*(26^1) + 1*(26^0)
*/