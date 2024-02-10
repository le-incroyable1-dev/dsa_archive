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
#define vi vector< ll >
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
long long powerof2[] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824,2147483648,4294967296};


/*
//OP
First of all, if an−1>an, then the answer is −1 since we can't change the last two elements.

If an≥0, there exists a simple solution: perform the operation (i,n−1,n) for each 1≤i≤n−2.

Otherwise, the answer exists if and only if the initial array is sorted.

Proof:

Assume that an<0 and we can sort the array after m>0 operations.

Consider the last operation we performed (xm,ym,zm). Since all elements should be negative 
after the last operation, so azm<0 should hold before the last operation. But axm=aym−azm>aym 
after this, so the array isn't sorted in the end. By contradiction, we have proved that we can't 
perform any operations as long as an<0.
*/

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector <int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        if (a[n - 2] > a[n - 1]) {
            cout << -1 << endl;
        } else {
            if (a[n - 1] < 0) {
                if (is_sorted(a.begin(), a.end())) {
                    cout << 0 << endl;
                } else {
                    cout << -1 << endl;
                }
            } else {
                cout << n - 2 << endl;
                for (int i = 1; i <= n - 2; ++i) {
                    cout << i << ' ' << n - 1 << ' ' << n << endl;
                }
            }
        }
    }
}


/*
//INCORRECT
void sol(vi v){

    ll nmoves = 0;
    vvi moves;

    ll n = v.size();

    if(v.at(n-2) > v.at(n-1)){
        cout << -1 << endl;
        return;
    }

    ll ax, ay, az;

    fr(i, n-2){
        ax = v.at(i);
        ay = v.at(i+1);

        ll k = i+2;

        az = v.at(k);

        if(ay<ax){
            while(k < n && az < 0){
                k++;

                if(k == n)
                break;

                az = v.at(k);
            }

            if(az < 0){
                cout << -1 << endl;
                return;
            }

            //v.at(i) = ay-az;

            vi cmove;
            cmove.pb(i);
            cmove.pb(i+1);
            cmove.pb(k);

            moves.pb(cmove);

            nmoves++;
        }
        else
        continue;
    }

    if(nmoves == 0)
    cout << 0 << endl;
    else{
        cout << nmoves << endl;
        fr(i, nmoves){
            fr(j, moves.at(i).size()){
                cout << (moves.at(i).at(j)+1) << " ";
            }
            cout << endl;
        }
    }

    return;

}

int main(void){
    fast;
    test(t){
        ll n;
        cin >> n;

        vi v;
        ll ele;
        fr(i,n){
            cin >> ele;
            v.pb(ele);
        }

        sol(v);
    }
}
*/