#ifndef OpNoviceHit_h
#define OpNoviceHit_h

#include "G4VHit.hh"
#include "G4Allocator.hh"
#include "G4THitsCollection.hh"
//#include "OpNoviceSD.hh"
#include "G4UnitsTable.hh"
#include <iomanip>
class OpNoviceHit: public G4VHit{
public:
  OpNoviceHit(){}
  //OpNoviceHit(const OpNoviceHit&);
  ~OpNoviceHit(){}
  
  // void* operator new(size_t);
  // void operator delete(void* );
    
  void Print(){
    G4cout
      <<"Edep:"
      <<std::setw(7) << G4BestUnit(edep,"Energy")<<G4endl;
  }
  void AddEdep(const double e){edep +=e;
    G4cout <<"double e"<<e<< G4endl;}
  G4double GetEdep() const {return edep;}
  void Count() {Hitscount++;}
  G4double GetCounting()const {return Hitscount;}
 
private:
  G4double edep;
  G4int Hitscount=0;
  
};
typedef G4THitsCollection<OpNoviceHit> OpNoviceHitsCollection;
// extern G4Allocator<OpNoviceHit>OpNoviceHitAllocator;
// inline void*OpNoviceHit::operator new(size_t)
// {
//     void *aHit;
//     aHit = (void*)OpNoviceHitAllocator.MallocSingle();
//     return aHit;}
// inline void OpNoviceHit::operator delete(void* aHit)
// {
//   OpNoviceHitAllocator.FreeSingle((OpNoviceHit*) aHit);
// }
#endif
