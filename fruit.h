#pragma once
#include<SFML/Graphics.hpp>
#include<string>

using namespace sf;
using namespace std;

//과일 클래스
class Fruit {
public:
    Sprite sprite;  // 과일 이미지
    bool grabbed;   // 과일을 잡았는가
    bool isStick = false;  //꼬치인가
    bool isCoating = false;  //설탕물 코팅했는가
    bool isLadle = false;  //국자인가
    string name;  //과일 이름
    //생성자
    Fruit(String fruitName) : name(fruitName) {
        grabbed = true;
    }
};