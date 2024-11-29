#include <iostream>
#include <string>
#include "Device.h"


std::string Device::getOS() const
{
	return _os;
}
bool Device::isActive() const
{
	return _active;
}
void Device::activate()
{
	_active = true;
}
void Device::deactivate()
{
	_active = false;
}
void Device::init(const unsigned int id, const DeviceType type, const std::string os)
{
	this->_id = id;
	this->_type = type;
	this->_os = os;
	_active = true;
}
unsigned int Device::getID() const 
{
	return _id;
}
DeviceType Device::getType() const 
{
	return _type;
}