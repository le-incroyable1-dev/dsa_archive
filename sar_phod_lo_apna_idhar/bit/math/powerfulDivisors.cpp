#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


//INCOMPLETE

int findDivisors(int s, int num){

    if(num == 1)
    return 0;

    int count = 1;

    for(int i = s+1; i <= num/2; i++){
        if(num % i == 0)
        count++;
    }

    return count;
}

vector<int> powerfulDivisors(vector<int> &A) {

    //vector<pair<int,int>> v;
    vector<pair<int,int>> divs;
    vector<pair<int,int>> divsi;
    vector<pair<int,int>> divsirev;
    vector<int> res;

    if(A.size() == 0)
    return res;

    if(A.size() == 1){
        res.push_back(findDivisors(0, A.at(0)));
        return res;
    }

    for(int i = 0; i < A.size(); i++){

        pair<int, int> p;
        p.first = A.at(i);
        p.second = i;
        divs.push_back(p);
    }

    sort(divs.begin(), divs.end());

    for(int i = 0; i < A.size(); i++){

        pair<int, int> p;

        if(i == 0){
            p.first = findDivisors(0, A.at(i));
            p.second = i;

            divsi.push_back(p);
        }
        else{

            int s = 0;
            int si = -1;
            //int j;

            for(int j = i-1; j >= 0; j--){
                if(divs.at(i).first%divs.at(j).first == 0){
                    si = j;
                    s = divs.at(j).first;
                    break;
                }
            }

            pair<int, int> p;
            p.first = findDivisors(s, divs.at(i).first);
            if(si!=-1)
            p.first += divsi.at(si).first;
        }
    }



}
