#include <iostream>
#include "math.h"

using namespace std;

void add(float x, float y)
{
    float x2 = 0;
    float y2 = 0;
    cout << "Input coordinates second vector" << endl;
    cout << "x2=";
    cin >> x2;
    cout << "y2=";
    cin >> y2;

    cout << "Result of adding two vectors: ";
    cout << "x=" << x + x2;
    cout << " y=" << y + y2;
}

void subtract (float x, float y)
{
    float x2 = 0;
    float y2 = 0;
    cout << "Input coordinates second vector" << endl;
    cout << "x2=";
    cin >> x2;
    cout << "y2=";
    cin >> y2;

    cout << "Result of subtract two vectors: ";
    cout << "x=" << x - x2;
    cout << " y=" << y - y2;
}

void scale (float x, float y)
{
    float k = 0;
    cout << "Input scale" << endl;
    cout << "k=";
    cin >> k;
    cout << "Result of subtract two vectors: ";
    cout << "x=" << x * k;
    cout << " y=" << y * k;
}

void length (float x, float y)
{
    cout << "Length of vector: ";
    cout << sqrt(x*x + y*y) << endl;
}

void normalize (float x, float y)
{
    cout << "Result of normalize vector: ";
    cout << "x=" << x/sqrt(x*x + y*y);
    cout << " y=" << y/sqrt(x*x + y*y);
}

struct vec
{
    float x1 = 0;
    float y1 = 0;
};

int main() {
    vec primary_vec;
    cout << "Input coordinates primary vector:" << endl;
    cout << "x=";
    cin >> primary_vec.x1;
    cout << "y=";
    cin >> primary_vec.y1;

   int operation;
    cout << "Input operation " << endl;
    cout << "You can chose: 1 - add, 2 - subtract, 3 - scale, 4 - length, 5 - normalize" << endl;
    cin >> operation;

    switch (operation)
    {
        case 1: add(primary_vec.x1, primary_vec.y1);
            break;
        case 2: subtract(primary_vec.x1, primary_vec.y1);
            break;
        case 3: scale(primary_vec.x1, primary_vec.y1);
            break;
        case 4: length(primary_vec.x1, primary_vec.y1);
            break;
        case 5: normalize(primary_vec.x1, primary_vec.y1);
            break;
    }
}
