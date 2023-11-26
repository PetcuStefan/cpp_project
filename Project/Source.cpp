#include<iostream>
#include<string>
using namespace std;
class event
{
private:
	char* eventName=nullptr;
	char address[40] = {};
	int hour;
	int minutes;
	bool isOutdoors;
public:
	event()
	{
		this->eventName = nullptr;
		strcpy_s(this->address, 4, "n/a");
		this->hour = 0;
		this->minutes = 0;
		this->isOutdoors = false;
	}
	//constr
	event(const char* eventName)
	{
		this->eventName = new char[strlen(eventName) + 1];
		strcpy_s(this->eventName, strlen(eventName) + 1, eventName);
		strcpy_s(this->address, 4, "n/a");
		this->hour = 0;
		this->minutes = 0;
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
		if (hour >= 0)
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
		if (minutes >= 0 && minutes < 60)
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
	//op!
	bool operator!()
	{
		bool copy;
		copy = !this->isOutdoors;
		return copy;
	}
	//op[]
	char operator[](int index)
	{
		if (index<0 || index>strlen(this->eventName))
		{
			throw exception("Inexistent index");
		}
		return this->eventName[index];
	}
	//op+
	event& operator+ (int value)
	{
		event copy;
		copy = *this;
		copy.minutes += value;
		if (copy.minutes >= 60)
		{
			copy.hour++;
			copy.minutes -= 60;
		}
		return copy;
	}
	//op==
	bool operator==(const event& a)
	{
		if (strcmp(this->eventName, a.eventName) == 0 && strcmp(this->address, a.address) == 0 && this->hour == a.hour && this->minutes == a.minutes && this->isOutdoors == a.isOutdoors)
			return true;
		else return false;
	}
	//op++
	event& operator++ (int)
	{
		event copy = *this;
		this->minutes++;
		if (this->minutes >= 60)
		{
			this->hour++;
			this->minutes -= 60;
		}
		return copy;
	}
	//op>
	bool operator>(const event& a)
	{
		if (this->hour > a.hour)
			return true;
		else
		{
			if (this->hour == a.hour && this->minutes > a.minutes)
				return true;
			else
				return false;
		}
	}
	//op()
	explicit operator float()
	{
		float a;
		a = this->minutes / 60.0;
		a += this->hour;
		return a;
	}
	//generic method 1
	int countWords(const event& a)
	{
		int counter=0;
		if (a.eventName != nullptr)
		{
			counter = 1;
		}
		else
		{
			return 0;
		}
		for (int i = 0;i < strlen(a.eventName);i++)
		{
			if (a.eventName[i] == '-' || a.eventName[i] == '_' || a.eventName[i] == ' ' || a.eventName[i] == '.')
				counter++;
			if((a.eventName[i]>='a'&&a.eventName[i]<='z')&&(a.eventName[i+1]>='A'&&a.eventName[i+1]<='Z'))
				counter++;
		}
		return counter;
	}
	//generic method 2
	char* abbreviation(const event& a)
	{
		char* copy = new char[countWords(a.eventName) + 1];
		copy[0] = toupper(a.eventName[0]);
		copy[1] = '\0';
		char c0py[2];
		c0py[1] = '\0';
		for (int i = 1;i < strlen(a.eventName);i++)
		{
			if (a.eventName[i] == '-' || a.eventName[i] == '_' || a.eventName[i] == ' ' || a.eventName[i] == '.')
			{
				c0py[0] = a.eventName[i+1];
				c0py[0]=toupper(c0py[0]);
				strcat(copy, c0py);
			}
			if ((a.eventName[i] >= 'a' && a.eventName[i] <= 'z') && (a.eventName[i + 1] >= 'A' && a.eventName[i + 1] <= 'Z'))
			{
				c0py[0] = a.eventName[i + 1];
				strcat(copy, c0py);
			}
		}
		copy[countWords(a.eventName) + 1] = '\0';
		return copy;
	}
	//destr
	~event()
	{
		delete[] this->eventName;
		this->eventName = nullptr;
	}
	friend event operator++(event& a);
	friend ostream& operator<<(ostream& a, const event& b);
	friend istream& operator>>(istream& a, event& b);
};
event operator+ (int value, event a)
{
	return a + value;
}
event operator++(event& a)
{
	a.minutes++;
	if (a.minutes >= 60)
	{
		a.hour++;
		a.minutes -= 60;
	}
	return a;
}
ostream& operator<<(ostream& a,const event& b)
{
	a << "Event " << b.eventName << ' ' << "is taking place on " << b.address << ' ' << "at " << b.hour << ':' << b.minutes<<'.'<<endl;
	if (b.isOutdoors == true)
	{
		a << "The event is outdoors.";
	}
	else
	{
		a << "The event is indoors.";
	}
	return a;
}
istream& operator>> (istream& a, event& b)
{
	if (b.eventName != nullptr)
	{
		delete[] b.eventName;
		b.eventName = nullptr;
	}
	b.eventName = new char[30];
	cout << "Event name:";
	a.getline(b.eventName,30);
	cout << endl << "Address:";
	a.getline(b.address,30);
	cout << endl << "Hour:";
	a >> b.hour;
	cout << endl<<"Minutes:";
	a >> b.minutes;
	cout << "Is it outdoors? Type true for yes and false for no:";
	a >> b.isOutdoors;
	return a;
}
class location
{
private:
	const int id;
	int maxSeats;
	int noRows;
	char zone[10] = {};
	char* name=nullptr;
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
	location() :id(noLocations)
	{
		this->maxSeats = 0;
		this->noRows = 0;
		this->name = nullptr;
		strcpy_s(this->zone, 4, "n/a");
		this->hasParkingLot = true;
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
	//op+
	location& operator+ (int value)
	{
		location copy;
		copy = *this;
		copy.noRows += value;
		copy.maxSeats += (value * 30);
		return copy;
	}
	//op==
	bool operator== (const location& a)
	{
		if (this->maxSeats == a.maxSeats && this->noRows == a.noRows && this->hasParkingLot == a.hasParkingLot && strcmp(this->zone, a.zone) == 0 && strcmp(this->name, a.name) == 0)
			return true;
		else return false;
	}
	//op++
	location& operator++ (int)
	{
		location copy;
		copy = *this;
		this->noRows++;
		this->maxSeats += 30;
		return copy;
	}
	//op>
	bool operator> (const location& a)
	{
		if (this->maxSeats > a.maxSeats)
			return true;
		else return false;
	}
	//op()
	explicit operator float()
	{
		float a;
		a = maxSeats / 30.0;
		return a;
	}
	//generic method 1
	//generic method 2
	~location()
	{
		if (this->name != nullptr)
		{
			delete[] this->name;
			this->name = nullptr;
		}
	}
	friend location operator++(location&);
	friend ostream& operator<<(ostream& a, location& b);
	friend istream& operator>>(istream& a, location& b);
};
int location::noLocations = 0;
location operator+ (int value,location a)
{
	return a + value;
}
location operator++(location &a)
{
	a.noRows++;
	a.maxSeats += 30;
	return a;
}
ostream& operator<<(ostream& a, location& b)
{
	a << "Location "<<b.name<<" with ID : " << b.id<<" has "<<b.maxSeats<<" seats in "<<b.noRows<<".The zone of the location is "<<b.zone<<'.'<<endl;
	if (b.hasParkingLot == true)
	{
		a << "It has a parking lot.";
	}
	else
	{
		a << "It doesn't have a parking lot.";
	}
	a <<endl<< "There are " << b.noLocations<<'.';
	return a;
}
istream& operator>>(istream& a, location& b)
{
	if (b.name != nullptr)
	{
		delete[] b.name;
		b.name = nullptr;
	}
	b.name = new char[30];
	cout << "Name:";
	a.getline(b.name, 30);
	cout <<endl<< "Max no of seats:";
	a >> b.maxSeats;
	cout <<endl<< "No rows:";
	a >> b.noRows;
	cout << endl << "Zone:";
	a >> b.zone;
	cout << endl << "Does it have a parking lot? Type true for yes and false for no:";
	a >> b.hasParkingLot;
	return a;
}
int main()
{
	char* p1 = new char[30];
	strcpy_s(p1, 20, "bling_blong");
	char* p2 = new char[30];
	strcpy_s(p2, 30, "str. Mihail Sebastian");
	event ceva;
	cin >> ceva;
	cout << ceva<<endl;
	cout << ceva.abbreviation(ceva);
	return 0;
}