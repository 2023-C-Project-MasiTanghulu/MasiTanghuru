#include <SFML/Graphics.hpp>
#include "happy.h"

int main() {
    RenderWindow window(VideoMode(1500, 800), "���ǿ��� �׽�Ʈ");
    Happy happy;
    happy.run(window);
    return 0;
}
