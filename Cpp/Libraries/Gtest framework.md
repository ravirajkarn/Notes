---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2025-07-27T06:12:00
tags:
  - Cpp
  - Framework
  - google
  - CMakeList
---
# **[GTest](https://google.github.io/googletest/)**

> [!important] TEST
> - It is micron. You can think it as a function.
> ```cpp
> TEST(TestGroupName, TestName ){}
> ```

> [!success] Assertions
> In google test assertions are of three type.
> ![[assertions.png]]
> **ASSERT_EQ() :** If it fails, then the test will terminate.
> ![[Expect and Assert.png]]
> **Assertions on string**
> ![[assertion on string.png]]


## How to write a test.
![[how to write test.png]]


> [!NOTE]  What is Unit Test?
> ![[unit test.png]]

## Test Fixture
![[test fixture.png]]

```cpp
#include <gtest/gtest.h>
using namespace std;
  
class Stack {
	vector<int> vstack = {}; 
	
	public:
		void push(int value) { vstack.push_back(value); }
		int pop() {
			if (vstack.size() > 0) {
				int value = vstack.back();
				vstack.pop_back();
				return value;
			} else {
			return -1;
			}
		}
		int size() { return vstack.size(); }
};
  
struct stackTest : public testing::Test {
	Stack s1;
	void SetUp() {
		int value[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
		for (auto& val : value) {
			s1.push(val);
		}
	}
	void TearDown() {}
};
  
TEST_F(stackTest, PopTest) {
	int lastPoppedValue = 9;
	while (lastPoppedValue != 1) ASSERT_EQ(s1.pop(), lastPoppedValue--);
}
  
TEST_F(stackTest, sizeValidityTest) {
	int val = s1.size();
	for (val; val > 0; val--) ASSERT_NE(s1.pop(), -1);
}
  
int main(int argc, char** argv) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
```

> [!summary] Purpose of fixture
> In above case there is a stack created by vector. And we have to test the working of the code. So, we wrote some TEST for it to pop a element. We do it we have to pop build pop test for each element. So we wrote a fixture to generalise it.


## Mock
![[Pasted image 20260521231647.png]]
if your code needs to interact with something complicated, like a database or a live server, a "mock" lets you pretend to be that system so you can test your code safely without needing the real thing.

```cpp
#include <gmock/gmock.h>
#include <gtest/gtest.h>
  
#include <iostream>
#include <vector>
  
using namespace std;
using ::testing::_;
using ::testing::AtLeast;
using ::testing::Return;
  
class DataBaseConnect {
	public:
		virtual bool login(string username, string password) { return true; }
		virtual bool login2(string username, string password) { return true; }
		virtual bool logout(string username) { return true; }
		virtual int fetchRecord() { return -1; }
};
  
class MockDB : public DataBaseConnect {
	public:
		MOCK_METHOD0(fetchRecord, int());
		MOCK_METHOD1(logout, bool(string username));
		MOCK_METHOD2(login, bool(string username, string password));
		MOCK_METHOD2(login2, bool(string username, string password));
};
  
class MyDatabase {
	DataBaseConnect& dbC;
	
	public:
		MyDatabase(DataBaseConnect& _dbC) : dbC(_dbC) {}
		int Init(string username, string password) {
			int rvalue = rand() % 2;
			if (rvalue == 0) {
				if (dbC.login(username, password) != true) {
					if (dbC.login(username, password) != true) {
						cout << "DB FAILURE" << endl;
						return -1;
					}
				} else
					cout << "DB SUCCESS" << endl;
				return 1;
			} else {
				return dbC.login2(username, password);
		}
	}
};
  
TEST(MyDBTest, LoginTest) {
	// Arrange
	MockDB mdb;
	MyDatabase db(mdb);
	// EXPECT_CALL(mdb, login(_, _)).Times(AtLeast(1)).WillOnce(Return(true));
	ON_CALL(mdb, login(_, _)).WillByDefault(Return(true));
	ON_CALL(mdb, login2(_, _)).WillByDefault(Return(true));
	// Act
	int retValue = db.Init("Terminator", "I'll be Back");
	// Assert
	EXPECT_EQ(retValue, 1);
}
  
TEST(MyDBTest, LoginFailure) {
	// Arrange
	MockDB mdb;
	MyDatabase db(mdb);
	EXPECT_CALL(mdb, login(_,_)).Times(AtLeast(2)).WillRepeatedly(Return(false));
	// Act
	int retValue = db.Init("Terminator", "I'll be Back");
	// Assert
	EXPECT_EQ(retValue, -1);
}
  
int main(int argc, char** argv) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
```

## CMakeList
```cmake
# 1. Project Setup
cmake_minimum_required(VERSION 3.15)
project(MyDatabaseTests CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 2. Find GTest (Assuming you are using Conan to provide the package)
find_package(GTest REQUIRED)

# 3. Build the Test Executable
add_executable(leetCode2_test test/test2.cpp)

# Link the required GTest and GMock libraries
target_link_libraries(leetCode2_test 
    PRIVATE 
    GTest::gmock 
    GTest::gmock_main 
    GTest::gtest 
    GTest::gtest_main
)

# 4. Integrate with CTest
enable_testing() # Turns on CMake's test runner
include(GoogleTest)

# This command parses your executable and registers each TEST() or TEST_F() 
# as an individual CTest, rather than running the whole binary as one giant test.
gtest_discover_tests(leetCode2_test)
```
