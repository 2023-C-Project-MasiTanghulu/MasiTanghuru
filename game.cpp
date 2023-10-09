#include <SFML/Graphics.hpp>
#include "game.h"
#include <iostream>

using namespace sf;

//과일 클래스
class Fruit { 
public:
    Sprite sprite;  // 과일 이미지
    bool grabbed;   // 과일을 잡았는가
    bool isStick = false;  //꼬치인가
    String name;  //과일 이름
    //생성자
    Fruit(){
        grabbed = true;
    }
};

void game() {
    RenderWindow window(VideoMode(1500, 800), "탕후루 만들기");

    Texture frame;  //게임 화면
    frame.loadFromFile("image/Game_frame.png");  //게임 화면 이미지
    Sprite frameSprite(frame);  //게임 화면 이미지 할당

    Texture speechBubble;  //말풍선
    speechBubble.loadFromFile("image/speechBubble.png");  //말풍선 이미지
    Sprite speechBubbleSprite(speechBubble);  //말풍선 이미지 할당
    speechBubbleSprite.setPosition(0, 0);  //말풍선 위치 설정

    Texture blackGrapeBoxTexture;  //블랙 사파이어 박스
    blackGrapeBoxTexture.loadFromFile("image/BlackGrape_box.png");  //블랙 사파이어 박스 이미지
    Sprite blackGrapeBox(blackGrapeBoxTexture);  //블랙 사파이어 박스 이미지 할당
    blackGrapeBox.setPosition(960, 260);  //블랙 사파이어 박스 위치 설정

    Texture blackGrapeTexture;  //블랙 사파이어
    blackGrapeTexture.loadFromFile("image/BlackGrape.png");  //블랙 사파이어 이미지

    Texture strawberryBoxTexture;  //딸기 박스
    strawberryBoxTexture.loadFromFile("image/Strawberry_box.png");  //딸기 박스 이미지
    Sprite strawberryBox(strawberryBoxTexture);  //딸기 박스 이미지 할당
    strawberryBox.setPosition(1200, 260);  //딸기 박스 위치 설정

    Texture strawberryTexture;  //딸기
    strawberryTexture.loadFromFile("image/Strawberry.png");  //딸기 이미지

    Texture shineMuscatBoxTexture;  //샤인머스켓 박스
    shineMuscatBoxTexture.loadFromFile("image/Shinemuscat_box.png");  //샤인머스켓 박스 이미지
    Sprite shineMuscatBox(shineMuscatBoxTexture);  //샤인머스켓 박스 이미지 할당
    shineMuscatBox.setPosition(960, 440);  //샤인머스켓 박스 위치 설정

    Texture shineMuscatTexture;  //샤인머스켓
    shineMuscatTexture.loadFromFile("image/Shinemuscat.png");  //샤인머스켓 이미지

    Texture mandarinBoxTexture;  //귤 박스
    mandarinBoxTexture.loadFromFile("image/Mandarin_box.png");  //귤 박스 이미지
    Sprite mandarinBox(mandarinBoxTexture);  //귤 박스 이미지 할당
    mandarinBox.setPosition(1200, 440);  //귤 박스 위치 설정

    Texture mandarinTexture;  //귤
    mandarinTexture.loadFromFile("image/Mandarin.png");  //귤 이미지

    Texture pineappleBoxTexture;  //파인애플 박스
    pineappleBoxTexture.loadFromFile("image/Pineapple_box.png");  //파인애플 박스 이미지
    Sprite pineappleBox(pineappleBoxTexture);  //파인애플 박스 이미지 할당
    pineappleBox.setPosition(960, 620);  //파인애플 박스 위치 설정

    Texture pineappleTexture;  //파인애플
    pineappleTexture.loadFromFile("image/Pineapple.png");  //파인애플 이미지

    Texture stickBoxTexture;  //꼬치 박스
    stickBoxTexture.loadFromFile("image/Stick_box.png");  //꼬치 박스 이미지
    Sprite stickBox(stickBoxTexture);  //꼬치 박스 이미지 할당
    stickBox.setPosition(1190, 610);  //꼬치 박스 위치 설정

    Texture stickTexture;  //꼬치
    stickTexture.loadFromFile("image/Stick.png");  //꼬치 이미지

    bool isFruitGrabbed = false;  //과일을 집었는가 안집었는가
    std::vector<Fruit> fruits;  //과일 벡터

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
        }
        Vector2i mousePosition = Mouse::getPosition(window);
        //클릭했을 때
        if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {

            //커서가 과일 박스 위에 있다면 그 과일을 잡음
            if (blackGrapeBox.getGlobalBounds().contains(static_cast<Vector2f>(mousePosition))) {  //블랙 사파이어 잡음
                Fruit blackGrape;  //블랙 사파이어 객체 생성
                blackGrape.sprite.setTexture(blackGrapeTexture);  //블랙 사파이어 이미지 할당
                blackGrape.sprite.setPosition(static_cast<Vector2f>(mousePosition));  //블랙 사파이어 위치 설정
                fruits.push_back(blackGrape);  //벡터에 추가
            }
            if (strawberryBox.getGlobalBounds().contains(static_cast<Vector2f>(mousePosition))) {  //딸기 잡음
                Fruit strawberry;  //딸기 객체 생성
                strawberry.sprite.setTexture(strawberryTexture);  //딸기 이미지 할당
                strawberry.sprite.setPosition(static_cast<Vector2f>(mousePosition));  //딸기 위치 설정
                fruits.push_back(strawberry);  //벡터에 추가
            }
            if (shineMuscatBox.getGlobalBounds().contains(static_cast<Vector2f>(mousePosition))) {  //샤인머스켓 잡음
                Fruit shineMuscat;  //샤인머스켓 객체 생성
                shineMuscat.sprite.setTexture(shineMuscatTexture);  //샤인머스켓 이미지 할당
                shineMuscat.sprite.setPosition(static_cast<Vector2f>(mousePosition));  //샤인머스켓 위치 설정
                fruits.push_back(shineMuscat);  //벡터에 추가
            }
            if (mandarinBox.getGlobalBounds().contains(static_cast<Vector2f>(mousePosition))) {  //귤 잡음
                Fruit mandarin;  //귤 객체 생성
                mandarin.sprite.setTexture(mandarinTexture);  //귤 이미지 할당
                mandarin.sprite.setPosition(static_cast<Vector2f>(mousePosition));  //귤 위치 설정
                fruits.push_back(mandarin);  //벡터에 추가
            }
            if (pineappleBox.getGlobalBounds().contains(static_cast<Vector2f>(mousePosition))) {  //파인애플 잡음
                Fruit pineapple;  //파인애플 객체 생성
                pineapple.sprite.setTexture(pineappleTexture);  //파인애플 이미지 할당
                pineapple.sprite.setPosition(static_cast<Vector2f>(mousePosition));  //파인애플 위치 설정
                fruits.push_back(pineapple);  //벡터에 추가
            }
            if (stickBox.getGlobalBounds().contains(static_cast<Vector2f>(mousePosition))) {  //꼬치 잡음
                Fruit stick;  //꼬치 객체 생성
                stick.isStick = true;  //꼬치임
                stick.sprite.setTexture(stickTexture);  //꼬치 이미지 할당
                stick.sprite.setPosition(static_cast<Vector2f>(mousePosition));  //꼬치 위치 설정
                fruits.push_back(stick);  //벡터에 추가
            }
        }

        // 마우스 뗐을 때
        if (event.type == Event::MouseButtonReleased && event.mouseButton.button == Mouse::Left) {
            Sprite stick;  //스틱
            for (Fruit& fruit : fruits) {  //과일
                fruit.grabbed = false;
                if (fruit.isStick) {  //스틱인지 확인
                    stick = fruit.sprite;  //fruits 벡터에 있는 스틱을 변수에 저장해줌
                }
                if (!stick.getGlobalBounds().intersects(fruit.sprite.getGlobalBounds())) {  //과일을 스틱 위에 안 놓았다면
                    fruits.pop_back();  //객체에서 삭제
                }
            }
        }

        // 마우스 이동 중
        if (event.type == Event::MouseMoved) {
            //드래그하면 과일을 마우스 위치로 이동
            Vector2i mousePosition = Mouse::getPosition(window);
            for (Fruit& fruit : fruits) {  //과일
                if (fruit.grabbed) {
                    fruit.sprite.setPosition(static_cast<Vector2f>(mousePosition));
                }
            }
        }

        window.clear();
        //↓ 갈수록 레이어가 위임
        window.draw(frameSprite);  //게임화면 draw
        window.draw(speechBubbleSprite);  //말풍선 draw
        window.draw(blackGrapeBox);  //블랙 사파이어 박스 draw
        window.draw(strawberryBox);  //딸기 박스 draw
        window.draw(shineMuscatBox);  //샤인머스켓 박스 draw
        window.draw(mandarinBox);  //귤 박스 draw
        window.draw(pineappleBox);  //파인애플 박스 draw
        window.draw(stickBox);  //꼬치 박스 draw
        for (const Fruit& fruit : fruits) { //과일 draw
            window.draw(fruit.sprite);
        }
        window.display();

    }

}