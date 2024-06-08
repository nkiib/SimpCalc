#include<string>
#include<vector>
#include<cmath>
#include<gmp.h>
#include<gmpxx.h>
#include<fstream>
#include<sstream>
#include<iostream>
#include<chrono>
#include"./header/parse.hpp"

std::vector<int> GenPrimeVector(int num){
    // 素数を格納するベクター配列
    std::vector<int> prime_ary;

    // 素数が格納されたファイル
    std::ifstream inputFile("../prime_file/prime_doc.txt");

    // 例外処理
    if(!inputFile.is_open()){
        return prime_ary;
    }

    // 格納
    std::string line;
    while(std::getline(inputFile , line)){
        std::istringstream iss(line);

        int prime;
        while(iss >> prime && num > 0){
            prime_ary.push_back(prime);
            num--;
        }
        break;
    }
    return prime_ary;
}

bool Trial_Division(mpz_class candidate , std::vector<int> prime_ary){
    if(prime_ary.empty()) return 1; // ファイルが開けなかったときエラーで終了

    mpz_class ans;
    for(int i = 0;i < prime_ary.size();i++){
        ans = candidate % prime_ary[i];
        if(ans == 0){
            return false;
        }
    }
    return true;
}

bool MillerRabin(mpz_class candidate , int k){
    if( candidate <= 1) return false;
    if( candidate <= 3) return true;

    mpz_class t = candidate - 1;
    mpz_class tmp ,s;s = "0";
    while(t % 2 == 0){
        t /= 2;
        s++;
    }

    int flag = 0;

    gmp_randclass rand(gmp_randinit_default);

    for(int i = 0; i < k; i++){
        mpz_class a = rand.get_z_range(candidate - 1) + 1;
        mpz_class x;
        mpz_powm(x.get_mpz_t() , a.get_mpz_t() , t.get_mpz_t() , candidate.get_mpz_t());


        if(x == 1 || x == candidate - 1){
            flag = 1;
            continue;
        }

        for(int j = 0; j < s -1;j++){
            mpz_powm_ui(x.get_mpz_t() , x.get_mpz_t() , 2 , candidate.get_mpz_t());
            if(x == candidate - 1){
                break;
            }
            flag = 1;
        }

        if (x != candidate - 1) return false;
    }

    return true;
}

bool prime_test(mpz_class prime_candidate){
    std::vector<int> prime_ary = GenPrimeVector(1000);

    if(prime_candidate == 2) return true;

    if(Trial_Division(prime_candidate , prime_ary)){
            // MR法
        if(MillerRabin(prime_candidate, 3)){
                return true;
        }
    }
    return false;
}

std::string prime_check(std::vector<std::string> arguments){
    if(!arguments_check(arguments,1)){
        return "error:arguments are missing.";
    }

    mpz_class prime_candidate;

    mpz_set_str(prime_candidate.get_mpz_t(), arguments[0].c_str(), 10);

    if(prime_test(prime_candidate)){
        return "Prime.";
    }else{
        return "Not Prime.";
    }
}

std::string prime_generate(std::vector<std::string> arguments){
    if(!arguments_check(arguments,1)){
        return "error:arguments are missing.";
    }

    // 1 bit に素数はないためあらかじめ除外
    if(arguments[0] == "1"){
        return "None";
    }

    gmp_randstate_t state;
    gmp_randinit_default(state);
    std::ostringstream oss;

    std::chrono::system_clock::time_point now;
    std::chrono::system_clock::duration duration;
    unsigned long seed;

    mpz_class randNum;

    for(;;){
        // 現在の時間を取得し、秒単位に変換してシードとして設定
        now = std::chrono::system_clock::now();
        duration = now.time_since_epoch();
        seed = std::chrono::duration_cast<std::chrono::microseconds>(duration).count();
        gmp_randseed_ui(state, seed);

        // 乱数を生成して出力
        
        mpz_init(randNum.get_mpz_t());
        mpz_urandomb(randNum.get_mpz_t(), state, stoi(arguments[0]));

        if(prime_test(randNum)){
            oss << randNum;
            return oss.str();
        }
    }
}