#include <cassert>
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <iomanip>
#include <array>
#include <unordered_set>
typedef long double ld;
typedef unsigned long long ll;
using namespace std;


// This is the class you need to implement! Feel free to add members, private methods etc, but don't change the public
// method signatures.



class limit{
    public:

    double maxValue; 
    int maxVolume10Seconds;
    double maxValue1Second;

    limit(){
    
    }

    limit(double maxValue, int maxVolume10Seconds, double maxValue1Second){
        this->maxValue = maxValue;
        this->maxVolume10Seconds = maxVolume10Seconds;
        this->maxValue1Second = maxValue1Second;
    }
};

class order{
    public:

    ll timestamp;
    int volume;
    double price;

    order(){

    }

    order(ll timestamp, int volume, double price){
        this->timestamp = timestamp;
        this->volume = volume;
        this->price = price;
    }
};

unordered_map<string, limit> limit_map;
unordered_map<string, vector<order>> order_map;
unordered_set<string> breached;

class RiskLimitProcessor
{
    private:
    

    public:
        void AddLimit(const std::string& instrument, double maxValue, int maxVolume10Seconds, double maxValue1Second)
        {
            if(breached.find(instrument) == breached.end()){
                limit *cur_limit = new limit(maxValue, maxVolume10Seconds, maxValue1Second);
                limit_map[instrument] = *cur_limit;
            }
        }

        void ProcessOrder(const std::string& instrument, uint64_t timestamp, int volume, double price)
        {
            if(breached.find(instrument) != breached.end()) return;

            if(limit_map.find(instrument) == limit_map.end()){
                cout << "NO_LIMITS " << instrument << "\n";
                return;
            }


            limit cur_limit = limit_map[instrument];
            order *cur_order = new order(timestamp, volume, price);
            order_map[instrument].push_back(*cur_order);

            double cur_value = (double)volume * price;

            if(cur_value > cur_limit.maxValue){
                cout << "MAX_VAL_LIMIT " << instrument << "\n";
                breached.insert(instrument);
                return; 
            }

            ll one_sec = 1000000;

            vector<order> v = order_map[instrument];
            int n = v.size();

            int i = n-1;

            ll check;
            if(timestamp >= one_sec)
            check = timestamp - one_sec;
            else
            check = 0;

            ll cur_ts = v[i].timestamp;

            double cur_val_1s = 0;

            while(i >= 0 && cur_ts >= check){
                cur_val_1s += v[i].price * v[i].volume;
                i--;

                if(i >= 0)
                cur_ts = v[i].timestamp;
            }

            if(cur_val_1s > cur_limit.maxValue1Second){
                cout << "MAX_VAL_1S_LIMIT " << instrument << "\n";
                breached.insert(instrument);
                return;
            }

            i = n-1;

            if(timestamp >= (ll)10*one_sec)
            check = timestamp - (ll)10*one_sec;
            else
            check = 0;

            cur_ts = v[i].timestamp;

            double cur_vol_10s = 0;

            while(i >= 0 && cur_ts >= check){
                cur_vol_10s += v[i].volume;
                i--;

                if(i >= 0)
                cur_ts = v[i].timestamp;
            }

            if(cur_vol_10s > cur_limit.maxVolume10Seconds){
                cout << "MAX_VOL_10S_LIMIT " << instrument << "\n";
                breached.insert(instrument);
                return;
            }

            return; 
            
        }
};

int main()
{
    RiskLimitProcessor riskLimitProcessor;
    while(!std::cin.eof())
    {
        std::string action, instrument;
        std::cin >> action >> instrument;
        if (action.empty())
            break; // handle whitespace at end of input
        if (action == "LIMIT")
        {
            double maxValue;
            int maxVolume10Seconds;
            double maxValue1Second;
            std::cin >> maxValue >> maxVolume10Seconds >> maxValue1Second;
            riskLimitProcessor.AddLimit(instrument, maxValue, maxVolume10Seconds, maxValue1Second);
        }
        else if (action == "ORDER")
        {
            uint64_t timestamp;
            int volume;
            double price;
            std::cin >> timestamp >> volume >> price;
            riskLimitProcessor.ProcessOrder(instrument, timestamp, volume, price);
        }
        else
        {
            std::cerr << "Malformed input!\n";
            return -1;
        }
    }
    return 0;
}