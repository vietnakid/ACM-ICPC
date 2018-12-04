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

int cnt = 0;
set<pair<ii, int> > st;

bool isLeap(int year) {
    if (year % 400 == 0) return true;
    if (year % 100 == 0 && year % 400 != 0) return false;
    if (year % 4 == 0 && year % 100 != 0) return true;
    if (year % 4 != 0) return false;
    return false;
}

void checkValid(vi arr) {
    int day = arr[0] * 10 + arr[1];
    int month = arr[2] * 10 + arr[3];
    int year = arr[4] * 1000 + arr[5] * 100 + arr[6] * 10 + arr[7];

    bool check = false;
    if (month != 2 && month <= 12 && month >= 1 && year >= 1) {
        if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
            if (day <= 31 && day >= 1) {
                check = true;
            }
        } else {
            if (day <= 30 && day >= 1) {
                check = true;
            }
        }
    } else if (month == 2 && year >= 1) {
        if (day <= 28 && day >= 1) {
            check = true;
        }
        if (day == 29 && isLeap(year)) {
            check = true;
        }
    }
    if (check) {
        st.insert({{year, month}, day});
        // REP(i, arr.begin(), arr.end()) {
        //         cerr << *i << " ";
        //     }
        //     cerr << endl;
        // cerr << day << " " << month << " " << year << endl;
    }
}

string toStr(int n, int l) {
    string res = "";
    while (n > 0) {
        char c = (n % 10) + '0';
        res.push_back(c);
        n /= 10;
    }
    reverse(res.begin(), res.end());
    while (res.size() < l) {
        res = "0" + res;
    }
    return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    // freopen("/Users/macbook/Desktop/MyCPPLibrary/error", "w", stderr);
    int TC;
    cin >> TC;
    while (TC--) {
        st.clear();
        string a, b, c;
        cin >> a >> b >> c;
        // cout << a << " " << b << " " << c << endl;
        vector<int> arr;
        arr.push_back(a[0] - '0');
        arr.push_back(a[1] - '0');
        arr.push_back(b[0] - '0');
        arr.push_back(b[1] - '0');
        arr.push_back(c[0] - '0');
        arr.push_back(c[1] - '0');
        arr.push_back(c[2] - '0');
        arr.push_back(c[3] - '0');
        sort(arr.begin(), arr.end());
        cnt = 0;
        do {
            checkValid(arr);
        } while (next_permutation(arr.begin(), arr.end()));
        cout << st.size() << " ";
        if (st.size() > 0) {
            pair<ii, int> res = *st.begin();
            int day = res.second;
            int month = res.first.second;
            int year = res.first.first;
            cout << toStr(day, 2) << " " << toStr(month, 2) << " " << toStr(year, 4);
        } 
        cout << endl;
    }
    
    return 0;
}