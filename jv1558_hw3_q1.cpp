// Justin Veras - Extended CS Bridge Summer 2020 - Homework 3 - Question 1//

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
//------------------------------------------------- Variables --------------------------------------------------------//
    double item1Price, item2Price, taxRate, basePrice, salePrice, discountPrice, totalPrice, taxPrice ;
    char clubCard;
//------------------------------------------------- User input  ------------------------------------------------------//
    cout << "Enter price of first item: " ;

    cin >> item1Price;

    cout << "Enter price of second item: ";

    cin >> item2Price;

    cout << "Does customer have a club card? (Y/N): ";

    cin >> clubCard;

    cout << "Enter tax rate, e.g. 5.5 for 5.5% tax: ";

    cin >> taxRate;
//------------------------------------------------- Base Price ------------------------------------------------------//
    basePrice = item1Price + item2Price;


    cout << "Base price: "  << basePrice <<  endl;
//------------------------------------------------- Discounts  ------------------------------------------------------//
    if(item1Price > item2Price)
        item2Price = item2Price / 2;
    else if(item1Price < item2Price)
        item1Price = item1Price / 2;
    else
        item1Price = item1Price/2;

    salePrice = item1Price + item2Price;

    if(clubCard == 'Y' || clubCard == 'y')
        discountPrice = salePrice * .9;
    else if(clubCard == 'N' || clubCard == 'n')
        discountPrice = salePrice;

    cout << "Price after discounts: " << discountPrice << endl;
//------------------------------------------------- Tax Rate  ------------------------------------------------------//
    taxRate = taxRate / 100;

    taxPrice = discountPrice * taxRate;

    totalPrice = discountPrice + taxPrice;

    cout << setprecision(7) << "Total price: " << totalPrice;

    return 0;
}
