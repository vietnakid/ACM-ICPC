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
string s;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    // freopen("/Users/macbook/Desktop/MyCPPLibrary/error", "w", stderr);
    cin >> n;
    n++;
    cin >> s;
    s.push_back('?');
    int cnt = 0;
    vi arr, brr;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'M') {
            cnt++;
        } else {
            if (cnt > 0) {
                arr.push_back(cnt);
            }
            cnt = 0;
        }
    }
    // for (auto a : arr) {
    //     cerr << a << " ";
    // }
    // cerr << "\n";
    cnt = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'F') {
            cnt++;
        } else {
            if (cnt > 0) {
                brr.push_back(cnt);
            }
            cnt = 0;
        }
    }
    // for (auto a : brr) {
    //     cerr << a << " ";
    // }
    // cerr << "\n";
    

    if (s[0] == 'F') {
        brr.erase(brr.begin());
    }
    if (arr.size() == 0) {
        cout << 0 << "\n";
    }  else if (arr.size() == 1) {
        cout << arr[0] << "\n";
    } else if (arr.size() == 2) {
        if (brr[0] == 1) {
            cout << arr[0] + arr[1] << "\n";
        } else {
            cout << max(arr[0], arr[1]) + 1 << "\n";
        }
    } else {
        int res = 0;
        for (int i = 0; i < arr.size() - 2; i++) {
            if (brr[i] == 1) {
                res = max(res, arr[i] + arr[i+1] + 1);
            }
        }
        cout << res << "\n";
    }
 	// cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}