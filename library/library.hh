#ifndef _LIBRARY_H_
#define _LIBRARY_H_
#include "reader.hh"
#include "item.hh"
#include <vector>
#include <memory>

using Readers = std::vector<std::shared_ptr<Reader>>;

class Library {

public:
    Items getItemsByReaderNumber(const std::string& readerNumber);
    void add_reader(const std::shared_ptr<Reader>& reader);
private:
    Readers readers;
};


#endif