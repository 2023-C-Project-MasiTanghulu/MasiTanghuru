#include <SFML/Graphics.hpp>


using namespace sf;

void bad() {
    RenderWindow window(sf::VideoMode(1500, 800), "���ķ� �����");

    Texture Bad_frame;  // ���� ȭ��
    if (!Bad_frame.loadFromFile("image/Bad_frame.png")) {
    
    }
    Sprite frameSprite(Bad_frame);  // ���� ȭ�� �̹��� �Ҵ�

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