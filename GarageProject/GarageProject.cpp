#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//global variabels
int counter=0;
int bicycleCounter = 0;
int motorcycleCounter = 0;
int carCounter = 0;
int sizeGarage = 0;
string userSearch = "";


class Vehicle //headclass of vehicles such as cars,bikes trucks etc.
{
private:

protected:
	string vehicleType;
	string manufacturer;
	string model;
	string registrationNumber;
	string colour;
	short int numberOfWheels;

public:	
	Vehicle(string a, string b, string c, string d, string e, short int i) : vehicleType (a), manufacturer(b), model(c), registrationNumber(d), colour(e), numberOfWheels(i) //Constructor
	{
	}
	virtual void set_Chassi(string x) {};
	virtual string get_Chassi() { return ""; };
	virtual void set_Horsepower(int x) {};
	virtual int get_Horsepower() { return 0; };

	virtual void set_numberOfCylinders(short int x) {};
	virtual short int get_numberOfCylinders() { return 0; };
	virtual void set_chassiNumber(int x) {};
	virtual int get_chassiNumber() { return 0; };
	   	 
	string get_VehicleType() { return vehicleType; };
	string get_Manufacturer() { return manufacturer; };
	string get_Model() {return model; };
	string get_RegistrationNumber() { return registrationNumber; };
	string get_Colour() { return colour; };
	int get_NumberOfWheels() { return numberOfWheels; };
	
	virtual void output() = 0;
	virtual ~Vehicle() //dekonstructor
	{
	};
};

class Bicycle : public Vehicle
{
protected:
	short int numberOfGears;
	

public:

	Bicycle(string a, string b, string c, string d, string e, short int i, short int inkNumberOfGears) : Vehicle(a, b, c, d, e, i)
	{
		vehicleType = "Bicycle";
		numberOfGears = inkNumberOfGears;
		cout << "Bicycle created" << endl;
	}
	void set_NumberOfGears(short int x)
	{
		numberOfGears = x;
	}


	void output()
	{
		cout << "*************\n" << "Type: " << this->vehicleType << "\nManufacturer: " << this->manufacturer << " \nModel: " << this->model << "\nRegistrationnumber: " << this->registrationNumber << "\nColour: " << this->colour << "\nNumber of wheels: " << this->numberOfWheels << "\n*************" << endl;
	}

	void PrintAllTypeOfVehicles()
	{
		cout << "Number of bicycels in the garage is: " << bicycleCounter << endl;
	}

	~Bicycle() //dekonstructor
	{
		//cout << "This is the deconstructor of BICYCLE" << endl;		
	};
};

class Motorcycle : public Vehicle
{
protected:
	short int numberOfCylinders;
	int chassiNumber;

public:

	Motorcycle(string a, string b, string c, string d, string e, short int i, short int inkNumberOfCylinders, int inkChassiNumber) : Vehicle(a, b, c, d, e, i)
	{
		vehicleType = "Motorcycle";
		numberOfCylinders = inkNumberOfCylinders;
		chassiNumber = inkChassiNumber;

		cout << "Motorcycle created" << "\n" << endl;
	}
	void set_NumberOfCylinders(short int x)
	{
		numberOfCylinders = x;
	}
	void set_ChassiNumber(int x)
	{
		chassiNumber = x;
	}

	void output()
	{
		cout << "*************\n" << "Type: " << this->vehicleType << "\nManufacturer: " << this->manufacturer << " \nModel: " << this->model << "\nRegistrationnumber: " << this->registrationNumber << "\nColour: " << this->colour << "\nNumber of wheels: " << this->numberOfWheels << "\nNumber of cylinders: " << this->numberOfCylinders << "\nChassinumber: "<< this->chassiNumber<<"\n*************" << endl;
	}

	void PrintAllTypeOfVehicles()
	{
		cout << "Number of motorcycels in the garage is: " << motorcycleCounter << endl;
	}

	~Motorcycle() //dekonstructor
	{
		//cout << "This is the deconstructor of MOTORCYCLE" << endl;		
	};
};

class Car : public Vehicle
{
protected:	
	string chassi;
	int horsePower;

public:	
	Car(string a, string b, string c, string d, string e, short int i, string inkChassi, int inkHorsepower) : Vehicle(a,b,c,d,e,i)
	{
		vehicleType = "Car";
		chassi = inkChassi;
		horsePower = inkHorsepower;
		cout << "Car created" << "\n" << endl;			
	}
	
	void set_Chassi(string x) 
	{
		chassi = x;		
	}
	void set_HorsePower(int x) 
	{
		horsePower = x;		
	}
	
	string get_Chassi() { return chassi; };
	int get_Horsepower() { return horsePower; };	
	
	void output()
	{
		cout << "*************\n" << "Type: " << this->vehicleType << "\nManufacturer: " << this->manufacturer << " \nModel: " << this->model << "\nRegistrationnumber: " << this->registrationNumber << "\nColour: " << this->colour << "\nNumber of wheels: " << this->numberOfWheels << "\nChassi: " << this->chassi << "\nHorsepower: " << this->horsePower << "\n*************" << endl;
	}
	void PrintAllTypeOfVehicles()
	{
		cout << "Number of cars in the garage is now: " << carCounter << endl;
	}	

	~Car() //dekonstructor
	{
		//cout << "This is the deconstructor of CAR" << endl;
	};
};


class Garage //representation of the "building" itself. The garage can store x number of vehicles
{
protected:

public:
	
	vector <Vehicle*> myGarage;
	int numberOfVehicles()  // returns the total number of vehicles stored in the garage
	{ 
		cout << "Total number of vehicles in the garage is: ";
		return myGarage.size();
	}
	   	 
	void addVehicle(Vehicle* x)
	{

		if (numberOfVehicles() < sizeGarage)
		{		
			myGarage.push_back(x);	
			counter++;
			//cout << "New vehicle parked in the garage. Number of vehicles is now: " << counter  <<"\n"<< endl;
		
			if (x->get_VehicleType() == "Bicycle")
			{
				bicycleCounter++;
			}
			if (x->get_VehicleType() == "Motorcycle")
			{
				motorcycleCounter++;			
			}
			if (x->get_VehicleType() == "Car")
			{
				carCounter++;
			}
		}
		else
		{
			cout << "Garage is full, your vehicle could not be parked" << endl;
		}
	}

	Vehicle* SearchAndRemove(vector <Vehicle*> &x, string y)
	{
		for (int i = 0; i < x.size(); i++)
		{
			if (x[i]->get_RegistrationNumber() == y)
			{
				cout << "Found your vehicle, it is now being removed" << endl;
				delete x[i];
				x.erase(remove(x.begin(), x.end(), x[i]), x.end());
				break;
			}
		}
		return 0;
	}

	void printAllVehicles(vector <Vehicle*> x)
	{
		for (int i = 0; i < x.size(); i++)
		{			
			x[i]->output();			
		}
	}

	void printAllCars(vector <Vehicle*> x)
	{
		for (int i = 0; i < x.size(); i++)
		{
			if (x[i]->get_VehicleType()=="Car")
			{
				x[i]->output();
			}
		}
	}

	void printAllMotorcycles(vector <Vehicle*> x)
	{
		for (int i = 0; i < x.size(); i++)
		{
			if (x[i]->get_VehicleType() == "Motorcycle")
			{
				x[i]->output();
			}
		}
	}

	void searchRegnr(vector <Vehicle*> x, string y)
	{
		for (int i = 0; i < x.size(); i++)
		{
			if (x[i]->get_RegistrationNumber() == y)
			{
				cout << "FOUND YOUR VEHICLE!!!!"<< endl;
				x[i]->output();
				break;
			}			
		}
	}

	~Garage() //dekonstructor
	{	
	};
};


int main()
{
	int selection;
	
	cout << "Welcome to the garage" << endl;
	cout << "To start, enter the size of the garage: ";
	cin >> sizeGarage;
	cout << endl;

	Garage garage; //Create a garage-object
	
	do
	{
		cout << "  ====================================\n";
		cout << "	Welcome to the garage\n";
		cout << "  ====================================\n";
		cout << "  1.  Add a vehicle to the garage\n";
		cout << "  2.  Remove a vehicle from garage\n";
		cout << "  3.  Search for a vehicle with reg-number\n";
		cout << "  4.  Search for a vehicle by entering attribut\n";
		cout << "  5.  List all vehicles in garage\n";
		cout << "  6.  List type of vehicles\n"; 
		cout << "\n";
		cout << "  0.  Exit\n";
		cout << "\n";
		cout << "  ====================================\n";
		cout << "  Enter your selection: ";
		cin >> selection;
		cout << endl;

		switch (selection)
		{
		case 1:
		{
			int addVehicleInput;
			cout << endl;
			cout << "What type of vehicle would you like to add?" << endl;
			cout << "1. Bicycle" << endl;
			cout << "2. Motorcycle" << endl;
			cout << "3. Car" << endl;
			cout << "4. Bus" << endl;
			cout << "5. Truck" << endl;
			cin >> addVehicleInput;

			string inBicycleManufacturer;
			string inBicycleModel;
			string  inBicycleRegnumber;
			string inBicycleColour;
			int inBicycleNumberOfWheels;

			if (addVehicleInput == 1)
			{
				string inBicycleManufacturer;
				string inBicycleModel;
				string  inBicycleRegnumber;
				string inBicycleColour;
				int inBicycleNumberOfWheels;
				short int inBicycleNumberOfGears;

				cout << "Enter manufacturer: " << endl;
				cin >> inBicycleManufacturer;
				cout << "Enter model: " << endl;
				cin >> inBicycleModel;
				cout << "Enter regnumber: " << endl;
				cin >> inBicycleRegnumber;
				cout << "Enter colour:" << endl;
				cin >> inBicycleColour;
				cout << "Enter number of wheels: " << endl;
				cin >> inBicycleNumberOfWheels;
				cout << "Enter number of gears: " << endl;
				cin >> inBicycleNumberOfGears;

				Vehicle* ptrBicycle = new Bicycle("", inBicycleManufacturer, inBicycleModel, inBicycleRegnumber, inBicycleColour, inBicycleNumberOfWheels, inBicycleNumberOfGears);
				garage.addVehicle(ptrBicycle);
			}
			if (addVehicleInput == 2)
			{
				string inMotorcycleManufacturer;
				string inMotorcycleModel;
				string  inMotorcycleRegnumber;
				string inMotorcycleColour;
				int inMotorcycleNumberOfWheels;
				short int inMotorcycleNumberOfCylinders;
				int inMotorcycleChassiNumber;

				cout << "Enter manufacturer: " << endl;
				cin >> inMotorcycleManufacturer;
				cout << "Enter model: " << endl;
				cin >> inMotorcycleModel;
				cout << "Enter regnumber: " << endl;
				cin >> inMotorcycleRegnumber;
				cout << "Enter colour:" << endl;
				cin >> inMotorcycleColour;
				cout << "Enter number of wheels: " << endl;
				cin >> inMotorcycleNumberOfWheels;
				cout << "Enter number of cylinders: " << endl;
				cin >> inMotorcycleNumberOfCylinders;
				cout << "Enter chassinumber: " << endl;
				cin >> inMotorcycleChassiNumber;

				Vehicle* ptrMotorcycle = new Motorcycle("", inMotorcycleManufacturer, inMotorcycleModel, inMotorcycleRegnumber, inMotorcycleColour, inMotorcycleNumberOfWheels, inMotorcycleNumberOfCylinders, inMotorcycleChassiNumber);
				garage.addVehicle(ptrMotorcycle);
			}
			if (addVehicleInput == 3)
			{
				string inCarManufacturer;
				string inCarModel;
				string  inCarRegnumber;
				string inCarColour;
				int inCarNumberOfWheels;
				string inCarChassi;
				int inCarHorsepower;

				cout<< "Enter manufacturer: " << endl;
				cin >> inCarManufacturer;
				cout << "Enter model: " << endl;
				cin >> inCarModel;
				cout << "Enter regnumber: " << endl;
				cin >> inCarRegnumber;
				cout << "Enter colour:" << endl;
				cin >> inCarColour;
				cout << "Enter number of wheels: " << endl;
				cin >> inCarNumberOfWheels;
				cout << "Enter chassitype: " << endl;
				cin >> inCarChassi;
				cout << "Enter horsepower: " << endl;
				cin >> inCarHorsepower;
				Vehicle* ptrCar = new Car("", inCarManufacturer, inCarModel, inCarRegnumber, inCarColour, inCarNumberOfWheels, inCarChassi, inCarHorsepower);

				garage.addVehicle(ptrCar);				
			}
		}
			/*
			if (addVehicleInput == 4)
			{
				cout << "Enter manufacturer: " << endl;
				cin >> inManufacturer;
				cout << "Enter model: " << endl;
				cin >> inModel;
				cout << "Enter regnumber: " << endl;
				cin >> inRegnumber;
				cout << "Enter colour:" << endl;
				cin >> inColour;
				cout << "Enter number of wheels: " << endl;
				cin >> inNumberOfWheels;
			}

			if (addVehicleInput == 5)
			{
				cout << "Enter manufacturer: " << endl;
				cin >> inManufacturer;
				cout << "Enter model: " << endl;
				cin >> inModel;
				cout << "Enter regnumber: " << endl;
				cin >> inRegnumber;
				cout << "Enter colour:" << endl;
				cin >> inColour;
				cout << "Enter number of wheels: " << endl;
				cin >> inNumberOfWheels;
			}
			*/
			cout << endl;
			break;

	
		case 2:
		{
			string inputRemoveVehicle;
			cout << endl;
			cout << "Enter the registartionnumber of the vehicle you want to remove: " << endl;
			cin >> inputRemoveVehicle;

			garage.SearchAndRemove(garage.myGarage, inputRemoveVehicle);

			cout << endl;
			break;
		}

		case 3:
		{
			cout << "\n Search for a vehicle with reg-number:";
			cin >> userSearch;
			garage.searchRegnr(garage.myGarage, userSearch);
			cout << endl;
			break;
		}

		case 4:
		{
			cout << endl;
			cout << "Choose what attribute you want to search for" << endl;
			cout << "1. Manufacturer" << endl;
			cout << "2. Model" << endl;
			cout << "3. Colour" << endl;
			cout << "4. Number of wheels" << endl;
			cout << "5. " << endl;
	
			cout << endl;
			break;
		}

		case 5:
		{
			cout << endl;
			garage.printAllVehicles(garage.myGarage);
			cout << endl;
			break;
		}

		case 6:
		{
			int listInput;
			cout << endl;
			cout << "Wich vehicletype would you like to list?" << endl;
			cout << "1. Bicycles" << endl;
			cout << "2. Motorcycles" << endl;
			cout << "3. Cars" << endl;
			cout << "4. Buses" << endl;
			cout << "5. Trucks" << endl;
			cin >> listInput;
			if (listInput == 1)
			{

			}
			if (listInput==2)
			{
				cout << "Here is all the motorcycles in the garage:" << endl;
				garage.printAllMotorcycles(garage.myGarage);

			}
			if (listInput==3)
			{
				cout << "Here is all the cars in the garage:" << endl;
				garage.printAllCars(garage.myGarage);
			}
			cout << endl;
			break;
		}


		case 0:
		{
			cout << endl;
			cout << endl;
			break;
		}

		default: cout << selection << " is not a valid menu item.\n";
			cout << endl;
		}

	} while (selection != 0);			


	garage.myGarage[1]->output();
	garage.myGarage[2]->output();
	garage.myGarage.erase(remove(garage.myGarage.begin(), garage.myGarage.end(), garage.myGarage[1]), garage.myGarage.end()); // inte kopplad till counters i detta läge
	garage.myGarage[1]->output();
	garage.myGarage[2]->output();

	
	//garage.removeVehicle(ptrCarOne); // calls the removeVehicle-function and removes the element and deletes the pointer-object	
	

	cout << "Main-counter " << counter << endl;
	cout <<"MC-counter "<< motorcycleCounter <<endl;
	cout <<"CAR-counter "<< carCounter << endl;
	cout << endl;

	

	


	return 0;
}


