//file CherProtoPrimaryGeneratorMessenger.hh

#ifndef CherProtoPrimaryGeneratorMessenger_h
#define CherProtoPrimaryGeneratorMessenger_h 1

#include "G4UImessenger.hh"
#include "globals.hh"

class CherProtoPrimaryGeneratorAction;
class G4UIdirectory;
class G4UIcmdWithADoubleAndUnit;

class CherProtoPrimaryGeneratorMessenger: public G4UImessenger
{
public:
  CherProtoPrimaryGeneratorMessenger(CherProtoPrimaryGeneratorAction* );
  ~CherProtoPrimaryGeneratorMessenger();

  void SetNewValue(G4UIcommand*, G4String);

private:
  CherProtoPrimaryGeneratorAction* fCherProtoAction;
  G4UIdirectory*                   fGunDir;
  G4UIcmdWithADoubleAndUnit*       fPolarCmd;
};
#endif
