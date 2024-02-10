#include <iostream>
#include <vector>
using namespace std;

int solve(int A, vector<int> &B) {
    int sum = 0;

    for(int i = 0; i < A; i++)
    {
        sum += B.at(i);
    }

    if(sum%3 != 0)
    return 0;

    sum = sum/3 ;

    int lidx = -1;
    //int nl = 0;
    //int nr = 0;

    int res = 0;

    int sum1 = 0;
    int sum2 = 0;

    for(int i = 0; i < A-2; i++)
    {
        sum1 += B.at(i);
        if(sum1 == sum)
        {
            lidx = i;
            //nl++;
            sum2 = 0;

            for(int i = A-1; i > lidx+1; i--)
            {
                sum2 += B.at(i);
                if(sum2 == sum)
                {
                   //nr++;
                   res++;
                }
            }
        }

    }
    
    return res;


}
