#ifndef OpNoviceSensitiveDetector_h
#define OpNoviceSensitiveDetector_h 1

#include "G4VSensitiveDetector.hh"
#include "OpNoviceHit.hh"
#include <vector>

class G4Step;
class G4HCofThisEvent;

class OpNoviceSensitiveDetector : public G4VSensitiveDetector
{
public:
  OpNoviceSensitiveDetector(G4String name);
  virtual ~OpNoviceSensitiveDetector();

  virtual void Initialize(G4HCofThisEvent* hitCollection);
  virtual G4bool ProcessHits(G4Step* step);
  virtual void EndOfEvent(G4HCofThisEvent* hitCollection);

private:
  OpNoviceHitsCollection* fHitsCollection;
};
#endif
  
