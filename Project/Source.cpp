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

public:
	//constr
	event(const char* eventName)
	{
		this->eventName = new char[strlen(eventName) + 1];
		strcpy_s(this->eventName, strlen(eventName) + 1, eventName);
		strcpy_s(this->address, 4, "n/a");
		this->hour = -1;
		this->minutes = -1;
	}
	event(const char* eventName, const char* address, int hour, int minutes)
	{
		this->eventName = new char[strlen(eventName) + 1];
		strcpy_s(this->eventName, strlen(eventName) + 1, eventName);
		strcpy_s(this->address, strlen(address)+1, address);
		this->hour = hour;
		this->minutes = minutes;
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
		return *this;
	}
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
	//destr
	~event()
	{
		cout << endl << "Destr" << endl;
		delete[] eventName;
	}
};
int main()
{
	char* p1 = new char[30];
	char* p2 = new char[30];
	strcpy_s(p2, 29, "str Mihail Sebastian");
	strcpy_s(p1, 12, "bling blong");
	event ceva(p1,p1,22,11);
	cout << ceva.getEventName() << endl << ceva.getAddress() << endl << ceva.getHour() << ':' << ceva.getMinutes();
	event ceva2(p2,p2,13,10);
	ceva2 = ceva;
	cout << ceva2.getEventName() << endl << ceva2.getAddress() << endl << ceva2.getHour() << ':' << ceva2.getMinutes();
	return 0;
}