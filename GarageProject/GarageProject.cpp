#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//Global variables
int counter=0;
int bicycleCounter = 0;
int motorcycleCounter = 0;
int carCounter = 0;
int busCounter = 0;
int truckCounter = 0;
int sizeGarage = 0;
string userSearch = "";

//Abstract headclass 
class Vehicle
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
	Vehicle(string a, string b, string c, string d, string e, short int i) : vehicleType (a), manufacturer(b), model(c), registrationNumber(d), colour(e), numberOfWheels(i)
	{
	}

	string get_VehicleType() { return vehicleType; };
	string get_Manufacturer() { return manufacturer; };
	string get_Model() { return model; };
	string get_RegistrationNumber() { return registrationNumber; };
	string get_Colour() { return colour; };
	int get_NumberOfWheels() { return numberOfWheels; };

	virtual void set_numberOfGears(int x) {};
	virtual int get_numberOfGears() { return 0; };
	virtual void set_Year(int x) {};
	virtual int get_Year() { return 0; };

	virtual void set_numberOfCylinders(short int x) {};
	virtual short int get_numberOfCylinders() { return 0; };
	virtual void set_chassiNumber(int x) {};
	virtual int get_chassiNumber() { return 0; };

	virtual void set_Chassi(string x) {};
	virtual string get_Chassi() { return ""; };
	virtual void set_Horsepower(int x) {};
	virtual int get_Horsepower() { return 0; };

	virtual void set_NumberOfPassengers(int x) {};
	virtual int get_NumberOfPassengers() { return 0; };
	virtual void set_NumberOfDoors(int x) {};
	virtual int get_NumberOfDoors() { return 0; };

	virtual void set_Load(string x) {};
	virtual string get_Load() { return ""; };
	virtual void set_Weight(int x) {};
	virtual int get_Weight() { return 0; };
		
	virtual void output() = 0;
	virtual ~Vehicle(){};
};

//Subclasses inherited from headclass, with 2 extra attributes
class Bicycle : public Vehicle
{
protected:
	short int numberOfGears;
	int year;	

public:
	

	Bicycle(string a, string b, string c, string d, string e, short int i, short int inkNumberOfGears, int inkYear) : Vehicle(a, b, c, d, e, i)
	{
		vehicleType = "Bicycle";
		numberOfGears = inkNumberOfGears;
		year = inkYear;
		cout << "Bicycle created" << "\n" << endl;
	}
	void set_NumberOfGears(short int x)
	{
		numberOfGears = x;
	}

	void set_Year(int x)
	{
		year = x;
	}

	int get_NumberOfGears() { return numberOfGears; };
	int get_Year() { return year; };

	void output()
	{
		cout << "\n*************\n" << "Type: " << vehicleType << "\nManufacturer: " << manufacturer << " \nModel: " << model << "\nRegistrationnumber: " << registrationNumber << "\nColour: " << colour << "\nNumber of wheels: " << numberOfWheels << "\nNumber of gears: " << numberOfGears << "\nYear: " << year << "\n*************\n" << endl;
	}

	~Bicycle()
	{				
	};
};

//Subclasses inherited from headclass, with 2 extra attributes
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
		cout << "\n*************\n" << "Type: " << vehicleType << "\nManufacturer: " << manufacturer << " \nModel: " << model << "\nRegistrationnumber: " << registrationNumber << "\nColour: " << colour << "\nNumber of wheels: " << numberOfWheels << "\nNumber of cylinders: " << numberOfCylinders << "\nChassinumber: "<< chassiNumber<<"\n*************\n" << endl;
	}

	~Motorcycle()
	{				
	};
};

//Subclasses inherited from headclass, with 2 extra attributes
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
		cout << "\n*************\n" << "Type: " << vehicleType << "\nManufacturer: " << manufacturer << " \nModel: " << model << "\nRegistrationnumber: " << registrationNumber << "\nColour: " << colour << "\nNumber of wheels: " << numberOfWheels << "\nChassi: " << chassi << "\nHorsepower: " << horsePower << "\n*************\n" << endl;
	}	

	~Car()
	{		
	};
};

//Subclasses inherited from headclass, with 2 extra attributes
class Bus : public Vehicle
{
protected:
	int numberOfDoors;
	int numberOfPassengers;

public:
	Bus(string a, string b, string c, string d, string e, short int i, int inkNumberOfDoors, int inkNumberOfPassengers) : Vehicle(a, b, c, d, e, i)
	{
		vehicleType = "Bus";
		numberOfDoors = inkNumberOfDoors;
		numberOfPassengers = inkNumberOfPassengers;
		cout << "Bus created" << "\n" << endl;
	}

	void set_NumberOfPassengers(int x)
	{
		numberOfPassengers = x;
	}	

	int get_NumberOfPassengers() { return numberOfPassengers; };

	void set_NumberOfDoors(int x)
	{
		numberOfDoors = x;
	}

	int get_NumberOfDoors() { return numberOfDoors; };

	void output()
	{
		cout << "\n*************\n" << "Type: " << vehicleType << "\nManufacturer: " << manufacturer << " \nModel: " << model << "\nRegistrationnumber: " << registrationNumber << "\nColour: " << colour << "\nNumber of wheels: " << numberOfWheels << "\nNumber of doors: " << numberOfDoors << "\nNumber of passengers: " << numberOfPassengers << "\n*************\n" << endl;
	}

	~Bus()
	{	
	};
};

//Subclasses inherited from headclass, with 2 extra attributes
class Truck : public Vehicle
{
protected:
	int weight;
	string load;

public:
	Truck(string a, string b, string c, string d, string e, short int i, int inkWeight, string inkLoad) : Vehicle(a, b, c, d, e, i)
	{
		vehicleType = "Truck";
		weight = inkWeight;
		load = inkLoad;
		cout << "Truck created" << "\n" << endl;
	}

	void set_Load(string x)
	{
		load = x;
	}

	void set_Weight(int x)
	{
		weight=x;
	}

	string get_Load() { return load; };
	int get_Weight() { return weight; };

	void output()
	{
		cout << "\n*************\n" << "Type: " << vehicleType << "\nManufacturer: " << manufacturer << " \nModel: " << model << "\nRegistrationnumber: " << registrationNumber << "\nColour: " << colour << "\nNumber of wheels: " << numberOfWheels << "\nWeight: "<< weight <<"\nType of load: " << load << "\n*************\n" << endl;
	}

	~Truck()
	{		
	};
};

//Garageclass, represent the "building" itself and stores all the different types of vehicles
class Garage
{
protected:
	vector <Vehicle*> myGarage;
public:	
	
	int numberOfVehicles() 
	{	
		return myGarage.size();
	}
	   	 
	void addVehicle(Vehicle* x)
	{				
		myGarage.push_back(x);	
		counter++;
				
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
		if (x->get_VehicleType() == "Bus")
		{
			busCounter++;
		}
		if (x->get_VehicleType() == "Truck")
		{
			truckCounter++;
		}
	}

	Vehicle* SearchAndRemove(string y)
	{		
		for (int i = 0; i < myGarage.size(); i++)
		{
			if (myGarage[i]->get_RegistrationNumber() == y)
			{
				if (myGarage[i]->get_VehicleType() == "Bicycle")
				{
					bicycleCounter--;
				}
				if (myGarage[i]->get_VehicleType() == "Motorcycle")
				{
					motorcycleCounter--;
				}
				if (myGarage[i]->get_VehicleType() == "Car")
				{
					carCounter--;
				}
				if (myGarage[i]->get_VehicleType() == "Bus")
				{
					busCounter--;
				}
				if (myGarage[i]->get_VehicleType() == "Truck")
				{
					truckCounter--;
				}
				cout << "Found your vehicle, it is now being removed\n" << endl;
				myGarage[i]->output();
				delete myGarage[i];
				counter--;
				myGarage.erase(remove(myGarage.begin(), myGarage.end(), myGarage[i]), myGarage.end());
				break;
			}
		}
		cout <<"Number of vehicles is now: "<< counter << endl;
		return 0;
	}

	//delete the object in the vector and clears vector
	Vehicle* Destroy()
	{
		for (int i = 0; i < myGarage.size(); i++)
		{ 
			delete myGarage[i];
		}
		cout << "The garage is now destroyed!" << endl;
		myGarage.clear();
		return 0;
	}

	void printAllVehicles()
	{
		for (int i = 0; i < myGarage.size(); i++)
		{			
			myGarage[i]->output();
		}

		cout << "Number of vehicles in the garage is: " << counter << "\n" << endl;		
	}

	void printAllBicycles()
	{
		for (int i = 0; i < myGarage.size(); i++)
		{
			if (myGarage[i]->get_VehicleType() == "Bicycle")
			{
				myGarage[i]->output();
			}
		}

		cout << "Number of bicycles in the garage is: " << bicycleCounter << "\n" << endl;	
	}

	void printAllMotorcycles()
	{
		for (int i = 0; i < myGarage.size(); i++)
		{
			if (myGarage[i]->get_VehicleType() == "Motorcycle")
			{
				myGarage[i]->output();
			}
		}
		cout << "Number of motorcycles in the garage is: " << motorcycleCounter << "\n" << endl;
	}

	void printAllCars()
	{
		for (int i = 0; i < myGarage.size(); i++)
		{
			if (myGarage[i]->get_VehicleType()=="Car")
			{
				myGarage[i]->output();
			}
		}
		cout << "Number of cars in the garage is: " << carCounter << "\n" << endl;
	}

	void printAllBuses()
	{
		for (int i = 0; i < myGarage.size(); i++)
		{
			if (myGarage[i]->get_VehicleType() == "Bus")
			{
				myGarage[i]->output();
			}
		}
		cout << "Number of buses in the garage is: " << busCounter << "\n" << endl;
	}

	void printAllTrucks()
	{
		for (int i = 0; i < myGarage.size(); i++)
		{
			if (myGarage[i]->get_VehicleType() == "Truck")
			{
				myGarage[i]->output();
			}
		}
		cout << "Number of trucks in the garage is: " << truckCounter << "\n" << endl;
	}
	
	void searchRegnr(string y)
	{
		for (int i = 0; i < myGarage.size(); i++)
		{
			if (myGarage[i]->get_RegistrationNumber() == y)
			{
				cout << "FOUND YOUR VEHICLE!!!!"<< endl;
				myGarage[i]->output();
				break;
			}			
		}
	}

	void searchByAttributManufacturer(string y)
	{
		for (int i = 0; i < myGarage.size(); i++)
		{
			if (myGarage[i]->get_Manufacturer() == y)
			{
				cout << "\nFOUND A VEHICLE WITH THE ATTRIBUT YOU SEARCHED FOR!\n" << endl;
				myGarage[i]->output();
			}
		}
	}

	void searchByAttributModel(string y)
	{
		for (int i = 0; i < myGarage.size(); i++)
		{
			if (myGarage[i]->get_Model() == y)
			{
				cout << "\nFOUND A VEHICLE WITH THE ATTRIBUT YOU SEARCHED FOR!\n" << endl;
				myGarage[i]->output();
			}
		}
	}

	void searchByAttributColour(string y)
	{
		for (int i = 0; i < myGarage.size(); i++)
		{
			if (myGarage[i]->get_Colour() == y)
			{
				cout << "\nFOUND A VEHICLE WITH THE ATTRIBUT YOU SEARCHED FOR!\n" << endl;
				myGarage[i]->output();
			}
		}
	}

	void searchByAttributNumberOfWheels(int y)
	{
		for (int i = 0; i < myGarage.size(); i++)
		{
			if (myGarage[i]->get_NumberOfWheels() == y)
			{
				cout << "\nFOUND A VEHICLE WITH THE ATTRIBUT YOU SEARCHED FOR!\n" << endl;
				myGarage[i]->output();
			}
		}
	}

	~Garage() //dekonstructor
	{	
	};
};

//Main-function with menu that calls functions from classes
int main()
{
	int selection;
	
	cout << "Welcome to the garage" << endl;
	cout << "To start, enter the size of the garage: ";
	cin >> sizeGarage;
	cout << endl;
	Garage garage;

	//DEMO-VEHICLES. these will be added to the garage, even if you enter a "garagesize" smaller then 5.
	Vehicle* ptrBicycle = new Bicycle("", "Monark", "Citybike", "CYC123", "Green", 2, 1,1990);
	garage.addVehicle(ptrBicycle);
	Vehicle* ptrMotorcycle = new Motorcycle("", "Kawasaki", "ER6n", "HML584", "Black", 2, 2, 123456789);
	garage.addVehicle(ptrMotorcycle);
	Vehicle* ptrCar = new Car("", "Volvo", "V70", "CAR123", "Black", 4, "Kombi", 250);
	garage.addVehicle(ptrCar);
	Vehicle* ptrBus = new Bus("", "Scania", "DX", "BUS123", "Black", 8, 3, 50);
	garage.addVehicle(ptrBus);
	Vehicle* ptrTruck = new Truck("", "Volvo", "D500", "LAS123", "White", 8, 8000, "Stone");
	garage.addVehicle(ptrTruck);

	//A "do/while"-loop best suted for menu because you want to run it atleast once!
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
		cout << "  0.  Empty garage and exit\n";
		cout << "\n";
		cout << "  ====================================\n";
		cout << "  Enter your selection: ";
		cin >> selection;
		cout << endl;

		switch (selection)
		{
		case 1:
		{
			system("cls");
			int addVehicleInput;
			cout << endl;
			cout << "What type of vehicle would you like to add?" << endl;
			cout << "1. Bicycle" << endl;
			cout << "2. Motorcycle" << endl;
			cout << "3. Car" << endl;
			cout << "4. Bus" << endl;
			cout << "5. Truck" << endl;
			cin >> addVehicleInput;

			string inManufacturer;
			string inModel;
			string  inRegnumber;
			string inColour;
			int inNumberOfWheels;

			if (garage.numberOfVehicles() < sizeGarage)
			{									
				if (addVehicleInput == 1)
				{
					short int inBicycleNumberOfGears;
					int inYear;
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
					cout << "Enter number of gears: " << endl;
					cin >> inBicycleNumberOfGears;
					cout << "Enter what year it was manufactured: " << endl;
					cin >> inYear;

					Vehicle* ptrBicycle = new Bicycle("", inManufacturer, inModel, inRegnumber, inColour, inNumberOfWheels, inBicycleNumberOfGears, inYear);
					garage.addVehicle(ptrBicycle);
				}

				if (addVehicleInput == 2)
				{
					short int inMotorcycleNumberOfCylinders;
					int inMotorcycleChassiNumber;
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
					cout << "Enter number of cylinders: " << endl;
					cin >> inMotorcycleNumberOfCylinders;
					cout << "Enter chassinumber: " << endl;
					cin >> inMotorcycleChassiNumber;
					Vehicle* ptrMotorcycle = new Motorcycle("", inManufacturer, inModel, inRegnumber, inColour, inNumberOfWheels, inMotorcycleNumberOfCylinders, inMotorcycleChassiNumber);
					garage.addVehicle(ptrMotorcycle);
				}

				if (addVehicleInput == 3)
				{
					string inCarChassi;
					int inCarHorsepower;
					cout<< "Enter manufacturer: " << endl;
					cin >> inManufacturer;
					cout << "Enter model: " << endl;
					cin >> inModel;
					cout << "Enter regnumber: " << endl;
					cin >> inRegnumber;
					cout << "Enter colour:" << endl;
					cin >> inColour;
					cout << "Enter number of wheels: " << endl;
					cin >> inNumberOfWheels;
					cout << "Enter chassitype: " << endl;
					cin >> inCarChassi;
					cout << "Enter horsepower: " << endl;
					cin >> inCarHorsepower;
					Vehicle* ptrCar = new Car("", inManufacturer, inModel, inRegnumber, inColour, inNumberOfWheels, inCarChassi, inCarHorsepower);
					garage.addVehicle(ptrCar);				
				}

				if (addVehicleInput == 4)
				{
					int inNumberOfDoors;
					int inNumberOfPassengers;
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
					cout << "Enter capacity (number of passengers): " << endl;
					cin >> inNumberOfPassengers;
					cout << "Enter number of doors: " << endl;
					cin >> inNumberOfDoors;
					Vehicle* ptrBus = new Bus("", inManufacturer, inModel, inRegnumber, inColour, inNumberOfWheels, inNumberOfDoors, inNumberOfPassengers);
					garage.addVehicle(ptrBus);
				}

				if (addVehicleInput == 5)
				{
					int inWeight;
					string inLoad;
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
					cout << "Enter weight: " << endl;
					cin >> inWeight;
					cout << "Enter type of load: " << endl;
					cin >> inLoad;

					Vehicle* ptrTruck = new Truck("", inManufacturer, inModel, inRegnumber, inColour, inNumberOfWheels,inWeight, inLoad);
					garage.addVehicle(ptrTruck);
				}
			}
			else
			{
			cout << "Garage is full" << endl;
			}
			cout << endl;
			break;
		}
	
		case 2:
		{
			system("cls");
			string inputRemoveVehicle;
			cout << endl;
			cout << "Enter the registartionnumber of the vehicle you want to remove: " << endl;
			cin >> inputRemoveVehicle;
			garage.SearchAndRemove(inputRemoveVehicle);
			cout << endl;
			break;
		}

		case 3:
		{
			system("cls");
			cout << "\n Search for a vehicle with reg-number:";
			cin >> userSearch;
			garage.searchRegnr(userSearch);
			cout << endl;
			break;
		}

		case 4:
		{
			system("cls");
			int intAttributSearch;
			string strAttributSearch;
			int searchSelection;
			cout << endl;
			cout << "Choose what attribute you want to search for" << endl;
			cout << "1. Manufacturer" << endl;
			cout << "2. Model" << endl;
			cout << "3. Colour" << endl;
			cout << "4. Number of wheels" << endl;
			
			cin >> searchSelection;

			if (searchSelection == 1)
			{
				cout << "Enter the manufacturer you would like to search for: " << endl;
				cin >> strAttributSearch;
				garage.searchByAttributManufacturer(strAttributSearch);
			}

			if (searchSelection == 2)
			{
				cout << "Enter the model you want to search for: " << endl;
				cin >> strAttributSearch;
				garage.searchByAttributModel(strAttributSearch);
			}
			if (searchSelection == 3)
			{
				cout << "Enter colour you want to search for: " << endl;
				cin >> strAttributSearch;
				garage.searchByAttributColour(strAttributSearch);
			}

			if (searchSelection == 4)
			{
				cout << "Enter number of wheels you want to search for: " << endl;
				cin >> intAttributSearch;
				garage.searchByAttributNumberOfWheels(intAttributSearch);				
			}	
			cout << endl;
			break;
		}

		case 5:
		{
			system("cls");
			cout << endl;
			garage.printAllVehicles();
			cout << endl;
			break;
		}

		case 6:
		{
			system("cls");
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
				cout << "Here is all the bicycles in the garage:" << endl;
				garage.printAllBicycles();
			}

			if (listInput==2)
			{
				cout << "Here is all the motorcycles in the garage:" << endl;
				garage.printAllMotorcycles();
			}

			if (listInput==3)
			{
				cout << "Here is all the cars in the garage:" << endl;
				garage.printAllCars();
			}

			if (listInput == 4)
			{
				cout << "Here is all the buses in the garage:" << endl;
				garage.printAllBuses();
			}

			if (listInput == 5)
			{
				cout << "Here is all the trucks in the garage:" << endl;
				garage.printAllTrucks();
			}
			cout << endl;
			break;
		}

		case 0:
		{
			cout << endl;
			garage.Destroy();
			system("cls");
			cout << endl;
			break;
		}

		default: cout << selection << " is not a valid menu item.\n";
			cout << endl;
		}
	} while (selection != 0);
	return 0;
}