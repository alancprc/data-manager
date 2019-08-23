#ifndef DATA_MANAGER_H_
#define DATA_MANAGER_H_
#include <algorithm>
#include <string>
#include <vector>

enum ItemMode { mSTD, mDATE };

struct DataItem
{
  std::string name;
  ItemMode mode;
  unsigned lsb;
  unsigned len;
  std::string process;
  double llimit;
  double hlimit;
  void print() const;
};

class DataManager
{
 public:
  void addItem(const DataItem &item) { data_.push_back(item); }
  void print() const
  {
    for (std::vector<DataItem>::const_iterator it = data_.begin();
         it != data_.end(); ++it)
      it->print();
  }

 private:
  std::vector<DataItem> data_;
};

#endif
