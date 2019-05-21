//file CherProtoHit.cc

#include "CherProtoHit.hh"
#include "G4UnitsTable.hh"
#include "G4VVisManager.hh"

G4ThreadLocal G4Allocator<CherProtoHit>* CherProtoHitAllocator;

CherProtoHit::CherProtoHit(){}
CherProtoHit::~CherProtoHit(){}
void CherProtoHit::Print(){
   G4cout<<"Edep:"<<std::setw(7)<<G4BestUnit(edep,"Energy")<<G4endl;
  }
void CherProtoHit::AddEdep(G4double e){
   edep +=e;
    G4cout<<"double e"<<e<<G4endl;
  }
