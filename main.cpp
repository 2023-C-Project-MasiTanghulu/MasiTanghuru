#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(1500, 800), "메인");

    sf::Texture texture;
    if (!texture.loadFromFile("image/Main_frame.png")) {
        return -1; // 이미지를 불러올 수 없으면 종료
    }

    sf::Sprite sprite(texture);

    sf::Texture buttonTexture1;
    if (!buttonTexture1.loadFromFile("image/Start_btn.png")) {
        return -1; // 이미지를 불러올 수 없으면 종료
    }

    sf::Sprite button1(buttonTexture1);
    button1.setPosition(900, 500);

    sf::Texture buttonTexture2;
    if (!buttonTexture2.loadFromFile("image/Rule_btn.png")) {
        return -1; // 이미지를 불러올 수 없으면 종료
    }

    sf::Sprite button2(buttonTexture2);
    button2.setPosition(900, 650);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);

                    if (button1.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                        printf("게임시작 버튼");// 버튼 1을 눌렀을 때 실행할 코드 추가
                    }

                    if (button2.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                        printf("게임룰 버튼");
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
