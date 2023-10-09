#include "game.h"

int main() {
    RenderWindow window(sf::VideoMode(1500, 800), "����");
    Game game;  //���� ��ü ����

    Texture textureMain;
    if (!textureMain.loadFromFile("image/Main_frame.png")) {
        return -1; // �̹����� �ҷ��� �� ������ ����
    }

    Sprite sprite(textureMain);

    Texture start_btn;
    if (!start_btn.loadFromFile("image/Start_btn.png")) {
        return -1; // �̹����� �ҷ��� �� ������ ����
    }

    Sprite button1(start_btn);
    button1.setPosition(900, 500);

    Texture Rule_btn;
    if (!Rule_btn.loadFromFile("image/Rule_btn.png")) {
        return -1; // �̹����� �ҷ��� �� ������ ����
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
                        printf("���ӽ��� ��ư");// ��ư 1�� ������ �� ������ �ڵ� �߰�
                        game.run(window);  //����ȭ�� ����
                
                    }

                    if (button2.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                        printf("���ӹ�� ��ư");
                        // ��ư 2�� ������ �� ������ �ڵ� �߰�
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
