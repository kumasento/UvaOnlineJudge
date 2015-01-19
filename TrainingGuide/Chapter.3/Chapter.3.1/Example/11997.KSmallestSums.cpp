
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Item {
    int s, b;
    Item(int s, int b): s(s), b(b) {}
    friend bool operator < (Item a, Item b) {
        return a.s > b.s;
    }
};

int main() {
    freopen("11997.KSmallestSums.dat", "r", stdin);
    
    int n; 
    while (scanf("%d", &n) == 1) {

        vector<int> A(n), B(n);
        for (int i = 0; i < n; i++)
            scanf("%d", &A[i]);
        sort(A.begin(), A.end());

        for (int i = 1; i < n; i++) {
            // A will be updated as the result
            // B will be updated as the source
            for (int j = 0; j < n; j++) 
                scanf("%d", &B[j]);
            sort(B.begin(), B.end());

            priority_queue<Item> q;
            for (int k = 0; k < n; k++)
                q.push(Item(A[k]+B[0], 0));

            for (int k = 0; k < n; k++) {
                // only update the first n elements
                Item item = q.top(); q.pop();
                A[k] = item.s; 
                int b = item.b;
                
                // and then, maybe (s, b+1) will be the next one
                if (b+1 < n) 
                    q.push(Item(item.s-B[b]+B[b+1], b+1));
            }
        }

        for (int i = 0; i < n-1; i++)
            printf("%d ", A[i]);
        printf("%d\n", A[n-1]);
    }

    return 0;
}
