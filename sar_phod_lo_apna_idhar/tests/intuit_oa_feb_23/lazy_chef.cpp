#include<bits/stdc++.h>
using namespace std;
 
void solve()
{
	
    int n; cin >> n;
	string s;
    
	cin >> s;
   

    char c; cin >> c;

    for(int i = 0; i < n; ++i){
        if(s[i] == c) s[i] = '*';
        else s[i] = '.';
    }

	int cnt = 0;
	for(auto x : s)
		cnt += (x == '*' ? 1 : 0);
	int pos = -1;
	int cur = -1;
	for(int i = 0; i < n; i++)
	{
	 	if(s[i] == '*')
	 	{
	 	    cur++;
	 	    if(cur == cnt / 2)
	 	    	pos = i;
	 	}	
	}
	long long ans = 0;
	cur = pos - cnt / 2;
	for(int i = 0; i < n; i++)
		if(s[i] == '*')
		{
		 	ans += abs(cur - i);
		 	cur++;
		}
	cout << ans << endl;
}
 
int main()
{
    solve();
}