#include <gtest/gtest.h>
#include <iomanip>
#include <iostream>
#include "data-manager.h"

using namespace std;

void DataItem::print() const
{
  cout << setw(13) << left << name << "\t" << mode << "\t" << process << "\t\n";
}

TEST(DataManagerTest, ArrayInitTest)
{
  DataItem efuseTable[1] = {{"Foo", mSTD, 0, 8, "RT_FTA", 0, 255}};
}
TEST(DataManagerTest, ArrayPrintTest)
{
  DataItem efuseTable[1] = {{"Foo", mSTD, 0, 8, "RT_FTA", 0, 255}};
  for (size_t i = 0; i < sizeof(efuseTable) / sizeof(DataItem); ++i) {
    efuseTable[i].print();
  }
}

TEST(DataManagerTest, ObjectInitTest) { DataManager efuse; }

TEST(DataManagerTest, ObjectAddItemTest)
{
  DataManager efuse;
  efuse.addItem({"CHIPID", mSTD, 32, 24, "RT_FTA", 0, 3});
}

TEST(DataManagerTest, ObjectPrintTest)
{
  DataManager efuse;
  efuse.addItem({"CHIPID", mSTD, 32, 24, "RT_FTA", 0, 3});
  efuse.print();
}
