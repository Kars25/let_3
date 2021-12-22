#include <iostream>
using namespace std;
long transformation(char *str){
    long result = 0;
    if (*str == '-' || *str == '+') {
        str++;
    }
    str+=2;
    while (*str != '\0') {
        int number;
        number = *str - '0';
        if (number > 9) {
            number = (number - 7) % 32;
        }
        result = 16 * result + number;
        str++;
    }
    return result;
}
int str_check(int argc, char *argv[]){
    for (int i = 0; i < argc-1; ++i) {
        char *str = argv[argc - i - 1];
        bool is_negative = (*str == '-');
        long result = transformation(str);
        if (is_negative) {
            result = -result;
        }
        result = 121 + result;
        cout << result << endl;
    }
    return 0;
}
int main(int argc, char *argv[]) {
    if (argc == 1) {
        exit(-1);
    }
    str_check(argc, argv);
    return 0;
}