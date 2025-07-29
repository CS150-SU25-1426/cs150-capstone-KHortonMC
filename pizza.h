// To make sure we don't include our pizza multiple times
// which could lead to symbol collision
// we use pre-processor directives
#ifndef PIZZA_H // checks if Pizza hasn't been defined
#define PIZZA_H // makes sure it's defined only once

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// We've created a template/promise of what
// our pizza class will do
class Pizza {
private: 
    // we declare class-level variables
    static const int MAX_TOPPINGS = 10;
    static const int DEFAULT_SLICES = 12;

    // and we declare instance level variables
    // these let the compiler know how much space
    // to reserve for the class (ie: pointer++)
    // how much space you skip with a pointer increment
    int slices;
    vector<string> toppings;

public:
    // Even our constructors can be forward declared
    Pizza();
    Pizza(const Pizza& other);
    ~Pizza();

    // All our logic should be forward declared
    // this way we can change functionality
    // without changing interface
    void addTopping(string topping);
    void display();
    void eatSlice();

protected: 
};

#endif // PIZZA_H, end the definition