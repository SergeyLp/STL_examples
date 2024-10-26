// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
//PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
// TinyPIM (c) 1999 Pablo Halpern. File AddressBook.cpp
#include "Address.h"

void Address::lastname(const std::string& s)
{
  lastname_ = s;
}

void Address::firstname(const std::string& s)
{
  firstname_ = s;
}

void Address::phone(const std::string& s)
{
  phone_ = s;
}

void Address::address(const std::string& s)
{
  address_ = s;
}

bool operator==(const Address& a1, const Address& a2) {
  return (a1.lastname() == a2.lastname() &&
    a1.firstname() == a2.firstname() &&
    a1.phone() == a2.phone() &&
    a1.address() == a2.address());
}

bool operator< (const Address& a1, const Address& a2) {
  if (a1.lastname() < a2.lastname())
    return true;
  else if (a2.lastname() < a1.lastname())
    return false;
  else
    return (a1.firstname() < a2.firstname());
}
