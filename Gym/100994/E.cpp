using namespace std;
#include<bits/stdc++.h>

#define BG begin()
#define ED end()
#define st first
#define nd second
#define PB push_back
#define PF push_front
#define FOR(i,a,b) for (long long i=a;i<b;i++)
#define FORE(i,a,b) for (long long i=a;i<=b;i++)
#define FORD(i,a,b) for (long long i=a;i>=b; i--)
#define TR(c, it) for(typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
#define debug(x) { cout << #x << " = "; cout << (x) << endl; }
#define ri(n)({\
    int neg=0;\
    n=0;\
    char ch;\
    for(ch=getchar(); ch<'0' || ch>'9'; ch=getchar()) if (ch=='-') neg=1-neg;\
    n=ch-48;\
    for(ch=getchar(); ch>='0' && ch<='9'; ch=getchar()) n=(n<<3)+(n<<1)+ch-48;\
    if (neg) n=-n;\
})

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> II;
typedef pair<ll,ll> LL;
typedef pair<int,II> iII;
typedef pair<II,int> IIi;
const ll INF=1000000000+7;
const double esp=1e-13;
const ld PI = acos(-1.0);

struct node{
    ll gt;
    int vt;
};

struct node2{
    ll l;
    ll r;
    ll sum;
    ll ans;
};

bool cmp(node a, node b){
    return a.gt > b.gt;
}

const int maxn = 1e5;

node2 f[8 * maxn + 10];
node a[maxn + 10], b[maxn + 10];
ll ans[maxn + 10];
int n, m;

void build(int k, int l, int r){
    if (l == r){
        f[k].l = f[k].r = f[k].sum = f[k].ans = -INF * 1000000;
        return;
    }
    int m = (l + r)/2;
    build(k * 2, l, m);
    build(k * 2 + 1, m + 1, r);
    f[k].l = max(f[k * 2].l, f[k * 2].sum + f[k * 2 + 1].l);
    f[k].r = max(f[k * 2].r + f[k * 2 + 1].sum, f[k * 2 + 1].r);
    f[k].sum = f[k * 2].sum + f[k * 2 + 1].sum;
    f[k].ans = max(f[k * 2].ans, f[k * 2 + 1].ans);
    f[k].ans = max(f[k].ans, f[k * 2].r + f[k * 2 + 1].l);
}

void update(int k, int l, int r, int i, ll v){
    if (l == i && i==r){
       // debug(k);
        f[k].l = f[k].r = f[k].sum = f[k].ans = v;
        return;
    }
    int m = (l + r)/2;
    if (i<=m) update(k * 2, l, m, i, v);
    else update(k * 2 + 1, m + 1, r, i, v);
    f[k].l = max(f[k * 2].l, f[k * 2].sum + f[k * 2 + 1].l);
    f[k].r = max(f[k * 2].r + f[k * 2 + 1].sum, f[k * 2 + 1].r);
    f[k].sum = f[k * 2].sum + f[k * 2 + 1].sum;
    f[k].ans = max(f[k * 2].ans, f[k * 2 + 1].ans);
    f[k].ans = max(f[k].ans, f[k * 2].r + f[k * 2 + 1].l);
}

int main(){
 //   freopen("codeforces.inp", "r", stdin);
 //   freopen(".out", "w", stdout);
    ios_base::sync_with_stdio (false);
    cin.tie();
    cin >> n >> m;
    FORE(i, 1, n){
        cin >> a[i].gt;
        a[i].vt = i;
    }
    FORE(i, 1, m){
        cin >> b[i].gt;
        b[i].vt = i;
    }
    sort(a + 1, a + n + 1, cmp);
    sort(b + 1, b + m + 1, cmp);

    int j = 1;
    build(1, 1, n);
    FORE(i, 1, m){
        while (j<=n && a[j].gt >= b[i].gt){
            update(1, 1, n, a[j].vt, a[j].gt);
            j++;
        }
       // cout << b[i].gt << "\n";
        ans[ b[i].vt ] = f[1].ans;
    }
    //debug(f[1].ans);
    //debug(f[6].ans);
    FORE(i, 1, m)
    if (ans[i] == -INF * 1000000) cout << 0 << " ";
    else cout << ans[i] << " ";
}