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
string a, b;
int arr[5005];
int cnt[4];

void vietnakid() {
	cin >> n;
    cin >> a >> b;
    for (int i = 0; i < n; i++) {
        int value = (b[i]-'0')*2 + (a[i] - '0');
        cnt[value]++;
        arr[i] = value;
    }
    for (int c1 = 0; c1 <= cnt[1]; c1++) {
        for (int c2 = 0; c2 <= cnt[2]; c2++) {
            int c3 = c2 + cnt[3] - c1;
            if (c3 % 2 == 0) {
                c3 /= 2;
                if (c3 <= cnt[3] && c3 >= 0 && c1 + cnt[2] - c2 + c3 <= n/2 && cnt[1] - c1 + c2 + cnt[3] - c3 <= n/2) {
                    // if (n == 4990) {
                    //     cout << cnt[1] << " " << cnt[2] << " " << cnt[3] << "\n";
                    //     cout << c1 << " " << c2 << " " << c3 << "\n";
                    // }
                    // cout << c1 << " - " << cnt[2] - c2 << "  - " << c3 << "\n";
                    int n1 = c1;
                    for (int i = 0; i < n && n1 > 0; i++) {
                        if (arr[i] == 1) {
                            cout << i+1 << " ";
                            n1--;
                        }
                    }
                    int n2 = cnt[2] - c2;
                    for (int i = 0; i < n && n2 > 0; i++) {
                        if (arr[i] == 2) {
                            cout << i+1 << " ";
                            n2--;
                        }
                    }

                    int n3 = c3;
                    for (int i = 0; i < n && n3 > 0; i++) {
                        if (arr[i] == 3) {
                            cout << i+1 << " ";
                            n3--;
                        }
                    }

                    int n0 = n/2 - (c1 + cnt[2] - c2 + c3);
                    for (int i = 0; i < n && n0 > 0; i++) {
                        if (arr[i] == 0) {
                            cout << i+1 << " ";
                            n0--;
                        }
                    }
                    cout << "\n";
                    exit(0);
                }
            }
        }
    }
    cout << -1 << "\n";
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