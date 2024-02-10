#include<bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> arr1, vector<int> arr2){

    vector<int> res;
    sort(arr1.begin(), arr1.end());

    int n = arr2.size();

    for(int i = 0; i < n; ++i){

        //if(upper_bound(arr1.begin(), arr1.end(), arr2[i]) < arr1.end())
        res.push_back((upper_bound(arr1.begin(), arr1.end(), arr2[i]) - arr1.begin()));
    }

    return res;

}


int main(){
    vector<int> arr1 = {1, 4, 2, 4};
    vector<int> arr2 = {3, 5};

    for(auto el : solve(arr1, arr2))
    cout << el << endl;

    return 0;
}