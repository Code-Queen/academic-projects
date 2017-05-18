#pragma once
// STL Containers
// Product.h
// Date 2016/11/06

#ifndef _I_PRODUCT_H_
#define _I_PRODUCT_H_
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

namespace w7 {

    class iProduct {
    public:
         virtual float getPrice() const =0;
         virtual char getTax() const =0;
         virtual void display(std::ostream&) const=0;
    };

    class Product: public iProduct{
        int product_number;
        float price;
    public:
        Product(){
            product_number=0;
            price=0;
        };
        Product(int product_number_new, float price_new):product_number(product_number_new), price(price_new){
        };
        ~Product(){
            product_number=0;
            price=0;
        };
        float getPrice() const{
            return price;
        }
        void display(std::ostream& os) const{
            std::cout.width(10);
            os << product_number << " " ;
            std::cout.width(9);
            os << std::fixed << std::setprecision(2) <<  getPrice();
        };
        char getTax() const{
            return ' ';
        };
    };

    class TaxableProduct: public Product{
    private:
        char tax;
    public:
        TaxableProduct(){
            Product::Product();
        };
        TaxableProduct(int product_number_n, float price_n, char new_tax): Product::Product(product_number_n,price_n), tax(new_tax){
        };
        ~TaxableProduct(){
          //  Product::~Product();
           // tax = nullptr;
        };
        char getTax() const{
            return tax;
        }; 
        void display(std::ostream& os) const{
            Product::display(os);
            os << " " << tax;
        };
    };
 }

 #endif