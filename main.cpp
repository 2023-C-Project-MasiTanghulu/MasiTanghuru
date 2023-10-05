#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(1500, 800), "����");

    sf::Texture texture;
    if (!texture.loadFromFile("image/Main_frame.png")) {
        return -1; // �̹����� �ҷ��� �� ������ ����
    }

    sf::Sprite sprite(texture);

    sf::Texture buttonTexture1;
    if (!buttonTexture1.loadFromFile("image/Start_btn.png")) {
        return -1; // �̹����� �ҷ��� �� ������ ����
    }

    sf::Sprite button1(buttonTexture1);
    button1.setPosition(900, 500);

    sf::Texture buttonTexture2;
    if (!buttonTexture2.loadFromFile("image/Rule_btn.png")) {
        return -1; // �̹����� �ҷ��� �� ������ ����
    }

    sf::Sprite button2(buttonTexture2);
    button2.setPosition(900, 650);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);

                    if (button1.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                        printf("���ӽ��� ��ư");// ��ư 1�� ������ �� ������ �ڵ� �߰�
                    }

                    if (button2.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                        printf("���ӷ� ��ư");
                        // ��ư 2�� ������ �� ������ �ڵ� �߰�
                    }
                }
            }
        }

        window.clear();
        window.draw(sprite);
        window.draw(button1);
        window.draw(button2);
        window.display();
    }

    return 0;
}
