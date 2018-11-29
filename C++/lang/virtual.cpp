#include <iostream>
using namespace std;

class Vehicle {
    public:
        virtual void apply_breaks(){
            cout << "Vehicle breaks" << endl;
        }
        virtual void apply_horn(){
            cout << "Vehicle horn" << endl;
        }
        virtual ~Vehicle(){
            cout << "Vehicle delete" << endl;
        }
};

class Car: public Vehicle {
    public:
        virtual void apply_horn(){
            cout << "Car horn" << endl;
        }
};

class MercedesCar: public Car {
    public:
        virtual void apply_horn(){
            cout << "MercedesCar horn" << endl;
        }
};

class Truck: public Vehicle {
    public:
        virtual void apply_breaks(){
            cout << "Truck breaks" << endl;
        }
};

void break_horn(Vehicle &v, string type){
    cout << endl << type << endl;
    v.apply_breaks();
    v.apply_horn();
    cout << endl;
}


int main() {
    // class has nothing but virtual function table - size should be 4
    cout << "sizeof Vehicle: " << sizeof(Vehicle) << endl;   
    cout << "sizeof Car: " << sizeof(Car) << endl;
    cout << "sizeof MercedesCar: " << sizeof(MercedesCar) << endl;
    cout << "sizeof Truck: " << sizeof(Truck) << endl;   
    cout << "Car: " << sizeof(Car) << endl;
    cout << "MercedesCar: " << sizeof(MercedesCar) << endl;
    cout << "Truck: " << sizeof(Truck) << endl;
    
    Vehicle* v = new Vehicle;
    break_horn(*v, "Vehicle");
    delete v;

    v = new Car;
    break_horn(*v, "Car");
    delete v;

    v = new MercedesCar;
    break_horn(*v, "MercedesCar");
    delete v;

    v = new Truck;
    break_horn(*v, "Truck");
    delete v;

    return 0;
}