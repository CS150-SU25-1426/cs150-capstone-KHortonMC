// Lecture 15b -- Multi File Classes

// When we include our own headers (.h)
// we need to use ".h" vs the system
// headers which use < >
#include "pizza.h"

void deliverPizzaByVal(Pizza pizza) {
    cout << "Pizza Val Delivered!\n";
    pizza.eatSlice();
}

void deliverPizzaByRef(Pizza& pizza) {
    cout << "Pizza Ref Delivered!\n";
    pizza.eatSlice();
}

void deliverPizzaByPtr(Pizza* pizza) {
    cout << "Pizza Ptr Delivered!\n";
    pizza->eatSlice();
}

int main() {
// CLASSES

    // classes can be created in stack memory
    // just like any other variable
    Pizza chicken;
    // notice, we can't access the private slices!
    //cout << "Slices: " << chicken.slices << "\n";

    chicken.addTopping("BBQ Chicken");
    chicken.display();
    // we don't have to delete chicken
    // it'll automatically deleted
    // when it falls out of scope

    // passing by value will invoke a copy constructor!
    deliverPizzaByVal(chicken);
    cout << "After delivering by value our pizza is unchanged: \n";
    chicken.display();

    // passing be reference does not create a new copy
    deliverPizzaByRef(chicken);
    cout << "After delivering by reference our pizza has changed: \n";
    chicken.display();
    
    // passing by pointer also does not create a new copy
    deliverPizzaByPtr(&chicken);
    cout << "After delivering by pointer our pizza has changed: \n";
    chicken.display();

    // classes can be created in heap memory
    // with a new just like any other variable
    Pizza* pepperoni = new Pizza();
    pepperoni->addTopping("Pepperoni");
    pepperoni->display();
    pepperoni->eatSlice();
    // if this doesn't get deleted,
    // it will persist forever (or until program shutdown)
    // but the pointer will fall out of scope
    delete pepperoni; // delete all new!
    pepperoni = nullptr; // clear pointers!

    return 0;
}