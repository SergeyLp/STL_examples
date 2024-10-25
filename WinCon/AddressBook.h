// TinyPIM (c) 1999 Pablo Halpern. File AddressBook.h
#pragma once
#pragma warning( disable : 5040 5043 4290)

#ifndef USED_PRECOMPILE
#include <vector>
#endif // !USED_PRECOMPILE
#include "Address.h"

class AddressBook
{
public:
  AddressBook() = default;
  ~AddressBook() = default;

  // Exception classes
  class AddressNotFound { };
  class DuplicateId { };

  int insertAddress(const Address& addr, int recordId = 0); //-V1071
  void eraseAddress(int recordId);
  void replaceAddress(const Address& addr, int recordId = 0);
  const Address& getAddress(int recordId) const;

  // Test routine to print out contents of address book
  void print() const;

private:
  // Disable copying
  AddressBook(const AddressBook&) = delete;
  AddressBook& operator=(const AddressBook&) = delete;

  static int nextId_;
  std::vector<Address> addresses_;

  // Get the index of the record with the specified ID.
  // Returns notFound if not found.
  int getById(int recordId) const;
  const int notFound = 0;//-1 ;
};
