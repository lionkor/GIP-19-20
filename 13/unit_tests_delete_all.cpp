// Datei: unit_tests_delete_all.cpp

#include "catch.h"

#include "CharListenKnoten.h"
#include "MyString2.h"

TEST_CASE("Pruefung der Methode void MyString2::delete()") {

	SECTION("MyString2::delete() bei einem leeren MyString2") {

		MyString2 s;
		REQUIRE(s.get_anker() == nullptr);

		s.delete_all();

		REQUIRE(s.get_anker() == nullptr);
	}

	SECTION("MyString2::delete() bei einem MyString2 mit einem Buchstaben") {

		MyString2 s;
		s.append('a');
		REQUIRE(s.get_anker() != nullptr);
		REQUIRE(s.get_anker()->get_data() == 'a');
		REQUIRE(s.get_anker()->get_next() == nullptr);

		s.delete_all();

		REQUIRE(s.get_anker() == nullptr);
	}

	SECTION("MyString2::delete() bei einem MyString2 mit zwei Buchstaben") {

		MyString2 s;
		s.append('a');
		s.append('b');
		REQUIRE(s.get_anker() != nullptr);
		REQUIRE(s.get_anker()->get_data() == 'a');
		REQUIRE(s.get_anker()->get_next() != nullptr);
		REQUIRE(s.get_anker()->get_next()->get_data() == 'b');
		REQUIRE(s.get_anker()->get_next()->get_next() == nullptr);

		s.delete_all();

		REQUIRE(s.get_anker() == nullptr);
	}
}


