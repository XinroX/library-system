#include "library.hh"
#include <algorithm>

Items Library::getItemsByReaderNumber(const std::string& readerNumber) {
    auto reader = std::find_if(readers.begin(), readers.end(), [&readerNumber](std::shared_ptr<Reader> reader) {
        // std::cout << reader->get_number();
        return reader->get_number() == readerNumber;
    });
    if (reader == readers.end()) return Items{};

    return reader->get()->get_items();
}

void Library::add_reader(const std::shared_ptr<Reader>& reader) {
    if (std::find(readers.begin(), readers.end(), reader) == readers.end()) {
        readers.emplace_back(reader);
    }
}
