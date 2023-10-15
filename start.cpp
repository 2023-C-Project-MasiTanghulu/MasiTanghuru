#include "game.h"
#include"game_rule.h"
#include "main.h"
#include "bad.h"
#include "happy.h"


void Start::run(RenderWindow& window) {
    window.create(VideoMode(1500, 800), "시작화면");
    Game game;  //게임 화면 객체 생성
    Game_Rule game_rule;  //게임 방법 화면 객체 생성

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
                        printf("게임시작 버튼");
                        game.run(window);  //게임화면 실행

                    }

                    if (button2.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                        printf("게임방법 버튼");
                        game_rule.run(window); //게임방법 화면 실행
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