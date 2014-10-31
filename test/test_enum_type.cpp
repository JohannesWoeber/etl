/******************************************************************************
The MIT License(MIT)

Embedded Template Library.

Copyright(c) 2014 jwellbelove

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files(the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and / or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions :

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
******************************************************************************/

#include <UnitTest++/UnitTest++.h>
#include <string>

#include "../enum_type.h"

struct enum_test
{
  enum enum_type
  {
    ZERO,
    ONE,
    THREE = 3,
    FOUR
  };

  DECLARE_ENUM_TYPE(enum_test, int)
  ENUM_TYPE(ZERO,  "ZERO")
  ENUM_TYPE(ONE,   "ONE")
  ENUM_TYPE(THREE, "THREE")
  END_ENUM_TYPE
};

namespace 
{		
  SUITE(TestEnumType)
  {
    //*************************************************************************
    TEST(Values)
    {
      CHECK_EQUAL(0, enum_test::value_type(enum_test::ZERO));
      CHECK_EQUAL(1, enum_test::value_type(enum_test::ONE));
      CHECK_EQUAL(3, enum_test::value_type(enum_test::THREE));
      CHECK_EQUAL(4, enum_test::value_type(enum_test::FOUR));
    }

    //*************************************************************************
    TEST(Strings)
    {
      enum_test value;

      value = enum_test::ZERO;
      CHECK_EQUAL(std::string("ZERO"), std::string(value.c_str()));

      value = enum_test::ONE;
      CHECK_EQUAL(std::string("ONE"), std::string(value.c_str()));

      value = enum_test::THREE;
      CHECK_EQUAL(std::string("THREE"), std::string(value.c_str()));

      // No ENUM_TYPE definition.
      value = enum_test::FOUR;
      CHECK_EQUAL(std::string("?"), std::string(value.c_str()));

      // Illegal value.
      value = enum_test(5);
      CHECK_EQUAL(std::string("?"), std::string(value.c_str()));
    }

    //*************************************************************************
    TEST(Assignment)
    {
      enum_test value1 = enum_test::ZERO;
      enum_test value2 = enum_test::ONE;

      value1 = value2;

      CHECK_EQUAL(enum_test::ONE, value1);
    }

    //*************************************************************************
    TEST(GetValue)
    {
      enum_test actual = enum_test::THREE;
      enum_test::value_type expected = enum_test::THREE; 

      CHECK_EQUAL(expected, actual.get_value());
    }

    //*************************************************************************
    TEST(GetEnum)
    {
      enum_test actual = enum_test::THREE;
      enum_test::enum_type expected = enum_test::THREE;

      CHECK_EQUAL(expected, actual.get_enum());
    }
  };
}