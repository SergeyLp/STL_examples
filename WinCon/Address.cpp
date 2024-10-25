// TinyPIM (c) 1999 Pablo Halpern, File Address.cpp

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

