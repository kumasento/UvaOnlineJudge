
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

#define MAXN 100100

using namespace std;

struct MergeFindSet 
{
    vector<int> arr;
    MergeFindSet(int n) 
    { 
        arr.resize(n); 
        for (int i = 0; i < n; i++) arr[i] = i;
    }

    int Find(int x) 
    { return arr[x] != x ? arr[x] = Find(arr[x]) : x; }

    bool Union(int x, int y) 
    {
        int fx = Find(x);
        int fy = Find(y);

        if (fx == fy) 
            return false;

        arr[fx] = fy; // no rank union
        return true;
    }
};

int main() 
{
    freopen("1160.X-Plosives.dat", "r", stdin);
    
    MergeFindSet mfset(MAXN);

    int x, y; // 2 input arguments
    int count = 0;
    while (scanf("%d", &x) == 1 && x != -1) 
    {
        scanf("%d", &y);
        if (!mfset.Union(x, y))
            count ++;
    }

    cout << count << endl;

    return 0;
}
