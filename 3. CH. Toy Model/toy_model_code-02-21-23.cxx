// Generating vector elements, filling vectors
// Fill vten0
for(int m = 0, m < NEntries0; m++){
    if(m < (NEntries0*0.5)){
        f0 = gRandom->Gaus(0,1) * gRandom->Rndm(); // Create random float value
        vten0.emplace_back(f0); // Emplace that float into vector
    } else {
        f0 = m;
        vten0.emplace_back(f0);
    }
}
// Fill vten1
for(int n = 0, n < NEntries1; n++){
    if(n < (NEntries1*0.5)){
        f1 = gRandom->Rndm() * gRandom->Gaus(0,1);
        vten1.emplace_back(f1);
    } else {
        f1 = 1;
        vten1.emplace_back(f1);
    }
}
// Fill vten2
for(int a = 0, a < NEntries2; a++){
    if(a < (NEntries2*0.5)){
        f2 = gRandom->Rndm() * gRandom->Gaus(0,1);
        vten2.emplace_back(f2);
    } else {
        f2 = 1;
        vten2.emplace_back(f2);
    }
}
// Fill vten3
for(int b = 0, b < NEntries3; b++){
  if(b < (NEntries3*0.5)){
        f3 = gRandom->Rndm() * gRandom->Gaus(0,1);
        vten3.emplace_back(f3);
    } else {
        f3 = 1;
        vten3.emplace_back(f3);
    }
}