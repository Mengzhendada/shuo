#ifndef OpNoviceHit_h
#define OpNoviceHit_h 1

#include "G4VHit.hh"
#include "G4THitsCollection.hh"
#include "G4Allocator.hh"
#include "G4ThreeVector.hh"
#include "G4Threading.hh"

class OpNoviceHit : public G4VHit
{
public:
  OpNoviceHit();
  ~OpNoviceHit();
}
  using OpNoviceHitsCollection = G4THitsCollection<OpNoviceHit>;
extern G4ThreadLocal G4Allocator<OpNoviceHit>* OpNoviceHitAllocator;
#endif
