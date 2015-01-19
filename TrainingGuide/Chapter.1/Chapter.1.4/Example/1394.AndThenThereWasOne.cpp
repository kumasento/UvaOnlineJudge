#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    freopen("1394.AndThenThereWasOne.dat", "r", stdin);

    int n, k, m; cin >> n >> k >> m;
    while (!(!n && !k && !m)) {

        int ans = 0;

        // f[i] = (f[i-1] + k) % i
        for (int i = 2; i < n; i++)
            ans = (ans + k) % i;
        
        // now ans = f[n-1]
        // for the first person is not killed by k steps
        ans = (ans + m) % n + 1;

        cout << ans << endl;

        cin >> n >> k >> m;
    }

    return 0;
}
