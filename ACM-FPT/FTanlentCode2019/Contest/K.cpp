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

vi IT(4*10005, 0);
vi lazy(4*10005, 0);

void setMaxIT(int node, int left, int right, int l, int r, int h) {
    if (left > r || right < l) return;
    IT[node] = max(IT[node], lazy[node]);
    if (left < right) {
        lazy[node*2+1] = max(lazy[node*2+1], IT[node]);
        lazy[node*2+2] = max(lazy[node*2+2], IT[node]);
    }

    if (left >= l && r >= right) {
        IT[node] = max(IT[node], h);
        if (left < right) {
            lazy[node*2+1] = max(lazy[node*2+1], h);
            lazy[node*2+2] = max(lazy[node*2+2], h);
        }
        // cerr << node << " " << left << ' ' << right << '\n';
        return;
    } 

    int mid = (left+right) / 2;
    setMaxIT(node*2+1, left, mid, l, r, h);
    setMaxIT(node*2+2, mid+1, right, l, r, h);
}

int getMaxIT(int node, int left, int right, int index) {
    IT[node] = max(IT[node], lazy[node]);
    if (left < right) {
        lazy[node*2+1] = max(lazy[node*2+1], IT[node]);
        lazy[node*2+2] = max(lazy[node*2+2], IT[node]);
    }

    if (index == left && right == index) {
        return IT[node];
    }

    if (left >= right)
        return 0;
    if (index > right || index < left)
        return 0;
    
    int mid = (left+right) / 2;
    int leftRes = getMaxIT(node*2+1,left, mid, index);
    int rightRes = getMaxIT(node*2+2, mid+1, right, index);
    return max(leftRes, rightRes);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    // freopen("/Users/macbook/Desktop/MyCPPLibrary/error", "w", stderr);
    int l, h, r;
    while (cin >> l >> h >> r) {
        setMaxIT(0, 0, 10000, l, r-1, h);
    }
    int oldMax = 0;
    // @TODO edit i
    for (int i = 0; i <= 10000; i++) {
        int curMax = getMaxIT(0, 0, 10000, i);
        if (curMax != oldMax) {
            oldMax = curMax;
            cout << i << " " << curMax << "\n";
        }
        // cerr << i << " " << curMax << "\n";
    }
    return 0;
}