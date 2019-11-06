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
    int r[N];
    float train_x [N] [d];
    int numcorr = 0;
    srand(time(NULL));
    ifstream file;
    
    //Initialize nn
    nn = 10;
    
    //Declaring/Initializing axis
    //axis = 1;
    
    //Declaring/Initializing train_x
    // Cluster 1
    for(int h = 0; h < 20; h++)
        {
            for ( int e = 0; e < 2; e++)
            {
            train_x [h] [e] = ((float)rand()) / ((float)RAND_MAX) * 0.20 + -0.10;
            }
            r[h] = 0;
        }
    
    cout << "cluster 1" << endl;
    for (int k = 0; k < 20; k++)
    {
        for (int m = 0; m < 2; m++)
        {
            cout << train_x[k] [m] << " ";
        }
        cout << endl;
    }
    cout << endl;
    
    //Cluster 2
    for (int h = 20; h < 40; h++)
    {
        for( int e = 0; e < 2; e++)
        {
            if (e == 1)
            {
                train_x [h] [e] = ((float) rand()) / ((float) RAND_MAX) * 0.20 + 0.80;
            }
            else
            train_x [h] [e] = ((float) rand()) / ((float) RAND_MAX) * 0.40 + -0.10;
        }
        r[h] = 0;
    }
    
    cout << "cluster 2" << endl;
    for (int k = 20; k < 40; k++)
    {
        for (int m = 0; m < 2; m++)
        {
            cout << train_x[k] [m] << " ";
        }
        cout << endl;
    }
    cout << endl;
    
    //Cluster 3
      for (int h = 40; h < 60; h++)
      {
          for( int e = 0; e < 2; e++)
          {
                  train_x [h] [e] = ((float) rand()) / ((float) RAND_MAX) * 0.10 + 0.80;
          }
          r[h] = 1;
      }
      
      cout << "cluster 3" << endl;
      for (int k = 40; k < 60; k++)
      {
          for (int m = 0; m < 2; m++)
          {
              cout << train_x[k] [m] << " ";
          }
          cout << endl;
      }
    cout << endl;
    
    //Cluster 4
      for (int h = 60; h < 80; h++)
      {
          for( int e = 0; e < 2; e++)
          {
              if (e == 1)
              {
                  train_x [h] [e] = ((float) rand()) / ((float) RAND_MAX) * 0.20+ -0.10;
              }
              else
              train_x [h] [e] = ((float) rand()) / ((float) RAND_MAX) * 0.40 + 0.60;
          }
          r[h] = 0;
      }
      
      cout << "cluster 4" << endl;
      for (int k = 60; k < 80; k++)
      {
          for (int m = 0; m < 2; m++)
          {
              cout << train_x[k] [m] << " ";
          }
          cout << endl;
      }
    cout << endl;
    
    //Declaring/Initializing eta
    float eta = 0.5;
    
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
        float y = 0.0;
        for (int i = 0; i < 3; i++)
        {
            dw[i] = 0;
        }
        numcorr=0;
        for (int t = 0; t < N; t++)
        {
            for (int j = 0; j < 3; j++)
            {
                y = 0;
                y = y + train_x[t][j] * w[j];
                //Sigmoid function
                float sigmoid = 1 / (1 + exp(-y));
            }
                
                if ((y > 0.5 && r[t] == 1) || (y <= 0.5 && r[t] == 0))
                {
                    numcorr = numcorr + 1;
                }
                float delta = r[t] - y;
            
            for (int j = 0; j < 3; j++)
            {
                dw[j] = dw[j] + train_x[t][j] * delta;
            }
        }
        for (int j = 0; j < 3; j++)
        {
            w[j] = w[j] + eta * dw[j] / N;
        }
        epoch++;
    }
    cout << "Number Correct: " << numcorr << endl;
    
    
    return 0;
}
