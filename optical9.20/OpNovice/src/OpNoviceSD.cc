#include "OpNoviceSD.hh"
#include "G4HCofThisEvent.hh"
#include "G4Step.hh"
#include "G4ThreeVector.hh"
#include "G4SDManager.hh"
#include "G4ios.hh"
#include "OpNoviceHit.hh"
#include "G4SystemOfUnits.hh"
#include "g4root.hh"
G4String OpNoviceSD::SD="SD";
//G4String OpNoviceSD::bubble="Bubble";
OpNoviceSD::OpNoviceSD(G4String SDname)
: G4VSensitiveDetector(SDname)
{
  G4cout<<"Creating SD with name: "<<SDname<<G4endl;
  collectionName.insert("OpNoviceHitCollection");
}
OpNoviceSD::~OpNoviceSD()
{
}
void OpNoviceSD::Initialize(G4HCofThisEvent* HCE)
{
   G4cout<<"GetName()"<<hitCollection->GetName()<<G4endl;
  hitCollection = new OpNoviceHitsCollection(GetName(),collectionName[0]);
  static G4int HCID = -1;
  if (HCID<0) HCID = GetCollectionID(0);
  G4cout<<"check Initialize"<<G4endl;
  G4cout<<"HCID"<<HCID<<G4endl;
  HCE->AddHitsCollection(HCID,hitCollection);
  sum = 0;
  // sum1=0;
  TrackID.clear();
  
			
}
G4bool OpNoviceSD::ProcessHits(G4Step *step, G4TouchableHistory*)
{
  G4TouchableHandle touchable = step->GetPreStepPoint()->GetTouchableHandle();
  G4int copyNo = touchable ->GetVolume(0)->GetCopyNo();
  volume = touchable ->GetVolume()->GetName();
  G4cout<<"volumename "<<volume<<G4endl;
  G4cout <<"copyNo"<<copyNo<<G4endl;

  OpNoviceHit* aHit = new OpNoviceHit();
  
  // G4int r = (random()%100)+1;
  //G4cout<<"randomnumber "<<r<<G4endl;
  //strconp,
 
    
    
  G4double edep = step->GetTotalEnergyDeposit();
  G4cout<<"edep in SD.cc "<<edep<<G4endl;
  G4cout<<"TrackID "<<step->GetTrack()->GetTrackID()<<" ParentID "<<step->GetTrack()->GetParentID()<<G4endl;
  G4cout<<"Particle name "<<step->GetTrack()->GetParticleDefinition()->GetParticleName()<<G4endl;
    
   
    
  G4String opticalphoton="opticalphoton";
  if(step->GetTrack()->GetParticleDefinition()->GetParticleName()== opticalphoton){
    if (volume == SD){
      if (Random(0,100)<20.8){
	hitCollection ->insert(aHit);
	aHit->AddEdep(edep);
	aHit ->Print();
	aHit ->Count();
	trackid=step->GetTrack()->GetTrackID();
	G4cout<<"trackid"<<trackid<<G4endl;
	if(is_element_in_vector(TrackID,trackid))
	  {
	    G4cout<<"sameID"<<G4endl;
	  }
	else
	  {
	    TrackID.push_back(step->GetTrack()->GetTrackID());
	    G4AnalysisManager* analysisManager = G4AnalysisManager::Instance();
	    analysisManager->FillNtupleIColumn(0,0,step->GetTrack()->GetTrackID());
	    analysisManager->FillNtupleDColumn(0,1,step->GetTrack()->GetTotalEnergy()*eV);
	    analysisManager->FillNtupleIColumn(0,2,EventN);
	    analysisManager->FillNtupleDColumn(0,3,step->GetTrack()->GetPosition().x());
	    analysisManager->FillNtupleDColumn(0,4,step->GetTrack()->GetPosition().y());
	    analysisManager->FillNtupleDColumn(0,4,step->GetTrack()->GetPosition().z());
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
void OpNoviceSD::EndOfEvent(G4HCofThisEvent* HCE)
{
  G4cout<<"EndOfEvent"<<G4endl;
 
  
    sort(TrackID.begin(),TrackID.end());
    TrackID.erase(unique(TrackID.begin(),TrackID.end()),TrackID.end());
    for(unsigned int i=0;i<TrackID.size();i++){
      G4cout<<"TrackIDsorted"<<TrackID[i]<<G4endl;}
  
    G4cout<<"size of vector"<<TrackID.size()<<G4endl;
    G4AnalysisManager* analysisManager = G4AnalysisManager::Instance();
    analysisManager->FillH1(0,(int)TrackID.size());
    // analysisManager->FillNtupleIColumn(0,0,(int)TrackID.size());
    // analysisManager->AddNtupleRow(0);
    EventN++;
  
 

}
