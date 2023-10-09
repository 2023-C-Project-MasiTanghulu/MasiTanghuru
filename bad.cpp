#include <SFML/Graphics.hpp>


using namespace sf;

void bad() {
    RenderWindow window(sf::VideoMode(1500, 800), "탕후루 만들기");

    Texture Bad_frame;  // 게임 화면
    if (!Bad_frame.loadFromFile("image/Bad_frame.png")) {
    
    }
    Sprite frameSprite(Bad_frame);  // 게임 화면 이미지 할당

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