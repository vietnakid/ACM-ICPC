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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    int tc = 0;
    while (true) {
        int n;
        cin >> n;
        if (n == 0) {
            break;
        }
        tc++;
        map<string, int> mp;
        int cnt = 0;
        int arr[400][400];
        vector<string> name;
        memset(arr, 0, sizeof(arr));
        FOR(i, 0, n) {
            int m;
            cin >> m;
            string s1, s2;
            cin >> s2;
            if (m == 1) {
                if (mp.find(s2) == mp.end()) {
                    mp[s2] = cnt;
                    cnt++;
                    name.push_back(s2);
                }
            }
            FOR(i, 1, m) {
                s1 = s2;
                cin >> s2;

                if (mp.find(s1) == mp.end()) {
                    mp[s1] = cnt;
                    cnt++;
                    name.push_back(s1);
                }
                if (mp.find(s2) == mp.end()) {
                    mp[s2] = cnt;
                    cnt++;
                    name.push_back(s2);
                }

                arr[mp[s1]][mp[s2]] = 1;
                arr[mp[s2]][mp[s1]] = -1;
            }
        }
        cin >> n;
        FOR(i, 0, n) {
            string s1, s2;
            cin >> s1 >> s2;
            arr[mp[s1]][mp[s2]] = 1;
            arr[mp[s2]][mp[s1]] = -1;
        }
        FOR(i, 0, cnt) {
            arr[i][i] = 1;
        }
        FOR(k, 0, cnt) {
            FOR(i, 0, cnt) {
                FOR(j, 0, cnt) {
                    if (arr[i][k] == 1 && arr[k][j] == 1) 
                        arr[i][j] = 1;
                }
            }
        }
        int res = 0;
        FOR(i, 0, cnt) {
            FOR(j, i+1, cnt) {
                if (arr[i][j] == 0 && arr[j][i] == 0) {
                    // cerr << i << " " << j << endl;
                    res++;
                }
            }
        }
        if (res == 0) {
            cout << "Case " << tc << ", no concurrent events." << endl;
        } else {
            cout << "Case " << tc << ", " << res << " concurrent events:" << endl;
        }
        int cc = 0;
        FOR(i, 0, cnt) {
            FOR(j, i+1, cnt) {
                if (arr[i][j] == 0 && arr[j][i] == 0) {
                    if (cc >= 2) {
                        break;
                    }
                    cc++;
                    // if (cc == 2) {
                    //     cout << " ";
                    // }
                    cout << "(" << name[i] << "," << name[j] << ") ";
                    // cerr << i << " " << j << endl;
                    // res++;
                }
            }
        }
        if (res != 0)
            cout << endl;        
    }
    return 0;
}