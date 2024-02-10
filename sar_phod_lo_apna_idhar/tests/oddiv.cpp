#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<long>sod(100001,1);
    sod[0] = 0;
    for(int i=3; i<sod.size(); i+=2){
        int j = i;
        while(j < sod.size()){
            sod[j] += i;
            j += i;
        }
    }
    for(int i=1; i<sod.size(); i++){
        sod[i] += sod[i-1];
    }
    int T;
    cin>>T;
    while(T--){
        int l, r;
        cin>>l>>r;
        cout<<sod[r] - sod[l-1]<<"\n";
    }
    
	return 0;
}
