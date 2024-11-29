#include "Profile.h"
#include <stdio.h>
void Profile::init(User owner)
{
	this->_owner = owner;
    this->_page = new Page();
    this->_page->init();
    this->_friends = new UserList();
    this->_friends->init();
}
void Profile::clear()
{
    _friends->clear();
    delete _page;
    delete _friends;
}
User Profile::getOwner() const
{
	return _owner;
}
void Profile::setStatus(std::string new_status)
{
    _page->setStatus(new_status);
}
void Profile::addPostToProfilePage(std::string post)
{
    _page->addLineToPosts(post);
}
void Profile::addFriend(User friend_to_add)
{
	_friends->add(friend_to_add);
}
std::string Profile::getPage() const
{
    std::string kohaviot = "*******************\n*******************\n";
    return "Status: " + _page->getStatus() +"\n" + kohaviot + _page->getPosts();
}
std::string Profile::getFriends() const
{
    std::string friends_list;
    UserNode* curr = _friends->get_first();
    while (curr != nullptr)
    {
        friends_list += curr->get_data().getUserName() + ",";
        curr = curr->get_next();
    }
    if (!friends_list.empty())
    {
        friends_list.pop_back();
    }
    return friends_list;
}
std::string Profile::getFriendsWithSameNameLength() const
{
    if (_friends->get_first() == nullptr)
    {
        return "";
    }
    std::string sameName;
    std::string SameNameFriend;
    UserNode* curr = _friends->get_first();
    while (curr != nullptr)
    {
        SameNameFriend = curr->get_data().getUserName();
        if (_owner.getUserName().length() == SameNameFriend.length())
        {
            sameName += SameNameFriend += ",";
        }
        curr = curr->get_next();
    }
    if (!sameName.empty())
    {
        sameName.pop_back();
    }
    return sameName;
}