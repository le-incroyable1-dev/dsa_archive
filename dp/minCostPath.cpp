#include <bits/stdc++.h>
using namespace std;

/*
An integer matrix of size (M x N) has been given. Find out the 
minimum cost to reach from the cell (0, 0) to (M - 1, N - 1).
From a cell (i, j), you can move in three directions:
1. ((i + 1),  j) which is, "down"
2. (i, (j + 1)) which is, "to the right"
3. ((i+1), (j+1)) which is, "to the diagonal"
The cost of a path is defined as the sum of each cell's values through 
which the route passes.
*/

//O(m*n)
int minCostPath(int **input, int m, int n){

    vector<std::vector<int>> dp(m, std::vector<int>(n, -1));

    dp[0][0] = input[0][0];

    for(int i = 1; i < n; i++)
    dp[0][i] = dp[0][i-1] + input[0][i];

    for(int i = 1; i < m; i++)
    dp[i][0] = dp[i-1][0] + input[i][0];

    // int mn = min(m, n);
    // for(int i = 1; i < mn; i++)
    // dp[i][i] = dp[i-1][i-1] + input[i][i];

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
			if(dp[i][j] == -1){
				int v1, v2, v3 = INT_MAX;
				if(i-1 >= 0){
					v1 = dp[i-1][j] + input[i][j];
				}

				if(j-1 >= 0){
					v2 = dp[i][j-1] + input[i][j];
				}

				if(i-1 >=0 && j-1 >= 0){
					v3 = dp[i-1][j-1] + input[i][j];
				}

				int res = min(v1, min(v2, v3));

				dp[i][j] = res;
			}
            else
                continue;
        }
    }

	return dp[m-1][n-1];
}

int main()
{
	int **arr, n, m;
	cin >> n >> m;
	arr = new int *[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = new int[m];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}
	cout << minCostPath(arr, n, m) << endl;
}