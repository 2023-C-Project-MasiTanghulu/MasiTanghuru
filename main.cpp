#include "main.h"
using namespace sf;

int main() {
    Start start;
    RenderWindow window(VideoMode(1500, 800), "����");
    start.run(window);

    return 0;
}
