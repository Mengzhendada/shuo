//file CherProtoPrimaryGeneratorMessenger.cc

#include "CherProtoPrimaryGeneratorMessenger.hh"

#include "CherProtoPrimaryGeneratorAction.hh"
#include "G4UIdirectory.hh"
#include "G4UIcmdWithADoubleAndUnit.hh"
#include "G4SystemOfUnits.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

CherProtoPrimaryGeneratorMessenger::
  CherProtoPrimaryGeneratorMessenger(CherProtoPrimaryGeneratorAction* CherProtoGun)
  : G4UImessenger(),
    fCherProtoAction(CherProtoGun)
{
  fGunDir = new G4UIdirectory("/CherProto/gun/");
  fGunDir->SetGuidance("PrimaryGenerator control");

  fPolarCmd =
           new G4UIcmdWithADoubleAndUnit("/CherProto/gun/optPhotonPolar",this);
  fPolarCmd->SetGuidance("Set linear polarization");
  fPolarCmd->SetGuidance("  angle w.r.t. (k,n) plane");
  fPolarCmd->SetParameterName("angle",true);
  fPolarCmd->SetUnitCategory("Angle");
  fPolarCmd->SetDefaultValue(-360.0);
  fPolarCmd->SetDefaultUnit("deg");
  fPolarCmd->AvailableForStates(G4State_Idle);
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

CherProtoPrimaryGeneratorMessenger::~CherProtoPrimaryGeneratorMessenger()
{
  delete fPolarCmd;
  delete fGunDir;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void CherProtoPrimaryGeneratorMessenger::SetNewValue(
                                        G4UIcommand* command, G4String newValue)
{
  if( command == fPolarCmd ) {
      G4double angle = fPolarCmd->GetNewDoubleValue(newValue);
      if ( angle == -360.0*deg ) {
         fCherProtoAction->SetOptPhotonPolar();
      } else {
         fCherProtoAction->SetOptPhotonPolar(angle);
      }
  }
}
