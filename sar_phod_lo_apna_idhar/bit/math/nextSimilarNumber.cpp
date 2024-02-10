
#include <string>
#include <iostream>
using namespace std;
#define ll long long

//interviewbit chu hai stoi aur stoll pe error deta

void swap(char &n, char &m)
{
    char temp = m;
    m = n;
    n = temp;
}

string getString(char x)
{
    // string class has a constructor
    // that allows us to specify size of
    // string as first parameter and character
    // to be filled in given size as second
    // parameter.
    string s(1, x);
 
    return s;  
}

string solve(string A) {

    string str = A;

    ll val = stoll(str);

    if(val <= 11)
    return "-1";

    ll len = str.length();

    ll smol = len-1;
    ll index = 0;

    for(ll i = len-1; i > 0; i--)
    {
        if(stoll(getString(str.at(i-1))) < stoll(getString(str.at(i))))
        {
            while(smol >= i && stoll(getString(str.at(smol))) <= stoll(getString(str.at(i-1))))
            {
                if(smol == i)
                break;

                smol--;
            }
    
            swap(str.at(smol), str.at(i-1));
            index = i;
            break;
        }

        if(i == 1)
        return "-1";
    }

    //cout << str << " " << index << endl;
    string part1 = str.substr(0, index);
    string part2 = str.substr(index, len-index);
    reverse(part2.begin(), part2.end());
    //cout << part1 << " " << part2 << endl;
    

    return part1 + part2;

}

