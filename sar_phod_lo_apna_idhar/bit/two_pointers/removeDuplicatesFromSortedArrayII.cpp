#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define fi first
#define sec second
typedef long long ll;
typedef long double ld;
#define pii pair<ll, ll>
#define vi vector<ll>
#define vvi vector<vi>
#define vpi vector<pii>
#define vvpi vector<vpi>
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0)
#define test(t) \
    ll t;       \
    cin >> t;   \
    while (t--)
#define mem(a, b) memset(a, b, sizeof(a))
#define inn freopen("input.txt", "r", stdin)
#define outt freopen("output.txt", "w", stdout)
#define all(arr) arr.begin(), arr.end()
#define fr(i, n) for (ll i = 0; i < (n); ++i)
#define rep(i, a, b) for (ll i = a; i <= b; ++i)
#define per(i, a, b) for (ll i = a; i >= b; i--)
#define remin(a, b) (a = min((a), (b)))
#define remax(a, b) (a = max((a), (b)))
#define itr(type) type::iterator itr
long long powerof2[] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288, 1048576, 2097152, 4194304, 8388608, 16777216, 33554432, 67108864, 134217728, 268435456, 536870912, 1073741824, 2147483648, 4294967296};


//best solution
int removeDuplicates3(vector<int> &A) {

    int n1 = A.size();

    if(n1<3) 
    return n1;
        
    int end = 1;
    int i;

    int k = 2; // when you want upto k dups of each element at max
    int comp;

    for(i=k; i<n1; i++) {

        comp = end-1;

        if(A[i]!=A[comp]) 
            A[++end] = A[i];
    
    }

    return end+1;
}



int removeDuplicates(vector<int> &A)
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}

int removeDuplicates2(vector<int> &A)
{
    A.push_back(A.back() + 1);
    int p1 = 0, p2 = 1;
    int count = 1;
    while (p2 < A.size())
    {
        if (A[p2] != A[p1])
        {
            count++;
            p1 = p2;
            p2++;
        }
        else
        {
            while (A[p2] == A[p1])
                p2++;
            if ((p2 - p1) >= 2)
            {
                p1 += 2;
                A.erase(A.begin() + p1, A.begin() + p2);
                count++;
            }
            p1--;
            p2 = p1 + 1;
        }
    }
    A.pop_back();
    return --count;
}


/*

*/

/*
You need to modify the original array itself. So you need to keep
current like pointer which will point to the index of the array where you can store the next value.

How can you define another pointer to keep track of next value?



*/

void sol()
{
}

int main(void)
{

    fast;

    test(t)
    {
        sol();
    }
}