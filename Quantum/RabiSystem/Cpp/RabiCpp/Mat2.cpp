#pragma once

#include <complex>
#include "Mat2.h"
#include "Vec2.h"
#include <iostream>
#include <string>

std::string to_string_complex(complex c) {
    std::string r = std::to_string(real(c));
    std::string i = std::to_string(imag(c));
    return r + "+" + i + "i";
}

Mat2 Mat2::Hermitian(){
        complex m11 = conj(this->m11);
        complex m12 = conj(this->m21);
        complex m21 = conj(this->m12);
        complex m22 = conj(this->m22);

        return Mat2(m11, m12, m21, m22);
    }

Mat2 Mat2::dot(Mat2 &b){
    complex m11 = this->m11 * b.m11 + this->m12 * b.m21;
    complex m12 = this->m11 * b.m12 + this->m12 * b.m22;

    complex m21 = this->m21 * b.m11 + this->m22 * b.m21;
    complex m22 = this->m21 * b.m12 + this->m22 * b.m22;

    return Mat2(m11, m12, m21, m22);
};
Mat2 Mat2::operator*(complex c){
    return Mat2(this->m11 * c, this->m12 * c, this->m21 * c, this->m22 * c);
}

std::string Mat2::ToString() {

    /*
    std::string m_11 = std::to_string(real(this->m11)) + std::to_string(imag(this->m11));
    std::string m_12 = std::to_string(real(this->m12)) + std::to_string(imag(this->m12));
    std::string m_21 = std::to_string(real(this->m21)) + std::to_string(imag(this->m21));
    std::string m_22 = std::to_string(real(this->m22)) + std::to_string(imag(this->m22));
    */
    return to_string_complex(m11) + ", " + to_string_complex(m12) + "\n" + to_string_complex(m21) + ", " + to_string_complex(m22);

    //return m_11 + ", " + m_12 + "\n" + m_21 + ", " + m_22;

}

Mat2& Mat2::operator*=(complex c){
    this->m11 = this->m11 * c;
    this->m12 = this->m12 * c;
    this->m21 = this->m21 * c;
    this->m22 = this->m22 * c;
    return *this;
}

Mat2 Mat2::operator*(double c){
    return Mat2(this->m11 * c, this->m12 * c, this->m21 * c, this->m22 * c);
}
Mat2& Mat2::operator*=(double c){
    this->m11 = this->m11 * c;
    this->m12 = this->m12 * c;
    this->m21 = this->m21 * c;
    this->m22 = this->m22 * c;
    return *this;
    
}

Mat2 Mat2::operator+(Mat2 c){
    complex m11 = this->m11 + c.m11;
    complex m12 = this->m12 + c.m12;
    complex m21 = this->m21 + c.m21;
    complex m22 = this->m22 + c.m22;
    return Mat2(m11,m12,m21,m22);
}

Mat2& Mat2::operator+=(Mat2 c){
    this->m11 = this->m11 + c.m11;
    this->m12 = this->m12 + c.m12;
    this->m21 = this->m21 + c.m21;
    this->m22 = this->m22 + c.m22;
    return *this;
}
Mat2 Mat2::operator-(Mat2 c){
    complex m11 = this->m11 - c.m11;
    complex m12 = this->m12 - c.m12;
    complex m21 = this->m21 - c.m21;
    complex m22 = this->m22 - c.m22;
    return Mat2(m11,m12,m21,m22);
}


Vec2 Mat2::dot(Vec2 b){
    complex x = this->m11 * b.x + this->m12 * b.y;
    complex y = this->m21 * b.x + this->m22 * b.y;
    return Vec2(x,y);
}

