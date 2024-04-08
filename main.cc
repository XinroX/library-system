#include "library.hh"
#include <memory>
#include "item.hh"


int main() {
    std::shared_ptr<Item> item = std::make_shared<Item>("TEST", "AUTHOR", "BOOK");
    std::shared_ptr<Reader> reader = std::make_shared<Reader>("FIRST NAME", "LAST NAME", "00004");
    std::shared_ptr<Library> library = std::make_shared<Library>();

    reader->add_item(item);
    library->add_reader(reader);

    Items items = library->getItemsByReaderNumber("00004");
    std::cout << items.size() << '\n';

    return 0;
}