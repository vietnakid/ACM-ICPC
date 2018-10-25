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

const int nMax = 5842;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    set<ll> q1, q2;
    vl q;
    q2.insert(1);
    while (q1.size() < nMax) {
        ll x = *q2.begin();
        q2.erase(q2.begin());
        q1.insert(x);
        q2.insert(x*2);
        q2.insert(x*3);
        q2.insert(x*5);
        q2.insert(x*7);
    }
    FOR(i, 0, nMax){
        ll x = *q1.begin();
        q1.erase(q1.begin());
        q.push_back(x);
    }
    while (true) {
        int n; cin >> n;
        if (n == 0) {
            break;
        }
        int r = n % 10;
        string s = "th";
        if (n % 100 < 10 || n % 100 > 13) {
            if (r == 1) {
                s = "st";
            } else if (r == 2) {
                s = "nd";
            } else if (r == 3) {
                s = "rd";
            }
        }
        
        cout << "The " << n << s << " humble number is " << q[n-1] << "." << endl;
    }
    return 0;
}