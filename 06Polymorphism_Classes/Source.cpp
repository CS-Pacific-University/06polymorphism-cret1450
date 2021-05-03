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