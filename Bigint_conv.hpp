/*
    MIT License

    Copyright (c) 2020 Davide Fassio

    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in all
    copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
    SOFTWARE.
*/

#ifndef BIGINT_CONV_HPP
#define BIGINT_CONV_HPP

#include <iostream>
#include <cstdint>
#include <vector>
#include <string>

class BigInt{
public:
    // Constructors:
    BigInt();
    BigInt(const BigInt&);
    BigInt(const int64_t);
    BigInt(const std::string);
    BigInt(const char[]);

    // Assignment operators:
    BigInt& operator=(const BigInt&);
    BigInt& operator=(const int64_t);
    BigInt& operator=(const std::string);
    BigInt& operator=(const char[]);

    // Getters:
    int getSign() const ;
    std::string getString() const ;
    std::vector<uint64_t> getVector() const ;

private:
    // Internal state:
    int8_t sign;
    std::vector<uint64_t> mant;

    // Conversion methods:
    static std::vector<uint64_t> strToVec(std::string);
    static std::string vecToStr(std::vector<uint64_t>);
};


/** ========== CONSTRUCTOR ========== **/

// Default constructor.
BigInt::BigInt(){
    this->sign = 0;
}

// Copy constructor.
BigInt::BigInt(const BigInt& other){
    if(other.sign == 0){ return; }
    this->sign = other.sign;
    this->mant = other.mant;
}

// Constructor from 64bit integer.
BigInt::BigInt(const int64_t n){
    this->sign = (n < 0) ? -1 : 1;
    this->mant.push_back((n < 0) ? -n : n);
}

// Constructor from a std::string.
BigInt::BigInt(const std::string str){
    std::string stmp = str;
    if(stmp[0] == '-'){
        if(stmp.size() == 2 && stmp[1] == '0'){
            this->sign = 1;
            stmp.erase(0, 1);

        }
        else{
            this->sign = -1;
            stmp.erase(0, 1);
        }
    }
    else if(stmp[0] == '+'){
        this->sign = 1;
        stmp.erase(0, 1);
    }
    else{
        this->sign = 1;
    }
    this->mant = BigInt::strToVec(stmp);
}

// Constructor from an array or characters.
BigInt::BigInt(const char arr[]){
    std::string stmp(arr);
    if(stmp[0] == '-'){
        if(stmp.size() == 2 && stmp[1] == '0'){
            this->sign = 1;
            stmp.erase(0, 1);

        }
        else{
            this->sign = -1;
            stmp.erase(0, 1);
        }
    }
    else if(stmp[0] == '+'){
        this->sign = 1;
        stmp.erase(0, 1);
    }
    else{
        this->sign = 1;
    }
    this->mant = BigInt::strToVec(stmp);
}


/** ========== ASSIGNMENT ========== **/

// Assignment from another initialized BigInt
BigInt& BigInt::operator=(const BigInt& other){
    if(other.sign == 0){ exit(0); }
    this->sign = other.sign;
    this->mant = other.mant;
    return *this;
}

// Assignment from a 64bit integer
BigInt& BigInt::operator=(const int64_t n){
    this->sign = (n < 0) ? -1 : 1;
    this->mant.push_back((n < 0) ? -n : n);
    return *this;
}

// Assignment from a string
BigInt& BigInt::operator=(const std::string str){
    std::string stmp = str;
    if(stmp[0] == '-'){
        if(stmp.size() == 2 && stmp[1] == '0'){
            this->sign = 1;
            stmp.erase(0, 1);

        }
        else{
            this->sign = -1;
            stmp.erase(0, 1);
        }
    }
    else if(stmp[0] == '+'){
        this->sign = 1;
        stmp.erase(0, 1);
    }
    else{
        this->sign = 1;
    }
    this->mant = BigInt::strToVec(stmp);
    return *this;
}

// Assignment from an array of character
BigInt& BigInt::operator=(const char arr[]){
    std::string stmp(arr);
    if(stmp[0] == '-'){
        if(stmp.size() == 2 && stmp[1] == '0'){
            this->sign = 1;
            stmp.erase(0, 1);

        }
        else{
            this->sign = -1;
            stmp.erase(0, 1);
        }
    }
    else if(stmp[0] == '+'){
        this->sign = 1;
        stmp.erase(0, 1);
    }
    else{
        this->sign = 1;
    }
    this->mant = BigInt::strToVec(stmp);
    return *this;
}



/** ========== GETTER ========== **/

// Return an integer (int) containing the sign:
//      1) -1 = negative;
//      2)  0 = not initialized;
//      3)  1 = positive.
int BigInt::getSign() const {
    if(this->sign != 0){ return static_cast<int>(this->sign); }
    exit(0);
}

// Return a string of digits, with sign if negative.
std::string BigInt::getString() const {
    if(this->sign == 0){ exit(0); }
    if(this->sign == -1){ return "-" + BigInt::vecToStr(this->mant); }
    else{ return BigInt::vecToStr(this->mant); }
}

// Return a vector of uint64 without the sign.
std::vector<uint64_t> BigInt::getVector() const {
    return this->mant;
}


/** ========== CONVERSION ========== **/

// Convert a string of digit in a vector of 64bit integer. TO FIX
std::vector<uint64_t> BigInt::strToVec(std::string str){
    // Convert the string to a vector of digits
    std::vector<int8_t> vdig;
    for(char c : str){
        if(c > 47 && c < 58){ vdig.push_back(((int) c) - 48); }
        else{ exit(0); }
    }
    for(int64_t i = 0; i < vdig.size(); ++i){
        if(vdig[i] != 0){
            vdig.erase(vdig.begin(), vdig.begin()+i);
            break;
        }
        if(i == vdig.size()-1){
            vdig.erase(vdig.begin(), vdig.begin()+i);
            break;
        }
    }
    std::vector<uint64_t> vtmp;
    int64_t cnt = -1;
    int dig = 0;
    if(vdig.size() == 1 && vdig[0] == 0){
        vtmp.push_back(0);
        return vtmp;
    }
    while(vdig.size() != 1 || vdig[0] != 0){
        if(dig % 64 == 0){
            vtmp.push_back(0);
            dig = 0;
            ++cnt;
        }
        if(vdig[vdig.size()-1] % 2 != 0){
            vtmp[cnt] |= ((uint64_t) 0x0000000000000001 << dig);
            // Subtract 1
            --vdig[vdig.size()-1];
            for(int64_t i = vdig.size() - 1; i >= 0; --i){
                if(vdig[i] != -1){ break; }
                vdig[i] = 9;
                --vdig[i-1];
            }
            for(int64_t i = 0; i < vdig.size(); ++i){
                if(vdig[i] != 0){
                    vdig.erase(vdig.begin(), vdig.begin()+i);
                    break;
                }
                if(i == vdig.size()-1){
                    vdig.erase(vdig.begin(), vdig.begin()+i);
                    break;
                }
            }
        }
        // Divide by 2
        for(int64_t i = 0; i < vdig.size(); ++i){
            if(vdig[i] >= 2){
                if(vdig[i]%2 == 0){
                    vdig[i] /= 2;
                }
                else{
                    vdig[i] = (vdig[i]-1)/2;
                    vdig[i+1] += 10;
                }
            }
            else if(vdig[i] == 1){
                vdig[i] = 0;
                vdig[i+1] += 10;
            }
        }
        for(int64_t i = 0; i < vdig.size(); ++i){
            if(vdig[i] != 0){
                vdig.erase(vdig.begin(), vdig.begin()+i);
                break;
            }
            if(i == vdig.size()-1){
                vdig.erase(vdig.begin(), vdig.begin()+i);
                break;
            }
        }
        ++dig;
    }
    return vtmp;
}

// Convert a vector of 64bit integer of digit in a string.
std::string BigInt::vecToStr(std::vector<uint64_t> vec){
    std::vector<uint8_t> vdig;
    vdig.push_back(0);
    int rep;
    for(int64_t i = vec.size()-1; i >= 0; --i){
        for(int j = 63; j >= 0; --j){
            // Multiply vdig by 2
            rep = 0;
            for(int64_t k = 0; k < vdig.size(); ++k){
                vdig[k] = (2*vdig[k]) + rep;
                if(k == vdig.size()-1){
                    if(vdig[k] > 9){
                        vdig[k] -= 10;
                        vdig.push_back(1);
                    }
                    break;
                }
                else{
                    if(vdig[k] > 9){
                        vdig[k] -= 10;
                        rep = 1;
                    }
                    else{ rep = 0; }
                }
            }
            // If it's 1 add 1, else nothing
            if((vec[i] >> j) & 1){
                ++vdig[0];
                for(int64_t k = 0; k < vdig.size(); ++k){
                    if(vdig[k] != 10){ break; }
                    if(k == vdig.size()-1){
                        vdig[k] = 0;
                        vdig.push_back(1);
                    }
                    else{
                        vdig[k] = 0;
                        ++vdig[k+1];
                    }
                }
            }
        }
    }
    // Convert vdig into stmp
    std::string stmp;
    for(int64_t i = vdig.size()-1; i >= 0; --i){
        stmp.push_back((char) (vdig[i]+48));
    }
    return stmp;
}

#endif // BIGINT_CONV_HPP
