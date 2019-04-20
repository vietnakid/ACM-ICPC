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

struct Trie {
    set<int> pos;
    Trie * left, *right;
    Trie() {
        left = NULL;
        right = NULL;
        pos.insert(INF);
    }
};

int n, q;
Trie * root;
int w[100005];
vvi arr;
int indexVec[100005];
ii manager[100005];
int eulerVec[100005];
int cntVec;

const int maxBit = 20;

void putTrie(int value, int pos) {
    Trie* node = root;
    node->pos.insert(pos);
    for (int i = maxBit; i >= 0; i--) {
        if ((value >> i) & 1) {
            if (!node->right) {
                node->right = new Trie();
            }
            node = node->right;
            node->pos.insert(pos);
        } else {
            if (!node->left) {
                node->left = new Trie();
            }
            node = node->left;
            node->pos.insert(pos);
        }
    }
}

ii getTrie(int u, int k) {
    int l = manager[u].first;
    int r = manager[u].second;
    int xorMax = 0;
    Trie* node = root;
    // cerr << "Query: " << u << " ; l, r = " << l << " " << r << " |  k = " << k << "\n";
    for (int i = maxBit; i >= 0; i--) {
        if ((k >> i) & 1) {
            // cerr << "bit " << i << " = 1 \n";
            if (node->left && *node->left->pos.lower_bound(l) <= r) {
                xorMax |= 0 << i;
                node = node->left;
                // cerr << "Go to left\n";
            } else if (node->right && *node->right->pos.lower_bound(l) <= r) {
                xorMax |= 1 << i;
                node = node->right;
                // cerr << "Go to right\n";
            } else {
                assert(0);
            }
        } else {
            // cerr << "bit " << i << " = 0 \n";
            if (node->right && *node->right->pos.lower_bound(l) <= r) {
                xorMax |= 1 << i;
                node = node->right;
                // cerr << "Go to right\n";
            } else if (node->left && *node->left->pos.lower_bound(l) <= r) {
                xorMax |= 0 << i;
                node = node->left;
                // cerr << "Go to left\n";
            } else {
                assert(0);
            }
        }
    }
    int minPos = INF;
    for (set<int>::iterator it = node->pos.lower_bound(l); it != node->pos.upper_bound(r); it++) {
        minPos = min(minPos, eulerVec[*it]);
    }
    return {xorMax, minPos};
}

void eulerTour(int u, int father) {
    cntVec++;
    eulerVec[cntVec] = u;
    indexVec[u] = cntVec;
    int startManager = cntVec;
    for (auto v : arr[u]) {
        if (v != father) {
            eulerTour(v, u);
        }
    }
    manager[u] = {startManager, cntVec};
}

void vietnakid() {
    int TC;
    scanf("%d", &TC);
    while (TC--) {
        scanf("%d %d", &n, &q);   
        root = new Trie();
        arr.clear(); arr.resize(n+1);
        cntVec = 0;

        for (int i = 1; i <= n; i++) {
            scanf("%d", &w[i]);   
        }
        for (int i = 1; i < n; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            arr[u].push_back(v);
            arr[v].push_back(u);
        }
        eulerTour(1, 0);
        for (int i = 1; i <= n; i++) {
            putTrie(w[i], indexVec[i]);
        }

        int xorMax = 0, posMin = 0;
        for (int i = 0; i < q; i++) {
            int u, k;
            scanf("%d %d", &u, &k);
            u ^= posMin; k ^= xorMax;
            ii res = getTrie(u, k);
            xorMax = res.first ^ k;
            posMin = res.second;
            printf("%d %d\n", posMin, xorMax);
        }
    }
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