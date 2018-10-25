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

int n;
int state[11][3][3];
vi symbol;

bool sovle() {
    vi sym = symbol;
    int curState = 1;
    int index = 13;
    FOR(i, 0, 11) {
        if (curState == n) {
            return true;
        }
        int curSym = sym[index];
        // cerr << curState << " " << curSym << endl;
        int nextState = state[curState][curSym][0];
        int dir = state[curState][curSym][1];
        sym[index] = state[curState][curSym][2];
        index += dir;
        curState = nextState;
    }
    return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    int TC; cin >> TC;
    FORE(tc, 1, TC) {
        cout << "Machine #" << tc << ":" << endl;
        cin >> n;
        FOR(i, 1, n) {
            char c;
            FOR(j, 0, 3) {
                cin >> c >> state[i][j][0] >> c >> state[i][j][1] >> c >> state[i][j][2] >> c;
            }
            // printf("(%d, %d, %d) (%d, %d, %d) (%d, %d, %d)\n", state[i][0][0], state[i][0][1], state[i][0][2], state[i][1][0], state[i][1][1], state[i][1][2], state[i][2][0], state[i][2][1], state[i][2][2]);
        }
        int q; cin >> q;
        FOR(i, 0, q) {
            symbol = vi(30, 2);
            int k;
            cin >> k;
            FOR(j, 0, k) {
                cin >> symbol[j+13];
            }
            if (sovle()) {
                cout << "yes" << endl;
            } else {
                cout << "no" << endl;
            }
        }
    }
    return 0;
}