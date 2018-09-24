//file CherProtoRunAction.hh

#ifndef CherProtoRunAction_h
#define CherProtoRunAction_h 1

#include "globals.hh"
#include "G4UserRunAction.hh"

class G4Timer;
class G4Run;

class CherProtoRunAction : public G4UserRunAction
{
public:
  CherProtoRunAction();
  ~CherProtoRunAction();
public:
  virtual void BeginOfRunAction(const G4Run* aRun);
  virtual void EndOfRunAction(const G4Run* aRun);

private:
  G4Timer* fTimer;
};
#endif
