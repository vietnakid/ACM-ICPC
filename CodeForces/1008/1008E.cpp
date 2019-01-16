#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector< vector<int> > vvi;
typedef vector<ll> vl;
typedef vector< vector<ll> > vvl;
typedef pair<int, int> ii;
typedef vector<ii> vii;

#define FOR(i, a, b) \
    for (int i = (a); i < (b); i++)
#define FORE(i, a, b) \
    for (int i = (a); i <= (b); i++)
#define FORD(i, a, b) \
    for (int i = (a); i >= (b); i--)

#define INF 2e9 // 2e9
#define INFLL 2e18 // 2e18
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
    ll n, t;
    cin >> n;
    ll leftX = 1, rightX = n, leftY = 1, rightY = n;
    ll x, y;
    while (true) {
        x = (leftX + rightX) / 2;
        y = (leftY + rightY) / 2;
        cerr << leftX << " - " << rightX << endl;
        cerr << leftY << " - " << rightY << endl;
        cout << x << " " << y << endl;
        fflush(stdout);
        cin >> t;
        if (t == 0) {
            break;
        } else if (t == 1) {
            leftX = x + 1;
        } else if (t == 2) {
            leftY = y + 1;
        } else {
            // Case 1: x > a && y < b
            cout << x << " " << leftY << endl;
            cin >> t;
            if (t == 0) {
                break;
            } else if (t == 1) {
                leftX = x + 1;
            } else if (t == 2) {
                leftY++;
            } else if (t == 3) {
                rightX = x - 1;
            }
            
            // Case 2: x < a && y > b
            cout << leftX << " " << y << endl;
            cin >> t;
            if (t == 0) {
                break;
            } else if (t == 1) {
                leftX++;
            } else if (t == 2) {
                leftY = y + 1;
            } else if (t == 3) {
                rightY = y - 1;
            }
            
            // Case 3: x > a && y > b
            cout << (leftX + x) / 2 << " " << (leftY + y) / 2 << endl;
            cin >> t;
            if (t == 0) {
                break;
            } else if (t == 1) {
                leftX = (leftX + x) / 2 + 1;
            } else if (t == 2) {
                leftY = (leftY + y) / 2 + 1;
            } else if (t == 3) {
                // Case 1: x > a && y < b
                cout << (leftX + x) / 2 << " " << leftY << endl;
                cin >> t;
                if (t == 0) {
                    break;
                } else if (t == 1) {
                    leftX = (leftX + x) / 2 + 1;
                } else if (t == 2) {
                    leftY++;
                } else if (t == 3) {
                    rightX = (leftX + x) / 2 - 1;
                }
                
                // Case 2: x < a && y > b
                cout << leftX << " " << (leftY + y) / 2  << endl;
                cin >> t;
                if (t == 0) {
                    break;
                } else if (t == 1) {
                    leftX++;
                } else if (t == 2) {
                    leftY = (leftY + y) / 2  + 1;
                } else if (t == 3) {
                    rightY = (leftY + y) / 2  - 1;
                }
            }
        }
    }
    return 0;
}