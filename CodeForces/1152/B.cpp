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

#define lowBit(S) (S & (-S))

inline ll GCD(ll a, ll b) {while (b != 0) {ll c = a % b; a = b; b = c;} return a;};
inline ll LCM(ll a, ll b) {return (a / GCD(a,b)) * b;};

#define isOn(S, j) (S & (1 << j))
#define setBit(S, j) (S |= (1 << j))
#define clearBit(S, j) (S &= ~(1 << j))
#define toggleBit(S, j) (S ^= (1 << j))
#define lowBit(S) (S & (-S))
#define setAll(S, n) (S = (1 << n) - 1)

int n;
int arr[25];

bool check(int n) {
    int l = log2(n);
    for (int i = l; i >= 0; i--) {
        if (((n >> i) & 1) == 0) {
            return false;
        }
    }
    return true;
}

vi step;

void vietnakid() {
    int p = 1;
    for (int i = 0; i < 25; i++) {
        p *= 2;
        arr[i] = p-1;
    }
	cin >> n;
    int l = log2(n);
    for (int i = l; i >= 0; i--) {
        // cerr << i << " th is " << ((n >> i) & 1) << "\n";
        if (((n >> i) & 1) == 0) {
            n ^= arr[i];
            // cerr << n << "\n";
            step.push_back(i+1);
            if (check(n)) {
                break;
            }
            n++;
            step.push_back(INF);
        }
    }
    cout << step.size() << "\n";
    for (int i = 0; i < step.size(); i+=2) {
        cout << step[i] << " ";
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