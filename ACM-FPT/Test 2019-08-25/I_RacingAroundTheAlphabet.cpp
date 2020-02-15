#include <bits/stdc++.h>
#include <unistd.h>

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

int pos[256];

void init() {
    for (int i = 'A'; i <= 'Z'; i++) {
        pos[i] = i - 'A';
    }
    pos[' '] = 26;
    pos['\''] = 27;
}

void vietnakid() {
    init();
    int n; cin >> n;
    string s;
    getline(cin, s);
    double circumference = 30. * 2 * PI;
    double t = (circumference / 28.);
    for (int i = 0; i < n; i++) {
        getline(cin, s);
        int leng = s.size();
        double totalLeng = 0;
        for (int i = 0; i < leng - 1; i++) {
            int _min = min(pos[s[i]], pos[s[i + 1]]);
            int _max = max(pos[s[i]], pos[s[i + 1]]);
            totalLeng += min(_max - _min, _min + 28 - _max);
        }
        double res = (totalLeng / 15.)*t + leng;
        printf("%.10lf\n", res);
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