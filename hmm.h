//
// Created by Lilou Sicard-Noel on 8/29/23.
//

#ifndef HMM_HMM_H
#define HMM_HMM_H
#define N 2
#define M 3
#define T 3

static int observation[] = {1,0,2};


void forward(double pDouble[2], double pDouble1[2][2], double pDouble2[2][3], double pDouble3[3][2]);

double calculateTotalProb(double pDouble[2], double pDouble1[2][2], double pDouble2[2][3]);


#endif //HMM_HMM_H
