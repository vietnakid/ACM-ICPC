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

bool dif(char a, char b) {
    if (a == '-' || b == '-') return false;
    return a != b;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    int n, m;
    char c;
    cin >> c >> n >> m;
    vector< vector<char> > arr(8, vector<char>(8));
    FOR(i, 0, 8) {
        FOR(j, 0, 8) 
            cin >> arr[i][j];
    }
    n--; m--;
    arr[n][m] = c;
    int res = 0;
    vii rr;
    FOR(i, 0, 8) {
        FOR(j, 0, 8) {
            if (i == n && dif(arr[i][j], c)) {
                // cerr << i << " " << j << " " << arr[i][j] << endl;
                int check = 0;
                FOR(jj, j+1, 8) {
                    if (dif(arr[i][j], arr[i][jj])) {
                        check++;
                        break;
                    }
                }
                FORD(jj, j-1, 0) {
                    if (dif(arr[i][j], arr[i][jj])) {
                        check++;
                        break;
                    }
                }
                if (check == 2) {
                    res++;
                    rr.push_back({i+1, j+1});
                }
            }
            if (j == m && dif(arr[i][j], c)) {
                // cerr << i << " " << j << " " << arr[i][j] << endl;
                int check = 0;
                FOR(ii, i+1, 8) {
                    if (dif(arr[i][j], arr[ii][j])) {
                        check++;
                        break;
                    }
                }
                FORD(ii, i-1, 0) {
                    if (dif(arr[i][j], arr[ii][j])) {
                        check++;
                        break;
                    }
                }
                if (check == 2) {
                    res++;
                    rr.push_back({i+1, j+1});
                }
            }
            if (i-j == n-m && dif(arr[i][j], c)) {
                // cerr << i << " " << j << " " << arr[i][j] << endl;
                int check = 0;
                int ii = i;
                int jj = j;
                FOR(k, 0, 8) {
                    ii--; jj--;
                    if (ii >= 8 || jj >= 8 || ii < 0 || jj < 0) break;
                    // cerr << ii << " " << jj << endl;
                    if (dif(arr[i][j], arr[ii][jj])) {
                        check++;
                        break;
                    }
                }
                ii = i;
                jj = j;
                FOR(k, 0, 8) {
                    ii++;
                    jj++;
                    if (ii >= 8 || jj >= 8 || ii < 0 || jj < 0) break;
                    // cerr << ii << " " << jj << endl;
                    if (dif(arr[i][j], arr[ii][jj])) {
                        check++;
                        break;
                    }
                }
                if (check == 2) {
                    res++;
                    rr.push_back({i+1, j+1});
                }
            }
            if (i+j == n+m && dif(arr[i][j], c)) {
                // cerr << i << " " << j << " " << arr[i][j] << endl;
                int check = 0;
                int ii = i;
                int jj = j;
                FOR(k, 0, 8) {
                    ii--;
                    jj++;
                    if (ii >= 8 || jj >= 8 || ii < 0 || jj < 0) break;
                    // cerr << ii << " " << jj << endl;
                    if (dif(arr[i][j], arr[ii][jj])) {
                        check++;
                        break;
                    }
                }
                ii = i;
                jj = j;
                FOR(k, 0, 8) {
                    ii++;
                    jj--;
                    if (ii >= 8 || jj >= 8 || ii < 0 || jj < 0) break;
                    // cerr << ii << " " << jj << endl;
                    if (dif(arr[i][j], arr[ii][jj])) {
                        check++;
                        break;
                    }
                }
                if (check == 2) {
                    res++;
                    rr.push_back({i+1, j+1});
                }
            }
        }
    }
    // cerr << arr[2][6] << endl;
    cout << res << endl;
    FOR(i, 0, rr.size()) {
        cout << rr[i].first << " " << rr[i].second << endl;
    }
    return 0;
}