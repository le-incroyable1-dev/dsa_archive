#include <iostream>
#include <unordered_map>
#include <string>
typedef long long ll;
using namespace std;

string solve(string A, string B) {

    ll len = A.length();

    ll x = 0;
    ll y = 0;

    unordered_map<char, ll> achars;
    unordered_map<char, ll>::iterator itr;

    for(ll i = 0; i < len; i++){
        itr = achars.find(A.at(i));

        if(itr == achars.end()){
            achars.insert(make_pair(A.at(i), 1));
        }
        else{
            itr->second = itr->second + 1;
        }

    }

    for(ll i  = 0; i < len; i++){
        if(A.at(i) == B.at(i)){
            x++;
            //cout << x << B.at(i) << endl;
            itr = achars.find(B.at(i));

            itr->second = itr->second - 1;

            if(itr->second == 0)
            achars.erase(B.at(i));
        }
    }


    for(ll i  = 0; i < len; i++){
        
        if(A.at(i) != B.at(i)){
            itr = achars.find(B.at(i));
            if(itr != achars.end()){
                y++;
                itr->second = itr->second - 1;

                if(itr->second == 0)
                achars.erase(B.at(i));
            }

            //cout << y << " " << B.at(i) << endl;
        }
    }

    //cout << "hello" << endl;

    //cout << x << y << endl;

    string res = "";
    res += to_string((int)x) + "A" + to_string((int)y) + "B";

    //cout << res << endl;

    return res;
}
