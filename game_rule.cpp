#include <SFML/Graphics.hpp>
#include "game_rule.h"
#include "main.h"

using namespace sf;
void Game_Rule::run(RenderWindow& window) {
    window.create(VideoMode(1500, 800), "���ӹ��");
    Start start;  //����ȭ�� ��ü ����
    Texture frame;  // ���� ȭ��
    if (!frame.loadFromFile("image/Rule_frame.png")) {
        // �̹��� �ε��� ������ ����� ó�� (�ʿ信 ���� �߰�)
    }
    Sprite frameSprite(frame);  // ���� ȭ�� �̹��� �Ҵ�

    Texture buttonTexture;
    if (!buttonTexture.loadFromFile("image/Back_btn.png")) {
        // �̹��� �ε��� ������ ����� ó�� (�ʿ信 ���� �߰�)
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
