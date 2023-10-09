#include <SFML/Graphics.hpp>


using namespace sf;

void happy() {
    RenderWindow window(sf::VideoMode(1500, 800), "탕후루 만들기");

    Texture Happy_frame;  // 게임 화면
    if (!Happy_frame.loadFromFile("image/Happy_frame.png")) {
      
    }
    Sprite frameSprite(Happy_frame);  // 게임 화면 이미지 할당

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