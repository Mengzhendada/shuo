//file CherProtoRunAction.cc

#include "G4Timer.hh"

#include "CherProtoRunAction.hh"

#include "G4Run.hh"
#include "g4root.hh"
#include "G4RunManager.hh"
#include "CherProtoEventAction.hh"
#include "G4SDManager.hh"
#include "CherProtoHit.hh"
#include "CherProtoSD.hh"
#include "G4THitsCollection.hh"


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

CherProtoRunAction::CherProtoRunAction()
 : G4UserRunAction(),
   fTimer(0)
{
  fTimer = new G4Timer;
  
  G4AnalysisManager* analysisManager = G4AnalysisManager::Instance();
  analysisManager->OpenFile("CherProto");
  analysisManager ->SetVerboseLevel(1);
  analysisManager->CreateH1("Number","Number of optical photons",100,0,100);
  analysisManager->CreateNtuple("T","PMT Tree");
  analysisManager->CreateNtupleIColumn(0,"TrackID");
  analysisManager->CreateNtupleDColumn(0,"Energy");
  analysisManager->CreateNtupleIColumn(0,"EventID");
  analysisManager->CreateNtupleDColumn(0,"xposition");
  analysisManager->CreateNtupleDColumn(0,"yposition");
  analysisManager->CreateNtupleDColumn(0,"zposition");
  analysisManager->FinishNtuple(0);
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

CherProtoRunAction::~CherProtoRunAction()
{
  delete fTimer;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void CherProtoRunAction::BeginOfRunAction(const G4Run* aRun)
{
  G4cout << "### Run " << aRun->GetRunID() << " start." << G4endl;
  fTimer->Start();
  
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void CherProtoRunAction::EndOfRunAction(const G4Run* aRun)
{
  
  fTimer->Stop();
  G4cout << "number of event = " << aRun->GetNumberOfEvent()
         << " " << *fTimer << G4endl;
  G4AnalysisManager* analysisManager = G4AnalysisManager::Instance();
  analysisManager->Write();
  analysisManager->CloseFile();
}
