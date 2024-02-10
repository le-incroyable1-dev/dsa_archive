#include <bits/stdc++.h>
using namespace std;



string solve(int n, vector<int> &instances, vector<float> &price){

    float res;
    int m = instances.size();

    if(n < instances[0]){
        float a1 = instances[0];
        float a2 = instances[1];
        float p1 = price[0];
        float p2 = price[1];

        res = p1 - ((a1-n)*(p2-p1))/(a2-a1);
    }
    else if(n > instances[m-1]){
        float a1 = instances[m-2];
        float a2 = instances[m-1];
        float p1 = price[m-2];
        float p2 = price[m-1];

        res = p2 - ((a2-n)*(p1-p2))/(a1-a2);
    }
    else{

        float a1,a2,p1,p2;

        for(int i = 0; i < m; ++i){
            if(instances[i] == n){
                string ans = to_string(price[i]);
                int index = ans.length();
                for(int i = 0; i < ans.length(); i++){
                    if(ans[i] == '0'){
                        index = i;
                        break;
                    }
                }
                ans = ans.substr(0, index);
                return ans;
            }
            else if(instances[i] > n){
                a1 =  instances[i-1];
                a2 = instances[i];
                p1 = price[i-1];
                p2 = price[i];

                break;
            }

        }

        float f = ((n-a1)*(p2-p1))/(a2-a1);
        res = p1 + f;
    }

    float nres = ceil(res*100);
    res = (nres/100);
    string ans = to_string(res);
    int index = ans.length();
    for(int i = 0; i < ans.length(); i++){
        if(ans[i] == '0'){
            index = i;
            break;
        }
    }
    ans = ans.substr(0, index);
    return ans;

}

int main(void){
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector<int> instances;
    vector<float> price;

    int ele;
    for(int i = 0; i < m; ++i){
        cin >> ele;
        instances.push_back(ele);
    }

    float pr;
    for(int i = 0; i < m; ++i){
        cin >> pr;
        price.push_back(pr);
    }

    cout << solve(n, instances, price);
    return 0;

}

