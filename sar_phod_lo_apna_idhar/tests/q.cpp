#include <bits/stdc++.h>
using namespace std;


bool isPalindrome(string s){
    int n = s.length();

    int i = 0;
    int j = n-1;

    while(i < j && s[i] == s[j]){
        i++;
        j--;
    }

    if(i >= j)
    return true;
    else
    return false;

}


string solve(string s){

    string ans = "";
    int n = s.length();

    string word = "";

    for(int i = 0; i < n; ++i){
        if(s[i] == ' '){
            string ns;

            if(isPalindrome(word)){
                ns += "$";
                ns += word;
                ns += "$";
            }
            else{
            for(int i = word.size()-1; i >= 0; i--)
                ns += word[i];
            }

            ans += ns;
            ans += " ";
        }
        else
        word += s[i];
    }

}