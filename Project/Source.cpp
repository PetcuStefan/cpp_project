#include<iostream>
#include<string>
using namespace std;
class event
{
private:
	char* eventName;
	char address[40];
	int hour;
	int minutes;
	bool isOutdoors;

public:
	//constr
	event(const char* eventName)
	{
		this->eventName = new char[strlen(eventName) + 1];
		strcpy_s(this->eventName, strlen(eventName) + 1, eventName);
		strcpy_s(this->address, 4, "n/a");
		this->hour = -1;
		this->minutes = -1;
		this->isOutdoors = false;
	}
	event(const char* eventName, const char* address, int hour, int minutes, bool isOutdoors)
	{
		this->eventName = new char[strlen(eventName) + 1];
		strcpy_s(this->eventName, strlen(eventName) + 1, eventName);
		strcpy_s(this->address, strlen(address)+1, address);
		this->hour = hour;
		this->minutes = minutes;
		this->isOutdoors = isOutdoors;
	}
	//copy-constr
	event(const event& a)
	{
		if (a.eventName != nullptr)
		{
			this->eventName = new char[strlen(a.eventName) + 1];
			strcpy_s(this->eventName, strlen(a.eventName) + 1, a.eventName);

		}
		if (a.address != nullptr)
		{
			strcpy_s(this->address, strlen(a.address) + 1, a.address);
		}
		this->hour = a.hour;
		this->minutes = a.minutes;
		this->isOutdoors = a.isOutdoors;
	}
	//op=
	event& operator=(const event& a)
	{
		if (a.eventName != nullptr)
		{
			if (this->eventName != nullptr)
			{
				delete[] eventName;
				this->eventName = nullptr;
			}
			this->eventName = new char[strlen(a.eventName) + 1];
			strcpy_s(this->eventName, strlen(a.eventName) + 1, a.eventName);

		}
		if (a.address != nullptr)
		{
			strcpy_s(this->address, strlen(a.address) + 1, a.address);
		}
		this->hour = a.hour;
		this->minutes = a.minutes;
		this->isOutdoors = a.isOutdoors;
		return *this;
	}
	//setters
	void setEventName(const char *newEventName)
	{
		if (this->eventName != nullptr)
		{
			delete[] eventName;
			this->eventName = nullptr;
		}
		this->eventName = new char[strlen(newEventName) + 1];
		strcpy_s(this->eventName,strlen(newEventName)+1, newEventName);
	}
	void setAddress(char *newAddress)
	{
		strcpy_s(this->address,39, newAddress);
	}
	void setHour(int hour)
	{
		if (hour >= 0 && hour < 24)
		{
			this->hour = hour;
		}
		else
		{
			throw exception{ "Wrong hour!!" };
		}
	}
	void setMinutes(int minutes)
	{
		if (minutes >= 0 && minutes < 24)
		{
			this->minutes = minutes;
		}
		else
		{
			throw exception{ "Wrong number of minutes!!" };
		}
	}
	void setOutdoors()
	{
		this->isOutdoors = true;
	}
	void setIndoors()
	{
		this->isOutdoors = false;
	}
	//getters
	char* getEventName()
	{
		char *copyEventName=new char[strlen(this->eventName)+1];
		strcpy_s(copyEventName,strlen(this->eventName)+1, this->eventName);
		return copyEventName;
	}
	char* getAddress()
	{
		char* copyAddress = new char[strlen(this->address)+1];
		strcpy_s(copyAddress,strlen(this->address)+1, this->address);
		return copyAddress;
	}
	int getHour()
	{
		return this->hour;
	}
	int getMinutes()
	{
		return this->minutes;
	}
	bool getIsOutdoors()
	{
		return this->isOutdoors;
	}
	bool operator!()
	{
		bool copy;
		copy = !this->isOutdoors;
		return copy;
	}
	char operator[](int index)
	{
		if (index<0 || index>strlen(this->eventName))
		{
			throw exception("Inexistent index");
		}
		return this->eventName[index];
	}
	//destr
	~event()
	{
		cout << endl << "Destr" << endl;
		delete[] this->eventName;
		this->eventName = nullptr;
	}
};
class location
{
private:
	const int id;
	int maxSeats;
	int noRows;
	char zone[10];
	char* name;
	bool hasParkingLot;
	static int noLocations;
public:
	//setters
	void setMaxSeats(int maxSeats)
	{
		if (maxSeats < 0)
		{
			throw exception("No of max seats cannot be less than 0");
		}
		else
		{
			this->maxSeats = maxSeats;
		}
	}
	void setNoRows(int noRows)
	{
		if (noRows < 0)
		{
			throw exception("No of rows cannot be less than 0");
		}
		else
		{
			this->noRows = noRows;
		}
	}
	void setZone(const char* zone)
	{
		strcpy_s(this->zone, 9, zone);
	}
	void setName(const char* name)
	{
		if (name != nullptr)
		{
			if (this->name != nullptr)
			{
				delete[] this->name;
				this->name = nullptr;
			}
			this->name = new char[strlen(name) + 1];
			strcpy_s(this->name, strlen(name) + 1, name);
		}
	}
	void setParkingLot()
	{
		this->hasParkingLot = true;
	}
	void unSetParkingLot()
	{
		this->hasParkingLot = false;
	}
	//getters
	int getId()
	{
		return id;
	}
	int getMaxSeats()
	{
		return maxSeats;
	}
	int getNoRows()
	{
		return noRows;
	}
	char* getZone()
	{
		char* copy = new char[strlen(this->zone)+1];
		strcpy_s(copy, strlen(this->zone) + 1, this->zone);
		return copy;
	}
	char* getName()
	{
		char* copy = new char[strlen(this->name) + 1];
		strcpy_s(copy, strlen(this->name) + 1, this->name);
		return copy;
	}
	bool getParkingLot()
	{
		return this->hasParkingLot;
	}
	//constr1
	location(const char* name) :id(++noLocations)
	{
		this->maxSeats = 0;
		this->noRows = 0;
		strcpy_s(this->zone, 4, "n/a");
		if (name != nullptr)
		{
			this->name = new char[strlen(name) + 1];
			strcpy_s(this->name, strlen(name) + 1, name);
		}
		this->hasParkingLot = false;
	}
	//constr2
	location(int maxSeats,int noRows,const char*zone, const char* name, bool hasParkingLot) :id(++noLocations)
	{
		if (maxSeats < 0)
		{
			throw exception("No of max seats cannot be less than 0");
		}
		if (noRows < 0)
		{
			throw exception("No of rows cannot be less than 0");
		}
		this->maxSeats = maxSeats;
		this->noRows = noRows;
		if (zone != nullptr) 
		{
			strcpy_s(this->zone, strlen(zone)+1, zone);

		}
		if (name != nullptr)
		{
			this->name = new char[strlen(name) + 1];
			strcpy_s(this->name, strlen(name) + 1, name);
		}
		this->hasParkingLot = hasParkingLot;
	}
	//copy-constr
	location(const location& a) :id(++noLocations)
	{
		this->maxSeats =a.maxSeats;
		this->noRows = a.noRows;
		strcpy_s(this->zone, strlen(a.zone) + 1, a.zone);
		if (a.name != nullptr);
		{
			name = new char[strlen(a.name) + 1];
			strcpy_s(this->name, strlen(a.name) + 1, a.name);
		}
		this->hasParkingLot = a.hasParkingLot;
	}
	location& operator=(const location& a)
	{
		this->maxSeats = a.maxSeats;
		this->noRows = a.noRows;
		strcpy_s(this->zone, strlen(a.zone) + 1, a.zone);
		if (a.name != nullptr)
		{
			if (this->name != nullptr)
			{
				delete[] this->name;
				this->name = nullptr;
			}
			name = new char[strlen(a.name) + 1];
			strcpy_s(this->name, strlen(a.name) + 1, a.name);
			this->hasParkingLot = a.hasParkingLot;
		}
		return *this;
	}
	bool operator!()
	{
		bool copy;
		copy = !this->hasParkingLot;
		return copy;
	}
	char operator[](int index)
	{
		if (index<0 || index>strlen(this->name))
		{
			throw exception("Inexistent index");
		}
		return this->name[index];
	}
	~location()
	{
		if (this->name != nullptr)
		{
			delete[] this->name;
			this->name = nullptr;
		}
	}
};
int main()
{
	char* p1 = new char[30];
	char* p2 = new char[30];
	return 0;
}