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

