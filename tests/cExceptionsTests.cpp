#include "gtest/gtest.h"
#include "Exceptions.h"


// still need to include full tests here

TEST(suiteName, defaultException) {
    cExceptions a;
    EXPECT_STREQ(a.what(), "default_error");
    EXPECT_EQ(-1, a.getErrorNumber());
    EXPECT_EQ(-1, a.getErrorOffset());
}

TEST(exceptionsTest, customExceptions) {
    cExceptions a("this is a custom error", 1, 1);
    EXPECT_STREQ(a.what(), "this is a custom error");
    EXPECT_EQ(1, a.getErrorNumber());
    EXPECT_EQ(1, a.getErrorOffset());
}

TEST(exceptionsTest, customExceptionsID1) {
    cExceptions a;
    EXPECT_ANY_THROW(throw a.id_error(1));
    EXPECT_STREQ("this ID already exists. ID's are unique attributes", a.what());
    EXPECT_EQ(1, a.getErrorNumber());
    EXPECT_EQ(0, a.getErrorOffset());
}

TEST(exceptionsTest, customExceptionsID2) {
    cExceptions a;
    EXPECT_ANY_THROW(throw a.id_error(2));
    EXPECT_STREQ("this ID does not exist in the current scope.", a.what());
    EXPECT_EQ(2, a.getErrorNumber());
    EXPECT_EQ(0, a.getErrorOffset());
}

TEST(exceptionsTest, customExceptionsID3) {
    cExceptions a;
    EXPECT_ANY_THROW(throw a.id_error(3));
    EXPECT_STREQ("this ID does not exist in the current scope.", a.what());
    EXPECT_EQ(3, a.getErrorNumber());
    EXPECT_EQ(0, a.getErrorOffset());
}

TEST(exceptionsTest, customExceptionsIDDefault) {
    cExceptions a;
    EXPECT_ANY_THROW(throw a.id_error(5));
    EXPECT_STREQ("invalid_error_number. default exception thrown", a.what());
    EXPECT_EQ(-1, a.getErrorNumber());
    EXPECT_EQ(-1, a.getErrorOffset());
}

TEST(exceptionsTest, customExceptionsIDXRange) {
    cExceptions a;
    EXPECT_ANY_THROW(throw a.idx_range_error());
    EXPECT_STREQ(a.what(), "index out of range error.");
    EXPECT_EQ(1, a.getErrorNumber());
    EXPECT_EQ(3, a.getErrorOffset());
}

TEST(exceptionsTest, customExceptionsWeekLimit) {
    cExceptions a;
    EXPECT_ANY_THROW(throw a.weeks_limit_error());
    EXPECT_STREQ(a.what(), "total weeks limit has been reached.");
    EXPECT_EQ(2, a.getErrorNumber());
    EXPECT_EQ(3, a.getErrorOffset());
}

TEST(exceptionsTest, customExceptionsMemory1) {
    cExceptions a;
    EXPECT_ANY_THROW(throw a.memory_leaks_error(1));
    EXPECT_STREQ(a.what(), "The players memory is not cleared.");
    EXPECT_EQ(1, a.getErrorNumber());
    EXPECT_EQ(1, a.getErrorOffset());
}

TEST(exceptionsTest, customExceptionMemory2) {
    cExceptions a;
    EXPECT_ANY_THROW(throw a.memory_leaks_error(2));
    EXPECT_STREQ(a.what(), "The orders to be executed memory is not cleared.");
    EXPECT_EQ(2, a.getErrorNumber());
    EXPECT_EQ(1, a.getErrorOffset());
}

TEST(exceptionsTest, customExceptionMemory3) {
    cExceptions a;
    EXPECT_ANY_THROW(throw a.memory_leaks_error(3));
    EXPECT_STREQ(a.what(), "The shipments to be executed memory is not cleared.");
    EXPECT_EQ(3, a.getErrorNumber());
    EXPECT_EQ(1, a.getErrorOffset());
}

TEST(exceptionsTest, customExceptionMemory4) {
    cExceptions a;
    EXPECT_ANY_THROW(throw a.memory_leaks_error(4));
    EXPECT_STREQ(a.what(), "The consumer demand memory is not cleared.");
    EXPECT_EQ(4, a.getErrorNumber());
    EXPECT_EQ(1, a.getErrorOffset());
}

TEST(cExceptionsTest, customExceptionGame1){
    cExceptions a;
    EXPECT_ANY_THROW(throw a.game_class_errors(1));
    EXPECT_STREQ(a.what(), "No players are in the game. It's possible that the game memory has been flushed.");
    EXPECT_EQ(1, a.getErrorNumber());
    EXPECT_EQ(4, a.getErrorOffset());
}

TEST(cExceptionsTest, customExceptionGame2){
    cExceptions a;
    EXPECT_ANY_THROW(throw a.game_class_errors(2));
    EXPECT_STREQ(a.what(), "This value can't be negative.");
    EXPECT_EQ(2, a.getErrorNumber());
    EXPECT_EQ(4, a.getErrorOffset());
}

TEST(cExceptionsTest, customExceptionGame3){
    cExceptions a;
    EXPECT_ANY_THROW(throw a.game_class_errors(3));
    EXPECT_STREQ(a.what(), "This value can't be 0.");
    EXPECT_EQ(3, a.getErrorNumber());
    EXPECT_EQ(4, a.getErrorOffset());
}

TEST(cExceptionsTest, customExceptionGame4){
    cExceptions a;
    EXPECT_ANY_THROW(throw a.game_class_errors(4));
    EXPECT_STREQ(a.what(), "The info code must contain 4 digits.");
    EXPECT_EQ(4, a.getErrorNumber());
    EXPECT_EQ(4, a.getErrorOffset());
}

TEST(cExceptionsTest, customExceptionGame5){
    cExceptions a;
    EXPECT_ANY_THROW(throw a.game_class_errors(5));
    EXPECT_STREQ(a.what(), "This role number does not exits.");
    EXPECT_EQ(5, a.getErrorNumber());
    EXPECT_EQ(4, a.getErrorOffset());
}

TEST(cExceptionsTest, customExceptionGame6){
    cExceptions a;
    EXPECT_ANY_THROW(throw a.game_class_errors(6));
    EXPECT_STREQ(a.what(), "Unable to execute this action from the factory player.");
    EXPECT_EQ(6, a.getErrorNumber());
    EXPECT_EQ(4, a.getErrorOffset());
}

TEST(cExceptionsTest, customExceptioonsGame7){
    cExceptions a;
    EXPECT_ANY_THROW(throw a.game_class_errors(7));
    EXPECT_STREQ(a.what(), "Unable to execute this action from the distributor player.");
    EXPECT_EQ(7, a.getErrorNumber());
    EXPECT_EQ(4, a.getErrorOffset());
}

TEST(cExceptionsTest, customExceptioonsGame8){
    cExceptions a;
    EXPECT_ANY_THROW(throw a.game_class_errors(8));
    EXPECT_STREQ(a.what(), "Unable to execute this action from the wholesaler player.");
    EXPECT_EQ(8, a.getErrorNumber());
    EXPECT_EQ(4, a.getErrorOffset());
}

TEST(cExceptionsTest, customExceptioonsGame9){
    cExceptions a;
    EXPECT_ANY_THROW(throw a.game_class_errors(9));
    EXPECT_STREQ(a.what(), "Unable to execute this action from the retailer player.");
    EXPECT_EQ(9, a.getErrorNumber());
    EXPECT_EQ(4, a.getErrorOffset());
}

TEST(cExceptionsTest, customExceptioonsGame10){
    cExceptions a;
    EXPECT_ANY_THROW(throw a.game_class_errors(10));
    EXPECT_STREQ(a.what(), "Critical logic error. This might interfere with the game logic.");
    EXPECT_EQ(10, a.getErrorNumber());
    EXPECT_EQ(4, a.getErrorOffset());
}

TEST(cExceptionsTest, customExceptioonsGame11){
    cExceptions a;
    EXPECT_ANY_THROW(throw a.game_class_errors(11));
    EXPECT_STREQ(a.what(), "Overflow in number of players. Number of players can't exceed 4.");
    EXPECT_EQ(11, a.getErrorNumber());
    EXPECT_EQ(4, a.getErrorOffset());
}

TEST(cExceptionsTest, customExceptioonsGame12){
    cExceptions a;
    EXPECT_ANY_THROW(throw a.game_class_errors(12));
    EXPECT_STREQ(a.what(), "Underflow in number of players. Number of players must be 4.");
    EXPECT_EQ(12, a.getErrorNumber());
    EXPECT_EQ(4, a.getErrorOffset());
}

TEST(cExceptionsTest, customExceptioonsGame13){
    cExceptions a;
    EXPECT_ANY_THROW(throw a.game_class_errors(13));
    EXPECT_STREQ(a.what(), "Critical logic error. IDs in players vector don't match stored IDs.");
    EXPECT_EQ(13, a.getErrorNumber());
    EXPECT_EQ(4, a.getErrorOffset());
}

TEST(cExceptionsTest, customExceptioonsGame14){
    cExceptions a;
    EXPECT_ANY_THROW(throw a.game_class_errors(14));
    EXPECT_STREQ(a.what(), "The data failed to copy.");
    EXPECT_EQ(14, a.getErrorNumber());
    EXPECT_EQ(4, a.getErrorOffset());
}

TEST(cExceptionsTest, customExceptioonsGame15){
    cExceptions a;
    EXPECT_ANY_THROW(throw a.game_class_errors(15));
    EXPECT_STREQ(a.what(), "The elements in this container exceed the limit specified.");
    EXPECT_EQ(15, a.getErrorNumber());
    EXPECT_EQ(4, a.getErrorOffset());
}

TEST(cExceptionsTest, customExceptioonsGameDEFAULT){
    cExceptions a;
    EXPECT_ANY_THROW(throw a.game_class_errors(404));
    EXPECT_STREQ(a.what(), "invalid_error_number. default exception thrown");
    EXPECT_EQ(-1, a.getErrorNumber());
    EXPECT_EQ(-1, a.getErrorOffset());
}
