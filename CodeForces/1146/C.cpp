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

vi arr, brr;

void vietnakid() {
    int TC;
	cin >> TC;
    while (TC--) {
        int n; cin >> n;
        arr.clear(); brr.clear();
        arr.resize(0); brr.resize(0);
        for (int i = 2; i <= n; i++) {
            arr.push_back(i);
        }
        int mmax = 0;
        do {
            cout << 1 << " " << arr.size() << " " << 1 << " ";
            for (auto x : arr) {
                cout << x << " ";
            }
            cout << "\n";
            cout.flush();
            int leng;
            cin >> leng;
            vi _a;
            if (leng >= mmax) {
                _a = arr;    
            } else {
                _a = brr;
            }
            mmax = max(leng, mmax);
            arr.clear(); brr.clear();
            arr.resize(0); brr.resize(0);
            // cerr << leng << " -- " << _a.size() << "\n";
            for (int i = 0; i < _a.size()/2; i++) {
                arr.push_back(_a[i]);
            }
            for (int i = _a.size()/2; i < _a.size(); i++) {
                brr.push_back(_a[i]);
            }
            // cerr << arr.size() << " ?? " << brr.size() << "\n";
        } while (arr.size() != 0 && brr.size() != 0);
        // cerr << "end--" << "\n";
        if (arr.size() == 0) {
            arr = brr;
        }
        cout << 1 << " " << n-1 << " " << arr[0] << " ";
        for (int i = 1; i <= n; i++) {
            if (i != arr[0]) {
                cout << i << " ";
            }
        }
        cout << "\n";
        cout.flush();
        int leng;
        cin >> leng;
        cout << "-1 " << leng << "\n";
        cout.flush();
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	#ifdef LOCAL_KID
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    // freopen("/Users/macbook/Desktop/MyCPPLibrary/error", "w", stderr);
	#else
	// online submission
	#endif
	vietnakid();
 	cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}