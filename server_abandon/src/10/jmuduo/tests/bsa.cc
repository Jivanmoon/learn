#include <boost/static_assert.hpp>

class TimeStamp
{
private:
    int64_t microSecondsSinceEpoch_;
};

BOOST_STATIC_ASSERT(sizeof(TimeStamp) == sizeof(int64_t));
//BOOST_STATIC_ASSERT(sizeof(int) == sizeof(short));

int main() {
    return 0;
}