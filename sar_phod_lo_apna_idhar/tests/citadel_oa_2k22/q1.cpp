#include <bits/stdc++.h>
using namespace std;
  
// Function to find the minimum and
// maximum element for each subarray
// of size K
int maxSubarray(int arr[], int n, int k)
{
  
    // To store the frequency of element
    // for every subarray
    map<int, int> Map;
  
    // To count the subarray array size
    // while traversing array
    int l = 0;
  
    // Traverse the array
    for (int i = 0; i < n; i++) {
  
        // Increment till we store the
        // frequency of first K element
        l++;
  
        // Update the count for current
        // element
        Map[arr[i]]++;
  
        // If subarray size is K, then
        // find the minimum and maximum
        // for each subarray
        if (l == k) {
  
            // Iterator points to end
            // of the Map
            auto itMax = Map.end();
            itMax--;
  
            // Iterator points to start of
            // the Map
            auto itMin = Map.begin();
  
            // Print the minimum and maximum
            // element of current sub-array
            cout << itMin->first << ' '
                 << itMax->first << endl;
  
            // Decrement the frequency of
            // arr[i - K + 1]
            Map[arr[i - k + 1]]--;
  
            // if arr[i - K + 1] is zero
            // remove from the map
            if (Map[arr[i - k + 1]] == 0) {
                Map.erase(arr[i - k + 1]);
            }
  
            l--;
        }
    }
    return 0;
}
  
// // Driver Code
// int main()
// {
//     // Given array arr[]
//     int arr[] = { 5, 4, 3, 2, 1, 6,
//                   3, 5, 4, 2, 1 };
  
//     // Subarray size
//     int k = 3;
  
//     int n = sizeof(arr) / sizeof(arr[0]);
  
//     // Function Call
//     maxSubarray(arr, n, k);
//     return 0;
// }

int segment(int x, vector<int> space){
    int n = space.size();

    if(n==1)
        return space[0];

    int count = 0;
    int currMin = INT_MAX;
    int globMax = -1;
    for(int i=0; i<n; i++){
        if(count<x){
            currMin = min(currMin, space[i]);
            count++;
        }else{
            
            globMax = max(globMax, currMin);
            if(space[i-count]==currMin){
                currMin = space[i-count+1];
                int j = i-count+1;
                while(j<=i){
                    currMin = min(currMin, space[j]);
                    j++;
                }
            }else{
                currMin = min(currMin, space[i]);
            }
        }
    }
    globMax = globMax == -1?currMin:globMax;
    return globMax;
}



int segment2(int x, vector<int> space){
    int n = space.size();
    multiset<int> s;
    int ans = -1;

    if(n==1)
        return space[0];

    int count = 0;

    for(int i = 0; i <= n; ++i){
        if(count < x){
            s.insert(space[i]);
            count++;
        }
        else{
            int curmin = *s.begin();
            ans = max(ans, curmin);

            if(i == n)
            break;

            int prev = space[i-count];
            multiset<int>::iterator itr = s.find(prev);
            s.erase(itr);
            s.insert(space[i]);
        }
    }

    return ans;
}

int segment3(int x, vector<int> space){
    int n = space.size();
    deque<int> dq;
    int ans = -1;

    if(n==1)
        return space[0];

    int count = 0;

    for(int i = 0; i <= n; ++i){
        if(count <= x){
            while(!dq.empty() && dq.back() > space[i])
            dq.pop_back();
            dq.push_back(space[i]);
            count++;
        }
        else{
            int curmin = dq.front();
            ans = max(ans, curmin);

            if(i == n)
            break;

            if(dq.front() == space[i-count])
            dq.pop_front();

            while(!dq.empty() && dq.back() > space[i])
            dq.pop_back();
            dq.push_back(space[i]);
        }
    }

    return ans;
}


int main(){

    vector<int> space = {2,5,4,6,8};
    cout << segment3(2,space);
    return 0;
}

int solve(int x, int space[]){

    //int n = sizeof(space)/sizeof(int);

    int c = 0;
    int ans = INT_MIN;

    return ans;

}