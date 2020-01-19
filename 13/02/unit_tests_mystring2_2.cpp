// Datei: unit_tests_mystring2_2.cpp

#include <string>

#include "catch.h"

#include "CharListenKnoten.h"
#include "MyString2.h"

TEST_CASE("Pruefung des Konstruktors MyString2(std::string )") {

	MyString2 s = std::string{ "abc" };

	REQUIRE(s.get_anker() != nullptr);
	REQUIRE(s.get_anker()->get_data() == 'a');
	REQUIRE(s.get_anker()->get_next() != nullptr);
	REQUIRE(s.get_anker()->get_next()->get_data() == 'b');
	REQUIRE(s.get_anker()->get_next()->get_next() != nullptr);
	REQUIRE(s.get_anker()->get_next()->get_next()->get_data() == 'c');
	REQUIRE(s.get_anker()->get_next()->get_next()->get_next() == nullptr);
}

TEST_CASE("Pruefung des Copy-Konstruktors von MyString2") {

	MyString2 s = std::string{ "abc" };
	MyString2 s2 = s;

	REQUIRE(s2.get_anker() != nullptr);
	REQUIRE(s2.get_anker() != s.get_anker());
	REQUIRE(s2.get_anker()->get_data() == 'a');
	REQUIRE(s2.get_anker()->get_next() != nullptr);
	REQUIRE(s2.get_anker()->get_next() != s.get_anker()->get_next());
	REQUIRE(s2.get_anker()->get_next()->get_data() == 'b');
	REQUIRE(s2.get_anker()->get_next()->get_next() != nullptr);
	REQUIRE(s2.get_anker()->get_next()->get_next() != s.get_anker()->get_next()->get_next());
	REQUIRE(s2.get_anker()->get_next()->get_next()->get_data() == 'c');
	REQUIRE(s2.get_anker()->get_next()->get_next()->get_next() == nullptr);
}

TEST_CASE("Pruefung des Assignment Operators von MyString2") {

	MyString2 s = std::string{ "abc" };
	MyString2 s2 = std::string{ "def" };

	CharListenKnoten* p1 = s2.get_anker();
	REQUIRE(p1 != nullptr);
	CharListenKnoten* p2 = s2.get_anker()->get_next();
	REQUIRE(p2 != nullptr);
	CharListenKnoten* p3 = s2.get_anker()->get_next()->get_next();
	REQUIRE(p3 != nullptr);

	s2 = s;

	REQUIRE(s2.get_anker() != nullptr);
	REQUIRE(s2.get_anker() != s.get_anker());
	REQUIRE(s2.get_anker() != p1);
	REQUIRE(s2.get_anker()->get_data() == 'a');
	REQUIRE(s2.get_anker()->get_next() != nullptr);
	REQUIRE(s2.get_anker()->get_next() != s.get_anker()->get_next());
	REQUIRE(s2.get_anker()->get_next() != p2);
	REQUIRE(s2.get_anker()->get_next()->get_data() == 'b');
	REQUIRE(s2.get_anker()->get_next()->get_next() != nullptr);
	REQUIRE(s2.get_anker()->get_next()->get_next() != s.get_anker()->get_next()->get_next());
	REQUIRE(s2.get_anker()->get_next()->get_next() != p3);
	REQUIRE(s2.get_anker()->get_next()->get_next()->get_data() == 'c');
	REQUIRE(s2.get_anker()->get_next()->get_next()->get_next() == nullptr);
}
