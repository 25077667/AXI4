#include "pe.h"

void Convolution::f()
{
    int sum = 0;
    for(int i = 0 ; i < 5 ; i++)
        for(int j = 0 ; j < 5 ; j++)
            sum += input_data.read()[0][i][j] * input_data.read()[1][i][j];
    output_data.write(sum);
}

void Pooling::input()
{
    data[counter++] = input_data.read();
    if(counter == 4)
    {
        this->f();
        counter = 0;
    }
}

void Pooling::f()
{
    int max = 0;

    for(int i = 0 ; i < 4 ; i++)
            max = (max > data[i] ? max : data[i]);
    output_data.write(max);
}