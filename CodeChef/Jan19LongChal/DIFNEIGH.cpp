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

int n, m, TC;

void sovleSmall() {
    if (n == 1 && m == 1) {
        cout << 1 << endl;
        cout << 1 << endl;
    } else if (n == 1 && m == 2) {
        cout << 1 << endl;
        cout << "1 1" << endl;
    } else if (n == 1 && m == 3) {
        cout << 2 << endl;
        cout << "1 1 2" << endl;
    } else if (n == 1 && m == 4) {
        cout << 2 << endl;
        cout << "1 1 2 2" << endl;
    } else if (n == 2 && m == 1) {
        cout << 1 << endl;
        cout << "1" << endl << "1";
    } else if (n == 2 && m == 2) {
        cout << 2 << endl;
        cout << "1 1" << endl;
        cout << "2 2" << endl;
    } else if (n == 2 && m == 3) {
        cout << 3 << endl;
        cout << "1 2 3" << endl;
        cout << "1 2 3" << endl;
    } else if (n == 2 && m == 4) {
        cout << 3 << endl;
        cout << "1 1 3 2" << endl;
        cout << "2 2 3 1" << endl;
    } else if (n == 3 && m == 1) {
        cout << 2 << endl;
        cout << "1" << endl;
        cout << "1" << endl;
        cout << "2" << endl;
    } else if (n == 3 && m == 2) {
        cout << 3 << endl;
        cout << "1 1" << endl;
        cout << "2 2" << endl;
        cout << "3 3" << endl;
    } else if (n == 3 && m == 3) {
        cout << 4 << endl;
        cout << "1 1 3" << endl;
        cout << "2 2 3" << endl;
        cout << "3 4 1" << endl;
    } else if (n == 3 && m == 4) {
        cout << 4 << endl;
        cout << "1 1 3 3" << endl;
        cout << "2 2 4 4" << endl;
        cout << "3 3 1 1" << endl;
    } else if (n == 4 && m == 1) {
        cout << 2 << endl;
        cout << "1" << endl;
        cout << "1" << endl;
        cout << "2" << endl;
        cout << "2" << endl;
    } else if (n == 4 && m == 2) {
        cout << 3 << endl;
        cout << "1 1" << endl;
        cout << "2 2" << endl;
        cout << "3 3" << endl;
        cout << "1 1" << endl;
    } else if (n == 4 && m == 3) {
        cout << 4 << endl;
        cout << "1 1 3" << endl;
        cout << "2 2 4" << endl;
        cout << "3 3 1" << endl;
        cout << "4 4 2" << endl;
    } else if (n == 4 && m == 4) {
        cout << 4 << endl;
        cout << "1 1 3 3" << endl;
        cout << "2 2 4 4" << endl;
        cout << "3 3 1 1" << endl;
        cout << "4 4 2 2" << endl;
    } 

}

void sovleLarge() {
    if (n == 1) {
        int cur = 0;
        cout << 2 << endl;
        for (int j = 0; j < m; j++) {
            cout << cur+1 << " ";
            j++;
            if (j < m) 
                cout << cur+1 << " ";
            cur = (cur + 1) % 2;
        }
        cout << endl;
    } else if (n == 2) {
        int cur = 0;
        cout << 3 << endl;
        for (int j = 0; j < m; j++) {
            cout << cur+1 << " ";
            j++;
            if (j < m) 
                cout << cur+1 << " ";
            cur = (cur + 1) % 3;
        }
        cout << endl;
        cout << 2 << " ";
        cur = 2;
        for (int j = 1; j < m; j++) {
            cout << cur+1 << " ";
            j++;
            if (j < m) 
                cout << cur+1 << " ";
            cur = (cur + 1) % 3;
        }
        cout << endl;
    } else if (m == 1) {
        int cur = 0;
        cout << 2 << endl;
        for (int j = 0; j < n; j++) {
            cout << cur+1 << endl;
            j++;
            if (j < n) 
                cout << cur+1 << endl;
            cur = (cur + 1) % 2;
        }
    } else if (m == 2) {
        int cur = 0;
        cout << 3 << endl;
        for (int j = 0; j < n; j++) {
            cout << cur +1 << " " << cur + 1 << endl;
            cur = (cur + 1) % 3;
        }
    } else {
        cout << 4 << endl;
        int cur = -3;
        for (int i = 0; i < n; i++) {
            cur = (cur + 3) % 4;
            for (int j = 0; j < m; j++) {
                cout << cur+1 << " ";
                j++;
                if (j < m) 
                    cout << cur+1 << " ";
                cur = (cur + 2) % 4;
            }
            cout << endl;
        }
    }
}

int dx[] = {0, -1, -2, -1};
int dy[] = {-2, -1, 0, 1};

void sovle() {
    int arr[n][m];
    memset(arr, 0, sizeof(arr));
    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            bitset<5> check;
            check.set();
            for (int ii = 0; ii < 4; ii++) {
                int x = i + dx[ii];
                int y = j + dy[ii];
                if (x >= 0 && y >= 0 && x < n && y < m) {
                    check[arr[x][y]] = false;
                }
            }
            for (int ii = 1; ii < 5; ii++) {
                if (check[ii]) {
                    arr[i][j] = ii;
                    res = max(res, ii);
                    break;
                } 
            }
        }
    }
    cout << res << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    // freopen("/Users/macbook/Desktop/MyCPPLibrary/error", "w", stderr);
    cin >> TC;
    while (TC--) {
        cin >> n >> m;
        // sovle();
        // cout << endl;
        if (n > 4 || m > 4) sovleLarge();
        else sovle();
        // cout << endl << endl;
    }
    return 0;
}