// Initializing Variables
std::cout << "initializing variables and vector" << std::endl;

const Int_t NEvents = 1000;
std::vector<float> vten0, vten1, vten2, vten3; // vectors
float f0, f1, f2, f3; // Temporary float placeholders

// Set Number of Entries with 10^# of random floats
int NEntries0 = 1;
int NEntries1 = 10;
int NEntries2 = 100;
int NEntries3 = 1000;

// ROOT uses branches
std::cout << "creating branches" <<  std::endl;

// Each branch will have either 1, 10, 100, or 1000 vectors 
//      of random floats values
tree->Branch("bOnes", &vten0);
tree->Branch("bTens", &vten1);
tree->Branch("bHundreds", &vten2);
tree->Branch("bThousands", &vten3);

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
    for(int m = 0, m < NEntries0; m++){
        f0 = gRandom->Rndm()*10; // Create random float value
        vten0.emplace_back(f0); // Emplace that float into vector
    }
    // Fill vten1
    for(int n = 0, n < NEntries1; n++){
        f1 = gRandom->Rndm()*10;
        vten1.emplace_back(f1);
    }
    // Fill vten2
    for(int a = 0, a < NEntries2; a++){
        f2 = gRandom->Rndm()*10;
        vten2.emplace_back(f2);
    }
    // Fill vten3
    for(int b = 0, b < NEntries3; b++){
        f3 = gRandom->Rndm()*10;
        vten3.emplace_back(f3);
    }
    tree->Fill(); // Fill our TTree with all the new branches
}