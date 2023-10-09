#include <SFML/Graphics.hpp>
#include "game.h"
#include <iostream>

using namespace sf;

//���� Ŭ����
class Fruit { 
public:
    Sprite sprite;  // ���� �̹���
    bool grabbed;   // ������ ��Ҵ°�
    bool isStick = false;  //��ġ�ΰ�
    String name;  //���� �̸�
    //������
    Fruit(){
        grabbed = true;
    }
};

void game() {
    RenderWindow window(VideoMode(1500, 800), "���ķ� �����");

    Texture frame;  //���� ȭ��
    frame.loadFromFile("image/Game_frame.png");  //���� ȭ�� �̹���
    Sprite frameSprite(frame);  //���� ȭ�� �̹��� �Ҵ�

    Texture speechBubble;  //��ǳ��
    speechBubble.loadFromFile("image/speechBubble.png");  //��ǳ�� �̹���
    Sprite speechBubbleSprite(speechBubble);  //��ǳ�� �̹��� �Ҵ�
    speechBubbleSprite.setPosition(0, 0);  //��ǳ�� ��ġ ����

    Texture blackGrapeBoxTexture;  //�� �����̾� �ڽ�
    blackGrapeBoxTexture.loadFromFile("image/BlackGrape_box.png");  //�� �����̾� �ڽ� �̹���
    Sprite blackGrapeBox(blackGrapeBoxTexture);  //�� �����̾� �ڽ� �̹��� �Ҵ�
    blackGrapeBox.setPosition(960, 260);  //�� �����̾� �ڽ� ��ġ ����

    Texture blackGrapeTexture;  //�� �����̾�
    blackGrapeTexture.loadFromFile("image/BlackGrape.png");  //�� �����̾� �̹���

    Texture strawberryBoxTexture;  //���� �ڽ�
    strawberryBoxTexture.loadFromFile("image/Strawberry_box.png");  //���� �ڽ� �̹���
    Sprite strawberryBox(strawberryBoxTexture);  //���� �ڽ� �̹��� �Ҵ�
    strawberryBox.setPosition(1200, 260);  //���� �ڽ� ��ġ ����

    Texture strawberryTexture;  //����
    strawberryTexture.loadFromFile("image/Strawberry.png");  //���� �̹���

    Texture shineMuscatBoxTexture;  //���θӽ��� �ڽ�
    shineMuscatBoxTexture.loadFromFile("image/Shinemuscat_box.png");  //���θӽ��� �ڽ� �̹���
    Sprite shineMuscatBox(shineMuscatBoxTexture);  //���θӽ��� �ڽ� �̹��� �Ҵ�
    shineMuscatBox.setPosition(960, 440);  //���θӽ��� �ڽ� ��ġ ����

    Texture shineMuscatTexture;  //���θӽ���
    shineMuscatTexture.loadFromFile("image/Shinemuscat.png");  //���θӽ��� �̹���

    Texture mandarinBoxTexture;  //�� �ڽ�
    mandarinBoxTexture.loadFromFile("image/Mandarin_box.png");  //�� �ڽ� �̹���
    Sprite mandarinBox(mandarinBoxTexture);  //�� �ڽ� �̹��� �Ҵ�
    mandarinBox.setPosition(1200, 440);  //�� �ڽ� ��ġ ����

    Texture mandarinTexture;  //��
    mandarinTexture.loadFromFile("image/Mandarin.png");  //�� �̹���

    Texture pineappleBoxTexture;  //���ξ��� �ڽ�
    pineappleBoxTexture.loadFromFile("image/Pineapple_box.png");  //���ξ��� �ڽ� �̹���
    Sprite pineappleBox(pineappleBoxTexture);  //���ξ��� �ڽ� �̹��� �Ҵ�
    pineappleBox.setPosition(960, 620);  //���ξ��� �ڽ� ��ġ ����

    Texture pineappleTexture;  //���ξ���
    pineappleTexture.loadFromFile("image/Pineapple.png");  //���ξ��� �̹���

    Texture stickBoxTexture;  //��ġ �ڽ�
    stickBoxTexture.loadFromFile("image/Stick_box.png");  //��ġ �ڽ� �̹���
    Sprite stickBox(stickBoxTexture);  //��ġ �ڽ� �̹��� �Ҵ�
    stickBox.setPosition(1190, 610);  //��ġ �ڽ� ��ġ ����

    Texture stickTexture;  //��ġ
    stickTexture.loadFromFile("image/Stick.png");  //��ġ �̹���

    bool isFruitGrabbed = false;  //������ �����°� �������°�
    std::vector<Fruit> fruits;  //���� ����

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
        }
        Vector2i mousePosition = Mouse::getPosition(window);
        //Ŭ������ ��
        if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {

            //Ŀ���� ���� �ڽ� ���� �ִٸ� �� ������ ����
            if (blackGrapeBox.getGlobalBounds().contains(static_cast<Vector2f>(mousePosition))) {  //�� �����̾� ����
                Fruit blackGrape;  //�� �����̾� ��ü ����
                blackGrape.sprite.setTexture(blackGrapeTexture);  //�� �����̾� �̹��� �Ҵ�
                blackGrape.sprite.setPosition(static_cast<Vector2f>(mousePosition));  //�� �����̾� ��ġ ����
                fruits.push_back(blackGrape);  //���Ϳ� �߰�
            }
            if (strawberryBox.getGlobalBounds().contains(static_cast<Vector2f>(mousePosition))) {  //���� ����
                Fruit strawberry;  //���� ��ü ����
                strawberry.sprite.setTexture(strawberryTexture);  //���� �̹��� �Ҵ�
                strawberry.sprite.setPosition(static_cast<Vector2f>(mousePosition));  //���� ��ġ ����
                fruits.push_back(strawberry);  //���Ϳ� �߰�
            }
            if (shineMuscatBox.getGlobalBounds().contains(static_cast<Vector2f>(mousePosition))) {  //���θӽ��� ����
                Fruit shineMuscat;  //���θӽ��� ��ü ����
                shineMuscat.sprite.setTexture(shineMuscatTexture);  //���θӽ��� �̹��� �Ҵ�
                shineMuscat.sprite.setPosition(static_cast<Vector2f>(mousePosition));  //���θӽ��� ��ġ ����
                fruits.push_back(shineMuscat);  //���Ϳ� �߰�
            }
            if (mandarinBox.getGlobalBounds().contains(static_cast<Vector2f>(mousePosition))) {  //�� ����
                Fruit mandarin;  //�� ��ü ����
                mandarin.sprite.setTexture(mandarinTexture);  //�� �̹��� �Ҵ�
                mandarin.sprite.setPosition(static_cast<Vector2f>(mousePosition));  //�� ��ġ ����
                fruits.push_back(mandarin);  //���Ϳ� �߰�
            }
            if (pineappleBox.getGlobalBounds().contains(static_cast<Vector2f>(mousePosition))) {  //���ξ��� ����
                Fruit pineapple;  //���ξ��� ��ü ����
                pineapple.sprite.setTexture(pineappleTexture);  //���ξ��� �̹��� �Ҵ�
                pineapple.sprite.setPosition(static_cast<Vector2f>(mousePosition));  //���ξ��� ��ġ ����
                fruits.push_back(pineapple);  //���Ϳ� �߰�
            }
            if (stickBox.getGlobalBounds().contains(static_cast<Vector2f>(mousePosition))) {  //��ġ ����
                Fruit stick;  //��ġ ��ü ����
                stick.isStick = true;  //��ġ��
                stick.sprite.setTexture(stickTexture);  //��ġ �̹��� �Ҵ�
                stick.sprite.setPosition(static_cast<Vector2f>(mousePosition));  //��ġ ��ġ ����
                fruits.push_back(stick);  //���Ϳ� �߰�
            }
        }

        // ���콺 ���� ��
        if (event.type == Event::MouseButtonReleased && event.mouseButton.button == Mouse::Left) {
            Sprite stick;  //��ƽ
            for (Fruit& fruit : fruits) {  //����
                fruit.grabbed = false;
                if (fruit.isStick) {  //��ƽ���� Ȯ��
                    stick = fruit.sprite;  //fruits ���Ϳ� �ִ� ��ƽ�� ������ ��������
                }
                if (!stick.getGlobalBounds().intersects(fruit.sprite.getGlobalBounds())) {  //������ ��ƽ ���� �� ���Ҵٸ�
                    fruits.pop_back();  //��ü���� ����
                }
            }
        }

        // ���콺 �̵� ��
        if (event.type == Event::MouseMoved) {
            //�巡���ϸ� ������ ���콺 ��ġ�� �̵�
            Vector2i mousePosition = Mouse::getPosition(window);
            for (Fruit& fruit : fruits) {  //����
                if (fruit.grabbed) {
                    fruit.sprite.setPosition(static_cast<Vector2f>(mousePosition));
                }
            }
        }

        window.clear();
        //�� ������ ���̾ ����
        window.draw(frameSprite);  //����ȭ�� draw
        window.draw(speechBubbleSprite);  //��ǳ�� draw
        window.draw(blackGrapeBox);  //�� �����̾� �ڽ� draw
        window.draw(strawberryBox);  //���� �ڽ� draw
        window.draw(shineMuscatBox);  //���θӽ��� �ڽ� draw
        window.draw(mandarinBox);  //�� �ڽ� draw
        window.draw(pineappleBox);  //���ξ��� �ڽ� draw
        window.draw(stickBox);  //��ġ �ڽ� draw
        for (const Fruit& fruit : fruits) { //���� draw
            window.draw(fruit.sprite);
        }
        window.display();

    }

}