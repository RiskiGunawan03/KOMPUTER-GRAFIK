#include <iostream>
#include <cmath>

void drawLineDDA(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    float xIncrement = static_cast<float>(dx) / steps;
    float yIncrement = static_cast<float>(dy) / steps;

    float x = x1;
    float y = y1;

    for (int i = 0; i <= steps; i++) {
        std::cout << "Titik (" << round(x) << ", " << round(y) << ")\n";
        x += xIncrement;
        y += yIncrement;
    }
}

int main() {
    int x1 = 1, y1 = 3;
    int x2 = 4, y2 = 9;

    std::cout << "Titik awal: (" << x1 << ", " << y1 << ")\n";
    std::cout << "Titik akhir: (" << x2 << ", " << y2 << ")\n";

    drawLineDDA(x1, y1, x2, y2);

    return 0;
}
