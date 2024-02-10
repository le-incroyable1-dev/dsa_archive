#include <iostream>
#include <vector>

using namespace std;


//INCOMPLETE
int solve(vector<int> &A, int B) {

    int nlights = 0;
    int n = A.size();
    bool success = false;

    if(2*(B-1) >= n)
    {
        if(B-1 >= n)
        {
            for(int i = 0; i < n; i++)
            {
                if(A.at(i) == 1)
                {
                    return 1;
                }
            }

            return -1;
        }
        else if(A.at(B-1) == 1 || A.at(B-2) == 1)
        return 1;
    }

    for(int i = 0; i < n; i++)
    {
        success = false;

        //cout << "iteration " << i << " : " << nlights << endl;
        //cout << "iteration " << i;

        if(A.at(i) == 0)
        {
            for(int j = B-1; j > 0; j--)
            {
                if(A.at(i+j) == 1)
                {
                    nlights++;
                    success = true;
                    i+=j-1;
                    break;
                }
            }

            if(!success)
            return -1;

        }
        else{

            //if A.at(i) is equal to 1, then

            

            if(n-1-i <= B-1)
            {
                success = true;
                //nlights -= 1;
                break;
            }

            for(int j = B; j > 0; j--)
            {
                if(A.at(i+j) == 1)
                {
                    nlights++;
                    success = true;
                    i+=j-1;
                    break;
                }
            }

            if(i == 0 && !success)
            {
                success = true;
                nlights++;
                i-= 1;
            }

            if(!success)
            {
                for(int k = i + 2*(B-1) + 1; k > i; k--)
                {
                    if(A.at(k) == 1)
                    {
                        success = true;
                        nlights++;
                        i += k-1;
                        break;
                    }
                }
            }

            if(!success)
            {
                return -1;
            }

        }

        //cout << " : " << nlights << endl;        
    }

    return nlights;
}
