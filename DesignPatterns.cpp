/*
Zlata Babych
Design Patterns in C++
*/

#include <iostream>
#include<string>
using namespace std;
using namespace Builder;

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

/*"Строитель (Builder)".
пример порождающего шаблона проектирования программ «Строитель», 
который предоставляет способ создания составного объекта. 
Он отделяет конструирование сложного объекта от его представления так, 
что в результате одного и того же процесса конструирования 
могут получаться разные представления.*/

namespace Builder {
    class Phone {
        string data;
    public:
        Phone() {
            data = "";
        }

        string getData() {
            return data;
        }

        void appendData(string str) {
            data += str;
        }
    };

    class IDeveloper {
    public:
        virtual void createDisplay() = 0;
        virtual void createBox() = 0;
        virtual void systemInstall() = 0;

        virtual Phone* getPhone() = 0;
    };

    class AndroidDeveloper : public IDeveloper {
        Phone* phone;
    public:
        AndroidDeveloper() {
            phone = new Phone();
        }

        virtual ~AndroidDeveloper() {
            delete phone;
        }

         void createDisplay() override {
            phone->appendData("create display Samsung; ");
        }

         void createBox() override {
            phone->appendData("create corpus (box) Samsung; ");
        }

         void systemInstall() override {
            phone->appendData("install system Android; ");
        }

         Phone* getPhone() override {
            return phone;
        }
    };

    class IPhoneDeveloper : public IDeveloper {
        Phone* phone;
    public:
        IPhoneDeveloper() {
            phone = new Phone();
        }

         ~IPhoneDeveloper() {
            delete phone;
        }

         void createDisplay() override {
            phone->appendData("create display Apple; ");
        }

         void createBox() override {
            phone->appendData("create corpus (box) Apple; ");
        }

         void systemInstall() override {
            phone->appendData("install system IOS; ");
        }

         Phone* getPhone() {
            return phone;
        }
    };

    class Director {
        IDeveloper* developer;
    public:
        Director(IDeveloper* devel): developer(devel) {}

        void setDeveloper(IDeveloper* devel) {
            developer = devel;
        }

        Phone* onlyPhone() {
            developer->createBox();
            developer->createDisplay();
            return developer->getPhone();
        }

        Phone* fullPhone() {
            developer->createBox();
            developer->createDisplay();
            developer->systemInstall();
            return developer->getPhone();
        }

    };
}



int main()
{
    
    return 0;
}

