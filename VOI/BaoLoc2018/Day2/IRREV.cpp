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
ll n, m;
vi arr;
int nMax = 1e5 + 5;
vi divisor(100005, 0);
map<int, int> divisorM;
vi primes;
int divisor_nCk[100005];

void test() {
    arr.push_back(0);
    arr.push_back(1);
    for (int i = 1; i <= n; i++) {
        vi brr;
        brr.push_back(0);
        for (int j = 1; j <= i; j++) {
            brr.push_back((arr[j] + arr[j-1]) % m);
        }
        brr.push_back(1);
        arr = brr;
        // for (auto x : arr) {
        //     cerr << x << " ";
        // }
        // cerr << endl;
    }
}

void sieveOfPrimes() {
    for (ll i = 2; i < nMax; i++) {
        if (divisor[i] == 0) {
            primes.push_back(i);
            ll j = (ll)i + (ll)i;
            while (j <= nMax) {
                divisor[j] = i;
                j += i;
            }
        }
    }
}

map<int, int> phanTich(ll m) {
    // cerr << "phan tich " << m << endl;
    map<int, int> res;
    if (m >= nMax) {
        for (int i = 0; primes[i] * primes[i] <= m && i < primes.size(); i++) {
            while (m % primes[i] == 0) {
                res[primes[i]]++;
                m /= primes[i];
            }
        }
        if (m > 1) {
            res[m]++;
        }
    } else {
        while (divisor[m] != 0) {
            res[divisor[m]]++;
            m /= divisor[m];
        }
        if (m > 1) {
            res[m]++;
        }
    }
    // for(auto & x : divisor) {
    //     int u = x.first;
    //     int v = x.second;
    //     cerr << u << " " << v << endl;
    // }
    // cerr << endl;
    return res;
}

void loaibo(map<int, int> & divi, int s) {
    for(auto & x : divi) {
        int u = x.first;
        int v = x.second;
        divisor_nCk[u] += s*v;
        // cerr << "loai bo: " << u << " " << v << " " << s << endl;
    }
}

void init() {
    sieveOfPrimes();
    divisorM = phanTich(m);
    memset(divisor_nCk, 0, sizeof(divisor_nCk));
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    // freopen("/Users/macbook/Desktop/MyCPPLibrary/error", "w", stderr);
    cin >> n >> m;
    n--;
    // test();
    init();
    vi res;
    for (int k = 1; k < n; k++) {
        // cerr << "k = " << k << endl;
        map<int, int> divi;
        // cong ++ phan tich (n - k + 1)
        divi = phanTich(n-k+1);
        loaibo(divi, 1);
        // cong ++ phan tich (k - 1)
        divi = phanTich(k);
        loaibo(divi, -1);
        bool check = true;
        // cerr << "nCk: ";
        // for (int i = 1; i <= n; i++) {
        //     cerr << divisor_nCk[i] << " ";
        // }
        // cerr << endl;
        for(auto & x : divisorM) {
            int u = x.first;
            int v = x.second;
            // cerr << u << " " s<< v << " " << divisor_nCk[u] << " " << k << endl;
            if (u >= nMax) {
                check = false;
                break;
            }
            if (divisor_nCk[u] < v) {
                check = false;
                break;
            }
        }
        if (check) {
            res.push_back(k+1);
        }
    }
    cout << res.size() << endl;
    for (auto & x:res) {
        cout << x << '\n';
    }
    return 0;
}