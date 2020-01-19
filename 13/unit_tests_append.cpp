// Datei: unit_tests_append.cpp

#include "catch.h"

#include "CharListenKnoten.h"
#include "MyString2.h"

TEST_CASE("Pruefung der Methode void MyString2::append(char p_data)") {

	SECTION("MyString2::append() bei einem leeren MyString2") {

		MyString2 s;
		REQUIRE(s.get_anker() == nullptr);

		s.append('x');

		REQUIRE(s.get_anker() != nullptr);
		REQUIRE(s.get_anker()->get_data() == 'x');
		REQUIRE(s.get_anker()->get_next() == nullptr);
	}

	SECTION("MyString2::append() bei einem nicht-leeren MyString2") {

		MyString2 s;
		s.append('a');

		s.append('b');

		REQUIRE(s.get_anker() != nullptr);
		REQUIRE(s.get_anker()->get_data() == 'a');
		REQUIRE(s.get_anker()->get_next() != nullptr);
		REQUIRE(s.get_anker()->get_next()->get_data() == 'b');
		REQUIRE(s.get_anker()->get_next()->get_next() == nullptr);

		s.append('c');

		REQUIRE(s.get_anker() != nullptr);
		REQUIRE(s.get_anker()->get_data() == 'a');
		REQUIRE(s.get_anker()->get_next() != nullptr);
		REQUIRE(s.get_anker()->get_next()->get_data() == 'b');
		REQUIRE(s.get_anker()->get_next()->get_next() != nullptr);
		REQUIRE(s.get_anker()->get_next()->get_next()->get_data() == 'c');
		REQUIRE(s.get_anker()->get_next()->get_next()->get_next() == nullptr);
	}
}


