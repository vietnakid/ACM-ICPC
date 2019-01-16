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

vector<string> arr;
int n;
bitset<51> isFree;
bool isCycle;
int numConnected = 0, num2 = 0;
int cnt = 0;

void DFS(int u, int father) {
    isFree[u] = false;
    cnt++;
    int deg = 0;
    for (int i = 0; i < n; i++) {
        if (arr[u][i] == 'Y') {
            deg++;
            if (i != father) {
                if (!isFree[i]) isCycle = true;
                if (isFree[i])
                    DFS(i, u);
            }
        } 
    }
    if (deg > 2) {
        isCycle = true;
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    // freopen("/Users/macbook/Desktop/MyCPPLibrary/error", "w", stderr);
    cin >> n;
    arr.resize(n);
    isFree.set();
    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int i = 0; i < n; i++) {
        if (isFree[i]) {
            numConnected++;
            isCycle = false;
            cnt = 0;
            DFS(i, -1);
            if (isCycle) {
                cout << "0" << endl;
                return 0;
            }
            if (cnt > 1) num2++;
        }
    }
    ll res = 1;
    for (ll i = 2; i <= numConnected; i++) {
        res = (res * i) % nMod;
    }
    for (ll i = 0; i < num2; i++) {
        res = (res * 2) % nMod;
    }
    cout << res << endl;
    return 0;
}