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

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

int n, m;
vector<string> arr;

void printArray() {
    FOR(i, 0, n)
        cout << arr[i] << endl;
    cout << endl;
}

void sovle(int x, int y) {
    FOR(i, 0, 4) {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if (arr[xx][yy] == '0') {
            arr[xx][yy] = '.';
            printArray();
            sovle(xx, yy);
            arr[xx][yy] = '0';
        } else if (arr[xx][yy] == 'e') {
            cout << "Success. This is just only the first successful exiting road." << endl;
            exit(0);
        }
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    string s;
    n = 0; m = 0;
    arr.push_back("tmp");
    while (cin >> s) {
        cout << s << endl;
        s = '1' + s;
        s.push_back('1');
        n++;
        m = s.length();
        arr.push_back(s);
    }
    cout << endl;
    s = "";
    n += 2;
    FOR(i, 0, m) s.push_back('1');
    arr.push_back(s);
    arr[0] = s;
    int x = 0, y = 0;
    FOR(i, 0, n) {
        cout << arr[i] << endl;
        FOR(j, 0, m) {
            if (arr[i][j] == 'm') {
                x = i; y = j;
            }
        }
    }
    cout << endl;
    sovle(x, y);
    cout << "Failure" << endl;
    return 0;
}