#include <SFML/Graphics.hpp>

using namespace sf;

void gamerule() {
    RenderWindow window(VideoMode(1500, 800), "탕후루 만들기");

    Texture frame;  // 게임 화면
    if (!frame.loadFromFile("image/Rule_frame.png")) {
        
    }
    Sprite frameSprite(frame);  // 게임 화면 이미지 할당

    Texture buttonTexture;
    if (!buttonTexture.loadFromFile("image/Back_btn.png")) {
        
    }
    Sprite backButton(buttonTexture);
    backButton.setPosition(1100, 650);

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();

            if (event.type == Event::MouseButtonPressed) {
                if (event.mouseButton.button == Mouse::Left) {
                    Vector2i mousePos = Mouse::getPosition(window);

                    if (backButton.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                        printf("돌아가기 버튼 클릭\n");
                    }
                }
            }
        }

        window.clear();
        window.draw(frameSprite);
        window.draw(backButton);
        window.display();
    }


}
