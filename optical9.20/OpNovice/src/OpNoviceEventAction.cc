#include "g4root.hh"
#include "OpNoviceEventAction.hh"
#include "OpNoviceHit.hh"
#include "OpNoviceSD.hh"
#include "G4SDManager.hh"
#include "G4Event.hh"
#include "G4HCofThisEvent.hh"
#include "G4RunManager.hh"



OpNoviceEventAction::OpNoviceEventAction()
  :G4UserEventAction(),
   SDHCID(-1),
   mirrorHCID(-1)
{}
OpNoviceEventAction::~OpNoviceEventAction()
{}
OpNoviceHitsCollection* OpNoviceEventAction::GetHitsCollection(G4int hcID, const G4Event* event) const
{
   auto hitsCollection 
    = static_cast<OpNoviceHitsCollection*>(
        event->GetHCofThisEvent()->GetHC(hcID));
   if ( ! hitsCollection ) {
    G4ExceptionDescription msg;
    msg << "Cannot access hitsCollection ID " << hcID; 
    G4Exception("OpNoviceEventAction::GetHitsCollection()",
      "EventAction", FatalException, msg);
   }
   return hitsCollection;
}
void OpNoviceEventAction::BeginOfEventAction(const G4Event* event)
{}
void OpNoviceEventAction::EndOfEventAction(const G4Event* event)
{
    // if (SDHCID ==-1){
  //   SDHCID = G4SDManager::GetSDMpointer()->GetCollectionID("SDHitCollection");
  //   mirrorHCID = G4SDManager::GetSDMpointer()->GetCollectionID("mirrorHitCollection");
  // }
  //   auto SDHC = GetHitsCollection(SDHCID,event);
  //   auto mirrorHC = GetHitsCollection(mirrorHCID,event);

  //   auto SDHit = (*SDHC)[SDHC->entries()-1];
  //   auto mirrorHit=(*mirrorHC)[mirrorHC->entries()-1];

    // G4cout<<"HitCounting"<< SDHIT->Getcounting()<<G4endl;
    
}
