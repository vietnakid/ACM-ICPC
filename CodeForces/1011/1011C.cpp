#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector< vector<int> > vvi;
typedef vector<ll> vl;
typedef vector< vector<ll> > vvl;
typedef pair<double, double> ii;
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
#define esp 1e-7
#define PI 3.14159265

ll nMod = 1e9 + 7;

inline ll GCD(ll a, ll b) {while (b != 0) {ll c = a % b; a = b; b = c;} return a;};
inline ll LCM(ll a, ll b) {return (a / GCD(a,b)) * b;};

int n, m;
vii arr;

bool test(double fuel) {
    double weigth = m + fuel;
    fuel -= weigth / arr[0].first;
    if (fuel < 0) {
        return false;
    }
    weigth = m + fuel;
    
    FOR(i, 1, n) {
        // cerr << weigth << " " << fuel << endl;
        fuel -= weigth / arr[i].second;
        if (fuel < 0) {
            return false;
        }
        weigth = m + fuel;
        // cerr << weigth << " " << fuel << endl;
        fuel -= weigth / arr[i].first;
        if (fuel < 0) {
            return false;
        }
        weigth = m + fuel;
    }
    fuel -= weigth / arr[0].second;
    if (fuel < 0) {
        return false;
    }
    weigth = m + fuel;
    // cerr << weigth << " " << fuel << endl;
    return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    cin >> n >> m;
    arr = vii(n);
    FOR(i, 0, n) {
        cin >> arr[i].first;
    }
    FOR(i, 0, n) {
        cin >> arr[i].second;
    }
    double low = 0, high = INF;
    FOR(i, 0, 1000) {
        double m = (low + high) / 2.;
        // cerr << low << " " << high << endl;
        if (test(m+esp)) {
            high = m;
        } else {
            low = m+esp;
        }
    }
    // low = 10;
    if (test(low+esp)) {
        printf("%.10lf\n", low);
    } else {
        printf("-1\n");
    }
    return 0;
}