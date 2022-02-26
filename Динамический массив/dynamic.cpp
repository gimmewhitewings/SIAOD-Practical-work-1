#include <iostream>
#include <locale>
#include <string>


using namespace std;

int n = 0;

void create(long* arr, int n); //���������� ������������� �������
void show(long* arr, int n);//����� �������� �� �����
long* insert_after(long* arr, int &n);
long* deleting(long* arr, int &n);
bool all_digits_divisibility(int number);
bool div3(int number);
void show_index(long* arr, int n);

int main() {
	setlocale(LC_ALL, "Russian");
	string stop = "\n----------------------------------------------------------------------------\n";
	int problem, flag = 1;
	int element = 0;
	long* arr = NULL;

	while (flag)
	{
		system("cls"); //�������, ��������� �������
		cout << "������������ ������ �1 ����-03-21 ��������� �.�. ������� 22" << "\n\n" //����� ����
			"������� 2\n"
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
			arr = new long[n];
			cout << "������� �������� �������: ";
			create(arr, n);
			system("pause"); //������ ��������� �� �����, ���� �� ����� ������ �������
			break;
		case 2:
			cout << "����� �������.\n";
			show(arr, n);
			system("pause");
			break;
		case 3:
			delete[] arr;
			n = 0;
			cout << "������ �������.\n";
			system("pause");
			break;
		case 4:
			show_index(arr, n);
			system("pause");
			break;
		case 5:
			arr = insert_after(arr, n);
			system("pause");
			break;
		case 6:
			arr = deleting(arr, n);
			show(arr, n);
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


void create(long* arr, int n)
{
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
}

void show(long* arr, int n)
{
	if (n == 0) {
		cout << "������ ����\n";
	}
	else {
		for (int i = 0; i < n; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}
}

long* insert_after(long* arr, int &n)
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
			if (all_digits_divisibility(arr[i])) {
				index = i;
			}
		}
		if (index != -1)
		{
			int element;
			cout << "������� �������� ������ ��������: ";
			cin >> element;
			arr = (long*)realloc(arr, (n + 1) * sizeof(long));
			n++;
			for (int i = n; i > index + 1; i--) {
				arr[i] = arr[i - 1];
			}
			arr[index + 1] = element;
			show(arr, n);
		}
		else
		{
			cout << "� ������� �� ������� ��������, �������� �������� ������� �� ������ ����� ��������.\n";

		}
	}
	return arr;
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


void show_index(long* arr, int n)
{
	if (n == 0)
	{
		cout << "������ ����, ���������� ��������� �������.\n";
	}
	else {
		int index = -1;
		for (int i = 0; i < n; i++)
		{
			if (all_digits_divisibility(arr[i])) {
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

long* deleting(long* arr, int &n)
{
	if (n == 0)
	{
		cout << "�� ������� ��������� ��������, ��� ��� ������ ����.\n";
	}
	else
	{
		if (arr != NULL)
		{
			for (int i = 0; i < n; i++)
			{
				if (div3(arr[i]))
				{
					for (int j = i; j < n; j++)
					{
						arr[j] = arr[j + 1];
					}
					arr = (long*)realloc(arr, (n - 1) * sizeof(long));
					n--;
					i--;
				}
			}
		}
		cout << "�� ������� ������� ��� ��������, ������� ���.\n";
	}
	if (n != 0)
	{
		return arr;
	}
	return NULL;
}
