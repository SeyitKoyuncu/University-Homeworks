#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Car{
protected:
    string brand_name;
    int model_year, price, total_cost;
public:
    string getBrand_name(){
        return brand_name;
    }
    void setBrand_name(string b){
        brand_name = b;
    }
    int getModel_year(){
        return model_year;
    }
    void setModel_year(int m){
        model_year = m;
    }
    int getPrice(){
        return price;
    }
    void setPrice(int p){
        price = p;
    }
    int Total_cost(){
        return total_cost;
    }
    void setTotal_cost(int t){
        total_cost = t;
    }
    Car();
    Car(string bn, int m, int p);
    Car(const Car &c);
};
Car::Car() {
    brand_name = "";
    model_year = 2000;
    price = 0;
    total_cost = 0;
}
Car::Car(string bn, int m, int p) {
    brand_name = bn;
    model_year = m;
    price = p;
}
Car::Car(const Car &c) {
    brand_name = c.brand_name;
    model_year = c.model_year;
    price = c.price;
    total_cost = c.total_cost;
}
class GasolineCar: virtual public Car{
protected:
    int engine_volume, fuel_cost;
public:
    int getEngine_volume(){
        return engine_volume;
    }
    void setEngine_volume(int e){
        engine_volume = e;
    }
    int getFuel_cost(){
        return fuel_cost;
    }
    void setFuel_cost(int f){
        fuel_cost = f;
    }
    GasolineCar();
    GasolineCar(string bn, int m, int p, int e, int f);
    GasolineCar(const GasolineCar &g);
    friend ostream & operator <<(ostream &os, const GasolineCar &obj);
};
GasolineCar::GasolineCar() {
    engine_volume = 0;
    fuel_cost = 0;
}
GasolineCar::GasolineCar(string bn, int m, int p, int e, int f) {
    brand_name = bn;
    model_year = m;
    price = p;
    engine_volume = e;
    fuel_cost = f;
}
GasolineCar::GasolineCar(const GasolineCar &g) :Car(g){
    engine_volume = g.engine_volume;
    fuel_cost = g.fuel_cost;
    total_cost = g.fuel_cost;
}
ostream & operator <<(ostream &os, const GasolineCar &obj){
    os  << endl << obj.brand_name << " " << obj.model_year << endl;
    os << "price: " << obj.price << endl;
    os << "Engine Volume: " << obj.engine_volume << endl;
    os << "Fuel cost: " << obj.fuel_cost << endl;
    os << "Total cost: " << obj.total_cost << endl;
    return os;
}
class ElectricCar: virtual public Car{
protected:
    int number_of_batteries, electric_cost;
public:
    int getNumber_of_batteries(){
        return number_of_batteries;
    }
    void setNumber_of_batteries(int n){
        number_of_batteries = n;
    }
    int getElectric_cost(){
        return electric_cost;
    }
    void setElectric_cost(int e){
        electric_cost = e;
    }
    ElectricCar();
    ElectricCar(string bn, int m, int p , int n, int e);
    ElectricCar(const ElectricCar &e);
    friend ostream & operator << (ostream &os, const ElectricCar&obj);
};
ElectricCar::ElectricCar() {
    number_of_batteries = 0;
    electric_cost = 0;
}
ElectricCar::ElectricCar(string bn, int m, int p, int n, int e) {
    brand_name = bn;
    model_year = m;
    price = p;
    number_of_batteries = n;
    electric_cost = e;
}
ElectricCar::ElectricCar(const ElectricCar &e) : Car(e) {
    number_of_batteries = e.number_of_batteries;
    electric_cost = e.electric_cost;
    total_cost = e.electric_cost;
}
ostream & operator << (ostream &os, const ElectricCar&obj){
    os  << endl << obj.brand_name << " " << obj.model_year << endl;
    os << "price: " << obj.price << endl;
    os << "Number of batteries: " << obj.number_of_batteries << endl;
    os << "Electric cost: " << obj.electric_cost << endl;
    os << "Total cost: " << obj.total_cost << endl;
}
class Hybrid :public ElectricCar, public GasolineCar{
public:
    string getname(){
        return ElectricCar::getBrand_name();
    }
    int getmodelyear(){
        return ElectricCar::getModel_year();
    }
    int getprice(){
        return ElectricCar::getPrice();
    }
    Hybrid();
    Hybrid(const Hybrid &h);
    friend ostream&operator<<(ostream &os, const Hybrid&obj);
};
Hybrid::Hybrid() : ElectricCar(), GasolineCar(){};
Hybrid::Hybrid(const Hybrid &h) : ElectricCar(h), GasolineCar(h){
    total_cost = h.electric_cost + h.fuel_cost;
};
ostream&operator<<(ostream &os, const Hybrid&obj){
    os  << endl << obj.brand_name << " " << obj.model_year << endl;
    os << "price: " << obj.price << endl;
    os << "Number of batteries: " << obj.number_of_batteries << endl;
    os << "Electric cost: " << obj.electric_cost << endl;
    os << "Engine volume: " << obj.engine_volume << endl;
    os << "Fuel Cost: " << obj.fuel_cost << endl;
    os << "Total cost: " << obj.total_cost << endl;
    return os;
}
int main() {
    vector<ElectricCar> E;
    vector<GasolineCar> G;
    vector<Hybrid> H;
    int i = 0, UI, c1 = 0, c2 = 0, c3 = 0, m, p, n, e, v, f;
    int cheap1, cheap2, cheap3, temp1, temp2, temp3;
    string bn;
    do {
        cout << "1-Electric Car" << endl;
        cout << "2-Gasoline Car" << endl;
        cout << "3-Hybrid Car" << endl;
        cout << "4-Exit" << endl;
        cin >> UI;
        if(UI == 1){
            cout << "Enter brand name: " << endl;
            cin >> bn;
            cout << "Enter the model year: " << endl;
            cin >> m;
            cout << "Enter price: " << endl;
            cin >> p;
            cout << "number of batteries: " << endl;
            cin >> n;
            cout << "Electric cost: " << endl;
            cin >> e;
            E.push_back(ElectricCar(bn, m, p, n, e));
            c1++;
        }
        else if(UI == 2){
            cout << "Enter brand name: " << endl;
            cin >> bn;
            cout << "Enter the model year: " << endl;
            cin >> m;
            cout << "Enter price: " << endl;
            cin >> p;
            cout << "Engine Volume: " << endl;
            cin >> v;
            cout << "Fuel cost: " << endl;
            cin >> f;
            G.push_back(GasolineCar(bn ,m, p, v, f));
            c2++;
        }
        else if(UI == 3){
            Hybrid hy;
            cout << "Enter brand name: " << endl;
            cin >> bn;
            cout << "Enter the model year: " << endl;
            cin >> m;
            cout << "Enter price: " << endl;
            cin >> p;
            cout << "number of batteries: " << endl;
            cin >> n;
            cout << "Electric cost: " << endl;
            cin >> e;
            cout << "Engine Volume: " << endl;
            cin >> v;
            cout << "Fuel cost: " << endl;
            cin >> f;
            hy.setBrand_name(bn);
            hy.setModel_year(m);
            hy.setPrice(p);
            hy.setNumber_of_batteries(n);
            hy.setElectric_cost(e);
            hy.setEngine_volume(v);
            hy.setFuel_cost(f);
            H.push_back(Hybrid(hy));
            c3++;
        }
        else if(UI == 4){
            break;
        }
        else{
            cout << "Wrong input type" << endl;
        }
    }while(UI != 4);
    cout << "Electric cars:" << endl;
    cheap1 = E[0].getElectric_cost();
    for(i = 0; i < c1; i++){
        if(E[i].getElectric_cost() < cheap1){
            cheap1 = E[i].getElectric_cost();
            temp1 = i;
        }
        cout << i + 1 << "-" << E[i];
    }
    cout << "Gasoline cars:" << endl;
    cheap2 = G[0].getFuel_cost();
    for(i = 0; i < c2; i++){
        if(G[i].getFuel_cost() < cheap2){
            cheap2 = G[i].getFuel_cost();
            temp2 = i;
        }
        cout << i + 1 << "-" << G[i];
    }
    cout << "Hybrid cars:" << endl;
    cheap3 = H[0].getFuel_cost() + H[0].getElectric_cost();
    for(i = 0; i < c3; i++){
        if(H[0].getFuel_cost() + H[0].getElectric_cost() < cheap3){
            cheap3 = H[0].getFuel_cost() + H[0].getElectric_cost();
            temp3 = i;
        }
        cout << i + 1 << "-" << H[i];
    }
    if(cheap1 < cheap2){
        cout  << endl << E[temp1].getBrand_name() << "Has the minimum cost of all cars." << endl;
    }
    else if(cheap1 < cheap3){
        cout  << endl << E[temp1].getBrand_name() << "Has the minimum cost of all cars." << endl;
    }
    else if(cheap2 < cheap1){
        cout  << endl << G[temp2].getBrand_name() << "Has the minimum cost of all cars." << endl;
    }
    else if(cheap2 < cheap3){
        cout  << endl << G[temp2].getBrand_name() << "Has the minimum cost of all cars." << endl;
    }
    else if(cheap3 < cheap1){
        cout  << endl << H[temp3].getBrand_name() << "Has the minimum cost of all cars." << endl;
    }
    else if(cheap3 < cheap2){
        cout  << endl << H[temp3].getBrand_name() << "Has the minimum cost of all cars." << endl;
    }
    return 0;
}
