
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <fstream>
#include "Quote.h"
#include "Basket.h"
int main()
{
	std::cout << "-------------1-----------" << std::endl;
    Basket basket;
	std::cout << "-------------2-----------" << std::endl;
    for (unsigned i = 0; i != 10; ++i)
        basket.add_item(Bulk_quote("CNN", 15, 5, 0.3));
	std::cout << "-------------3-----------" << std::endl;
    for (unsigned i = 0; i != 20; ++i)
        basket.add_item(Bulk_quote("Test", 18, 5, 0.4));
	std::cout << "-------------4-----------" << std::endl;
	for (unsigned i = 0; i != 2; ++i)
        basket.add_item(Quote("Train", 20));
	std::cout << "-------------5-----------" << std::endl;
    std::ofstream log("log.txt", std::ios_base::app|std::ios_base::out);
	std::cout << "-------------6-----------" << std::endl;
    basket.total_receipt(log);
	std::cout << "-------------7-----------" << std::endl;
    return 0;
}
