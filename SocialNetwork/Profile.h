#pragma once
#include "Page.h"
#include "UserList.h"
class Profile
{
public:
	void init(User owner);
	void clear();
	User getOwner() const;
	void setStatus(std::string new_status);
	void addPostToProfilePage(std::string post);
	void addFriend(User friend_to_add);
	std::string getPage() const;
	std::string getFriends() const;
	std::string getFriendsWithSameNameLength() const;
private:
	Page* _page;
	UserList* _friends;
	User _owner;
};