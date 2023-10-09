#include <SFML/Graphics.hpp>


using namespace sf;

void levelup() {
    RenderWindow window(sf::VideoMode(1500, 800), "탕후루 만들기");

    Texture Levelup_frame;  // 게임 화면
    if (!Levelup_frame.loadFromFile("image/Levelup_frame.png")) {
       
    }
    Sprite frameSprite(Levelup_frame);  // 게임 화면 이미지 할당

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        // ↓ 갈수록 레이어가 위임
        window.draw(frameSprite);  // 게임화면 draw
        window.display();
    }

}