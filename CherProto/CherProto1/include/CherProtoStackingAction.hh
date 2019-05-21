//file CherProtoStackingAction.hh

#ifndef CherProtoStackingAction_h
#define CherProtoStackingAction_h 1

#include "globals.hh"
#include "G4UserStackingAction.hh"

class CherProtoStackingAction : public G4UserStackingAction
{
public:
  CherProtoStackingAction();
  ~CherProtoStackingAction();

public:
  virtual G4ClassificationOfNewTrack ClassifyNewTrack(const G4Track* aTrack);
  virtual void NewStage();
  virtual void PrepareNewEvent();

private:
  G4int fScintillationCounter;
  G4int fCerenkovCounter;
};
#endif
