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

vl root, compareRoot;
int n, m;


int getRoot(int u) {
    if (root[u] == -1) return u;
    
    int v = getRoot(root[u]);
    compareRoot[u] += compareRoot[root[u]];
    root[u] = v;
    return root[u];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    // freopen("/Users/macbook/Desktop/MyCPPLibrary/error", "w", stderr);
    while (scanf("%d %d", &n, &m)) {
        if (n == 0 && m == 0) break;
        root.clear();
        compareRoot.clear();
        root.resize(n+1, -1);
        compareRoot.resize(n+1, 0);
        for (int i = 0; i < m; i++) {
            char ch;
            int a, b, c;
            scanf("%c%c", &ch, &ch);
            if (ch == '!') {
                scanf("%d %d %d", &a, &b, &c);
                int rootA = getRoot(a);
                int rootB = getRoot(b);
                if (rootA != rootB) {
                    root[rootB] = rootA;
                    compareRoot[rootB] = -compareRoot[b] + compareRoot[a] + c;
                }
                // cerr << rootB << " " << getRoot(rootB) << " " << compareRoot[rootB] << endl;
            } else {
                scanf("%d %d", &a, &b);
                int rootA = getRoot(a);
                int rootB = getRoot(b);
                if (rootA != rootB) {
                    printf("UNKNOWN\n");
                } else {
                    printf("%lld\n", compareRoot[b] - compareRoot[a]);
                }
            }
        }
    }
    return 0;
}