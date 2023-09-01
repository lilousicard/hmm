//
// Created by Lilou Sicard-Noel on 9/1/23.
//
#include <stdio.h>

#define N 2
#define M 3
#define T 4

//******************************Static Variables***************************************//
static int allObservation[][4] = {{0, 0, 0, 0},
                                  {0, 0, 0, 1},
                                  {0, 0, 0, 2},
                                  {0, 0, 1, 0},
                                  {0, 0, 1, 1},
                                  {0, 0, 1, 2},
                                  {0, 0, 2, 0},
                                  {0, 0, 2, 1},
                                  {0, 0, 2, 2},
                                  {0, 1, 0, 0},
                                  {0, 1, 0, 1},
                                  {0, 1, 0, 2},
                                  {0, 1, 1, 0},
                                  {0, 1, 1, 1},
                                  {0, 1, 1, 2},
                                  {0, 1, 2, 0},
                                  {0, 1, 2, 1},
                                  {0, 1, 2, 2},
                                  {0, 2, 0, 0},
                                  {0, 2, 0, 1},
                                  {0, 2, 0, 2},
                                  {0, 2, 1, 0},
                                  {0, 2, 1, 1},
                                  {0, 2, 1, 2},
                                  {0, 2, 2, 0},
                                  {0, 2, 2, 1},
                                  {0, 2, 2, 2},
                                  {1, 0, 0, 0},
                                  {1, 0, 0, 1},
                                  {1, 0, 0, 2},
                                  {1, 0, 1, 0},
                                  {1, 0, 1, 1},
                                  {1, 0, 1, 2},
                                  {1, 0, 2, 0},
                                  {1, 0, 2, 1},
                                  {1, 0, 2, 2},
                                  {1, 1, 0, 0},
                                  {1, 1, 0, 1},
                                  {1, 1, 0, 2},
                                  {1, 1, 1, 0},
                                  {1, 1, 1, 1},
                                  {1, 1, 1, 2},
                                  {1, 1, 2, 0},
                                  {1, 1, 2, 1},
                                  {1, 1, 2, 2},
                                  {1, 2, 0, 0},
                                  {1, 2, 0, 1},
                                  {1, 2, 0, 2},
                                  {1, 2, 1, 0},
                                  {1, 2, 1, 1},
                                  {1, 2, 1, 2},
                                  {1, 2, 2, 0},
                                  {1, 2, 2, 1},
                                  {1, 2, 2, 2},
                                  {2, 0, 0, 0},
                                  {2, 0, 0, 1},
                                  {2, 0, 0, 2},
                                  {2, 0, 1, 0},
                                  {2, 0, 1, 1},
                                  {2, 0, 1, 2},
                                  {2, 0, 2, 0},
                                  {2, 0, 2, 1},
                                  {2, 0, 2, 2},
                                  {2, 1, 0, 0},
                                  {2, 1, 0, 1},
                                  {2, 1, 0, 2},
                                  {2, 1, 1, 0},
                                  {2, 1, 1, 1},
                                  {2, 1, 1, 2},
                                  {2, 1, 2, 0},
                                  {2, 1, 2, 1},
                                  {2, 1, 2, 2},
                                  {2, 2, 0, 0},
                                  {2, 2, 0, 1},
                                  {2, 2, 0, 2},
                                  {2, 2, 1, 0},
                                  {2, 2, 1, 1},
                                  {2, 2, 1, 2},
                                  {2, 2, 2, 0},
                                  {2, 2, 2, 1},
                                  {2, 2, 2, 2}};
int weatherSequence[16][4] = {{0, 0, 0, 0},
                              {0, 0, 0, 1},
                              {0, 0, 1, 0},
                              {0, 0, 1, 1},
                              {0, 1, 0, 0},
                              {0, 1, 0, 1},
                              {0, 1, 1, 0},
                              {0, 1, 1, 1},
                              {1, 0, 0, 0},
                              {1, 0, 0, 1},
                              {1, 0, 1, 0},
                              {1, 0, 1, 1},
                              {1, 1, 0, 0},
                              {1, 1, 0, 1},
                              {1, 1, 1, 0},
                              {1, 1, 1, 1}};

//******************************************************************************//
//******************************Functions***************************************//
void findAllProbabilities(double pi[2], double A[2][2], double B[2][3]) {
    double totalSum = 0.0;
    //printf("Printing all possible probabilities:\n");
    for (int i = 0; i < 81; i++) {
        double sum = 0.0;
        //printf("observation[i]: %d %d %d %d\n", allObservation[i][0], allObservation[i][1], allObservation[i][2],
        //       allObservation[i][3]);
        for (int j = 0; j < 16; j++) {
            int *current = weatherSequence[j];
            double prob = pi[current[0]] * B[current[0]][allObservation[i][0]] * A[current[0]][current[1]] *
                          B[current[1]][allObservation[i][1]] * A[current[1]][current[2]] *
                          B[current[2]][allObservation[i][2]] *
                          A[current[2]][current[3]] * B[current[3]][allObservation[i][3]];
            //printf("sequence[j]: %d %d %d %d prob = %f\n", current[0], current[1], current[2], current[3], prob);
            sum += prob;
        }
        totalSum += sum;
        //printf("totalSum: %f\n", totalSum);
    }
    printf("Total probability in findAllProbability: %f\n", totalSum);
}

void forwardForAll(double pi[2], double A[2][2], double B[2][3], double alpha[4][2]) {
    double totalProbability = 0.0;
    for (int i = 0; i < 81; i++) {
        int *currentObservation = allObservation[i];
        //Initialization of alpha's first row
        for (int i = 0; i < N; i++) {
            alpha[0][i] = pi[i] * B[i][currentObservation[0]];
        }
        //Compute alpha's other rows
        for (int t = 0; t < T - 1; t++) {
            for (int j = 0; j < N; j++) {
                double sum = 0;
                for (int i = 0; i < N; i++) {
                    sum += alpha[t][i] * A[i][j];
                }
                alpha[t + 1][j] = sum * B[j][currentObservation[t + 1]];
            }
        }
        //printf("Total probability for this sequence: %f\n", alpha[3][0] + alpha[3][1]);
        totalProbability += alpha[3][0] + alpha[3][1];
    }
    printf("Total probability in forwardForAll: %f\n", totalProbability);
}

/*
int main() {
    double pi[N] = {0.6, 0.4};
    double A[N][N] = {{0.7, 0.3},
                      {0.4, 0.6}};
    double B[N][M] = {{0.1, 0.4, 0.5},
                      {0.7, 0.2, 0.1}};
    double alpha[T][N] = {{0, 0},
                          {0, 0},
                          {0, 0},
                          {0, 0}};

    findAllProbabilities(pi, A, B);
    forwardForAll(pi, A, B, alpha);

    return 0;
}*/