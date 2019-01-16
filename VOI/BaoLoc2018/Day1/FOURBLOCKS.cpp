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

int m, n;
vector<string> arr(10);
int f[27][1024][1024];

int calF(int col, int stateU, int stateV) {
    if (col < 0) return 0;
    if (col == 0) return __builtin_popcount(stateV);
    if (f[col][stateU][stateV] != -1) {
        return f[col][stateU][stateV];
    }
    f[col][stateU][stateV] = 0;
    int res = __builtin_popcount(stateV) + calF(col-1, (1<<m) - 1, stateU);
    // res = max(res, __builtin_popcount(stateV) + __builtin_popcount(stateU) + calF(col-1, (1<<m) - 1, 0));
    if (stateV == 0) {
        res = calF(col-1, (1<<m) - 1, stateU);
    } else if (__builtin_popcount(stateV) >= 2) {
        for (int i = 0; i < m; i++) {
            if (stateU & (1 << i)) {
                // res = max(res, calF(col, stateU ^ (1 << i), stateV) + 1);
                if (i != m-1) {
                    if (stateU & (1 << (i+1)) && stateV & (1 << i) && stateV & (1 << (i+1))) {
                        if (arr[i][col] != '1' && arr[i+1][col] != '1' && arr[i][col+1] != '1' && arr[i+1][col+1] != '1') {
                            int _stateU = stateU ^ (1 << i);
                            _stateU = _stateU ^ (1 << (i+1));
                            int _stateV = stateV ^ (1 << i);
                            _stateV = _stateV ^ (1 << (i+1));
                            res = max(res, calF(col, _stateU, _stateV) + 16);
                        }
                    }
                }
            }
        }
    }
    f[col][stateU][stateV] = res;
    // cerr << col << " " << stateU << " " << stateV << " " << res << endl;
    return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    // freopen("/Users/macbook/Desktop/MyCPPLibrary/error", "w", stderr);
    cin >> m >> n;
    for (int i = 0; i < m; i++) {
        cin >> arr[i];
        arr[i] = '.' + arr[i] + '.';
    }
    memset(f, -1, sizeof(f));
    f[0][0][0] = 0;
    // cout << calF(4, 3, 3) << endl;
    cout << calF(n, (1<<m) - 1, 0) << endl;
    return 0;
}