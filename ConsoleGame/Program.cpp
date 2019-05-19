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
	cout << "����������:" << endl;
	cout << "�������� ����: " << pl.impudence << endl;
	cout << "����������:" << endl;
	if (pl.glass)
		cout << "����� ������ �� ����" << endl;
	if (pl.stick)
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
		cout << "������� ��������� ����, �������� ������, ����� �����!\n� ���� ���������� �����\n����� � ���, ������� ���, � ������ ����� �����!\n����� ������, ��� �����. �� �� ����� ����� - �����\n�� ���-�� �� ���� ���������, ������ �����" << endl;
	}
	void choice(player pl)
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
		cout << "���� �� ��� �������� ����� ������� - �����\n�� ����� �������. ���� � ������ �������� ����� �������� ������\n����������� �� ����, �� �������� �� �����, �������� �� ����� � ���������� �������� ����" << endl;
	}
	void choice(player pl)
	{
		if (pl.glass)
			cout << "\n�������� ��������:\n1. ���������� ������� ������ �� ����\n2. ������� ������, ������ �� ����, � ��� ������" << endl;
		else if (pl.stick)
			cout << "\n�������� ��������:\n1. ���������� ������� ������ �� ����\n2. ������� ��� ������" << endl;
		else 
			cout << "\n�������� ��������:\n1. ���������� ������� ������ �� ����" << endl;
	}
	void first(player pl)
	{
		cout << "��� �� ������� ��� ������� ������������\n���� � ���� �������� � ������� � �������" << endl;
		GameOver(pl);
	}
	void second(player pl)
	{
		cout << "�� ������� ������������ �� �����. ������� �� ��� ��������" << endl;
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
		cout << "����� �� ����� �� ����� �� ��������� � ����� �����\n� ������ �������� �����-�� ������\n��� ������� ���������� ����\n� � ���������� ���� ��� ����� ����� �����\n� �������� ������ ��������: \"��� ���� ������� � ������\"" << endl;
	}
	void choice(player pl)
	{
		cout << "\n�������� ��������:\n1. �������� �� ��� ����� � ������� ����� ����� ������\n2. ����������� �� ������ � �������� ������" << endl;
	}
	void first(player pl)
	{
		if(pl.impudence == 1)
		cout << "�� ������� �� ���� ����� � � ������ ������� ����� ���� ������ � �����. ��� ���." << endl;
		else if (pl.impudence == 0)
			cout << "������� �� �� ��������� ������ � ����������� �������\n�� �� ����. ������ ���� ����� �� ����� ������" << endl;
		location6_Pit(pl);
	}
	void second(player pl)
	{
		cout << "������ ���� ����� �� �������� ������" << endl;
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
		cout << "�� ���� ������� ��������� ���, ��� �� �������, ��� �� �����?\n���� � �������� ������� ��� � ����� ������ ����-�-����. ����� ���������� ���������� � � ����� ������� ��������\n��� ���������� ���� ����� ���" << endl;
	}
	void choice(player pl)
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
		cout << "\n�������� ��������:\n1. ����� �����\n2. �� ����� �����" << endl;
	}
	void first(player pl)
	{
		cout << "�������, ������ �� ������� �����" << endl;
		pl.stick = true;
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
		cout << "- � �� ����, �������� ��� ����� �������� ������ ��������, � ���� �� �� ���� ������, ������ ������ �� ���������?" << endl;
	}
	void choice(player pl)
	{
		cout << "\n�������� ��������:\n1. ������� ������� ���� ��������\n2. ���������� � ����� ������ ����� ������ �� �����\n3. ������� ������ � ��������" << endl;
	}
	void first(player pl)
	{
		cout << "������ ������� ���� �� ����" << endl;
		location5_magazine00(pl);
	}
	void second(player pl)
	{
		cout << "- ����� �� ������������ �������!" << endl;
		location5_magazine00(pl);
	}
	void third(player pl)
	{
		cout << "- � �� ����, ������!" << endl;
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
		cout << "����������� � ����, ��(��� Β���) �� ������ ��������� ������, ����� ����, ��� �� - ��������\n���������, ��� ����� ���� ����� ������, � �������� �� ��������� ��� ����, ����� �����, ��������� ������� ������\n����� ����� ���������� � ������������� ����������" << endl;
	}
	void choice(player pl)
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