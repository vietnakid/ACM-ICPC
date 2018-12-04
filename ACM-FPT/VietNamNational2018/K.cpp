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

int q;

map<int, pair<ii, ii> >  mp;

int doc[5001], ngang[5001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    freopen("/Users/macbook/Desktop/MyCPPLibrary/error", "w", stderr);
    scanf("%d", &q);
    memset(doc, 0, sizeof(doc));
    memset(ngang, 0, sizeof(ngang));

    FORE(t, 1, q) {
        int x;
        cin >> x;
        if (x == 1) {
            int x1, y1, x2, y2;
            scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
            if (x1 > x2) {
                swap(x1, x2);
            }
            if (y1 > y2) {
                swap(y1, y2);
            }

            ii p1 = {x1, y1};
            ii p2 = {x2, y2};
            mp[t] = {p1, p2};

            ngang[x1]--;
            ngang[x2]++;

            doc[y1]--;
            doc[y2]++;
        } else if (x == 2) {
            int index;
            scanf("%d", &index);
            ii p1 = mp[index].first;
            ii p2 = mp[index].second;

            ngang[p1.first]++;
            doc[p1.second]++;

            ngang[p2.first]--;
            doc[p2.second]--;
        } else {
            int x1, y1, x2, y2;
            scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
            if (x1 > x2) {
                swap(x1, x2);
            }
            if (y1 > y2) {
                swap(y1, y2);
            }

            int sumdoc = 0;
            FORE(i, y1, y2) {
                sumdoc += doc[i];
            }

            int sumngang = 0;
            FORE(i, x1, x2) {
                sumngang += ngang[i];
            }

            cerr << sumdoc << " " << sumngang << endl;
            if (sumdoc != 0 || sumngang != 0) {
                printf("N");
            } else {
                printf("Y");
            }
        }
    }
    return 0;
}