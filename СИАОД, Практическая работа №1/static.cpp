#include <iostream>
#include <locale>
#include <string>


using namespace std;

long arr[1000];
int n = 0;

void create(long* arr, int n); //Создаем новый массив (из большого массива просто берем часть длиной n)
void show(long* arr, int n);//Вывод масссива на экран
void insert_after(long* arr, int &n);
void deleting(long* arr, int &n);
bool all_digits_divisibility(int number);
bool div3(int number);
void show_index(long* arr, int n);
void del_even(long* arr, int& n);

int main() {
	setlocale(LC_ALL, "Russian");
	string stop = "\n----------------------------------------------------------------------------\n";
	int problem, flag = 1;
	int index;
	int element;

	while (flag)
	{
		system("cls"); //Команда, очищающая консоль
		cout << "Практическая работа №1 ИКБО-03-21 Поведенок С.С. Варинат 22" << "\n\n" //Вывод меню
			"Задание 1\n"
			"Меню\n"
			"1) Заполнить массив.\n"
			"2) Вывести массив.\n"
			"3) Очистить массив.\n"
			"4) Найти индекс элемента массива значение которого делится на каждую из цифр числа.\n"
			"5) Вставить в массив новый элемент после элемента, значение которого делится на каждую цифру значения.\n"
			"6) Удалить из массива все элементы, кратные трём.\n"
			"7) Выход из программы.\n"
			"8) Удалить из массива все чётные элементы\n";
		cout << "Ваш выбор: ";
		cin >> problem; //Ввод задания
		switch (problem) {
		case 1:
			
			cout << "Введите количество элементов в массиве: ";
			cin >> n;
			while (n < 1 || n > 1000)
			{
				cout << "Длина массива не должна быть меньше 1 или больше 1000. Пожалуйста, попробуйте ещё раз.\n";
				cin.clear();
				cin.ignore();
				cout << "Введите количество элементов в массиве: ";
				cin >> n;
			}
			cout << "Введите элементы массива: ";
			create(arr, n);
			system("pause"); //Ставит программу на паузу, пока не будет нажата клавиша
			break;
		case 2:
			cout << "Вывод массива \n";
			show(arr, n);
			system("pause");
			break;
		case 3:
			n = 0;
			cout << "Массив сброшен.\n";
			system("pause");
			break;
		case 4:
			show_index(arr, n);
			system("pause");
			break;
		case 5:
			insert_after(arr, n);
			system("pause");
			break;
		case 6:
			deleting(arr, n);
			show(arr, n);
			system("pause");
			break;
		case 7:
			cout << "Спасибо, до свидания!" << stop;
			flag = 0;
			break;
		case 8:
			del_even(arr, n);
			show(arr, n);
			system("pause");
			break;
		default:
			cout << "Извините, я не совсем понимаю, что вы хотите сделать. Попробуйте в другой раз." << stop;
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
		cout << "Массив пуст\n";
	}
	else {
		for (int i = 0; i < n; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}
}

void insert_after(long* arr, int &n)
{
	if (n == 0)
	{
		cout << "Невозможно выполнить операцию, так как массив пуст.\n";
	}
	else
	{
		cout << "Вставка в массив нового элемента после элемента, значение которого делится на каждую цифру значения.\n";
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
			cout << "Введите значение нового элемента: ";
			cin >> element;
			for (int i = n - 1; i > index; i--) {
				arr[i + 1] = arr[i];
			}
			arr[index + 1] = element;
			n++;
			show(arr, n);
		}
		else
		{
			cout << "В массиве не нашлось элемента, значение которого делится на каждую цифру значения.\n";
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

void del_even(long* arr, int& n)
{
	if (n == 0)
	{
		cout << "Не удалось выполнить операцию, так как массив пуст.\n";
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			if (arr[i] % 2 == 0)
			{
				arr[i] = arr[i + 1];
				n--;
				i--;
			}
		}
		cout << "Из массива удалены все чётные элементы.\n";
	}
}

void show_index(long* arr, int n)
{
	if (n == 0)
	{
		cout << "Массив пуст, невозможно выполнить команду.\n";
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
			cout << "В массиве не нашлось элементов, занчение которых делится на каждую из цифр числа.\n";
		}
		else {
			cout << "Индекс элемента массива значение которого делится на каждую из цифр числа: " << index << endl;
		}
	}
	
}

void deleting(long* arr, int &n)
{
	if (n == 0)
	{
		cout << "Не удалось выполнить операцию, так как массив пуст.\n";
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			if (div3(arr[i]))
			{
				for (int j = i; j < n; j++)
				{
					arr[j] = arr[j + 1];
				}
				n--;
				i--;
			}
		}
		cout << "Из массива удалены все элементы, кратные трём.\n";
	}
}
