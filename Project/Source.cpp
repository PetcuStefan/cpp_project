#include<iostream>
using namespace std;
class event
{
private:
	char* eventName = new char[20];
	char* address = new char[40];
	int hour;
	int minutes;

public:
	event()
	{
		eventName = nullptr;
		address = nullptr;
		hour = -1;
		minutes = -1;
	}

	void setEventName(char *newEventName)
	{
		strcpy(this->eventName, newEventName);
	}

	void setAddress(char *newAddress)
	{
		strcpy(this->address, newAddress);
	}
	void setHour(int hour)
	{
		this->hour = hour;
	}
	void setMinutes(int minutes)
	{
		this->minutes = minutes;
	}
	char* getEventName()
	{
		char *copyEventName=new char[strlen(this->eventName)];
		strcpy(copyEventName, this->eventName);
		return copyEventName;
	}
	char* getAddress()
	{
		char* copyAddress = new char[strlen(this->address)];
		strcpy(copyAddress, this->address);
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
		delete[] address;
	}
};
int main()
{
	event ceva;
	cout << ceva.getHour;
	return 0;
}