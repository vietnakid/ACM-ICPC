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

    int main()
    {
        ios_base::sync_with_stdio(false);
        cin.tie();
        // freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
        // freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
        int n, q;
        cin >> n >> q;
        vi arr(n+1);
        vi next(n+1);
        vvi pos(q+1, vi(2, -1));
        vi posMark;
        FOR(i, 0, n) {
            cin >> arr[i];
            next[i] = i+1;
            if (pos[arr[i]][0] == -1) {
                pos[arr[i]][0] = i;
                pos[arr[i]][1] = i;
            } else {
                pos[arr[i]][1] = i;
            }
            if (arr[i] == 0) {
                posMark.push_back(i);
            }
        }
        if (pos[q][0] == -1 && posMark.size() == 0) {
            cout << "NO" << endl;
            return 0;
        }
        FORD(i, q, 1) {
            if (pos[i][0] == -1) {
                while (posMark.size() > 0) {
                    int x = posMark[posMark.size() - 1];
                    posMark.pop_back();
                    if (arr[x] == 0) {
                        arr[x] = i;
                        break;
                    }
                }
            } else {
                int l = pos[i][0];
                int r = pos[i][1];
                for(int j = l; j < r;) {
                    if (arr[j] == 0) {
                        arr[j] = i;
                    }
                    if (arr[j] < i) {
                        cout << "NO" << endl;
                        return 0;
                    }
                    j = next[j];
                }
                next[l-1] = r+1;
            }
        }
        cout << "YES" << endl;
        FOR(i, 0, n) {
            cout << max(arr[i], 1) << " ";
        }
        cout << endl;
        return 0;
    }