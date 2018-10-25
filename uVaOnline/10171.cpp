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
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;
        vvi arr(26, vi(26, INF));
        vvi brr(26, vi(26, INF));
        FOR(i, 0, 26) {
            arr[i][i] = 0;
            brr[i][i] = 0;
        }
        FOR(i, 0, n) {
            char age, type, src, dst;
            int cost;
            cin >> age >> type >> src >> dst >> cost;
            src -= 'A';
            dst -= 'A';
            if (age == 'Y') {
                arr[src][dst] = min(arr[src][dst], cost);
                if (type == 'B') {
                    arr[dst][src] = min(arr[src][dst], cost);
                }
            } else {
                brr[src][dst] = min(brr[src][dst], cost);
                if (type == 'B') {
                    brr[dst][src] = min(brr[src][dst], cost);
                }
            }
        }
        char men1, men2;
        cin >> men1 >> men2;
        men1 -= 'A';
        men2 -= 'A';
        
        FOR(k, 0, 26) {
            FOR(i, 0, 26) {
                FOR(j, 0, 26) {
                    arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
                    brr[i][j] = min(brr[i][j], brr[i][k] + brr[k][j]);
                }
            }
        }
        int res = INF;
        FOR(k, 0, 26) {
            if (res > arr[men1][k] + brr[men2][k]) {
                res = arr[men1][k] + brr[men2][k];
            }
        }
        vi resName;
        FOR(k, 0, 26) {
            if (res == arr[men1][k] + brr[men2][k]) {
                resName.push_back(k);
            }
        }
        
        if (res == INF) {
            cout << "You will never meet." << endl;
        } else {
            cout << res;
            FOR(i, 0, resName.size()) {
                cout << " " << (char)(resName[i] + 'A');
            }
            cout << endl;
        }
    }
    return 0;
}