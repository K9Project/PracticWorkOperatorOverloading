// PracticWorkOperatorOverloading.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>

class Vector
{
public:

    Vector()
    {
        x = 0;
        y = 0;
        z = 0;
    }

    Vector(float x, float y, float z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    operator float()
    {
        return sqrt(x * x + y * y + z * z);
    }

    friend Vector operator+(const Vector& a, const Vector& b);

    friend std::ostream& operator<<(std::ostream& out, const Vector& v);

    friend bool operator>(const Vector& a, const Vector& b);

    float operator[](int index)
    {
        switch (index)
        {
        case 0:
            return x;
            break;
        case 1:
            return y;
            break;
        case 2:
            return z;
            break;
        default:
            std::cout << "Error";
            return 0;
            break;
        }
    }

private:
    float x;
    float y;
    float z;
};

bool operator>(const Vector& a, const Vector& b)
{
    return false;
}

Vector operator+(const Vector& a, const Vector& b)
{
    return Vector(a.x + b.x, a.y + b.y, a.z + b.z);
}

std::ostream& operator<<(std::ostream& out, const Vector& v)
{
    out << ' ' << v.x << ' ' << v.y << ' ' << v.z;
    return out;
}

int main()
{
    Vector v1(0, 1, 2);
    Vector v2(3, 4, 5);
    Vector v3;
    Vector v4;
    v3 = v1 + v2;
    std::cout << v3 << '\n';
    std::cout << "v3 length: "  << static_cast<float>(v3) << '\n';
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
