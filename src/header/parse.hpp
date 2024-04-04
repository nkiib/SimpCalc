#ifndef HEADER_PARSE_HPP_
#define HEADER_PARSE_HPP_
#include<string>
#include<vector>
#include<map>
#include<gmp.h>
#include<gmpxx.h>

/// @brief 引数が足りているかの確認
/// @param  引数ベクター
/// @param  要求引数の個数
/// @return 結果
bool arguments_check(std::vector<std::string>, int);

/// @brief 構文解析と実行
/// @param input 
/// @return 結果
std::string parse(std::string input);

/// @brief 引数の合計を計算する関数
/// @param augment 引数ベクター
/// @return 結果
std::string sum(std::vector<std::string> augment);

/// @brief 累乗を計算する関数
/// @param augment 引数ベクター
/// @return 結果
std::string pow(std::vector<std::string> augment);

/// @brief 素数テストを行う
/// @param augment 引数ベクター
/// @return 結果
bool prime_test(std::vector<std::string> augment);


/// @brief 素数判定で用いる試行割算を実行する
/// @param candidate 素数候補
/// @param prime_ary 試行割り算に用いる素数リスト
/// @return 結果
bool Trial_Division(mpz_class candidate, std::vector<int> prime_ary);

/// @brief MillerRabin法による素数判定
/// @param candidate 素数候補
/// @param num 試行回数
/// @return 結果
bool MillerRabin(mpz_class candidate, int num);


/// @brief 試行割算で用いる素数リストの作成
/// @param 個数
/// @return 作成された素数リスト
std::vector<int> GenPrimeVector(int);

/// @brief 素数を生成する関数
/// @param 引数リスト
/// @return 生成された素数
std::string prime_generate(std::vector<std::string>);

/// @brief 引数が素数であるかを確認するテスト
/// @param  引数リスト
/// @return  結果
std::string prime_check(std::vector<std::string>);

/// @brief 整数の剰余算
/// @param  引数リスト
/// @return 結果
std::string mod(std::vector<std::string>);

/// @brief 素因数分解
/// @param 引数リスト
/// @return 結果
std::string factoriz(std::vector<std::string>);

/// @brief 平均
/// @param 引数リスト
/// @return 結果
std::string average(std::vector<std::string>);

#endif