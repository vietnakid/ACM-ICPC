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
    for (__typeof(b) i = (a); i < (b); i++)
#define FORE(i, a, b) \
    for (__typeof(b) i = (a); i <= (b); i++)
#define FORD(i, a, b) \
    for (__typeof(b) i = (a); i >= (b); i--)
#define REP(i, begin, end) \
    for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))


#define INF 1000000007
#define INFLL 1000000000000000000
#define esp 1e-9
#define PI 3.14159265

ll nMod = 1e9 + 7;

inline ll GCD(ll a, ll b) {while (b != 0) {ll c = a % b; a = b; b = c;} return a;};
inline ll LCM(ll a, ll b) {return (a / GCD(a,b)) * b;};

int k, s, ma, mb;
int S, MA, MB;
vector<char> arr;

void solve() {
    int ra = k, rb = k, pa = 0, pb = 0;
    ma = -1, mb = -1, s = -1;
    FORE(i, 1, 2*k) {
        if (i % 2 != 0) {
            ra--;
            pa += (arr[i] == 'E');
        } else {
            rb--;
            pb += (arr[i] == 'E');
        }
        int ha = pa + ra;
        int hb = pb + rb;
        if (pa > hb || pb > ha) {
            s = i;
            ma = pa;
            mb = pb;
            break;
        }
    }
    if (ma == -1) {
        ma = pa;
        mb = pb;
        s = 2*k;
    }
    
}

int check(int leng) {
    int cnt = 0;
    vector<char> brr = arr;
    FOR(i, 0, 1 << leng) {
        arr = brr;
        FOR(j, 0, leng) {
            int x = (i >> j) & 1;
            if (x == 0)
                arr.push_back('N');
            else
                arr.push_back('E');
        }
        solve();
        if (s == S && ma == MA && mb == MB) {
            cnt++;
            // REP(i, arr.begin(), arr.end()) {
                //cerr << *i << " ";
            // }
            //cerr << endl;
        }
    }
    return cnt;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    // freopen("/Users/macbook/Desktop/MyCPPLibrary/error", "w", stderr);
    int TC; cin >> TC;
    while (TC--) {
        cin >> k;
        arr.resize(2*k+1);
        FORE(i, 1, 2*k) {
            cin >> arr[i];
        }
        solve();
        S = s;
        MA = ma;
        MB = mb;
        vector<char> brr = arr;

        //cerr << s << " ma mb " << ma << " " << mb << endl;

        int h = 1 << (2*k - s);
        FORE(i, 0, S) {
            arr.resize(1);
            arr[0] = 'A';
            
            FORE(j, 1, i) {
                arr.push_back(brr[j]);
            }

            // REP(i, arr.begin(), arr.end()) {
                //cerr << *i << " ";
            // }
            //cerr << endl;

            if (check(2*k - i) == h) {
                cout << S << " " << i << endl;
                break;
            }
            //cerr << endl << endl;
        }
    }
    return 0;
}