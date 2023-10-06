#include <SFML/Graphics.hpp>

using namespace sf;

int main() {
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
    Sprite blackGrape(blackGrapeTexture);  //블랙 사파이어 이미지 할당
    blackGrape.setPosition(1600, 900);  //블랙 사파이어 위치 설정

    Texture strawberryBoxTexture;  //딸기 박스
    strawberryBoxTexture.loadFromFile("image/Strawberry_box.png");  //딸기 박스 이미지
    Sprite strawberryBox(strawberryBoxTexture);  //딸기 박스 이미지 할당
    strawberryBox.setPosition(1200, 260);  //딸기 박스 위치 설정

    Texture strawberryTexture;  //딸기
    strawberryTexture.loadFromFile("image/Strawberry.png");  //딸기 이미지
    Sprite strawberry(strawberryTexture);  //딸기 이미지 할당
    strawberry.setPosition(1600, 900);  //딸기 위치 설정

    Texture shineMuscatBoxTexture;  //샤인머스켓 박스
    shineMuscatBoxTexture.loadFromFile("image/Shinemuscat_box.png");  //샤인머스켓 박스 이미지
    Sprite shineMuscatBox(shineMuscatBoxTexture);  //샤인머스켓 박스 이미지 할당
    shineMuscatBox.setPosition(960, 440);  //샤인머스켓 박스 위치 설정

    Texture shineMuscatTexture;  //샤인머스켓
    shineMuscatTexture.loadFromFile("image/Shinemuscat.png");  //샤인머스켓 이미지
    Sprite shineMuscat(shineMuscatTexture);  //샤인머스켓 이미지 할당
    shineMuscat.setPosition(1600, 900);  //샤인머스켓 위치 설정

    Texture mandarinBoxTexture;  //귤 박스
    mandarinBoxTexture.loadFromFile("image/Mandarin_box.png");  //귤 박스 이미지
    Sprite mandarinBox(mandarinBoxTexture);  //귤 박스 이미지 할당
    mandarinBox.setPosition(1200, 440);  //귤 박스 위치 설정

    Texture mandarinTexture;  //귤
    mandarinTexture.loadFromFile("image/Mandarin.png");  //귤 이미지
    Sprite mandarin(mandarinTexture);  //귤 이미지 할당
    mandarin.setPosition(1600, 900);  //귤 위치 설정

    Texture pineappleBoxTexture;  //파인애플 박스
    pineappleBoxTexture.loadFromFile("image/Pineapple_box.png");  //파인애플 박스 이미지
    Sprite pineappleBox(pineappleBoxTexture);  //파인애플 박스 이미지 할당
    pineappleBox.setPosition(960, 620);  //파인애플 박스 위치 설정

    Texture pineappleTexture;  //파인애플
    pineappleTexture.loadFromFile("image/Pineapple.png");  //파인애플 이미지
    Sprite pineapple(pineappleTexture);  //파인애플 이미지 할당
    pineapple.setPosition(1600, 900);  //파인애플 위치 설정

    Texture stickBoxTexture;  //꼬치 박스
    stickBoxTexture.loadFromFile("image/Stick_box.png");  //꼬치 박스 이미지
    Sprite stickBox(stickBoxTexture);  //꼬치 박스 이미지 할당
    stickBox.setPosition(1190, 610);  //꼬치 박스 위치 설정

    Texture stickTexture;  //꼬치
    stickTexture.loadFromFile("image/Stick.png");  //꼬치 이미지
    Sprite stick(stickTexture);  //꼬치 이미지 할당
    stick.setPosition(1600, 900);  //꼬치 위치 설정

    bool isFruitGrabbed = false;  //과일을 집었는가 안집었는가(꼬치 포함...)
    Sprite fruit;  //과일(꼬치 포함...)

	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed)
				window.close();
		}
        // 마우스 왼쪽 버튼을 눌렀을 때
        if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
            Vector2i mousePosition = Mouse::getPosition(window);

            // 마우스 버튼이 과일 박스 위에 있다면 과일을 잡음
            if (blackGrapeBox.getGlobalBounds().contains(static_cast<Vector2f>(mousePosition))) {  //블랙 사파이어 잡음
                fruit = blackGrape;
                isFruitGrabbed = true;
            }
            if (strawberryBox.getGlobalBounds().contains(static_cast<Vector2f>(mousePosition))) {  //딸기 잡음
                fruit = strawberry;
                isFruitGrabbed = true;
            }
            if (shineMuscatBox.getGlobalBounds().contains(static_cast<Vector2f>(mousePosition))) {  //샤인머스켓 잡음
                fruit = shineMuscat;
                isFruitGrabbed = true;
            }
            if (mandarinBox.getGlobalBounds().contains(static_cast<Vector2f>(mousePosition))) {  //귤 잡음
                fruit = mandarin;
                isFruitGrabbed = true;
            }
            if (pineappleBox.getGlobalBounds().contains(static_cast<Vector2f>(mousePosition))) {  //파인애플 잡음
                fruit = pineapple;
                isFruitGrabbed = true;
            }
            if (stickBox.getGlobalBounds().contains(static_cast<Vector2f>(mousePosition))) {  //꼬치 잡음
                fruit = stick;
                isFruitGrabbed = true;
            }

        }

        // 마우스 왼쪽 버튼을 놓았을 때
        if (event.type == Event::MouseButtonReleased && event.mouseButton.button == Mouse::Left) {
            isFruitGrabbed = false;
        }
        
        // 마우스 이동 중
        if (event.type == Event::MouseMoved) {
            if (isFruitGrabbed) {
                // 마우스 버튼이 눌린 상태에서 마우스를 움직이면 과일을 마우스 위치로 이동
                Vector2i mousePosition = Mouse::getPosition(window);
                fruit.setPosition(static_cast<Vector2f>(mousePosition));
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
        window.draw(fruit);  //과일 draw
		window.display();
	}
}