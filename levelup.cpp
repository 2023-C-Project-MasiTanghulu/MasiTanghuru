#include <SFML/Graphics.hpp>


using namespace sf;

void levelup() {
    RenderWindow window(sf::VideoMode(1500, 800), "���ķ� �����");

    Texture Levelup_frame;  // ���� ȭ��
    if (!Levelup_frame.loadFromFile("image/Levelup_frame.png")) {
       
    }
    Sprite frameSprite(Levelup_frame);  // ���� ȭ�� �̹��� �Ҵ�

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        // �� ������ ���̾ ����
        window.draw(frameSprite);  // ����ȭ�� draw
        window.display();
    }

}