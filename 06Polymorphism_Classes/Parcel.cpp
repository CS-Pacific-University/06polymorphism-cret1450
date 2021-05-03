//****************************************************************************** 
// File name:   Parcel.cpp
// Author:      Diane Crets
// Date:        5/3/2021
// Class:       CS 250
// Assignment:  06Polymorphism 
// Purpose:     Demonstrate Polymorphism
//******************************************************************************
#include "Parcel.h"
#include <iostream>
#include <string>

//****************************************************************************
// Constructor: Parcel
//
// Description: Initialize the parcel data with the various parameters
//
// Parameters:  trackingId - tracking Id of a specific parcel
//              weight - the weight of the parcel
//              distance - the distance the parcel traveled
//              to - the email address the parcel is being sent to
//              from - the email address sending the parcel
//
// Returned:    none
//***************************************************************************
Parcel::Parcel(int trackingId, int weight, int distance,
  std::string to, std::string from) {
  mTrackingId = trackingId;
  mWeight = weight;
  mDistance = distance;
  mTo = to;
  mFrom = from;
}

//****************************************************************************
// Function:    getTrackingID
//
// Description: Retrieve the tracking Id of the Parcel
//
// Parameters:  none
//
// Returned:    the tracking Id of the Parcel
//***************************************************************************
int Parcel::getTrackingID() const {
  return mTrackingId;
}

//****************************************************************************
// Function:    getWeight
//
// Description: Retrieve the weight of the Parcel
//
// Parameters:  none
//
// Returned:    weight of the Parcel
//***************************************************************************
int Parcel::getWeight() const {
  return mWeight;
}

//****************************************************************************
// Function:    getDistance
//
// Description: Retrieve the distance the parcel traveled
//
// Parameters:  none
//
// Returned:    the distance the parcel traveled
//***************************************************************************
int Parcel::getDistance() const {
  return mDistance;
}

//****************************************************************************
// Function:    getInsured
//
// Description: Retrieve the cost of insurance for the Parcel
//
// Parameters:  none
//
// Returned:    cost of insurance for the Parcel
//***************************************************************************
bool Parcel::getInsured() const {
  bool mbInsured = true;
  return mbInsured;
}

//****************************************************************************
// Function:    getRush
//
// Description: Retrieve the cost of rushing a Parcel
//
// Parameters:  none
//
// Returned:    cost of rushing a Parcel
//***************************************************************************
bool Parcel::getRush() const {
  bool mbRush = true;
  return mbRush;
}

//****************************************************************************
// Function:    setCost
//
// Description: Sets the cost of the Parcel
//
// Parameters:  cost - cost of the Parcel
//
// Returned:    none
//***************************************************************************
void Parcel::setCost(double cost) {
  mCost = cost;
}

//****************************************************************************
// Function:    read
//
// Description: Inputs the Parcel to the stream
//
// Parameters:  rcIn - the stream to input to
//
// Returned:    returns true if able to read in information and false if not
//***************************************************************************
bool Parcel::read(istream& rcIn) {
  bool bRetVal = true;
  if (!(rcIn >> mTrackingId >> mTo >> mFrom >> mWeight >> mDistance)) {
    bRetVal = false;
  }
  return bRetVal;
}

//****************************************************************************
// Function:    print
//
// Description: Output the Parcel to the stream
//
// Parameters:  rcOut - the stream to output to
//
// Returned:    none
//***************************************************************************
void Parcel::print(ostream& rcOut) const {
  rcOut << "TID: " << mTrackingId << "\t" << "From: " << mFrom << "\t" 
        << "To: " << mTo;

  if (mbInsured == true) {
    rcOut << "\t" << " INSURED";
  }
  if (mbRush == true) {
    rcOut << "\t" << " RUSH";
  }
}

//****************************************************************************
// Function:    getCost
//
// Description: Retrieve the cost of the Parcel
//
// Parameters:  none
//
// Returned:    cost of the Parcel
//***************************************************************************
double Parcel::getCost() const {
  return mCost;
}

//****************************************************************************
// Function:    getDeliveryDay
//
// Description: Retrieve the delivery day of the parcel
//
// Parameters:  none
//
// Returned:    The delivery day of the Parcel
//***************************************************************************
int Parcel::getDeliveryDay() const {
  const int MIN_DELIVERY_TIME = 1; //1 day
  return MIN_DELIVERY_TIME;
}

