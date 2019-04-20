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

int pow2[21];
int eulerVec[200005];
map<int, vi> posVal;

struct RMQ {
    vvi array;
    int n = 0, k = 0, value;

    RMQ() {};
    RMQ(int _value) {
        value = _value;
        n = posVal[value].size();
        if (n == 0) return;
        k = log2(n);
        array.resize(n+1);
        for (int i = 0; i <= n; i++) {
            array[i].resize(k+1);
        }
    }

    void construct() {
        for (int i = 0; i < n; i++) {
            // cerr << "value = " << value << ": i = " << i << " | " << posVal[value][i] << " " << eulerVec[posVal[value][i]] << "\n";
            array[i][0] = eulerVec[posVal[value][i]];
        }
        for (int j = 1; j <= k; j++) {
            for (int i = 0; i + pow2[j] - 1 < n; i++) {
                array[i][j] = min(array[i][j-1], array[i + pow2[j-1]][j-1]);
            }
        }
    }

    int calRMQ(int l, int r) {
        // cerr << "CalRMQ// value = " << value << " k = " << k << " " << " l = " << l << " r = " << r << "\n";
        int leng = r-l+1;
        int near2 = (int)log2(leng);
        // cerr << "near2 = " << near2  << " | r.. = " << r-pow2[near2]+1 << " | arr[l][near2] = " << array[l][near2] << " | arr[r..] " << array[r-pow2[near2]+1][near2] << "\n";
        return min(array[l][near2], array[r-pow2[near2]+1][near2]);
    }

};

map<int, RMQ> rmq;
int n, q;
Trie * root;
int w[200005];
vvi arr;
int indexVec[200005];
ii manager[200005];
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
    int left = distance(posVal[xorMax].begin(), lower_bound(posVal[xorMax].begin(), posVal[xorMax].end(), l));
    int right = distance(posVal[xorMax].begin(), (upper_bound(posVal[xorMax].begin(), posVal[xorMax].end(), r)) - 1);
    int minPos = rmq[xorMax].calRMQ(left, right);
    // int minPos2 = INF;
    // for (set<int>::iterator it = node->pos.lower_bound(l); it != node->pos.upper_bound(r); it++) {
    //     minPos2 = min(minPos2, eulerVec[*it]);
    // }
    // if (minPos != minPos2) {
    //     cerr << "u = " << u << " | k = " << k << " : xorMax = " << xorMax << " | minPos= " << minPos << " " << minPos2 << "\n";
    //     cerr << "l =  " << l << " r = " << r << " || left = " << left << " - right = " << right << "\n"; 
    //     assert(0);
    // }
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

void initRMQ() {
    for (int i = 1; i <= n; i++) {
        posVal[w[eulerVec[i]]].push_back(i);
    }
    for (auto pv : posVal) {
        int value = pv.first;
        // cerr << value << " " << posVal[value].size() << "\n";
        rmq[value] = RMQ(value);
        rmq[value].construct();
    }
}

void vietnakid() {
    pow2[0] = 1;
    for (int i = 1; i < 21; i++) {
        pow2[i] = pow2[i-1]*2;
    }
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
        initRMQ();
        

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