//############################################################################
//Parcel.h 
//############################################################################
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


//############################################################################
//Letter.h 
//############################################################################
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


//############################################################################
//Postcard.h 
//############################################################################
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
 

//############################################################################
//Overnight.h 
//############################################################################
//****************************************************************************** 
// File name:   Overnight.h
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

class Overnight : public Parcel {
public:
  Overnight();
  Overnight(int trackingId, int weight, int distance,
    string to, string from, int volume);

  virtual int getDeliveryDay() const;
  virtual double getCost() const;

  virtual double setInsured(bool bIsInsured);
  virtual double setRush(bool bIsRushed);

  virtual bool read(istream& rcIn);
  virtual void print(ostream& rcOut) const;

private:
  int mVolume;
};     



//############################################################################
//Parcel.cpp 
//############################################################################
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


//############################################################################
//Letter.cpp 
//############################################################################
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


//############################################################################
//Postcard.cpp 
//############################################################################
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
  
 
//############################################################################
//Overnight.cpp 
//############################################################################
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
   


//############################################################################
//Source.cpp 
//############################################################################
//****************************************************************************** 
// File name:   Source.cpp
// Author:      Diane Crets
// Date:        5/3/2021
// Class:       CS 250
// Assignment:  Polymorphism
// Purpose:     Demonstrate Polymorphism
//******************************************************************************

#include "Parcel.h"
#include "Letter.h"
#include "Postcard.h"
#include "Overnight.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

void openFileForRead(ifstream& cInputFile, string fileName);
int displayMenu(int choice);
int readFile(ifstream& cInputFile, Parcel* pacArray[], int numParcels,
             const int MAX_PARCELS);
void printAll(Parcel* pacArray[], int numParcels);
int getTrackingId(int trackingId);
void addInsurance(Parcel* pacArray[], int numParcels, int trackingId, 
                  bool bInsured);
void addRush(Parcel* pacArray[], int trackingId, bool bRushed);
void deliver(Parcel* pacArray[], int trackingId);

//******************************************************************************
// Function:    main
//
// Description: Demonstrate Polymorphism
//
// Parameters:  none
//
// Returned:    exit status
//******************************************************************************

int main() {
  const int MAX_PARCELS = 25;
  const int PRICE_OUTPUT = 2;
  const int MIN_TID = 0;
  const int CHOICE_1 = 1;
  const int CHOICE_2 = 2;
  const int CHOICE_3 = 3;
  const int CHOICE_4 = 4;
  const int CHOICE_5 = 5;
  string fileName = "parcels.txt";
  bool bInsured;
  bool bRushed;
  int choice = 0;
  int trackingId = 0;
  
  ifstream cInputFile;

  Parcel* pacParcel[MAX_PARCELS] = { nullptr };
  int numParcels = 0;

  cout << "Mail Simulator!" << endl << endl;
  openFileForRead(cInputFile, fileName);
  
  cout << fixed << setprecision(PRICE_OUTPUT);

  do {
    numParcels = readFile(cInputFile, pacParcel, numParcels, MAX_PARCELS);
    choice = displayMenu(choice);
    cout << endl;
    if (CHOICE_1 == choice) {
      printAll(pacParcel, numParcels);
      cout << endl;
    }
    else if (CHOICE_2 == choice || CHOICE_3 == choice || CHOICE_4 == choice) {
      trackingId = getTrackingId(trackingId);
      if (trackingId == MIN_TID || trackingId > numParcels) {
        cout << endl;
        continue;
      }
      if (CHOICE_2 == choice) {
        bInsured = true;
        addInsurance(pacParcel, numParcels, trackingId, bInsured);
        cout << endl;
      }
      else if (CHOICE_3 == choice) {
        bRushed = true;
        addRush(pacParcel, trackingId, bRushed);
        cout << endl;
      }
      else if (CHOICE_4 == choice) {
        deliver(pacParcel, trackingId);
        cout << endl;
      }
    }
  } while (CHOICE_5 != choice);
  
  if (CHOICE_5 == choice) {
    delete pacParcel[numParcels];
    return EXIT_SUCCESS;
  }

  cout << "Reached the end!\n";
  return EXIT_SUCCESS;
}

//***************************************************************************
// Function:    openFileForRead
//
// Description: Opens a text file to read and outputs an error if file can't 
// open. 
//
// Parameters:  cInputFile - text file being opened 
//              fileName - name of file being opened
//
// Returned:    None
//***************************************************************************
void openFileForRead(ifstream& cInputFile, string fileName) {
  cInputFile.open("parcels.txt");
  if (!cInputFile.is_open()) {
    cout << "Could not open file" << endl;
    exit(EXIT_SUCCESS);
  }
}

//***************************************************************************
// Function:    displayMenu
//
// Description: Displays menu of options for user to pick from 
//
// Parameters:  choice - the option choice that the user picks
//
// Returned:    The choice that the user inputted from the menu of options
//***************************************************************************
int displayMenu(int choice) {
  const int MIN_TID = 0;
  const int CHOICE_1 = 1;
  const int CHOICE_2 = 2;
  const int CHOICE_3 = 3;
  const int CHOICE_4 = 4;
  const int CHOICE_5 = 5;

  cout << CHOICE_1 << ". " << "Print All" << endl << CHOICE_2 << ". "
    << "Add Insurance" << endl << CHOICE_3 << ". " << "Add Rush" << endl
    << CHOICE_4 << ". " << "Deliver" << endl << CHOICE_5 << ". " << "Quit"
    << endl << endl;

  do {
    cout << "Choice> ";
    cin >> choice;
  } while (CHOICE_1 != choice && CHOICE_2 != choice && CHOICE_3 != choice
    && CHOICE_4 != choice && CHOICE_5 != choice);
  
  return choice;
}

//***************************************************************************
// Function:    readFile
//
// Description: Reads text file of parcels 
//
// Parameters:  cInputFile - text file being read 
//              pacParcel - pointer of arrays to class Parcel
//              numParcels - number of parcels in text file
//              MAX_PARCELS - max amount of parcels that can be read in text 
//                            file
//
// Returned:    The number of parcels in the file
//***************************************************************************
int readFile(ifstream& cInputFile, Parcel* pacParcel[], int numParcels,
  const int MAX_PARCELS) {
  char type;
  while (cInputFile >> type) {
    switch (type) {
    case 'P': pacParcel[numParcels] = new Postcard;
      pacParcel[numParcels]->read(cInputFile);
      numParcels++;
      break;
    case 'L': pacParcel[numParcels] = new Letter;
      pacParcel[numParcels]->read(cInputFile);
      numParcels++;
      break;
    case 'O': pacParcel[numParcels] = new Overnight;
      pacParcel[numParcels]->read(cInputFile);
      numParcels++;
      break;
    default: break;
    }
  }
  if (numParcels > MAX_PARCELS) {
    cout << "Invalid File" << endl;
    exit(EXIT_SUCCESS);
  }
  return numParcels;
}

//***************************************************************************
// Function:    printAll
//
// Description: Prints all the the parcels in the text file 
//
// Parameters:  pacParcel - pointer of arrays to class Parcel
//              numParcels - number of parcels in text file
//
// Returned:    None
//***************************************************************************
void printAll(Parcel* pacParcel[], int numParcels) {
  for (int i = 0; i < numParcels; i++) {
    if (pacParcel[i] != nullptr) {
      pacParcel[i]->print(cout);
      cout << endl;
    }
  }
}

//***************************************************************************
// Function:    getTrackingId
//
// Description: Gets the tracking Id from the user 
//
// Parameters:  trackingId - the tracking Id of a certain parcel
//
// Returned:    The trackingId
//***************************************************************************
int getTrackingId(int trackingId) {
  cout << "TID> ";
  cin >> trackingId;
  return trackingId;
}

//***************************************************************************
// Function:    addInsurance
//
// Description: Adds inurance to a specific parcel 
//
// Parameters:  pacParcel - pointer of arrays to class Parcel
//              numParcels - number of parcels in text file
//              trackingId - the tracking Id of a certain parcel
//              bInsured - boolean for whether the parcel was insured or not
//
// Returned:    None
//***************************************************************************
void addInsurance(Parcel* pacParcel[], int numParcels, int trackingId, 
                  bool bInsured) {
  const int GET_INDEX = 1;
  int index = trackingId - GET_INDEX;
  cout << "Added Insurance for $" << pacParcel[index]->setInsured(bInsured)
       << endl;
  pacParcel[index]->print(cout);
  cout << endl;
}

//***************************************************************************
// Function:    addRush
//
// Description: Adds rush price and rushs delivery of specific parcel 
//
// Parameters:  pacParcel - pointer of arrays to class Parcel
//              trackingId - the tracking Id of a certain parcel
//              bRushed - boolean for whether the parcel was rushed or not
//
// Returned:    None
//***************************************************************************
void addRush(Parcel* pacParcel[], int trackingId, bool bRushed) {
  const int GET_INDEX = 1;
  int index = trackingId - GET_INDEX;
  cout << "Added Rush for $" << pacParcel[index]->setRush(bRushed) << endl;
  pacParcel[index]->print(cout);
  cout << endl;
}

//***************************************************************************
// Function:    deliver
//
// Description: Gets delivery day of specific parcel and prints out cost to 
//              deliver that parcel 
//
// Parameters:  pacParcel - pointer of arrays to class parcel
//              trackingId - the tracking Id of a certain parcel
//
// Returned:    None
//***************************************************************************
void deliver(Parcel* pacParcel[], int trackingId) {
  const int GET_INDEX = 1;
  int deliveryDay;

  int index = trackingId - GET_INDEX;

  cout << "Delivered!" << endl;
  deliveryDay = pacParcel[index]->getDeliveryDay();
  cout << deliveryDay;

  cout << " Day, $" << pacParcel[index]->getCost() << endl;
  pacParcel[index]->print(cout);

  delete pacParcel[index];
  pacParcel[index] = { nullptr };
  cout << endl;
}   