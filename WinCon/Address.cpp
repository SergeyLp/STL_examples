// TinyPIM (c) 1999 Pablo Halpern, File Address.cpp
#include "Address.h"

// Destructor
Address::~Address()
{
  // Clean up memory
  delete[] lastname_;
  delete[] firstname_;
  delete[] phone_;
  delete[] address_;
}

char* Address::dup(const char* s)
{
  // Allocate space for string, including NUL terminator
  char* ret = new char[strlen(s) + 1];

  // Copy contents into newly allocated string
  strcpy(ret, s);

  return ret;
}

// Copy constructor
Address::Address(const Address& a2)
  : lastname_(nullptr), firstname_(nullptr), phone_(nullptr), address_(nullptr)
{
  // Use assignment operator to do the hard work
  *this = a2;
}

// Assignment operator
const Address& Address::operator=(const Address& a2)
{
  if (this != &a2)
  {
    lastname(a2.lastname_);
    firstname(a2.firstname_);
    phone(a2.phone_);
    address(a2.address_);
  }

  return *this;
}

void Address::lastname(const char* s) {
  assert(lastname_ != s);

  delete[] lastname_;
  lastname_ = dup(s);
}

void Address::firstname(const char* s) {
  assert(firstname_ != s);

  delete[] firstname_;
  firstname_ = dup(s);
}

void Address::phone(const char* s)
{
  if (phone_ != s)
  {
    delete[] phone_;
    phone_ = dup(s);
  }
}

void Address::address(const char* s)
{
  if (address_ != s)
  {
    delete[] address_;
    address_ = dup(s);
  }
}
