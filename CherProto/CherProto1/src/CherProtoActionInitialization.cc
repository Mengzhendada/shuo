//file CherProtoActionInitialization.cc

#include "CherProtoActionInitialization.hh"
#include "CherProtoPrimaryGeneratorAction.hh"
#include "CherProtoRunAction.hh"
//#include "CherProtoEventAction.hh"
#include "CherProtoSteppingAction.hh"
#include "CherProtoStackingAction.hh"
#include "CherProtoSteppingVerbose.hh"

CherProtoActionInitialization::CherProtoActionInitialization()
  :G4VUserActionInitialization()
{}

CherProtoActionInitialization::~CherProtoActionInitialization()
{}

void CherProtoActionInitialization::BuildForMaster() const
{
  SetUserAction(new CherProtoRunAction());
}

void CherProtoActionInitialization::Build() const
{
  SetUserAction(new CherProtoPrimaryGeneratorAction());
  SetUserAction(new CherProtoRunAction());
  SetUserAction(new CherProtoSteppingAction());
  SetUserAction(new CherProtoStackingAction());
G4cout<<"ActionInitialization check"<<G4endl;
}

G4VSteppingVerbose*
   CherProtoActionInitialization::InitializeSteppingVerbose() const
{
  return new CherProtoSteppingVerbose();
}

