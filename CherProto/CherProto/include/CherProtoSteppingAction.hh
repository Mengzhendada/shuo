//file CherProtoSteppingAction.hh

#ifndef CherProtoSteppingAction_h
#define CherProtoSteppingAction_h 1

#include "G4UserSteppingAction.hh"
#include "globals.hh"

class CherProtoSteppingAction : public G4UserSteppingAction
{
public:
  CherProtoSteppingAction();
  ~CherProtoSteppingAction();

  //method from the base class
  virtual void UserSteppingAction(const G4Step*);

private:
  G4int fScintillationCounter;
  G4int fCerenkovCounter;
  G4int fEventNumber;
};
#endif
