#pragma once
#include<SFML/Graphics.hpp>
#include<string>

using namespace sf;
using namespace std;

//���� Ŭ����
class Fruit {
public:
    Sprite sprite;  // ���� �̹���
    Texture coatedSprite;  //���õ� ���� �̹���
    bool grabbed;   // ������ ��Ҵ°�
    bool isStick = false;  //��ġ�ΰ�
    bool isCoating = false;  //������ �����ߴ°�
    bool isLadle = false;  //�����ΰ�
    string name;  //���� �̸�

    //������
    Fruit(String fruitName) : name(fruitName) {
        grabbed = true;
    }

    //���� ���� �̹����� �ٲ���
    void sugarCoating() {
        coatedSprite.loadFromFile("image/Coating_" + name + ".png");
        sprite.setTexture(coatedSprite);
    }
};