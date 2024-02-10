#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_set>
#include <map>
#include <unordered_map>
using namespace std;



//INCOMPLETE


map<int, int> uniqueVals(vector<int> v)
{
    map<int, int> m;

    for(int i = 0; i < v.size(); i++){

        if(m.find(v.at(i)) == m.end()){
            pair<int,int> p;
            p.first = v.at(i);
            p.second = 1;
            m.insert(p);
        }
        else{
            map<int, int>::iterator itr = m.find(v.at(i));
            if(itr != m.end())
            itr->second = itr->second + 1;
        }
    }

    return m;
}

int countDigit(long long n) {
  return floor(log10(n) + 1);
}

int solve(vector<int> &A, int B, int C) {

    int n = A.size();

    if(B > n)
    return 0;

    if(countDigit(C) < B)
    return 0;

    map<int, int> uval = uniqueVals(A);
    
    if(countDigit(C) > B){

        if(B==1){
            return uval.size();
        }
        else{
            map<int, int>::iterator itr = uval.find(0);
            int nz = 0;
            if(itr != uval.end()){
                nz = itr->second;
            }

            return (pow(uval.size(), B-1) * (uval.size()-nz));
        }
    }

    if(countDigit(C) == B){

        int s = uval.size();

        map<int, int>::iterator itr = uval.find(0);
        int nz = 0;
        if(itr != uval.end()){
            nz = itr->second;
        }

        //int wz = s-nz;

        int ans = 0;
        int num = C;
        
        int ci = countDigit(num) - 1; // current index
        int c = 0;

        while(ci >= 0){

            int cn = 0; //current number 
            int nltc =0; // numbers less than current

            cn = (cn*pow(10,ci+1))-(num/pow(10,ci));

            map<int, int>::iterator itr;
            for(itr = uval.begin(); itr != uval.end(); itr++){
                if(itr->first < cn)
                nltc++;
            }

            if(ci == 4 && cn > 0 && nz>0 && B!=1 && nltc>0)
            nltc-=1;

            ans += pow(s, ci) * nltc;
            ci--;
            //num = num/10;
        }

        return ans;

    }

}