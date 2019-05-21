// file: CherProtoDetectorConstruction.hh

#ifndef CherProtoDetectorConstruction_h
#define CherProtoDetectorConstruction_h 1

#include "globals.hh"
#include "G4VUserDetectorConstruction.hh"

class CherProtoDetectorConstruction : public G4VUserDetectorConstruction
{
public:
  CherProtoDetectorConstruction();
  ~CherProtoDetectorConstruction();

public:
  virtual G4VPhysicalVolume* Construct();

private:
  G4double fExpHall_x;
  G4double fExpHall_y;
  G4double fExpHall_z;

  G4double fGas_R;
  G4double fGas_h;

  G4double fMirror_x;
  G4double fMirror_y;
  G4double fMirror_z;

  G4double mirror_z;
  G4double sd_z;
};
#endif
