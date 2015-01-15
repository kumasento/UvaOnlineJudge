#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define EVEN(x) (((x) % 2 == 0) ? 1 : 0)

int sum(vector< vector<int> > &mat, int i, int j) {
    int ans = 0;
    int N = mat.size() - 1;
    if (i-1 >= 0) ans += mat[i-1][j];
    if (j-1 >= 0) ans += mat[i][j-1];
    if (i+1 <= N) ans += mat[i+1][j];
    if (j+1 <= N) ans += mat[i][j+1];
    
    return ans;
}

void print(vector< vector<int> > &mat) {
    for (int i = 0; i < mat.size(); i++) {
        for (int j = 0; j < mat[i].size(); j++) 
            cout << mat[i][j] << ' ';
        cout << endl;
    }
    cout << endl;
}

int solve(vector< vector<int> > &mat) {
    // iterate from 0 to 2^N
    int N = mat.size();
    int maxmin = N * N + 100;
    int min = maxmin;
    for (int n = 0; n < (2 << N); n++) {
        vector< vector<int> > tmp(mat);

        int count = 0;
        // assign
        for (int i = 0; i < N; i++) 
            if (((n >> i) & 1) && tmp[0][i] == 0)
                tmp[0][i] = 1, count ++;

        int ok = 1;
        for (int i = 1; i < N && ok; i++)
            for (int j = 0; j < N && ok; j++) 
                if (!EVEN(sum(tmp, i-1, j))) {
                    if (tmp[i][j] == 0)
                        tmp[i][j] = 1, count ++; // flip 
                    else
                        ok = 0;
                }
                        
        if (!ok) continue;

        int i;
        for (i = 0; i < N; i++)
            if (!EVEN(sum(tmp, N-1, i)))
                break;

        if (i == N && count < min) 
            min = count;
    }

    return (min == maxmin) ? -1 : min;
}

int main() {
    freopen("11464.EvenParty.dat", "r", stdin);

    int T; cin >> T;
    for (int t = 0; t < T; t++) {
        int N; cin>>N;
        vector< vector<int> > mat(N, vector<int>(N));

        for (int i = 0; i < N; i++) 
            for (int j = 0; j < N; j++)
                cin >> mat[i][j];

        cout << "Case " << t+1 << ": " << solve(mat) << endl;
    }

    return 0;
}
