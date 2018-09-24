//file CherProtoPhysicsList.hh

#ifndef CherProtoPhysicsList_h
#define CherProtoPhysicsList_h 1

#include "globals.hh"
#include "G4VUserPhysicsList.hh"

class CherProtoPhysicsListMessenger;

class G4Cerenkov;
class G4Scintillation;
class G4OpAbsorption;
//class G4OpRayleigh;
//class G4OpMieHG;
class G4OpBoundaryProcess;

class CherProtoPhysicsList : public G4VUserPhysicsList
{
public:
  CherProtoPhysicsList();
  ~CherProtoPhysicsList();

public:
  virtual void ConstructParticle();
  virtual void ConstructProcess();

  virtual void SetCuts();

  //these methods Construct physics process
  void ConstructDecay();
  void ConstructEM();
  void ConstructOp();

  //for the Messenger
  void SetVerbose(G4int);
  void SetNbOfPhotonCerenkov(G4int);

private:
  
  CherProtoPhysicsListMessenger* fMessenger;

  static G4ThreadLocal G4int fVerboseLevel;
  static G4ThreadLocal G4int fMaxNumPhotonStep;

  static G4ThreadLocal G4Cerenkov* fCerenkovProcess;
  static G4ThreadLocal G4Cerenkov* fScintillationProcess;
  static G4ThreadLocal G4OpAbsorption* fAbsorptionProcess;
  //static G4ThreadLocal G4OpRayleigh* fRayleighScatteringProcess;
  //static G4ThreadLocal G4OpMieHG* fMieHGScatteringProcess;
  static G4ThreadLocal G4OpBoundaryProcess* fBoundaryProcess;
};
#endif
