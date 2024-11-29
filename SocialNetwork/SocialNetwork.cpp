#include  "SocialNetwork.h"

void SocialNetwork::init(std::string networkName, int minAge)
{
	this->_networkName = networkName;
	this->_minAge = minAge;
	this->_profiles = new ProfileList();
	this->_profiles->init();
}
void SocialNetwork::clear()
{
	_profiles->clear();
	delete _profiles;

}
std::string SocialNetwork::getNetworkName() const
{
	return _networkName;
}
int SocialNetwork::getMinAge() const
{
	return _minAge;
}
bool SocialNetwork::addProfile(Profile profile_to_add)
{
	if (profile_to_add.getOwner().getAge() < _minAge)
	{
		return false;
	}
	else
	{
		_profiles->add(profile_to_add);
		return true;
	}
}
std::string SocialNetwork::getWindowsDevices() const
{
	std::string windowsDevices = "";
	ProfileNode* curr = _profiles->get_first();
	while (curr != nullptr)
	{
		Profile profile = curr->get_data();
		User user = profile.getOwner();
		DevicesList deviceList = user.getDevices();
		DeviceNode* devices = deviceList.get_first();
		while (devices != nullptr)
		{
			Device device = devices->get_data();
			if (device.getOS() == WINDOWS10 || device.getOS() == WINDOWS11 || device.getOS() == WINDOWS7)
			{
				std::string newDevice = "[" + std::to_string(device.getID());
				newDevice += ", " + device.getOS();
				newDevice += "], ";
				windowsDevices += newDevice;
			}
			devices = devices->get_next();
		}
		curr = curr->get_next();
	}
	if (!windowsDevices.empty())
	{
		windowsDevices.pop_back();
		windowsDevices.pop_back();
	}
	return windowsDevices;
}