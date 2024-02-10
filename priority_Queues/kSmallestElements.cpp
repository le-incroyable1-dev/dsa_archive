#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector<int> kSmallest(int arr[], int n, int k) {

    //min pq
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i < n; ++i)
    pq.push(arr[i]);

    vector<int> ans;
    while(k-- && pq.size() > 0){
        ans.push_back(pq.top());
        pq.pop();
    }

    return ans;
}

int main() {
    int size;
    cin >> size;

    int *input = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> input[i];
    }

    int k;
    cin >> k;

    vector<int> output = kSmallest(input, size, k);
    sort(output.begin(), output.end());

    for (int i = 0; i < output.size(); i++) {
        cout << output[i] << " ";
    }

    delete[] input;

    return 0;
}