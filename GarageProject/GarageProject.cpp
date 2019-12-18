#include <iostream>
#include <vector>
using namespace std;

class Vehicle //headclass of vehicles such as cars,bikes trucks etc.
{
	/*
	•  Vehicle contains all the variables that should excist in all the vehicle-types, like (manufacuter, model, registrationnumbers, colour, numberofwheels)
		atleast these following subclasses : 
			o Bicycle 
			o Motorcycle  
			o Car
			o Bus  
			o Truck
		• should contain atleast two attributes
	*/
private:

protected:
	string manufacturer;
	string model;
	string registrationNumber;
	string colour;
	short int numberOfWheels;

public:	

	Vehicle(string a, string b, string c, string d, short int i) : manufacturer(a), model(b), registrationNumber(c), colour(d), numberOfWheels(i) //Constructor
	{
	}

	virtual void output() = 0;
	virtual ~Vehicle() //dekonstructor
	{
		cout << "This is the head deconstructor of VEHICLE" << endl;
	};
};

class Car : public Vehicle
{
private:

protected:
	
public:	
	Car(string a, string b, string c, string d, short int i) : Vehicle(a,b,c,d,i)
	{
		cout << "Car created!" << endl;
	}

	void output()
	{
		cout << "Manufacturer: " << this->manufacturer << " \nModel: " << this->model << "\nRegistrationnumber: " << this->registrationNumber << "\nColour: " << this->colour << "\nNumber of wheels: " << this->numberOfWheels << "\n*************" << endl;
	}

	~Car() //dekonstructor
	{
		
		cout << "This is the deconstructor of CAR" << endl;
	};
};

class Motorcycle : public Vehicle
{
private:

protected:

public:
	Motorcycle(string a, string b, string c, string d, short int i) : Vehicle(a, b, c, d, i)
	{
		cout << "Motorcycle created!" << endl;
	}

	void output()
	{
		cout << "Manufacturer: " << this->manufacturer << " \nModel: " << this->model << "\nRegistrationnumber: " << this->registrationNumber << "\nColour: " << this->colour << "\nNumber of wheels: " << this->numberOfWheels << "\n*************" << endl;
	}

	~Motorcycle() //dekonstructor
	{
		cout << "This is the deconstructor of MOTORCYCLE" << endl;
	};
};

class Garage //representation of the "building" itself. The garage can store x number of vehicles
{
	/*
ListVehicles: lists all the vehicles in the garage
	• ListTypeOfVehicles - Lists all the different type of vehicles in the garage and how many of these are parked in the garage.
	• AddVehicle - Adds a vehicle to garage
	• RemoveVehicle - Removes a vehicles from garage
	• Initilize a max limit - A limit of how many parkingspots the garage has, input from user in the start of the program.
	• SearchVehicle - Search after a specific vehicle by REG-nr, and print out if there is a match or not.
	• Possibility to search multiple vehicles by entering more variables then just REG-nr.
	*/
private:
	int capacity;
	int parkingspotIndex;
	int counter=0;

protected:

public:
	
	vector <Vehicle*> myGarage;
	int numberOfVehicles() {  // returns the total number of car arrivals
		return myGarage.size();
	}

	void addVehicle(Vehicle* x)
	{
		myGarage.push_back(x);
		counter++;
	}

	void removeVehicle(Vehicle* x)
	{
		vector<Vehicle*>::iterator it = find(myGarage.begin(), myGarage.end(), x);
			
			if (it != myGarage.end())
			{
			cout << "Element Found" << endl;
			myGarage.erase(it); //den fattar att den ska retunera en vector iterator.
			}
	}

	void printAllVehicles(vector <Vehicle*> x)
	{
		for (int i = 0; i < myGarage.size(); i++)
		{			
			myGarage[i]->output();
		}
	}

	~Garage() //dekonstructor
	{
		cout << "This is the deconstructor of GARAGE" << endl;
	};
};

int main()
{
	/*
	• textbased UI for a consolapplication 
		o Should be able to navigate to ALL the functions from garage via UI 
		o Should be able to CREATE a garage via UI (set a max-limit)
		o Should be able to exit the application from the UI
	*/
	
	Garage garage; //Create a garage-object
	
	Vehicle* ptrCarOne = new Car("Volvo", "V70" ,"ABC123", "Red", 4); // Creates a pointer to a new car-object
	Vehicle* ptrCarTwo = new Car("Audi", "A4", "AFS143", "Silver", 4); // Creates a pointer to a new car-object
	Vehicle* ptrBikeOne = new Motorcycle("Kawasaki", "ER6n", "HML584", "Black", 2); // Creates a pointer to a new car-object	
	
	/*
	string userSearchRegNr;
	cout << "Enter regnr to search: " << endl;
	cin >> userSearchRegNr;
	garage.searchRegistrationNumber(userSearchRegNr);
	*/

	cout << garage.numberOfVehicles()<<endl; // print number of vehicles in vector

	garage.addVehicle(ptrCarOne); // calls the push_back function in garage. Push_back to vector.
	garage.addVehicle(ptrCarTwo); // calls the push_back function in garage. Push_back to vector.
	garage.addVehicle(ptrBikeOne); // calls the push_back function in garage. Push_back to vector.
	

	cout << garage.numberOfVehicles() << endl; // print number of vehicles in vector

	garage.removeVehicle(ptrBikeOne);	

	cout << garage.numberOfVehicles() << endl;	

	garage.printAllVehicles(garage.myGarage);
	
	delete ptrCarOne;
	delete ptrCarTwo;
	delete ptrBikeOne;	
	

			
	return 0;
}


