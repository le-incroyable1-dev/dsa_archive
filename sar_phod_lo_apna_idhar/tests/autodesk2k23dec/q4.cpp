#include <bits/stdc++.h>
using namespace std;

int ROW, COL;

// check whether given cell (row, col) is a valid
// cell or not.
bool isvalid(int row, int col, int prevRow, int prevCol)
{
	// return true if row number and column number
	// is in range
	return (row >= 0) && (row < ROW) &&
		(col >= 0) && (col < COL) &&
		!(row== prevRow && col == prevCol);
}

int rowNum[] = {1, 0};
int colNum[] = {0, 1};

// A utility function to do DFS for a 2D boolean
// matrix. It only considers the 8 neighbours as
// adjacent vertices
int DFS(vector<vector<char>> mat, int row, int col,
		int prevRow, int prevCol, string word,
		int index, int n)
{

    int res = 0;
	// return if current character doesn't match with
	// the next character in the word
	if (index > n || mat[row][col] != word[index])
		return 0;

	// current character matches with the last character
	// in the word
	if (index == n)
	{
		res++;
	}

	// Recur for all connected neighbours
	for (int k = 0; k < 2; ++k)
		if (isvalid(row + rowNum[k], col + colNum[k],
					prevRow, prevCol))

			res += DFS(mat, row + rowNum[k], col + colNum[k],
				row, col, word, index+1, n);
}


int findWords(vector<vector<char>> mat, string word, int n)
{
    int res = 0;
    int ROW = mat.size(); int COL = mat[0].size();
	// traverse through the all cells of given matrix
	for (int i = 0; i < ROW; ++i)
		for (int j = 0; j < COL; ++j)

			// occurrence of first character in matrix
			if (mat[i][j] == word[0])

				// check and print if path exists
				res += DFS(mat, i, j, -1, -1, word, 0, n);

    return res;
}


int sol(vector<vector<char>> matrix, vector<string> words){
    int ans = 0;
    ROW = matrix.size();
    COL = matrix[0].size();
    for(auto word : words){
        int n = word.size();
        ans += findWords(matrix, word, n);
    }
}
// Driver program to test above function
int main()
{

	return 0;
}
