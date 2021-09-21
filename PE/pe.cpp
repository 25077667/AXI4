#include "pe.h"

void Convolution::f()
{
    int sum = 0;
    for(int i = 0 ; i < 5 ; i++)
        for(int j = 0 ; j < 5 ; j++)
            sum += data[i][j]*kernel[i][j];
    output = sum;
}

/*void Convolution::f()
{
    int sum = 0;
    for(int i = 0 ; i < 5 ; i++)
        for(int j = 0 ; j < 5 ; j++)
            sum += input_data.read()[0][i][j] * input_data.read()[1][i][j];
    output_data.write(sum);
}*/

void Pooling::f()
{
    int max = 0;

    for(int i = 0 ; i < 4 ; i++)
            max = (max > data[i] ? max : data[i]);
    output = max;
}

void Layer12::f()
{
    for(int i = 0 ; i < 4 ; i++)
    {
        for(int j = 0 ; j < 5 ; j++)
        {
            for(int k = 0 ; k < 5 ; k++)
            {
                conv[i].data[j][k] = input_data.read()[i][j][k];
                conv[i].kernel[j][k] = input_kernel.read()[j][k];
                conv[i].f();
            }
        }
    }
    for(int i = 0 ; i < 4 ; i++)
        pool.data[i] = conv[i].output;
    pool.f();
    output_data.write(pool.output);
}

/*void Pooling::input()
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
}*/