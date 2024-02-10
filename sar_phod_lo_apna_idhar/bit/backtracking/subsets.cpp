#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> subs;
void solve1(int k, vector<int> &ans, vector<int> &A)
{
    if (k == n)
    {
        subs.push_back(ans);
    }
    else
    {
        solve1(k + 1, ans, A);
        ans.push_back(A[k]);

        solve1(k + 1, ans, A);
        if (!ans.empty())
        {
            ans.pop_back();
        }
    }
}

void solve2(vector<int> &A)
{
    int n = A.size();
    for (int p = 1; p <= (1 << n); p++)
    {
        vector<int> subset;
        for (int i = 0; i < n; i++)
        {
            if (p & (1 << i))
                subset.push_back(A[i]);
        }
        subs.push_back(subset);
    }
}


vector<vector<int>> subsets(vector<int> &A)
{
    n = A.size();
    subs.clear();
    vector<int> ans;

    sort(A.begin(), A.end());
    // solve1(0,ans,A); // recursive
    solve2(A); // bitmask method
    sort(subs.begin(), subs.end());
    return subs;
}