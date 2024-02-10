#include <iostream>
#include <vector>
using namespace std;



struct Interval {
     int start;
     int end;
     Interval() : start(0), end(0) {}
     Interval(int s, int e) : start(s), end(e) {}
 };

vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {

// ans contains final ans
vector<Interval> ans;
// tmp will hold intervals that are greater than(comes after) newInterval.
vector<Interval> tmp;

for(int i=0;i<intervals.size();i++){
    // push all intervals before newInterval to ans
    if(intervals[i].end < newInterval.start){
        ans.push_back(intervals[i]);
        // put all greater intervals into temp
    }else if(intervals[i].start > newInterval.end){
        tmp.push_back(intervals[i]);
    }
    else {
        // merging intervals here
        newInterval.start = min(newInterval.start,intervals[i].start);
        newInterval.end = max(intervals[i].end, newInterval.end);
    }
}
// after merge the newInterval is pushed to ans
ans.push_back(newInterval);

// all intervals greater than newInterval are pushed at last
for(int i=0;i<tmp.size();i++){
    ans.push_back(tmp[i]);
}

return ans;
}