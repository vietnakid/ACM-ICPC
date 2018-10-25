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

int p, n, res;
bool arr[40][40];
vi x;
vi cnt(21);
bool isFree[40];

vi ww(22, 0);

int countRes() {
    int res = x.size() - 1;
    int cc = res;
    FOR(u, p, 2*p) {
        if (cnt[u-p] < cc) continue;
        bool check = true;
        FOR(i, 1, x.size()) {
            int v = x[i];
            if (arr[u][v] == false) { 
                check = false;
                break;
            }
        }
        if (check)  {
            // cerr << u << " ";
            res++;
        }
    }
    // cerr << endl << "res =  " << res << "\nx[i] = ";
    // FOR(i, 1, x.size()) {
    //     cerr << x[i] << " ";
    // }
    
    // cerr << endl << endl;
    return res;
}

void sovle(int index, int limit) {
    if (index == limit) {
        res = max(res, countRes());
        return;
    }

    int start = x[x.size() - 1] + 1;

    if (limit - index > p - start + 1) return;

    FOR(u, start, p) {
        x.push_back(u);
        sovle(index+1, limit);
        x.pop_back();
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    int TC; cin >> TC;
    x.push_back(-1);
    while (TC--) {
        cin >> p >> n;
        memset(arr, 0, sizeof(arr));

        FOR(i, 0, p) {
            FOR(j, 0, p) {
                arr[i][j] = true;
            }
        }
        FOR(i, p, 2*p) {
            FOR(j, p, 2*p) {
                arr[i][j] = true;
            }
        }
        cnt = vi(22, 0);
        FOR(i, 0, n) {
            int x, y;
            cin >> x >> y;
            x--;
            y--;
            cnt[y]++;
            y += p;
            arr[x][y] = true;
            arr[y][x] = true;
        }
        // cerr << cnt[1] << endl;
        res = p;
        ww = vi(22, 0);
        FORD(i, 21, 0) {
            int mm = 0;
            FOR(j, 0, p) {
                if (cnt[j] == i) mm++;
            }
            ww[i] = ww[i+1] + mm;
        }
        FORD(i, p, 0) {
            if (i + ww[i] <= res) continue;
            sovle(0, i);
        }
        // cerr << x.size() << endl;
        cout << res << endl;
    }
    return 0;
}