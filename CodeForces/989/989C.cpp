#include <bits/stdc++.h>

using namespace std;

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

ll nMod = 1e9 + 7;

inline ll GCD(ll a, ll b) {while (b != 0) {ll c = a % b; a = b; b = c;} return a;};
inline ll LCM(ll a, ll b) {return (a / GCD(a,b)) * b;};

priority_queue< ll, vector<ll>, greater<ll> > heap;

vi ai(4);
vvi arr(101, vi(101, 0));

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    FOR(i, 0, 4) cin >> ai[i];

    int lower = 50, upper = 50, leng = 0;
    int index = 0;
    while(true) {
        int cnt = 0;
        bool isOk = false;
        while (ai[index] == 0) {
            cnt++;
            index = (index+1) % 4;
            if (cnt == 4) {
                isOk = true;
                lower++;
                upper--;
                break;
            }
        }
        if (isOk) {
            break;
        }
        FORE(j, lower, upper) {
            arr[lower][j] = index;
        }
        FORE(j, lower, upper) {
            arr[upper][j] = index;
        }
        FORE(i, lower+1, upper-1) {
            arr[i][lower] = index;
            arr[i][upper] = index;
        }
        ai[index]--;

        // cout << lower << " " << upper << " " << index << " " << ai[index] << endl;
        if (ai[index] != 0 && lower != 50) {
            int x = lower;
            int y = lower + 1;
            int c = arr[lower+1][lower+1];
            int cnt = 0;
            FOR(i, 0, 4) {
                if (ai[i] == 0) cnt++;
            }
            if (cnt > 2 && lower != 50) {
                arr[lower][lower+1] = c;
                arr[lower+1][lower] = c;
                ai[index]--;

                while (ai[index] > 0) {
                    y += 2;
                    if (y <= upper) {
                        arr[x][y] = c;
                        ai[index]--;
                    } else {
                        break;
                    }
                }

                x = lower + 1;
                y = lower;

                while (ai[index] > 0) {
                    x += 2;
                    if (x <= upper) {
                        arr[x][y] = c;
                        ai[index]--;
                    } else {
                        break;
                    }
                }

                x = lower - 1;
                y = upper;

                while (ai[index] > 0) {
                    x += 2;
                    if (x <= upper) {
                        arr[x][y] = c;
                        ai[index]--;
                    } else {
                        break;
                    }
                }

                x = upper;
                y = lower - 1;

                while (ai[index] > 0) {
                    y += 2;
                    if (y <= upper) {
                        arr[x][y] = c;
                        ai[index]--;
                    } else {
                        break;
                    }
                }
            } else {
                x = lower;
                y = lower;
                c = arr[lower+1][lower+2];
        
                while (y <= upper - 2) {
                    y += 2;
                    arr[x][y] = c;
                }
                if (ai[index] > 0) {
                    arr[lower][lower+1] = c;
                    arr[lower+1][lower] = c;
                    ai[index]--;
                }
                

                x = lower;
                y = lower;

                while (x <= upper - 2) {
                    x += 2;
                    arr[x][y] = c;
                }
                if (ai[index] > 0) {
                    arr[upper][lower+1] = c;
                    arr[upper-1][lower] = c;
                    ai[index]--;
                }

                x = lower;
                y = upper;

                while (x <= upper - 2) {
                    x += 2;
                    arr[x][y] = c;
                }
                if (ai[index] > 0) {
                    arr[lower][upper-1] = c;
                    arr[lower+1][upper] = c;
                    ai[index]--;
                }

                x = upper;
                y = lower;

                while (y <= upper - 2) {
                    y += 2;
                    arr[x][y] = c;
                }
                if (ai[index] > 0) {
                    arr[upper][upper-1] = c;
                    arr[upper-1][upper] = c;
                    ai[index]--;
                }
            }
        }
        lower--;
        upper++;
        index = (index+1) % 4;
        
    }
    cout << (upper - lower + 1) << " " << (upper - lower + 1) << endl;
    FORE(i, lower, upper) {
        FORE(j, lower, upper) {
            cout << char(arr[i][j] + 'A');
        }
        cout << endl;
    }
    return 0;
}