#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

pair<int, int> getReducedForm(int dy, int dx)
{
    int g = gcd(abs(dy), abs(dx));

    bool sign = (dy < 0) ^ (dx < 0);

    if (sign)
        return make_pair(-abs(dy) / g, abs(dx) / g);
    else
        return make_pair(abs(dy) / g, abs(dx) / g);
}

int minLinesToCoverPoints(vector<vector<int>> &points, int N,
                          int xO, int yO)
{
    set<pair<int, int>> st;
    pair<int, int> temp;
    int minLines = 0;

    for (int i = 0; i < N; i++)
    {
        int curX = points[i][0];
        int curY = points[i][1];

        if (curX != xO || curY != yO)
        {
            temp = getReducedForm(curY - yO, curX - xO);
            if (st.find(temp) == st.end())
            {
                st.insert(temp);
                minLines++;
            }
        }
    }

    return minLines;
}
int main()
{

    int n;
    cin >> n;
    vector<vector<int>> vec(n);
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        vec[i] = {x, y};
    }
    int res = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        res = min(res, minLinesToCoverPoints(vec, n, vec[i][0], vec[i][1]));
    }
    cout << res;
    return 0;
}


