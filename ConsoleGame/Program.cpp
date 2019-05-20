#include <iostream>
#include <string>

using namespace std;
// 
class enemy
{
public:
	virtual int attackGlass() = 0;
	virtual int attackStick() = 0;
};
class policeman : enemy
{
public:
	int xp = 250;
	int attackGlass() 
	{
		cout << "���� ������� 200 ����� ������������" << endl;
		return 200;
	}
	int attackStick()
	{
		cout << "���� ������� 50 ����� ������������" << endl;
		return 50;
	}
};
class player // stats and inventory
{
public:
	int impudence = 0;
	bool glass = false;
	bool glassStat = false;
	bool stick = false;
	bool stickStat = false;
};
class location
{
public:
	virtual void intro() = 0;
	virtual void choice() = 0;
	virtual void first(player pl) = 0;
	virtual void second(player pl) = 0;
	virtual void third(player pl) = 0;
};
//

///
void printStats(player pl)
{
	cout << "����������:" << endl;
	cout << "�������� ����: " << pl.impudence << endl;
	cout << "����������:" << endl;
	if (pl.glassStat)
		cout << "����� ������ �� ����" << endl;
	if (pl.stickStat)
		cout << "����� ����� �� ������ �� ����" << endl;
	cout << "\n" << "�� ������� �����:\n����� ����� - Green Crow" << endl;
	system("pause");
}
void GameOver(player pl)
{
	cout << '\n';
	cout << "���� ��������\n�� ��������" << endl;
	cout << '\n';
	printStats(pl);
}
void Win(player pl)
{
	cout << '\n';
	cout << "���� ��������\n�� �������" << endl;
	cout << '\n';
	printStats(pl);
}
///

class end00 : public location
{
public:
	void intro()
	{
		cout << "����������� ����� ��� ��������, � ��� ������, ���\n������� ��������� ����, �������� ������, ����� �����!\n� ���� ���������� �����\n����� � ���, ������� ���, � ������ ����� �����!\n����� ������, ��� �����. �� �� ����� ����� - �����\n�� ���-�� �� ���� ���������, ������ �����" << endl;
	}
	void choice()
	{
		cout << "\n�������� ��������:\n1. ����������" << endl;
	}
	void first(player pl)
	{
		cout << "������ ����� - ��������... �� ��� ������ � � ������� ����\n��� ��� ��� ���\n������ ������� � ������, � ����� ������ ���!" << endl;
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
		pub.choice();
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

class Pit
{
public:
	void intro(policeman pol)
	{
		cout << "�������� ������������: " << pol.xp << endl;
	}
	void choice00()
	{		
		cout << "\n�������� ��������:\n1. ���������� ������� ������ �� ����" << endl;
	}
	void choice01()
	{
		cout << "\n�������� ��������:\n1. ���������� ������� ������ �� ����\n2. ������ ������, ������ �� ����, ��� � ������\n3. ������� ������ ������ ������ ��" << endl;		
	}
	void choice02()
	{
		cout << "\n�������� ��������:\n1. ���������� ������� ������ �� ����\n2. ������ ������, ������ �� ����, ��� � ������" << endl;
	}
	void choice03()
	{
		cout << "\n�������� ��������:\n1. ���������� ������� ������ �� ����\n2. ������� ��� ������" << endl;
	}
	void first(player pl, policeman pol)
	{
		if (pol.xp > 0 && (!pl.glass || !pl.stick)) {
			cout << "��� �� ������� ��� ������� ������������\n���� � ���� �������� � ������� � �������" << endl;
			GameOver(pl);
		}
		else if (pol.xp == 0 || pol.xp < 0)
			Win(pl);
		

	}
	void second00(player pl, policeman &pol)
	{
		pol.xp -= pol.attackGlass();		
		if (pol.xp == 0)
			location7_End00(pl);
	}
	void second01(player pl, policeman &pol)
	{
		pol.xp -= pol.attackStick();
		if (pol.xp == 0)
			location7_End00(pl);
	}
	void third(player pl)
	{

	}
};

void location6_Pit(player pl, policeman pol)
{
	Pit pub;	
	bool flag{ true };
	while (flag)
	{
		if (pol.xp < 0 || pol.xp == 0)
			flag = false;
		if(pol.xp != 0)
		{
		pub.intro(pol);
			if (!pl.glass && !pl.stick) {
				pub.choice00();
				int cas;
				cin >> cas;
				switch (cas)
				{
				case 1:
					flag = false;
					system("cls");
					pol.xp -= 50;
					pub.first(pl, pol);
					break;
				}
			}
		else if (pl.glass && pl.stick) {
			pub.choice01();
			int cas;
			cin >> cas;
			switch (cas)
			{
			case 1:
				flag = false;
				system("cls");
				pol.xp -= 50;
				pub.first(pl, pol);
				break;
			case 2:
				flag = false;
				system("cls");
				pub.second00(pl, pol);
				pl.glass = false;
				location6_Pit(pl, pol);
				break;
			case 3:
				flag = false;
				system("cls");
				pub.second01(pl, pol);
				pl.stick = false;
				location6_Pit(pl, pol);
				break;
			}
		}
		else if (pl.glass) {
			pub.choice02();
			int cas;
			cin >> cas;
			switch (cas)
			{
			case 1:
				flag = false;
				system("cls");
				pol.xp -= 50;
				pub.first(pl, pol);
				break;
			case 2:
				flag = false;
				system("cls");
				pub.second00(pl, pol);
				pl.glass = false;
				location6_Pit(pl, pol);
				break;
			}
		}
		else if (pl.stick) {
				pub.choice03();
				int cas;
				cin >> cas;
				switch (cas)
				{
				case 1:
					flag = false;
					system("cls");
					pol.xp -= 50;
					pub.first(pl, pol);
					break;
				case 2:
					flag = false;
					system("cls");
					pub.second01(pl, pol);
					pl.stick = false;
					location6_Pit(pl, pol);
					break;
				}
			}
		}		
	}
}

class magazine00 : public location
{
public:
	void intro()
	{
		cout << "����� �� ����� �� ����� �� ��������� � ����� �����\n� ������ �������� �����-�� ������\n��� ������� ���������� ����\n� � ���������� ���� ��� ����� ����� �����\n� �������� ������ ��������: \"��� ���� ������� � ������\"" << endl;
	}
	void choice()
	{
		cout << "\n�������� ��������:\n1. �������� �� ��� ����� � ������� ����� ����� ������\n2. ����������� �� ������ � �������� ������" << endl;
	}
	void first(player pl)
	{
		if(pl.impudence == 1)
		cout << "�� ������� �� ���� ����� � � ������ ������� ����� ���� ������ � �����. ��� ���.\n���� �� ��� �������� ����� ������� - �����\n�� ����� �������. ���� � ������ �������� ����� �������� ������\n����������� �� ����, �� �������� �� �����, �������� �� ����� � ���������� �������� ����" << endl;
		else if (pl.impudence == 0)
			cout << "������� �� �� ��������� ������ � ����������� �������\n�� �� ����. ������ ���� ����� �� ����� ������\n���� �� ��� �������� ����� ������� - �����\n�� ����� �������. ���� � ������ �������� ����� �������� ������\n����������� �� ����, �� �������� �� �����, �������� �� ����� � ���������� �������� ����" << endl;
		policeman pol;
		location6_Pit(pl, pol);
	}
	void second(player pl)
	{
		cout << "������ ���� ����� �� �������� ������\n���� �� ��� �������� ����� ������� - �����\n�� ����� �������. ���� � ������ �������� ����� �������� ������\n����������� �� ����, �� �������� �� �����, �������� �� ����� � ���������� �������� ����" << endl;
		policeman pol;
		location6_Pit(pl, pol);
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
		mag.choice();
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

class loc2Cont : public location
{
public:
	void intro()
	{
		cout << "������� ���� ����� �� ��������� ����������� ����� �� ������" << endl;
	}
	void choice()
	{
		cout << "\n�������� ��������:\n1. ������� � �����\n2. �� �����" << endl;
	}
	void first(player pl)
	{
		cout << "\"�� ��������� �� �����\" - �� �������" << endl;
		pl.stick = true;
		pl.stickStat = true;
		location5_magazine00(pl);
	}
	void second(player pl)
	{
		cout << "\"������� ��� �� ����\" - �� �������" << endl;
		location5_magazine00(pl);
	}
	void third(player pl)
	{

	}
};

void location2Continue(player pl)
{
	loc2Cont pub;
	bool flag{ true };
	while (flag)
	{
		pub.intro();
		pub.choice();
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

class pubExit02 : public location
{
public:
	void intro()
	{
		cout << "�� ���� ������� ��������� ���, ��� �� �������, ��� �� �����?\n���� � �������� ������� ��� � ����� ������ ����-�-����. ����� ���������� ���������� � � ����� ������� ��������\n��� ���������� ���� ����� ���" << endl;
	}
	void choice()
	{
		cout << "\n�������� ��������:\n1. �� �� ���� �� ���� �������?!?! �������� ������ � ����\n2. �����������" << endl;
	}
	void first(player pl)
	{
		cout << "������ �������, ��� ����������? - ������� ���" << endl;
		location5_magazine00(pl);
	}
	void second(player pl)
	{
		cout << "����� ������� ����� �� �������� � ���� ��� � ����������� ��� ������ �������� ����. �� ������ �� ��������" << endl;
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
		pub.choice();
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
	void choice()
	{
		cout << "\n�������� ��������:\n1. ����� �����\n2. �� ����� �����" << endl;
	}
	void first(player pl)
	{
		cout << "�������, ������ �� ������� �����" << endl;
		pl.stick = true;
		pl.stickStat = true;
		location5_magazine00(pl);
	}
	void second(player pl)
	{
		cout << "� ��� ��� �����..." << endl;
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
		pub.choice();
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
		cout << "- � �� ����, �������� ��� ����� �������� ������ ��������, � ���� �� �� ���� ������, ������ ������ �� ���������?" << endl;
	}
	void choice()
	{
		cout << "\n�������� ��������:\n1. ������� ������� ���� ��������\n2. ���������� � ����� ������ ����� ������ �� �����\n3. ������� ������ � ��������" << endl;
	}
	void first(player pl)
	{
		cout << "������ ������� ���� �� ����" << endl;
		location2Continue(pl);
	}
	void second(player pl)
	{
		cout << "- ����� �� ������������ �������!" << endl;
		location2Continue(pl);
	}
	void third(player pl)
	{
		cout << "- � �� ����, ������!" << endl;
		pl.glass = true;
		pl.glassStat = true;
		pl.impudence++;
		location2Continue(pl);
	}
};

void location2_PubExit00(player pl)
{
	pubExit00 pub;
	bool flag{ true };
	while (flag)
	{
		pub.intro();
		pub.choice();
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
		cout << "����������� � ����, ��(��� Β���) �� ������ ��������� ������, ����� ����, ��� �� - ��������\n���������, ��� ����� ���� ����� ������, � �������� �� ��������� ��� ����, ����� �����, ��������� ������� ������\n����� ����� ���������� � ������������� ����������" << endl;
	}
	void choice()
	{
		cout << "\n�������� ��������:\n1. �������� ������� ���� ������ ���� ������\n2. ����� ������ ����� ������ �� �����\n3. �������� � ������ �����������" << endl;
	}
	void first(player pl)
	{
		cout << "�� ��������� �������� � ������� ��� ������ � ��������� �����:" << endl;
		location2_PubExit00(pl);
	}
	void second(player pl)
	{
		cout << "������������� � ������ � ��������� � ����� ����� �� ������" << endl;
		location3_pubExit01(pl);
	}
	void third(player pl)
	{
		cout << "�� ��������������� � ����������� � ����������� �������� �� ��� ������." << endl;
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
		pub.choice();
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
		cout << "����������� ����, ��� ���� \n� ���� ���� ���� ��������� ������ �� ������ ��������� ����� Β����� ������ ����������� � ������������� ������ ��� ��������, �����:)" << endl;
		cout << "��� ������ �������� ���������� ������� ����� �������, �������� �������� �� ������(��������: 1, 2, 3, ...) � ����� ������� ENTER" << endl;
		cout << "\n�������� ��������: \n1. ������ ���� \n2. ������ \n3. �����" << endl;
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
		cout << "\n�������� ��������: \n1. ������ ���� \n2. ������ \n3. �����" << endl;
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