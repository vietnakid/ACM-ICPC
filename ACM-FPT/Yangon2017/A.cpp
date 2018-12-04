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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    // freopen("/Users/macbook/Desktop/MyCPPLibrary/error", "w", stderr);
    int TC;
    scanf("%d", &TC);
    int pow2[20];
    pow2[0] = 1;
    for(int i = 1; i < 20; i++) {
        pow2[i] = 2 * pow2[i-1];
    }
    for(int tc = 1; tc <= TC; tc++) {
        printf("Case %d:\n", tc);
        int n;
        scanf("%d", &n);
        n--;
        int numNode = pow2[n+1];
        char arr[numNode+1][2*n+1];
        int endLine[numNode+1];
        memset(endLine, 0, sizeof(endLine));
        memset(arr, 0, sizeof(arr));
        for(int i = 0; i < n; i++) {
            int s = pow2[i];
            int e = s + pow2[i+1];
            while (e <= numNode) {
                arr[s][2*i] = '_';
                arr[e][2*i] = '_';
                endLine[s] = 2*i+1;
                endLine[e] = 2*i+1;
                for(int j = s+1; j <= e; j++) {
                    arr[j][2*i+1] = '|';
                    endLine[j] = 2*i+2;
                }
                s += pow2[i+2];
                e = s + pow2[i+1];
            }
        }
        arr[pow2[n]][2*n] = '_';
        endLine[pow2[n]] = 2*n+1;
        for (int i = 1; i <= numNode; i++) {
            printf("o--|");
            for(int j = 0; j < endLine[i]; j++) {
                if (arr[i][j] == '|') {
                    printf("|");
                } else if (arr[i][j] == '_') {
                    printf("__");
                } else {
                    if (j % 2 == 0)
                        printf(" ");
                    printf(" ");
                }
            }
            printf("\n");
        }
    }
    return 0;
}