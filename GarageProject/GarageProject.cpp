#include <iostream>

using namespace std;

class Garage //representation of the "building" itself. The garage can store x number of vehicles
{
	/*
	ListVehicles som listar samtliga fordon i garaget 
		� ListTypeOfVehicles som listar samtliga olika typer av  fordon i garaget och hur m�nga av dessa som st�r i garaget 
		� AddVehicle som l�gger till ett fordon ur garaget  
		� RemoveVehicle som tar bort fordon ur garaget  
		� Ha en max - gr�ns som kr�vs som inparameter vid instansieringen av ett nytt garage  
		� SearchVehicle som s�ker efter ett specifikt fordon via REG - NR och skriver ut det om det finns, annars inte.
		� M�jlighet att s�ka efter ett flertal fordon p� ett flertal valfria variabler.
	*/
};

class Vehicle //headclass of vehicles such as cars,bikes trucks etc.
{
	/*
	�  Vehicle inneh�ller samtliga variabler som ska finnas i samtliga fordonstyper.EX.REG - NR, F�rg, Antal hjul.Och andra variabler ni kan komma p�.
		� Det m�ste minst finnas f�ljande subklasser : 
			o Bicycle 
			o Motorcycle  
			o Car
			o Bus  
			o Truck
		� Dessa skall inneh�lla minst tv� egna attribut
	*/
private:

protected:
	string manufacturer;
	string model;
	string registrationNumber;
	string colour;
	short int numberOfWheels;

public:	
	Vehicle(string a, string b, string c, string d, short int i) : manufacturer(a), model(b), registrationNumber(c), colour(d), numberOfWheels(i) 
	{
	}

	virtual void output() = 0;
};

class Car : public Vehicle
{
public:
	
	Car(string a, string b, string c, string d, short int i) : Vehicle(a,b,c,d,i)
	{
	}

	void output()
	{
		cout << "Manufacturer: " << this->manufacturer << " \nModel: " << this->model << "\nRegistrationnumber: " << this->registrationNumber << "\nColour: " << this->colour << "\nNumber of wheels: " << this->numberOfWheels << "\n*************" << endl;
	}
};

class Motorcycle : public Vehicle
{
public:

	Motorcycle(string a, string b, string c, string d, short int i) : Vehicle(a, b, c, d, i)
	{
	}

	void output()
	{
		cout << "Manufacturer: " << this->manufacturer << " \nModel: " << this->model << "\nRegistrationnumber: " << this->registrationNumber << "\nColour: " << this->colour << "\nNumber of wheels: " << this->numberOfWheels << "\n*************" << endl;
	}
};


int main()
{
	/*
	� Ett textbaserat UI f�r en konsolapplikation 
		o Det skall g� att navigera till SAMTLIG funktionalitet fr�n garage via UI : t 
		o Det skall g� att SKAPA ett Garage i UI : t.
		o Det skall g� att avsluta applikationen fr�n UI : t
	*/
	Vehicle* ptrCarOne = new Car("Volvo", "V70" ,"ABC123", "Red", 4);
	Vehicle* ptrCarTwo = new Car("Audi", "A4", "AFS143", "Silver", 4);
	Vehicle* ptrBikeOne = new Motorcycle("Kawasaki", "ER6n", "HML584", "Black", 2);

	ptrCarOne->output();
	ptrCarTwo->output();
	ptrBikeOne->output();


	delete ptrBikeOne;
	delete ptrCarOne;
	delete ptrCarTwo;

	
	return 0;
}


