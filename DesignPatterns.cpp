/*
Zlata Babych
Design Patterns in C++
*/

#include <iostream>
#include<string>
using namespace std;

namespace FactoryMethod{
/*"Фабричный метод (FactoryMethod)".
пример порождающего шаблона проектирования программ «Фабричный метод», 
который предоставляет дочерним классам интерфейс 
для создания экземпляров некоторого класса. 
В момент создания наследники могут определить какой класс создавать. 
Это позволяет использовать в коде программы неспецифические классы, 
а манипулировать абстрактными объектами на более высоком уровне.*/

class IProduct {
public:
    virtual void create() = 0;
};

class Car: public IProduct {
public:
    void create() override {
        cout << " New Car " << endl;
    }
};

class Ship : public IProduct {
public:
    void create() override {
        cout << " New Ship " << endl;
    }
};

class ICompany {
public:
    virtual IProduct* create() = 0;
};

class CarCompany: public ICompany {
public:
    IProduct* create() override {
        return new Car;
    }
};

class ShipCompany : public ICompany {
public:
    IProduct* create() override {
        return new Ship;
    }
};


/*main:
ICompany* fordCompany = new CarCompany;
    IProduct* newCar1 = fordCompany->create();
    newCar1->create();
    IProduct* newCar2 = fordCompany->create();
    newCar2->create();
    delete fordCompany;

    fordCompany = new ShipCompany;
    IProduct* newShip1 = fordCompany->create();
    newShip1->create();

    newCar1->create();
    newCar2->create();*/
}

int main()
{
    
    return 0;
}

