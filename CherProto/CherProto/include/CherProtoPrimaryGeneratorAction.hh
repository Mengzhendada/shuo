//file CherProtoPrimaryGeneratorAction.hh

#ifndef CherProtoPrimaryGeneratorAction_h
#define CherProtoPrimaryGeneratorAction_h 1

#include "G4VUserPrimaryGeneratorAction.hh"
#include "globals.hh"

class G4ParticleGun;
class G4Event;
class CherProtoPrimaryGeneratorMessenger;

class CherProtoPrimaryGeneratorAction : public G4VUserPrimaryGeneratorAction
{
public:
  CherProtoPrimaryGeneratorAction();
  ~CherProtoPrimaryGeneratorAction();

public:
  virtual void GeneratePrimaries(G4Event*);

  void SetOptPhotonPolar();
  void SetOptPhotonPolar(G4double);

private:
  G4ParticleGun* fParticleGun;
  CherProtoPrimaryGeneratorMessenger* fGunMessenger;
};

#endif
