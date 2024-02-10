#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>
#include <string>
#include <stack>

using namespace std;

#define ll long long
#define ld long double

int solve(string A) {

    if(A.size() == 0 || A.size() == 1)
    return A.size();

    stack<char> st;

    for(auto ch : A){
        if(!st.empty() && st.top() == '('){
            if(ch == ')')
            st.pop();
            else
            st.push(ch);
        }
        else
        st.push(ch);
    }

    return st.size();
}
