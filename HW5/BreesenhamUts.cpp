#include <iostream>

struct Vertex
{
    int x, y;
    Vertex(int x_, int y_) : x(x_), y(y_) {}
};
void drawPoint(const Vertex &v)
{
    std::cout << "Drawing point (" << v.x << ", " << v.y << ")\n";
}

// Bresenham's line algorithm
void drawLine(const Vertex &start, const Vertex &end)
{
    int dx = end.x - start.x;
    int dy = end.y - start.y;
    int d;
    int dL;
    int dU;

    if (dy > 0)
    {
        if (dy > dx)
        {
            // +steep
            d = dy - 2 * dx;
            dL = -2 * dx;
            dU = 2 * dy - 2 * dx;

            for (int x = start.x, y = start.y; y <= end.y; y++)
            {
                Vertex v(x, y);
                drawPoint(v);
                if (d >= 1)
                {
                    d += dL;
                }
                else
                {
                    x++;
                    d += dU;
                }
            }
        }
        else
        {
            // +shallow
            d = 2 * dy - dx;
            dL = 2 * dy;
            dU = 2 * dy - 2 * dx;

            for (int x = start.x, y = start.y; x <= end.x; x++)
            {
                Vertex v(x, y);
                drawPoint(v);
                if (d <= 0)
                {
                    d += dL;
                }
                else
                {
                    y++;
                    d += dU;
                }
            }
        }
    }
    else
    {
        if (-dy > dx)
        {
            // -steep
            d = dy - 2 * dx;
            dL = 2 * dx;
            dU = 2 * dy - 2 * dx;

            for (int x = start.x, y = start.y; y >= end.y; --y)
            {
                Vertex v(x, y);
                drawPoint(v);
                if (d >= 1)
                {
                    d -= dL;
                }
                else
                {
                    x++;
                    d -= dU;
                }
            }
        }
        else
        {
            d = 2 * dy - dx;
            dL = 2 * dy;
            dU = 2 * dy - 2 * dx;

            for (int x = start.x, y = start.y; x <= end.x; x++)
            {
                Vertex v(x, y);
                drawPoint(v);
                if (d >= 0)
                {
                    d += dL;
                }
                else
                {
                    --y;
                    d -= dU;
                }
            }
        }
    }
}

int main()
{
    Vertex start(3, 8);
    Vertex end(9, 3);
    drawLine(start, end);
    return 0;
}