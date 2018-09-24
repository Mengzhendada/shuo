#ifndef OpNoviceEventAction_h
#define OpNoviceEventAction_h 1

#include "G4UserEventAction.hh"
#include "OpNoviceHit.hh"
#include "globals.hh"

class OpNoviceEventAction : public G4UserEventAction
{
public:
  OpNoviceEventAction();
  ~OpNoviceEventAction();
  void BeginOfEventAction(const G4Event* event);
  void EndOfEventAction(const G4Event* event);


private:
  OpNoviceHitsCollection* GetHitsCollection(G4int hcID, const G4Event* event) const;
     G4int SDHCID;
  G4int mirrorHCID;

};
  #endif
