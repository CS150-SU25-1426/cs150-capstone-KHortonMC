// in C++ implementation files (.cpp) hold
// the code that actually does the work

#include "pizza.h"

// because this is all forward declared in the
// .h file, we need to implement it all here
// 
// when we modify any of these methods
// only this file gets recompiled
// and then it gets linked in at the end

Pizza::Pizza() {
    cout << "Pizza constructor ran!\n";
    this->slices = DEFAULT_SLICES;
}

Pizza::Pizza(const Pizza& other) {
    cout << "Pizza copy constructor ran!\n";
    this->slices = other.slices;

    for (string topping : other.toppings) {
        this->toppings.push_back(topping);
    }
}

Pizza::~Pizza() {
    cout << "Pizza destructor ran!\n";
    while (toppings.size() > 0) {
        toppings.pop_back();
    }
}

void Pizza::addTopping(string topping)
{
    toppings.push_back(topping);
}

void Pizza::display()
{
    cout << "Pizza has toppings: ";
    for (int i = 0; i < toppings.size(); i++) {
        cout << toppings.at(i) << (i < toppings.size() - 1 ? ", " : "\n");
    }
    cout << "Slices left: " << slices << "\n";
}

void Pizza::eatSlice() 
{
    if (slices == 0) {
        cout << "Can't eat a slice, none are left!\n";
    }
    else {
        --slices;
        cout << "Slice eaten, there are " << slices << " remaining\n";
    }       
}