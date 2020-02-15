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

const ll nMax = 1e6 + 5;

unsigned long long phi[nMax], leng[nMax];
bool state[nMax];

void generatePhi() {
    phi[1] = 0;
    for (int i = 2; i < nMax; i++) {
        if(!phi[i]) {
            phi[i] = i-1;
            for(int j = (i << 1); j < nMax; j += i) {
                if(!phi[j]) phi[j] = j;
                phi[j] = phi[j] * (i-1) / i;
            }
        }
    }
}

void generateLeng() {
    
    for (int i = 0; i < nMax; i++) {
        int res = 0;
        int x = i;
        while (x > 0) {
            res++;
            x /= 10;
        }
        leng[i] = res;
    }
}

void vietnakid() {
    generatePhi();
    generateLeng();
    // cerr << phi[9] << " " << leng[999] << "\n";
    state[1] = true;
    for (int i = 2; i < nMax; i++) {
        int cnt = state[i-1] + state[i - phi[i]] + state[i - leng[i]];
        if (cnt == 3) state[i] = false;
        else state[i] = true;
    }
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (state[x]) {
            cout << "BACH\n";
        } else {
            cout << "KHOA\n";
        }
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