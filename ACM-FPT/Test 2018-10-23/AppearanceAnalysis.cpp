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

int r, c, n = 0, m = 0, cnt = 0;
vvi arr;
vector < vvi > seg;

vvi rotateVec(vvi arr) {
    int n = arr.size();
    int m = arr[0].size();
    vvi tmp(m, vi(n));
    int i = -1, j = -1;
    FORD(jj, m-1, 0) {
        i++;
        j = -1;
        FOR(ii, 0, n) {
            j++;
            tmp[i][j] = arr[ii][jj];
        }
    }
    return tmp;
}

bool isSame(vvi arr, vvi brr) {
    FOR(rota, 0, 4) {
        arr = rotateVec(arr);
        if (arr.size() == brr.size() && arr[0].size() == brr[0].size()) {
            // FOR(i, 0, arr.size()) {
            //     FOR(j, 0, arr[0].size()) {
            //         printf("%c", arr[i][j]);
            //     }
            //     printf("\n");
            // }
            // printf("\n");
            if (arr == brr) {
                return true;
            }
        }
    }
    return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    scanf("%d %d", &r, &c);
    arr = vvi(r, vi(c));
    FOR(i, 0, r) {
        char tmp; scanf("%c", &tmp);
        FOR(j, 0, c) {
            scanf("%c", &arr[i][j]);
            if (arr[i][j] == '#' && j != 0 && i != 0 && m == 0) {
                m = j - 1;
            }
        }
        if (arr[i][1] == '#' && i != 0 && n == 0) {
            n = i - 1;
        }
    }
    // cerr << n << " " << m << endl;
    cnt = (r-1) / (n+1) * (c - 1) / (m+1);
    // cerr << cnt << endl;
    seg = vector< vvi >(cnt, vvi(n, vi(m)));
    int si = 1, sj = 1;
    FOR(ii, 0, cnt) {
        if (sj >= c) {
            sj = 1;
            si += n + 1;
        }
        if (si >= r) {
            break;
        }
        int ei = si + n - 1;
        int ej = sj + m - 1;
        // cerr << si << " " << sj << " " << ei << " " << ej << endl;
        FORE(i, si, ei) {
            FORE(j, sj, ej) {
                seg[ii][i-si][j-sj] = arr[i][j];
                // printf("%c", seg[ii][i-si][j-sj]);
            }
            // cout << endl;
        }
        // cout << endl;
        sj += m + 1;
    }
    int res = 0;
    FOR(i, 0, cnt) {
        bool isCheck = true;
        FOR(j, i+1, cnt) {
            if (isSame(seg[i], seg[j])) {
                isCheck = false;
                break;
            }
        }
        if (isCheck) {
            res++;
        }
    }
    cout << res << endl;
    return 0;
}