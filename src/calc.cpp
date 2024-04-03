#include<string>
#include<vector>
#include<cmath>
#include<gmp.h>
#include<gmpxx.h>
#include<sstream>
#include"./header/parse.hpp"
#include<iostream>

bool augment_check(std::vector<std::string> augment , int min){
    if(augment.size() < min){
        return false;
    }
    return true;
}

std::string sum(std::vector<std::string> augment){
    mpf_class result = 0.0;
    mpf_class tmp;
    for (size_t i = 0; i < augment.size(); ++i) {
        mpf_set_str(tmp.get_mpf_t(),augment[i].c_str(),10);
        result += tmp;
    }
    std::ostringstream oss;
    oss << result;
    
    return oss.str();
}

std::string pow(std::vector<std::string> augment){
    if(!augment_check(augment , 2)){
        return "error:arguments are missing.";
    }

    mpf_class result , base;
    mpf_set_str(base.get_mpf_t() , augment[0].c_str(), 10);


    mpf_pow_ui(result.get_mpf_t() , base.get_mpf_t() , stol(augment[1]));

    std::ostringstream oss;
    oss << result;

    return oss.str();
}

std::string mod(std::vector<std::string> augment){
    if(!augment_check(augment , 2)){
        return "error:arguments are missing.";
    }

    mpz_class x , y , result;
    mpz_set_str(x.get_mpz_t() , augment[0].c_str(), 10);
    mpz_set_str(y.get_mpz_t() , augment[1].c_str(), 10);

    result = x % y;

    std::ostringstream oss;
    oss << result;

    return oss.str();
}

std::string factoriz(std::vector<std::string> augment){
    if(!augment_check(augment, 1)){
        return "error:arguments are missing.";
    }


    std::ostringstream oss;

    mpz_class CompositeNumber, d , q;
    mpz_set_str(CompositeNumber.get_mpz_t(), augment[0].c_str(), 10);

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