#pragma once
#include<SFML/Graphics.hpp>
#include<string>

using namespace sf;
using namespace std;

//���� Ŭ����
class Fruit {
public:
    Sprite sprite;  // ���� �̹���
    bool grabbed;   // ������ ��Ҵ°�
    bool isStick = false;  //��ġ�ΰ�
    bool isCoating = false;  //������ �����ߴ°�
    bool isLadle = false;  //�����ΰ�
    string name;  //���� �̸�
    //������
    Fruit(String fruitName) : name(fruitName) {
        grabbed = true;
    }
};