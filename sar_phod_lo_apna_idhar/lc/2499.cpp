#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
public:
    long long minimumTotalCost(vector<int>& nums1, vector<int>& nums2) {

        int n = nums1.size();
        map<int, set<int>> m;

        ll cost = 0;

        for(int i = 0; i < n; ++i){
            if(nums1[i] == nums2[i]){
                m[nums1[i]].insert(i);
            }
        }

        set<int> left;
        while(1){
            if(m.size() == 0) break;

            map<int, set<int>>::iterator itr = m.begin();
            map<int, set<int>>::iterator itrn = m.begin(); ++itrn;

            if(itrn == m.end()){
                left = itr->second;
                break;
            }

            ll i1 = *itr->second.begin();
            ll i2 = *itrn->second.begin();
            int v1 = nums1[i1];
            int v2 = nums2[i2];
            nums1[i1] = v2; nums2[i2] = v1;

            cost += i1; cost += i2;
            
            itr->second.erase((int)i1);
            if(itr->second.size() == 0) m.erase(itr);

            itrn->second.erase((int)i2);
            if(itrn->second.size() == 0) m.erase(itrn);
        }

        int sz = left.size();
        int num;
        if(sz) num = nums1[*left.begin()];

        for(int i = 0; i < n && sz > 0; ++i){
            if(nums1[i] != num && nums2[i] != num) sz--, cost += (ll)i;
        }

        if(sz) return -1LL;
        while(!left.empty()) { 
            cost += (ll)(*left.begin()), left.erase(*left.begin());
        }

        return cost;

    }
};

int main(){
    Solution sol;
    vector<int> v1 = {1,2,3,4,5};
    vector<int> v2 = {1,2,3,4,5};

    cout << sol.minimumTotalCost(v1, v2) << "\n";
    return 0;
}