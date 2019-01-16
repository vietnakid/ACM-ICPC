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

int n, m;
vector<string> arr;
int res = -1;
unsigned long long hashRow[305][305][2];
unsigned long long hashCol[305][305][2];
unsigned long long primePow[305];
unsigned long long powPrime = 257;

void init() {
    primePow[0] = 1;
    primePow[1] = powPrime;
    for (int i = 2; i < 305; i++) {
        primePow[i] = primePow[i-1] * powPrime;
    }
    for (int i = 1; i <= n; i++) {
        hashRow[i][0][0] = 0;
        hashRow[i][m+1][1] = 0;
        for (int j = 1; j <= m; j++) {
            hashRow[i][j][0] = hashRow[i][j-1][0]*powPrime + arr[i][j];
        }
        for (int j = m; j >= 1; j--) {
            hashRow[i][j][1] = hashRow[i][j+1][1]*powPrime + arr[i][j];
        }
    }

    for (int j = 1; j <= m; j++) {
        hashCol[j][0][0] = 0;
        hashCol[j][n+1][1] = 0;
        for (int i = 1; i <= n; i++) {
            hashCol[j][i][0] = hashCol[j][i-1][0] * powPrime + arr[i][j];
        }
        for (int i = n; i >= 1; i--) {
            hashCol[j][i][1] = hashCol[j][i+1][1] * powPrime + arr[i][j];
        }
    }
}

bool isOk(int x, int y, int size) {
    if (x <= 0 || y <= 0 || y+size-1 > m || x+size-1 > n) return false;
    if (arr[x][y] != arr[x+size-1][y+size-1]) return false;
    if (arr[x][y+size-1] != arr[x+size-1][y]) return false;
    // cerr << x << " " << y << " " << size << endl;
    ll hashRowUp = hashRow[x][y+size-1][0] - (hashRow[x][y-1][0] * primePow[size]);
    ll hashRowDown = hashRow[x+size-1][y][1] - (hashRow[x+size-1][y+size][1] * primePow[size]);
    // cerr << hashRowUp << " hashRow " << hashRowDown << endl;
    if (hashRowUp != hashRowDown) return false;

    ll hashColUp = hashCol[y][x+size-1][0] - (hashCol[y][x-1][0] * primePow[size]);
    ll hashColDown = hashCol[y+size-1][x][1] - (hashCol[y+size-1][x+size][1] * primePow[size]);
    // cerr << hashColUp << " hashCol " << hashColDown << endl;
    if (hashColUp != hashColDown) return false;
    // cerr << "ok " << x << " " << y << " " << size << endl;
    return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    // freopen("/Users/macbook/Desktop/MyCPPLibrary/error", "w", stderr);
    cin >> n >> m;
    arr.resize(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        arr[i] = '.' + arr[i];
    }
    init();
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (min(i, j)*2 <= res || min(n-i+1, m-j+1)*2 <= res)
                continue;
            for (int state = 2; state <= 3; state++) {
                int size = state;
                while (isOk(i-(size/2), j-(size/2), size)) {
                    res = max(res, size);
                    size += 2;
                }
            }
        }
    }

    cout << res << endl;
    return 0;
}