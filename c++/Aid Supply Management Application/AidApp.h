// The Aid Management Aplication
// AidApp.h
// Version 1.0
// Date 2016-04-10       
/////////////////////////////////////////////////////////////////
#ifndef SICT_AIDAPP_H__
#define SICT_AIDAPP_H__
#include <iostream>
#include <fstream>
#include "Product.h"
#include "AmaPerishable.h"
#include "general.h"
#include "sort.h"
using namespace std;

namespace sict{
  class AidApp{
  private:
  	char filename_[256];
  	Product* product_[MAX_NO_RECS];
  	fstream datafile_;
  	int noOfProducts_;
  	AidApp(const AidApp&) = delete;
  	void operator=(const AidApp&) = delete;
  	void pause()const;
  	int menu(const char* name, const char* name2);
  	void loadRecs();
  	void saveRecs();
  	void listProducts()const;
  	int searchProducts(const char* sku)const;
  	void addQty(const char* sku);
    void updQty(const char* sku);
  	void addProduct(bool isPerishable);
    void deleteProduct(const char* sku);
    void sortProducts();
  public:
  	AidApp(const char* filename);
  	int run();
  };
}
#endif