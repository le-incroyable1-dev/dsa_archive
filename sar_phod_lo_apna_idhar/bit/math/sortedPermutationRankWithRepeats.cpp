#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;


//INCOMPLETE

#define mod 1000003;


bool check_key(unordered_map<int, int> m, int key)
{
    // Key is not present
    if (m.find(key) == m.end())
        return false;
 
    return true;
}


int fact(int n)
{
        if(n==0) return 1 ; else return (n*fact(n-1)) %mod;
}


int findRank(string A) {
    
                    string s=A ;
                    //cin>>s;
                    int ans =0;
                    int n=s.length();
                    for(int i=0;i<n-1;i++)
                        {
                            int c=0;
                            
                            for(int j=i+1;j<n;j++)
                                {
                                    unordered_map<int, int> mymap;
                                    pair<int, int> p;
                                    p.first = s[j];
                                    p.second = 1;

                                    if(s[j]<s[i] && check_key(mymap, s[j]) && mymap.at(s[j]) == 1)
                                    {
                                        c--;
                                    }
                                    else
                                    mymap.insert(p);
                                    
                                    if(s[j]<s[i])
                                            c++;
                                }   
                                ans+=( (c*fact(n-i-1)) )%mod;
                                //cout << c <<" "<<ans<< endl;
                        }
                        return (ans+1 )%mod;
                        //cout << ans+1 ;

}