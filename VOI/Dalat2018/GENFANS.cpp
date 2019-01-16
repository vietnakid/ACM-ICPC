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

ll n, sum, minsum, maxsum;
string s = "";

void generate(int pos) {
    int k = rand() % 2;
    while (true) {
        int h = k == 1 ? 1 : - 1;
        ll _sum = sum + h;
        ll _minsum = min(_sum, minsum);
        ll _maxsum = max(_sum, maxsum);
        // cerr << h << " " << k << " " << _maxsum << " " << _minsum << " " << sum << endl;
        if (abs(_minsum - _maxsum) <= 2) {
            break;
        }
        k = rand() % 2;
    }
    // cerr << pos << " " << k << endl;
    int h = k == 1 ? 1 : - 1;
    sum += h;
    minsum = min(sum, minsum);
    maxsum = max(sum, maxsum);
    if (k == 0) s.push_back('V');
    else s.push_back('M');

    if (pos == n) {
        return;
    } else {
        generate(pos+1);
    }
    
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	freopen("/Users/macbook/Desktop/PREVOIDALAT2018/FANS/Test20/FANS.INP", "w", stdout);
    freopen("/Users/macbook/Desktop/MyCPPLibrary/error", "w", stderr);
    srand(time(NULL));
    ll numtest = 20;
    cout << numtest << endl;
    for (int tc = 0; tc < numtest; tc++) {
        n = rand() % 100 + 100;
        // ll m = rand() % (1000000000 - 5) + 5;
        // while (m < 100) {
        //     m = rand() % 1000000000;
        // }
        ll m = 0;
        sum = 0;
        minsum = 0;
        maxsum = 0;
        s = "";
        generate(1);

        cout << n << " " << m << endl;
        cout << s << endl;
    }
    return 0;
}