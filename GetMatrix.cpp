//
//  main.c
//  java to c
//
//  Created by YUNXINGZHAO on 9/30/18.
//  Copyright © 2018 YUNXINGZHAO. All rights reserved.
//

#include <stdio.h>
#define N 5
#define H 1.0/(N-1)
double TAU = 0.1;
double RHO = 100;
double A[N*N][N*N];
double P[N][N];
double B[N*N];


void getAmatrix(double A[N*N][N*N], double B[N*N], double P[N][N])
{
//    double** A;
//    A = malloc(N * N * sizeof(double*));
//    for (int i = 0; i < N * N; i++) {
//        A[i] = malloc(N * N * sizeof(double));
//    }
//
//    double* B;
//    B = malloc(N * N * sizeof(double));
//
//    double** P;
//    P = malloc(N * sizeof(double*));
//    for (int i = 0; i < N; i++) {
//        P[i] = malloc(N * sizeof(double));
//    }
    for (int i = 1; i < N-1; i++) {
        for (int j = 1; j < N-1; j++) {
            int phiNum = i * N + j;
            //Right Point
            A[phiNum][phiNum+1] =  (RHO * (j+1) * H )/(2 * H) - (TAU / (H * H));
            //Left Point
            A[phiNum][phiNum-1] = -(RHO * (j-1) * H)/(2 * H) - (TAU / (H * H));
            //Up Point
            A[phiNum][phiNum-N] = (RHO * (i-1)*-1 * H)/(2 * H) - (TAU / (H * H));
            //Down Point
            A[phiNum][phiNum+N] = -(RHO * (i+1)*-1 * H)/(2 * H) - (TAU / (H * H));
            //Current Point
            A[phiNum][phiNum] = (4 * TAU)/(H * H);
        }
    }
    
    //Boundary Points
    //Left
    double index = 0;
    for (int i = 0; i < N * N; i=i+N) {
        for (int j = 0; j < N * N; j++) {
            if (i == j) {
                A[i][j] = 1;
                B[i] = index++ / (N - 1);
            }
            else
                A[i][j] = 0;
        }
    }
    //Up
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N*N; j++) {
            if (i == j)
                A[i][j] = 1;
            else
                A[i][j] = 0;
        }
    }
    //Right
    for (int i = 2*N-1; i < N * N - 1; i=i+N) {
        for (int j = 0; j < N * N; j++) {
            if (i == j)
                A[i][j] = 3;
            if (j == i - 1)
                A[i][j] = -4;
            if (j == i - 2)
                A[i][j] = 1;
        }
    }
    //Down
    for (int i = (N-1)*N+1; i < N * N; i++) {
        for (int j = 0; j < N * N; j++) {
            if (i == j)
                A[i][j] = 3;
            if (j == i - N)
                A[i][j] = -4;
            if (j == i - 2*N)
                A[i][j] = 1;
        }
    }
    
//    for(int i = 0; i < N * N; i ++)
//    {
//        for(int j = 0; j < N * N; j ++)
//        {
//            printf("%f ", A[i][j]);
//        }
//        printf("\n");
//    }
//    for(int i = 0; i < N * N; i ++)
//    {
//        printf("%f ", B[i]);
//    }
//    printf("\n");
}

int main()
{
    getAmatrix(A, B, P);
    printf("A matrix:");
    printf("\n");
    for(int i = 0; i < N * N; i ++)
    {
        for(int j = 0; j < N * N; j ++)
        {
            printf("%f ", A[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("B matrix:");
    printf("\n");
    for(int i = 0; i < N * N; i ++)
    {
        printf(" %f ", B[i]);
    }
    printf("\n");
}
