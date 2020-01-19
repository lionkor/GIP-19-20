// Datei: unit_tests_mystring2_3.cpp

#include <string>

#include "catch.h"

#include "CharListenKnoten.h"
#include "MyString2.h"

TEST_CASE("Pruefung der Methode unsigned int MyString2::length()") {

	SECTION("MyString2::length() bei einem leeren MyString2") {
		MyString2 s;
		REQUIRE(s.length() == 0);
	}

	SECTION("MyString2::length() bei einem nicht-leeren MyString2") {
		MyString2 s = std::string{ "abc" };
		REQUIRE(s.length() == 3);
	}
}

TEST_CASE("Pruefung der Methode char MyString2::at(unsigned int pos)") {

	SECTION("MyString2::at() bei einem leeren MyString2") {
		MyString2 s;
		REQUIRE(s.at(0) == '\0');
		REQUIRE(s.at(99) == '\0');
	}

	SECTION("MyString2::at() bei einem nicht-leeren MyString2") {
		MyString2 s = std::string{ "abc" };
		REQUIRE(s.at(0) == 'a');
		REQUIRE(s.at(1) == 'b');
		REQUIRE(s.at(2) == 'c');
		REQUIRE(s.at(3) == '\0');
		REQUIRE(s.at(4) == '\0');
		REQUIRE(s.at(5) == '\0');
		REQUIRE(s.at(99) == '\0');
	}
}

TEST_CASE("Pruefung der Methode MyString2 MyString2::operator+(char c)") {

	MyString2 s;

	MyString2 s2 = s + 'x';
	REQUIRE(s2.get_anker() != nullptr);
	REQUIRE(s2.get_anker()->get_data() == 'x');
	REQUIRE(s2.get_anker()->get_next() == nullptr);
	REQUIRE(s2.length() == 1);
	REQUIRE(s2.get_anker() != s.get_anker());

	MyString2 s3 = s2 + 'y';
	REQUIRE(s3.get_anker() != nullptr);
	REQUIRE(s3.get_anker()->get_data() == 'x');
	REQUIRE(s3.get_anker()->get_next() != nullptr);
	REQUIRE(s3.get_anker()->get_next()->get_data() == 'y');
	REQUIRE(s3.get_anker()->get_next()->get_next() == nullptr);
	REQUIRE(s3.length() == 2);
	REQUIRE(s3.get_anker() != s2.get_anker());
	REQUIRE(s3.get_anker()->get_next() != s2.get_anker()->get_next());

}

TEST_CASE("Pruefung der Methode std::string MyString2::to_string()") {

	SECTION("MyString2::to_string() bei einem leeren MyString2") {
		MyString2 s;
		REQUIRE(s.to_string() == std::string(""));
	}

	SECTION("MyString2::to_string() bei einem nicht-leeren MyString2") {
		MyString2 s = std::string("abc");
		REQUIRE(s.to_string() == std::string("abc"));
	}
}
