#include <bits/stdc++.h>
using namespace std;
bool strongPasswordCheckerII(string password)
{
    int countoflower = 0;
    int countofupper = 0;
    int countofdigits = 0;
    int countofspecial = 0;
    int countofduplicates = 0;
    for (int i = 0; i < password.length(); i++)
    {
        if (islower(password[i]))
        {
            countoflower++;
        }
        if (isupper(password[i]))
        {
            countofupper++;
        }
        if (isdigit(password[i]))
        {
            countofdigits++;
        }
        if (password[i] == '!' || password[i] == '@' || password[i] == '#' || password[i] == '%' || password[i] == '^' || password[i] == '&' || password[i] == '*' || password[i] == '(' || password[i] == ')' || password[i] == '-' || password[i] == '+')
        {
            countofspecial++;
        }
        if (password[i] == password[i + 1])
        {
            countofduplicates++;
        }
    }
    //    if(password.length()>=8 && countoflower>1 && countofupper>1 && countofdigits>1 && countofspecial>1 && countofduplicates==0)
    //    {
    //        return true;
    //    }
    //    else{
    //        return false;
    //    }
    cout << countoflower << " " << countofupper << " " << countofdigits << countofspecial << countofduplicates;

    return true;
}
int main()
{
    string anmol = "IloveLe3tcode!";
    bool res = strongPasswordCheckerII(anmol);

    if(res)
    cout << endl << "trueee";

    return 0;
}