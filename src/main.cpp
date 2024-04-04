#include<iostream>
#include<string>
#include<vector>
#include<gmp.h>
#include<gmpxx.h>
#include<sstream>
#include<map>
#include"./header/parse.hpp"

int main(int argc, char * argv[]){

    std::string input;

    std::cout << "Tlooks SimpCalc v0.1.0-alpha (C)2024 Nishiki-Hub" << std::endl;

    while (true) {
        std::cout << ">>> ";
        std::getline(std::cin, input);

        if (input == "exit") {
            break;
        }

        // 入力を評価して結果を出力
        std::stringstream ss;
        ss << input;

        // コードの評価
        try {
            std::cout << parse(input) << std::endl;
        } catch (...) {
            std::cout << "Error: Evaluation failed." << std::endl;
        }
    }

    std::cout << "Have a nice Day!" << std::endl;
    return 0;
}