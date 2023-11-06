#include <iostream>
#include <cmath>

void rotate(double &x, double &y, double angle)
{
    double radians = angle * M_PI / 180;
    double new_x = x * cos(radians) - y * sin(radians);
    double new_y = x * sin(radians) + y * cos(radians);
    x = new_x;
    y = new_y;
}

int main()
{
    double x = 3.8;
    double y = 9.3;
    double rotation_angle = 45.0; // Sudut rotasi dalam derajat

    std::cout << "Koordinat awal: (" << x << ", " << y << ")\n";
    rotate(x, y, rotation_angle);
    std::cout << "Koordinat setelah rotasi: (" << x << ", " << y << ")\n";

    return 0;
}
