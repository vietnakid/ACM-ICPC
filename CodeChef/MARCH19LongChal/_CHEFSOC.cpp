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

ll memo[1000][257];

int n;
int arr[100005];
ll result;

bitset<100005> isFree;
int rr[100005];

bool inRange(int index) {
    return index >= 0 && index < n;
}


void sovle10(int index) {
    isFree[index] = false;
    result++;
    // for (int g = 0; g < n; g++) {
    //     cerr << 1 - (int)isFree[g];
    // }
    // cerr << "\n";
    rr[index]++;
    for (int i = -arr[index]; i <= arr[index]; i++) {
        int j = index + i;
        if (inRange(j) && isFree[j]) {
            sovle10(j);
        }
    }
    isFree[index] = true;
}

bool isValidState(int index, int state) {
    if (((state >> 3) & 1) == 0) return false;
    if (((state >> 0) & 1) == 1 && ((state >> 1) & 1) == 0 && ((state >> 2) & 1) == 0) return false;
    if (((state >> 1) & 1) == 1 && ((state >> 2) & 1) == 0) return false;
    if (((state >> 2) & 1) == 1 && ((state >> 4) & 1) == 0) return false;

    if (index > 2 && ((state >> 5) & 1) == 0 && ((state >> 6) & 1) == 0) return false;

    if (index == 2 && ((state >> 5) & 1) == 0) return false;
    if (index == 2 && ((state >> 6) & 1) == 1) return false;

    if (index == 1 && ((state >> 4) & 1) == 0) return false;
    if (index == 1 && ((state >> 5) & 1) == 1) return false;
    if (index == 1 && ((state >> 6) & 1) == 1) return false;

    if (index == 0 && ((state >> 4) & 1) == 1) return false;
    if (index == 0 && ((state >> 5) & 1) == 1) return false;
    if (index == 0 && ((state >> 6) & 1) == 1) return false;

    return true;
}

ll cal(int index, int state) {
    if (!isValidState(index, state)) return 0;

    if (!inRange(index)) return 0;
    if (index == 0) {
        if (state == 8) return 1;
        else return 0;
    } 
    // cerr << index << " " << state << '\n';
    if (memo[index][state] != -1) {
        return memo[index][state];
    }

    ll res = 0;
    
    for (int i = -2; i <= 2; i++) {
        int j = index + i;
        if (!inRange(j)) continue;
        int l = 3;
        int newState = state;
        if (i < 0) {
            l = abs(i) + 3;
            newState = ((newState & (~(1 << 3))) >> abs(i)) % 256;
            if (((state >> l) & 1) == 1 && arr[j] >= abs(i)) {
                // cerr << "?? " << j << " " << newState << "\n";
                res = (res + cal(j, newState)) % nMod;
            }
            // cerr << index << " " << j << " " << l << " " << state << " " << newState << "--<\n";
        } else if (i > 0) {
            l = 3 - abs(i);
            newState = ((newState & (~(1 << 3))) << abs(i)) % 256;
            if (((state >> l) & 1) == 1 && arr[j] >= abs(i)) {
                // cerr << "?? " << j << " " << newState << "\n";
                res = (res + cal(j, newState)) % nMod;
            }
            // cerr << index << " " << j << " " << l << " " << state << " " << newState << "-->\n";
        }
    }
    // cerr << index << " " << state << " " << res << '\n';
    return memo[index][state] = res;
}

void solve() {
    for (int i = 0; i < n; i++) {
        for (int state = 0; state < 128; state++) {
            result = (result + cal(i, state)) % nMod;
        }
        cerr << result << " -- " << rr[i] <<  "\n\n";
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    freopen("/Users/macbook/Desktop/MyCPPLibrary/error", "w", stderr);
    int TC; cin >> TC;
    while (TC--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        result = 0;
        isFree.set();
        sovle10(0);
        cout << result << "\n";

        result = 0;
        memset(memo, -1, sizeof(memo));
        solve();
        cout << result << "\n";

        cout << "\n";
    }
    return 0;
}