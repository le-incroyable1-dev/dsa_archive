
#include <bits/stdc++.h>
//typedef long long ll;
using namespace std;



vector<int> minimal(vector<string> strs){

   vector<int> ans;

   int s = strs.size();
   for(int i = 0; i < s; i++){
       int ct = 0;

       string cur = strs.at(i);

       int size = cur.length()-1;

       for(int j = 0; j < size; j++){
           if(cur.at(j) == cur.at(j+1)){
               ct++;
               j++;
           }
       }

       ans.push_back(ct);
   }

   return ans;
}

int main(){
 vector<int> res;

 vector<string> strs = { "abc", "aabbaab", "aabaaab"};

 res = minimal(strs);

 for(int i = 0; i < res.size(); i++)
 cout << res.at(i) << endl;

 return 0;

}