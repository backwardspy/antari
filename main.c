#include "antari.h"
#include "vec.h"

#define W 128
#define H 128

const uint8_t spr[8] = {
    0b01111110,
    0b10000001,
    0b10100101,
    0b10000001,
    0b10100101,
    0b10011001,
    0b10000001,
    0b01111110,
};

void update() {}

void draw()
{
    cls(30, 30, 30);

    hline(6, 0, W - 1, 90, 90, 90);
    hline(H - 6, 0, W - 1, 60, 60, 60);
    vline(6, 0, H - 1, 90, 90, 90);
    vline(W - 6, 0, H - 1, 60, 60, 60);

    hline(79, 80, 100, 120, 0, 0);
    line(80, 80, 100, 80, 0, 120, 0);

    double t = ticks() / 300.0;
    line(80 - sin(t) * 16, 82 - cos(t) * 16, 80 + cos(t) * 8, 82 + sin(t) * 8, 120, 120, 120);

    vline(80, 84, 90, 120, 0, 0);
    line(81, 84, 81, 90, 0, 120, 0);

    for (int y = 0; y < H; ++y)
    {
        for (int x = 0; x < W; ++x)
        {
            if ((x & y) == 0)
            {
                dot(x, y, 64 + x, 64 + y, 128);
            }
        }
    }

    sprite(90, 60, 64, 128, 192, spr);

    text(48, 102, 255, 128, 0, "%dx%d", W, H);
    text(48, 110, 0, 255, 128, "sierpinski");
    text(48, 118, 128, 0, 255, "gasket");
}

int main()
{
    init(W, H, 4, 30);
    run(&update, &draw);
    return 0;
}
