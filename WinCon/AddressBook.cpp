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
  } else {
    for (const auto& a : addresses_) {
      if (a.recordId() == recordId)
        throw DuplicateId();
    }
  }
    
  addresses_.push_back(addr);
  addresses_.back().recordId(recordId);

  return recordId;
}

void AddressBook::eraseAddress(int recordId){
  auto i = addresses_.begin();
  for (; i != addresses_.end(); ++i) {
    if (i->recordId() == recordId)
      break;
  }

  if (i == addresses_.end())
    throw AddressNotFound();

  addresses_.erase(i);
}

void AddressBook::replaceAddress(const Address& addr, int recordId){
  if (recordId == 0)
    recordId = addr.recordId();

  auto i = addresses_.begin();
  for (; i != addresses_.end(); ++i) {
    if (i->recordId() == recordId)
      break;
  }

  if (i == addresses_.end())
    throw AddressNotFound();

  *i = addr;
  i->recordId(recordId);
}

const Address& AddressBook::getAddress(int recordId) const{
  return *(getById(recordId));
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

AddressBook::addrlist::iterator
AddressBook::getById(int recordId){
  for (auto i = addresses_.begin(); i != addresses_.end(); ++i){
    if (i->recordId() == recordId)
      return i;
  }

  throw AddressNotFound();
}

AddressBook::addrlist::const_iterator
AddressBook::getById(int recordId) const{
  for (auto i = addresses_.begin(); i != addresses_.end(); ++i) {
    if (i->recordId() == recordId)
      return i;
  }

  throw AddressNotFound();
}
