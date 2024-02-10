#include <iostream>
#include <vector>
using namespace std;

class PriorityQueue {
    vector<int> pq;

   public:
    bool isEmpty() { 
        return pq.size() == 0; 
    }

    int getSize() { 
        return pq.size(); 
    }

    int getMin() {
        if (isEmpty()) {
            return 0;
        }

        return pq[0];
    }

    void insert(int element) {
        pq.push_back(element);

        int childIndex = pq.size() - 1;

        while (childIndex > 0) {
            int parentIndex = (childIndex - 1) / 2;

            if (pq[childIndex] < pq[parentIndex]) {
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            } else {
                break;
            }

            childIndex = parentIndex;
        }
    }

    int removeMin() {
        
        int s = pq.size();
        int min = pq[0];
        
        int le = pq[s - 1];
        pq[0] = le;
        pq.pop_back();
        
        int pi = 0;
        int ci;
        
        if(pq[1] > pq[2])
            ci = 2;
        else
            ci = 1;
        
        while(ci < s && pq[pi] > pq[ci]){
            
            int temp = pq[ci];
            pq[ci] = pq[pi];
            pq[pi] = temp;
            
            pi = ci;
            
            if(pq[2*pi + 1] > pq[2*pi + 2])
                ci = 2*pi + 2;
            else
                ci = 2*pi + 1;
        }
        
        return min;
    }
};