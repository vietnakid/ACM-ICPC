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

ll n, k, done = 0, cur = 0;
vl arr(1005), brr(1005), q(105, -1);
queue<int> fp;
set<int> res;

void vietnakid() {
	cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < k; i++) fp.push(i);
    while (done < n) {
        while (!fp.empty() && cur < n) {
            int u = fp.front(); fp.pop();
            q[u] = cur;
            cur++;
        }
        int _done = done;
        for (int i = 0; i < k; i++) {
            if (q[i] != -1) {
                brr[q[i]]++;
                if (brr[q[i]] == floor(100*double(_done)/double(n) + 0.5)) {
                    res.insert(q[i]);
                    // cerr << q[i] << " - " << brr[q[i]] << " / " << arr[q[i]] << "\t\t| done = " << _done << " : " << floor(100*double(_done)/double(n) + 0.5) << "\n";
                }
                    
                if (brr[q[i]] == arr[q[i]]) {
                    done++;
                    fp.push(i);
                    q[i] = -1;
                }
            }
        }
    }
    cout << res.size() << "\n";
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