#include <bits/stdc++.h>
typedef long long ll;
#define l(i) 2 * i
#define r(i) 2 * i + 1
#define p(i) floor(i / 2)
#define fr(i, n) for (ll i = 0; i < (n); ++i)
#define rep(i, a, b) for (ll i = a; i <= b; ++i)
#define per(i, a, b) for (ll i = a; i >= b; i--)
using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void maxHelper(vector<ll> &v, ll i, ll heapSize)
{
    ll largest;

    ll l = l(i);
    ll r = r(i);

    if (l < heapSize && v.at(l) > v.at(i))
    {
        largest = l;
    }
    else
        largest = i;

    if (r < heapSize && v.at(r) > v.at(i))
    {
        largest = r;
    }

    if (largest != i)
    {
        swap(v.at(i), v.at(largest));
        maxHelper(v, largest, heapSize);
    }
}

void maxHeapify(vector<ll> &v, ll heapSize)
{
    ll n = v.size();

    fr(i, n){
        maxHelper(v, i, heapSize);
    }
}

void heapSort(vector<ll> &v, ll heapSize){

    maxHeapify(v, heapSize);

    per(i, v.size()-1, 1){
        swap(v.at(i), v.at(0)); 
        heapSize--;
        maxHeapify(v, heapSize);
    }

}

int main(void)
{
    vector<ll> v;
    v = {16, 4, 10, 14, 7, 9, 3, 2, 8, 1};

    heapSort(v, v.size());

    for(auto val : v)
    cout << val << " ";

    return 0;
}