#include "gtest/gtest.h"
#include "Instructor.h"

TEST(instructorTest, setInstrIdTest) {
    Instructor i;
    i.setInstrId(2020);
    EXPECT_EQ(2020, i.getInstrId());
}

TEST(instructorTest, getInstrIdTest) {
    Instructor i;
    i.setInstrId(30);
    EXPECT_EQ(30, i.getInstrId());
}

TEST(instructorTest, setInstrEmailTest) {
    Instructor i;
    i.setInstrEmail("hi.again@jacobs-university.de");
    std::string email = "hi.again@jacobs-university.de";
    EXPECT_EQ(email, i.getInstrEmail());
}

TEST(instructorTest, getInstrEmailTest) {
    Instructor i;
    i.setInstrEmail("hi.there@jacobs-university.de");
    EXPECT_EQ("hi.there@jacobs-university.de", i.getInstrEmail());
}

TEST(instructorTest, setInstrPasswordTest) {
    Instructor i;
    i.setInstrPassword("superstrongpassword");
    EXPECT_EQ("superstrongpassword", i.getInstrPassword());
}

TEST(instructorTest, getInstrPasswordTest) {
    Instructor i;
    i.setInstrPassword("weakpassword");
    EXPECT_EQ("weakpassword", i.getInstrPassword());
}

TEST(instructorTest, setGamesTest){
    Instructor instructor;
    std::vector<Game> games;
    instructor.setGames(games);
    EXPECT_EQ(instructor.getGames(), games);
}

TEST(instructorTest, getGamesTest){
    Instructor instructor;
    std::vector<Game> games;
    Game game;
    games.push_back(game);
    instructor.setGames(games);
    EXPECT_EQ(instructor.getGames(), games);
}
