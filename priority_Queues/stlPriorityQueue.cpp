#include <iostream>
#include <queue>
using namespace std;

//define a custom comparison object that can be passed to the pq

template<typename _Tp>
    struct myComparisonObject
    {
      bool operator()(const _Tp& __x, const _Tp& __y) const
      { return __x/2 > __y; }
    };


int main(){

    //max pq
    priority_queue<int> pq;

    //min pq
    priority_queue<int, vector<int>, greater<int>> pq2;
    //swap when parent is greater than child

    //custom pq
    priority_queue<int, vector<int>, myComparisonObject<int>> pq3;
    //swap when parent/2 > child

    cout << pq.top();
    cout << pq.size();

    pq.pop();
    pq.push(1);

    while(!pq.empty())
    pq.pop();
    
    return 0;
}