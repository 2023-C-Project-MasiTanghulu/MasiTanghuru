#include <SFML/Graphics.hpp>
#include "happy.h"

int main() {
    RenderWindow window(VideoMode(1500, 800), "해피엔딩 테스트");
    Happy happy;
    happy.run(window);
    return 0;
}
