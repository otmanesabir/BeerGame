#include "gtest/gtest.h"
#include "UniqueID.h"

TEST(uniqueIDTest, createInstanceID) {
    UniqueID a;
    UniqueID b;
    EXPECT_FALSE(a == b);
}

TEST(uniqueIDTest, createInstaceID2) {
    UniqueID(false);
    UniqueID a(4);
    UniqueID b(5);
    EXPECT_FALSE(a == b);
}

TEST(uniqueIDTest, IDOverwriteTest) {
    UniqueID(false);
    UniqueID a(1, true);
    UniqueID b(1, true);
    EXPECT_EQ((int) a, (int) b);
}

/*
TEST(uniqueIDTest, createMultipleUniqueInstances){
UniqueID(false);
std::vector<UniqueID> ids;
ids.reserve(100);
for (int i = 0; i < 100; i++){
ids.emplace_back(UniqueID());
}
sort(ids.begin(), ids.end());
auto it = std::unique( ids.begin(), ids.end() );
EXPECT_TRUE(it == ids.end());
}
*/

TEST(uniqueIDTest, createInstanceException) {
    UniqueID(false);
    EXPECT_ANY_THROW(UniqueID a(0, false));
}

TEST(uniqueIDTest, createInstanceNoException) {
    UniqueID(false);
    EXPECT_NO_THROW(UniqueID a(2, false));
}
