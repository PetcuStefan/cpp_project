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
	~event()
	{
		cout << endl << "Destr" << endl;
		delete[] eventName;
	}
};
int main()
{
	char* p = new char[30];
	char* add = new char[30];
	strcpy_s(add, 29, "str Mihail Sebastian");
	strcpy_s(p, 12, "bling blong");
	event ceva(p,add,12,03);
	cout << ceva.getEventName() << endl << ceva.getAddress() << endl << ceva.getHour() << ':' << ceva.getMinutes();

	return 0;
}