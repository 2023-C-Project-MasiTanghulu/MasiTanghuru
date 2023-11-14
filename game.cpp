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
		return L"����";
	}
	else if (englishName == "shinemusket") {
		return L"���θӽ���";
	}
	else if (englishName == "pineapple") {
		return L"���ξ���";
	}
	else if (englishName == "black grape") {
		return L"�� �����̾� ����";
	}
	else if (englishName == "mandarin") {
		return L"���";
	}
};


void Game::run(RenderWindow& window) {
	window.create(VideoMode(1500, 800), L"���ķ� �����");

	//���ķ� ����
	Texture frame;  //���� ȭ��
	frame.loadFromFile("image/Game_frame.png");  //���� ȭ�� �̹���
	Sprite frameSprite(frame);  //���� ȭ�� �̹��� �Ҵ�

	Texture cuttingBoard;  //����
	cuttingBoard.loadFromFile("image/CuttingBoard.png");  //���� �̹���
	Sprite cuttingBoardSprite(cuttingBoard);  //���� �̹��� �Ҵ�
	cuttingBoardSprite.setPosition(20, 310);  //���� ��ġ ����

	Texture speechBubble;  //��ǳ��
	speechBubble.loadFromFile("image/speechBubble.png");  //��ǳ�� �̹���
	Sprite speechBubbleSprite(speechBubble);  //��ǳ�� �̹��� �Ҵ�
	speechBubbleSprite.setPosition(0, 0);  //��ǳ�� ��ġ ����

	// 3�� �Ŀ� ��ǳ���� ����� �Լ�
	auto clearSpeechBubble = [&speechBubbleSprite]() {
		this_thread::sleep_for(chrono::seconds(3));
		speechBubbleSprite.setPosition(-1000, -1000); // ȭ�� ������ �̵����� ������ �ʰ� ��
	};

	// 3�� �ڿ� ��ǳ���� ����
	thread(clearSpeechBubble).detach();  // �� �����忡�� ����


	Texture boxildTexture; //�ڽ� �Ѳ�
	boxildTexture.loadFromFile("image/boxlid.png");

	Texture blackGrapeBoxTexture;  //�� �����̾� �ڽ�
	blackGrapeBoxTexture.loadFromFile("image/BlackGrape_box.png");  //�� �����̾� �ڽ� �̹���
	Sprite blackGrapeBox(boxildTexture);  //�� �����̾� �ڽ� �̹��� �Ҵ�
	blackGrapeBox.setPosition(960, 260);  //�� �����̾� �ڽ� ��ġ ����

	Texture blackGrapeTexture;  //�� �����̾�
	blackGrapeTexture.loadFromFile("image/BlackGrape.png");  //�� �����̾� �̹���

	Texture strawberryBoxTexture;  //���� �ڽ�
	strawberryBoxTexture.loadFromFile("image/Strawberry_box.png");  //���� �ڽ� �̹���
	Sprite strawberryBox(boxildTexture);  //���� �ڽ� �̹��� �Ҵ�
	strawberryBox.setPosition(1200, 260);  //���� �ڽ� ��ġ ����

	Texture strawberryTexture;  //����
	strawberryTexture.loadFromFile("image/Strawberry.png");  //���� �̹���

	Texture shineMusketBoxTexture;  //���θӽ��� �ڽ�
	shineMusketBoxTexture.loadFromFile("image/Shinemusket_box.png");  //���θӽ��� �ڽ� �̹���
	Sprite shineMusketBox(boxildTexture);  //���θӽ��� �ڽ� �̹��� �Ҵ�
	shineMusketBox.setPosition(960, 440);  //���θӽ��� �ڽ� ��ġ ����

	Texture shineMusketTexture;  //���θӽ���
	shineMusketTexture.loadFromFile("image/Shinemusket.png");  //���θӽ��� �̹���

	Texture mandarinBoxTexture;  //�� �ڽ�
	mandarinBoxTexture.loadFromFile("image/Mandarin_box.png");  //�� �ڽ� �̹���
	Sprite mandarinBox(boxildTexture);  //�� �ڽ� �̹��� �Ҵ�
	mandarinBox.setPosition(1200, 440);  //�� �ڽ� ��ġ ����

	Texture mandarinTexture;  //��
	mandarinTexture.loadFromFile("image/Mandarin.png");  //�� �̹���

	Texture pineappleBoxTexture;  //���ξ��� �ڽ�
	pineappleBoxTexture.loadFromFile("image/Pineapple_box.png");  //���ξ��� �ڽ� �̹���
	Sprite pineappleBox(boxildTexture);  //���ξ��� �ڽ� �̹��� �Ҵ�
	pineappleBox.setPosition(960, 620);  //���ξ��� �ڽ� ��ġ ����

	Texture pineappleTexture;  //���ξ���
	pineappleTexture.loadFromFile("image/Pineapple.png");  //���ξ��� �̹���

	Texture stickBoxTexture;  //��ġ �ڽ�
	stickBoxTexture.loadFromFile("image/Stick_box.png");  //��ġ �ڽ� �̹���
	Sprite stickBox(stickBoxTexture);  //��ġ �ڽ� �̹��� �Ҵ�
	stickBox.setPosition(1190, 610);  //��ġ �ڽ� ��ġ ����

	Texture stickTexture;  //��ġ
	stickTexture.loadFromFile("image/Stick.png");  //��ġ �̹���
	Sprite stick(stickTexture);  //��ġ �̹��� �Ҵ�
	stick.setPosition(1200, 1000);  //��ġ ��ġ ����

	Texture sugarPotTexture;  //������ ����
	sugarPotTexture.loadFromFile("image/SugarPot.png");  //������ ���� �̹���
	Sprite sugarPot(sugarPotTexture);  //������ ���� �̹��� �Ҵ�
	sugarPot.setPosition(620, 345);  //������ ���� ��ġ ����

	Texture ladleTexture;  //����
	ladleTexture.loadFromFile("image/Ladle.png");  //���� �̹���
	Sprite ladleSprite(ladleTexture);  //���� �̹��� �Ҵ�
	ladleSprite.rotate(90);  //���� ���� ����
	ladleSprite.setPosition(710, 250);  //���� ��ġ ����

	Texture sugarLadleTexture;  //������ ����
	sugarLadleTexture.loadFromFile("image/SugarLadle.png");  //������ ���� �̹���
	Sprite sugarLadle(sugarLadleTexture);  //������ ���� �̹��� �Ҵ�

	Texture wastebasketTexture;  //��������
	wastebasketTexture.loadFromFile("image/Wastebasket.png");  //�������� �̹���
	Sprite wastebasket(wastebasketTexture);  //�������� �̹��� �Ҵ�
	wastebasket.setPosition(20, 230);

	//�����̹���
	Texture failTexture;  //����
	failTexture.loadFromFile("image/fail.png");  //���� �̹���
	Sprite failSprite(failTexture);  //���� �̹��� �Ҵ�
	failSprite.setPosition(0, 3);//���� �̹��� ��ġ ����

	//�����̹���
	Texture perfectTexture;  //����
	perfectTexture.loadFromFile("image/perfect.png");  //���� �̹���
	Sprite perfectSprite(perfectTexture);  //���� �̹��� �Ҵ�
	perfectSprite.setPosition(0, 3);//���� �̹��� ��ġ ����

	bool isFruitGrabbed = false;  //������ �����°� �������°�
	bool isClicked = false;  //���콺 Ŭ���� �ߴ°� ���ߴ°�
	bool isLadleGrabbed = false;  //���ڸ� �����°� �������°�
	bool isSugarLadle = false;  //������ �����ΰ� �ƴѰ�
	bool isStickGrabbed = false;  //��ġ�� �����°� �������°�
	bool isMix = false;  //���� 2������ ���ķ��ΰ�
	bool showingFail = false;
	bool showingPerfect = false;

	int size = 0;  //���� ���� ���� ���ϴ� ����
	int startPosition = 650;  //���� �ȱ� ���� ��ġ
	vector<Fruit> fruits;  //���� ����


	//��Ʈ ����
	Font font;
	font.loadFromFile("font/NanumGothic.ttf");

	// ���� �ð� : ȭ�鿡 ǥ���� �ؽ�Ʈ ����
	Text timerText;
	timerText.setFont(font); // ��Ʈ ���� (sfml�� ������ ��Ʈ�� ����ؾ���. )
	timerText.setCharacterSize(50); // �۲� ũ�� ����
	timerText.setFillColor(Color::Black); // �۲� ������ ���������� ����
	timerText.setStyle(Text::Bold); // �۲� ��Ÿ�� ����
	timerText.setPosition(1250, 35); // �ؽ�Ʈ ��ġ ����

	//���ѽð� : �� ����
	Clock clock;
	const Time timeLimit = seconds(60); // 60�ʷ� ����

	//�Ǹ��ϱ� : �ؽ�Ʈ ����
	Text saleText;  // �ؽ�Ʈ ��ü ����
	saleText.setFont(font);  // ��Ʈ ����
	saleText.setCharacterSize(50);  // ���� ũ�� ����
	saleText.setFillColor(Color::Black);  // ���� ���� ����
	saleText.setStyle(Text::Bold);
	saleText.setPosition(1230, 105);  // ��ġ ����

	//���� ǥ��  : �ؽ�Ʈ ����
	Text levelText;  // �ؽ�Ʈ ��ü ����
	levelText.setFont(font);  // ��Ʈ ����
	levelText.setCharacterSize(50);  // ���� ũ�� ����
	levelText.setFillColor(Color::Black);  // ���� ���� ����
	levelText.setStyle(Text::Bold);
	levelText.setPosition(1250, 170);  // ��ġ ����

	//��ǳ�� ��: �մ� �ֹ�
	Text bubbleText;
	bubbleText.setFont(font);
	bubbleText.setCharacterSize(50);
	bubbleText.setFillColor(Color::Black);
	bubbleText.setStyle(Text::Bold);
	bubbleText.setPosition(50, 50); // �ؽ�Ʈ ��ġ ����

	// 3�� �Ŀ� ��ǳ�� ������ ����� �Լ�
	auto clearBubbleText = [&bubbleText]() {
		this_thread::sleep_for(chrono::seconds(3));
		bubbleText.setString(L"");
	};

	// 3�� �ڿ� ��ǳ�� ���� ����
	thread(clearBubbleText).detach();

	// �Ǹ��ϱ� ��ư
	Texture Sale_btn_texture;
	Sale_btn_texture.loadFromFile("image/Sale_btn.png"); // ��ư �̹��� �ҷ�����
	Sprite Sale_btn_sprite(Sale_btn_texture);
	Sale_btn_sprite.setPosition(50, 50); // ��ư ��ġ ����

	bool Sale_btnVisible = false; // Sale ��ư�� ó������ ���ܳ���

	// 3�� �ڿ� Sale ��ư�� ���̵��� �ϴ� �Լ�
	auto AfterSale_btn = [&]() {
		this_thread::sleep_for(chrono::seconds(3));
		Sale_btnVisible = true;
	};

	thread(AfterSale_btn).detach(); // �� �����忡�� ����


	// ���� �ֹ� ���
	vector<vector<string>> levelFruits = {
			   { "shinemusket","strawberry"},                  // Level 1
			   {"strawberry", "shinemusket", "pineapple"},     // Level 2
			   {"strawberry", "shinemusket", "pineapple", "mandarin"},  // Level 3
			   {"strawberry", "shinemusket", "pineapple", "mandarin", "black grape"}  // Level 4
	};
	
	int level = 4;
	// ���� ������ �ش��ϴ� �ֹ� ��� ��������
	vector<string> orders = levelFruits[level - 1];

	// �ֹ� ���� ������
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	uniform_int_distribution<int> dist(0, orders.size() - 1);
	int randomIndex = dist(rng);


	
	
	// �ֹ� wstring���� ��ȯ
	wstring order = L"";
	int numFruits = orders.size(); // ���� ������ ���� ����
	// ������ �°� �ֹ� ����
	if (numFruits > 0) {
		// �������� ������ ���� ����
		int numSelectedFruits = dist(rng) % 2 + 1;

		// ������ ���ϵ��� ������ ����
		vector<string> selectedFruits;

		for (int i = 0; i < numSelectedFruits; ++i) {
			int randomFruitIndex;

			// �̹� ���õ� ������ ������ �ʵ��� �ݺ��ؼ� ����
			do {
				randomFruitIndex = dist(rng);
			} while (find(selectedFruits.begin(), selectedFruits.end(), orders[randomFruitIndex]) != selectedFruits.end());

			selectedFruits.push_back(orders[randomFruitIndex]);
		}

		// ������ ���ϵ��� ���ڿ��� ��ġ��
		for (int i = 0; i < numSelectedFruits; ++i) {
			order += convertToFruitName(selectedFruits[i]);

			// ������ ������ �ƴϸ� ��ǥ �߰�
			if (i < numSelectedFruits - 1) {
				order += L", ";
			}
		}
	}

	bubbleText.setString(order + L" ���ķ� �ּ���.");

	//�ֹ� wstring���� ��ȯ & ���� ���� ��ġ ���� & ���� ���� ����
	if (order == "����") {
		size = 4;
		startPosition -= strawberryTexture.getSize().x * size;
		isMix = false;
	}
	else if (order == "���θӽ���") {
		size = 6;
		startPosition -= shineMusketTexture.getSize().x * size;
		isMix = false;
	}
	else if (order == "���ξ���") {
		size = 5;
		startPosition -= pineappleTexture.getSize().x * size;
		isMix = false;
	}
	else if (order == "�� �����̾� ����") {
		size = 8;
		startPosition -= blackGrapeTexture.getSize().x * size;
		isMix = false;
	}
	else if (order == "���") {
		size = 4;
		startPosition -= mandarinTexture.getSize().x * size;
		isMix = false;
	}
	else if (order == "����,���θӽ���") {
		size = 5;
		startPosition -= shineMusketTexture.getSize().x * 2 + strawberryTexture.getSize().x * 3;
		isMix = true;
	}
	else if (order == "����,���ξ���") {
		size = 5;
		startPosition -= pineappleTexture.getSize().x * 2 + strawberryTexture.getSize().x * 3;
		isMix = true;
	}
	else if (order == "����,�� �����̾� ����") {
		size = 5;
		startPosition -= strawberryTexture.getSize().x * 3 + blackGrapeTexture.getSize().x * 2;
		isMix = true;
	}
	else if (order == "����,���") {
		size = 4;
		startPosition -= strawberryTexture.getSize().x * 2 + mandarinTexture.getSize().x * 2;
		isMix = true;
	}
	else if (order == "���θӽ���,���ξ���") {
		size = 6;
		startPosition -= shineMusketTexture.getSize().x * 3 + pineappleTexture.getSize().x * 3;
		isMix = true;
	}
	else if (order == "���θӽ���,���") {
		size = 5;
		startPosition -= strawberryTexture.getSize().x * 2 + mandarinTexture.getSize().x * 2;
		isMix = true;
	}
	else if (order == "���θӽ���,�� �����̾� ����") {
		size = 8;
		startPosition -= shineMusketTexture.getSize().x * 4 + blackGrapeTexture.getSize().x * 4;
		isMix = true;
	}
	else if (order == "���ξ���,�� �����̾� ����") {
		size = 6;
		startPosition -= pineappleTexture.getSize().x * 3 + blackGrapeTexture.getSize().x * 3;
		isMix = true;
	}
	else if (order == "���ξ���,���") {
		size = 4;
		startPosition -= pineappleTexture.getSize().x * 2 + mandarinTexture.getSize().x * 2;
		isMix = true;
	}
	else if (order == "�� �����̾� ����,���") {
		size = 6;
		startPosition -= blackGrapeTexture.getSize().x * 3 + mandarinTexture.getSize().x * 3;
		isMix = true;
	}

	

	//������ ȭ��
	Clock levelupClock;
	Time levelupCount = seconds(3);
	bool showingLevelup = false;

	Texture levelupTexture;  //������ �̹���
	levelupTexture.loadFromFile("image/Levelup_frame.png");  // ������ �̹��� �ε�
	Sprite levelupSprite(levelupTexture);
	levelupSprite.setPosition(0, 3);  // ������ �̹��� ��ġ ����

	//����,���� ȭ��
	Clock perfectClock;
	Time perfectCount = seconds(2);

	Clock failClock;
	Time failCount = seconds(2);

	//����
	int sale = 0;//�Ǹž�

	//�Ǹž׿� ���� ����
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
		shineMusketBox.setTexture(shineMusketBoxTexture);  //���� ���θӽ��� �ڽ��� �ٲ���
		strawberryBox.setTexture(strawberryBoxTexture);  //���� ���� �ڽ��� �ٲ���
		break;

	case 2:
		cout << "���� 2 �޼�!" << endl;
		pineappleBox.setTexture(pineappleBoxTexture);
		shineMusketBox.setTexture(shineMusketBoxTexture);
		strawberryBox.setTexture(strawberryBoxTexture);
		//showingLevelup = true;
		//levelupClock.restart();
		break;

	case 3:
		cout << "���� 3 �޼�!" << endl;
		pineappleBox.setTexture(pineappleBoxTexture);
		mandarinBox.setTexture(mandarinBoxTexture);
		shineMusketBox.setTexture(shineMusketBoxTexture);
		strawberryBox.setTexture(strawberryBoxTexture);
		showingLevelup = true;
		levelupClock.restart();
		break;

	case 4:
		cout << "���� 4 �޼�!" << endl;
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


		//���� ȭ�鿡 ���̰� �ϱ� & 3�� �� �������
		if (showingLevelup) {
			if (levelupClock.getElapsedTime() >= levelupCount) {
				showingLevelup = false;
				cout << "����";
			}
		}
		//���� ȭ�鿡 ���̰� �ϱ� & 2�� �� �������
		if (showingPerfect) {
			if (perfectClock.getElapsedTime() >= perfectCount) {
				showingPerfect = false;
				cout << "����ȭ��";
			}
		}
		//���� ȭ�鿡 ���̰� �ϱ� & 2�� �� �������
		if (showingFail) {
			if (failClock.getElapsedTime() >= failCount) {
				showingFail = false;
				cout << "����ȭ��";
			}
		}
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed)
				window.close();


			levelText.setString(to_string(level));

			//�ǸŹ�ư Ŭ��
			if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
				Vector2i mousePosition = Mouse::getPosition(window);
				bool isPerfect = false;  //�� ��������� üũ��

				if (Sale_btn_sprite.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
					//�°� ��������� �˻�

					if (isMix) {  //ȥ���ΰ�
						istringstream iss(order);  //�ֹ� �и��� ����
						string order;  //�и��� ���ڿ��� �ִ� �뵵
						vector<string> mixOrder;  //�и��� �ֹ��� ���� ����
						int i = 0;

						while (getline(iss, order, ',')) {  //',' �� �������� ���ڿ� �и�
							mixOrder.push_back(order);  //�ֹ� �и��ؼ� ���Ϳ� ����
						}

						for (Fruit fruit : fruits) {
							if (!(fruit.name == mixOrder.at(i)) || !fruit.isCoated) {  //�ֹ��� ������ �ٸ��� ������ �ȵƴٸ�
								isPerfect = false;  //����� �� ����
								cout << "���� ����    :" << fruit.name << endl;
								cout << "�Ⱦƾ��� ����:" << mixOrder.at(i) << endl;
								cout << "--------------------" << endl;
								//break;  //�� �̻� üũ�� �ʿ䰡 ������ for�� ����
							}
							else {
								isPerfect = true;
							}
							//test
							cout << "���� ����    :" << fruit.name << endl;
							cout << "�Ⱦƾ��� ����:" << mixOrder.at(i) << endl;
							cout << "--------------------" << endl;

							//mixOrder���� 0�� 1�� ���� ����...
							if (i == 0) i = 1;
							else i = 0;
						}
					}
					else {  //ȥ���� �ƴϸ�
						for (Fruit fruit : fruits) {
							if (!(fruit.name == order) || !fruit.isCoated) {  //�ֹ��� ������ �ٸ��� ������ �ȵƴٸ�
								isPerfect = false;  //����� �� ����
								cout << "���� ����    :" << fruit.name << endl;
								cout << "�Ⱦƾ��� ����:" << mixOrder.at(i) << endl;
								cout << "--------------------" << endl;
								//break;  //�� �̻� üũ�� �ʿ䰡 ������ for�� ����
							}
							else {
								isPerfect = true;
							}
						}
					}



					if (isPerfect) { //����� ������ٸ�
						cout << endl << "����~" << endl;
						sale += 3000;
						string saleString = to_string(sale);
						saleText.setString(saleString);  // saleText ������Ʈ
						showingFail = false;  //���� �� ��
						showingPerfect = true;  //������
						perfectClock.restart();

					}
					else {  //�� ������ٸ�
						cout << endl << "����!" << endl;
						showingPerfect = false;  //���� �� ��
						showingFail = true;  //������
						failClock.restart();
					}

					levelText.setString(to_string(level));


					//���� �� �ʱ�ȭ
					fruits.clear();  //���� ���� ���
					stick.setPosition(1200, 1000);  //��ġ �ָ� ��������
				}
			}
		}

		Vector2i mousePosition = Mouse::getPosition(window);


		//Ŭ������ ��
		if (!isClicked && event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
			isClicked = true;  //Ŭ����

			//Ŀ���� ���� �ڽ� ���� �ִٸ� �� ������ ����
			if (level >= 4 && blackGrapeBox.getGlobalBounds().contains(static_cast<Vector2f>(mousePosition))) {  //�� �����̾� ����
				Fruit blackGrape("black grape");  //�� �����̾� ��ü ����
				blackGrape.sprite.setTexture(blackGrapeTexture);  //�� �����̾� �̹��� �Ҵ�
				blackGrape.sprite.setPosition(1200, 1000);  //�� �����̾� ��ġ ����
				fruits.push_back(blackGrape);  //���Ϳ� �߰�
			}
			else if (level >= 1 && strawberryBox.getGlobalBounds().contains(static_cast<Vector2f>(mousePosition))) {  //���� ����
				Fruit strawberry("strawberry");  //���� ��ü ����
				strawberry.sprite.setTexture(strawberryTexture);  //���� �̹��� �Ҵ�
				strawberry.sprite.setPosition(1200, 1000);  //���� ��ġ ����
				fruits.push_back(strawberry);  //���Ϳ� �߰�
			}
			else if (level >= 1 && shineMusketBox.getGlobalBounds().contains(static_cast<Vector2f>(mousePosition))) {  //���θӽ��� ����
				Fruit shineMusket("shinemusket");  //���θӽ��� ��ü ����
				shineMusket.sprite.setTexture(shineMusketTexture);  //���θӽ��� �̹��� �Ҵ�
				shineMusket.sprite.setPosition(1200, 1000);  //���θӽ��� ��ġ ����
				fruits.push_back(shineMusket);  //���Ϳ� �߰�
			}
			else if (level >= 3 && mandarinBox.getGlobalBounds().contains(static_cast<Vector2f>(mousePosition))) {  //�� ����
				Fruit mandarin("mandarin");  //�� ��ü ����
				mandarin.sprite.setTexture(mandarinTexture);  //�� �̹��� �Ҵ�
				mandarin.sprite.setPosition(1200, 1000);  //�� ��ġ ����
				fruits.push_back(mandarin);  //���Ϳ� �߰�
			}
			else if (level >= 2 && pineappleBox.getGlobalBounds().contains(static_cast<Vector2f>(mousePosition))) {  //���ξ��� ����
				Fruit pineapple("pineapple");  //���ξ��� ��ü ����
				pineapple.sprite.setTexture(pineappleTexture);  //���ξ��� �̹��� �Ҵ�
				pineapple.sprite.setPosition(1200, 1000);  //���ξ��� ��ġ ����
				fruits.push_back(pineapple);  //���Ϳ� �߰�
			}
			else if (stickBox.getGlobalBounds().contains(static_cast<Vector2f>(mousePosition)) && fruits.empty()) {  //fruits ���Ͱ� ������� ��ġ ����
				stick.setPosition(1200, 1000);  //���� ��ġ �ָ� ��������
				isStickGrabbed = true;  //��ġ ����
			}
			//������ ������ �� ���� ������ ���ڸ� ���� �� ����
			else if (fruits.size() == size && ladleSprite.getGlobalBounds().contains(static_cast<Vector2f>(mousePosition))) {  //����
				ladleSprite.setPosition(1200, 1000);  //���� ���� �ָ� ��������
				ladleSprite.setRotation(0);  //���� ���� ����
				isLadleGrabbed = true;  //���� ����
			}
			if (wastebasket.getGlobalBounds().contains(static_cast<Vector2f>(mousePosition))) {  //�������� Ŭ��
				fruits.clear();  //���� ���� ���
				stick.setPosition(1200, 1000);  //��ġ �ָ� ��������
			}
		}

		int positionX = startPosition;  //���� x ��ġ ����
		int positionY = 560;  //���� y ��ġ ����

		// ���콺 �̵� ���� ��
		if (event.type == Event::MouseMoved) {
			//�巡���ϸ� ������ ���콺 ��ġ�� �̵�
			Vector2i mousePosition = Mouse::getPosition(window);
			if (isStickGrabbed) {
				Vector2f centerPosition(static_cast<float>(mousePosition.x - stick.getLocalBounds().width / 2), static_cast<float>(mousePosition.y - stick.getLocalBounds().height / 2));
				stick.setPosition(centerPosition);  //��ġ ��� ��ġ ����
			}
			if (isLadleGrabbed) {
				Vector2f centerPosition(static_cast<float>(mousePosition.x - ladleSprite.getLocalBounds().width / 2), static_cast<float>(mousePosition.y - ladleSprite.getLocalBounds().height / 2));
				ladleSprite.setPosition(centerPosition);  //���� ��� ��ġ ����

				if (sugarPot.getGlobalBounds().contains(static_cast<Vector2f>(mousePosition))) {  //������ ���� ���ڸ� ���� ���
					ladleSprite.setTexture(sugarLadleTexture);  //������ ���ڷ� �ٲ�
					isSugarLadle = true;  //������ ����
				}
			}
			for (Fruit& fruit : fruits) {  //����
				if (fruit.grabbed) {
					Vector2f centerPosition(static_cast<float>(mousePosition.x - fruit.sprite.getLocalBounds().width / 2), static_cast<float>(mousePosition.y - fruit.sprite.getLocalBounds().height / 2));
					fruit.sprite.setPosition(centerPosition);  //���� ��� ��ġ ����
				}
				if (isSugarLadle && ladleSprite.getGlobalBounds().intersects(fruit.sprite.getGlobalBounds()) && !fruit.isCoated) {  //������ �����϶� ���Ͽ� ������ ���õ�
					ladleSprite.setRotation(-20);  //���� ��¦ �����
					fruit.sugarCoating();  //���� ���� �̹����� �ٲ�
				}
			}
		}

		//���ڿ��� ���콺 ���� ��
		if (isLadleGrabbed && event.type == Event::MouseButtonReleased && event.mouseButton.button == Mouse::Left) {
			isLadleGrabbed = false;  //���� �� ����
			isSugarLadle = false;  //������ ����
			ladleSprite.setTexture(ladleTexture);  //���� ���� �̹����� ����
			ladleSprite.setPosition(710, 250);  //���� ���� ��ġ�� �ǵ�������
			ladleSprite.setRotation(90);  //���� ���� ������ ��������
		}

		//���콺 ���� ��
		if (event.type == Event::MouseButtonReleased && event.mouseButton.button == Mouse::Left) {
			isClicked = false;  //Ŭ�� ����
			if (isStickGrabbed) {
				if (!stick.getGlobalBounds().intersects(cuttingBoardSprite.getGlobalBounds())) {  //��ġ�� ���� ���� �� �θ�
					stick.setPosition(1200, 1000);
				}
				else {
					stick.setPosition(40, 550);  //��ġ ��ġ �ڵ����� ����
				}
				isStickGrabbed = false;
			}

			for (Fruit& fruit : fruits) {  //����
				fruit.grabbed = false;
				//������ ��ġ ���� �� ���ų� ���� ���� ��Ḧ �� ���Ҵٸ�
				if (!stick.getGlobalBounds().intersects(fruit.sprite.getGlobalBounds())) {
					fruits.pop_back();  //��ü���� ����
				}
				else {
					fruit.sprite.setPosition(positionX, positionY - fruit.sprite.getGlobalBounds().height / 2);  //���� ��ġ �ڵ����� ����
					positionX += fruit.sprite.getGlobalBounds().width - 6;  //���� ���� ����
				}
			}
		}

		//���ķ� ���� ��

		//���ѽð� : �ð� ������ �ڵ�
		Time elapsed = clock.getElapsedTime();
		if (elapsed >= timeLimit) {
			//cout << "�ð� �ʰ�!" << endl;
			//window.close();
		}
		//���ѽð� : �ð� ������ �ڵ� ��

	   // �ð��� ���ڿ��� ��ȯ�Ͽ� �ؽ�Ʈ�� ����
		int remainingTime = timeLimit.asSeconds() - elapsed.asSeconds();
		timerText.setString(to_string(remainingTime));


		window.clear();
		//�� ������ ���̾ ����
		window.draw(cuttingBoardSprite);  //���� draw
		window.draw(sugarPot);  //������ ���� draw
		window.draw(frameSprite);  //����ȭ�� draw
		window.draw(ladleSprite);  //���� draw
		window.draw(speechBubbleSprite);  //��ǳ�� draw
		window.draw(blackGrapeBox);  //�� �����̾� �ڽ� draw
		window.draw(strawberryBox);  //���� �ڽ� draw
		window.draw(shineMusketBox);  //���θӽ��� �ڽ� draw
		window.draw(mandarinBox);  //�� �ڽ� draw
		window.draw(pineappleBox);  //���ξ��� �ڽ� draw
		window.draw(stickBox);  //��ġ �ڽ� draw
		window.draw(stick);  //��ġ draw
		window.draw(wastebasket);  //�������� draw
		for (const Fruit& fruit : fruits) { //���� draw
			window.draw(fruit.sprite);
		}
		if (Sale_btnVisible) {
			window.draw(Sale_btn_sprite);
		}
		window.draw(ladleSprite);  //����
		window.draw(timerText); // ���� �ð� ǥ��
		window.draw(saleText); //�Ǹž� ǥ��
		window.draw(levelText); //���� ǥ��
		window.draw(bubbleText);//��ǳ�� ��
		if (showingLevelup) {
			window.draw(levelupSprite);//������ ȭ��
		}
		if (showingPerfect) {
			window.draw(perfectSprite);  //����
		}
		if (showingFail) {
			window.draw(failSprite);  //����
		}
		window.display();

	}
}
