#pragma once
#include<SFML/Graphics.hpp>
#include<string>

using namespace sf;
using namespace std;

//���� Ŭ����
class Fruit {
public:
    Sprite sprite;  // ���� �̹���
    Texture coatedTexture;  //���õ� ���� �̹���
    bool grabbed;   // ������ ��Ҵ°�
    bool isCoating = false;  //������ �����ߴ°�
    string name;  //���� �̸�

    //������
    Fruit(String fruitName) : name(fruitName) {
        grabbed = true;
    }

    //���� ���� �̹����� �ٲ���
    void sugarCoating() {
        coatedTexture.loadFromFile("image/Coating_" + name + ".png");
        sprite.setTexture(coatedTexture);
    }
};