#include <iostream>
#include <time.h>
#include <thread>
#include "game.h"
#include "fruit.h"

using namespace std;

void Game::run(RenderWindow& window) {
    window.create(VideoMode(1500, 800), "탕후루 만들기");

    //탕후루 게임
    Texture frame;  //게임 화면
    frame.loadFromFile("image/Game_frame.png");  //게임 화면 이미지
    Sprite frameSprite(frame);  //게임 화면 이미지 할당

    Texture cuttingBoard;  //도마
    cuttingBoard.loadFromFile("image/CuttingBoard.png");  //도마 이미지
    Sprite cuttingBoardSprite(cuttingBoard);  //도마 이미지 할당
    cuttingBoardSprite.setPosition(20,310);  //도마 위치 설정

    Texture speechBubble;  //말풍선
    speechBubble.loadFromFile("image/speechBubble.png");  //말풍선 이미지
    Sprite speechBubbleSprite(speechBubble);  //말풍선 이미지 할당
    speechBubbleSprite.setPosition(0, 0);  //말풍선 위치 설정

    // 3초 후에 말풍선을 숨기는 함수
    auto clearSpeechBubble = [&speechBubbleSprite]() {
        this_thread::sleep_for(chrono::seconds(3));
        speechBubbleSprite.setPosition(-1000, -1000); // 화면 밖으로 이동시켜 보이지 않게 함
    };

    // 3초 뒤에 말풍선을 숨김
    thread(clearSpeechBubble).detach();  // 새 스레드에서 실행


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

    Texture shineMusketBoxTexture;  //샤인머스켓 박스
    shineMusketBoxTexture.loadFromFile("image/Shinemusket_box.png");  //샤인머스켓 박스 이미지
    Sprite shineMusketBox(shineMusketBoxTexture);  //샤인머스켓 박스 이미지 할당
    shineMusketBox.setPosition(960, 440);  //샤인머스켓 박스 위치 설정

    Texture shineMusketTexture;  //샤인머스켓
    shineMusketTexture.loadFromFile("image/Shinemusket.png");  //샤인머스켓 이미지

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
    bool isClicked = false;  //마우스 클릭을 했는가 안했는가
    vector<Fruit> fruits;  //과일 벡터

    //제한시간 : 초 설정
    Clock clock;
    const Time timeLimit = seconds(60); // 60초로 설정

    //폰트 설정
    Font font;
    if (!font.loadFromFile("font/NanumGothic.ttf")) {
        // 폰트를 로드하지 못한 경우 예외처리
        cout << "폰트를 로드할 수 없습니다." << endl;
    }

    // 제한 시간 : 화면에 표시할 텍스트 설정
    Text timerText;
    timerText.setFont(font); // 폰트 설정 (sfml은 무조건 폰트를 사용해야함. )
    timerText.setCharacterSize(50); // 글꼴 크기 설정
    timerText.setFillColor(Color::Black); // 글꼴 색상을 검정색으로 설정
    timerText.setStyle(Text::Bold); // 글꼴 스타일 설정
    timerText.setPosition(1250,35 ); // 텍스트 위치 설정

    //말풍선 말: 손님 주문
    Text bubbleText;
    bubbleText.setFont(font);
    bubbleText.setCharacterSize(50);
    bubbleText.setFillColor(Color::Black);
    bubbleText.setStyle(Text::Bold);
    bubbleText.setPosition(100,50 ); // 텍스트 위치 설정
    bubbleText.setString(L"딸기 탕후루 주세요."); // 내용 설정

    // 3초 후에 말풍선 내용을 지우는 함수
    auto clearBubbleText = [&bubbleText]() {
        std::this_thread::sleep_for(std::chrono::seconds(3));
        bubbleText.setString(L"");
    };

    // 3초 뒤에 말풍선 내용 지움
    thread(clearBubbleText).detach();

    Texture Sale_btn_texture;
    Sale_btn_texture.loadFromFile("image/Sale_btn.png"); // 버튼 이미지 불러오기
    Sprite Sale_btn_sprite(Sale_btn_texture);
    Sale_btn_sprite.setPosition(50, 50); // 버튼 위치 설정

    bool Sale_btnVisible = false; // Sale 버튼을 처음에는 숨겨놓기

    // 3초 뒤에 Sale 버튼을 보이도록 하는 함수
    auto AfterSale_btn = [&]() {
        std::this_thread::sleep_for(std::chrono::seconds(3));
        Sale_btnVisible = true;
    };

   thread(AfterSale_btn).detach(); // 새 스레드에서 실행



    // 과일 주문 목록
    vector<wstring> orders = {
        L"딸기 탕후루 주세요.",
        L"샤인머스켓 탕후루 주세요.",
        L"파인애플 탕후루 주세요.",
        L"블랙 사파이어 포도 탕후루 주세요.",
        L"통귤 탕후루 주세요.",
        L"딸기, 샤인머스캣 탕후루 주세요.",
        L"딸기, 파인애플 탕후루 주세요.",
        L"딸기, 블랙 사파이어 포도 탕후루 주세요.",
        L"딸기, 통귤 탕후루 주세요.",
        L"샤인머스캣, 파인애플 탕후루 주세요.",
        L"샤인머스캣, 블랙 사파이어 포도 탕후루 주세요.",
        L"샤인머스캣, 통귤 탕후루 주세요.",
        L"파인애플, 블랙 사파이어 탕후루 주세요."
    };


    //말풍선 내용 랜덤으로 설정
    int randomIndex = rand() % orders.size(); // 랜덤한 인덱스 생성
    bubbleText.setString(orders[randomIndex]);



    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
        }
        Vector2i mousePosition = Mouse::getPosition(window);

        //클릭했을 때
        if (!isClicked && event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
            isClicked = true;  //클릭함

            //커서가 과일 박스 위에 있다면 그 과일을 잡음
            if (blackGrapeBox.getGlobalBounds().contains(static_cast<Vector2f>(mousePosition))) {  //블랙 사파이어 잡음
                Fruit blackGrape("blackGrape");  //블랙 사파이어 객체 생성
                blackGrape.sprite.setTexture(blackGrapeTexture);  //블랙 사파이어 이미지 할당
                blackGrape.sprite.setPosition(1200, 1000);  //블랙 사파이어 위치 설정
                fruits.push_back(blackGrape);  //벡터에 추가
            }
            else if (strawberryBox.getGlobalBounds().contains(static_cast<Vector2f>(mousePosition))) {  //딸기 잡음
                Fruit strawberry("strawberry");  //딸기 객체 생성
                strawberry.sprite.setTexture(strawberryTexture);  //딸기 이미지 할당
                strawberry.sprite.setPosition(1200, 1000);  //딸기 위치 설정
                fruits.push_back(strawberry);  //벡터에 추가
            }
            else if (shineMusketBox.getGlobalBounds().contains(static_cast<Vector2f>(mousePosition))) {  //샤인머스켓 잡음
                Fruit shineMusket("shineMusket");  //샤인머스켓 객체 생성
                shineMusket.sprite.setTexture(shineMusketTexture);  //샤인머스켓 이미지 할당
                shineMusket.sprite.setPosition(1200, 1000);  //샤인머스켓 위치 설정
                fruits.push_back(shineMusket);  //벡터에 추가
            }
            else if (mandarinBox.getGlobalBounds().contains(static_cast<Vector2f>(mousePosition))) {  //귤 잡음
                Fruit mandarin("mandarin");  //귤 객체 생성
                mandarin.sprite.setTexture(mandarinTexture);  //귤 이미지 할당
                mandarin.sprite.setPosition(1200, 1000);  //귤 위치 설정
                fruits.push_back(mandarin);  //벡터에 추가
            }
            else if (pineappleBox.getGlobalBounds().contains(static_cast<Vector2f>(mousePosition))) {  //파인애플 잡음
                Fruit pineapple("pineapple");  //파인애플 객체 생성
                pineapple.sprite.setTexture(pineappleTexture);  //파인애플 이미지 할당
                pineapple.sprite.setPosition(1200, 1000);  //파인애플 위치 설정
                fruits.push_back(pineapple);  //벡터에 추가
            }
            else if (stickBox.getGlobalBounds().contains(static_cast<Vector2f>(mousePosition)) && fruits.empty()) {  //fruits 벡터가 비었으면 꼬치 잡음
                Fruit stick("stick");  //꼬치 객체 생성
                stick.isStick = true;  //꼬치임
                stick.sprite.setTexture(stickTexture);  //꼬치 이미지 할당
                stick.sprite.setPosition(1200,1000);  //꼬치 위치 설정
                fruits.push_back(stick);  //벡터에 추가
            }
        }
        int positionX = 200;  //과일 x 위치 설정
        int positionY = 570;  //과일 y 위치 설정

        // 마우스 뗐을 때
        if (event.type == Event::MouseButtonReleased && event.mouseButton.button == Mouse::Left) {
            Sprite stick;  //꼬치
            isClicked = false;  //클릭 안함

            for (Fruit& fruit : fruits) {  //과일
                fruit.grabbed = false;
                if (fruit.isStick) {  //꼬치면
                    stick = fruit.sprite;  //fruits 벡터에 있는 스틱을 변수에 저장해줌
                }
                //과일을 꼬치 위에 안 놓거나 도마 위에 재료를 안 놓았다면
                if (!stick.getGlobalBounds().intersects(fruit.sprite.getGlobalBounds()) || !cuttingBoardSprite.getGlobalBounds().intersects(fruit.sprite.getGlobalBounds())) {
                    fruits.pop_back();  //객체에서 삭제
                }
                if(!fruit.isStick){  //꼬치가 아니라 과일이면
                    fruit.sprite.setPosition(positionX, positionY-fruit.sprite.getGlobalBounds().height/2);  //과일 위치 자동으로 설정
                    positionX += fruit.sprite.getGlobalBounds().width;  //가로 길이 누적
                }
                else {  //꼬치면
                    fruit.sprite.setPosition(40, 570);  //꼬치 위치 자동으로 설정
                }
            }
        }

        // 마우스 이동 중
        if (event.type == Event::MouseMoved) {
            //드래그하면 과일을 마우스 위치로 이동
            Vector2i mousePosition = Mouse::getPosition(window);
            for (Fruit& fruit : fruits) {  //과일
                if (fruit.grabbed) {
                    // 마우스 위치를 이미지의 중심으로 조정
                    Vector2f centerPosition(static_cast<float>(mousePosition.x - fruit.sprite.getLocalBounds().width / 2), static_cast<float>(mousePosition.y - fruit.sprite.getLocalBounds().height / 2));
                    fruit.sprite.setPosition(centerPosition);
                }
            }
        }
        //탕후루 게임 끝

        //제한시간 : 시간 지나는 코드
        Time elapsed = clock.getElapsedTime();
        if (elapsed >= timeLimit) {
            cout << "시간 초과!" << endl;
            //window.close();
        }
        //제한시간 : 시간 지나는 코드 끝

       // 시간을 문자열로 변환하여 텍스트에 설정
        int remainingTime = timeLimit.asSeconds() - elapsed.asSeconds();
        timerText.setString(to_string(remainingTime));
        

        window.clear();
        //↓ 갈수록 레이어가 위임
        window.draw(cuttingBoardSprite);  //도마 draw
        window.draw(frameSprite);  //게임화면 draw
        window.draw(speechBubbleSprite);  //말풍선 draw
        window.draw(blackGrapeBox);  //블랙 사파이어 박스 draw
        window.draw(strawberryBox);  //딸기 박스 draw
        window.draw(shineMusketBox);  //샤인머스켓 박스 draw
        window.draw(mandarinBox);  //귤 박스 draw
        window.draw(pineappleBox);  //파인애플 박스 draw
        window.draw(stickBox);  //꼬치 박스 draw
        for (const Fruit& fruit : fruits) { //과일 draw
            window.draw(fruit.sprite);
        }
        if (Sale_btnVisible) {
            window.draw(Sale_btn_sprite);
        }

        window.draw(timerText); // 제한 시간 표시
        window.draw(bubbleText);//말풍선 말
        window.display();

    }

}