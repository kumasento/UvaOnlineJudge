#include <iostream>
#include <vector>

using namespace std;

int rotLeft[] = { 4, 0, 2, 3, 5, 1 };
int rotUp[] = { 2, 1, 5, 0, 4, 3 };

int N = 6;

void rotate(int *p, int *T) {
    int q[N];
    for (int i = 0; i < N; i++) 
        q[i] = p[i];
    for (int i = 0; i < N; i++)
        p[i] = T[q[i]];
}

void rotateLeft(int *p, int n) {
    for (int i = 0; i < n; i++)
        rotate(p, rotLeft);
}

int main() {
    int p[] = { 0, 1, 2, 3, 4, 5 };

    int q[N];
    for (int i = 0; i < N; i++) 
        q[i] = p[i];

    for (int i = 0; i < N; i++) {
        if (i == 0) { rotate(p, rotUp); }
        else if (i == 1) { rotate(p, rotLeft); rotate(p, rotUp); }
        else if (i == 2) {}
        else if (i == 3) { rotate(p, rotUp); rotate(p, rotUp); }
        else if (i == 4) { rotateLeft(p, 3); rotate(p, rotUp); }
        else if (i == 5) { rotateLeft(p, 2); rotate(p, rotUp); }


        for (int k = 0; k < 4; k++) {
            if (k != 0)
                rotate(p, rotLeft);
            cout << '{';
            for (int j = 0; j < N; j++)
                cout << p[j] << ((j != N-1) ? ',' : '\0');
            cout << "}," << endl;
        }

        for (int i = 0; i < N; i++)
            p[i] = q[i];
    }

    return 0;
}
