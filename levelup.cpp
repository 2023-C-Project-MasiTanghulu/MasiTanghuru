#include <SFML/Graphics.hpp>
#include "levleup.h"
#include "game.h"

using namespace sf;

void Levelup::run(RenderWindow& window) {
    window.create(VideoMode(1500, 800), "배드 엔딩");

    Texture Levelup_frame;
    if (!Levelup_frame.loadFromFile("image/Levelup_frame.png")) {
        // 이미지 로딩에 실패한 경우의 처리 (필요에 따라 추가)
    }
    Sprite frameSprite(Levelup_frame);

    Texture buttonTexture;
    if (!buttonTexture.loadFromFile("image/Nextstep_btn.png")) {
        // 이미지 로딩에 실패한 경우의 처리 (필요에 따라 추가)
    }
    Sprite Nextstep_btn(buttonTexture);
    Nextstep_btn.setPosition(1100, 650);

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();

            if (event.type == Event::MouseButtonPressed) {
                if (event.mouseButton.button == Mouse::Left) {
                    Vector2i mousePos = Mouse::getPosition(window);

                    if (Nextstep_btn.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                        Game game;
                        game.run(window);
                    }
                }
            }
        }

        window.clear();
        window.draw(frameSprite);
        window.draw(Nextstep_btn);
        window.display();
    }
}