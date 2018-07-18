#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

typedef long long ll;
typedef long double ld;
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

int n, q;

int f[1<<19][19][2];
vvi sum;
vi arr;
#define isOn(S, j) (S & (1 << j))
int res = 0;

vi toBinary(int u) {
    vi res(n);
    FOR(i, 0, n) {
        res[i] = (u & (1 << i)) >> i;
    }
    reverse(res.begin(), res.end());
    return res;
}

int toDecimal(vi & arr) {
    int res = 0;
    int u = 1;
    FOR(i, 0, n) {
        res += u * arr[i];
        u *= 2;
    }
    return res;
}

void check(vi & permu) {
    int u = toDecimal(permu);
    vi ssum = vi(10);
    FOR(i, 0, n) {
        if (permu[i]) {
            FOR(j, 0, 10) {
                ssum[j] += sum[i][j];
            }
        }
    }
    FOR(j, 0, 10) {
        if (ssum[j] > q) {
            FOR(i, 0, n) {
                f[u][i][0] = -INF;
                f[u][i][1] = -INF;
            }
            return;
        }
    }
}

void cal(vi & permu, int pos, int state) {
    int u = toDecimal(permu);
    if (f[u][pos][state] != -1) {
        res = max(res, f[u][pos][state]);
        return;   
    }
    check(permu);
    if (f[u][pos][state] != -1) {
        return;   
    }
    vi newPermu = permu;
    newPermu[pos] = 0;
    int v = toDecimal(newPermu);
    if (state = 0) {
        FOR(i, 0, n) {
            if (newPermu[i]) {
                f[u][pos][state] = max(f[u][pos][state], arr[pos] ^ arr[i] + f[v][i][state]);
            }
        }        
    } else {

    }
    
}

// Complete the maximumElegance function below.
void solve() {
    // Return an integer denoting the maximum elegance which can be obtained by Diane.
    memset(f, -1, sizeof(f));
    
    f[0][0][0] = 0;
    FORD(ii, n, 0) {
        int u = (1 << ii) - 1;
        vi arru = toBinary(u);
        do {
            FOR(i, 0, n) {
                if (arr[u]) {
                    cal(arru, i, 0);
                    cal(arru, i, 1);
                }
            }
            
        } while (next_permutation(arru.begin(), arru.end()));
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie();
    freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
    cin >> n >> q;
    arr = vi(n);
    sum = vvi(n, vi(10, 0));
    FOR(i, 0, n) {
        cin >> arr[i];
    }
    
    FOR(i, 0, n) {
        string s;
        cin >> s;
        FOR(j, 0, s.size()) {
            sum[i][s[j] - '0']++;
        }
    }
    solve();
    return 0;
}
