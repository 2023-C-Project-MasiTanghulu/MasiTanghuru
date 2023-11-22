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
    bool isCoated = false;  //������ �����ߴ°�
    string name;  //���� �̸�

    //������
    Fruit(string fruitName) : name(fruitName) {
        grabbed = true;
        coatedTexture.loadFromFile("image/Coating_" + name + ".png");
    }

    //���� ���� �̹����� �ٲ���
    void sugarCoating() {
        if (!isCoated) {
            sprite.setTexture(coatedTexture);  //���õ� �̹����� ����
            isCoated = true;
        }
    }
};