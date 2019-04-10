#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector< vector<int> > vvi;
typedef vector<ll> vl;
typedef vector< vector<ll> > vvl;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector< vii> vvii;

#define INF 1000000007
#define INFLL 1000000000000000000
#define esp 1e-9
#define PI 3.14159265

ll nMod = 1e9 + 7;

inline ll GCD(ll a, ll b) {while (b != 0) {ll c = a % b; a = b; b = c;} return a;};
inline ll LCM(ll a, ll b) {return (a / GCD(a,b)) * b;};

int n;
vi arr, Arr;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    // freopen("/Users/macbook/Desktop/MyCPPLibrary/error", "w", stderr);
    cin >> n;
    arr.resize(n);
    int mmin = INF, last = -1, cnt = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        
        cnt += arr[i] - 1;
        if (mmin > cnt) {
            mmin = cnt;
            last = i;
        }
    }
    last = (last + 1) % n;  

    vi brr;
    for (int i = last; i < n; i++) {
        brr.push_back(arr[i]);
    }
    for (int i = 0; i < last; i++) {
        brr.push_back(arr[i]);
    }
    arr = brr;
    ll res = 0;
    int pos = n-1;
    bool isOk = true;
    for (int i = n-1; i >= 0; i--) {
        if (arr[i] == 0) {
            pos = min(pos, i);
            while (pos >= 0 && arr[pos] == 0) pos--;
            if (pos < 0) {
                isOk = false;
                break;
            } 
            // cerr << i << " " << pos << "\n";
            arr[pos]--;
            res += (i - pos)*(i - pos);
        }
    }
    cout << res << "\n";
            

 	cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}