#include <bits/stdc++.h>
// typedef long long ll;
using namespace std;


/*
bool static cmp(vector<long> a, vector<long> b)
{
    return a[1] > b[1];
}

long getMaxUnits(vector<long> boxes, vector<long> unitsPerBox, long truckSize)
{
    vector<vector<long>> boxTypes;

    for(int i = 0; i < boxes.size(); i++){
        vector<long> v;
        v.push_back(boxes.at(i));
        v.push_back(unitsPerBox.at(i));
        boxTypes.push_back(v);
    }
    

    long ans = 0;
    sort(boxTypes.begin(), boxTypes.end(), cmp);

    /* You can check the sorting technique by using this
    // You can understand very easily by running this.
    // Calculation must be easy after seeing this.

    for(auto i : boxTypes){
        cout<<i[0]<<" "<<i[1]<<" ";
        cout<<endl;

    }
    cout<<endl;
    */
/*
    for (auto i : boxTypes)
    {

        if (truckSize > i[0])
        {
            ans += (i[0] * i[1]);
            truckSize -= i[0];
        }
        else
        {
            ans += truckSize * i[1];
            truckSize = 0;
            break;
        }
    }

    return ans;
}
*/

int main(void)
{

    return 0;
}