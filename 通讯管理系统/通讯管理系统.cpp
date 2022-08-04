#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
using namespace std;
#define MAX 1000

struct Person
{
	string m_Name;
	int m_Sex;           //1 or 2
	int m_Age;
	string m_Phone;
	string m_Addr;
};

struct Addressbooks
{
	struct Person personArray[MAX];
	int m_Size;
};

void showMenu()
{
	cout << "*************************" << endl;
	cout << "***** 1�������ϵ�� *****" << endl;
	cout << "***** 2����ʾ��ϵ�� *****" << endl;
	cout << "***** 3��ɾ����ϵ�� *****" << endl;
	cout << "***** 4��������ϵ�� *****" << endl;
	cout << "***** 5���޸���ϵ�� *****" << endl;
	cout << "***** 6�������ϵ�� *****" << endl;
	cout << "***** 0���˳�ͨѶ¼ *****" << endl;
	cout << "*************************" << endl;
}

void addPerson(Addressbooks* abs)
{
	if (abs->m_Size == MAX)
	{
		cout << "ͨѶ¼�������޷����" << endl;
		return;
	}
	else
	{
		string name;
		cout << "����������" << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;
		//
		cout << "�������Ա�" << endl;
		cout << "1 --- ��" << endl
			<< "2 --- Ů" << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "������������������" << endl;
		}
		//
		cout << "����������" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[abs->m_Size].m_Age  = age;
		//
		cout << "��������ϵ�绰" << endl;
		string phone;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone  = phone;
		//
		cout << "�������ͥסַ" << endl;
		string address;
		cin >> address;
		abs->personArray[abs->m_Size].m_Addr = address;
		//
		abs->m_Size++;
		cout << "��ӳɹ�" << endl;
		system("pause");
		system("cls");
	}
}
void showPerson(Addressbooks* abs)
{
	if (abs->m_Size == 0)
	{
		cout << "��ǰ��¼Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "����:" << abs->personArray[i].m_Name << endl;
			cout << "�Ա�:" << abs->personArray[i].m_Sex << endl;
			cout << "����:" << abs->personArray[i].m_Age << endl;
			cout << "�绰:" << abs->personArray[i].m_Phone << endl;
			cout << "סַ:" << abs->personArray[i].m_Addr << endl;
		}
	}
	system("pause");
	system("cls");
}
int main()
{
	Addressbooks abs;
	abs.m_Size = 0;
	int select = 0;
	while (true)
	{
		showMenu();
		cin >> select;
		switch (select)
		{
		case 1:
			addPerson(&abs);
			break;
		case 2:
			showPerson(&abs);
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 0:
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
			break;
		}
	}
	system("pause");
	return 0;
}