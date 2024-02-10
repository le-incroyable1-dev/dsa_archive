#include <iostream>
#include <vector>
#include <string>
using namespace std;


//g mrgyi

vector<int> flip(string A) {
    int n = A.length();
    int l,r,fl,fr = 0;
    vector<int> res;
    
    bool foundZero = false;

    for(int i = 0; i < n; i++)
    {
        if(A.at(i) == '0')
        {
            l = i;
            r = i;
            fl = i;
            fr = i;

            foundZero = true;
        }

        if(foundZero)
        break;
    }

    if(!foundZero)
    return res;

    int z = 1;
    int o = 0;

    bool fz = false;
    int frnew = -1;
                    
    int dif = z - o;
    
    r++;
        
    while(r < n)
    {

        if(A.at(r) == '0')
        z++;
        else
        o++;

        if((z - o) > dif)
        {
            
            dif = z - o;

            if(fz)
            {
                fl = l;
                frnew = r;
            }
            else
            fr = r;
        }

        if(z < o)
        {
            for(int i = r; i < n; i++)
            {
                fz = false;

                if(A.at(i) == '0')
                {
                    l = i;
                    r = i;
                    z = 1;
                    o = 0;
                    //dif = z - o;
                    fz = true;
                    break;
                }
            }
        }

        r++;
    }

    if(frnew != -1)
    fr = frnew;

    fl++;
    fr++;
    
    res.push_back(fl);
    res.push_back(fr);

    return res;
}

int main()
{

    string A;
    cin >> A;

    vector<int> res = flip(A);
    cout << res.at(0) << res.at(1);
    return 0;
}
