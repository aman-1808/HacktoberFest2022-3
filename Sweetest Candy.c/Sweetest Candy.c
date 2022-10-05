//https://www.codechef.com/problems/SUBMAXA
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int maxn = 2002002;
int s[maxn], a[maxn];
ll sum[maxn];
int main(void) {
//    freopen("in.txt", "r", stdin);
    int T; scanf("%d", &T);
    while (T--) {
        int n; scanf("%d", &n);
        for (int i=0; i<n; i++) scanf("%d", &a[i]);
        for (int i=0; i<=n; i++) sum[i] = 0;
        s[0] = -1;
        int top = 0;
        for (int i=0; i<=2*n; i++) {
            while (top && (i==2*n || a[i%n] >= a[s[top]%n])) {
                int v = a[s[top]%n];
                if (s[top-1] < n) {
                    int l = min(n-1, s[top]) - s[top-1];
                    int x = i-1 - s[top] + 1;
                    int y = s[top]<n ? 1: (s[top]-(n-1)+1);
                    sum[y] += v, sum[x+y] -= v;
                    sum[l+y] -= v, sum[l+x+y] += v;
                }
                top--;
            }
            s[++top] = i;
        }
        for (int i=1; i<=n; i++) sum[i] += sum[i - 1];
        for (int i=1; i<=n; i++) sum[i] += sum[i - 1];
        for (int i=1; i<=n; i++) printf("%lld%c", sum[i], " \n"[i == n]);
    }
    return 0;
}
