#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "header.h"
#include "func.cpp"

TEST_CASE("Numeris_TempIsNotNumber_ReturnsFalse")
{
    string temp = "Test"; //Arrange
    bool result = numeris(temp); //Act
    REQUIRE(result == false); //Assert
};

TEST_CASE("Numeris_TempIsNumber_ReturnsTrue")
{
    string temp = "123"; //Arrange
    bool result = numeris(temp); //Act
    REQUIRE(result == true); //Assert
}

TEST_CASE("Numeris_TempHasNumber_ReturnsFalse")
{
    string temp = "T3st"; //Arrange
    bool result = numeris(temp); //Act
    REQUIRE(result == false); //Assert
}

TEST_CASE("Skirstymas_AllAveragesAboveFive_ReturnsLiudnukaiSizeZero")
{
    //Arrange
    studentas a, b, c; 
    vector <studentas> stud, liudnukai;
    double f;

    a.setVid(10); b.setVid(10); c.setVid(10); 
    stud.push_back(a);
    stud.push_back(b);
    stud.push_back(c);

    //Act
    skirstymas(stud, liudnukai);

    //Assert
    REQUIRE(stud.size() == 3);
    REQUIRE(liudnukai.size() == 0);
}

TEST_CASE("Skirstymas_AllAveragesUnderFive_ReturnsLiudnukaiSizeThree")
{
    //Arrange
    studentas a, b, c;
    vector <studentas> stud, liudnukai;
    double f;

    a.setVid(4); b.setVid(4); c.setVid(4);
    stud.push_back(a);
    stud.push_back(b);
    stud.push_back(c);

    //Act
    skirstymas(stud, liudnukai);

    //Assert
    REQUIRE(stud.size() == 0);
    REQUIRE(liudnukai.size() == 3);
}

TEST_CASE("Skirstymas_TwoAveragesAboveFive_ReturnsLiudnukaiSizeOne")
{
    //Arrange
    studentas a, b, c;
    vector <studentas> stud, liudnukai;
    double f;

    a.setVid(10); b.setVid(10); c.setVid(4);
    stud.push_back(a);
    stud.push_back(b);
    stud.push_back(c);

    //Act
    skirstymas(stud, liudnukai);

    //Assert
    REQUIRE(stud.size() == 2);
    REQUIRE(liudnukai.size() == 1);
}