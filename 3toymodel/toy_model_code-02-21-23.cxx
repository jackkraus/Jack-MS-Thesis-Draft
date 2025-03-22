
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
