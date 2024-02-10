#include <bits/stdc++.h>
using namespace std;





int main(){

    int n, m; cin >> n >> m;
    vector<int> arr(n, -1);
    unordered_map<int, int> mp;
    int ele;

    for(int i = 0; i < n; ++i){
        cin >> ele;
        arr[i] = ele;
        int val = ele%m;
        mp[val]++;
    }

    int q; cin >> q;

    for(int i = 0; i < q; ++i){
        int opt; cin >> opt;

        if(opt == 1){
            int i, a; cin >> i >> a;
            int cval = arr[i-1]%m;
            mp[cval]--;
            int nval = a%m;
            mp[nval]++;

            arr[i-1] = a;
        }
        else{

            int x; cin >> x;
            cout << mp[x%m] << "\n";
        }
    }

    return 0;
}