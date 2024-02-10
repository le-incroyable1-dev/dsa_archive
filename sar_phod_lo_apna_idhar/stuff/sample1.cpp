#include <bits/stdc++.h>
using namespace std;

int solve(int v1[], int v2[], int n){

    int res = 0;
    for(int i = 0; i < n; ++i){

        for(int j = 0; j < n; ++j){

            int i1 = i; int j1 = j;
            int count = 0;
            do{
                if(v1[i1] == v2[j1]) ++count;
                (i1 += 1) %= n; (j1 += 1) %= n;
            } while( i1 != i );

            res = max(res, count);
        }

    }

    return res;

}