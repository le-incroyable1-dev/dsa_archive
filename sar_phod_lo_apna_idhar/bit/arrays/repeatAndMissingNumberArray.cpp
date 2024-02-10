#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
using namespace std;


//REVIEW
//EDITORIAL SOLUTION


vector<int> repeatedNumber(const vector<int> &V) {
    
       long long sum = 0;
       long long squareSum = 0;
       long long temp;

       for (int i = 0; i < V.size(); i++) {
           temp = V[i];
           sum += temp;
           sum -= (i + 1);
           squareSum += (temp * temp);
           squareSum -= ((long long)(i + 1) * (long long)(i + 1));
       }
       // sum = A - B
       // squareSum = A^2 - B^2 = (A - B)(A + B)
       // squareSum / sum = A + B
       squareSum /= sum;

       // Now we have A + B and A - B. Lets figure out A and B now. 
       int A = (int) ((sum + squareSum) / 2);
       int B = squareSum - A;

       vector<int> ret;
       ret.push_back(A);
       ret.push_back(B);
       return ret;
    }

/*
//MEMORY LIMIT EXCEEDED :(

vector<int> repeatedNumber(const vector<int> &A) {

    vector<int> res;

    int n = A.size();

    unordered_map<int, int> freq;
    unordered_map<int, int>::iterator itr;
    
    int a;
    int b;

    int sum = 0;

    for(int i = 0; i < n; i++){

        sum += A.at(i);

        itr = freq.find(A.at(i));

        if(itr == freq.end()){
            pair<int, int> p;
            p.first = A.at(i);
            p.second = 1;
            freq.insert(p);
        }
        else{
            itr->second = itr->second + 1;
            a = itr->first;
        }
    }

    int esum = n*(n+1)/2;

    //cout << esum << " " << sum << " " << a << endl;

    b = esum - sum + a;

    res.push_back(a);
    res.push_back(b);

    return res;
}

*/

/*
//count sort gfg
void countSort(vector<int>& arr)
{
    int max = *max_element(arr.begin(), arr.end());
    int min = *min_element(arr.begin(), arr.end());
    int range = max - min + 1;
  
    vector<int> count(range), output(arr.size());
    for (int i = 0; i < arr.size(); i++)
        count[arr[i] - min]++;
  
    for (int i = 1; i < count.size(); i++)
        count[i] += count[i - 1];
  
    for (int i = arr.size() - 1; i >= 0; i--) {
        output[count[arr[i] - min] - 1] = arr[i];
        count[arr[i] - min]--;
    }
  
    for (int i = 0; i < arr.size(); i++)
        arr[i] = output[i];
}

vector<int> repeatedNumber(const vector<int> &A) {

    long n = A.size();
    sort(A.begin(), A.end());

    int num = 1;
    int a = -1;
    int b = -1;

    vector<int> res;

    for(long i = 0; i < n; i++){

        if(A.at(i) != num){
            b = A.at(i);
        }

        if(i < n-1 && A.at(i) == A.at(i+1)){
            a = A.at(i);
        }

        if(a > 0 && b > 0)
        return;

        num++;

    }

    res.push_back(a);
    res.push_back(b);

    return res;

}
*/