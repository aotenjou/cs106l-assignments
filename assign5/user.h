/*
 * CS106L Assignment 5: TreeBook
 * Created by Fabio Ibanez with modifications by Jacob Roberts-Baca.
 */

#include <iostream>
#include <string>

class User
{
public:
  User(const std::string& name);
  void add_friend(const std::string& name);
  std::string get_name() const;
  size_t size() const;
  void set_friend(size_t index, const std::string& name);
  std::string * get_friend() const;
  size_t get_capacity() const;
  /** 
   * STUDENT TODO:
   * Your custom operators and special member functions will go here!
   */
  ~User();//distructor
  User(const User & user);//copy construct
  User& operator=(const User& user);//copy assign
  User(User&& user)=delete;//move construct
  User& operator=(User&& user)=delete;//move assign
  friend std::ostream & operator<<(std::ostream & os,const User & user);
  User& operator+=(User& other) {
    this->add_friend(other.get_name());
    other.add_friend(this->get_name()); // Error: 'add_friend' isn't const
    return *this;
  }
  bool operator<(const User& other) const {
    return _name < other._name;
  }

private:
  std::string _name;
  std::string* _friends;
  size_t _size;
  size_t _capacity;
};