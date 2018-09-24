//file CherProtoSD.hh /short for CherProtoSensitiveDetector.hh

#ifndef CherProtoSD_h
#define CherProtoSD_h 1

#include "G4VSensitiveDetector.hh"
#include "CherProtoHit.hh"
#include <vector>
using namespace std;

class CherProtoSD : public G4VSensitiveDetector
{
public:
  CherProtoSD(G4String SDname);
  ~CherProtoSD();
  G4int sum;
  G4int EventN = 0;
  G4String volume;
  static G4String SD;
  //vector to store all TrackIDs for photons
  std::vector<int> TrackID;
  G4int trackid;
  //Random number to simulate quantum efficiency
  G4double Random(G4double min,G4double max);
  G4bool is_element_in_vector(vector<int> v,G4int element);
public:
  G4bool ProcessHits(G4Step *step, G4TouchableHistory *ROhist);
  void Initialize(G4HCofThisEvent* HCE);
  void EndOfEvent(G4HCofThisEvent* HCE);

private:
  CherProtoHitCollection* hitCollection;
};
inline G4double CherProtoSD::Random(G4double min, G4double max)
{
  G4double f = (G4double) rand()/RAND_MAX;
  return min+f*(max-min);
}
inline G4bool CherProtoSD::is_element_in_vector(vector<int> v,G4int element)
{
  vector<int>::iterator it;
  it = find(v.begin(),v.end(),element);
  if(it!=v.end()){
    return true;
  }
  else{
    return false;
  }
}
#endif
  
