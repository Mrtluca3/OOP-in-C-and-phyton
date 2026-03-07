#include <iostream>
#include <chrono>
#include <random>

using namespace std;
double mean(const double *array, const int length)
{
    double summ=0;
    for(int i=0; i<length; i++)
    {
        summ+= array[i];
    }
    return summ/length;
}
double var1(const double *array, const int length)
{
    double array2[length];
    double m=mean(array, length);
    for(int i=0; i<length; i++)
    {
        array2[i] = array[i]*array[i];
    }
    return mean(array2, length)- m*m;
}
double var2(const double *array, const int length)
{
    double summ=0;
    double m=mean(array, length);
    for(int i=0; i<length; i++)
    {
        summ += (array[i]-m)*(array[i]-m);
    }
    return summ/length;
}


int main(){
    srand(145);
    const int nmeans=100;
    for (int length=10; length<=100000; length+=1000)
    {
    double array[length];


    for (int i=0; i<length; i++)
    {
        array[i] = rand()/(double)RAND_MAX;
    }
    double m1=0, m2=0;
    for (int j=0; j<nmeans; j++)
    {


    auto start = chrono::steady_clock::now();
    double v1=var1(array, length);
    // cout  << v1 << endl;
    auto end = chrono::steady_clock::now();
    
    chrono::duration<double, milli> duration = end - start;
    // cout << "Execution time std1: " << duration.count() << " ms" << endl;
    m1+=duration.count();

    start = chrono::steady_clock::now();
    double v2=var2(array, length);
    // cout << "Variance 2: " << v2 << endl;

    end = chrono::steady_clock::now();
    
    duration = end - start;
    // cout << "Execution time std2: " << duration.count() << " ms" << endl;
    m2+=duration.count();
    }
    cout << m1/nmeans << " " << m2/nmeans << " " << length << endl;
}
    return 0;

}