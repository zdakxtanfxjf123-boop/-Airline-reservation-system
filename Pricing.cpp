#include "Pricing.h"

using namespace std;

double Pricing::getBasicFare(const string& c) const
{
    if (c == "Economy") return 1000;
    if (c == "Business") return 2000;
    if (c == "First") return 3000;
    return 0;
}

double Pricing::getFinalPrice(const string& c, double tax, double discount) const
{
    return getBasicFare(c) + tax - discount;
}