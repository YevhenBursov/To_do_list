#include <iostream>
#include <conio.h>
#include <string>
#include <windows.h>;
#include "Array_lib.h"


using namespace std;

struct business {

    struct date {
        int day;
        int month;
        int year;
    };
    struct time {
        int hours;
        int minutes;
    };
    string name;
    int priority;
    string description;
    date date;
    time time;
};

void add_business(business* bus, int n);        // Добавить дело.
void show_all_business(business* bus, int n);       // Показать все дела.
void find_by_name(business* bus, int n, string name);       // Найти по имени.
void find_by_priority(business* bus, int n, int priority);      // Найти по приоритету.
void find_by_description(business* bus, int n, string description);     // Найти по описанию. 
void find_by_date(business* bus, int n, int day, int month, int year, int hours, int minutes);      // Найти по дату. 
void show_business_on_day(business* bus, int n, int day, int month, int year);      // Показать дела на день.
void show_business_on_week(business* bus, int n, int day, int month, int year);     // Показать дела на неделю.
void show_business_on_month(business* bus, int n, int day, int month, int year);        // Показать дела на месяц.    
void show_business_on_month(business* bus, int n, int day, int month, int year);
void show_business_on_year(business* bus, int n, int day, int month, int year);     // Показать дела на год.
void sort_by_priority(business* bus, int n);        // Сортировать по приоритету.
void sort_by_date(business* bus, int n);        // Сортировать по дате.
void edit_business(business* bus, int n, int index);        // Редактировать дело.


int main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int n = 0;


    int select;
    int del_index = 0;
    int edit_index = 0;
    int select1 = 0;

    string name;
    int priority = 0;
    string description;
    int day = 0;
    int month = 0;
    int year = 0;
    int hours = 0;
    int minutes = 0;


    business* bus = new business[999999];


    do {
        cout << "Чтобы добавить запись в список дел, нажмите 1..." << endl;
        cout << "Чтобы удалить запись из списка дел, нажмите 2..." << endl;
        cout << "Чтобы редактировать запись из списка дел, нажмите 3..." << endl;
        cout << "Чтобы найти запись в списке дел, нажмите 4..." << endl;
        cout << "Чтобы отобразить все записи из списка дел, нажмите 5..." << endl;
        cout << "Чтобы отобразить все записи из списка дел по приоритету нажмите 6..." << endl;
        cout << "Чтобы отобразить все записи из списка дел по дате нажмите 7..." << endl;
        cout << endl;
        cout << endl;
        cout << "Информация об авторе, нажмите 0..." << endl;
        cout << endl;
        cout << "Ваш выбор: ";
        cin >> select;


        system("cls");
        switch (select) {
        case 1:
            cout << "Сколько записей хотите внести?" << endl;
            cout << "Ваш выбор: ";
            cin >> n;
            system("cls");

            add_business(bus, n);
            cout << "Запись создана!" << endl;
            system("pause");
            system("cls");
            break;

        case 2:
            cout << "Введите номер записи, которую нужно удалить: " << endl;
            show_all_business(bus, n);
            cin >> del_index;
            delElement(bus, n, del_index);
            cout << "Запись удалена!" << endl;
            system("pause");
            system("cls");
            break;
        case 3:
            cout << "Введите номер записи, которую нужно редактировать: " << endl;
            show_all_business(bus, n);
            cout << "Ваш выбор: ";
            cin >> edit_index;
            edit_business(bus, n, edit_index);
            cout << "Запись отредактирована!" << endl;
            system("pause");
            system("cls");
            break;
        case 4:
            cout << "Чтобы найти дело по названию, нажмите 1..." << endl;
            cout << "Чтобы найти дело по приоритету, нажмите 2..." << endl;
            cout << "Чтобы найти дело по описанию, нажмите 3..." << endl;
            cout << "Чтобы найти дело по дате и времени, нажмите 4..." << endl;
            cout << "Ваш выбор: ";
            cin >> select1;
            system("cls");
            switch (select1) {
            case 1:
                cout << "Введите название дела: ";
                cin.ignore();
                getline(cin, name);
                find_by_name(bus, n, name);
                system("pause");
                system("cls");
                break;
            case 2:
                cout << "Введите приоритет: ";
                cin >> priority;
                find_by_priority(bus, n, priority);
                system("pause");
                system("cls");
                break;
            case 3:
                cout << "Введите описание: ";
                cin.ignore();
                getline(cin, description);
                find_by_description(bus, n, description);
                system("pause");
                system("cls");
                break;

            case 4:
                cout << "Введите дату: ";
                cout << "  Введите день: ";
                cin >> day;
                cout << "  Введите номер месяца: ";
                cin >> month;
                cout << "  Введите год: ";
                cin >> year;
                cout << "Введите время: ";
                cout << "  Введите часы: ";
                cin >> hours;
                cout << "  Введите минуты: ";
                cin >> minutes;
                find_by_date(bus, n, day, month, year, hours, minutes);
                system("pause");
                system("cls");
                break;


            }
        case 5:
            show_all_business(bus, n);
            system("pause");
            system("cls");
            break;
        case 6:
            sort_by_priority(bus, n);
            show_all_business(bus, n);
            system("pause");
            system("cls");
            break;
        case 7:

            sort_by_date(bus, n);
            show_all_business(bus, n);
            system("pause");
            system("cls");
            break;
        case 0:
            system("cls");
            cout << "КА 'ШАГ' Группа: БВ011, студент Бурсов Евгений Сергеевич" << endl;
            system("pause");
            system("cls");

        }
    } while (true);


}


void add_business(business* bus, int n) {
    for (int i = 0; i < n; i++) {

        cout << "Введите название дела: ";
        cin.ignore();
        getline(cin, bus[i].name);


        cout << "Задайте приоритет (от 1 до 5): ";
        do {


            cin >> bus[i].priority;
            if (bus[i].priority > 5 || bus[i].priority < 1) {
                cout << "Введите значение от 1 до 5: ";
            }
        } while (bus[i].priority > 5 || bus[i].priority < 1);

        cout << "Введите описание дела: ";
        cin.ignore();
        getline(cin, bus[i].description);

        cout << "Введите дату: " << endl;
        cout << "  Введите день: ";
        do {
            cin >> bus[i].date.day;
            if (bus[i].date.day < 1 || bus[i].date.day>31) {
                cout << "Введите правильную дату: ";
            }
        } while (bus[i].date.day < 1 || bus[i].date.day>31);

        cout << "  Введите номер месяц: ";
        do {
            cin >> bus[i].date.month;
            if (bus[i].date.month < 1 || bus[i].date.month>12) {
                cout << "Введите правильную дату: ";
            }
        } while (bus[i].date.month < 1 || bus[i].date.month>12);

        cout << "  Введите год: ";
        do {
            cin >> bus[i].date.year;
            if (bus[i].date.year < 2021 || bus[i].date.year>3000) {
                cout << "Введите правильную дату: ";
            }
        } while (bus[i].date.year < 2021 || bus[i].date.year>3000);

        cout << "Введите время: " << endl;
        cout << "  Введите часы: ";
        do {
            cin >> bus[i].time.hours;
            if (bus[i].time.hours < 0 || bus[i].time.hours>24) {
                cout << "Введите правильное время: ";
            }
        } while (bus[i].time.hours < 0 || bus[i].time.hours>24);

        cout << "  Введите минуты: ";
        do {
            cin >> bus[i].time.minutes;
            if (bus[i].time.minutes < 0 || bus[i].time.minutes>60) {
                cout << "Введите правильное время(1-60): ";
            }
        } while (bus[i].time.minutes < 0 || bus[i].time.minutes>60);
        cout << endl;


    }

}

void show_all_business(business* bus, int n) {
    for (int i = 0; i < n; i++) {
        cout << "Название: " << bus[i].name << endl;
        cout << "Приоритет: " << bus[i].priority << endl;
        cout << "Описание: " << bus[i].description << endl;
        cout << "Дата: " << bus[i].date.day << "." << bus[i].date.month << "." << bus[i].date.year << endl;
        cout << "Время: " << bus[i].time.hours << ":" << bus[i].time.minutes << endl;
        cout << endl;
        cout << endl;

    }
}

void find_by_name(business* bus, int n, string name) {
    for (int i = 0; i < n; i++) {
        if (bus[i].name == name) {
            cout << "Название: " << bus[i].name << endl;
            cout << "Приоритет: " << bus[i].priority << endl;
            cout << "Описание: " << bus[i].description << endl;
            cout << "Дата: " << bus[i].date.day << "." << bus[i].date.month << "." << bus[i].date.year << endl;
            cout << "Время: " << bus[i].time.hours << ":" << bus[i].time.minutes << endl;
        }

    }
}

void find_by_priority(business* bus, int n, int priority) {
    for (int i = 0; i < n; i++) {
        if (bus[i].priority == priority) {
            cout << "Название: " << bus[i].name << endl;
            cout << "Приоритет: " << bus[i].priority << endl;
            cout << "Описание: " << bus[i].description << endl;
            cout << "Дата: " << bus[i].date.day << "." << bus[i].date.month << "." << bus[i].date.year << endl;
            cout << "Время: " << bus[i].time.hours << ":" << bus[i].time.minutes << endl;
        }

    }
}

void find_by_description(business* bus, int n, string description) {
    for (int i = 0; i < n; i++) {
        if (bus[i].description == description) {
            cout << "Название: " << bus[i].name << endl;
            cout << "Приоритет: " << bus[i].priority << endl;
            cout << "Описание: " << bus[i].description << endl;
            cout << "Дата: " << bus[i].date.day << "." << bus[i].date.month << "." << bus[i].date.year << endl;
            cout << "Время: " << bus[i].time.hours << ":" << bus[i].time.minutes << endl;
        }

    }
}

void find_by_date(business* bus, int n, int day, int month, int year, int hours, int minutes) {
    for (int i = 0; i < n; i++) {
        if (bus[i].date.day == day && bus[i].date.month == month && bus[i].date.year == year && bus[i].time.hours == hours && bus[i].time.minutes == minutes) {
            cout << "Название: " << bus[i].name << endl;
            cout << "Приоритет: " << bus[i].priority << endl;
            cout << "Описание: " << bus[i].description << endl;
            cout << "Дата: " << bus[i].date.day << "." << bus[i].date.month << "." << bus[i].date.year << endl;
            cout << "Время: " << bus[i].time.hours << ":" << bus[i].time.minutes << endl;
        }

    }
}

void show_business_on_day(business* bus, int n, int day, int month, int year) {
    for (int i = 0; i < n; i++) {
        if (day == bus[i].date.day && bus[i].date.month == month && bus[i].date.year == year) {
            cout << "Название: " << bus[i].name << endl;
            cout << "Приоритет: " << bus[i].priority << endl;
            cout << "Описание: " << bus[i].description << endl;
            cout << "Дата: " << bus[i].date.day << "." << bus[i].date.month << "." << bus[i].date.year << endl;
            cout << "Время: " << bus[i].time.hours << ":" << bus[i].time.minutes << endl;
        }

    }
}

void show_business_on_week(business* bus, int n, int day, int month, int year) {
    for (int i = 0; i < n; i++) {
        if ((day >= bus[i].date.day + 7) && bus[i].date.month == month && bus[i].date.year == year) {
            cout << "Название: " << bus[i].name << endl;
            cout << "Приоритет: " << bus[i].priority << endl;
            cout << "Описание: " << bus[i].description << endl;
            cout << "Дата: " << bus[i].date.day << "." << bus[i].date.month << "." << bus[i].date.year << endl;
            cout << "Время: " << bus[i].time.hours << ":" << bus[i].time.minutes << endl;
        }

    }
}

void show_business_on_month(business* bus, int n, int day, int month, int year) {
    for (int i = 0; i < n; i++) {
        if (bus[i].date.day <= day && (month <= bus[i].date.month + 1) && bus[i].date.year == year) {
            cout << "Название: " << bus[i].name << endl;
            cout << "Приоритет: " << bus[i].priority << endl;
            cout << "Описание: " << bus[i].description << endl;
            cout << "Дата: " << bus[i].date.day << "." << bus[i].date.month << "." << bus[i].date.year << endl;
            cout << "Время: " << bus[i].time.hours << ":" << bus[i].time.minutes << endl;
        }

    }
}

void show_business_on_year(business* bus, int n, int day, int month, int year) {
    for (int i = 0; i < n; i++) {
        if (bus[i].date.day <= day && (month <= bus[i].date.month) && bus[i].date.year + 1 == year) {
            cout << "Название: " << bus[i].name << endl;
            cout << "Приоритет: " << bus[i].priority << endl;
            cout << "Описание: " << bus[i].description << endl;
            cout << "Дата: " << bus[i].date.day << "." << bus[i].date.month << "." << bus[i].date.year << endl;
            cout << "Время: " << bus[i].time.hours << ":" << bus[i].time.minutes << endl;
        }

    }
}

void sort_by_priority(business* bus, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (bus[i].priority < bus[i + 1].priority) {
                business temp = bus[i];
                bus[i] = bus[i + 1];
                bus[i + 1] = temp;
            }
        }
    }
}

void sort_by_date(business* bus, int n) {

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (bus[i].date.year != bus[i + 1].date.year) {
                if (bus[i].date.year > bus[i + 1].date.year) {
                    business temp = bus[i];
                    bus[i] = bus[i + 1];
                    bus[i + 1] = temp;
                    continue;
                }

            }
            else if (bus[i].date.month != bus[i + 1].date.month) {
                if (bus[i].date.month > bus[i].date.month) {
                    business temp = bus[i];
                    bus[i] = bus[i + 1];
                    bus[i + 1] = temp;
                    continue;
                }
            }
            else if (bus[i].date.day > bus[i + 1].date.day) {
                business temp = bus[i];
                bus[i] = bus[i + 1];
                bus[i + 1] = temp;

            }

        }
    }
}

void edit_business(business* bus, int n, int index) {

    do {

        index = index - 1;
        if (index > n) {
            cout << "Введите корректный индекс! ";
        }
    } while (index > n);
    cout << "Изменить название на: " << endl;
    cin.ignore();
    getline(cin, bus[index].name);
    cout << "Изменить приоритет на: " << endl;
    cin >> bus[index].priority;
    cout << "Изменить описание на: " << endl;
    cin.ignore();
    getline(cin, bus[index].description);
    cout << "Изменить день на: " << endl;
    cin >> bus[index].date.day;
    cout << "Изменить месяц на: " << endl;
    cin >> bus[index].date.month;

    cout << "Изменить год на: " << endl;
    cin >> bus[index].date.year;
    cout << "Измените время :" << endl;
    cout << "  Измените часы на :" << endl;
    cin >> bus[index].time.hours;
    cout << "  Измените минуты на :" << endl;
    cin >> bus[index].time.minutes;
}