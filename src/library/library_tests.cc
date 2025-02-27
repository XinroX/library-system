#include <gtest/gtest.h>
#include "library/item.hh"
#include "library/reader.hh"
#include "library/library.hh"

TEST(LibraryTest, AddItemToReader) {
    auto item = std::make_shared<Item>("Test", "Test", "Test");
    auto reader = std::make_shared<Reader>("Test", "Test", "00001");

    reader->add_item(item);

    ASSERT_EQ(1, reader->get_items().size());
}

TEST(LibraryTest, Add2ItemsToReader) {
    auto item = std::make_shared<Item>("Test", "Test", "Test");
    auto item2 = std::make_shared<Item>("Test", "Test", "Test");
    auto reader = std::make_shared<Reader>("Test", "Test", "00001");

    reader->add_item(item);
    reader->add_item(item2);

    ASSERT_EQ(2, reader->get_items().size());
    
}

TEST(LibraryTest, Add2SameItemsToReader) {
    auto item = std::make_shared<Item>("Test", "Test", "Test");
    auto reader = std::make_shared<Reader>("Test", "Test", "00001");

    reader->add_item(item);
    reader->add_item(item);

    ASSERT_EQ(1, reader->get_items().size());

}

TEST(LibraryTest, GetItemsFromWrongReaderNumber) {
    Library library;

    ASSERT_EQ(0, library.getItemsByReaderNumber("000000").size());

}

TEST(LibraryTest, AddReaderWithoutItems) {
    Library library;
    auto reader = std::make_shared<Reader>("Test", "Test", "00001");

    library.add_reader(reader);

    ASSERT_EQ(0, library.getItemsByReaderNumber("00001").size());
}

int main() {
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}