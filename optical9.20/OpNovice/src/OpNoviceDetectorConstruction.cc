//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//
/// \file OpNovice/src/OpNoviceDetectorConstruction.cc
/// \brief Implementation of the OpNoviceDetectorConstruction class
//
//
//
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#include "OpNoviceDetectorConstruction.hh"

#include "G4Material.hh"
#include "G4Element.hh"
#include "G4LogicalBorderSurface.hh"
#include "G4LogicalSkinSurface.hh"
#include "G4OpticalSurface.hh"
#include "G4Box.hh"
#include "G4Tubs.hh"
#include "G4LogicalVolume.hh"
#include "G4ThreeVector.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"
#include "OpNoviceSD.hh"
#include "G4SDManager.hh"
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

OpNoviceDetectorConstruction::OpNoviceDetectorConstruction()
 : G4VUserDetectorConstruction()
{
  fExpHall_x = fExpHall_y = fExpHall_z = 10.0*m;

  fBubble_x  = fBubble_y  =2.5*m;
  fBubble_z  =  0.05*m;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

OpNoviceDetectorConstruction::~OpNoviceDetectorConstruction(){;}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4VPhysicalVolume* OpNoviceDetectorConstruction::Construct()
{

// ------------- Materials -------------

  G4double a, z, density;
  G4int nelements;

// Air
//
  G4Element* N = new G4Element("Nitrogen", "N", z=7 , a=14.01*g/mole);
  G4Element* O = new G4Element("Oxygen"  , "O", z=8 , a=16.00*g/mole);

  G4Material* air = new G4Material("Air", density=1.29*mg/cm3, nelements=2);
  air->AddElement(N, 70.*perCent);
  air->AddElement(O, 30.*perCent);

//
//nitrogen
  G4Material* nitrogen = new G4Material("Nitrogen",density = 1.25*mg/cm3,nelements=1);
  nitrogen ->AddElement(N,100.*perCent);

//
// ------------ Generate & Add Material Properties Table ------------
//
  G4double photonEnergy[] =
            { 2.034*eV, 2.068*eV, 2.103*eV, 2.139*eV,
              2.177*eV, 2.216*eV, 2.256*eV, 2.298*eV,
              2.341*eV, 2.386*eV, 2.433*eV, 2.481*eV,
              2.532*eV, 2.585*eV, 2.640*eV, 2.697*eV,
              2.757*eV, 2.820*eV, 2.885*eV, 2.954*eV,
              3.026*eV, 3.102*eV, 3.181*eV, 3.265*eV,
              3.353*eV, 3.446*eV, 3.545*eV, 3.649*eV,
              3.760*eV, 3.877*eV, 4.002*eV, 4.136*eV };

  const G4int nEntries = sizeof(photonEnergy)/sizeof(G4double);


//
// Air
//
  G4double refractiveIndex2[] =
            { 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00,
              1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00,
              1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00,
              1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00,
              1.00, 1.00, 1.00, 1.00 };

  G4MaterialPropertiesTable* myMPT2 = new G4MaterialPropertiesTable();
  myMPT2->AddProperty("RINDEX", photonEnergy, refractiveIndex2, nEntries);

  G4cout << "Air G4MaterialPropertiesTable" << G4endl;
  myMPT2->DumpTable();

   air->SetMaterialPropertiesTable(myMPT2);


   //nitrogen
  G4double refractiveIndex3[32];
  G4double wavelength;
    for(int i=0;i<32;i++){
      wavelength=1*1E3*4.13566766*1E-15*2.99792458*1E8/(photonEnergy[i]/eV);
      refractiveIndex3[i]=1+6.8552*1E-5+3.243157*1E-2/(144-wavelength*wavelength);
      G4cout << "refractiveIndex for nitrogen is " << refractiveIndex3[i]<<G4endl;
   }
        G4MaterialPropertiesTable* myMPT3 = new G4MaterialPropertiesTable();
        myMPT3->AddProperty("RINDEX",photonEnergy,refractiveIndex3, nEntries);
      G4cout <<"Nitrogen G4MaterialPropertiesTable"<<G4endl;
      myMPT3->DumpTable();
      nitrogen ->SetMaterialPropertiesTable(myMPT3);
//

// ------------- Volumes --------------

// The experimental Hall
//
  G4Box* expHall_box = new G4Box("World",fExpHall_x,fExpHall_y,fExpHall_z);

  G4LogicalVolume* expHall_log
    = new G4LogicalVolume(expHall_box,air,"World",0,0,0);

  G4VPhysicalVolume* expHall_phys
    = new G4PVPlacement(0,G4ThreeVector(),expHall_log,"World",0,false,0);

// tank
   G4double fTank_R=5*m;
  G4double fTank_h=9*m;
  G4Tubs* nitrogentub_tub=new G4Tubs("Tub",0,fTank_R,fTank_h,0,360*degree);
  G4LogicalVolume* nitrogentub_log = new G4LogicalVolume(nitrogentub_tub,nitrogen,"Tub",0,0,0);
  G4VPhysicalVolume* nitrogentub_phys = new G4PVPlacement(0,G4ThreeVector(),nitrogentub_log,"Tub",expHall_log,false,0);



//airbubble
  
  G4Box* bubbleAir_box = new G4Box("Bubble",fBubble_x,fBubble_y,fBubble_z);

  G4LogicalVolume* bubbleAir_log
    = new G4LogicalVolume(bubbleAir_box,air,"Bubble",0,0,0);
  typedef CLHEP::HepRotation G4RotationMatrix;
  G4RotationMatrix* xRot = new G4RotationMatrix;
  xRot -> rotateX(-M_PI/4.*rad);

  G4VPhysicalVolume* bubbleAir_phys =
  new G4PVPlacement(xRot,G4ThreeVector(0,0,3*m),bubbleAir_log,"Bubble",
                        nitrogentub_log,false,0);
  // OpNoviceSD* sensitive1 = new OpNoviceSD("sensitive1");
  // G4SDManager* sdman1 = G4SDManager::GetSDMpointer();
  // sdman1 ->AddNewDetector(sensitive1);
  // bubbleAir_log -> SetSensitiveDetector(sensitive1);
  //detector
  G4Box * SD_box = new G4Box("SensitiveDetector", 2*m,2*m,2*m);
  G4LogicalVolume* SD_log = new G4LogicalVolume(SD_box, air, "SD",0,0,0);
  G4VPhysicalVolume* SD_phys = new G4PVPlacement(0,G4ThreeVector(0,4*m,4*m),SD_log,"SD",nitrogentub_log,true,0);
  OpNoviceSD* sensitive = new OpNoviceSD("sensitive");
  G4SDManager* sdman = G4SDManager:: GetSDMpointer();
  sdman ->AddNewDetector(sensitive);
  SD_log->SetSensitiveDetector(sensitive);
  
// ------------- Surfaces --------------
//


// Air Bubble
//
  G4OpticalSurface* opAirSurface = new G4OpticalSurface("AirSurface");
  opAirSurface->SetType(dielectric_metal);
  opAirSurface->SetFinish(polished);
  opAirSurface->SetModel(glisur);

  G4LogicalSkinSurface* airSurface =
          new G4LogicalSkinSurface("AirSurface", bubbleAir_log, opAirSurface);

  
 G4OpticalSurface* opticalSurface = dynamic_cast <G4OpticalSurface*>
        (airSurface->GetSurface(bubbleAir_log)->GetSurfaceProperty());
  if (opticalSurface) opticalSurface->DumpInfo();

  /* G4OpticalSurface* opAirSurface = new G4OpticalSurface("AirSurface");

    new G4LogicalBorderSurface("AirSurface", bubbleAir_phys,
                               nitrogentub_phys,
                               opAirSurface);

    opAirSurface->SetType(dielectric_metal);
    opAirSurface->SetFinish(polished);
    opAirSurface->SetModel(glisur);
  */
//
// Generate & Add Material Properties Table attached to the optical surfaces
//
  const G4int num = 2;
  G4double ephoton[num] = {2.034*eV, 4.136*eV};

  

  //OpticalAirSurface
  G4double reflectivity[num] = {0.2, 0.3};
  G4double efficiency[num]   = {0.2, 0.3};

  G4MaterialPropertiesTable *myST2 = new G4MaterialPropertiesTable();

  myST2->AddProperty("REFLECTIVITY", ephoton, reflectivity, num);
  myST2->AddProperty("EFFICIENCY",   ephoton, efficiency,   num);

  G4cout << "Air Surface G4MaterialPropertiesTable" << G4endl;
  myST2->DumpTable();

   opAirSurface->SetMaterialPropertiesTable(myST2);

  //always return the physical World
  return expHall_phys;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
