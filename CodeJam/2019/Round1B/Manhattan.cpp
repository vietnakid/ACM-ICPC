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

int n, q;
int hor[100005], ver[100005];

void vietnakid() {
    int TC; cin >> TC;
    for (int tc = 1; tc <= TC; tc++) {
        cin >> n >> q;
        memset(hor, 0, sizeof(hor));
        memset(ver, 0, sizeof(ver));
        for (int i = 0; i < n; i++) {
            int x, y; char d;
            cin >> x >> y >> d;
            switch (d) {
                case 'N':
                    ver[y+1]++;
                    break;
                case 'S':
                    ver[0]++;
                    ver[y]--;
                    break;
                case 'E':
                    hor[x+1]++;
                    break;
                case 'W':
                    hor[0]++;
                    hor[x]--;
                    break;
            }
        }
        int resx = 0, resy = 0;
        
        for (int i = 1; i <= q; i++) {
            hor[i] += hor[i-1];
            ver[i] += ver[i-1];
            if (hor[i] > hor[resx]) resx = i;
            if (ver[i] > ver[resy]) resy = i;
        }
        cout << "Case #" << tc << ": " << resx << " " << resy << "\n";
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