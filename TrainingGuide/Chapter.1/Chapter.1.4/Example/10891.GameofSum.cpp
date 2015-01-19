#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    freopen("10891.GameofSum.dat", "r", stdin);

    int n; cin >> n;
    while (n) {
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        vector< vector<int> > best(n, vector<int>(n, 0));
        vector< vector<int> > sum(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++)
            best[i][i] = a[i], sum[i][i] = a[i];
        for (int i = 0; i < n; i++)
            for (int j = i+1; j < n; j++)
                sum[i][j] = sum[i][j-1] + a[j];

        for (int len = 2; len <= n; len ++) 
            for (int i = 0; i+len-1 < n; i++) {
                int j = i + len - 1;
                // why m starts from 0? take all
                int m = 0;
                // best[i][j] [i, j] 
                // need to iterate in [i+k, j] and [i, j-k] 
                // k should >= 1, for "one or more"
                for (int k = 1; i + k <= j; k++) m = min(m, best[i+k][j]);
                for (int k = 1; j - k >= i; k++) m = min(m, best[i][j-k]);
                best[i][j] = sum[i][j] - m;
            }

        int ans = best[0][n-1] - (sum[0][n-1] - best[0][n-1]);

        cout << ans << endl;

        cin >> n;
    }

    return 0;
}
