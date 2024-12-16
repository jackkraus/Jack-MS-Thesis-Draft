// C++ Standard Library
#include <iostream>
#include <memory>
#include <ostream>
#include <vector>

// Necessary ROOT Headers
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

    const int NEvents = 1e6; // N = 1,000,000
    // Set Number of Entries with 10^# of random floats
    int NEntries0 = 1;
    int NEntries1 = 10;
    int NEntries2 = 100;
    int NEntries3 = 1000;

    // vectors
    std::vector<float> vten0; // 10^0 = 1 entry
    std::vector<float> vten1; // 10^1 = 10 entries
    std::vector<float> vten2; // 10^2 = 100 entries
    std::vector<float> vten3; // 10^3 = 1000 entries

    // variables
    float f0;
    float f1;
    float f2;
    float f3;

    // Initializing branches
    std::cout << "creating branches" << std::endl;
    tree->Branch("branch_of_vectors_size_one", &vten0);
    tree->Branch("branch_of_vectors_size_ten", &vten1);
    tree->Branch("branch_of_vectors_size_hundred", &vten2);
    tree->Branch("branch_of_vectors_size_thousand", &vten3);

    int bSize = 4000;

    tree->SetBasketSize("*", bSize);

    // Events Loop
    std::cout << "generating events..." << std::endl;
    for (int j = 0; j < NEvents; j++) {
        // Clearing entries from previous iteration
        vten0.clear();
        vten1.clear();
        vten2.clear();
        vten3.clear();

        // Generating vector elements, filling vectors
        // Fill vten0
        for (int m = 0, m < NEntries0; m++) {
            f0 = gRandom->Rndm() * 10; // Create random float value
            vten0.emplace_back(f0);    // Emplace that float into vector
        }
        // Fill vten1
        for (int n = 0, n < NEntries1; n++) {
            f1 = gRandom->Rndm() * 10;
            vten1.emplace_back(f1);
        }
        // Fill vten2
        for (int a = 0, a < NEntries2; a++) {
            f2 = gRandom->Rndm() * 10;
            vten2.emplace_back(f2);
        }
        // Fill vten3
        for (int b = 0, b < NEntries3; b++) {
            f3 = gRandom->Rndm() * 10;
            vten3.emplace_back(f3);
        }
        tree->Fill(); // Fill our TTree with all the new branches
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