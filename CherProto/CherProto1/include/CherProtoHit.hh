//file CherProtoHit.hh

#ifndef CherProtoHit_h
#define CherProtoHit_h 1

#include "G4VHit.hh"
#include "G4Allocator.hh"
#include "G4THitsCollection.hh"
#include "G4UnitsTable.hh"
#include <iomanip>

class CherProtoHit: public G4VHit
{
public:
  CherProtoHit();
  ~CherProtoHit();

  void Print();
  // {
  //   G4cout<<"Edep:"<<std::setw(7)<<G4BestUnit(edep,"Energy")<<G4endl;
  // }
  void AddEdep(const double e);
  // {
  //   edep +=e;
  //   G4cout<<"double e"<<e<<G4endl;
  // }
  G4double GetEdep() const {return edep;}
  //void Count() {Hitscount++;}
  //G4double GetCounting() const {return Hitscount;}

private:
  G4double edep;
  //G4int Hitscount = 0;
};
typedef G4THitsCollection<CherProtoHit> CherProtoHitCollection;

#endif
  
