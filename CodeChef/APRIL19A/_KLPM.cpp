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

inline ll GCD(ll a, ll b) {while (b != 0) {ll c = a % b; a = b; b = c;} return a;};
inline ll LCM(ll a, ll b) {return (a / GCD(a,b)) * b;};

string s;
int n;
uint64_t h[1005];
uint64_t base = 311;
map<uint64_t, multiset<int> > mp, mp2;
uint64_t nMod = 1e9 + 9277;
bool isPalindrome[1005][1005];
int counting[1005][1005], cntType2[1005][1005], cntType3[1005][1005];
// type 2: xp | x
// type 3: x | px
uint64_t res = 0;

uint64_t powMod(uint64_t a, uint64_t n) {
	if (n == 0 && a != 0) return 1;
    if (n == 0 && a == 0) return 0;
	if (n == 1) return a;
	uint64_t b = powMod(a, n >> 1);
	uint64_t res = (b * b) ;
	if (n & 1) res = (res * a) ;
	return res;
}

uint64_t getHash(int i, int j) {
    return (h[j] - (h[i-1] * powMod(base, j-i+1) ) + nMod)  + (j-i+1)*nMod;
}

void initDP() {
    memset(isPalindrome, false, sizeof(isPalindrome));
    for (int i = 0; i < n; i++) {
        isPalindrome[i][i] = true;
    }
    for (int k = 1; k < n; k++) {
        for (int i = 0; i < n; i++) {
            int j = k+i;
            if (j >= n) break;
            if (s[i] == s[j]) {
                if (k == 1) {
                    isPalindrome[i][j] = true;
                } else {
                    isPalindrome[i][j] = isPalindrome[i+1][j-1];
                }
            } else {
                isPalindrome[i][j] = false;
            }
        }
    }
    
}

void initCalHash() {
    for (int i = 1; i <= n; i++) {
        h[i] = (h[i-1] * base + s[i-1]) ;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            uint64_t seg = getHash(i, j);
            mp[seg].insert(j-1);
        }
    }
}

void calCounting() {
    for (int i = 1; i <= n; i++) {
        h[i] = (h[i-1] * base + s[i-1]) ;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            uint64_t seg = getHash(i, j);
            int _j = n - j;
            for (auto pos : mp[seg]) {
                if (pos < _j) {
                    res++;
                    counting[pos][_j]++; // s1 stop at pos; s2 start at _j
                    // cerr << pos << " " << _j << "\n";
                }
            }
        }
    }

    // type 2: xp | x
    // type 3: x | px

    for (int i = 0; i < n; i++) {
        cntType2[i][n-1] = counting[i][n-1];
        for (int j = n-2; j > i; j--) {
            cntType2[i][j] = cntType2[i][j+1] + counting[i][j];
        }
    }
    for (int j = n-1; j > 0 ; j--) {
        cntType3[0][j] = counting[0][j];
        for (int i = 1; i < j; i++) {
            cntType3[i][j] = cntType3[i-1][j] + counting[i][j];
        }
    }

    for (int i = 1; i < n-1; i++) {
        for (int j = i; j < n-1; j++) {
            if (isPalindrome[i][j]) {
                res += cntType2[i-1][j+1];
                // cerr << i << " " << j << " | Type 2 = " << cntType2[i-1][j+1] << "\n";
                res += cntType3[i-1][j+1];
                // cerr << i << " " << j << " | Type 3 = " << cntType3[i-1][j+1] << "\n";
            }
        }
    }
}

void vietnakid() {
    
	cin >> s;
    n = s.size();

    initDP();
    initCalHash();
    
    reverse(s.begin(), s.end());
    res = 0;
    calCounting();
    
    cout << res << "\n";
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