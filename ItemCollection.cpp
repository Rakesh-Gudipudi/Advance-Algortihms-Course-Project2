#include <string>

#include <iostream>

#include <fstream>

#include <stdexcept>

#include <algorithm>    

#include <array>

#include "ItemCollection.hpp"

using std::string;
using std::ifstream;
using std::cout;
using std::endl;

// function to return the hash value based on the first digit
unsigned int hashfct1(unsigned int barcode) {
  unsigned int d = barcode / 1000000;
  d = d % 10;
  return d;
}

// function to return the hash value based on the second digit
unsigned int hashfct2(unsigned int barcode) {
  unsigned int d = barcode / 100000;
  d = d % 10;
  return d;
}

// function to return the hash value based on the third digit
unsigned int hashfct3(unsigned int barcode) {
  unsigned int d = barcode / 10000;
  d = d % 10;
  return d;
}

// function to return the hash value based on the fourth digit
unsigned int hashfct4(unsigned int barcode) {
  unsigned int d = barcode / 1000;
  d = d % 10;
  return d;
}

// function to return the hash value based on the fifth digit
unsigned int hashfct5(unsigned int barcode) {
  unsigned int d = barcode / 100;
  d = d % 10;
  return d;
}

// function to return the hash value based on the fourth digit
unsigned int hashfct6(unsigned int barcode) {
  unsigned int d = barcode / 10;
  d = d % 10;
  return d;
}

// function to return the hash value based on the fifth digit
unsigned int hashfct7(unsigned int barcode) {
  unsigned int d = barcode;
  d = d % 10;
  return d;
}

// Constructor for struct Item
Item::Item(string itemColor, string itemShape, string itemBrand,
    unsigned int barcode): itemColor_(itemColor), itemShape_(itemShape), itemBrand_(itemBrand),
  barcode_(barcode) {};

// Load information from a text file with the given filename
// THIS FUNCTION IS COMPLETE
void ItemCollection::readTextfile(string filename) {
  ifstream myfile(filename);

  if (myfile.is_open()) {
    cout << "Successfully opened file " << filename << endl;
    string itemColor;
    string itemShape;
    string itemBrand;
    unsigned int barcode;
    while (myfile >> itemColor >> itemShape >> itemBrand >> barcode) {
      if (itemColor.size() > 0)
        addItem(itemColor, itemShape, itemBrand, barcode);
    }
    myfile.close();
  } else
    throw std::invalid_argument("Could not open file " + filename);
}

void ItemCollection::addItem(string itemColor, string itemShape, string itemBrand, unsigned int barcode) {
  Item item(itemColor, itemShape, itemBrand, barcode);

  hT1[barcode] = item;
  hT2[barcode] = item;
  hT3[barcode] = item;
  hT4[barcode] = item;
  hT5[barcode] = item;
  hT6[barcode] = item;
  hT7[barcode] = item;

}

bool ItemCollection::removeItem(unsigned int barcode) {
  if (hT1.erase(barcode) != 1) return false;
  if (hT2.erase(barcode) != 1) return false;
  if (hT3.erase(barcode) != 1) return false;
  if (hT4.erase(barcode) != 1) return false;
  if (hT5.erase(barcode) != 1) return false;
  if (hT6.erase(barcode) != 1) return false;
  if (hT7.erase(barcode) != 1) return false;
  return true;
}

unsigned int ItemCollection::bestHashing() {
  unsigned int min_loc, max_loc;
  unsigned int balance[8];
  unsigned int bucket[10];
  balance[0] = 0;
  for (unsigned int i = 0; i < 10; ++i) {
    bucket[i] = hT1.bucket_size(i);
  }
  min_loc = * std::min_element(bucket, bucket + 10);
  max_loc = * std::max_element(bucket, bucket + 10);
  balance[1] = max_loc - min_loc;

  for (unsigned int i = 0; i < 10; ++i) {
    bucket[i] = hT2.bucket_size(i);
  }
  min_loc = * std::min_element(bucket, bucket + 10);
  max_loc = * std::max_element(bucket, bucket + 10);
  balance[2] = max_loc - min_loc;
  for (unsigned int i = 0; i < 10; ++i) {

    bucket[i] = hT3.bucket_size(i);
  }
  min_loc = * std::min_element(bucket, bucket + 10);
  max_loc = * std::max_element(bucket, bucket + 10);
  balance[3] = max_loc - min_loc;
  for (unsigned int i = 0; i < 10; ++i) {
    bucket[i] = hT4.bucket_size(i);

  }
  min_loc = * std::min_element(bucket, bucket + 10);
  max_loc = * std::max_element(bucket, bucket + 10);
  balance[4] = max_loc - min_loc;
  for (unsigned int i = 0; i < 10; ++i) {

    bucket[i] = hT5.bucket_size(i);
  }
  min_loc = * std::min_element(bucket, bucket + 10);
  max_loc = * std::max_element(bucket, bucket + 10);
  balance[5] = max_loc - min_loc;
  for (unsigned int i = 0; i < 10; ++i) {
    bucket[i] = hT6.bucket_size(i);

  }
  min_loc = * std::min_element(bucket, bucket + 10);
  max_loc = * std::max_element(bucket, bucket + 10);
  balance[6] = max_loc - min_loc;

  for (unsigned int i = 0; i < 10; ++i) {

    bucket[i] = hT7.bucket_size(i);
  }
  min_loc = * std::min_element(bucket, bucket + 10);
  max_loc = * std::max_element(bucket, bucket + 10);
  balance[7] = max_loc - min_loc;

  unsigned int result = balance[1];
  unsigned int result_loc;

  result = * std::min_element(balance + 1, balance + 8);
  for (unsigned int pos = 1; pos <= 7; pos++) {
    if (result == balance[pos]) {
      result_loc = pos;
      break;
    }
  }
  return result_loc;
}

// ALREADY COMPLETED
size_t ItemCollection::size() {
  if ((hT1.size() != hT2.size()) || (hT1.size() != hT3.size()) || (hT1.size() != hT4.size()) || (hT1.size() != hT5.size()) || (hT1.size() != hT6.size()) || (hT1.size() != hT7.size()))
    throw std::length_error("Hash table sizes are not the same");

  return hT1.size();
}