//****************************************************************************** 
// File name:   Letter.cpp
// Author:      Diane Crets
// Date:        5/3/2021
// Class:       CS 250
// Assignment:  06Polymorphism 
// Purpose:     Demonstrate Polymorphism
//******************************************************************************
#include "Letter.h"
#include <iostream>

//******************************************************************************
// Constructor: Letter
//
// Description: Calls the Parcel default constructor
//
// Parameters:  none
//
// Returned:    none
//******************************************************************************
Letter::Letter() : Parcel()
{

}

//******************************************************************************
// Function:    getDeliveryDay
//
// Description: Calculates and returns the amount of days it takes to deliver 
//              the letter
//
// Parameters:  none
//
// Returned:    int - the amount of days it takes to deliver the letter
//******************************************************************************
int Letter::getDeliveryDay() const {
  const int MAX_MILES_PER_DAY = 100;
  const int MIN_DAYS = 1;
  const int RUSH = 1;
  const int ADD_DAY = 1;
  int distance = getDistance();
  int deliveryDay = 0;
  if (distance < MAX_MILES_PER_DAY) {
    deliveryDay = MIN_DAYS;
  }
  else if (distance % MAX_MILES_PER_DAY == 0){
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
// Description: Calculates and returns the total cost of the Letter
//
// Parameters:  none
//
// Returned:    double - the total cost
//******************************************************************************
double Letter::getCost() const {
  const double LETTER_INSURANCE = 0.45;
  const double LETTER_RUSH = 0.10;
  int weight = getWeight();
  double cost = LETTER_INSURANCE * weight;
  double rushCost = cost * LETTER_RUSH;
  if (mbInsured == true) {
    cost += LETTER_INSURANCE;
  }
  if (mbRush == true) {
    cost += rushCost;
  }
  return cost;
}

//******************************************************************************
// Function:    setInsured
//
// Description: returns the cost of the letter insurance and sets mbInsured to 
//              true
//
// Parameters:  bIsInsured - boolean for whether the parcel was insured or not
//
// Returned:    double - the letter insurance cost
//******************************************************************************
double Letter::setInsured(bool bIsInsured) {
  const double LETTER_INSURANCE = 0.45;
  if (bIsInsured == true) {
    mbInsured = true;
  }
    return LETTER_INSURANCE;
}

//******************************************************************************
// Function:    setRush
//
// Description: returns the rush cost of a letter and sets bIsRushed
//              to true
//
// Parameters:  bIsRushed - boolean for whether the letter was rushed or not
//
// Returned:    double - the rush cost of a letter
//******************************************************************************
double Letter::setRush(bool bIsRushed) {
  const double LETTER_RUSH = 0.10;
  double rushCost = 0;
  double cost = getCost();
  if (bIsRushed == true) {
    rushCost = cost * LETTER_RUSH;
    mbRush = true;
  }
  return rushCost;
}