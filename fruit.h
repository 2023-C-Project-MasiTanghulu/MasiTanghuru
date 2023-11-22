#pragma once
#include<SFML/Graphics.hpp>
#include<string>

using namespace sf;
using namespace std;

//과일 클래스
class Fruit {
public:
    Sprite sprite;  // 과일 이미지
    Texture coatedTexture;  //코팅된 과일 이미지
    bool grabbed;   // 과일을 잡았는가
    bool isCoated = false;  //설탕물 코팅했는가
    string name;  //과일 이름

    //생성자
    Fruit(string fruitName) : name(fruitName) {
        grabbed = true;
        coatedTexture.loadFromFile("image/Coating_" + name + ".png");
    }

    //설탕 코팅 이미지로 바꿔줌
    void sugarCoating() {
        if (!isCoated) {
            sprite.setTexture(coatedTexture);  //코팅된 이미지로 변경
            isCoated = true;
        }
    }
};