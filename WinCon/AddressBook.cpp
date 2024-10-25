// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
//PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
// TinyPIM (c) 1999 Pablo Halpern. File AddressBook.cpp
#ifndef USED_PRECOMPILE
#include <iostream> // For print() function
#endif // !USED_PRECOMPILE
#include "AddressBook.h"

int AddressBook::nextId_ = 1;

int AddressBook::insertAddress(const Address& addr, int recordId) {
  if (recordId == 0){
    // If recordId is not specified, create a new record id.
    recordId = nextId_++;
  }
  else if (recordId >= nextId_) {
    // Make sure nextId is always higher than any known record id.
    nextId_ = recordId + 1;
  }else
    try {
      getById(recordId);
      throw DuplicateId();
    }
    catch (AddressNotFound&) { } //-V565

  addresses_.push_back(addr);
  addresses_.back().recordId(recordId);

  return recordId;
}

int AddressBook::getById(int recordId) const {
  for (int i = 0; i < addresses_.size(); ++i)
    if (addresses_[i].recordId() == recordId)
      return i;

  throw AddressNotFound();
}

void AddressBook::eraseAddress(int recordId){
  const int index = getById(recordId);

  // Move element from end of vector to location being erased.
  addresses_[index] = addresses_.back();

  // Remove the now unused last element of the vector.
  addresses_.pop_back();
}

void AddressBook::replaceAddress(const Address& addr, int recordId){
  if (recordId == 0)
    recordId = addr.recordId();

  const int index = getById(recordId);

  addresses_[index] = addr;
  addresses_[index].recordId(recordId);
}

const Address& AddressBook::getAddress(int recordId) const{
  return addresses_[getById(recordId)];
}

void AddressBook::print() const
{
  std::cout << "******************************************\n";
  for (const auto& a: addresses_) {
    std::cout << "Record Id: " << a.recordId() << '\n'
              << a.firstname() << ' ' << a.lastname() << '\n'
              << a.address() << '\n' << a.phone() << '\n' 
	      << std::endl;
  }
}
