#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<map>
#include"./header/parse.hpp"


std::string parse(std::string input){
    std::string result; // 結果を格納する変数
    std::string command; // コマンド
    std::vector<std::string> arguments; // 引数
    std::string arg;// 引数のtmp
    // 構文解析をするためにSSに格納する
    std::stringstream stream;
    stream << input;
    stream >> command;

    while(stream >> arg){
        arguments.push_back(arg);
    }

    if(command == "sum"){
        result = sum(arguments);
    }else if(command == "prime"){
        result = prime_check(arguments);
    }else if(command == "genprime"){
        result = prime_generate(arguments);
    }else if(command == "pow"){
        result = pow(arguments);
    }else if(command == "mod"){
        result = mod(arguments);
    }else if(command == "factoriz"){
        result = factoriz(arguments);
    }else if(command == "average"){
        result = average(arguments);
    }else if(command == "square"){
        result = square(arguments);
    }  

    else{
        result = "SimpCalc: command not found:" + command;
    }
    return result;

}

