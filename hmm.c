#include <stdio.h>
#include "hmm.h"



int main() {
    double pi[] = {0, 1};
    double A[N][N] = {{0.7, 0.3}, {0.4, 0.6}};
    double B[N][M] = {{0.1, 0.4, 0.5}, {0.7, 0.2, 0.1}};
    double alpha[M][N] = {{0, 0}, {0, 0}};
    int T = (sizeof (observation) / sizeof (observation[0]));
    forward(pi, A, B, alpha, T);
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++)
            printf("%f ", alpha[i][j]);
        printf("\n");
    }
    printf("Total probability: %f\n", alpha[2][0] + alpha[2][1]);
    double totalProb = calculateTotalProb(pi, A, B);
    printf("Total probability: %f\n", totalProb);

    return 0;
}

double calculateTotalProb(double pi[2], double A[2][2], double B[2][3]) {
    double sum = 0.0;
    printf("Printing all possible probabilities:\n");
    int sequence[8][3] = {{0,0,0},
                          {0,0,1},
                          {0,1,0},
                          {0,1,1},
                          {1,0,0},
                          {1,0,1},
                          {1,1,0},
                          {1,1,1}};
    for (int i = 0; i < 8; i++) {
        int *current = sequence[i];
        double prob = pi[current[0]] * B[current[0]][observation[0]] * A[current[0]][current[1]] * B[current[1]][observation[1]] * A[current[1]][current[2]] * B[current[2]][observation[2]];
        sum += prob;
        printf("%f\n", prob);
    }
    return sum;
}




void forward(double pi[N], double A[N][N], double B[N][M], double alpha[M][N], int T) {
    for (int i = 0; i < N; i++) {
        alpha[0][i] = pi[i] * B[i][observation[0]];
    }
    for (int t = 0; t < T - 1; t++) {
        for (int j = 0; j < N; j++) {
            double sum = 0;
            for (int i = 0; i < N; i++) {
                sum += alpha[t][i] * A[i][j];
            }
            alpha[t + 1][j] = sum * B[j][observation[t + 1]];
        }
    }
}