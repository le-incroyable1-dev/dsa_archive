#include <algorithm>
#include <iostream>
#include <vector>
#include <climits>
#include <cmath>

using namespace std;

int maximumGap(const vector<int> &A) {

     if(A.size()<2){
        return 0;
    }

    int max_ele=INT_MIN, min_ele=INT_MAX;
    for(int a:A){
        if(a>max_ele){
            max_ele=a;
        }
        if(a<min_ele){
            min_ele=a;
        }
    }

    if(min_ele==max_ele){
        return 0;
    }

    double gap=((max_ele-min_ele)*1.0)/(A.size()-1);
    gap=max(gap,1.0);

    vector<int> min_bucket(A.size(), INT_MAX);
    vector<int> max_bucket(A.size(), INT_MIN);

    for(int a:A){
        int pos=floor((a-min_ele)/gap);
        min_bucket[pos]=min(min_bucket[pos],a);
        max_bucket[pos]=max(max_bucket[pos],a);
    }

    int prev_max=min_ele;
    int max_gap=floor(gap);

    for(int i=0;i<A.size();i++){
        if(min_bucket[i]==INT_MAX){//bucket is empty
            continue;
        }
        max_gap=max(min_bucket[i]-prev_max, max_gap);
        prev_max=max_bucket[i];
    }

    return max_gap; 

}
