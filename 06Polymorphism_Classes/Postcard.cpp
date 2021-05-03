//****************************************************************************** 
// File name:   Postcard.cpp
// Author:      Diane Crets
// Date:        5/3/2021
// Class:       CS 250
// Assignment:  06Polymorphism 
// Purpose:     Demonstrate Polymorphism
//******************************************************************************
#include "Postcard.h"
#include <iostream>

//******************************************************************************
// Constructor: Postcard
//
// Description: Calls the Parcel default constructor, sets mMessage to a space.
//
// Parameters:  none
//
// Returned:    none
//******************************************************************************
Postcard::Postcard() : Parcel(), mMessage(" ") 
{

}

//******************************************************************************
// Constructor: Postcard
//
// Description: Calls the Parcel constructor with trackingId, sets mMessage 
//              the given parameters.
//
// Parameters:  trackingId - tracking Id of a specific parcel
//              weight - the weight of the postcard
//              distance - the distance the postcard traveled
//              to - the email address the postcard is being sent to
//              from - the email address sending the postcard
//              message - the message to the person recieving the postcard
//
// Returned: none
//******************************************************************************
Postcard::Postcard(int trackingId, int weight, int distance,
          std::string to, std::string from, std::string message) :
          Parcel(trackingId, weight, distance, to, from), mMessage(message)
{

}

//******************************************************************************
// Function:    getDeliveryDay
//
// Description: Calculates and returns the amount of days it takes to deliver 
//              the postcard
//
// Parameters:  none
//
// Returned:    int - the amount of days it takes to deliver the postcard
//******************************************************************************
int Postcard::getDeliveryDay() const {
  const int MAX_MILES_PER_DAY = 10;
  const int MIN_DAYS = 1;
  const int RUSH = 2;
  const int ADD_DAY = 1;
  int distance = getDistance();
  int deliveryDay = 0;
  if (distance < MAX_MILES_PER_DAY) {
    deliveryDay = MIN_DAYS;
  }
  else if (distance % MAX_MILES_PER_DAY == 0) {
    deliveryDay = distance / MAX_MILES_PER_DAY;
  }
  else {
    deliveryDay = distance / MAX_MILES_PER_DAY;
    deliveryDay += ADD_DAY;
  }
  if (mbRush == true && deliveryDay > RUSH) {
    deliveryDay -= RUSH;
  }
  else if (mbRush == true && deliveryDay <= RUSH) {
    deliveryDay = MIN_DAYS;
  }
  return deliveryDay;
}

//******************************************************************************
// Function:    getCost
//
// Description: Calculates and returns the total cost of the postcard
//
// Parameters:  none
//
// Returned:    double - the total cost
//******************************************************************************
double Postcard::getCost() const {
  const double POSTCARD_INSURANCE = 0.15;
  const double POSTCARD_RUSH = 0.25;
  double cost = 0.15;
  if (mbInsured == true) {
    cost += POSTCARD_INSURANCE;
  }
  if (mbRush == true) {
    cost += POSTCARD_RUSH;
  }
  return cost;
}

//******************************************************************************
// Function:    setInsured
//
// Description: returns the cost of the postcard insurance and sets mbInsured to 
//              true
//
// Parameters:  bIsInsured - boolean for whether the parcel was insured or not
//
// Returned:    double - the postcard insurance cost
//******************************************************************************
double Postcard::setInsured(bool bIsInsured) {
  const double POSTCARD_INSURANCE = 0.15;
  if (bIsInsured == true) {
    mbInsured = true;
  }
  return POSTCARD_INSURANCE;
}

//******************************************************************************
// Function:    setRush
//
// Description: returns the rush cost of a postcard and sets bIsRushed
//              to true
//
// Parameters:  bIsRushed - boolean for whether the postcard was rushed or not
//
// Returned:    double - the rush cost for a postcard
//******************************************************************************
double Postcard::setRush(bool bIsRushed) {
  const double POSTCARD_RUSH = 0.25;
  if (bIsRushed == true) {
    mbRush = true;
  }
  return POSTCARD_RUSH;
}

//****************************************************************************
// Function:    read
//
// Description: Inputs the Postcard to the stream
//
// Parameters:  rcIn - the stream to input to
//
// Returned:    returns true if able to read in information and false if not
//***************************************************************************
bool Postcard::read(istream& rcIn) {
  bool bRetVal = true;
  Parcel::read(rcIn);
  if (!(rcIn >> mMessage)) {
    bRetVal = false;
  }
  return bRetVal;
}

//******************************************************************************
// Function:    print
//
// Description: Print the Postcard to the stream
//
// Parameters:  rcOut - the stream to print to
//
// Returned:    none
//******************************************************************************
void Postcard::print(ostream& rcOut) const {

  Parcel::print(rcOut);
  rcOut << "\t" << mMessage;

}