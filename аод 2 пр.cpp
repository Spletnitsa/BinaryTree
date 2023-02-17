#include "Binary_tree.h"

//проверка на некорректный ввод
int inputError() {
    int someVar;
    cin >> someVar;
    while (cin.fail()) {
        cout << "ошибка ввода, попробуйте снова\n";
        cin.clear();
        cin.ignore(100, '\n');
        cin >> someVar;
    }
    return someVar;
}

int main()
{
    setlocale(LC_ALL, "ru");
    bool progExit = false;
    int operNumber;
    string variable;
    struct Node *someTree = NULL;
    do {
        cout << "выберете операцию: \n";
        cout << "1) Вставка элемента\n2) Прямой обход\n3) Симметричный обход\n4) Длина пути\n5) Высота дерева\n6) Выход\n";
        operNumber = inputError();
        switch (operNumber)
        {
        case 1:
            cout << "чтобы закончить ввод, напишите слово \"stop\"\n";
            do {
                cout << "Введите элемент: ";
                cin >> variable;
                if (variable != "stop") {
                   someTree = push(variable, someTree);
                }
            } while (variable != "stop");
            system("cls");
            break;

        case 2:
            PostfixPrint(someTree);
            cout << endl;
            system("pause");
            system("cls");
            break;

        case 3:
            InfixPrint(someTree);
            cout << endl;
            system("pause");
            system("cls");
            break;

        case 4:
            cout << "Введите строку для поиска\n";
            cin >> variable;
            search(variable, someTree, -1);
            cout << endl;
            system("pause");
            system("cls");
            break;

        case 5:
            cout << Height(someTree);
            cout << endl;
            system("pause");
            system("cls");
            break;

        case 6:
            progExit = true;
            break;

        default:
            cout << "Ошибка ввода!\nПовторите попытку\n";
            system("pause");
            system("cls");
            break;
        }
    } while (!progExit);
    
}
