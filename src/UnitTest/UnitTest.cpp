#include "pch.h"
#include "CppUnitTest.h"
#include "../include/libgeom.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:

		TEST_METHOD(TestMethod_same_AABB)
		{
			AABB aabb1(0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f);

			Assert::AreEqual(true, AABB::isCollide(aabb1, aabb1));
		}

		TEST_METHOD(TestMethod_inside_AABB)
		{
			AABB aabb1(0.0f, 0.0f, 0.0f, 3.0f, 3.0f, 3.0f);
			AABB aabb2(1.0f, 1.0f, 1.0f, 2.0f, 2.0f, 2.0f);

			Assert::AreEqual(true, AABB::isCollide(aabb1, aabb2));
			Assert::AreEqual(true, AABB::isCollide(aabb2, aabb1));
		}

		TEST_METHOD(TestMethod_all_out)
		{
			AABB aabb1(0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f);
			AABB aabb2(2.0f, 2.0f, 2.0f, 3.0f, 3.0f, 3.0f);

			Assert::AreEqual(false, AABB::isCollide(aabb1, aabb2));
			Assert::AreEqual(false, AABB::isCollide(aabb2, aabb1));
		}

		TEST_METHOD(TestMethod_x_min)
		{
			AABB aabb1(0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f);
			AABB aabb2(-0.5f, 0.0f, 0.0f, 0.5f, 1.0f, 1.0f);

			Assert::AreEqual(true, AABB::isCollide(aabb1, aabb2));
			Assert::AreEqual(true, AABB::isCollide(aabb2, aabb1));
		}

		TEST_METHOD(TestMethod_x_max)
		{
			AABB aabb1(0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f);
			AABB aabb2(0.5f, 0.0f, 0.0f, 1.5f, 1.0f, 1.0f);

			Assert::AreEqual(true, AABB::isCollide(aabb1, aabb2));
			Assert::AreEqual(true, AABB::isCollide(aabb2, aabb1));
		}

		TEST_METHOD(TestMethod_x_min_out)
		{
			AABB aabb1(0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f);
			AABB aabb2(-1.5f, 0.0f, 0.0f, -0.5f, 1.0f, 1.0f);

			Assert::AreEqual(false, AABB::isCollide(aabb1, aabb2));
			Assert::AreEqual(false, AABB::isCollide(aabb2, aabb1));
		}

		TEST_METHOD(TestMethod_x_max_out)
		{
			AABB aabb1(0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f);
			AABB aabb2(1.5f, 0.0f, 0.0f, 2.5f, 1.0f, 1.0f);

			Assert::AreEqual(false, AABB::isCollide(aabb1, aabb2));
			Assert::AreEqual(false, AABB::isCollide(aabb2, aabb1));
		}

		TEST_METHOD(TestMethod_y_min)
		{
			AABB aabb1(0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f);
			AABB aabb2(0.0f,-0.5f, 0.0f, 1.0f, 0.5f, 1.0f);

			Assert::AreEqual(true, AABB::isCollide(aabb1, aabb2));
			Assert::AreEqual(true, AABB::isCollide(aabb2, aabb1));
		}

		TEST_METHOD(TestMethod_y_max)
		{
			AABB aabb1(0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f);
			AABB aabb2(0.0f, 0.5f, 0.0f, 1.0f, 1.5f, 1.0f);

			Assert::AreEqual(true, AABB::isCollide(aabb1, aabb2));
			Assert::AreEqual(true, AABB::isCollide(aabb2, aabb1));
		}

		TEST_METHOD(TestMethod_y_min_out)
		{
			AABB aabb1(0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f);
			AABB aabb2(0.0f,-1.5f, 0.0f, 1.0f,-0.5f, 1.0f);

			Assert::AreEqual(false, AABB::isCollide(aabb1, aabb2));
			Assert::AreEqual(false, AABB::isCollide(aabb2, aabb1));
		}

		TEST_METHOD(TestMethod_y_max_out)
		{
			AABB aabb1(0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f);
			AABB aabb2(0.0f, 1.5f, 0.0f, 1.0f, 2.5f, 1.0f);

			Assert::AreEqual(false, AABB::isCollide(aabb1, aabb2));
			Assert::AreEqual(false, AABB::isCollide(aabb2, aabb1));
		}

		TEST_METHOD(TestMethod_z_min)
		{
			AABB aabb1(0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f);
			AABB aabb2(0.0f, 0.0f,-0.5f, 1.0f, 1.0f, 0.5f);

			Assert::AreEqual(true, AABB::isCollide(aabb1, aabb2));
			Assert::AreEqual(true, AABB::isCollide(aabb2, aabb1));
		}

		TEST_METHOD(TestMethod_z_max)
		{
			AABB aabb1(0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f);
			AABB aabb2(0.0f, 0.0f, 0.5f, 1.0f, 1.0f, 1.5f);

			Assert::AreEqual(true, AABB::isCollide(aabb1, aabb2));
			Assert::AreEqual(true, AABB::isCollide(aabb2, aabb1));
		}

		TEST_METHOD(TestMethod_z_min_out)
		{
			AABB aabb1(0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f);
			AABB aabb2(0.0f, 0.0f,-1.5f, 1.0f, 1.0f,-0.5f);

			Assert::AreEqual(false, AABB::isCollide(aabb1, aabb2));
			Assert::AreEqual(false, AABB::isCollide(aabb2, aabb1));
		}

		TEST_METHOD(TestMethod_z_max_out)
		{
			AABB aabb1(0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f);
			AABB aabb2(0.0f, 0.0f, 1.5f, 1.0f, 1.0f, 2.5f);

			Assert::AreEqual(false, AABB::isCollide(aabb1, aabb2));
			Assert::AreEqual(false, AABB::isCollide(aabb2, aabb1));
		}
	};
}
