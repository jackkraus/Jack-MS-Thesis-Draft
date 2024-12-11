#include <iostream>
#include <memory>
#include <ostream>
#include <vector>

#include "TBranch.h"
#include "TCanvas.h"
#include "TFile.h"
#include "TH1.h"
#include "TRandom.h"
#include "TStyle.h"
#include "TTree.h"

void VectorTree() {
  /*
  Goal: separately load up four different branches
    with different vector sizes
      Size 1: 1 entry
      Size 2: 10 entries
      Size 3: 100 entries
      Size 4: 1000 entries
  */

  std::cout << "Initializing..." << std::endl;

  // CREATING FILE AND TREE
  std::cout << "creating file and tree..." << std::endl;

  std::unique_ptr<TFile> myFile =
      std::make_unique<TFile>("VectorTreeFile.root", "RECREATE");
  TTree *tree = new TTree("myTree", "myTree");

  tree->SetAutoFlush(0);
  tree->SetAutoSave(0);

  if (!myFile) {
    std::cout << "Error: file creation failed" << std::endl;
  }

  // INITIALIZING VARIABLES
  std::cout << "initializing variables and vector" << std::endl;

  const int NEvents = 1000000; // N = 1,000,000
  int NEntries0, NEntries1, NEntries2, NEntries3; 

  // Vectors
  std::vector<float> vten0; // 10^0 = 1 entry
  std::vector<float> vten1; // 10^1 = 10 entries
  std::vector<float> vten2; // 10^2 = 100 entries
  std::vector<float> vten3; // 10^3 = 1000 entries

  // Variables
  float f0;
  float f1;
  float f2;
  float f3;

  // INITIALIZING BRANCHES
  std::cout << "creating branches" << std::endl;

  tree->Branch("bOnes", &vten0);
  tree->Branch("bTens", &vten1);
  tree->Branch("bHundreds", &vten2);
  tree->Branch("bThousands", &vten3);

  int bSize = 4000;

  tree->SetBasketSize("*", bSize);

  // EVENTS LOOP
  std::cout << "generating events..." << std::endl;

  for (int j = 0; j < NEvents; j++) {

    // Randomizing number of entries
    int NEntries0 = 1;
    int NEntries1 = 10;
    int NEntries2 = 100;
    int NEntries3 = 1000;

    // clearing events
    vten0.clear();
    vten1.clear();
    vten2.clear();
    vten3.clear();

    // Generating vector elements, filling vectors

    // Generating vten0
    for (int m = 0; m < NEntries0; m++) {
      if (m < (NEntries0 / 2)) {
        f0 = gRandom->Gaus(0, 1) * gRandom->Rndm();
        vten0.emplace_back(f0);
      } else {
        f0 = m;
        vten0.emplace_back(f0);
      }
    }

    // Generating vten1
    for (int n = 0; n < NEntries1; n++) {
      if (n < NEntries1 / 2) {
        f1 = gRandom->Rndm() * gRandom->Gaus(0, 1);
        vten1.emplace_back(f1);
      } else {
        f1 = 1;
        vten1.emplace_back(f1);
      }
    }

    // Generating vten3
    for (int a = 0; a < NEntries3; a++) {
      if (a < NEntries3 / 2) {
        f3 = gRandom->Rndm() * gRandom->Gaus(0, 1);
        vten3.emplace_back(f3);
      } else {
        f3 = 1;
        vten3.emplace_back(f3);
      }
    }

    tree->Fill();
  }

  // Saving tree and file
  tree->Write();

  // Look in the tree
  tree->Scan();
  tree->Print();

  myFile->Save();
  myFile->Close();
}

int main() {
  VectorTree();
  return 0;
}