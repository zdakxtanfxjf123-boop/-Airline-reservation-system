#include "Pricing.h"

double Ticket::calculateFare()
{
    return 0;
}

double Economy::calculateFare()
{
    return 1000;
}

double Business::calculateFare()
{
    return 2000;
}

double First::calculateFare()
{
    return 3000;
}