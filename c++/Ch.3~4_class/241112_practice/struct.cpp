#include <iostream>

struct Point
{
    int xpos;
    int ypos;

    void MovePos(int s, int y)
    {
        xpos = xpos + s;
        ypos = ypos + y;
    }

    void AddPoint(const Point &pos)
    {
        xpos += pos.xpos;
        ypos += pos.ypos;
    }

    void ShowPosition()
    {
        std::cout << "xpos= " << xpos << " ypos= " << ypos << std::endl;
    }
};

int main()
{
    Point pos1 = {12, 4};
    Point pos2 = {20, 30};

    pos1.MovePos(-7, 10);
    pos1.ShowPosition();

    pos1.AddPoint(pos2);
    pos1.ShowPosition();
    return 0;
}// 114p ¹®Á¦