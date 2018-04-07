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

int n, k, r, k2;
int a[100000], b[100000];
int dem, num, len, bcnn;
set<int> s;
set<int>::iterator it;

int main(){
   // freopen("input", "r", stdin);
 //   freopen(".out", "w", stdout);
    ios_base::sync_with_stdio (false);
    cin.tie();
    srand(time(0));
    cin >> n >> r >> k;
    k2 = k;
    if (k==1){
        if (n==1) cout << 1 << endl;
        else cout << -1 << endl;
        return 0;
    }
    FORE(i,1,(int)sqrt(k)+1)
    if (k%i==0){
        if (i<=r) a[++dem] = i;
        if (i*i!=k && k/i<=r) a[++dem] = k/i;
    }
    FORE(i,2,(int)sqrt(k)+1)
    if (k%i==0){
        int so = 1;
        while (k%i==0){
            so*=i;
            k/=i;
        }
        if (so<=r) s.insert(so);
    }
    if (k>1 && k<=r) s.insert(k);
    // for(it=s.BG; it!=s.ED; it++) cout << *it << " "; cout << endl;

    std::vector<int> arr(s.size());
    int index = 0;
    for(it=s.BG; it!=s.ED; it++, index++) {
        arr[index] = *it;
    }

    std::vector<int> permu(s.size());
    FOR(i, 0, s.size()) {
        permu[i] = i;
    }

    do {
        set<int> tmp;
        int curMultiple = 1;
        FOR(i, 0, arr.size()) {
            if (curMultiple * arr[permu[i]] <= r) {
                curMultiple *= arr[permu[i]];
            } else {
                tmp.insert(curMultiple);
                curMultiple = arr[permu[i]];
            }
            // cout << arr[permu[i]] << " ";
        }
        tmp.insert(curMultiple);
        // cout << " ---> ";
        // for(it=tmp.BG; it!=tmp.ED; it++) cout << *it << " "; cout << endl;
        if (tmp.size() < s.size()) s = tmp;
    } while (next_permutation(permu.begin(), permu.end()));

    // for(it=s.BG; it!=s.ED; it++) cout << *it << " "; cout << endl;
    
    FORE(i,1,dem){
        if (s.size() >= n) break;
        s.insert(a[i]);
    }
    if (s.size()!=n) cout << -1 << endl;
    else{
        bcnn = 1;
        for(it=s.BG; it!=s.ED; it++){
            int uoc = __gcd(bcnn, *it);
            bcnn = bcnn / uoc * (*it);
        }
        if (bcnn != k2) cout << -1 << endl;
        else{
            for(it=s.BG; it!=s.ED; it++) cout << *it << " ";
        }
    }
}