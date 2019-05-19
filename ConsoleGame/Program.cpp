#include <iostream>
#include <string>

using namespace std;
// 
class player // stats and inventory
{
public:
	int impudence = 0;
	bool glass = false;
	bool stick = false;
};
class location
{
public:
	virtual void intro() = 0;
	virtual void choice(player pl) = 0;
	virtual void first(player pl) = 0;
	virtual void second(player pl) = 0;
	virtual void third(player pl) = 0;
};
//

///
void printStats(player pl)
{
	cout << "Статистика:" << endl;
	cout << "Наглость Тома: " << pl.impudence << endl;
	cout << "Достижения:" << endl;
	if (pl.glass)
		cout << "Украл стакан из паба" << endl;
	if (pl.stick)
		cout << "Украл палку от швабры из паба" << endl;
	cout << "\n" << "По мотивам песни:\nСухой закон - Green Crow" << endl;
	system("pause");
}
void GameOver(player pl)
{
	cout << '\n';
	cout << "ИГРА ОКОНЧЕНА\nТЫ ПРОИГРАЛ" << endl;
	cout << '\n';
	printStats(pl);
}
void Win(player pl)
{
	cout << '\n';
	cout << "ИГРА ОКОНЧЕНА\nТЫ ПОБЕДИЛ" << endl;
	cout << '\n';
	printStats(pl);
}
///

class end00 : public location
{
public:
	void intro()
	{
		cout << "Запален бикфордов шнур, раздался грохот, дверь долой!\nИ пиво вспенилось рекой\nГуляй и пей, веселый люд, и вечных славь богов!\nНарод ликует, пир горой. Ты во главе стола - герой\nНо что-то не дает вздохнуть, метлою тычет" << endl;
	}
	void choice(player pl)
	{
		cout << "\nВыберите действие:\n1. Продолжить" << endl;
	}
	void first(player pl)
	{
		cout << "Открыл глаза - официант... Ты под столом и в стельку пьян\nЭто был все сон\nВокруг веселье и друзья, и милый сердцу паб!" << endl;
		Win(pl);
	}
	void second(player pl)
	{

	}
	void third(player pl)
	{

	}
};

void location7_End00(player pl)
{
	end00 pub;
	bool flag{ true };
	while (flag)
	{
		pub.intro();
		pub.choice(pl);
		int cas;
		cin >> cas;
		switch (cas)
		{
		case 1:
			system("cls");
			pub.first(pl);
			flag = false;
			break;
		}
	}
}

class Pit : public location
{
public:
	void intro()
	{
		cout << "Один из них оказался твоим корешом - Питом\nОн варит динамит. Тебе в голову приходит мысль взорвать подвал\nПолицейский из паба, из которого ты вышел, следовал за тобой и собирается помешать тебе" << endl;
	}
	void choice(player pl)
	{
		if (pl.glass)
			cout << "\nВыберите действие:\n1. Попытаться напасть толпой на него\n2. Разбить стакан, взятый из паба, о его голову" << endl;
		else if (pl.stick)
			cout << "\nВыберите действие:\n1. Попытаться напасть толпой на него\n2. Ударить его палкой" << endl;
		else 
			cout << "\nВыберите действие:\n1. Попытаться напасть толпой на него" << endl;
	}
	void first(player pl)
	{
		cout << "Вам не хватило сил одолеть полицейского\nТебя и Пита повязали и забрали в участок" << endl;
		GameOver(pl);
	}
	void second(player pl)
	{
		cout << "Ты повалил полицейского на землю. Кажется он без сознания" << endl;
		location7_End00(pl);
	}
	void third(player pl)
	{

	}
};

void location6_Pit(player pl)
{
	Pit pub;
	bool flag{ true };
	while (flag)
	{
		pub.intro();
		pub.choice(pl);
		int cas;
		cin >> cas;
		switch (cas)
		{
		case 1:
			system("cls");
			pub.first(pl);
			flag = false;
			break;
		case 2:
			system("cls");
			pub.second(pl);
			flag = false;
			break;
		}
	}
}

class magazine00 : public location
{
public:
	void intro()
	{
		cout << "Выйдя на улицу ты сразу же затерялся в толпе людей\nВ городе творится какой-то бардак\nНад ратушей английский флаг\nИ в довершенье этих бед введён сухой закон\nВ утренней газете написано: \"Все пиво заперто в подвал\"" << endl;
	}
	void choice(player pl)
	{
		cout << "\nВыберите действие:\n1. Крикнуть на всю улицу в надежде найти своих друзей\n2. Прогуляться по улицам и поискать друзей" << endl;
	}
	void first(player pl)
	{
		if(pl.impudence == 1)
		cout << "Ты кричишь во весь голос и с другой стороны улицы тебе кричат в ответ. Это они." << endl;
		else if (pl.impudence == 0)
			cout << "Кажется ты не настолько наглый и постеснялся кричать\nНо не беда. Спустя пару часов ты нашел друзей" << endl;
		location6_Pit(pl);
	}
	void second(player pl)
	{
		cout << "Спустя пару часов ты находишь друзей" << endl;
		location6_Pit(pl);
	}
	void third(player pl)
	{

	}
};

void location5_magazine00(player pl)
{
	magazine00 mag;
	bool flag{ true };
	while (flag)
	{
		mag.intro();
		mag.choice(pl);
		int cas;
		cin >> cas;
		switch (cas)
		{
		case 1:
			system("cls");
			mag.first(pl);
			flag = false;
			break;
		case 2:
			system("cls");
			mag.second(pl);
			flag = false;
			break;
		}
	}
}

class pubExit02 : public location
{
public:
	void intro()
	{
		cout << "Но тебя смущает притихший паб, где же “Гиннес”, где же “Харп”?\nЛишь в чашечках дымится чай – здесь вечный файф-о-клок. Сидят английский джентльмен и в каске толстый полисмен\nОни предлагают тебе чашку чая" << endl;
	}
	void choice(player pl)
	{
		cout << "\nВыберите действие:\n1. ДА ЗА КОГО ВЫ МЕНЯ ДЕРЖИТЕ?!?! Хлопнуть дверью и уйти\n2. Согласиться" << endl;
	}
	void first(player pl)
	{
		cout << "Совсем одурели, что происходит? - Подумал Том" << endl;
		location5_magazine00(pl);
	}
	void second(player pl)
	{
		cout << "Такой вариант никак не приемлем и пить чай с англичанами это значит потерять себя. Ты больше не Ирландец" << endl;
		GameOver(pl);
	}
	void third(player pl)
	{

	}
};

void location4_PubExit02(player pl)
{
	pubExit02 pub;
	bool flag{ true };
	while (flag)
	{
		pub.intro();
		pub.choice(pl);
		int cas;
		cin >> cas;
		switch (cas)
		{
		case 1:
			system("cls");
			pub.first(pl);
			flag = false;
			break;
		case 2:
			system("cls");
			pub.second(pl);
			flag = false;
			break;
		}
	}
}

class pubExit01 : public location
{
public:
	void intro()
	{
		cout << "" << endl;
	}
	void choice(player pl)
	{
		cout << "\nВыберите действие:\n1. Взять палку\n2. Не брать палку" << endl;
	}
	void first(player pl)
	{
		cout << "Кажется, бармен не заметил этого" << endl;
		pl.stick = true;
		location5_magazine00(pl);
	}
	void second(player pl)
	{
		cout << "В ней нет толку..." << endl;
		location5_magazine00(pl);
	}
	void third(player pl)
	{

	}
};

void location3_pubExit01(player pl)
{
	pubExit01 pub;
	bool flag{ true };
	while (flag)
	{
		pub.intro();
		pub.choice(pl);
		int cas;
		cin >> cas;
		switch (cas)
		{
		case 1:
			system("cls");
			pub.first(pl);
			flag = false;
			break;
		case 2:
			system("cls");
			pub.second(pl);
			flag = false;
			break;
		}
	}
}

class pubExit00 : public location
{
public:
	void intro()
	{
		cout << "- Я не знаю, возможно они вышли подышать свежим воздухом, а пока ты не ушел можешь, можешь помочь со стаканами?" << endl;
	}
	void choice(player pl)
	{
		cout << "\nВыберите действие:\n1. Послать бармена куда подальше\n2. Отказаться и пойти искать своих друзей на улицу\n3. Украсть стакан и выбежать" << endl;
	}
	void first(player pl)
	{
		cout << "Бармен прогнал тебя из бара" << endl;
		location5_magazine00(pl);
	}
	void second(player pl)
	{
		cout << "- Какой же некультурный человек!" << endl;
		location5_magazine00(pl);
	}
	void third(player pl)
	{
		cout << "- А ну стой, подлец!" << endl;
		pl.glass = true;
		pl.impudence++;
		location5_magazine00(pl);
	}
};

void location2_PubExit00(player pl)
{
	pubExit00 pub;
	bool flag{ true };
	while (flag)
	{
		pub.intro();
		pub.choice(pl);
		int cas;
		cin >> cas;
		switch (cas)
		{
		case 1:
			system("cls");
			pub.first(pl);
			flag = false;
			break;
		case 2:
			system("cls");
			pub.second(pl);
			flag = false;
			break;
		case 3:
			system("cls");
			pub.third(pl);
			flag = false;
			break;
		}
	}
}

class pub : public location
{
public:
	void intro()
	{
		cout << "Проснувшись в пабе, ты(Том О’Нил) не можешь вспомнить ничего, кроме того, что ты - Ирландец\nЗамечаешь, что рядом нету твоих друзей, с которыми ты веселился всю ночь, перед тобой, протирает стаканы бармен\nРядом сидят посетители и разговаривают вполголоса" << endl;
	}
	void choice(player pl)
	{
		cout << "\nВыберите действие:\n1. Спросить бармена куда делись твои друзья\n2. Пойти искать своих друзей на улицу\n3. Спросить у других посетителей" << endl;
	}
	void first(player pl)
	{
		cout << "Ты решаешься спросить у бармена про друзей и получаешь ответ:" << endl;
		location2_PubExit00(pl);
	}
	void second(player pl)
	{
		cout << "Направляешься к выходу и замечаешь у двери палку от швабры" << endl;
		location3_pubExit01(pl);
	}
	void third(player pl)
	{
		cout << "Ты поворачиваешься к посетителям и собираешься спросить их про друзей." << endl;
		location4_PubExit02(pl);
	}
};

void location1_Pub(player pl)
{
	pub pub;
	bool flag{ true };
	while (flag)
	{
		system("cls");
		pub.intro();
		pub.choice(pl);
		int cas;
		cin >> cas;
		switch (cas)
		{
		case 1:
			system("cls");
			pub.first(pl);
			flag = false;
			break;
		case 2:
			system("cls");
			pub.second(pl);
			flag = false;
			break;
		case 3:
			system("cls");
			pub.third(pl);
			flag = false;
			break;
		}
	}
}

void location00_MenuHelp(player pl)
{
	bool flag{ true };
	while (flag)
	{
		system("cls");
		cout << "Приветствую тебя, мой друг \nВ этой игре тебе предстоит вместе со старым Ирландцем Томом О’Нилом вместе разобраться с происходящими вокруг вас чудесами, удачи:)" << endl;
		cout << "Для выбора действий необходимо вводить номер команды, варианты появятся на экране(например: 1, 2, 3, ...) и затем клавишу ENTER" << endl;
		cout << "\nВыберите действие: \n1. Начать игру \n2. Помощь \n3. Выход" << endl;
		int cas;
		cin >> cas;
		switch (cas)
		{
		case 1:
			location1_Pub(pl);
			flag = false;
			break;
		case 2:
			location00_MenuHelp(pl);
			flag = false;
			break;
		case 3:
			exit(0);
			flag = false;
			break;
		}
	}
}

void location0_Menu()
{
	player pl;
	bool flag{true};
	while (flag)
	{
		system("cls");
		int cas;
		cout << "\nВыберите действие: \n1. Начать игру \n2. Помощь \n3. Выход" << endl;
		cin >> cas;
		switch (cas)
		{
		case 1:
			location1_Pub(pl);
			flag = false;
			break;
		case 2:
			location00_MenuHelp(pl);
			flag = false;
			break;
		case 3:
			exit(0);
			flag = false;
			break;
		}
	}
}

void main()
{
	setlocale(LC_ALL, "Russian");
	location0_Menu();

}