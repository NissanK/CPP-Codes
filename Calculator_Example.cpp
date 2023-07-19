#include<iostream>
#include<math.h>
#include<cmath>
using namespace std;

class SimpleCalculator{
    public:
        void add(int,int);
        void subtract(int,int);
        void multiply(int,int);
        void divide(int,int);
};

void SimpleCalculator :: add(int n1,int n2){
    int sum1 = n1 + n2;
    cout<<"The sum of the numbers "<<n1<<" and "<<n2<<" is "<<sum1<<endl;
}

void SimpleCalculator :: subtract(int n1,int n2){
    int subtract = n1 - n2;
    cout<<"The subtraction of the numbers "<<n1<<" and "<<n2<<" is "<<subtract<<endl;
}

void SimpleCalculator :: divide(int n1,int n2){
    int division = n1 / n2;
    cout<<"The division of the numbers "<<n1<<" and "<<n2<<" is "<<division<<endl;
}

void SimpleCalculator :: multiply(int n1,int n2){
    int multiply = n1 * n2;
    cout<<"The multiplication of the numbers "<<n1<<" and "<<n2<<" is "<<multiply<<endl;
}


class ScientificCalculator{
    public:
        void square(int);
        void square_root(int);
        void to_the_power(int,int);
        void cos_result(int);
        void sin_result(int);
        void tan_result(int);
};

void ScientificCalculator::square(int n){
    int square = n*n;
    cout<<"The square of the number "<<n<<" is "<<square<<endl;
}

void ScientificCalculator :: square_root(int n){
    float squareroot = sqrt(n);
    cout<<"The square root of the number "<<n<<" is "<<squareroot<<endl;
}

void ScientificCalculator::to_the_power(int n,int p){
    int power = 1;
    
    for (int i = 0; i < p; i++){
        power = power * n;
    }
    
    cout<<"The number "<<n<<" to the power of "<<p<<" equals to "<<power<<endl;
}

void ScientificCalculator::cos_result(int n){
    cout<<"The cos of the number "<<n<<" is "<<cos(n)*(180/3.14)<<endl;
}

void ScientificCalculator::tan_result(int n){
    cout<<"The tan of the number "<<n<<" is "<<tan(n)*(180/3.14)<<endl;
}

void ScientificCalculator::sin_result(int n){
    cout<<"The sin of the number "<<n<<" is "<<sin(n)*(180/3.14)<<endl;
}


class HybridCalulator : public SimpleCalculator,public ScientificCalculator{};

int main(){
    SimpleCalculator a;
    a.add(6,9);
    a.divide(9,4);
    ScientificCalculator b;
    b.cos_result(6);
    b.square(6);
    b.to_the_power(6,3);
    HybridCalulator c;
    c.multiply(7,4);
    c.square_root(10);
}