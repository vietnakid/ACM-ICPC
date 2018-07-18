#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
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

int n, m, l;
vii arr;

// bool canLight(ll basex, ll basey) {
//     double y = (double)basex / (double)basey;
//     // cerr << y << endl;
//     int cnt = 0;
//     double now = 0;
//     for(int index = 0; index < m-1; index += 2) {
//         // cerr << "WTF " << arr[index+1].second << " " << y << endl;
//         if (arr[index+1].second <= y) {
//             cnt++;
//             now = arr[index+2].first;
//             if (now >= n) {
//                 return cnt <= l;
//             }
//         } else {
//             if (arr[index].second > y) {
//                 return false;
//             }
//             double x = (y - (double)(arr[index].second)) + (double)(arr[index].first);
//             double left = x - y;
//             // cout << " x, y " << x << " " << y << " " << now << endl;
//             if (left <= now) {
//                 now = x + y;
//             } else {
//                 return false;
//             }
//             cnt++;
//             if (now >= n) {
//                 return cnt <= l;
//             }
//             if (arr[index+2].second > y) {
//                 return false;
//             }
//             if (now >= (double)(arr[index+2].first)) {
//                 continue;
//             }
//             x = (double)(arr[index+2].first) - (y - (double)(arr[index+2].second));
//             left = x - y;
//             // cout << " x, y " << x << " " << y << " " << now << endl;
//             if (left <= now) {
//                 now = x + y;
//             } else {
//                 return false;
//             }
//             cnt++;
//             if (now >= n) {
//                 return cnt <= l;
//             }
//         }
//     }
//     // cerr << y << " " << cnt << endl;
//     if (now < n) {
//         return false;
//     }
    
//     return cnt <= l;
// }


bool canLight2(ll basex, ll basey) {
    double y = (double)basex / (double)basey;
    // cerr << "y = " << y << endl;
    double now = 0;
    int oldIndex = -1;
    FOR(i, 0, l) {
        double x = now + y;
        ii e = {(int)(x+1), 0};
        vii::iterator it = upper_bound(arr.begin(), arr.end(), e);
        int index = it - arr.begin();
        // cerr << "index = " << index << endl;
        index--;
        if (index == m) {
            index--;
        }
        bool isFound = false;
        for(; index > oldIndex; index--) {
            if (arr[index+1].second <= y || arr[index].second <= y) {
                double left, _now;
                if (arr[index].second >= y && arr[index+1].second <= y) {
                    x = arr[index].second - y + arr[index].first;
                    left = x - y;
                    _now = x + y;
                } else if (arr[index].second <= y && arr[index+1].second >= y) {
                    x = y - arr[index].second + arr[index].first;
                    left = x - y;
                    _now = x + y;
                } else if (arr[index].second <= y) {
                    double _y = arr[index].second;
                    x = arr[index].first;
                    left = x - _y;
                    _now = x + _y;
                } else if (arr[index+1].second <= y) {
                    double _y = arr[index+1].second;
                    x = arr[index+1].first;
                    left = x - _y;
                    _now = x + _y;
                }
                // cerr << "index = " << index << " x = " << x << " now = " << now << " left = " << left << endl;
                if (left <= now) {
                    now = _now;
                } else {
                    continue;
                }
                if (now >= n) {
                    // cerr << "true" << endl;
                    return true;
                }
                oldIndex = index;
                isFound = true;
                break;
            }
        }
        if (!isFound) {
            return false;
        }
    }
    // cerr << "false" << endl;
    return false;
}

bool canLight(double y) {
    // double y = (double)basex / (double)basey;
    // cerr << y << endl;
    vector<double> now;
    now.push_back(0);
    int res = INF;
    FOR(i, 0, m) {
        ii u = arr[i];
        ii v = arr[i+1];
        if (v.second >= y+0.000001 && u.second >= y+0.000001) {
            continue;
        }
        // cerr << "check 1 " << i << endl;
        if (v.second > u.second) {
            double left = u.first - u.second;
            vector<double>::iterator it = lower_bound(now.begin(), now.end(), left-0.0000001);
            if (it == now.end()) {
                continue;
            }
            int index = it - now.begin() + 1;
            double _now;
            if (y > v.second) {
                 _now = v.first + v.second;
            } else {
                double x = y - u.second + u.first;
                _now = x + y;
            }
            if (_now+0.000001 >= n) {
                res = min(res, index);
            } else {
                if (index == now.size()) {
                    now.push_back(_now);
                } else {
                    now[index] = _now;
                }
            }
        } else {
            double _now = v.first + v.second;
            double left;
            if (y > u.second) {
                left = u.first - u.second;
            } else {
                double x = u.second - y + u.first;
                left = x - y;
            }
            vector<double>::iterator it = lower_bound(now.begin(), now.end(), left-0.0000001);
            if (it == now.end()) {
                continue;
            }
            int index = it - now.begin() + 1;
            if (_now+0.000001 >= n) {
                res = min(res, index);
            } else {
                if (index == now.size()) {
                    now.push_back(_now);
                } else {
                    now[index] = _now;
                }
            }
        }
    }
    // cerr << "res = " << res << endl;
    return res <= l;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
    setbuf(stdout, NULL);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    int TC; cin >> TC;
    FORE(tc, 1, TC) {
        cout << "Case #" << tc << endl;
        cin >> n >> m >> l;
        ll high = 0, low = 0;
        arr = vii();
        FORE(i, 0, m) {
            ll u, v;
            cin >> u >> v;
            high = max(high, v);
            arr.push_back({u, v});
        }
        high *= 2;
        ll res = -1;
        FOR(tt, 0, 40) {
            ll mid = (high + low) / 2;
            double y = (double)mid / 2.0;
            // if (canLight(midx, midy) != canLight2(midx, midy)) {
            //     cerr << "waksdjfklsajfladsjfkadsjlkfjadslfj" << endl;
            // }
            if (canLight(y)) {
                res = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        if (res < 0) {
            cout << "-1" << endl;
        } else {
            if (res % 2 == 0) {
                cout << res/2 << " " << 1 << endl;
            } else {
                cout << res << " " << 2 << endl;
            }
        }
    }
    return 0;
}