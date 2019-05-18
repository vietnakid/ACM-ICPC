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

int n;
int arr[200005];
vi sq;
string res;

void vietnakid() {
    cin >> n;
    for (int i = 0; i < n ; i++) cin >> arr[i];
    int l = 0, r = n-1;
    sq.push_back(0);
    while (l <= r) {
        if (arr[l] > sq.back() && arr[r] > sq.back()) {
            if (arr[l] < arr[r]) {
                sq.push_back(arr[l]);
                res.push_back('L');
                l++;
            } else if (arr[l] > arr[r]) {
                sq.push_back(arr[r]);
                r--;
                res.push_back('R');
            } else {
                int cntL = 1;
                for (int i = l+1; i < r; i++) {
                    if (arr[i] > arr[i-1]) {
                        cntL++;
                    } else {
                        break;
                    }
                }

                int cntR = 1;
                for (int i = r-1; i > l; i--) {
                    if (arr[i] > arr[i+1]) {
                        cntR++;
                    } else {
                        break;
                    }
                }
                if (cntL > cntR) {
                    for (int i = 0; i < cntL; i++) {
                        res.push_back('L');
                    }
                } else {
                    for (int i = 0; i < cntR; i++) {
                        res.push_back('R');
                    }
                }
                break;
            }
        } else if (arr[l] > sq.back()) {
            sq.push_back(arr[l]);
            res.push_back('L');
            l++;
        } else if (arr[r] > sq.back()) {
            sq.push_back(arr[r]);
            r--;
            res.push_back('R');
        } else {
            break;
        }
    }
    cout << res.size() << "\n";
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