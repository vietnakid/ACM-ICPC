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
    int n;
    cin >> n;
    vvi arr(n+1, vi(n+1, false));
    arr[1][1] = true;
    arr[n][n] = true;
    // int q = n*4 - 4;
    string ans;

    int x = n, y = n;
    FOR(i, 0, n - 1) {
        cout.flush();
        cout << "? 1 1 " << x-1 << " " << y << endl; 
        cin >> ans;
        if (ans == "BAD") {
            return 0;
        } else if (ans == "YES") {
            arr[x-1][y] = true;
            x = x - 1;
        } else {
            arr[x][y-1] = true;
            y = y - 1;
        }
    }
    int X = x, Y = y;
    x = 1; y = 1;
    FOR(i, 0, n - 1) {
        if (x < X) {
            cout.flush();
            cout << "? " << x+1 << " " << y << " " << n << " " << n << endl; 
            cin >> ans;
            if (ans == "BAD") {
                return 0;
            } else if (ans == "YES") {
                arr[x+1][y] = true;
                x = x + 1;
            } else {
                arr[x][y+1] = true;
                y = y + 1;
            }
        } else {
            cout.flush();
            cout << "? " << x << " " << y+1 << " " << n << " " << n << endl; 
            cin >> ans;
            if (ans == "BAD") {
                return 0;
            } else if (ans == "YES") {
                arr[x][y+1] = true;
                y = y + 1;
            } else {
                arr[x+1][y] = true;
                x = x + 1;
            }
        }
        if (x == X && Y == y) break;
    }

    x = 1;
    y = 1;
    cout << "! ";
    FOR(i, 0, 2*n - 2) {
        if (x < n && arr[x+1][y] == true) {
            cout << "D";
            x++;
        } else {
            cout << "R";
            y++;
        }
    }
    cout << endl;

    // cout.flush();
    // cout << "? 1 1 1 " << n << endl; 
    // cin >> ans;
    // if (ans == "BAD") {
    //     return 0;
    // } else if (ans == "YES") {
    //     FOR(i, 1, n) {
    //         arr[1][i] = true;
    //     }
    // }

    // cout.flush();
    // cout << "? 1 1 " << n << " 1" << endl; 
    // cin >> ans;
    // if (ans == "BAD") {
    //     return 0;
    // } else if (ans == "YES") {
    //     FOR(i, 1, n) {
    //         arr[i][1] = true;
    //     }
    // }

    // cout.flush();
    // cout << "? 1 " << n << " " << n << " " << n << endl;
    // cin >> ans;
    // if (ans == "BAD") {
    //     return 0;
    // } else if (ans == "YES") {
    //     FOR(i, 1, n) {
    //         arr[i][n] = true;
    //     }
    // }

    // cout.flush();
    // cout << "? " << n << " 1 " << n << " " << n << endl; 
    // cin >> ans;
    // if (ans == "BAD") {
    //     return 0;
    // } else if (ans == "YES") {
    //     FOR(i, 1, n) {
    //         arr[n][i] = true;
    //     }
    // }

    return 0;
}