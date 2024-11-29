#include "User.h"

void User::init(unsigned int id, std::string username, unsigned int age)
{
	this->_id = id;
	this->_username = username;
	this->_age = age;
	this->_devices = new DevicesList;
	this->_devices->init();
}
void User::clear()
{
	delete _devices;
	_devices = nullptr;
}
unsigned int User::getID() const
{
	return _id;
}
const std::string& User::getUserName() const
{
	return _username;
}
unsigned int User::getAge() const
{
	return _age;
}
DevicesList& User::getDevices() const
{
	return *_devices;
}
void User::addDevice(const Device& newDevice)
{
	_devices->add(newDevice);
}
bool User::checkIfDevicesAreOn() const
{
	DeviceNode* curr = _devices->get_first();
	while (curr != nullptr)
	{
		if (curr->get_data().isActive() == false)
		{
			return false;
		}
		curr = curr->get_next();
	}
	return true;
}