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
typedef set<int> si;

#define FOR(i, a, b) \
for (int i = (a); i < (b); i++)
#define FORE(i, a, b) \
for (int i = (a); i <= (b); i++)

#define INF 2e9 // 2e9
#define INFLL 2e18 // 2e18
#define esp 1e-9
#define PI 3.14159265

inline ll GCD(ll a, ll b) {while (b != 0) {ll c = a % b; a = b; b = c;} return a;};
inline ll LCM(ll a, ll b) {return (a / GCD(a,b)) * b;};

priority_queue< ll, vector<ll>, greater<ll> > heap;

vii arr(0), brr(0);

ll findMax(int lefta, int righta, int leftb, int rightb) {
    if (lefta > righta)
        return 0;
    int mid = (lefta + righta) / 2;
    ll maxValue = -INFLL;
    int index = -1;
    FORE(i, leftb, rightb) {
        if (brr[i].second - arr[mid].second >= 0) {
            ll value = (ll)(brr[i].first - arr[mid].first) * (ll)(brr[i].second - arr[mid].second);
            if (value > maxValue) {
                maxValue = value;
                index = i;
            }
        }
    }
//    cout << lefta << " "<< righta << " " << mid << " " << index << " " << maxValue << '\n';
    ll maxLeft = 0, maxRight = 0;
    if (lefta < righta) {
        if (index != -1) {
            maxLeft = findMax(lefta, mid - 1, leftb, index);
            maxRight = findMax(mid+1, righta, index, rightb);
        } else {
            maxLeft = findMax(lefta, mid - 1, leftb, rightb);
//            maxRight = findMax(mid+1, righta, leftb, rightb);
        }
    }
    
    maxValue = max(maxValue, maxRight);
    maxValue = max(maxValue, maxLeft);
    
    return maxValue;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
//    freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
    // freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    int n, m;
    cin >> n >> m;
    vii tmp;
    FOR(i, 0, n) {
        int p, d;
        cin >> p >> d;
        arr.push_back(make_pair(d, p));
    }
    sort(arr.begin(), arr.end());
    tmp.clear();
    tmp.push_back(*arr.begin());
    for (vii::iterator it = arr.begin()+1; it != arr.end(); it++) {
        if (tmp[tmp.size()-1].second > it->second) {
            tmp.push_back(*it);
        }
    }
    arr = tmp;
    
    FOR(i, 0, m) {
        int p, d;
        cin >> p >> d;
        brr.push_back(make_pair(d, p));
    }
    
    sort(brr.begin(), brr.end(), greater<ii>());
    tmp.clear();
    tmp.push_back(*brr.begin());
    for (vii::iterator it = brr.begin()+1; it != brr.end(); it++) {
        if (tmp[tmp.size()-1].second < it->second) {
            tmp.push_back(*it);
        }
    }
    brr = tmp;
    reverse(brr.begin(), brr.end());
    ll res = findMax(0, arr.size() - 1, 0, brr.size() - 1);
    if (res < 0)
        res = 0;
    
    cout << res << '\n';
    return 0;
}
