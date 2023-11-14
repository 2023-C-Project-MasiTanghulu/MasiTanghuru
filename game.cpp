#include <iostream>
#include <time.h>
#include <thread>
#include <random>
#include <sstream>
#include "game.h"
#include "fruit.h"

using namespace std;

wstring convertToFruitName(const string& englishName) {
	if (englishName == "strawberry") {
		return L"딸기";
	}
	else if (englishName == "shinemusket") {
		return L"샤인머스켓";
	}
	else if (englishName == "pineapple") {
		return L"파인애플";
	}
	else if (englishName == "black grape") {
		return L"블랙 사파이어 포도";
	}
	else if (englishName == "mandarin") {
		return L"통귤";
	}
};


void Game::run(RenderWindow& window) {
	window.create(VideoMode(1500, 800), L"탕후루 만들기");

	//탕후루 게임
	Texture frame;  //게임 화면
	frame.loadFromFile("image/Game_frame.png");  //게임 화면 이미지
	Sprite frameSprite(frame);  //게임 화면 이미지 할당

	Texture cuttingBoard;  //도마
	cuttingBoard.loadFromFile("image/CuttingBoard.png");  //도마 이미지
	Sprite cuttingBoardSprite(cuttingBoard);  //도마 이미지 할당
	cuttingBoardSprite.setPosition(20, 310);  //도마 위치 설정

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


	Texture boxildTexture; //박스 뚜껑
	boxildTexture.loadFromFile("image/boxlid.png");

	Texture blackGrapeBoxTexture;  //블랙 사파이어 박스
	blackGrapeBoxTexture.loadFromFile("image/BlackGrape_box.png");  //블랙 사파이어 박스 이미지
	Sprite blackGrapeBox(boxildTexture);  //블랙 사파이어 박스 이미지 할당
	blackGrapeBox.setPosition(960, 260);  //블랙 사파이어 박스 위치 설정

	Texture blackGrapeTexture;  //블랙 사파이어
	blackGrapeTexture.loadFromFile("image/BlackGrape.png");  //블랙 사파이어 이미지

	Texture strawberryBoxTexture;  //딸기 박스
	strawberryBoxTexture.loadFromFile("image/Strawberry_box.png");  //딸기 박스 이미지
	Sprite strawberryBox(boxildTexture);  //딸기 박스 이미지 할당
	strawberryBox.setPosition(1200, 260);  //딸기 박스 위치 설정

	Texture strawberryTexture;  //딸기
	strawberryTexture.loadFromFile("image/Strawberry.png");  //딸기 이미지

	Texture shineMusketBoxTexture;  //샤인머스켓 박스
	shineMusketBoxTexture.loadFromFile("image/Shinemusket_box.png");  //샤인머스켓 박스 이미지
	Sprite shineMusketBox(boxildTexture);  //샤인머스켓 박스 이미지 할당
	shineMusketBox.setPosition(960, 440);  //샤인머스켓 박스 위치 설정

	Texture shineMusketTexture;  //샤인머스켓
	shineMusketTexture.loadFromFile("image/Shinemusket.png");  //샤인머스켓 이미지

	Texture mandarinBoxTexture;  //귤 박스
	mandarinBoxTexture.loadFromFile("image/Mandarin_box.png");  //귤 박스 이미지
	Sprite mandarinBox(boxildTexture);  //귤 박스 이미지 할당
	mandarinBox.setPosition(1200, 440);  //귤 박스 위치 설정

	Texture mandarinTexture;  //귤
	mandarinTexture.loadFromFile("image/Mandarin.png");  //귤 이미지

	Texture pineappleBoxTexture;  //파인애플 박스
	pineappleBoxTexture.loadFromFile("image/Pineapple_box.png");  //파인애플 박스 이미지
	Sprite pineappleBox(boxildTexture);  //파인애플 박스 이미지 할당
	pineappleBox.setPosition(960, 620);  //파인애플 박스 위치 설정

	Texture pineappleTexture;  //파인애플
	pineappleTexture.loadFromFile("image/Pineapple.png");  //파인애플 이미지

	Texture stickBoxTexture;  //꼬치 박스
	stickBoxTexture.loadFromFile("image/Stick_box.png");  //꼬치 박스 이미지
	Sprite stickBox(stickBoxTexture);  //꼬치 박스 이미지 할당
	stickBox.setPosition(1190, 610);  //꼬치 박스 위치 설정

	Texture stickTexture;  //꼬치
	stickTexture.loadFromFile("image/Stick.png");  //꼬치 이미지
	Sprite stick(stickTexture);  //꼬치 이미지 할당
	stick.setPosition(1200, 1000);  //꼬치 위치 설정

	Texture sugarPotTexture;  //설탕물 냄비
	sugarPotTexture.loadFromFile("image/SugarPot.png");  //설탕물 냄비 이미지
	Sprite sugarPot(sugarPotTexture);  //설탕물 냄비 이미지 할당
	sugarPot.setPosition(620, 345);  //설탕물 냄비 위치 설정

	Texture ladleTexture;  //국자
	ladleTexture.loadFromFile("image/Ladle.png");  //국자 이미지
	Sprite ladleSprite(ladleTexture);  //국자 이미지 할당
	ladleSprite.rotate(90);  //국자 각도 설정
	ladleSprite.setPosition(710, 250);  //국자 위치 설정

	Texture sugarLadleTexture;  //설탕물 국자
	sugarLadleTexture.loadFromFile("image/SugarLadle.png");  //설탕물 국자 이미지
	Sprite sugarLadle(sugarLadleTexture);  //설탕물 국자 이미지 할당

	Texture wastebasketTexture;  //쓰레기통
	wastebasketTexture.loadFromFile("image/Wastebasket.png");  //쓰레기통 이미지
	Sprite wastebasket(wastebasketTexture);  //쓰레기통 이미지 할당
	wastebasket.setPosition(20, 230);

	//실패이미지
	Texture failTexture;  //실패
	failTexture.loadFromFile("image/fail.png");  //실패 이미지
	Sprite failSprite(failTexture);  //실패 이미지 할당
	failSprite.setPosition(0, 3);//실패 이미지 위치 설정

	//성공이미지
	Texture perfectTexture;  //성공
	perfectTexture.loadFromFile("image/perfect.png");  //실패 이미지
	Sprite perfectSprite(perfectTexture);  //성공 이미지 할당
	perfectSprite.setPosition(0, 3);//성공 이미지 위치 설정

	bool isFruitGrabbed = false;  //과일을 집었는가 안집었는가
	bool isClicked = false;  //마우스 클릭을 했는가 안했는가
	bool isLadleGrabbed = false;  //국자를 집었는가 안집었는가
	bool isSugarLadle = false;  //설탕물 국자인가 아닌가
	bool isStickGrabbed = false;  //꼬치를 집었는가 안집었는가
	bool isMix = false;  //과일 2종류의 탕후루인가
	bool showingFail = false;
	bool showingPerfect = false;

	int size = 0;  //꽂을 과일 갯수 정하는 변수
	int startPosition = 650;  //과일 꽂기 시작 위치
	vector<Fruit> fruits;  //과일 벡터


	//폰트 설정
	Font font;
	font.loadFromFile("font/NanumGothic.ttf");

	// 제한 시간 : 화면에 표시할 텍스트 설정
	Text timerText;
	timerText.setFont(font); // 폰트 설정 (sfml은 무조건 폰트를 사용해야함. )
	timerText.setCharacterSize(50); // 글꼴 크기 설정
	timerText.setFillColor(Color::Black); // 글꼴 색상을 검정색으로 설정
	timerText.setStyle(Text::Bold); // 글꼴 스타일 설정
	timerText.setPosition(1250, 35); // 텍스트 위치 설정

	//제한시간 : 초 설정
	Clock clock;
	const Time timeLimit = seconds(60); // 60초로 설정

	//판매하기 : 텍스트 설정
	Text saleText;  // 텍스트 객체 생성
	saleText.setFont(font);  // 폰트 설정
	saleText.setCharacterSize(50);  // 글자 크기 설정
	saleText.setFillColor(Color::Black);  // 글자 색상 설정
	saleText.setStyle(Text::Bold);
	saleText.setPosition(1230, 105);  // 위치 설정

	//레벨 표시  : 텍스트 설정
	Text levelText;  // 텍스트 객체 생성
	levelText.setFont(font);  // 폰트 설정
	levelText.setCharacterSize(50);  // 글자 크기 설정
	levelText.setFillColor(Color::Black);  // 글자 색상 설정
	levelText.setStyle(Text::Bold);
	levelText.setPosition(1250, 170);  // 위치 설정

	//말풍선 말: 손님 주문
	Text bubbleText;
	bubbleText.setFont(font);
	bubbleText.setCharacterSize(50);
	bubbleText.setFillColor(Color::Black);
	bubbleText.setStyle(Text::Bold);
	bubbleText.setPosition(50, 50); // 텍스트 위치 설정

	// 3초 후에 말풍선 내용을 지우는 함수
	auto clearBubbleText = [&bubbleText]() {
		this_thread::sleep_for(chrono::seconds(3));
		bubbleText.setString(L"");
	};

	// 3초 뒤에 말풍선 내용 지움
	thread(clearBubbleText).detach();

	// 판매하기 버튼
	Texture Sale_btn_texture;
	Sale_btn_texture.loadFromFile("image/Sale_btn.png"); // 버튼 이미지 불러오기
	Sprite Sale_btn_sprite(Sale_btn_texture);
	Sale_btn_sprite.setPosition(50, 50); // 버튼 위치 설정

	bool Sale_btnVisible = false; // Sale 버튼을 처음에는 숨겨놓기

	// 3초 뒤에 Sale 버튼을 보이도록 하는 함수
	auto AfterSale_btn = [&]() {
		this_thread::sleep_for(chrono::seconds(3));
		Sale_btnVisible = true;
	};

	thread(AfterSale_btn).detach(); // 새 스레드에서 실행


	// 과일 주문 목록
	vector<vector<string>> levelFruits = {
			   { "shinemusket","strawberry"},                  // Level 1
			   {"strawberry", "shinemusket", "pineapple"},     // Level 2
			   {"strawberry", "shinemusket", "pineapple", "mandarin"},  // Level 3
			   {"strawberry", "shinemusket", "pineapple", "mandarin", "black grape"}  // Level 4
	};
	
	int level = 4;
	// 현재 레벨에 해당하는 주문 목록 가져오기
	vector<string> orders = levelFruits[level - 1];

	// 주문 랜덤 돌리기
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	uniform_int_distribution<int> dist(0, orders.size() - 1);
	int randomIndex = dist(rng);


	
	
	// 주문 wstring으로 변환
	wstring order = L"";
	int numFruits = orders.size(); // 현재 레벨의 과일 개수
	// 레벨에 맞게 주문 생성
	if (numFruits > 0) {
		// 랜덤으로 선택할 과일 개수
		int numSelectedFruits = dist(rng) % 2 + 1;

		// 선택한 과일들을 저장할 벡터
		vector<string> selectedFruits;

		for (int i = 0; i < numSelectedFruits; ++i) {
			int randomFruitIndex;

			// 이미 선택된 과일이 나오지 않도록 반복해서 선택
			do {
				randomFruitIndex = dist(rng);
			} while (find(selectedFruits.begin(), selectedFruits.end(), orders[randomFruitIndex]) != selectedFruits.end());

			selectedFruits.push_back(orders[randomFruitIndex]);
		}

		// 선택한 과일들을 문자열로 합치기
		for (int i = 0; i < numSelectedFruits; ++i) {
			order += convertToFruitName(selectedFruits[i]);

			// 마지막 과일이 아니면 쉼표 추가
			if (i < numSelectedFruits - 1) {
				order += L", ";
			}
		}
	}

	bubbleText.setString(order + L" 탕후루 주세요.");

	//주문 wstring으로 변환 & 과일 시작 위치 설정 & 과일 개수 지정
	if (order == "딸기") {
		size = 4;
		startPosition -= strawberryTexture.getSize().x * size;
		isMix = false;
	}
	else if (order == "샤인머스켓") {
		size = 6;
		startPosition -= shineMusketTexture.getSize().x * size;
		isMix = false;
	}
	else if (order == "파인애플") {
		size = 5;
		startPosition -= pineappleTexture.getSize().x * size;
		isMix = false;
	}
	else if (order == "블랙 사파이어 포도") {
		size = 8;
		startPosition -= blackGrapeTexture.getSize().x * size;
		isMix = false;
	}
	else if (order == "통귤") {
		size = 4;
		startPosition -= mandarinTexture.getSize().x * size;
		isMix = false;
	}
	else if (order == "딸기,샤인머스켓") {
		size = 5;
		startPosition -= shineMusketTexture.getSize().x * 2 + strawberryTexture.getSize().x * 3;
		isMix = true;
	}
	else if (order == "딸기,파인애플") {
		size = 5;
		startPosition -= pineappleTexture.getSize().x * 2 + strawberryTexture.getSize().x * 3;
		isMix = true;
	}
	else if (order == "딸기,블랙 사파이어 포도") {
		size = 5;
		startPosition -= strawberryTexture.getSize().x * 3 + blackGrapeTexture.getSize().x * 2;
		isMix = true;
	}
	else if (order == "딸기,통귤") {
		size = 4;
		startPosition -= strawberryTexture.getSize().x * 2 + mandarinTexture.getSize().x * 2;
		isMix = true;
	}
	else if (order == "샤인머스켓,파인애플") {
		size = 6;
		startPosition -= shineMusketTexture.getSize().x * 3 + pineappleTexture.getSize().x * 3;
		isMix = true;
	}
	else if (order == "샤인머스켓,통귤") {
		size = 5;
		startPosition -= strawberryTexture.getSize().x * 2 + mandarinTexture.getSize().x * 2;
		isMix = true;
	}
	else if (order == "샤인머스켓,블랙 사파이어 포도") {
		size = 8;
		startPosition -= shineMusketTexture.getSize().x * 4 + blackGrapeTexture.getSize().x * 4;
		isMix = true;
	}
	else if (order == "파인애플,블랙 사파이어 포도") {
		size = 6;
		startPosition -= pineappleTexture.getSize().x * 3 + blackGrapeTexture.getSize().x * 3;
		isMix = true;
	}
	else if (order == "파인애플,통귤") {
		size = 4;
		startPosition -= pineappleTexture.getSize().x * 2 + mandarinTexture.getSize().x * 2;
		isMix = true;
	}
	else if (order == "블랙 사파이어 포도,통귤") {
		size = 6;
		startPosition -= blackGrapeTexture.getSize().x * 3 + mandarinTexture.getSize().x * 3;
		isMix = true;
	}

	

	//레벨업 화면
	Clock levelupClock;
	Time levelupCount = seconds(3);
	bool showingLevelup = false;

	Texture levelupTexture;  //레벨업 이미지
	levelupTexture.loadFromFile("image/Levelup_frame.png");  // 레벨업 이미지 로딩
	Sprite levelupSprite(levelupTexture);
	levelupSprite.setPosition(0, 3);  // 레벨업 이미지 위치 설정

	//성공,실패 화면
	Clock perfectClock;
	Time perfectCount = seconds(2);

	Clock failClock;
	Time failCount = seconds(2);

	//레벨
	int sale = 0;//판매액

	//판매액에 따라 레벨
	if (sale >= 20000 && sale < 60000) {
		level = 2;
	}
	else if (sale >= 60000 && sale < 100000) {
		level = 3;
	}
	else if (sale >= 100000) {
		level = 4;
	}

	switch (level) {
	case 1:
		shineMusketBox.setTexture(shineMusketBoxTexture);  //원래 샤인머스켓 박스로 바꿔줌
		strawberryBox.setTexture(strawberryBoxTexture);  //원래 딸기 박스로 바꿔줌
		break;

	case 2:
		cout << "레벨 2 달성!" << endl;
		pineappleBox.setTexture(pineappleBoxTexture);
		shineMusketBox.setTexture(shineMusketBoxTexture);
		strawberryBox.setTexture(strawberryBoxTexture);
		//showingLevelup = true;
		//levelupClock.restart();
		break;

	case 3:
		cout << "레벨 3 달성!" << endl;
		pineappleBox.setTexture(pineappleBoxTexture);
		mandarinBox.setTexture(mandarinBoxTexture);
		shineMusketBox.setTexture(shineMusketBoxTexture);
		strawberryBox.setTexture(strawberryBoxTexture);
		showingLevelup = true;
		levelupClock.restart();
		break;

	case 4:
		cout << "레벨 4 달성!" << endl;
		pineappleBox.setTexture(pineappleBoxTexture);
		mandarinBox.setTexture(mandarinBoxTexture);
		blackGrapeBox.setTexture(blackGrapeBoxTexture);
		shineMusketBox.setTexture(shineMusketBoxTexture);
		strawberryBox.setTexture(strawberryBoxTexture);
		//showingLevelup = true;
		//levelupClock.restart();
		break;

	default:
		break;
	}





	while (window.isOpen()) {
		Event event;


		//레벨 화면에 보이게 하기 & 3초 뒤 사라지게
		if (showingLevelup) {
			if (levelupClock.getElapsedTime() >= levelupCount) {
				showingLevelup = false;
				cout << "나옴";
			}
		}
		//성공 화면에 보이게 하기 & 2초 뒤 사라지게
		if (showingPerfect) {
			if (perfectClock.getElapsedTime() >= perfectCount) {
				showingPerfect = false;
				cout << "성공화면";
			}
		}
		//실패 화면에 보이게 하기 & 2초 뒤 사라지게
		if (showingFail) {
			if (failClock.getElapsedTime() >= failCount) {
				showingFail = false;
				cout << "실패화면";
			}
		}
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed)
				window.close();


			levelText.setString(to_string(level));

			//판매버튼 클릭
			if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
				Vector2i mousePosition = Mouse::getPosition(window);
				bool isPerfect = false;  //잘 만들었는지 체크용

				if (Sale_btn_sprite.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
					//맞게 만들었는지 검사

					if (isMix) {  //혼합인가
						istringstream iss(order);  //주문 분리를 위해
						string order;  //분리된 문자열을 넣는 용도
						vector<string> mixOrder;  //분리한 주문을 넣을 벡터
						int i = 0;

						while (getline(iss, order, ',')) {  //',' 을 기준으로 문자열 분리
							mixOrder.push_back(order);  //주문 분리해서 벡터에 저장
						}

						for (Fruit fruit : fruits) {
							if (!(fruit.name == mixOrder.at(i)) || !fruit.isCoated) {  //주문과 과일이 다르고 코팅이 안됐다면
								isPerfect = false;  //제대로 못 만듦
								cout << "꽂은 과일    :" << fruit.name << endl;
								cout << "꽂아야할 과일:" << mixOrder.at(i) << endl;
								cout << "--------------------" << endl;
								//break;  //더 이상 체크할 필요가 없으니 for문 나감
							}
							else {
								isPerfect = true;
							}
							//test
							cout << "꽂은 과일    :" << fruit.name << endl;
							cout << "꽂아야할 과일:" << mixOrder.at(i) << endl;
							cout << "--------------------" << endl;

							//mixOrder에서 0과 1을 쓰기 위한...
							if (i == 0) i = 1;
							else i = 0;
						}
					}
					else {  //혼합이 아니면
						for (Fruit fruit : fruits) {
							if (!(fruit.name == order) || !fruit.isCoated) {  //주문과 과일이 다르고 코팅이 안됐다면
								isPerfect = false;  //제대로 못 만듦
								cout << "꽂은 과일    :" << fruit.name << endl;
								cout << "꽂아야할 과일:" << mixOrder.at(i) << endl;
								cout << "--------------------" << endl;
								//break;  //더 이상 체크할 필요가 없으니 for문 나감
							}
							else {
								isPerfect = true;
							}
						}
					}



					if (isPerfect) { //제대로 만들었다면
						cout << endl << "성공~" << endl;
						sale += 3000;
						string saleString = to_string(sale);
						saleText.setString(saleString);  // saleText 업데이트
						showingFail = false;  //실패 안 함
						showingPerfect = true;  //성공함
						perfectClock.restart();

					}
					else {  //못 만들었다면
						cout << endl << "실패!" << endl;
						showingPerfect = false;  //성공 안 함
						showingFail = true;  //실패함
						failClock.restart();
					}

					levelText.setString(to_string(level));


					//도마 위 초기화
					fruits.clear();  //과일 벡터 비움
					stick.setPosition(1200, 1000);  //꼬치 멀리 보내버림
				}
			}
		}

		Vector2i mousePosition = Mouse::getPosition(window);


		//클릭했을 때
		if (!isClicked && event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
			isClicked = true;  //클릭함

			//커서가 과일 박스 위에 있다면 그 과일을 잡음
			if (level >= 4 && blackGrapeBox.getGlobalBounds().contains(static_cast<Vector2f>(mousePosition))) {  //블랙 사파이어 잡음
				Fruit blackGrape("black grape");  //블랙 사파이어 객체 생성
				blackGrape.sprite.setTexture(blackGrapeTexture);  //블랙 사파이어 이미지 할당
				blackGrape.sprite.setPosition(1200, 1000);  //블랙 사파이어 위치 설정
				fruits.push_back(blackGrape);  //벡터에 추가
			}
			else if (level >= 1 && strawberryBox.getGlobalBounds().contains(static_cast<Vector2f>(mousePosition))) {  //딸기 잡음
				Fruit strawberry("strawberry");  //딸기 객체 생성
				strawberry.sprite.setTexture(strawberryTexture);  //딸기 이미지 할당
				strawberry.sprite.setPosition(1200, 1000);  //딸기 위치 설정
				fruits.push_back(strawberry);  //벡터에 추가
			}
			else if (level >= 1 && shineMusketBox.getGlobalBounds().contains(static_cast<Vector2f>(mousePosition))) {  //샤인머스켓 잡음
				Fruit shineMusket("shinemusket");  //샤인머스켓 객체 생성
				shineMusket.sprite.setTexture(shineMusketTexture);  //샤인머스켓 이미지 할당
				shineMusket.sprite.setPosition(1200, 1000);  //샤인머스켓 위치 설정
				fruits.push_back(shineMusket);  //벡터에 추가
			}
			else if (level >= 3 && mandarinBox.getGlobalBounds().contains(static_cast<Vector2f>(mousePosition))) {  //귤 잡음
				Fruit mandarin("mandarin");  //귤 객체 생성
				mandarin.sprite.setTexture(mandarinTexture);  //귤 이미지 할당
				mandarin.sprite.setPosition(1200, 1000);  //귤 위치 설정
				fruits.push_back(mandarin);  //벡터에 추가
			}
			else if (level >= 2 && pineappleBox.getGlobalBounds().contains(static_cast<Vector2f>(mousePosition))) {  //파인애플 잡음
				Fruit pineapple("pineapple");  //파인애플 객체 생성
				pineapple.sprite.setTexture(pineappleTexture);  //파인애플 이미지 할당
				pineapple.sprite.setPosition(1200, 1000);  //파인애플 위치 설정
				fruits.push_back(pineapple);  //벡터에 추가
			}
			else if (stickBox.getGlobalBounds().contains(static_cast<Vector2f>(mousePosition)) && fruits.empty()) {  //fruits 벡터가 비었으면 꼬치 잡음
				stick.setPosition(1200, 1000);  //원래 꼬치 멀리 보내버림
				isStickGrabbed = true;  //꼬치 잡음
			}
			//과일을 끝까지 다 꽂지 않으면 국자를 잡을 수 없음
			else if (fruits.size() == size && ladleSprite.getGlobalBounds().contains(static_cast<Vector2f>(mousePosition))) {  //국자
				ladleSprite.setPosition(1200, 1000);  //원래 국자 멀리 보내버림
				ladleSprite.setRotation(0);  //국자 각도 설정
				isLadleGrabbed = true;  //국자 잡음
			}
			if (wastebasket.getGlobalBounds().contains(static_cast<Vector2f>(mousePosition))) {  //쓰레기통 클릭
				fruits.clear();  //과일 벡터 비움
				stick.setPosition(1200, 1000);  //꼬치 멀리 보내버림
			}
		}

		int positionX = startPosition;  //과일 x 위치 설정
		int positionY = 560;  //과일 y 위치 설정

		// 마우스 이동 중일 때
		if (event.type == Event::MouseMoved) {
			//드래그하면 과일을 마우스 위치로 이동
			Vector2i mousePosition = Mouse::getPosition(window);
			if (isStickGrabbed) {
				Vector2f centerPosition(static_cast<float>(mousePosition.x - stick.getLocalBounds().width / 2), static_cast<float>(mousePosition.y - stick.getLocalBounds().height / 2));
				stick.setPosition(centerPosition);  //꼬치 잡는 위치 설정
			}
			if (isLadleGrabbed) {
				Vector2f centerPosition(static_cast<float>(mousePosition.x - ladleSprite.getLocalBounds().width / 2), static_cast<float>(mousePosition.y - ladleSprite.getLocalBounds().height / 2));
				ladleSprite.setPosition(centerPosition);  //국자 잡는 위치 설정

				if (sugarPot.getGlobalBounds().contains(static_cast<Vector2f>(mousePosition))) {  //설탕물 냄비에 국자를 갖다 대면
					ladleSprite.setTexture(sugarLadleTexture);  //설탕물 국자로 바뀜
					isSugarLadle = true;  //설탕물 있음
				}
			}
			for (Fruit& fruit : fruits) {  //과일
				if (fruit.grabbed) {
					Vector2f centerPosition(static_cast<float>(mousePosition.x - fruit.sprite.getLocalBounds().width / 2), static_cast<float>(mousePosition.y - fruit.sprite.getLocalBounds().height / 2));
					fruit.sprite.setPosition(centerPosition);  //과일 잡는 위치 설정
				}
				if (isSugarLadle && ladleSprite.getGlobalBounds().intersects(fruit.sprite.getGlobalBounds()) && !fruit.isCoated) {  //설탕물 국자일때 과일에 닿으면 코팅됨
					ladleSprite.setRotation(-20);  //국자 살짝 기울임
					fruit.sugarCoating();  //설탕 코팅 이미지로 바꿈
				}
			}
		}

		//국자에서 마우스 뗐을 때
		if (isLadleGrabbed && event.type == Event::MouseButtonReleased && event.mouseButton.button == Mouse::Left) {
			isLadleGrabbed = false;  //국자 안 잡음
			isSugarLadle = false;  //설탕물 없음
			ladleSprite.setTexture(ladleTexture);  //원래 국자 이미지로 설정
			ladleSprite.setPosition(710, 250);  //국자 원래 위치로 되돌려놓음
			ladleSprite.setRotation(90);  //국자 원래 각도로 돌려놓음
		}

		//마우스 뗐을 때
		if (event.type == Event::MouseButtonReleased && event.mouseButton.button == Mouse::Left) {
			isClicked = false;  //클릭 안함
			if (isStickGrabbed) {
				if (!stick.getGlobalBounds().intersects(cuttingBoardSprite.getGlobalBounds())) {  //꼬치를 도마 위에 안 두면
					stick.setPosition(1200, 1000);
				}
				else {
					stick.setPosition(40, 550);  //꼬치 위치 자동으로 설정
				}
				isStickGrabbed = false;
			}

			for (Fruit& fruit : fruits) {  //과일
				fruit.grabbed = false;
				//과일을 꼬치 위에 안 놓거나 도마 위에 재료를 안 놓았다면
				if (!stick.getGlobalBounds().intersects(fruit.sprite.getGlobalBounds())) {
					fruits.pop_back();  //객체에서 삭제
				}
				else {
					fruit.sprite.setPosition(positionX, positionY - fruit.sprite.getGlobalBounds().height / 2);  //과일 위치 자동으로 설정
					positionX += fruit.sprite.getGlobalBounds().width - 6;  //가로 길이 누적
				}
			}
		}

		//탕후루 게임 끝

		//제한시간 : 시간 지나는 코드
		Time elapsed = clock.getElapsedTime();
		if (elapsed >= timeLimit) {
			//cout << "시간 초과!" << endl;
			//window.close();
		}
		//제한시간 : 시간 지나는 코드 끝

	   // 시간을 문자열로 변환하여 텍스트에 설정
		int remainingTime = timeLimit.asSeconds() - elapsed.asSeconds();
		timerText.setString(to_string(remainingTime));


		window.clear();
		//↓ 갈수록 레이어가 위임
		window.draw(cuttingBoardSprite);  //도마 draw
		window.draw(sugarPot);  //설탕물 냄비 draw
		window.draw(frameSprite);  //게임화면 draw
		window.draw(ladleSprite);  //국자 draw
		window.draw(speechBubbleSprite);  //말풍선 draw
		window.draw(blackGrapeBox);  //블랙 사파이어 박스 draw
		window.draw(strawberryBox);  //딸기 박스 draw
		window.draw(shineMusketBox);  //샤인머스켓 박스 draw
		window.draw(mandarinBox);  //귤 박스 draw
		window.draw(pineappleBox);  //파인애플 박스 draw
		window.draw(stickBox);  //꼬치 박스 draw
		window.draw(stick);  //꼬치 draw
		window.draw(wastebasket);  //쓰레기통 draw
		for (const Fruit& fruit : fruits) { //과일 draw
			window.draw(fruit.sprite);
		}
		if (Sale_btnVisible) {
			window.draw(Sale_btn_sprite);
		}
		window.draw(ladleSprite);  //국자
		window.draw(timerText); // 제한 시간 표시
		window.draw(saleText); //판매액 표시
		window.draw(levelText); //레벨 표시
		window.draw(bubbleText);//말풍선 말
		if (showingLevelup) {
			window.draw(levelupSprite);//레벨업 화면
		}
		if (showingPerfect) {
			window.draw(perfectSprite);  //성공
		}
		if (showingFail) {
			window.draw(failSprite);  //실패
		}
		window.display();

	}
}
