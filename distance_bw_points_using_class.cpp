#include <iostream>
#include <math.h>

using namespace std;

float square(float n)
{
    float square = n * n;
    return square;
}

class Point
{
    int x, y;

public:
    void set_point(int a, int b)
    {
        x = a;
        y = b;
    }
    void display_point()
    {
        cout << "(" << x << ", " << y << ")" << endl;
    }

    Point(int a, int b)
    {
        x = a;
        y = b;
    }
    
    int get_x(){
        int a = x;
        return a;
    }
    int get_y(){
        int a = y;
        return a;
    }

    ~Point()
    {
        cout << "Points have been destroyed" << endl;
    }
};

float Distance(Point a, Point b)
{
    float distance = 0;
    distance = sqrt(square(a.get_x() - b.get_x()) + square(a.get_y() - b.get_y()));
    return distance;
}

int main()
{
    Point n(4, 3);
    Point m(7, 7);
    float distance;
    distance = Distance(n, m);
    cout<<distance<<endl;
    return 0;
    //why is it giving 2 destructor statements first i don't undetstand 
}