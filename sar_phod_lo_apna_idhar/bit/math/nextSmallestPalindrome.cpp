#include <iostream>
#include <string>
using namespace std;

//EDITORIAL
string solve(string A) {
    int size = A.size();
    int mid = (size+1)/2;

    bool incr = true;
    // check if we need to add 1 to first half of the number
    // before making it into a palindrome.
    for(int i = mid; i < size; i++) {
        if(A[size-1-i] == A[i]) continue;
        if(A[size-1-i] < A[i]) incr = true;
        if(A[size-1-i] > A[i]) incr = false;
        break;
    }

    A = A.substr(0,mid);

    //add 1 to the first half of the number.
    if(incr) {
        int carry = 1;

        for(int i = mid-1; i >= 0 && carry == 1; i--)
            A[i] = ( A[i] == '9' ? '0' : A[i] + carry--);

        if(carry) //every digit must have been '9'
            return '1' + string(size-1,'0') + '1';
    }

    //append the first half reversed to make the palindrome.
    for(int i = size-A.size()-1; i >= 0; i--)
        A.push_back(A[i]);

    return A;
}

/* 
//SELF


bool isPalindrome(string S)
{
    // Stores the reverse of the
    // string S
    string P = S;
 
    // Reverse the string P
    reverse(P.begin(), P.end());
 
    // If S is equal to P
    if (S == P) {
        // Return "Yes"
        return true;
    }
    // Otherwise
    else {
        // return "No"
        return false;
    }
}

string solve(string A) {

    if(stoll(A) < 9)
    {
        int a = stoll(A);
        a++;
        return to_string(a);
    }
    else if(stoll(A) < 11)
    return to_string(11);

    bool allnine = true;

    for(int i = 0; i < A.length(); i++)
    {
        if(A.at(i) != '9')
        {
            allnine = false;
            break;
        }
    }

    if(allnine)
    {
        int n = stoll(A);
        n += 2;
        return to_string(n);
    }

    int hs = A.size()/2;

    string p1 = A.substr(0, hs);
    string m = "x";
    string p2;

    if(A.size() % 2 == 0)
    p2 = A.substr(hs, hs);
    else
    {
        p2 = A.substr(hs+1, hs);
        m = A.substr(hs, 1);
    }

    string rp1 = p1;
    reverse(rp1.begin(), rp1.end());

    //cout << rp1 << endl << p1 << endl << p2;

    if(rp1 == p2)
    {
        if(m != "x")
        {
            int a = stoll(m);
            a++;

            if(a == 10)
            {
                a = 0;
                string lp1 = p1.substr(p1.size()-1, 1);

                int b = stoll(lp1);
                b++;

                if(b == 10)
                {
                    a = stoll(A);
                    a++;
                    A = to_string(a);
                    
                    while(!isPalindrome(A))
                    {
                        a = stoll(A);
                        a++;
                        A = to_string(a);
                    }

                    return A;

                }

                p1.at(p1.size() - 1) = '0' + static_cast<char>(b);
                p2.at(0) = '0' + static_cast<char>(b);

                return p1+to_string(a)+p2;
            }

            m = to_string(a);
            return p1+m+p2;
        }
        else
        {
            string lp1 = p1.substr(p1.size()-1, 1);
            //cout << lp1 << endl;
            int a = stoll(lp1);
            a++;

            if(a == 10)
            {
                if(A.size() == 2)
                {
                    return to_string(101);
                }

                int num = stoll(p1);
                num++;
                //cout << num << endl;

                string s1 = to_string(num);
                string s2 = s1;
                reverse(s2.begin(), s2.end());

                return s1+s2;
            }

            p1.at(p1.size() - 1) = '0' + static_cast<char>(a);
            p2.at(0) = '0' + static_cast<char>(a);

            return p1+p2;
        }
    }

    if(m=="x")
    {
        if(stoll(rp1) > stoll(p2))
        return p1+rp1;
        else
        {
            string lp1 = p1.substr(p1.size()-1, 1);
            int a = stoll(lp1);
            a++;

            if(a == 10)
            {
                int num = stoll(p1);
                num++;

                string s1 = to_string(num);
                string s2 = s1;
                reverse(s2.begin(), s2.end());

                return s1+s2;
            }

            p1.at(p1.size() - 1) ='0' + static_cast<char>(a);
            rp1 = p1;
            reverse(rp1.begin(), rp1.end());

            return p1 + rp1;
        }
    }
    else
    {
        if(stoll(rp1) > stoll(p2))
        return p1+m+rp1;
        else
        {
            int a = stoll(m);
            a++;

            if(a == 10)
            {
                int x = stoll(m);
                x++;

                if(x == 10)
                {
                    m = to_string(0);
                    int i1 = stoll(p1);
                    i1++;
                    string s1 = to_string(i1);
                    string s2 = s1;
                    reverse(s2.begin(), s2.end());

                    return s1+m+s2;
                }

                m = to_string(x);

                return p1+m+rp1;
            }

            m = to_string(a);

            return p1+m+rp1;
        }
    }


}
*/


/*
int to char c++
// for example you have such integer
int i = 3;

// and you want to convert it to a char so that
char c = '3';

what you need to do is, by adding i to '0'. The reason why it works is 
because '0' actually means an integer value of 48. '1'..'9' means 49..57. 
This is a simple addition to find out corresponding character for an single decimal digit integer:

i.e. char c = '0' + i;
*/