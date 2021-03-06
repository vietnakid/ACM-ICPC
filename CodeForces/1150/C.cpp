#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector< vector<int> > vvi;
typedef vector<ll> vl;
typedef vector< vector<ll> > vvl;
typedef pair<int, int> ii;
typedef vector<ii> vii;

#define FOR(i, a, b) \
    for (int i = (a); i < (b); i++)
#define FORE(i, a, b) \
    for (int i = (a); i <= (b); i++)
#define FORD(i, a, b) \
    for (int i = (a); i >= (b); i--)

#define INF 2e9 // 2e9
#define INFLL 2e18 // 2e18
#define esp 1e-9
#define PI 3.14159265

inline ll GCD(ll a, ll b) {while (b != 0) {ll c = a % b; a = b; b = c;} return a;};
inline ll LCM(ll a, ll b) {return (a / GCD(a,b)) * b;};

priority_queue< ll, vector<ll>, greater<ll> > heap;

vi primes;
int nMax = 1e6 + 1;
bitset<10000001> check;
int n;
int cnt[3];

void sieveOfPrimes() {
    check.set();
    check[0] = false;
    check[1] = false;
    for (int i = 2; i < nMax; i++) {
        if (check[i]) {
            primes.push_back(i);
            ll j = (ll)i * (ll)i;
            while (j <= nMax) {
                check[j] = false;
                j += i;
            }
        }
    }
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    sieveOfPrimes();
    cin >> n;
    for (int i = 0 ; i < n; i++) {
        int x; cin >> x; 
        cnt[x]++;
    }
    int curSum = 0, curIndex = 0;
    for (int i = 0; i < n; i++) {
        if (curSum + 2 <= primes[curIndex] && cnt[2] > 0) {
            cout << 2 << " ";
            curSum += 2;
            cnt[2]--;
        } else {
            if (cnt[1] > 0) {
                cout << 1 << " ";
                curSum += 1;
                cnt[1]--;
            }
            else if (cnt[2] > 0) {
                cout << 2 << " ";
                curSum += 2;
                cnt[2]--;
            }
        }
        if (primes[curIndex] <= curSum) {
            curIndex++;
        }
        // cerr << curSum << "\n";
    }
    cout << "\n";
    return 0;
}