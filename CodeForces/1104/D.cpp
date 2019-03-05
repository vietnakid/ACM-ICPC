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

void doTheGame() {
    ll x = 1, y = 2;
    for (int pos = 1; pos <= 30; pos++) {
        cout << "? " << x << " " << y << "\n";
        fflush(stdout);

        string result;
        cin >> result;
        if (result == "x") {
            break;
        } else if (result == "y") {
            x = y;
            y = y*2;
        } else {
            assert(0 > 1);
            exit(0);
        }
    }
    // Here we now a in range [x, y]

    for (int i = 0; i < 30; i++) {
        if (x == y-1) {
            break;
        }
        // first half or second half
        ll mid = (x+y) / 2;
        cout << "? " << x << " " << mid << "\n";
        fflush(stdout);

        string result;
        cin >> result;

        if (result == "x") {
            y = mid;
        } else if (result == "y") {
            x = mid;
        } else {
            assert(0 > 1);
            exit(0);
        }
    }
    if (x == 1 && y == 2) {
        cout << "? 2 3\n";
        fflush(stdout);

        string result;
        cin >> result;

        if (result == "x") {
            cout << "! " << 1 << "\n";
            fflush(stdout);
        } else if (result == "y") {
            cout << "! " << 2 << "\n";
            fflush(stdout);
        } else {
            assert(0 > 1);
            exit(0);
        }
    } else {
        cout << "! " << y << "\n";
        fflush(stdout);
    }
    
    
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    // freopen("/Users/macbook/Desktop/MyCPPLibrary/error", "w", stderr);
    
    while (true) {
        string s;
        cin >> s;
        if (s == "start") {
            doTheGame();
        } else if (s == "mistake") {
            assert(0 > 1);
            return 0;
        } else {
            return 0;
        }
    }
    return 0;
}