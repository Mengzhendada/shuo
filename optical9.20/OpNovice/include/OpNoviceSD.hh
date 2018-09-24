#ifndef OpNoviceSD_h
#define OpNoviceSD_h 1


#include "G4VSensitiveDetector.hh"
#include "OpNoviceHit.hh"
#include <vector>
using namespace std;

class OpNoviceSD: public G4VSensitiveDetector
{
public:
  OpNoviceSD(G4String SDname);
  ~OpNoviceSD();
  G4int sum;
  G4int EventN=0;
  G4String volume;
  static G4String SD;
  //static G4String bubble;
  std::vector <int> TrackID;
  G4int trackid;
  //std::vector <int> TrackID_mirror;
  G4double Random(G4double min,G4double max);
   G4bool is_element_in_vector(vector<int> v, G4int element);
public:
  G4bool ProcessHits(G4Step *step, G4TouchableHistory *ROhist);
  void Initialize(G4HCofThisEvent* HCE);
  void EndOfEvent(G4HCofThisEvent* HCE);
 
private:
  OpNoviceHitsCollection* hitCollection;
};
inline G4double OpNoviceSD::Random(G4double min,G4double max)
{
  G4double f = (G4double) rand()/(RAND_MAX-1);
  return min+f*(max-min);
}
inline G4bool OpNoviceSD::is_element_in_vector(vector<int> v,G4int element)
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

  

 
