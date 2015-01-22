
#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

struct Network 
{
    vector<int> arr;
    vector<int> d;
    Network(int n) 
    {
        // let network to be empty at first
        arr.resize(n);
        d.resize(n);
        for (int i = 0; i < n; i++) arr[i] = i, d[i] = 0;
    }
    int Find(int x)
    {
        if (x == arr[x]) return x;

        int root = Find(arr[x]);
        d[x] += d[arr[x]];
        return arr[x] = root;
    }
    int Query(int x) 
    {
        Find(x);
        return d[x];
    }
    void Union(int u, int v) 
    {
        arr[u] = v;
        d[u] = ((int) abs(u-v)) % 1000;
    }
};

int main() 
{
    freopen("1329.CorporativeNetwork.dat", "r", stdin);

    int T; cin >> T;
    for (int t = 0; t < T; t ++)
    {
        int N; cin >> N; 
        Network nw(N);

        string op; cin >> op;
        while(op != string("O")) 
        {
            if (op == string("E")) 
            {
                int u; cin >> u;
                cout << nw.Query(u) << endl;
            }
            else if (op == string("I"))
            {
                int u, v; cin >> u >> v;
                nw.Union(u, v);
            }
            
            cin >> op;
        }
    }

    return 0;
}
