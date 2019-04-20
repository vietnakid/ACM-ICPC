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

vector<string> arr(2005);
priority_queue<pair<ii, ii>, vector<pair<ii, ii>>, greater<pair<ii, ii>>> q;
bitset<2005> isFree[2005];
int n, m, r, c, X, Y;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};
int addL[] = {0, 0, 1, 0};
int addR[] = {0, 0, 0, 1};

bool inRange(int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= m) return false;
    return true;
}

void vietnakid() {
	cin >> n >> m;
    cin >> r >> c;
    r--; c--;
    cin >> X >> Y;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    for (int i = 0; i < n; i++) isFree[i].set();
    isFree[r][c] = false;
    q.push({{0, 0}, {r, c}});
    int res = 0;
    while (!q.empty()) {
        res++;
        pair<ii, ii> u = q.top(); 
        q.pop();
        int ux = u.second.first; int uy = u.second.second;
        // cerr << ux << " " << uy << "\n";
        for (int i = 0; i < 4; i++) {
            int x = ux + dx[i];
            int y = uy + dy[i];
            if (inRange(x, y) && arr[x][y] == '.' && isFree[x][y]) {
                int cntx = addL[i] + u.first.first;
                int cnty = addR[i] + u.first.second;
                if (cntx <= X && cnty <= Y) {
                    isFree[x][y] = false;
                    q.push({{cntx, cnty}, {x, y}});
                }
            }
        }
    }
    cout << res << '\n';
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