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

#define FOR(i, a, b) \
    for (int i = (a); i < (b); i++)
#define FORE(i, a, b) \
    for (int i = (a); i <= (b); i++)
#define FORD(i, a, b) \
    for (int i = (a); i >= (b); i--)

#define INF 1e9+7
#define INFLL 1e18+7
#define esp 1e-9
#define PI 3.14159265

ll nMod = 1e9 + 7;

inline ll GCD(ll a, ll b) {while (b != 0) {ll c = a % b; a = b; b = c;} return a;};
inline ll LCM(ll a, ll b) {return (a / GCD(a,b)) * b;};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    while (true) {
        string s;
        getline(cin ,s);
        stringstream ss(s);
        int n;
        ss >> n;
        if (n == 0) { 
            break;
        }
        vector<string> arr(n);
        vii brr(n);
        FOR(i, 0, n) {
            getline(cin, arr[i]);
            brr[i] = {24, 0};
            FOR(j, 0, 25) {
                if (arr[i][j] != 'X') {
                    brr[i].first = j - 1;
                    break;
                }
            }

            FORD(j, 24, 0) {
                if (arr[i][j] != 'X') {
                    brr[i].second = j + 1;
                    break;
                }
            }
            // cerr << brr[i].first << " " << brr[i].second << endl;
        }
        FOR(res, 0, 24) {
            bool check = false;
            FOR(i, 0, n) {
                if (brr[i].first + res >= brr[i].second - 1) {
                    check = true;
                    break;
                }
            }
            if (check) {
                // cerr << "res = " << res << endl;
                int r = 0;
                FOR(i, 0, n) {
                    int x = brr[i].second - 1 - (brr[i].first + res);
                    if (x < 0) x = 0;
                    r += x;
                }
                cout << r << endl;
                break;
            }
        }
    }
    return 0;
}