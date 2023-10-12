#include "main.h"

using namespace sf;

int main() {
    Start start;
    RenderWindow window(VideoMode(1500, 800), "메인");
    start.run(window);

    return 0;
}
