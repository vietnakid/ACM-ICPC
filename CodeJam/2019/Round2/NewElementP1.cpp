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

vii arr;
int n;

void sovleAll() {
    set<ii> st;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            int x = arr[i].first-arr[j].first;
            int y = arr[j].second-arr[i].second;
            if ((x)*(y) > 0) {
                int g = GCD(x, y);
                x /= g; y /= g;
                if (x < 0) {
                    x = -x;
                    y = -y;
                }
                st.insert({x, y});
                // cerr << x << " " << y << "\n";
            }
        }
    }
    cout << st.size() + 1 << "\n";
}

void sovleTrau() {
    int cnt = 0;
    vi permu(n);
    for (int i = 0; i < n; i++) {
        permu[i] = i;
    }
    do {
        double l = 0, r = INF;
        for (int ii = 0; ii < n-1; ii++) {
            int i = permu[ii];
            int j = permu[ii + 1];
            int x = arr[i].first-arr[j].first;
            int y = arr[j].second-arr[i].second;
            if ((x == 0 && y < 0) || (y == 0 && x > 0)) r = 0;
            if (y > 0) {
                l = max(l, (double)x/y);  
            } 
            if (y < 0) {
                r = min(r, (double)x/y);
            }
            
        }
        if (r - l > esp) {
            cnt++;
            // cerr << l << " " << r << "\n";
            // for (int jj = 0; jj < n; jj++) {
            //     cerr << permu[jj] << " ";
            // }
            // cerr << "\n";
        }
    } while (next_permutation(permu.begin(), permu.end()));
    cout << cnt << "\n";
}

void vietnakid() {
    int TC; cin >> TC;
    for (int tc = 1; tc <= TC; tc++) {
        cin >> n;
        
        arr.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i].first >> arr[i].second;
        }
        cout << "Case #" << tc << ": ";
        sovleAll();
        // cout << "Trau: ";
        // sovleTrau();
        
        
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