#include <SFML/Graphics.hpp>
#include "bad.h"
#include "main.h"

using namespace sf;

void Bad::run(RenderWindow& window) {
    window.create(VideoMode(1500, 800), "배드 엔딩");

    Texture bad_frame;
    if (!bad_frame.loadFromFile("image/Bad_frame.png")) {
        // 이미지 로딩에 실패한 경우의 처리 (필요에 따라 추가)
    }
    Sprite frameSprite(bad_frame);

    Texture buttonTexture;
    if (!buttonTexture.loadFromFile("image/Startback_btn.png")) {
        // 이미지 로딩에 실패한 경우의 처리 (필요에 따라 추가)
    }
    Sprite Startback_btn(buttonTexture);
    Startback_btn.setPosition(1100, 650);

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();

            if (event.type == Event::MouseButtonPressed) {
                if (event.mouseButton.button == Mouse::Left) {
                    Vector2i mousePos = Mouse::getPosition(window);

                    if (Startback_btn.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                        Start start;
                        start.run(window);
                    }
                }
            }
        }

        window.clear();
        window.draw(frameSprite);
        window.draw(Startback_btn);
        window.display();
    }
}
