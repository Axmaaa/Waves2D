struct Vector2D
{
    Vector2D()
    {
        x = 0;
        y = 0;
    }
    double x, y;
};

struct Point
{
    struct Vector2D coord, speed;
};
