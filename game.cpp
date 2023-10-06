#include <SFML/Graphics.hpp>

using namespace sf;

int main() {
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
    Sprite blackGrape(blackGrapeTexture);  //�� �����̾� �̹��� �Ҵ�
    blackGrape.setPosition(1600, 900);  //�� �����̾� ��ġ ����

    Texture strawberryBoxTexture;  //���� �ڽ�
    strawberryBoxTexture.loadFromFile("image/Strawberry_box.png");  //���� �ڽ� �̹���
    Sprite strawberryBox(strawberryBoxTexture);  //���� �ڽ� �̹��� �Ҵ�
    strawberryBox.setPosition(1200, 260);  //���� �ڽ� ��ġ ����

    Texture strawberryTexture;  //����
    strawberryTexture.loadFromFile("image/Strawberry.png");  //���� �̹���
    Sprite strawberry(strawberryTexture);  //���� �̹��� �Ҵ�
    strawberry.setPosition(1600, 900);  //���� ��ġ ����

    Texture shineMuscatBoxTexture;  //���θӽ��� �ڽ�
    shineMuscatBoxTexture.loadFromFile("image/Shinemuscat_box.png");  //���θӽ��� �ڽ� �̹���
    Sprite shineMuscatBox(shineMuscatBoxTexture);  //���θӽ��� �ڽ� �̹��� �Ҵ�
    shineMuscatBox.setPosition(960, 440);  //���θӽ��� �ڽ� ��ġ ����

    Texture shineMuscatTexture;  //���θӽ���
    shineMuscatTexture.loadFromFile("image/Shinemuscat.png");  //���θӽ��� �̹���
    Sprite shineMuscat(shineMuscatTexture);  //���θӽ��� �̹��� �Ҵ�
    shineMuscat.setPosition(1600, 900);  //���θӽ��� ��ġ ����

    Texture mandarinBoxTexture;  //�� �ڽ�
    mandarinBoxTexture.loadFromFile("image/Mandarin_box.png");  //�� �ڽ� �̹���
    Sprite mandarinBox(mandarinBoxTexture);  //�� �ڽ� �̹��� �Ҵ�
    mandarinBox.setPosition(1200, 440);  //�� �ڽ� ��ġ ����

    Texture mandarinTexture;  //��
    mandarinTexture.loadFromFile("image/Mandarin.png");  //�� �̹���
    Sprite mandarin(mandarinTexture);  //�� �̹��� �Ҵ�
    mandarin.setPosition(1600, 900);  //�� ��ġ ����

    Texture pineappleBoxTexture;  //���ξ��� �ڽ�
    pineappleBoxTexture.loadFromFile("image/Pineapple_box.png");  //���ξ��� �ڽ� �̹���
    Sprite pineappleBox(pineappleBoxTexture);  //���ξ��� �ڽ� �̹��� �Ҵ�
    pineappleBox.setPosition(960, 620);  //���ξ��� �ڽ� ��ġ ����

    Texture pineappleTexture;  //���ξ���
    pineappleTexture.loadFromFile("image/Pineapple.png");  //���ξ��� �̹���
    Sprite pineapple(pineappleTexture);  //���ξ��� �̹��� �Ҵ�
    pineapple.setPosition(1600, 900);  //���ξ��� ��ġ ����

    Texture stickBoxTexture;  //��ġ �ڽ�
    stickBoxTexture.loadFromFile("image/Stick_box.png");  //��ġ �ڽ� �̹���
    Sprite stickBox(stickBoxTexture);  //��ġ �ڽ� �̹��� �Ҵ�
    stickBox.setPosition(1190, 610);  //��ġ �ڽ� ��ġ ����

    Texture stickTexture;  //��ġ
    stickTexture.loadFromFile("image/Stick.png");  //��ġ �̹���
    Sprite stick(stickTexture);  //��ġ �̹��� �Ҵ�
    stick.setPosition(1600, 900);  //��ġ ��ġ ����

    bool isFruitGrabbed = false;  //������ �����°� �������°�(��ġ ����...)
    Sprite fruit;  //����(��ġ ����...)

	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed)
				window.close();
		}
        // ���콺 ���� ��ư�� ������ ��
        if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
            Vector2i mousePosition = Mouse::getPosition(window);

            // ���콺 ��ư�� ���� �ڽ� ���� �ִٸ� ������ ����
            if (blackGrapeBox.getGlobalBounds().contains(static_cast<Vector2f>(mousePosition))) {  //�� �����̾� ����
                fruit = blackGrape;
                isFruitGrabbed = true;
            }
            if (strawberryBox.getGlobalBounds().contains(static_cast<Vector2f>(mousePosition))) {  //���� ����
                fruit = strawberry;
                isFruitGrabbed = true;
            }
            if (shineMuscatBox.getGlobalBounds().contains(static_cast<Vector2f>(mousePosition))) {  //���θӽ��� ����
                fruit = shineMuscat;
                isFruitGrabbed = true;
            }
            if (mandarinBox.getGlobalBounds().contains(static_cast<Vector2f>(mousePosition))) {  //�� ����
                fruit = mandarin;
                isFruitGrabbed = true;
            }
            if (pineappleBox.getGlobalBounds().contains(static_cast<Vector2f>(mousePosition))) {  //���ξ��� ����
                fruit = pineapple;
                isFruitGrabbed = true;
            }
            if (stickBox.getGlobalBounds().contains(static_cast<Vector2f>(mousePosition))) {  //��ġ ����
                fruit = stick;
                isFruitGrabbed = true;
            }

        }

        // ���콺 ���� ��ư�� ������ ��
        if (event.type == Event::MouseButtonReleased && event.mouseButton.button == Mouse::Left) {
            isFruitGrabbed = false;
        }
        
        // ���콺 �̵� ��
        if (event.type == Event::MouseMoved) {
            if (isFruitGrabbed) {
                // ���콺 ��ư�� ���� ���¿��� ���콺�� �����̸� ������ ���콺 ��ġ�� �̵�
                Vector2i mousePosition = Mouse::getPosition(window);
                fruit.setPosition(static_cast<Vector2f>(mousePosition));
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
        window.draw(fruit);  //���� draw
		window.display();
	}
}