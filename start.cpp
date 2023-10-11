#include "game.h"
#include"game_rule.h"
#include "main.h"
#include "bad.h"
#include "happy.h"


void Start::run(RenderWindow& window) {
    window.create(VideoMode(1500, 800), "����ȭ��");
    Game game;  //���� ȭ�� ��ü ����
    Game_Rule game_rule;  //���� ��� ȭ�� ��ü ����

    Texture textureMain;
    textureMain.loadFromFile("image/Main_frame.png");

    Sprite sprite(textureMain);

    Texture start_btn;
    start_btn.loadFromFile("image/Start_btn.png");

    Sprite button1(start_btn);
    button1.setPosition(900, 500);

    Texture Rule_btn;
    Rule_btn.loadFromFile("image/Rule_btn.png");

    Sprite button2(Rule_btn);
    button2.setPosition(900, 650);

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();

            if (event.type == Event::MouseButtonPressed) {
                if (event.mouseButton.button == Mouse::Left) {
                    Vector2i mousePos = Mouse::getPosition(window);

                    if (button1.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                        printf("���ӽ��� ��ư");
                        game.run(window);  //����ȭ�� ����

                    }

                    if (button2.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                        printf("���ӹ�� ��ư");
                        game_rule.run(window); //���ӹ�� ȭ�� ����

                    }
                }
            }
        }

        window.clear();
        window.draw(sprite);
        window.draw(button1);
        window.draw(button2);
        window.display();
    }
}