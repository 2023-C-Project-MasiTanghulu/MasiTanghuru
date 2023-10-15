#include <iostream>
#include <time.h>
#include <thread>
#include "game.h"
#include "fruit.h"

using namespace std;

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

    // 3�� �Ŀ� ��ǳ���� ����� �Լ�
    auto clearSpeechBubble = [&speechBubbleSprite]() {
        this_thread::sleep_for(chrono::seconds(3));
        speechBubbleSprite.setPosition(-1000, -1000); // ȭ�� ������ �̵����� ������ �ʰ� ��
    };

    // 3�� �ڿ� ��ǳ���� ����
    thread(clearSpeechBubble).detach();  // �� �����忡�� ����


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
    bool isClicked = false;  //���콺 Ŭ���� �ߴ°� ���ߴ°�
    vector<Fruit> fruits;  //���� ����

    //���ѽð� : �� ����
    Clock clock;
    const Time timeLimit = seconds(60); // 60�ʷ� ����

    //��Ʈ ����
    Font font;
    if (!font.loadFromFile("font/NanumGothic.ttf")) {
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

    //��ǳ�� ��: �մ� �ֹ�
    Text bubbleText;
    bubbleText.setFont(font);
    bubbleText.setCharacterSize(50);
    bubbleText.setFillColor(Color::Black);
    bubbleText.setStyle(Text::Bold);
    bubbleText.setPosition(100,50 ); // �ؽ�Ʈ ��ġ ����
    bubbleText.setString(L"���� ���ķ� �ּ���."); // ���� ����

    // 3�� �Ŀ� ��ǳ�� ������ ����� �Լ�
    auto clearBubbleText = [&bubbleText]() {
        std::this_thread::sleep_for(std::chrono::seconds(3));
        bubbleText.setString(L"");
    };

    // 3�� �ڿ� ��ǳ�� ���� ����
    thread(clearBubbleText).detach();

    Texture Sale_btn_texture;
    Sale_btn_texture.loadFromFile("image/Sale_btn.png"); // ��ư �̹��� �ҷ�����
    Sprite Sale_btn_sprite(Sale_btn_texture);
    Sale_btn_sprite.setPosition(50, 50); // ��ư ��ġ ����

    bool Sale_btnVisible = false; // Sale ��ư�� ó������ ���ܳ���

    // 3�� �ڿ� Sale ��ư�� ���̵��� �ϴ� �Լ�
    auto AfterSale_btn = [&]() {
        std::this_thread::sleep_for(std::chrono::seconds(3));
        Sale_btnVisible = true;
    };

   thread(AfterSale_btn).detach(); // �� �����忡�� ����



    // ���� �ֹ� ���
    vector<wstring> orders = {
        L"���� ���ķ� �ּ���.",
        L"���θӽ��� ���ķ� �ּ���.",
        L"���ξ��� ���ķ� �ּ���.",
        L"�� �����̾� ���� ���ķ� �ּ���.",
        L"��� ���ķ� �ּ���.",
        L"����, ���θӽ�Ĺ ���ķ� �ּ���.",
        L"����, ���ξ��� ���ķ� �ּ���.",
        L"����, �� �����̾� ���� ���ķ� �ּ���.",
        L"����, ��� ���ķ� �ּ���.",
        L"���θӽ�Ĺ, ���ξ��� ���ķ� �ּ���.",
        L"���θӽ�Ĺ, �� �����̾� ���� ���ķ� �ּ���.",
        L"���θӽ�Ĺ, ��� ���ķ� �ּ���.",
        L"���ξ���, �� �����̾� ���ķ� �ּ���."
    };


    //��ǳ�� ���� �������� ����
    int randomIndex = rand() % orders.size(); // ������ �ε��� ����
    bubbleText.setString(orders[randomIndex]);



    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
        }
        Vector2i mousePosition = Mouse::getPosition(window);

        //Ŭ������ ��
        if (!isClicked && event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
            isClicked = true;  //Ŭ����

            //Ŀ���� ���� �ڽ� ���� �ִٸ� �� ������ ����
            if (blackGrapeBox.getGlobalBounds().contains(static_cast<Vector2f>(mousePosition))) {  //�� �����̾� ����
                Fruit blackGrape("blackGrape");  //�� �����̾� ��ü ����
                blackGrape.sprite.setTexture(blackGrapeTexture);  //�� �����̾� �̹��� �Ҵ�
                blackGrape.sprite.setPosition(1200, 1000);  //�� �����̾� ��ġ ����
                fruits.push_back(blackGrape);  //���Ϳ� �߰�
            }
            else if (strawberryBox.getGlobalBounds().contains(static_cast<Vector2f>(mousePosition))) {  //���� ����
                Fruit strawberry("strawberry");  //���� ��ü ����
                strawberry.sprite.setTexture(strawberryTexture);  //���� �̹��� �Ҵ�
                strawberry.sprite.setPosition(1200, 1000);  //���� ��ġ ����
                fruits.push_back(strawberry);  //���Ϳ� �߰�
            }
            else if (shineMusketBox.getGlobalBounds().contains(static_cast<Vector2f>(mousePosition))) {  //���θӽ��� ����
                Fruit shineMusket("shineMusket");  //���θӽ��� ��ü ����
                shineMusket.sprite.setTexture(shineMusketTexture);  //���θӽ��� �̹��� �Ҵ�
                shineMusket.sprite.setPosition(1200, 1000);  //���θӽ��� ��ġ ����
                fruits.push_back(shineMusket);  //���Ϳ� �߰�
            }
            else if (mandarinBox.getGlobalBounds().contains(static_cast<Vector2f>(mousePosition))) {  //�� ����
                Fruit mandarin("mandarin");  //�� ��ü ����
                mandarin.sprite.setTexture(mandarinTexture);  //�� �̹��� �Ҵ�
                mandarin.sprite.setPosition(1200, 1000);  //�� ��ġ ����
                fruits.push_back(mandarin);  //���Ϳ� �߰�
            }
            else if (pineappleBox.getGlobalBounds().contains(static_cast<Vector2f>(mousePosition))) {  //���ξ��� ����
                Fruit pineapple("pineapple");  //���ξ��� ��ü ����
                pineapple.sprite.setTexture(pineappleTexture);  //���ξ��� �̹��� �Ҵ�
                pineapple.sprite.setPosition(1200, 1000);  //���ξ��� ��ġ ����
                fruits.push_back(pineapple);  //���Ϳ� �߰�
            }
            else if (stickBox.getGlobalBounds().contains(static_cast<Vector2f>(mousePosition)) && fruits.empty()) {  //fruits ���Ͱ� ������� ��ġ ����
                Fruit stick("stick");  //��ġ ��ü ����
                stick.isStick = true;  //��ġ��
                stick.sprite.setTexture(stickTexture);  //��ġ �̹��� �Ҵ�
                stick.sprite.setPosition(1200,1000);  //��ġ ��ġ ����
                fruits.push_back(stick);  //���Ϳ� �߰�
            }
        }
        int positionX = 200;  //���� x ��ġ ����
        int positionY = 570;  //���� y ��ġ ����

        // ���콺 ���� ��
        if (event.type == Event::MouseButtonReleased && event.mouseButton.button == Mouse::Left) {
            Sprite stick;  //��ġ
            isClicked = false;  //Ŭ�� ����

            for (Fruit& fruit : fruits) {  //����
                fruit.grabbed = false;
                if (fruit.isStick) {  //��ġ��
                    stick = fruit.sprite;  //fruits ���Ϳ� �ִ� ��ƽ�� ������ ��������
                }
                //������ ��ġ ���� �� ���ų� ���� ���� ��Ḧ �� ���Ҵٸ�
                if (!stick.getGlobalBounds().intersects(fruit.sprite.getGlobalBounds()) || !cuttingBoardSprite.getGlobalBounds().intersects(fruit.sprite.getGlobalBounds())) {
                    fruits.pop_back();  //��ü���� ����
                }
                if(!fruit.isStick){  //��ġ�� �ƴ϶� �����̸�
                    fruit.sprite.setPosition(positionX, positionY-fruit.sprite.getGlobalBounds().height/2);  //���� ��ġ �ڵ����� ����
                    positionX += fruit.sprite.getGlobalBounds().width;  //���� ���� ����
                }
                else {  //��ġ��
                    fruit.sprite.setPosition(40, 570);  //��ġ ��ġ �ڵ����� ����
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
            //window.close();
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
        if (Sale_btnVisible) {
            window.draw(Sale_btn_sprite);
        }

        window.draw(timerText); // ���� �ð� ǥ��
        window.draw(bubbleText);//��ǳ�� ��
        window.display();

    }

}