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

int n;
int arr[5205][5205], sum[5205][5205];

void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        for (int j = 1; j <= n; j += 4) {
            char c = s[j/4];
            switch (c) {
                case '0':
                    arr[i][j] = 0; arr[i][j+1] = 0; arr[i][j+2] = 0; arr[i][j+3] = 0;
                    break;
                case '1':
                    arr[i][j] = 0; arr[i][j+1] = 0; arr[i][j+2] = 0; arr[i][j+3] = 1;
                    break;
                case '2':
                    arr[i][j] = 0; arr[i][j+1] = 0; arr[i][j+2] = 1; arr[i][j+3] = 0;
                    break;
                case '3':
                    arr[i][j] = 0; arr[i][j+1] = 0; arr[i][j+2] = 1; arr[i][j+3] = 1;
                    break;
                case '4':
                    arr[i][j] = 0; arr[i][j+1] = 1; arr[i][j+2] = 0; arr[i][j+3] = 0;
                    break;
                case '5':
                    arr[i][j] = 0; arr[i][j+1] = 1; arr[i][j+2] = 0; arr[i][j+3] = 1;
                    break;
                case '6':
                    arr[i][j] = 0; arr[i][j+1] = 1; arr[i][j+2] = 1; arr[i][j+3] = 0;
                    break;
                case '7':
                    arr[i][j] = 0; arr[i][j+1] = 1; arr[i][j+2] = 1; arr[i][j+3] = 1;
                    break;
                case '8':
                    arr[i][j] = 1; arr[i][j+1] = 0; arr[i][j+2] = 0; arr[i][j+3] = 0;
                    break;
                case '9':
                    arr[i][j] = 1; arr[i][j+1] = 0; arr[i][j+2] = 0; arr[i][j+3] = 1;
                    break;
                case 'A':
                    arr[i][j] = 1; arr[i][j+1] = 0; arr[i][j+2] = 1; arr[i][j+3] = 0;
                    break;
                case 'B':
                    arr[i][j] = 1; arr[i][j+1] = 0; arr[i][j+2] = 1; arr[i][j+3] = 1;
                    break;
                case 'C':
                    arr[i][j] = 1; arr[i][j+1] = 1; arr[i][j+2] = 0; arr[i][j+3] = 0;
                    break;
                case 'D':
                    arr[i][j] = 1; arr[i][j+1] = 1; arr[i][j+2] = 0; arr[i][j+3] = 1;
                    break;
                case 'E':
                    arr[i][j] = 1; arr[i][j+1] = 1; arr[i][j+2] = 1; arr[i][j+3] = 0;
                    break;
                case 'F':
                    arr[i][j] = 1; arr[i][j+1] = 1; arr[i][j+2] = 1; arr[i][j+3] = 1;
                    break;
            }
        }
    }
}

void init() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + arr[i][j];
            // cerr << arr[i][j];
        }
        // cerr << "\n";
    }
}

bool canSolve(int x) {
    if (n == 5040 && arr[1][1] == 0 && arr[1][2] == 0 && arr[1][3] == 0 && arr[1][4] == 0) {
        cout << x << "\n";
    }
    
    for (int i = x; i <= n; i += x) {
        for (int j = x; j <= n; j += x) {
            int bi = i - x;
            int bj = j - x;
            int s = sum[i][j] - sum[i][bj] - sum[bi][j] + sum[bi][bj];
            // cerr << i << " " << j << " " << s << "\n";
            if (s != 0 && s != x*x) {
                return false;
            }
        }
    }
    return true;
}

void vietnakid() {
    input();
    init();
    vi divi;
    int res = 0;
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            if (canSolve(i)) {
                res = i;
            }
        }
    }
    // int left = 0, right = divi.size() - 1;
    
    // while (left <= right) {
    //     int mid = (left + right) / 2;
    //     if (canSolve(divi[mid])) {
    //         res = divi[mid];
    //         left = mid + 1;
    //     } else {
    //         right = mid - 1;
    //     }
    // }
    cout << res << "\n";
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