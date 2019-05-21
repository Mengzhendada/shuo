#include "CherProtoSD.hh"
#include "G4HCofThisEvent.hh"
#include "G4Step.hh"
#include "G4ThreeVector.hh"
#include "G4SDManager.hh"
#include "G4ios.hh"
#include "CherProtoHit.hh"
#include "G4SystemOfUnits.hh"
#include "g4root.hh"
#include "CherProtoQE.hh"
G4String CherProtoSD::SD="SD";
//G4String CherProtoSD::bubble="Bubble";
CherProtoSD::CherProtoSD(G4String SDname)
: G4VSensitiveDetector(SDname)
{
  G4cout<<"Creating SD with name: "<<SDname<<G4endl;
  collectionName.insert("CherProtoHitCollection");
}
CherProtoSD::~CherProtoSD()
{
}
void CherProtoSD::Initialize(G4HCofThisEvent* HCE)
{
  // G4cout<<"GetName()"<<hitCollection->GetName()<<G4endl;
  hitCollection = new CherProtoHitCollection(GetName(),collectionName[0]);
  static G4int HCID = -1;
  if (HCID<0) HCID = GetCollectionID(0);
  G4cout<<"check Initialize"<<G4endl;
  G4cout<<"HCID"<<HCID<<G4endl;
  HCE->AddHitsCollection(HCID,hitCollection);
  sum = 0;
  // sum1=0;
  TrackID.clear();
  
			
}
G4bool CherProtoSD::ProcessHits(G4Step *step, G4TouchableHistory*)
{
  G4TouchableHandle touchable = step->GetPreStepPoint()->GetTouchableHandle();
  volume = touchable ->GetVolume()->GetName();
  G4cout<<"volumename "<<volume<<G4endl;
  CherProtoHit* aHit = new CherProtoHit();
  G4double edep = step->GetTrack()->GetTotalEnergy();
  G4cout<<"edep in SD.cc "<<edep<<G4endl;
  G4cout<<"TrackID "<<step->GetTrack()->GetTrackID()<<" ParentID "<<step->GetTrack()->GetParentID()<<G4endl;
  G4cout<<"Particle name "<<step->GetTrack()->GetParticleDefinition()->GetParticleName()<<G4endl;
  //G4cout<<"energycheck"<<edep<<G4endl;    


  G4String opticalphoton="opticalphoton";
  if(step->GetTrack()->GetParticleDefinition()->GetParticleName()== opticalphoton){
    if (volume == SD){
      CherProtoQE sdpmt;
      //   if (Random(0,100)/100<0.26){
      if (Random(0,100)/100<sdpmt.GetQE(edep)){
        G4cout<<"test for qe"<<G4endl;
        hitCollection ->insert(aHit);
        aHit->AddEdep(edep);
        aHit ->Print();
        //	aHit ->Count();
        trackid=step->GetTrack()->GetTrackID();
        G4cout<<"trackidcheck"<<trackid<<G4endl;
        if(is_element_in_vector(TrackID,trackid))
        {
          G4cout<<"sameID"<<G4endl;
        }
        else
        {
          TrackID.push_back(step->GetTrack()->GetTrackID());
          G4AnalysisManager* analysisManager = G4AnalysisManager::Instance();
          analysisManager->FillH2(0,step->GetTrack()->GetPosition().x(),step->GetTrack()->GetPosition().z()-(1.1-1.27/2)*m);
          analysisManager->FillNtupleIColumn(0,0,step->GetTrack()->GetTrackID());
          analysisManager->FillNtupleDColumn(0,1,step->GetTrack()->GetTotalEnergy()/eV);
          analysisManager->FillNtupleIColumn(0,2,EventN);
          analysisManager->FillNtupleDColumn(0,3,step->GetTrack()->GetPosition().x());
          analysisManager->FillNtupleDColumn(0,4,step->GetTrack()->GetPosition().y());
          analysisManager->FillNtupleDColumn(0,5,step->GetTrack()->GetPosition().z()-(1.1-1.27/2)*m);
          analysisManager->AddNtupleRow(0);

          sum++;
          // G4cout<<"sum in Process"<<sum<<G4endl;

        }
      }
    }
      else{
        if(is_element_in_vector(TrackID,trackid))
        {G4cout<<"sameID"<<G4endl;
        }
        else
        {
          TrackID.push_back(step->GetTrack()->GetTrackID());
          G4cout<<"not SD"<<G4endl;
          sum++;
          // G4cout<<"sum1 in Process"<<sum1<<G4endl;
        }
      }
    }
    else G4cout<<"not optical photons"<<G4endl;

    
  
 
  
  return true;
}
void CherProtoSD::EndOfEvent(G4HCofThisEvent* HCE)
{
  G4cout<<"EndOfEvent"<<G4endl;
 
  
    //sort(TrackID.begin(),TrackID.end());
    //TrackID.erase(unique(TrackID.begin(),TrackID.end()),TrackID.end());
    //for(unsigned int i=0;i<TrackID.size();i++){
    //  G4cout<<"TrackIDsorted"<<TrackID[i]<<G4endl;}
  
    //G4cout<<"size of vector"<<TrackID.size()<<G4endl;
    G4AnalysisManager* analysisManager = G4AnalysisManager::Instance();
    analysisManager->FillH1(0,(int)TrackID.size());
    // analysisManager->FillNtupleIColumn(0,0,(int)TrackID.size());
    // analysisManager->AddNtupleRow(0);
    EventN++;
  
 

}
