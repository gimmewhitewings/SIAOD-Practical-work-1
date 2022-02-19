#include <iostream>
#include <locale>
#include <string>
#include <vector>

using namespace std;

int n = 0;

void create(vector<long>& vec, int n); //���������� ������������� �������
void show(vector<long> vec, int n);//����� �������� �� �����
void insert_after(vector<long>& vec, int& n);
void deleting(vector<long>& vec, int& n);
bool all_digits_divisibility(int number);
bool div3(int number);
void show_index(vector<long> vec, int n);

int main() {
	setlocale(LC_ALL, "Russian");
	string stop = "\n----------------------------------------------------------------------------\n";
	vector<long> vec;
	int problem, flag = 1;
	int element;

	while (flag)
	{
		system("cls"); //�������, ��������� �������
		cout << "������������ ������ �1 ����-03-21 ��������� �.�. ������� 22" << "\n\n" //����� ����
			"������� 1\n"
			"����\n"
			"1) ��������� ������.\n"
			"2) ������� ������.\n"
			"3) �������� ������.\n"
			"4) ����� ������ �������� ������� �������� �������� ������� �� ������ �� ���� �����.\n"
			"5) �������� � ������ ����� ������� ����� ��������, �������� �������� ������� �� ������ ����� ��������.\n"
			"6) ������� �� ������� ��� ��������, ������� ���.\n"
			"7) ����� �� ���������.\n";
		cout << "��� �����: ";
		cin >> problem; //���� �������
		switch (problem) {
		case 1:
			cout << "������� ���������� ��������� � �������: ";
			cin >> n;
			while (n < 1)
			{
				cout << "����� ������� �� ������ ���� ������ 1. ����������, ���������� ��� ���.\n";
				cin.clear();
				cin.ignore();
				cout << "������� ���������� ��������� � �������: ";
				cin >> n;
			}
			vec.resize(n);
			cout << "������� �������� �������: ";
			create(vec, n);
			system("pause"); //������ ��������� �� �����, ���� �� ����� ������ �������
			break;
		case 2:
			cout << "����� �������.\n";
			show(vec, n);
			system("pause");
			break;
		case 3:
			n = 0;
			cout << "������ �������.\n";
			system("pause");
			break;
		case 4:
			show_index(vec, n);
			system("pause");
			break;
		case 5:
			insert_after(vec, n);
			system("pause");
			break;
		case 6:
			deleting(vec, n);
			show(vec, n);
			system("pause");
			break;
		case 7:
			cout << "�������, �� ��������!" << stop;
			flag = 0;
			break;
		default:
			cout << "��������, � �� ������ �������, ��� �� ������ �������. ���������� � ������ ���." << stop;
			system("pause");
		}
	}
}

void create(vector<long>& vec, int n)
{
	for (int i = 0; i < n; i++) {
		cin >> vec[i];
	}
}

void show(vector<long> vec, int n)
{
	if (n == 0) {
		cout << "������ ����\n";
	}
	else {
		for (int i = 0; i < n; i++) {
			cout << vec[i] << " ";
		}
		cout << endl;
	}
}

void insert_after(vector<long>& vec, int& n)
{
	if (n == 0)
	{
		cout << "���������� ��������� ��������, ��� ��� ������ ����.\n";
	}
	else
	{
		cout << "������� � ������ ������ �������� ����� ��������, �������� �������� ������� �� ������ ����� ��������.\n";
		int index = -1;
		for (int i = 0; i < n; i++)
		{
			if (all_digits_divisibility(vec[i])) {
				index = i;
			}
		}
		if (index != -1)
		{
			int element;
			cout << "������� �������� ������ ��������: ";
			cin >> element;
			vec.insert(vec.begin() + index + 1, element);
			n++;
			show(vec, n);
		}
		else
		{
			cout << "� ������� �� ������� ��������, �������� �������� ������� �� ������ ����� ��������.\n";
		}
	}
}

bool all_digits_divisibility(int number)
{
	bool flag = true;
	string str = to_string(number);
	for (int i = 0; i < str.length(); i++)
	{
		char digit = (int)str[i] - 48;
		if (digit == -3)
		{
			continue;
		}
		else {
			if (digit == 0 || number % digit != 0)
			{
				return false;
			}
		}
	}
	return true;
}

bool div3(int number)
{
	if (number % 3 == 0) {
		return true;
	}
	return false;
}

int find_index(vector<long> vec, int n)
{
	for (int i = 0; i < n; i++)
	{
		if (all_digits_divisibility(vec[i])) {
			return i;
		}
	}
	return -1;
}

void show_index(vector<long> vec, int n)
{
	if (n == 0)
	{
		cout << "������ ����, ���������� ��������� �������.\n";
	}
	else {
		int index = -1;
		for (int i = 0; i < n; i++)
		{
			if (all_digits_divisibility(vec[i])) {
				index = i;
			}
		}
		if (index == -1)
		{
			cout << "� ������� �� ������� ���������, �������� ������� ������� �� ������ �� ���� �����.\n";
		}
		else {
			cout << "������ �������� ������� �������� �������� ������� �� ������ �� ���� �����: " << index << endl;
		}
	}
}

void deleting(vector<long>& vec, int& n)
{
	if (n == 0)
	{
		cout << "�� ������� ��������� ��������, ��� ��� ������ ����.\n";
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			if (div3(vec[i]))
			{
				vec.erase(vec.begin() + i);
				i--;
				n--;
			}
		}
		cout << "�� ������� ������� ��� ��������, ������� ���.\n";
	}
}
