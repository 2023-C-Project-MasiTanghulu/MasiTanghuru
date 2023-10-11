#include <SFML/Graphics.hpp>
#include <iostream>
#include <time.h>
#include "game.h"
#include <string>

using namespace std;

//���� Ŭ����
class Fruit { 
public:
    Sprite sprite;  // ���� �̹���
    bool grabbed;   // ������ ��Ҵ°�
    bool isStick = false;  //��ġ�ΰ�
    string name;  //���� �̸�
    //������
    Fruit(String fruitName) : name(fruitName){
        grabbed = true;
    }
};

void Game::run(RenderWindow& window) {
    window.create(VideoMode(1500, 800), "���ķ� �����");

    //���ķ� ����
    Texture frame;  //���� ȭ��
    frame.loadFromFile("image/Game_frame.png");  //���� ȭ�� �̹���
    Sprite frameSprite(frame);  //���� ȭ�� �̹��� �Ҵ�

    Texture cuttingBoard;  //����
    cuttingBoard.loadFromFile("image/CuttingBoard.png");  //���� �̹���
    Sprite cuttingBoardSprite(cuttingBoard);  //���� �̹��� �Ҵ�
    cuttingBoardSprite.setPosition(20,310);  //���� ��ġ ����

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

    Texture shineMusketBoxTexture;  //���θӽ��� �ڽ�
    shineMusketBoxTexture.loadFromFile("image/Shinemusket_box.png");  //���θӽ��� �ڽ� �̹���
    Sprite shineMusketBox(shineMusketBoxTexture);  //���θӽ��� �ڽ� �̹��� �Ҵ�
    shineMusketBox.setPosition(960, 440);  //���θӽ��� �ڽ� ��ġ ����

    Texture shineMusketTexture;  //���θӽ���
    shineMusketTexture.loadFromFile("image/Shinemusket.png");  //���θӽ��� �̹���

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
    vector<Fruit> fruits;  //���� ����

    //���ѽð� : �� ����
    Clock clock;
    const Time timeLimit = seconds(60); // 60�ʷ� ����

    //��Ʈ ����
    Font font;
    if (!font.loadFromFile("font/NanumSquareL.ttf")) {
        // ��Ʈ�� �ε����� ���� ��� ����ó��
        cout << "��Ʈ�� �ε��� �� �����ϴ�." << endl;
    }

    // ���� �ð� : ȭ�鿡 ǥ���� �ؽ�Ʈ ����
    Text timerText;
    timerText.setFont(font); // ��Ʈ ���� (sfml�� ������ ��Ʈ�� ����ؾ���. )
    timerText.setCharacterSize(50); // �۲� ũ�� ����
    timerText.setFillColor(Color::Black); // �۲� ������ ���������� ����
    timerText.setStyle(Text::Bold); // �۲� ��Ÿ�� ����
    timerText.setPosition(1250,35 ); // �ؽ�Ʈ ��ġ ����


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
                Fruit blackGrape("blackGrape");  //�� �����̾� ��ü ����
                blackGrape.sprite.setTexture(blackGrapeTexture);  //�� �����̾� �̹��� �Ҵ�
                Vector2f centerPosition(static_cast<float>(mousePosition.x - blackGrape.sprite.getLocalBounds().width / 2), static_cast<float>(mousePosition.y - blackGrape.sprite.getLocalBounds().height / 2));
                blackGrape.sprite.setPosition(static_cast<Vector2f>(centerPosition));  //�� �����̾� ��ġ ����
                fruits.push_back(blackGrape);  //���Ϳ� �߰�
            }
            else if (strawberryBox.getGlobalBounds().contains(static_cast<Vector2f>(mousePosition))) {  //���� ����
                Fruit strawberry("strawberry");  //���� ��ü ����
                strawberry.sprite.setTexture(strawberryTexture);  //���� �̹��� �Ҵ�
                Vector2f centerPosition(static_cast<float>(mousePosition.x - strawberry.sprite.getLocalBounds().width / 2), static_cast<float>(mousePosition.y - strawberry.sprite.getLocalBounds().height / 2));
                strawberry.sprite.setPosition(centerPosition);  //���� ��ġ ����
                fruits.push_back(strawberry);  //���Ϳ� �߰�
            }
            else if (shineMusketBox.getGlobalBounds().contains(static_cast<Vector2f>(mousePosition))) {  //���θӽ��� ����
                Fruit shineMusket("shineMusket");  //���θӽ��� ��ü ����
                shineMusket.sprite.setTexture(shineMusketTexture);  //���θӽ��� �̹��� �Ҵ�
                Vector2f centerPosition(static_cast<float>(mousePosition.x - shineMusket.sprite.getLocalBounds().width / 2), static_cast<float>(mousePosition.y - shineMusket.sprite.getLocalBounds().height / 2));
                shineMusket.sprite.setPosition(centerPosition);  //���θӽ��� ��ġ ����
                fruits.push_back(shineMusket);  //���Ϳ� �߰�
            }
            else if (mandarinBox.getGlobalBounds().contains(static_cast<Vector2f>(mousePosition))) {  //�� ����
                Fruit mandarin("mandarin");  //�� ��ü ����
                mandarin.sprite.setTexture(mandarinTexture);  //�� �̹��� �Ҵ�
                Vector2f centerPosition(static_cast<float>(mousePosition.x - mandarin.sprite.getLocalBounds().width / 2), static_cast<float>(mousePosition.y - mandarin.sprite.getLocalBounds().height / 2));
                mandarin.sprite.setPosition(centerPosition);  //�� ��ġ ����
                fruits.push_back(mandarin);  //���Ϳ� �߰�
            }
            else if (pineappleBox.getGlobalBounds().contains(static_cast<Vector2f>(mousePosition))) {  //���ξ��� ����
                Fruit pineapple("pineapple");  //���ξ��� ��ü ����
                pineapple.sprite.setTexture(pineappleTexture);  //���ξ��� �̹��� �Ҵ�
                Vector2f centerPosition(static_cast<float>(mousePosition.x - pineapple.sprite.getLocalBounds().width / 2), static_cast<float>(mousePosition.y - pineapple.sprite.getLocalBounds().height / 2));
                pineapple.sprite.setPosition(centerPosition);  //���ξ��� ��ġ ����
                fruits.push_back(pineapple);  //���Ϳ� �߰�
            }
            else if (stickBox.getGlobalBounds().contains(static_cast<Vector2f>(mousePosition))) {  //��ġ ����
                Fruit stick("stick");  //��ġ ��ü ����
                stick.isStick = true;  //��ġ��
                stick.sprite.setTexture(stickTexture);  //��ġ �̹��� �Ҵ�
                Vector2f centerPosition(static_cast<float>(mousePosition.x - stick.sprite.getLocalBounds().width / 2), static_cast<float>(mousePosition.y - stick.sprite.getLocalBounds().height / 2));
                stick.sprite.setPosition(centerPosition);  //��ġ ��ġ ����
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
                //������ ��ƽ ���� �� ���ų� ���� ���� ��Ḧ �� ���Ҵٸ�
                if (!stick.getGlobalBounds().intersects(fruit.sprite.getGlobalBounds()) || !cuttingBoardSprite.getGlobalBounds().intersects(fruit.sprite.getGlobalBounds())) {
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
                    // ���콺 ��ġ�� �̹����� �߽����� ����
                    Vector2f centerPosition(static_cast<float>(mousePosition.x - fruit.sprite.getLocalBounds().width / 2), static_cast<float>(mousePosition.y - fruit.sprite.getLocalBounds().height / 2));
                    fruit.sprite.setPosition(centerPosition);
                }
            }
        }
        //���ķ� ���� ��

        //���ѽð� : �ð� ������ �ڵ�
        Time elapsed = clock.getElapsedTime();
        if (elapsed >= timeLimit) {
            cout << "�ð� �ʰ�!" << endl;
            window.close();
        }
        //���ѽð� : �ð� ������ �ڵ� ��

       // �ð��� ���ڿ��� ��ȯ�Ͽ� �ؽ�Ʈ�� ����
        int remainingTime = timeLimit.asSeconds() - elapsed.asSeconds();
        timerText.setString(to_string(remainingTime));
        

        window.clear();
        //�� ������ ���̾ ����
        window.draw(cuttingBoardSprite);  //���� draw
        window.draw(frameSprite);  //����ȭ�� draw
        window.draw(speechBubbleSprite);  //��ǳ�� draw
        window.draw(blackGrapeBox);  //�� �����̾� �ڽ� draw
        window.draw(strawberryBox);  //���� �ڽ� draw
        window.draw(shineMusketBox);  //���θӽ��� �ڽ� draw
        window.draw(mandarinBox);  //�� �ڽ� draw
        window.draw(pineappleBox);  //���ξ��� �ڽ� draw
        window.draw(stickBox);  //��ġ �ڽ� draw
        for (const Fruit& fruit : fruits) { //���� draw
            window.draw(fruit.sprite);
        }
        window.draw(timerText); // ���� �ð� ǥ��
        window.display();

    }

}