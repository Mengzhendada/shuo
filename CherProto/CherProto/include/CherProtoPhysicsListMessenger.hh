//file CherProtoPhysicsListMessenger

#ifndef CherProtoPhysicsListMessenger_h
#define CherProtoPhysicsListMessenger_h 1

#include "globals.hh"
#include "G4UImessenger.hh"

class CherProtoPhysicsList;
class G4UIdirectory;
class G4UIcmdWithAnInteger;

class CherProtoPhysicsListMessenger: public G4UImessenger
{
public:
  CherProtoPhysicsListMessenger(CherProtoPhysicsList* );
  ~CherProtoPhysicsListMessenger();

  virtual void SetNewValue(G4UIcommand*, G4String);
private:
  CherProtoPhysicsList* fPhysicsList;
  G4UIdirectory*        fCherProtoDir;
  G4UIdirectory*        fPhysDir;
  G4UIcmdWithAnInteger* fVerboseCmd;
  G4UIcmdWithAnInteger* fCerenkovCmd;
};
#endif
