#include <SFML/Graphics.hpp>
#include "bad.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(1500, 800), "��忣�� �׽�Ʈ");
    Bad bad;
    bad.run(window);
    return 0;
}
