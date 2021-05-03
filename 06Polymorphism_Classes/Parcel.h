//****************************************************************************** 
// File name:   Parcel.h
// Author:      Diane Crets
// Date:        5/3/2021
// Class:       CS 250
// Assignment:  06Polymorphism 
// Purpose:     Demonstrate Polymorphism
//******************************************************************************
#pragma once

#include <iostream>

using namespace std;

class Parcel {
public:
  Parcel(int trackingId = 0, int weight = 0, int distance = 0, 
         string to = " ", string from = " ");

  int getTrackingID() const;
  int getWeight() const;
  int getDistance() const;
  bool getInsured() const;
  bool getRush() const;
  

  void setCost(double cost);
  virtual double setInsured(bool bIsInsured) = 0;
  virtual double setRush(bool bIsRushed) = 0;

  virtual bool read(istream& rcIn);
  virtual void print(ostream& rcOut) const;

  virtual double getCost() const = 0;
  virtual int getDeliveryDay() const;

protected:
  bool mbInsured, mbRush, mbDelivered;

private:
  int mTrackingId, mWeight, mDistance;
  double mCost;
  string mTo, mFrom;

};
