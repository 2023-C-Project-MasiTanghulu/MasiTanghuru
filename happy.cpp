#include <SFML/Graphics.hpp>


using namespace sf;

void happy() {
    RenderWindow window(sf::VideoMode(1500, 800), "���ķ� �����");

    Texture Happy_frame;  // ���� ȭ��
    if (!Happy_frame.loadFromFile("image/Happy_frame.png")) {
      
    }
    Sprite frameSprite(Happy_frame);  // ���� ȭ�� �̹��� �Ҵ�

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(frameSprite); 
        window.display();
    }


}