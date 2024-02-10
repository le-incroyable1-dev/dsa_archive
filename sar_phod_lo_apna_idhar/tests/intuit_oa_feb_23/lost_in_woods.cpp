# include <bits/stdc++.h>
using namespace std;

void solve(vector<char>& board, int n) {

	int i = 0;

    while(i < n){
        if(i+1 < n && board[i+1] == '*'){
            cout << "J";
            ++i;
            while(i < n && board[i] == '*'){
                ++i;
            }
        }
        else{
            cout << "W";
            ++i;
        }
    }
	
	return;
}

int main(){
	int n;

	cin >> n;
	vector<char> board;

	for(int i = 0; i < n; i++) {
		char temp;
		cin >> temp;
		board.push_back(temp);
	}

	solve(board, n);

	return 0;
}