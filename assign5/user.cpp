#include "user.h"

/**
 * Creates a new User with the given name and no friends.
 */
User::User(const std::string& name)
  : _name(name)
  , _friends(nullptr)
  , _size(0)
  , _capacity(0)
{
}

/**
 * Adds a friend to this User's list of friends.
 * @param name The name of the friend to add.
 */
void
User::add_friend(const std::string& name)
{
  if (_size == _capacity) {
    _capacity = 2 * _capacity + 1;
    std::string* newFriends = new std::string[_capacity];
    for (size_t i = 0; i < _size; ++i) {
      newFriends[i] = _friends[i];
    }
    delete[] _friends;
    _friends = newFriends;
  }

  _friends[_size++] = name;
}

/**
 * Returns the name of this User.
 */
std::string
User::get_name() const
{
  return _name;
}

/**
 * Returns the number of friends this User has.
 */
size_t
User::size() const
{
  return _size;
}

/**
 * Sets the friend at the given index to the given name.
 * @param index The index of the friend to set.
 * @param name The name to set the friend to.
 */
void User::set_friend(size_t index, const std::string& name)
{
  _friends[index] = name;
}
std::string* User::get_friend() const
{
  return _friends;
}
size_t User::get_capacity() const
{
  return _capacity;
}
/** 
 * STUDENT TODO:
 * The definitions for your custom operators and special member functions will go here!
 */
std::ostream& operator<<(std::ostream& os, const User& user) {
  os << "User(name=" << user.get_name() << ", friends=[";
  if (user.size() >= 1) {
      for (size_t index = 0; index < user.size() - 1; index++) {
          os << user.get_friend()[index] << ", ";
      }
      os << user.get_friend()[user.size() - 1];
  }
  os << "])"; // Always close the list
  return os;
}

User::~User(){//destructor
  delete []_friends;
}
// Copy Constructor
User::User(const User& user) 
    : _name(user._name), _size(user._size), _capacity(user._capacity) {
    _friends = new std::string[_capacity];
    std::copy(user._friends, user._friends + _size, _friends);
}

// Copy Assignment
User& User::operator=(const User& user) {
    if (this != &user) {
        delete[] _friends;
        _name = user._name;
        _size = user._size;
        _capacity = user._capacity;
        _friends = new std::string[_capacity];
        std::copy(user._friends, user._friends + _size, _friends);
    }
    return *this;
}




