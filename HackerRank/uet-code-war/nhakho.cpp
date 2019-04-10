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

int n, m;
vvi arr(5005);
// vvi d(5005, vi(5005, INF));
int d[5005];
bitset<5005> inqueue;
priority_queue <ii, vector<ii>, greater<ii> > pq;

// void dijkstra(int node) {
//     while (pq.size()){
//         int u = pq.top().second;
//         int du = pq.top().first;
//         pq.pop();
//         if (du!=d[node][u]) continue;

//         for (auto v : arr[u])
//         {
//             if (d[node][v] > du+1) {
//                 d[node][v]=du+1;
//                 pq.push({d[node][v], v});
//             }
//         }
//     }
// }

void bellman(int u){
    int i, v, uv;
    queue<int> qu;

    for (i=1; i<=n; i++) d[i]=1000111000;
    d[u]=0;
    qu.push(u); inqueue[u]=true;

    while (qu.size()){
        u=qu.front(); inqueue[u]=false;
        qu.pop();

        for (auto v : arr[u]) {
            if (d[v]>d[u]+1){
                d[v]=d[u]+1;
                if (!inqueue[v]){
                    qu.push(v);
                    inqueue[v]=true;
                }
            }
        }
    }
}

void vietnakid() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        arr[u].push_back(v);
        arr[v].push_back(u);
    }
    int res = INF;
    for (int i = 1; i <= n; i++) {
        // d[i][i] = 0;
        // pq.push({0, i});
        bellman(i);
        int rr = 0;
        for (int j = 1; j <= n; j++) {
            if (i != j) {
                rr = max(rr, d[j]);
                // cerr << i << " " << j << " " << d[i][j] << "\n";
            }
        }
        res = min(res, rr);
    }
    printf("%d\n", res);
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