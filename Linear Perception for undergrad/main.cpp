//Bryan Barrientos

#include <iostream>
#include <math.h>
#include <iomanip>
#include <fstream>

using namespace std;

int main()
{
    //Declaring variables
    int N = 80;
    int d = 2;
    double nn;
    double target;
    int axis;
    float train_x [N] [d];
    double train_y[N];
    int numcorr = 0;
    srand(time(NULL));
    ifstream file;
    
    //Initialize nn
    nn = 10;
    
    // list comprehension also train_y
    for(int i = 0; i < N; i++)
    {
        target = i / nn;
        train_y[i] = target;
    }
    
    //Declaring/Initializing axis
    axis = 1;
    
    //Declaring/Initializing train_x
    
    // Cluster 1
    for(int h = 0; h < 20; h++)
        {
            for ( int e = 0; e < 2; e++)
            {
            train_x [h] [e] = ((double)rand()) / ((double)RAND_MAX) * 0.35 + 0;
            }
        }
    
    //Cluster 2
    for (int h = 20; h < 40; h++)
    {
        for( int e = 0; e < 2; e++)
        {
            if (e == 1)
            {
                train_x [h] [e] = ((double) rand()) / ((double) RAND_MAX) * 1.0 + 0.70;
                //cout << train_x [h] [e] << endl;
            }
            train_x [h] [e] = ((double) rand()) / ((double) RAND_MAX) * 0.35 + 0;
        }
    }
    
    for (int k = 0; k < 40; k++)
    {
        for (int m = 0; m < 2; m++)
        {
            cout << train_x[k] [m] << " ";
        }
        cout << endl;
    }
    
    int r[80] = { 0, 0 , 1, 0 , 0, 0 , 1, 0 , 0, 0 , 1, 0 , 0, 0 ,1, 0 , 0, 0 , 1, 0 ,
        0, 0 , 1, 0 , 0, 0 , 1, 0 , 0, 0 , 1, 0 , 0, 0 , 1, 0 , 0, 0 , 1, 0 ,
        0, 0 , 1, 0 , 0, 0 , 1, 0 , 0, 0 , 1, 0 , 0, 0 , 1, 0 , 0, 0 , 1, 0 ,
        0, 0 , 1, 0 , 0, 0 , 1, 0 ,0, 0 , 1, 0 , 0, 0 , 1, 0 , 0, 0 , 1, 0};
    
    /*float train_x [80] [2] = {
        {-0.23 ,-0.16} ,{-0.10 ,0.85} ,{0.92 ,0.94} ,{0.89 ,0.26},
        {0.34 ,0.01} ,{0.32 ,0.83} ,{0.98 ,0.91} ,{0.74 ,-0.15},
        {0.08 ,-0.23} ,{-0.20 ,0.88} ,{0.81 ,0.98} ,{0.85 ,-0.18},
        {-0.13 ,-0.34} ,{-0.34 ,0.91} ,{0.77 ,1.00} ,{0.96 ,0.12},
        {-0.14 ,0.26} ,{0.15 ,0.84} ,{0.91 ,0.76} ,{0.86 ,0.11},
        {-0.22 ,0.04} ,{-0.01 ,0.90} ,{0.78 ,0.71} ,{0.94 ,0.03},
        {0.10 ,0.23} ,{0.24 ,0.99} ,{0.98 ,0.73} ,{0.85 ,0.22},
        {0.12 ,0.26} ,{0.05 ,0.83} ,{0.79 ,0.73} ,{0.90 ,-0.26},
        {0.06 ,-0.32} ,{-0.32 ,0.75} ,{0.99 ,0.91} ,{0.88 ,0.17},
        {-0.19 ,-0.34} ,{-0.01 ,0.81} ,{0.98 ,0.75} ,{0.97 ,0.25},
        {0.35 ,-0.16} ,{-0.27 ,0.83} ,{0.91 ,0.97} ,{0.82 ,-0.35},
        {0.06 ,0.13} ,{0.15 ,0.78} ,{0.81 ,0.72} ,{0.89 ,-0.04},
        {0.28 ,-0.11} ,{0.29 ,0.75} ,{0.93 ,0.90} ,{0.82 ,-0.30},
        {0.33 ,0.18} ,{0.04 ,0.94} ,{0.77 ,0.93} ,{0.90 ,0.10},
        {0.32 ,0.24} ,{0.35 ,0.83} ,{0.80 ,0.80} ,{0.75 ,-0.28},
        {-0.14 ,-0.15} ,{0.30 ,0.88} ,{0.81 ,0.84} ,{0.96 ,0.00},
        {-0.20 , 0.31} ,{-0.16 ,0.83} ,{0.86 ,0.77} ,{0.87 ,-0.30},
        {0.32 ,0.20} ,{-0.14 ,0.73} ,{0.82 ,0.83} ,{0.73 ,-0.15},
        {0.23 ,0.11} ,{0.15 ,0.86} ,{0.81 ,0.85} ,{0.71 ,-0.16},
        {-0.33 ,0.12} ,{-0.24 ,0.75} ,{0.71 ,0.79} ,{0.97 ,-0.34}
    }; */
    
    //Declaring/Initializing eta
    double eta = 0.5;
    
    //w random array
    float w[d];
    float dw[d];
    for (int i = 0; i < 3; i++)
    {
        float rng = (rand() % 10) * 0.1;
        w[i] = rng/100;
    }
    
    float epoch = 0;
    while(epoch < 100)
    {
        for (int i = 0; i < 3; i++)
        {
            dw[i] = 0;
        }
        numcorr=0;
        for (int t = 0; t < N; t++)
        {
            for (int j = 0; j < 3; j++)
            {
                float y=0;
                y = y + train_x[t][j] * w[j];
                //Sigmoid function
                float sigmoid = 1 / (1 + exp(-y));
                
                if ((y > 0.5 && r[t] == 1) || (y <= 0.5 && r[t] == 0))
                {
                    numcorr = numcorr + 1;
                }
                float delta = r[N] - y;
                dw[j] = dw[j] + train_x[t][j] * delta;
            }
        }
        for (int j = 0; j < 3; j++)
        {
            w[j] = w[j] + eta * dw[j] / N;
        }
        epoch++;
    }
    cout << numcorr << endl;
    
    
    return 0;
}
