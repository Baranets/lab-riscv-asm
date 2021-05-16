#include <stdio.h>

#define N 5
#define M 4

int process(int n, int m, int array[N][M]) {
    int result = __INT_MAX__;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (array[i][j] < result) {
                result = array[i][j];
            }
        }
    }

    return result;
}

int main(int argc, char** argv) {
    int array[N][M] = {
        {  3,  2,  4, 11 },
        {  5,  1,  6, 10 },
        {  7,  9,  8, 12 }, 
        { 20, 19, 18, 17 },
        { 13, 15, 17, 16 }
    };

    int result = process(N, M, array);
    printf("%d\n", result);

    return 0;
}