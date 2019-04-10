#include <bits/stdc++.h>
using namespace std;
 
#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)
#define FORD(i, b, a) for (int i = b; i >= a; --i)
#define FORE(i, v) for (__typeof (v.begin()) i = v.begin(); i != v.end(); ++i)
#define FORR(i, v) for (__typpeof (v.rbegin()) i = v.rbegin(); i != v.rend(); ++i)
#define sz(v) (int) v.size()
#define all(v) v.begin(), v.end()
#define sqr(x) 1ll * (x) * (x)
#define EPS 1e-9
 
template <class T> int getBit(T x, int k) { return x >> k & 1; }
template <class T> T onBit(T x, int k) { return x  (T(1) << k); }
template <class T> T offBit(T x, int k) { return x & (~(T(1) << k)); }
template < class T > void read(T &x) {
    x = 0; char c; bool nega = 0;
    while (!isdigit(c = getchar()) && c != '-');
    if (c == '-') c = getchar(), nega = 1;
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
    if (nega) x = -x;
}
template <class T> void write(T x) { if (x / 10) write(x / 10); putchar(x % 10); }
template <class T> void writeln(T x) { write(x); putchar('\n'); }
 
const int N = 1111;
 
int x, y, a, b, n;
pair < int, int > dp[N][N];
 
bool load() {
    return ~scanf("%d%d%d%d%d", &x, &a, &y, &b, &n);
}
 
bool ok(int w) {
    REP(i, x + 1) REP(j, y + 1) if (i + j > 0) {
        pair <int, int> cur1, cur2;
        cur1 = cur2 = make_pair(0, 0);
        if (i > 0) {
            cur1 = make_pair(dp[i - 1][j].first, dp[i - 1][j].second + a);
            if (cur1.second >= w) {
                cur1 = make_pair(cur1.first + 1, 0);
            }
        }
        if (j > 0) {
            cur2 = make_pair(dp[i][j - 1].first, dp[i][j - 1].second + b);
            if (cur2.second >= w) {
                cur2 = make_pair(cur2.first + 1, 0);
            }
        }
        dp[i][j] = max(cur1, cur2);
        if (dp[i][j].first >= n) return 1;
    }
    return dp[x][y].first >= n;
}
 
void process() {
    int answer = 0, l = 1, r = x * a + y * b;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (ok(mid)) {
            l = mid + 1;
            answer = mid;
        } else {
            r = mid - 1;
        }
    }
    printf("%d\n", answer);
}
 
int main() {    
//    freopen("input.in", "r", stdin);
  //  freopen("output.out", "w", stdout);
 
    load();
    process();
 
    return 0;
}