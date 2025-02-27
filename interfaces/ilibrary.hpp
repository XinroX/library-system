#pragma once
#include "library/item.hh"
#include <vector>

class ILibrary
{
public:
    virtual std::vector<Item> getAllItems() const = 0;
    virtual std::vector<Item> getAvailableItems() const = 0;
    virtual std::vector<Item> getItemsByUser(const std::string&) const = 0;
};