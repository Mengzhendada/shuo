#include "g4root.hh"
#include "CherProtoEventAction.hh"
#include "CherProtoHit.hh"
#include "CherProtoSD.hh"
#include "G4SDManager.hh"
#include "G4Event.hh"
#include "G4HCofThisEvent.hh"
#include "G4RunManager.hh"


CherProtoEventAction::CherProtoEventAction()
  : G4UserEventAction()
{}
CherProtoEventAction::~CherProtoEventAction()
{}
void BeginOfEventAction(const G4Event* event)
{}
void EndOfEventAction(const G4Event* event)
{
  // G4cout<<"this is in EventAction"<<G4endl;
  //     if (SDHCID ==-1){
  //   SDHCID = G4SDManager::GetSDMpointer()->GetCollectionID("SDHitCollection");
  //   mirrorHCID = G4SDManager::GetSDMpointer()->GetCollectionID("mirrorHitCollection");
  // }
  //   new SDHC = GetHitsCollection(SDHCID,event);
  //   new mirrorHC = GetHitsCollection(mirrorHCID,event);

  //   new SDHit = (*SDHC)[SDHC->entries()-1];
  //   new mirrorHit=(*mirrorHC)[mirrorHC->entries()-1];

  //   G4cout<<"HitCounting"<< SDHIT->Getcounting()<<G4endl;
  //   G4cout<<"MirrorCounting"<<mirrorHit->Getcounting()<<G4endl;
    
}
