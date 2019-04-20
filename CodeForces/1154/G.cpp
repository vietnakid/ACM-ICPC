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
// vvii multi;
// vvi pos;

vii multi[10000005];
vi pos[10000005];
const int maxVal = 10000005;


void pushData(int i, int value, int pos) {
    if (multi[i].size() == 0) {
        multi[i].push_back({value, pos});
    } else if (multi[i][0].first > value) {
        multi[i][1] = multi[i][0];
        multi[i][0] = {value, pos};
    } else if (multi[i].size() == 1) {
        multi[i].push_back({value, pos});
    } else if (multi[i][1].first > value) {
        multi[i][1] = {value, pos};
    }
}

void preProcessing() {
    for (int i = 1; i < maxVal; i++) {
        for (int j = i; j < maxVal; j += i) {
            if (pos[j].size() > 0) {
                pushData(i, j, pos[j][0]);
                if (pos[j].size() == 2) {
                    pushData(i, j, pos[j][1]);
                }
            }
        }
    }
}

void vietnakid() {
    // multi.resize(maxVal);
    // pos.resize(maxVal);
	scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x; 
        scanf("%d", &x);
        if (pos[x].size() < 2)
            pos[x].push_back(i);
    }
    preProcessing();
    ll res = INFLL;
    int posRes1 = 0, posRes2;
    for (int i = 1; i <= maxVal; i++) {
        if (multi[i].size() == 2) {
            ll u = multi[i][0].first;
            ll v = multi[i][1].first;
            if (LCM(u, v) < res) {
                res = LCM(u, v);
                posRes1 = multi[i][0].second + 1;
                posRes2 = multi[i][1].second + 1;
            }
        }
    }
    // cerr << res << "\n";
    if (posRes1 > posRes2) {
        swap(posRes1, posRes2);
    }
    printf("%d %d\n", posRes1, posRes2);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	#ifdef LOCAL_KID
	freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    freopen("/Users/macbook/Desktop/MyCPPLibrary/error", "w", stderr);
	#else
	// online submission
	#endif
	vietnakid();
 	cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}