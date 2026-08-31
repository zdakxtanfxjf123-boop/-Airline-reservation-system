#pragma once
#include <string>

class Pricing
{
public:
    double getBasicFare(const std::string& c) const;
    double getFinalPrice(const std::string& c, double tax, double discount) const;
};