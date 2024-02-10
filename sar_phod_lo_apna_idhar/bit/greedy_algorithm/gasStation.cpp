#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define fi first
#define sec second
typedef long long ll;
typedef long double  ld;
#define pii pair<ll,ll>
#define vi vector< int >
#define vvi vector< vi >
#define vpi vector< pii >
#define vvpi vector< vpi >
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define test(t) ll t;cin>>t;while(t--)
#define mem(a,b) memset(a,b,sizeof(a))
#define inn freopen("input.txt", "r", stdin)
#define outt freopen("output.txt", "w", stdout)
#define all(arr) arr.begin(),arr.end()
#define fr(i,n) for(ll i=0;i<(n);++i)
#define rep(i,a,b) for(ll i=a;i<=b;++i)
#define per(i,a,b) for(ll i=a;i>=b;i--)
#define remin(a,b) (a=min((a),(b)))
#define remax(a,b) (a=max((a),(b)))
//#define ln ListNode*
//#define itr(type) type::iterator itr
long long powerof2[] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824,2147483648,4294967296};

/*
98 204 918 18 17 35 739 913 14 76 555 333 535 653 667 52 987 422 553 599 765 494 298 16 285 272 485 989 627 422 399 258 959 475 983 535 699 663 152 606 406 173 671 559 594 531 824 898 884 491 193 315 652 799 979 890 916 331 77 650 996 367 86 767 542 858 796 264 64 513 955 669 694 382 711 710 962 854 784 299 606 655 517 376 764 998 244 896 725 218 663 965 660 803 881 482 505 336 279
98 273 790 131 367 914 140 727 41 628 594 725 289 205 496 290 743 363 412 644 232 173 8 787 673 798 938 510 832 495 866 628 184 654 296 734 587 142 350 870 583 825 511 184 770 173 486 41 681 82 532 570 71 934 56 524 432 307 796 622 640 705 498 109 519 616 875 895 244 688 283 49 946 313 717 819 427 845 514 809 422 233 753 176 35 76 968 836 876 551 398 12 151 910 606 932 580 795 187
*/

/*

Try to find the relation between sum of gas and sum of cost for solution to exist.

When will you shift your starting point from 0?
Do you really need to cover every starting point? How can you use answer of above question to optimize this part?

The bruteforce solution should be obvious. Start from every i, and check to see if every point is reachable with the gas 
available. Return the first i for which you can complete the trip without the gas reaching a negative number.
This approach would however be quadratic.

Lets look at how we can improve.
1) If sum of gas is more than sum of cost, does it imply that there always is a solution ?
2) Lets say you start at i, and hit first negative of sum(gas) - sum(cost) at j. We know TotalSum(gas) - TotalSum(cost) > 0. 
What happens if you start at j + 1 instead ? Does it cover the validity clause for i to j already ?

*/

int canCompleteCircuit(const vector<int> &A, const vector<int> &B) {

       int asum=0,bsum=0;
    int n=A.size();
    for(int i=0;i<n;i++){
        asum+=A[i];
        bsum+=B[i];
    }
    if(asum<bsum){
        return -1;
    }
//otherwise, at every index check whether can the car move forward/not?
//Maintain index, and sum, and set them to zero. Then check A[index]-B[index] if it <0 then we cant move further so this index is not suitable. Make ans=ans+1 as next maybe possible.
    int sum=0,ans=0,pos=0;
    while(pos<n){
        sum+=(A[pos]-B[pos]);
        if(sum<0){
            ans=pos+1;
            ans=ans%n;
            sum=0;
        }
        pos+=1;
    }
    return ans;

}
