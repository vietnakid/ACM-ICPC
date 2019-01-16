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

struct trie {
    trie * child[2];

    trie() {
        memset(child, 0, sizeof(child));
    }
};

trie * root;
int n, m;

void addTrie(int x) {
    trie * node = root;
    for (int i = 29; i >= 0; i--) {
        int u = (x >> i) & 1;
        // cerr << x << " " << i << " " << u << " " << node << endl;
        if (node->child[u] == NULL) {
            node->child[u] = new trie;
        }
        node = node->child[u];
    }
}

int findTrie(int x) {
    int res = 0;
    trie * node = root;
    for (int i = 29; i >= 0; i--) {
        int u = ((x >> i) & 1) ^ 1;
        if (node->child[u] == NULL) {
            u ^= 1;
        }
        res += u * (1 << i);
        node = node->child[u];
    }
    return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    // freopen("/Users/macbook/Desktop/MyCPPLibrary/error", "w", stderr);
    root = new trie;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        addTrie(x);
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        int x; cin >> x;
        int res = findTrie(x);
        cout << res << endl;
    }
    return 0;
}