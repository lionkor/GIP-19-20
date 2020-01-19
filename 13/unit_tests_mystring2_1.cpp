// Datei: unit_tests_mystring2_1.cpp

#include "catch.h"

#include "CharListenKnoten.h"
#include "MyString2.h"

TEST_CASE("Pruefung der Methoden MyString2::get_anker() / CharListenKnoten::set_anker()") {

	MyString2 s;
	CharListenKnoten* k_ptr = new CharListenKnoten;

	REQUIRE(s.get_anker() == nullptr);

	s.set_anker(k_ptr);

	REQUIRE(s.get_anker() == k_ptr);
}
