#include <bits/stdc++.h>
using namespace std;

int delrow[] = {-1, +1, 0, 0};

int delcol[] = {0, 0, -1, +1};

void dfs(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &vis)
{

    vis[i][j] = 1;

    int m = grid.size();

    int n = grid[0].size();

    for (int k = 0; k < 4; k++)
    {

        int nrow = i + delrow[k];

        int ncol = j + delcol[k];

        if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && grid[nrow][ncol] >= grid[i][j] && !vis[nrow][ncol])
        {

            dfs(nrow, ncol, grid, vis);
        }
    }
}

int solve(vector<vector<int>> &grid)
{

    int m = grid.size();

    int n = grid[0].size();

    vector<vector<int>> vis4blue(m, vector<int>(n, 0));
    vector<vector<int>> vis4red(m, vector<int>(n, 0));

    for (int i = 0; i < m; i++)

        if (!vis4blue[i][0])

            dfs(i, 0, grid, vis4blue);

    for (int j = 1; j < n; j++)

        if (!vis4blue[0][j])

            dfs(0, j, grid, vis4blue);

    for (int i = 0; i < m; i++)

        if (!vis4red[i][n - 1])

            dfs(i, n - 1, grid, vis4red);

    for (int j = 0; j < n; j++)

        if (!vis4red[m - 1][j])

            dfs(m - 1, j, grid, vis4red);

    int count = 0;

    for (int i = 0; i < m; i++)

        for (int j = 0; j < n; j++)

            if (vis4blue[i][j] == 1 && vis4red[i][j] == 1)

                count++;

    return count;
}

int main()
{

    vector<vector<int>> A = {{1, 2, 2, 3, 5}, {3, 2, 3, 4, 4}, {2, 4, 5, 3, 1}, {6, 7, 1, 4, 5}, {5, 1, 1, 2, 4}};
    cout << solve(A) << "\n";
    return 0;
}