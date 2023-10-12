#include <SFML/Graphics.hpp>
#include "game_rule.h"
#include "main.h"
using namespace sf;

void Game_Rule::run(RenderWindow& window) {
    window.create(VideoMode(1500, 800), "게임방법");
    Start start;  //시작화면 객체 생성
    Texture frame;  // 게임 화면
    if (!frame.loadFromFile("image/Rule_frame.png")) {
        // 이미지 로딩에 실패한 경우의 처리 (필요에 따라 추가)
    }
    Sprite frameSprite(frame);  // 게임 화면 이미지 할당

    Texture buttonTexture;
    if (!buttonTexture.loadFromFile("image/Back_btn.png")) {
        // 이미지 로딩에 실패한 경우의 처리 (필요에 따라 추가)
    }
    Sprite backButton(buttonTexture);
    backButton.setPosition(1100, 650);

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();

            if (event.type == Event::MouseButtonPressed) {
                if (event.mouseButton.button == Mouse::Left) {
                    Vector2i mousePos = Mouse::getPosition(window);

                    if (backButton.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                        start.run(window);

                    }
                }
            }
        }

        window.clear();
        window.draw(frameSprite);
        window.draw(backButton);
        window.display();
    }
}
