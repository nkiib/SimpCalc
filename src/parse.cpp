#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<map>
#include"./header/parse.hpp"


std::string parse(std::string input){
    std::string result; // 結果を格納する変数
    std::string command; // コマンド
    std::vector<std::string> augment; // 引数
    std::string arg;// 引数のtmp
    // 構文解析をするためにSSに格納する
    std::stringstream stream;
    stream << input;
    stream >> command;


    while(stream >> arg){
        augment.push_back(arg);
    }

    if(command == "sum"){
        result = sum(augment);
    }else if(command == "prime"){
        result = prime_check(augment);
    }else if(command == "genprime"){
        result = prime_generate(augment);
    }else if(command == "pow"){
        result = pow(augment);
    }else if(command == "mod"){
        result = mod(augment);
    }



    else{
        result = "SimpCalc: command not found:" + command;
    }
    return result;

}

