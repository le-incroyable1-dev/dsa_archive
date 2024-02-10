#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution {
public:

    ll helper(ll sum, vector<int> &nums, int k, int n, int s){

        ll res = 0;
        if(sum > s-k)
        return 0;

        if(n == 0){
            return (sum >= k && sum <= s-k);
        }

        

        (res += helper(sum + nums[n-1], nums, k, n-1, s))%=mod;
        (res += helper(sum, nums, k, n-1, s))%=mod;

        res%=mod;

        return res;
    }

    int countPartitions(vector<int>& nums, int k) {

        int n = nums.size();
        ll sum = 0;
        for(auto val : nums)
        sum += val;

        if(sum < 2*k)
        return 0;

        ll ans = helper(0, nums, k, n, sum);
        (ans *= 2)%=mod;


        if(ans > INT_MAX)
        return INT_MAX;
        else
        return (int)ans;

    }
};

int main(){
    Solution sol;
    vector<int> nums = {1,2,3,4};
    sol.countPartitions(nums, 4);
    return 0;
}