#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "r", stdin);
    long long a;
    while (cin >> a){
		cout << a << endl;
        // if (!a && !b) break;
        // if (a > b) swap(a,b); // a:寬  b:長
        // long long ans = a*b*(a-1) + a*b*(b-1);  //寬 + 長
        // ans += 4* (2*(a*(a-1)*(a-2)/6) + (b-a+1)*a*(a-1)/2); // 對角線
        // printf("%lld\n",ans);
    }
    return 0;
}