//****************************************************************************** 
// File name:   Overnight.cpp
// Author:      Diane Crets
// Date:        5/3/2021
// Class:       CS 250
// Assignment:  06Polymorphism 
// Purpose:     Demonstrate Polymorphism
//******************************************************************************
#include "Overnight.h"
#include <iostream>

//******************************************************************************
// Constructor: Overnight
//
// Description: Calls the Parcel default constructor, sets mVolume to zero.
//
// Parameters: none
//
// Returned: none
//******************************************************************************
Overnight::Overnight() : Parcel(), mVolume(0)
{

}

//******************************************************************************
// Constructor: Overnight
//
// Description: Calls the Parcel constructor with trackingId, sets mVolume 
//              the given parameters.
//
// Parameters:  trackingId - tracking Id of a specific parcel
//              weight - the weight of the postcard
//              distance - the distance the postcard traveled
//              to - the email address the postcard is being sent to
//              from - the email address sending the postcard
//              volume - the volume of the overnight package
//
// Returned: none
//******************************************************************************
Overnight::Overnight(int trackingId, int weight, int distance,
  std::string to, std::string from, int volume) :
  Parcel(trackingId, weight, distance, to, from), mVolume(volume)
{

}

//******************************************************************************
// Function:    getDeliveryDay
//
// Description: Calculates and returns the amount of days it takes to deliver 
//              the overnight parcel
//
// Parameters:  none
//
// Returned:    int - the amount of days it takes to deliver the overnight 
//                    parcel
//******************************************************************************
int Overnight::getDeliveryDay() const {
  const int MAX_MILES_PER_DAY = 1000;
  const int MIN_DAYS = 1;
  const int MAX_DAYS = 2;
  int distance = getDistance();
  int deliveryDay = 0;
  if (distance <= MAX_MILES_PER_DAY || mbRush == true) {
    deliveryDay = MIN_DAYS;
  }
  else if (distance > MAX_MILES_PER_DAY) {
    deliveryDay = MAX_DAYS;
  }
  
  return deliveryDay;
}

//******************************************************************************
// Function:    getCost
//
// Description: Calculates and returns the total cost of the Overnight parcel
//
// Parameters:  none
//
// Returned:    double - the total cost
//******************************************************************************
double Overnight::getCost() const {
  const double OVERNIGHT_INSURANCE = 0.25;
  const double OVERNIGHT_RUSH = 0.75;
  const double OVERNIGHT_COST_1 = 20.00;
  const double OVERNIGHT_COST_2 = 12.00;
  double cost;
  double rushCost;
  double insuranceCost;
  if (mVolume > 100) {
    cost = OVERNIGHT_COST_1;
  }
  else {
    cost = OVERNIGHT_COST_2;
  }
  if (mbInsured == true) {
    insuranceCost = cost * OVERNIGHT_INSURANCE;
    cost += insuranceCost;
  }
  if (mbRush == true) {
    rushCost = cost * OVERNIGHT_RUSH;
    cost += rushCost;
  }
  return cost;
}

//******************************************************************************
// Function:    setInsured
//
// Description: returns the cost of the overnight insurance and sets mbInsured
//              to true
//
// Parameters:  bIsInsured - boolean for whether the parcel was insured or not
//
// Returned:    double - the overnight insurance cost
//******************************************************************************
double Overnight::setInsured(bool bIsInsured) {
  const double OVERNIGHT_INSURANCE = 0.25;
  double insurance = 0;
  double cost = getCost();
  if (bIsInsured == true) {
    insurance = cost * OVERNIGHT_INSURANCE;
    mbInsured = true;
  }
  return insurance;
}

//******************************************************************************
// Function:    setRush
//
// Description: returns the rush cost of a overnight parcel and sets bIsRushed
//              to true
//
// Parameters:  bIsRushed - boolean for whether the overnight parcel was rushed 
//                          or not
//
// Returned:    double - the overnight rush cost
//******************************************************************************
double Overnight::setRush(bool bIsRushed) {
  const double OVERNIGHT_RUSH = 0.75;
  double rushCost = 0;
  double cost = getCost();
  if (bIsRushed == true) {
    rushCost = cost * OVERNIGHT_RUSH;
    mbRush = true;
  }
  return rushCost;
  
}

//****************************************************************************
// Function:    read
//
// Description: Inputs the Overnight parcel to the stream
//
// Parameters:  rcIn - the stream to input to
//
// Returned:    returns true if able to read in information and false if not
//***************************************************************************
bool Overnight::read(istream& rcIn) {
  bool bRetVal = true;
  Parcel::read(rcIn);
  if (!(rcIn >> mVolume)) {
    bRetVal = false;
  }
  return bRetVal;
}

//******************************************************************************
// Function:    print
//
// Description: Print the Overnight parcel to the stream
//
// Parameters:  rcOut - the stream to print to
//
// Returned:    none
//******************************************************************************
void Overnight::print(ostream& rcOut) const {

  Parcel::print(rcOut);
  rcOut << "\t" << " OVERNIGHT!";

}