// Michael Kotzjan
// HFU, 30.05.2016

#include <gtest/gtest.h>
#include <iostream>
#include <string>
#include <map>

// ____________________________________________________________________________
TEST(MapTest, testConstructor)
{
  std::map<int, std::string> testMap;
  ASSERT_TRUE(testMap.empty());
  ASSERT_EQ(0, testMap.size());
}

// ____________________________________________________________________________
TEST(MapTest, testAdd)
{
  // Insert
  std::map<int, std::string> testMap;
  testMap.insert(std::pair<int, std::string>(1, "Test"));
  ASSERT_FALSE(testMap.empty());
  ASSERT_EQ(1, testMap.size());
  ASSERT_EQ("Test", testMap.at(1));

  // [] operator
  std::map<int, std::string> testMap2;
  testMap2[1] = "Test2";
  ASSERT_FALSE(testMap2.empty());
  ASSERT_EQ(1, testMap2.size());
  ASSERT_EQ("Test2", testMap2[1]);

}

// ____________________________________________________________________________
TEST(MapTest, testAddMore)
{
  // Insert
  std::map<int, std::string> testMap;
  testMap.insert(std::pair<int, std::string>(1, "Test"));
  testMap.insert(std::pair<int, std::string>(12, "Test12"));
  testMap.insert(std::pair<int, std::string>(42, "Test42"));
  testMap.insert(std::pair<int, std::string>(123, "Test123"));
  ASSERT_FALSE(testMap.empty());
  ASSERT_EQ(4, testMap.size());
  ASSERT_EQ("Test", testMap.at(1));
  ASSERT_EQ("Test12", testMap.at(12));
  ASSERT_EQ("Test42", testMap.at(42));
  ASSERT_EQ("Test123", testMap.at(123));

  // [] operator
  std::map<int, std::string> testMap2;
  testMap2[1] = "Test";
  testMap2[12] = "Test12";
  testMap2[42] = "Test42";
  testMap2[123] = "Test123";
  ASSERT_FALSE(testMap2.empty());
  ASSERT_EQ(4, testMap.size());
  ASSERT_EQ("Test", testMap[1]);
  ASSERT_EQ("Test12", testMap[12]);
  ASSERT_EQ("Test42", testMap[42]);
  ASSERT_EQ("Test123", testMap[123]);
}

// ____________________________________________________________________________
TEST(MapTest, testFind)
{
  std::map<int, std::string> testMap;
  testMap[1] = "Test";
  testMap[13] = "Test123";
  testMap[42] = "Antwort auf die Frage nach dem Leben, dem Universum und dem ganzen Rest.";

  // Check for element which is not in the map
  ASSERT_EQ(testMap.end(), testMap.find(123));
  // Check for existing element
  ASSERT_EQ("Antwort auf die Frage nach dem Leben, dem Universum und dem ganzen Rest.", testMap.find(42)->second);
}

// ____________________________________________________________________________
TEST(MapTest, testErase)
{
  std::map<int, std::string> testMap = {
    { 1, "Test" },
    { 12, "Test12" },
    { 42, "Test42" },
    { 123, "Test123" }
  };

  ASSERT_FALSE(testMap.empty());
  ASSERT_EQ(4, testMap.size());
  
  // Erase by iterator
  testMap.erase(testMap.find(1));

  ASSERT_EQ(3, testMap.size());

  // Ersase by key
  testMap.erase(12);

  ASSERT_EQ(2, testMap.size());
  ASSERT_EQ("Test42", testMap.at(42));
  ASSERT_EQ("Test123", testMap.at(123));
}

// ____________________________________________________________________________
TEST(MapTest, testIterate)
{
  std::map<int, std::string> testMap = {
    { 1, "Test" },
    { 12, "Test12" },
    { 42, "Test42" },
    { 123, "Test123" }
  };

  // Iterate over map and check
  std::map<int, std::string>::iterator it = testMap.begin();
  ASSERT_EQ(1, it->first);
  ASSERT_EQ("Test", it->second);
  it++;
  ASSERT_EQ(12, it->first);
  ASSERT_EQ("Test12", it->second);
  it++;
  ASSERT_EQ(42, it->first);
  ASSERT_EQ("Test42", it->second);
  it++;
  ASSERT_EQ(123, it->first);
  ASSERT_EQ("Test123", it->second);
  it++;
  ASSERT_EQ(testMap.end(), it);
}
