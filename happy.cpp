#include <SFML/Graphics.hpp>
#include "happy.h"
#include "main.h"
using namespace sf;

void Happy::run(RenderWindow& window) {
    window.create(VideoMode(1500, 800), "���� ����");

    Texture Happy_frame;  // ���� ȭ��
    if (!Happy_frame.loadFromFile("image/Happy_frame.png")) {
      
    }
    Sprite frameSprite(Happy_frame);  // ���� ȭ�� �̹��� �Ҵ�
    Texture buttonTexture;
    if (!buttonTexture.loadFromFile("image/Startback_btn.png")) {
        // �̹��� �ε��� ������ ����� ó�� (�ʿ信 ���� �߰�)
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
