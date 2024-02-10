#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

// FASTEST
#define mod 1000003;

int fact(int n)
{
    if (n == 0)
        return 1;
    else
        return (n * fact(n - 1)) % mod;
}

int findRank(string A)
{

    string s = A;
    // cin>>s;
    int ans = 0;
    int n = s.length();
    for (int i = 0; i < n - 1; i++)
    {
        int c = 0;
        for (int j = i + 1; j < n; j++)
        {
            if (s[j] < s[i])
                c++;
        }
        ans += ((c * fact(n - i - 1))) % mod;
        // cout << c <<" "<<ans<< endl;
    }
    return (ans + 1) % mod;
    // cout << ans+1 ;
}

// EDITORIAL
int findRank(string s)
{

    int l = s.length();
    long ans = 1;
    long rank[130] = {0}, fact[130] = {0};
    fact[0] = fact[1] = 1;
    for (int i = 2; i <= 120; i++)
        fact[i] = fact[i - 1] * i, fact[i] %= mod;
    string str = s;
    sort(begin(str), end(str));
    for (int i = 0; i < l; i++)
        rank[str[i] - 'A'] = i;
    for (int i = 0; i < l; i++)
    {
        ans += (rank[s[i] - 'A']) * fact[l - 1 - i];
        ans %= mod;
        int j = s[i] - 'A' + 1;
        for (; j < 126; j++)
            rank[j]--;
    }
    return (int)(ans) % mod;
}
