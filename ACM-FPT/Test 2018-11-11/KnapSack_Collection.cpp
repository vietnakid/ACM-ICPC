#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
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

inline ll GCD(ll a, ll b) {while (b != 0) {ll c = a % b; a = b; b = c;} return a;};
inline ll LCM(ll a, ll b) {return (a / GCD(a,b)) * b;};


ll n, s, t;
vl res;

int findNext(int pos, vi & luggage) {

    int res = -1;
    if (luggage.size() == 0) return res;
    if (pos > luggage[luggage.size() - 1]) {
        res = luggage[0];
        luggage.erase(luggage.begin());
    } else {
        vi::iterator posres = lower_bound(luggage.begin(), luggage.end(), pos);
        res = *(posres);
        luggage.erase(posres);

    }


    return res;
}

ll findRes(int pos, vi luggage) {
    //cout << " pos =   " << pos << " " << luggage[luggage.size() - 1] << endl;
    ll res = 0;
    int x;
    while ( (x = findNext(pos, luggage)) != -1) {
        if (x >= pos) res += x - pos;
        else {
            res += s - pos + x;
        }
        res += t;
        pos = (x + t) % s;
    }
    //cout << res << endl;
    return res;
}

int main()
{
    cin >> n >> s >> t;

    vi arr, luggage;
    arr = vi(s, 0);
    res = vl(s, INFLL);
    REP(i, 0, n) {
        int x;
        cin >> x;
        luggage.push_back(x);
        arr[x]++;
    }

    sort(luggage.begin(), luggage.end());

    if (arr[s-1] != 0)
        res[s-1] = findRes(s-1, luggage);

    for (int i = s-2; i >= 0; i--) {
        res[i] = res[i+1] + 1;
        if (arr[i] != 0)
            res[i] = findRes(i, luggage);
    }

    int i = s-1;
    while (res[i] >= INFLL) {
        res[i] = res[(i+1) % s] + 1;
        i--;
    }


    ll resmin = INFLL, resmax = -INFLL, resavg = 0;
    REP(i, 0, s) {
        resmin = min(resmin, res[i]);
        resmax = max(resmax, res[i]);
        resavg += res[i];
    }

    ll gcd = GCD(resavg, s);
    cout << resmin << endl << resmax << endl << resavg/gcd << "/" << s/gcd << endl;
    return 0;
}