#include <iostream>

#include "alphabet_map.hpp"





int main(){

    AlphaMap A_MAP;

    A_MAP.Map_Alphabet();
    //A_MAP.printAlphabet();


    //for(char alpha : A_MAP.getAlphabet()){
    //    std::cout << A_MAP.charToNumber(alpha)<< " ";
    //}

    std::string str;
    std::cin >> str;

    
    //for(char i : str){
    //    std::cout << A_MAP.charToNumber(i) << " ";
    //}


    std::cout << A_MAP.countDecodings(str);


    return 0;
}