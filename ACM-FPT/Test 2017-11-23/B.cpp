#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector< vector<int> > vvi;
typedef vector<ll> vl;
typedef vector< vector<ll> > vvl;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;

#define REP(i, a, b) \
    for (int i = (a); i < (b); i++)
#define TRvi(c, it) \
    for (vi::iterator it = (c).begin(); it != (c).end(); it++)
#define TRvii(c, it) \
    for (vii::iterator it = (c).begin(); it != (c).end(); it++)

#define INF 2000000000 // 2e9
#define INFLL 2000000000000000000 // 2e18
#define esp 0.0000000001
#define PI 3.14159265

inline ll GCD(ll a, ll b) {while (b != 0) {ll c = a % b; a = b; b = c;} return a;};
inline ll LCM(ll a, ll b) {return (a / GCD(a,b)) * b;};

priority_queue< ll, vector<ll>, greater<ll> > heap;

int main()
{
    vector <pair<pair<double, double>, string > > teams, tmp, res(4);
    int n;
    double r = INT_MAX;
    cin >> n;
    REP(i, 0, n) {
        string s;
        double a, b;
        cin >> s >> a >> b;
        teams.push_back(make_pair(make_pair(b, a) , s));
    }
    REP(i, 0, n) {
        tmp = teams;
        tmp.erase(tmp.begin() + i);
        sort(tmp.begin(), tmp.end());
        double tt = teams[i].first.second + tmp[0].first.first + tmp[1].first.first + tmp[2].first.first;
        if (tt < r) {
            r = tt;
            res[0] = teams[i];
            res[1] = tmp[0];
            res[2] = tmp[1];
            res[3] = tmp[2];
        }
    }
    cout<< r << endl;
    REP(i, 0, 4) {
        cout << res[i].second << endl;
    }
    return 0;
}
