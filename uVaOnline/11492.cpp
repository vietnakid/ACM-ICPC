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
#define INFLL 2e18
#define esp 1e-9
#define PI 3.14159265

ll nMod = 1e9 + 7;

inline ll GCD(ll a, ll b) {while (b != 0) {ll c = a % b; a = b; b = c;} return a;};
inline ll LCM(ll a, ll b) {return (a / GCD(a,b)) * b;};

int n;
vector< vector< pair<int, string> > > arr;
int dst, src;
map<string, int> mp;
int cnt;
priority_queue<pair<int, ii>, vector<pair<int, ii> >, greater<pair<int, ii> > > pq;
vvi dist;
const int MAXN = 4100;

int getIndex(string & a) {
    int res = 0;
    if (mp.find(a) == mp.end()) {
        cnt++;
        mp[a] = cnt;
        res = cnt;
    } else {
        res = mp[a];
    }
    return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    while (true) {
        cin >> n;
        if (n == 0) {
            break;
        }
        
        mp.clear();
        cnt = 0;
        arr = vector< vector< pair<int, string> > >(MAXN);
        dist = vvi(MAXN, vi(27, INF));
        string sdst, ssrc;
        cin >> ssrc >> sdst;
        FOR(i, 0, n) {
            string a, b, s;
            cin >> a >> b >> s;
            int ia = getIndex(a);
            int ib = getIndex(b);
            arr[ia].push_back({ib, s});
            arr[ib].push_back({ia, s});
            // cerr << ia << " " << ib << " " << s << endl;
        }
        src = getIndex(ssrc);
        dst = getIndex(sdst);
        FOR(i, 0, 27) {
            dist[src][i] = 0;
        }
        pq.push({0, {src, 26}});
        while (!pq.empty()) {
            pair<int, ii> node = pq.top();
            pq.pop();
            int d = node.first;
            int u = node.second.first;
            int f = node.second.second;
            if (d > dist[u][f]) {
                continue;
            }
            // cerr << u << " " << d << " " << char(f + 'a') << endl;
            FOR(i, 0, (int)arr[u].size()) {
                int v = arr[u][i].first;
                string s = arr[u][i].second;
                char c = s[0];
                c -= 'a';
                // cerr << v << " - " << s << endl;
                if (c != f && dist[v][c] > d + s.size()) {
                    dist[v][c] = d + s.size();
                    pq.push({dist[v][c], {v, c}});
                } 
            }
        }
        int res = INF;
        FOR(i, 0, 26) {
            res = min(res, dist[dst][i]);
        }
        if (res == INF) {
            cout << "impossivel" << endl;
        } else {
            cout << res << endl;
        }
    }
    return 0;
}