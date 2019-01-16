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

struct node {
    int a, b, c;
    bool operator < (node o) const {
        return make_pair(make_pair(a, b), c) < make_pair(make_pair(o.a, o.b), o.c);
    }
    bool operator == (node o) const {
        return make_pair(make_pair(a, b), c) == make_pair(make_pair(o.a, o.b), o.c);
    }
};

map<node, int> mp;
string s;
int n;
int res = 0;
vvi arr(133000);

int da[] = {-1, -1, 1, 1, 1, -1};
int db[] = {-1, 1, -1, 1, -1, 1};
int dc[] = {1, -1, -1, -1, 1, 1};

void init() {
    int cnt = 0;
    for (int i = 0; i <= 50; i++) {
        for (int j = 0; j <= 50; j++) {
            for (int k = 0; k <= 50; k++) {
                mp[{i, j, k}] = cnt++;
            }
        }
    }
    for (int i = 0; i <= 50; i++) {
        for (int j = 0; j <= 50; j++) {
            for (int k = 0; k <= 50; k++) {
                int u = mp[{i, j, k}];
                for (int ii = 0; ii < 6; ii++) {
                    int a = i + da[ii];
                    int b = j + db[ii];
                    int c = k + dc[ii];
                    if (a >= 0 && a <= 50 && b >= 0 && b <= 50 && c >= 0 && c <= 50) {
                        int v = mp[{a, b, c}];
                        arr[u].push_back(v);
                    }
                }
            }
        }
    }
}

node analyze(string s) {
    node res = {0, 0, 0};
    for (int i = 0; i < s.size(); i += 3)
        res.a += s[i] == '*';
    for (int i = 1; i < s.size(); i += 3)
        res.b += s[i] == '*';
    for (int i = 2; i < s.size(); i += 3)
        res.c += s[i] == '*';
    return res;
}

bool isConnect(node start, node dest) {
    int maxA = max(start.a, dest.a);
    int maxB = max(start.b, dest.b);
    int maxC = max(start.c, dest.c);
    set<node> visited;
    queue<node> q;
    visited.insert(start);
    q.push(start);
    // cerr << start << " " << dest << endl;
    while (!q.empty()) {
        node u = q.front();
        q.pop();
        if (u == dest) return true;
        for (int ii = 0; ii < 6; ii++) {
            int a = u.a + da[ii];
            int b = u.b + db[ii];
            int c = u.c + dc[ii];
            if (a >= 0 && a <= maxA+5 && b >= 0 && b <= maxB+5 && c >= 0 && c <= maxC+5) {
                node v = {a, b, c};
                if (visited.count(v) == 0) {
                    visited.insert(v);
                    q.push(v);
                }
            }
        }
    }
    return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    // freopen("/Users/macbook/Desktop/MyCPPLibrary/error", "w", stderr);
    // cerr << "OK";
    // init();
    // cerr << "OK";
    cin >> s;
    node root = analyze(s);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        node index = analyze(s);
        res += isConnect(root, index);
        // cerr << res << endl;
    }
    cout << res << endl;
    return 0;
}