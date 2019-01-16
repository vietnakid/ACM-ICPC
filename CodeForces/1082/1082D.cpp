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
    for (__typeof(b) i = (a); i < (b); i++)
#define FORE(i, a, b) \
    for (__typeof(b) i = (a); i <= (b); i++)
#define FORD(i, a, b) \
    for (__typeof(b) i = (a); i >= (b); i--)
#define REP(i, begin, end) \
    for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))


#define INF 1000000007
#define INFLL 1000000000000000000
#define esp 1e-9
#define PI 3.14159265

ll nMod = 1e9 + 7;

inline ll GCD(ll a, ll b) {while (b != 0) {ll c = a % b; a = b; b = c;} return a;};
inline ll LCM(ll a, ll b) {return (a / GCD(a,b)) * b;};

int n;
vii arr;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    // freopen("/Users/macbook/Desktop/MyCPPLibrary/error", "w", stderr);
    cin >> n;
    arr.resize(n);
    int num1 = 0, sumDiff1 = 0, numDif1 = 0;

    FOR(i, 0, n) {
        int x;
        cin >> x;
        if (x == 1) num1++;
        else {
            numDif1++;
            sumDiff1 += x - 2;
        } 
        arr[i] = {x, i+1};
    }
    sort(arr.begin(), arr.end());

    if (num1 == 0) {
        cout << "YES " << numDif1-1 << endl;
        cout << n-1 << endl;
        if (numDif1-1 != 0) {
            
            FOR(i, 1, n) {
                cout << i << " " << i + 1 << endl;
            }
        }
        
    } else if (num1 == 1) {
        cout << "YES " << numDif1 << endl;
        cout << n-1 << endl;
        if (numDif1 != 0) {
            
            cout << arr[0].second << " " << arr[1].second << endl;
            FOR(i, 1, n-1) {
                cout << arr[i].second << " " << arr[i + 1].second << endl;
            }
        }
    } else {
        if (num1 - 2 > sumDiff1) {
            cout << "NO" << endl;
            return 0;
        }
        cout << "YES " << numDif1+1 << endl;

        int pos = 0;
        FOR(i, 0, n) {
            if (arr[i].first > 1) {
                pos = i;
                break;
            }
        }

        cout << n-pos-1 + pos << endl;

        FOR(i, pos, n-1) {
            cout << arr[i].second << " " << arr[i+1].second << endl;
            arr[i].first--;
            arr[i+1].first--;
        }
        // cerr << pos << endl;
        int _pos = pos;
        cout << arr[0].second << " " << arr[n-1].second << endl;
        arr[n-1].first--;
        FOR(i, 1, _pos) {
            if (arr[pos].first > 0) {
                cout << arr[i].second << " " << arr[pos].second << endl;
                arr[pos].first--;
            } else {
                pos++;
                i--;
            }
        }
    }
    return 0;
}