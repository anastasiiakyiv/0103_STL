#include <iostream>
#include <list>
#include <sstream>

int calculateSum(const std::string& input) {
    std::istringstream iss(input);
    std::list<std::string> symbols;
    std::string symbol;

    while (iss >> symbol) {
        symbols.push_back(symbol);
    }

    std::list<int> List;

    for (const std::string& s : symbols) {
        if (s == "с") {
            if (!List.empty()) {
                List.pop_back();
            }
        }
        else if (s == "д") {
            if (!List.empty()) {
                int back = List.back();
                List.push_back(back * 2);
            }
        }
        else if (s == "+") {
            if (List.size() >= 2) {
                auto it = List.end();
                int back1 = *(--it);
                int back2 = *(--it);
                int sum = back1 + back2;
                List.push_back(sum);
            }
        }
        else {
            List.push_back(std::stoi(s));
        }
    }

    int total = 0;
    for (int num : List) {
        total += num;
    }

    return total;
}

int main() {
    system("chcp 1251>null");
    std::string input;
    std::cout << "Введіть рядок: ";
    std::getline(std::cin, input);

    int result = calculateSum(input);

    std::cout << "Вивід:  " << result << std::endl;

    return 0;
}