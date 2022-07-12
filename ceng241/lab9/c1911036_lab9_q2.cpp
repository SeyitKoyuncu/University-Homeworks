#include <iostream>
#include <string>
#include <vector>

using namespace std;

class car
{
    protected:
        string brandname;
        int modelyear;
        int price;
        int totalcost;

    public:
        car()
        {
            modelyear = 0;
            price = 0;
            totalcost = 0;
        }

        car(string bn, int my, int p)
        {
            brandname = bn;
            modelyear = my;
            price = p;
        }

        car(const car & obj)
        {
            brandname = obj.brandname;
            modelyear = obj.modelyear;
            price = obj.price;
        }

        string getBrandname()
        {
            return brandname;
        }

        int getModelyear()
        {
            return modelyear;
        }

        int getPrice()
        {
            return price;
        }

        int getTotalcost()
        {
            return totalcost;
        }

        void setBrandname(string bn)
        {
            brandname = bn;
        }

        void setModelyear(int m)
        {
            modelyear = m;
        }

        void setPrice(int p)
        {
            price = p;
        }   
        
        void setTotalCost(int tp)
        {
            totalcost = tp;
        }
};

class GasolineCar: virtual public car   
{
    protected:
        int engineVolume;
        int fuelCost;

    public:
        friend ostream & operator << (ostream & os, const GasolineCar & obj);

        GasolineCar()
        {
            
            brandname = " ";
            modelyear = 0;
            price = 0;
            engineVolume = 0;
            fuelCost = 0;
            totalcost = fuelCost;
        }


        GasolineCar(string bn, int my, int p, int ev, int fc) 
        {
            
            brandname = bn;
            modelyear = my;
            price = p;
            engineVolume = ev;
            fuelCost = fc;
            totalcost = fuelCost;
        }

        GasolineCar(const GasolineCar & obj) 
        {
            
            brandname = obj.brandname;
            modelyear = obj.modelyear;
            price = obj.price;
            engineVolume = obj.engineVolume;
            fuelCost = obj.fuelCost;     
            totalcost = obj.fuelCost;       
        }

        int getEngineVolume()
        {
            return engineVolume;
        }
        
        int getFuelCost()
        {
            return fuelCost;
        }

        void setEngineVolume(int ev)
        {
            engineVolume = ev;
        }

        void setFuelCost(int fc)
        {
            fuelCost = fc;
        }
};

class ElectricCar: virtual public car
{
    protected:
        int NumberOfBatteries;
        int electricCost;

    public:

        friend ostream & operator << (ostream & os, const ElectricCar & obj);

        ElectricCar()
        {
            brandname = " ";
            modelyear = 0;
            price = 0;
            NumberOfBatteries = 0;
            electricCost = 0;
            totalcost = electricCost;
        }

        ElectricCar(string bn, int my, int p, int nof, int ec) 
        {
            brandname = bn;
            modelyear = my;
            price = p;
            NumberOfBatteries = nof;
            electricCost = ec;
            totalcost = electricCost;
        }

        ElectricCar(const ElectricCar & obj)
        {
            brandname = obj.brandname;
            modelyear = obj.modelyear;
            price = obj.price;
            NumberOfBatteries = obj.NumberOfBatteries;
            electricCost = obj.electricCost;
            totalcost = obj.totalcost;            
        }

        int getNumberOfBatteries()
        {
            return NumberOfBatteries;
        }
        
        int getElectricCost()
        {
            return electricCost;
        }

        void setNumberOfBatteries(int nb)
        {
            NumberOfBatteries = nb;
        }

        void setElectricCost(int ec)
        {
            electricCost = ec;
        }

};

class Hybrid: public ElectricCar, public GasolineCar
{
    public:
        friend ostream & operator << (ostream & os, const Hybrid & obj);

        Hybrid(): GasolineCar(), ElectricCar()
        {
            brandname = " ";
            modelyear = 0;
            price = 0;
            NumberOfBatteries = 0;
            electricCost = 0;
            engineVolume = 0;
            fuelCost = 0;
            totalcost = electricCost + fuelCost;
        }

        Hybrid(string bn, int my, int p, int nof, int ec, int ev, int fc) : GasolineCar( bn,  my,  p,  ev,  fc) , ElectricCar(bn, my ,p ,nof, ec)
        {}

        Hybrid(const Hybrid & obj) : GasolineCar(obj), ElectricCar(obj)
        {
            
            brandname = obj.brandname;
            modelyear = obj.modelyear;
            price = obj.price;   
            NumberOfBatteries = obj.NumberOfBatteries;
            electricCost = obj.electricCost;    
            engineVolume = obj.engineVolume;
            fuelCost = obj.fuelCost;   
            totalcost = obj.electricCost + obj.fuelCost; 
        }
};


ostream & operator << (ostream & os, const ElectricCar & rhs)
{
    cout << rhs.brandname << " " << rhs.modelyear << " " << " price: " << rhs.price << " Number Of Batteries : " << rhs.NumberOfBatteries << " Electric Cost: " << rhs.electricCost << " Total Cost: " << rhs.totalcost << endl;
	return os;
}

ostream & operator << (ostream & os, const GasolineCar & rhs)
{
    cout << rhs.brandname << " " << rhs.modelyear << " " << " price: " << rhs.price << " Engine Volume: " << rhs.engineVolume << " Fuel Cost: " << rhs.fuelCost << " Total Cost: " << rhs.totalcost << endl;
	return os;
}

ostream & operator << (ostream & os, const Hybrid & rhs)
{
    cout << rhs.brandname << " " << rhs.modelyear << " " << " price: " << rhs.price  << " Number Of Batteries : " << rhs.NumberOfBatteries << " Electric Cost: " << rhs.electricCost << " Engine Volume: " << rhs.engineVolume << " Fuel Cost: " << rhs.fuelCost << " Total Cost: " << rhs.totalcost << endl;
	return os;
}

int main()
{
    vector <ElectricCar> objElectric;
    vector <GasolineCar> objGasoline;
    vector <Hybrid> objHybrid;

    int countElectric = 0;
    int countGasoline = 0;
    int countHybrid = 0;

    int choice;

    string name;
    int year;
    int price;
    int volume;
    int fuel;
    int electric;
    int battery;

    while(1)
    {
        cout << "1 - Elektric Car" << endl << "2 - Gasoline Car " << endl << "3 - Hybrid Car " << endl << "4- Exit" << endl;
        cin >> choice;

        if(choice == 1)
        {
            countElectric++;

            cout << "Enter brand name: ";
            cin >> name;
            cout << endl;

            cout << "Enter Model Year: ";
            cin >> year;
            cout << endl;   

            cout << "Enter Price: ";
            cin >> price;
            cout << endl;

            cout << "Enter Number Of Batteries: ";
            cin >> battery;
            cout << endl;

            cout << "Enter Electric Cost: ";
            cin >> electric;
            cout << endl;

            ElectricCar tempElectricObj(name,year,price,battery,electric);
            objElectric.push_back(tempElectricObj);
        }

        else if(choice == 2)
        {
            countGasoline++;

            cout << "Enter brand name: ";
            cin >> name;
            cout << endl;

            cout << "Enter Model Year: ";
            cin >> year;
            cout << endl;   

            cout << "Enter Price: ";
            cin >> price;
            cout << endl;

            cout << "Enter Engine Volume(CC): ";
            cin >> volume;
            cout << endl;

            cout << "Enter Fuel Cost: ";
            cin >> fuel;
            cout << endl;  

            GasolineCar tempGasolineObj(name,year,price,volume,fuel);   
            objGasoline.push_back(tempGasolineObj);      
        }

        else if(choice == 3)
        {
            countHybrid++;

            cout << "Enter brand name: ";
            cin >> name;
            cout << endl;

            cout << "Enter Model Year: ";
            cin >> year;
            cout << endl;   

            cout << "Enter Price: ";
            cin >> price;
            cout << endl;

            cout << "Enter Number Of Batteries: ";
            cin >> battery;
            cout << endl;

            cout << "Enter Electric Cost: ";
            cin >> electric;
            cout << endl;

            cout << "Enter Engine Volume(CC): ";
            cin >> volume;
            cout << endl;

            cout << "Enter Fuel Cost: ";
            cin >> fuel;
            cout << endl;         

            Hybrid tempHybridObj(name,year,price,battery,electric,volume,fuel);
            objHybrid.push_back(tempHybridObj);
        }

        else if(choice == 4)
        {
            int cheapElectric = objElectric[0].getTotalcost();
            int cheapGasoline = objGasoline[0].getTotalcost();
            int cheapHybrid = objHybrid[0].getTotalcost();

            int ndxE = 0;
            int ndxG = 0;
            int ndxH = 0;

            cout << "Electric Cars : " << endl;
            for(int i = 0; i < countElectric; i++)
            {
                cout << i+1 << "- ";
                cout << objElectric[i];

                if(objElectric[i].getTotalcost() < cheapElectric)
                    ndxE = i;
            }

            cout << "Gasoline Cars: " << endl;
            for(int i = 0; i < countGasoline; i++)
            {
                cout << i+1 << "- ";
                cout << objGasoline[i];

                if(objGasoline[i].getTotalcost() < cheapElectric)
                    ndxG = i;
            }

            
            cout << "Hybrid Cars: " << endl;
            for(int i = 0; i < countHybrid; i++)
            {
                cout << i+1 << "- ";
                cout << objHybrid[i];

                if(objHybrid[i].getTotalcost() < cheapElectric)
                    ndxH = i;
            }

            if(objHybrid[ndxH].getTotalcost() < objGasoline[ndxG].getTotalcost() && objHybrid[ndxH].getTotalcost() < objElectric[ndxE].getTotalcost())
                cout << objHybrid[ndxH].getBrandname() << " has the minumum cost of all cars";
            
            else if(objGasoline[ndxG].getTotalcost() < objHybrid[ndxH].getTotalcost() && objGasoline[ndxG].getTotalcost() < objElectric[ndxE].getTotalcost())
                cout << objGasoline[ndxG].getBrandname() << " has the minumum cost of all cars";

            else if(objElectric[ndxE].getTotalcost() < objHybrid[ndxH].getTotalcost() && objElectric[ndxE].getTotalcost() < objGasoline[ndxG].getTotalcost())
                cout << objElectric[ndxE].getBrandname() << " has the minumum cost of all cars";
            

            return 0;
        }

        else
        {
            cout << "Wrong number..." << endl;
        }
    }
    return 0;
}