
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    freopen("11078.OpenCreditSystem.dat", "r", stdin);
    
    int T; cin >> T;

    for (int i = 0; i < T; i++) {
        int n; cin >> n;
        
        int maxTillNow = 0;
        int maxTotal = 0;
        for (int j = 0; j < n; j ++) {
            int t; scanf("%d", &t);
            
            if (j == 0) 
                maxTillNow = t;
            else {
                if (j == 1)
                    maxTotal = maxTillNow - t;
                else 
                    maxTotal = max(maxTotal, maxTillNow - t); 
                maxTillNow = max(t, maxTillNow);
            }
        }

        cout << maxTotal << endl;
    }
    
    return 0;
}
