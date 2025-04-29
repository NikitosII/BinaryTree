#include <iostream> 
#include "Tree.h" 
#include <fstream> 

int main(int argc, char* argv[]) {
    setlocale(LC_ALL, "rus");

    Tree tree;
    std::string path;
    path = std::string(argv[1]);
    std::ifstream fin(path);

    int choice = 0;
    do {
        std::cout << "  Меню:\n";
        std::cout << "1) Ввод данных\n";
        std::cout << "2) Построение и вывод на экран бинарного дерева\n";
        std::cout << "0) Выход из программы\n";
        std::cout << "Выберите пункт меню: ";
        std::cin >> choice;
        switch (choice) {
        case 1: {
            int num;
            while (fin >> num && num != 0) {
                tree.insert(num);

            }
            fin.close();
            std::cout << "Everything went well" << std::endl;
            std::cout << std::endl;

            system("pause");
            system("cls");
        }
              break;
        case 2: {
            int choice2 = 0;
            std::cout << "    1)Прямой обход \n";
            std::cout << "    2)Симметричный обход \n";
            std::cout << "    3)Обратный обход\n";
            std::cout << "    4)Special (выглядит не идеально, но наглядно) \n";
            std::cin >> choice2;
            std::cout << "\n";
            switch (choice2) {
            case 1: {
                tree.Pref();
                std::cout << std::endl;
            }
                  break;

            case 3: {
                tree.Postf();
                std::cout << std::endl;
            }
                  break;
            case 2: {
                tree.Inf();
                std::cout << std::endl;
            }
                  break;
            case 4: {
                tree.printTree();
                std::cout << std::endl;
            }
                  break;
            default: {
                std::cout << "Введите пункт из списка\n";
            }
                   break;
            }
        }
              system("pause");
              system("cls");

              break;
        default: {
            std::cout << "Введите пункт из списка\n";
        }
               break;
        }
    } while (choice != 0);


    return 0;
}
