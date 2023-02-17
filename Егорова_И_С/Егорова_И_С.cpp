

#include <iostream>
#include <windows.h>
#include <string>

using namespace std;

struct Date {
	unsigned short day;
	unsigned short month;
	unsigned short year;
};

struct Record
{
	char type[17];
	char route[12];
	float lengthroute;
	unsigned short time;
	struct Date date;
};


void myCentr(string s, int wLine) {

	int w = s.length();
	int delta = (wLine - w) / 2;
	cout << left;
	cout.width(delta); cout << " ";
	cout << s;
	cout.width(delta + 1); cout << " ";

}

void printDate(unsigned short day, unsigned short month, unsigned short year, int wLine) {
	int w = 10;
	int delta = (wLine - w) / 2 - 1;
	cout << left;
	cout.width(delta); cout << " ";
	if (day > 9) {
		cout << day;
	}
	else {
		cout << "0" << day;
	}
	cout << ".";
	if (month > 9) {
		cout << month;
	}
	else {
		cout << "0" << month;
	}
	cout << ".";
	cout << year;
	cout.width(delta); cout << " ";
}

void Draw(struct Record* records) {
	cout << endl;	cout.width(92); cout.fill('-'); cout << "-" << endl;
	cout.fill(' '); cout.width(91);  cout << left << "| Ведомость общественного транспорта"; cout << "|" << endl;
	cout.width(92); cout.fill('-'); cout << "-" << endl;
	cout.fill(' ');
	cout << left << "| Вид транспорта ";
	cout << left << "| Маршрут";
	cout << left << "| Протяженность маршрута (км)";
	cout << left << "| Время в дороге (мин)";
	cout << left << " | Дата       ";
	cout << "|" << endl;
	cout.width(92); cout.fill('-'); cout << "-" << endl;
	cout.fill(' ');
	for (int i = 0; i < 3; i++) {
		cout << left << "|"; cout.width(16); cout << left << records[i].type;
		cout << left << "|"; cout.width(8); cout << left << records[i].route;
		cout << left << "|"; cout.width(28); cout << left << records[i].lengthroute;
		std::cout.precision(2);
		cout << left << "|"; cout.width(22); cout << left << fixed << records[i].time;
		cout << left << "|";
		printDate(records[i].date.day, records[i].date.month, records[i].date.year, 11);
		cout << "|" << endl;
	}
	cout.width(92); cout.fill('-'); cout << "-" << endl;
	cout.fill(' '); cout.width(91);  cout << left << "|Примечание: Тр - трамвай, Тс - троллейбус, А - автобус "; cout << "|" << endl;
	cout.width(92); cout.fill('-'); cout << "-" << endl;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	struct Record records[10];

	records[0] = { "Тр.", "12", 27.550, 75, {03,04,2022} };
	records[1] = { "Т-с", "17", 13.600, 57, {03,04,2020} };
	records[2] = { "А", "12а", 57.300, 117, {04,03,2022} };

	Draw(records);
}