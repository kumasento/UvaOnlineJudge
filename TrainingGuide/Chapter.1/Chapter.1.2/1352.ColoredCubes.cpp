#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

int pose[][6] = {
    {2,1,5,0,4,3},
    {2,0,1,4,5,3},
    {2,4,0,5,1,3},
    {2,5,4,1,0,3},
    {4,2,5,0,3,1},
    {5,2,1,4,3,0},
    {1,2,0,5,3,4},
    {0,2,4,1,3,5},
    {0,1,2,3,4,5},
    {4,0,2,3,5,1},
    {5,4,2,3,1,0},
    {1,5,2,3,0,4},
    {5,1,3,2,4,0},
    {1,0,3,2,5,4},
    {0,4,3,2,1,5},
    {4,5,3,2,0,1},
    {1,3,5,0,2,4},
    {0,3,1,4,2,5},
    {4,3,0,5,2,1},
    {5,3,4,1,2,0},
    {3,4,5,0,1,2},
    {3,5,1,4,0,2},
    {3,1,0,5,4,2},
    {3,0,4,1,5,2}};

int N = 6;
int NP = 24;

int MinSum = N * N + 100;

void dfs(vector< vector<string> > &cubes, int i) {
    int n = cubes.size();

    if (i == n) { // then do the checking, get the number of repainting
        int sum = 0;

        for (int t = 0; t < N; t++) {
            map<string, int> colorTable;
            for (int k = 0; k < n; k++) 
                // for the face t, count most number of color
                colorTable[cubes[k][t]] ++;
            
            int MaxCount = 0;
            map<string, int>::iterator p = colorTable.begin();
            while (p != colorTable.end()) {
                if (p->second > MaxCount)
                    MaxCount = p->second;
                p ++;
            }

            sum += n - MaxCount;
        }
        
        MinSum = min(MinSum, sum);

        return;
    }

    // do the permutation
    for (int t = 0; t < NP; t++) {
        vector< vector<string> > cubes_cpy(cubes);

        for (int j = 0; j < N; j++)
            cubes_cpy[i][pose[t][j]] = cubes[i][j];

        dfs(cubes_cpy, i+1);
    }

}

int main() {
    freopen("1352.ColoredCubes.dat", "r", stdin);

    int n; cin>>n;
    
    while (n != 0) {
        vector< vector<string> > cubes(n, vector<string>(N));

        for (int i = 0; i < n; i++)
            for (int j = 0; j < N; j++)
                cin >> cubes[i][j];

        MinSum = N * N + 100;

        dfs(cubes, 0);

        cout << MinSum << endl;

        cin >> n;
    }

    return 0;
}
