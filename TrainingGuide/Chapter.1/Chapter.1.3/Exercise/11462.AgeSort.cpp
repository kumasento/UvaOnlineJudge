#include <cstdio>
#include <cstring>

#define MAXN 101

using namespace std;

int main() {
    freopen("11462.AgeSort.dat", "r", stdin);

    int a[MAXN], n;
    memset(a, 0, sizeof(a));

    while(scanf("%d", &n) == 1 && n) {
    
        for (int i = 0; i < n; i++) {
            int num; 
            scanf("%d", &num);
            a[num] ++;
        }
        
        int first = 0;

        for (int i = 1; i < MAXN; i++) 
            for (int j = 0; j < a[i]; j++) {
                if (first) 
                    printf(" ");
                else 
                    first = 1;
                printf("%d", i);
            }

        printf("\n");

        memset(a, 0, sizeof(a));
    }

    return 0;
}
