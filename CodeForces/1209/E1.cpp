#include <bits/stdc++.h>
#include <unistd.h>

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

void vietnakid() {
    int TC; cin >> TC;
    while (TC--) {
        cin >> n >> m;
        vvi arr(n, vi(m));
        vii processArr;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> arr[i][j];
                processArr.push_back({arr[i][j],j});
            }
        }
        sort(processArr.rbegin(), processArr.rend());
        vi getCol;
        vector<bool> isSelected(m, false);
        for (auto x : processArr) {
            if (getCol.size() == 4) break;
            int col = x.second;
            if (!isSelected[col]) {
                isSelected[col] = true;
                getCol.push_back(col);
                // cerr << col << " ";
            }
        }
        int leng = getCol.size();
        // cerr << "\nleng = " << leng << "\n\n";
        int maxNum = (1 << (2 * (leng-1)));
        int res = 0;
        for (int num = 0; num < maxNum; num++) {
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                int maxRow = arr[i][getCol[0]];
                for (int j = 0; j < leng-1; j++) {
                    int posRow = (num % (1 << (2*(j + 1)))) >> (2*j);
                    // cerr << "posRow ?? " << (num % (4 * (j + 1))) / 4 << "\n";
                    posRow = (posRow + i) % n;
                    // cerr << "num = " << num << " | i = " << i <<  " | j =  " << j << " | posRow = " << posRow << "\n";
                    maxRow = max(maxRow, arr[posRow][getCol[j+1]]);
                }
                cnt += maxRow;
                // cerr << "i = " << i << " | maxRow = " << maxRow << "\n";
            }
            // cerr << "CNT = " << cnt << "\n";
            res = max(res, cnt);
        }
        cout << res << "\n";
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	#ifdef LOCAL_KID
	freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    freopen("/Users/macbook/Desktop/MyCPPLibrary/error", "w", stderr);
	#else
	// online submission
	#endif
	vietnakid();
 	cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}