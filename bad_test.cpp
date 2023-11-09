#include <SFML/Graphics.hpp>
#include "bad.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(1500, 800), L"배드엔딩 테스트");
    Bad bad;
    bad.run(window);
    return 0;
}
