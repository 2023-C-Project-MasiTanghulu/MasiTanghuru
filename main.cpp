#include "game.h"

int main() {
    RenderWindow window(sf::VideoMode(1500, 800), "메인");
    Game game;  //게임 객체 생성

    Texture textureMain;
    if (!textureMain.loadFromFile("image/Main_frame.png")) {
        return -1; // 이미지를 불러올 수 없으면 종료
    }

    Sprite sprite(textureMain);

    Texture start_btn;
    if (!start_btn.loadFromFile("image/Start_btn.png")) {
        return -1; // 이미지를 불러올 수 없으면 종료
    }

    Sprite button1(start_btn);
    button1.setPosition(900, 500);

    Texture Rule_btn;
    if (!Rule_btn.loadFromFile("image/Rule_btn.png")) {
        return -1; // 이미지를 불러올 수 없으면 종료
    }

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
                        printf("게임시작 버튼");// 버튼 1을 눌렀을 때 실행할 코드 추가
                        game.run(window);  //게임화면 실행
                
                    }

                    if (button2.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                        printf("게임방법 버튼");
                        // 버튼 2를 눌렀을 때 실행할 코드 추가
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

    return 0;
}
