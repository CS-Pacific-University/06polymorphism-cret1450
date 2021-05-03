//****************************************************************************** 
// File name:   Postcard.h
// Author:      Diane Crets
// Date:        5/3/2021
// Class:       CS 250
// Assignment:  06Polymorphism 
// Purpose:     Demonstrate Polymorphism
//******************************************************************************
#pragma once

#include "Parcel.h"
#include <string>
#include <iostream>

using namespace std;

class Postcard : public Parcel {
public:
  Postcard();
  Postcard(int trackingId, int weight, int distance,
    string to, string from, string message);

  virtual int getDeliveryDay() const;
  virtual double getCost() const;

  virtual double setInsured(bool bIsInsured);
  virtual double setRush(bool bIsRushed);

  virtual bool read(istream& rcIn);
  virtual void print(ostream& rcOut) const;

private:
  string mMessage;
};