#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>
#include <stdexcept>

void task1();

void task2();
int determine_number_type(const std::string& str);

class MyString {
public:
   
    MyString(const char* str) : data(str) {}
    MyString(const std::string& str) : data(str) {}

    
    size_t find_last_of(char c, size_t pos = std::string::npos) const {
        
        if (pos >= data.size()) {
            pos = data.size() - 1;
        }

       
        for (size_t i = pos + 1; i-- > 0;) {
            if (data[i] == c) {
                return i;
            }
        }

        
        return std::string::npos;
    }

private:
    std::string data;
};

int main() {
    int choice = 0;

    while (choice != 3) {

        std::cout << "Choose task: "
            "\n1.Task1"
            "\n2.Task2"
            "\n3.Exit" << std::endl;

        std::cin >> choice;

        switch (choice) {
        case 1: {
            task1();		
            break;
        }
        case 2: {
            task2();		
            break;
        }
        case 3: {
            std::cout << "Program is over!";
            break;
        }
        default: {
            std::cout << "Wrong one, try again";
        }
        }
    }
    
}

void task1() {
    MyString myStr("Obviously, i'm a best programmer ever(joke)!");
    size_t pos = myStr.find_last_of('o');
    if (pos != std::string::npos) {
        std::cout << "Last 'o' found at position: " << pos << std::endl;
    }
    else {
        std::cout << "'o' not found!" << std::endl;
    }
}

void task2() {
    std::string input;
    std::cout << "Enter string: ";
    std::cin >> input;

    int result = determine_number_type(input);
    std::cout << "Result: " << result << std::endl;
}

int determine_number_type(const std::string& str) {
    bool hasDecimalPoint = false;
    bool hasDigits = false;

   
    if (str.empty()) {
        return 0;
    }

    
    size_t start = 0;
    if (str[0] == '-' || str[0] == '+') {
        start = 1;
        if (str.size() == 1) {
            return 0; 
        }
    }

    for (size_t i = start; i < str.size(); ++i) {
        if (isdigit(str[i])) {
            hasDigits = true;
        }
        else if (str[i] == '.') {
            if (hasDecimalPoint) {
                return 0; 
            }
            hasDecimalPoint = true;
        }
        else {
            return 0; 
        }
    }

    if (!hasDigits) {
        return 0; 
    }

    if (hasDecimalPoint) {
        return 2; 
    }
    else {
        return 1; 
    }
}
