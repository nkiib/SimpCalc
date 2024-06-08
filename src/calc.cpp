#include<string>
#include<vector>
#include<cmath>
#include<gmp.h>
#include<gmpxx.h>
#include<sstream>
#include"./header/parse.hpp"
#include<iostream>

bool arguments_check(std::vector<std::string> arguments , int min){
    if(arguments.size() < min){
        return false;
    }
    return true;
}

std::string sum(std::vector<std::string> arguments){
    mpf_class result = 0.0;
    mpf_class tmp;
    for (size_t i = 0; i < arguments.size(); ++i) {
        mpf_set_str(tmp.get_mpf_t(),arguments[i].c_str(),10);
        result += tmp;
    }
    std::ostringstream oss;
    oss << result;
    
    return oss.str();
}

std::string pow(std::vector<std::string> arguments){
    if(!arguments_check(arguments , 2)){
        return "error:arguments are missing.";
    }

    mpf_class result , base;
    mpf_set_str(base.get_mpf_t() , arguments[0].c_str(), 10);

    mpf_pow_ui(result.get_mpf_t() , base.get_mpf_t() , stol(arguments[1]));

    std::ostringstream oss;
    oss << result;

    return oss.str();
}

std::string mod(std::vector<std::string> arguments){
    if(!arguments_check(arguments , 2)){
        return "error:arguments are missing.";
    }

    mpz_class x , y , result;
    mpz_set_str(x.get_mpz_t() , arguments[0].c_str(), 10);
    mpz_set_str(y.get_mpz_t() , arguments[1].c_str(), 10);

    result = x % y;

    std::ostringstream oss;
    oss << result;

    return oss.str();
}

std::string factoriz(std::vector<std::string> arguments){
    if(!arguments_check(arguments, 1)){
        return "error:arguments are missing.";
    }

    std::ostringstream oss;

    mpz_class CompositeNumber, d , q;
    mpz_set_str(CompositeNumber.get_mpz_t(), arguments[0].c_str(), 10);

    oss << CompositeNumber << " = ";
    while(CompositeNumber >= 4 && CompositeNumber % 2 == 0){
        oss << "2 * "; 
        CompositeNumber /= 2;
    }

    d = 3;
    q = CompositeNumber / d;

    while(q >= d){
        if(CompositeNumber % d == 0){
            oss << d << " * ";
            CompositeNumber = q;
        }else{
            d += 2;
        }
        q = CompositeNumber / d;
    }

    oss << CompositeNumber;

    return oss.str();
}

std::string average(std::vector<std::string> arguments){
    mpf_class sum = 0.0;
    mpf_class tmp , result;
    for (size_t i = 0; i < arguments.size(); ++i) {
        mpf_set_str(tmp.get_mpf_t(),arguments[i].c_str(),10);
        sum += tmp;
    }

    result = sum / arguments.size();

    std::ostringstream oss;
    oss << result;
    
    return oss.str();
}

mpf_class square_process(mpf_class x){

    mpf_class s, last;

    if(x > 0){
        if(x > 1){
            s = x;
        }else{
            s = 1;
        }
        do{
            last = s;
            s = ( x / s + s)/2;
        }while(s < last);
        return last;
    }

    if(x != 0){
        return -1;
    }

    return 0;
}

std::string square(std::vector<std::string> arguments){
    if(!arguments_check(arguments,1)){
        return "error:arguments are missing.";
    }

    std::stringstream oss;

    mpf_class x;

    mpf_set_str(x.get_mpf_t(), arguments[0].c_str(), 10);

    mpf_class s;

    if(x == 0){
        oss << 0;
    }

    s = square_process(x);
    oss << (x / s + s) / 2;

    return oss.str();

}