//****************************************************************************** 
// File name:   Letter.h
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

class Letter : public Parcel {
public:
  Letter();

  virtual int getDeliveryDay() const;
  virtual double getCost() const;

  virtual double setInsured(bool bIsInsured);
  virtual double setRush(bool bIsRushed);

};