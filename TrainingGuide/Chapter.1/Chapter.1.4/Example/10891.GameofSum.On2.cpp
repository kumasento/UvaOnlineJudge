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

        vector< vector<int> > dp(n, vector<int>(n, 0));
        vector< vector<int> > sum(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++) dp[i][i] = a[i];
        for (int i = 0; i < n; i++) sum[i][i] = a[i];
        for (int i = 0; i < n; i++)
            for (int j = i+1; j < n; j++)
                sum[i][j] = sum[i][j-1] + a[j];

        vector< vector<int> > f(n, vector<int>(n, 0));
        vector< vector<int> > g(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++) f[i][i] = a[i];
        for (int i = 0; i < n; i++) g[i][i] = a[i];
        

        // f[i][j] = min(f[i+1][j], dp[i][j]);
        // g[i][j] = min(g[i][j-1], dp[i][j]);
        //
        for (int l = 2; l <= n; l++) 
            for (int i = 0; i+l-1 < n; i++) {
                int j = i + l - 1;
                int m = 0;
                m = min(f[i+1][j], m);
                m = min(g[i][j-1], m);

                dp[i][j] = sum[i][j]- m;
                f[i][j] = min(f[i+1][j], dp[i][j]);
                g[i][j] = min(g[i][j-1], dp[i][j]);
            }   

        cout << dp[0][n-1] - (sum[0][n-1] - dp[0][n-1]) << endl;

        cin >> n;
    }

    return 0;
}
