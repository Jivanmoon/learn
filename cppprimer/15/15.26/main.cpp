#include <iostream>
#include <string>
#include "Quote.h"
int main()
{
	std::cout << "---------测试1------------" << std::endl;
    Bulk_quote bq1;
	std::cout << "---------测试2------------" << std::endl;
    Bulk_quote bq2("ss", 2.05, 12, 0.3);
	std::cout << "---------测试3------------" << std::endl;
    bq2 = std::move(bq2);
    return 0;
}
