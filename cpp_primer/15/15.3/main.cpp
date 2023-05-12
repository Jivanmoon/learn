#include "Quote.h"

int main() {
    Quote q("aaa", 12.5);
    Bulk_quote bq("bbb", 14.5, 5, 0.3);
    print_total(std::cout, q, 10);
    print_total(std::cout, bq, 10);
}