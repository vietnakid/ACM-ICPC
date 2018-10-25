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
#define INFLL 1e18+7
#define esp 1e-9
#define PI 3.14159265

ll nMod = 1e9 + 7;

inline ll GCD(ll a, ll b) {while (b != 0) {ll c = a % b; a = b; b = c;} return a;};
inline ll LCM(ll a, ll b) {return (a / GCD(a,b)) * b;};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    vi round;
    int a = 1, b = 1, t = 1, c;
    while (t <= 101017) {
        round.push_back(t);
        c = 2*a + 2*b + 2;
        t += c;
        a += 2; b++;
        // cerr << t << endl;
    }
    int n;
    while (cin >> n) {
        if (n == 1) {
            cout << "0 0" << endl;
            continue;
        }
        int i = 0;
        while (round[i] < n) {
            i++;
        }
        int num = round[i-1] + 1;
        int x = i-1, y = 1;
        // cerr << i << " " << x <<  " " << y << " " << num << endl;
        vi dx = {-1, -1, 0, 1, 1, 0};
        vi dy = {1, 0, -1, -1, 0, 1};
        FOR(p, 0, 6) {
            int r = 0;
            if (p == 0) {
                r = max(min(n - num, i-1), 0);
            } else {
                r = max(min(n - num, i), 0);
            }
            
            x += r*dx[p];
            y += r*dy[p];
            num += r;
        }

        cout << x << " " << y << endl;
    }
    return 0;
}