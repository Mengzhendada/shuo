#ifndef CherProtoQE_h
#define CherProtoQE_h 1
#include <vector>
#include <string>
#include "G4Types.hh"
#include "G4ios.hh"
#include "G4UnitsTable.hh"
#include "G4String.hh"
#include "G4SystemOfUnits.hh"
class CherProtoQE{
public:
  CherProtoQE(std::string name = "quantumEfficiency.txt");
  ~CherProtoQE();
  G4double GetQE(G4double energy);
  std::vector<double> photonEnergy;
  std::vector<double> quantumEfficiency;
  
};
#endif

