#include "CherProtoQE.hh"
#include <iostream>
#include <fstream>
CherProtoQE::CherProtoQE(std::string name){
  std::ifstream infile;
  infile.open(name);
  if(!infile.good()) exit(0);
  double a,b;
  while(!infile.eof()){
    infile>>a>>b;
  //
  //G4cout << a << " " << b << G4endl;
    photonEnergy.push_back(a*eV);
    quantumEfficiency.push_back(b);
    infile.ignore(100,'\n');
  }

}
CherProtoQE::~CherProtoQE(){}
G4double CherProtoQE::GetQE(G4double energy){
  G4int entries = photonEnergy.size();
  G4int i = 0, j = entries-1,k;
  if(energy<photonEnergy.front()){G4cout<<"energy is too low"<<energy<<"<"<<photonEnergy[0]<<G4endl;return 0;}
  else{
    if(energy>photonEnergy.back()){G4cout<<"energy is too high "<<">"<<photonEnergy.back()<<G4endl; return 0;}
    else{
      G4cout<<"energy is fine check"<<G4endl;
      while(i!=j){
        k = i+(j-i)/2;
        photonEnergy[k]>=energy ? j=k : i=k+1;
      }
    }

    G4cout<<"qe is "<< quantumEfficiency[i-1]+(quantumEfficiency[i]-quantumEfficiency[i-1])*(energy-photonEnergy[i-1])/(photonEnergy[i]-photonEnergy[i-1])<<G4endl;
    return quantumEfficiency[i-1]+(quantumEfficiency[i]-quantumEfficiency[i-1])*(energy-photonEnergy[i-1])/(photonEnergy[i]-photonEnergy[i-1]);
  }
}
