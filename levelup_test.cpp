#include <SFML/Graphics.hpp>
#include "levleup.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(1500, 800), "������ ȭ�� �׽�Ʈ");
    Levelup levelup;
    levelup.run(window);
    return 0;
}
