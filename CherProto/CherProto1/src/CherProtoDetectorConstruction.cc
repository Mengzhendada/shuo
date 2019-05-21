//file CherProtoDetectorConstruction.cc

#include "CherProtoDetectorConstruction.hh"
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
#include "CherProtoSD.hh"
#include "G4SDManager.hh"
#include <vector>
#include <iostream>
#include "CherProtoQE.hh"
#include "G4UnionSolid.hh"
#include "G4VisAttributes.hh"
#include "G4Colour.hh"
CherProtoDetectorConstruction::CherProtoDetectorConstruction()
  : G4VUserDetectorConstruction()
{
  fExpHall_x=fExpHall_y=fExpHall_z = 1*m;
  fGas_R = 0.09685*m;
  fGas_h = 1.27/2*m;
  fMirror_x=0.09685/sqrt(2)*m;
  //fMirror_x=0.09685*m;
  fMirror_y=0.09685*m;
  fMirror_z=0.005*m;
  mirror_z = 1.1*m - 1.27/2*m;
  sd_z = 1.1*m - 1.27/2*m;
}
CherProtoDetectorConstruction::~CherProtoDetectorConstruction()
{;}

G4VPhysicalVolume* CherProtoDetectorConstruction::Construct()
{
  //Materials
  G4double a,z,density;
  G4int nelements;
  //Air
  G4Element* N = new G4Element("Nitrogen", "N", z=7, a=14.01*g/mole);
  G4Element* O = new G4Element("Oxygen"  , "O", z=8 ,a=16.00*g/mole);

  G4Material* air = new G4Material("Air", density=1.29*mg/cm3,nelements = 2);
  air ->AddElement(N,70.*perCent);
  air ->AddElement(O,30.*perCent);
  //Nitrogen
  G4Material* nitrogen = new G4Material("Nitrogen", density=1.25*mg/cm3,nelements=1);
  nitrogen ->AddElement(N,100.*perCent);
  //CO2
  G4Element* C = new G4Element("Carbon","C",z=6, a = 12.01*g/mole);
  G4Material* CO2 = new G4Material("CO2",density = 1.98*mg/cm3,nelements = 2);
  CO2->AddElement(C, 1);
  CO2->AddElement(O, 2);
  //Al
  G4String name;
  G4Material* Al = new G4Material("Aluminum",z = 13., a = 26.98*g/mole, density = 2700*mg/cm3);
  //
// ------------ Generate & Add Material Properties Table ------------
//
  G4cout<<"test 1"<<G4endl;
  CherProtoQE pmt;
  G4int nEntries = pmt.photonEnergy.size();
  G4cout<<"Size of photonEnergy "<<nEntries<<G4endl;
 

//
// Air
//
vector<G4double> refractiveIndex2(nEntries);
for(int i = 0;i<nEntries;++i){refractiveIndex2[i]=1;}
  G4MaterialPropertiesTable* myMPT2 = new G4MaterialPropertiesTable();
  myMPT2->AddProperty("RINDEX", pmt.photonEnergy.data(), refractiveIndex2.data(), nEntries);

  G4cout << "Air G4MaterialPropertiesTable" << G4endl;
  myMPT2->DumpTable();

   air->SetMaterialPropertiesTable(myMPT2);

//CO2
  ifstream infile_co2;
  infile_co2.open("co2_refractive.txt");
  double co2_a,co2_b;
  if(!infile_co2.good()){G4cout<<"CO2 refractive index file missing"<<G4endl;exit(0);}
  vector<G4double> refractiveIndex4;
  vector<G4double> photone; 
  while(!infile_co2.eof()){
    infile_co2>>co2_a>>co2_b;
    photone.push_back(co2_a*eV);
    refractiveIndex4.push_back(co2_b);
  }
  G4int nentries = photone.size();
       G4MaterialPropertiesTable* myMPT4 = new G4MaterialPropertiesTable();
       myMPT4->AddProperty("RINDEX",photone.data(),refractiveIndex4.data(), nentries);
     G4cout <<"CO2 G4MaterialPropertiesTable"<<G4endl;
     myMPT4->DumpTable();
     CO2 ->SetMaterialPropertiesTable(myMPT4);

   //nitrogen
 vector<G4double> refractiveIndex3(nEntries);
 //vector<G4double> refractiveIndex4(nEntries);
 G4double wavelength;
   for(int i=0;i<nEntries;i++){
     wavelength=1*1E3*4.13566766*1E-15*2.99792458*1E8/(pmt.photonEnergy[i]/eV);
     G4cout<<"e"<<pmt.photonEnergy[i];
   //  wavelength = (pmt.photonEnergy[i]/eV)*1.24;
     refractiveIndex3[i]=1+6.8552*1E-5+3.243157*1E-2/(144-wavelength*wavelength);
   //G4double l2 = 1/(wavelength*wavelength);
   //G4cout<<" l "<<wavelength;
   //refractiveIndex4[i]=1+6.99100*1E-2/(166.175-l2)+1.44720*1E-3/(79.609-l2)+6.42941*1E-5/(56.3064-l2)+5.21306*1E-5/(46.0196-l2)+1.46847*1E-6/(0.0584738-l2);  
   //G4cout<<" nitrogen "<<refractiveIndex3[i]<<" CO2 "<<refractiveIndex4[i]<<G4endl;
   }
       G4MaterialPropertiesTable* myMPT3 = new G4MaterialPropertiesTable();
       myMPT3->AddProperty("RINDEX",pmt.photonEnergy.data(),refractiveIndex3.data(), nEntries);
     G4cout <<"Nitrogen G4MaterialPropertiesTable"<<G4endl;
     myMPT3->DumpTable();
     nitrogen ->SetMaterialPropertiesTable(myMPT3);
//CO2
  //vector<G4double> refractiveIndex4(nEntries);
  //G4double wavelength;
  //for(int i=0;i<nEntries;++i){
      //wavelength=1*1E3*4.13566766*1E-15*2.99792458*1E8/(pmt.photonEnergy[i]/eV);
      //wavelength=1*1E3*4.13566766*1E-15*2.99792458*1E8/(pmt.photonEnergy[i]/eV);
    //G4cout<<"wavelength"<<wavelength<<G4endl;
      //wavelength = pmt.photonEnergy[i]*1.24;  
    //G4double l2 = 1/(wavelength*wavelength);
    //refractiveIndex4[i]=1+6.99100*1E-2/(166.175-l2)+1.44720*1E-3/(79.609-l2)+6.42941*1E-5/(56.3064-l2)+5.21306*1E-5/(46.0196-l2)+1.46847*1E-6/(0.0584738-l2);  
//      refractiveIndex4[i] = 1.000448;
    //  G4cout <<"refractiveIndex for CO2 is "<<refractiveIndex4[i]<<G4endl;
  //}
     //   G4MaterialPropertiesTable* myMPT4 = new G4MaterialPropertiesTable();
     //   myMPT4->AddProperty("RINDEX",pmt.photonEnergy.data(),refractiveIndex4.data(), nEntries);
     // G4cout <<"CO2 G4MaterialPropertiesTable"<<G4endl;
     // myMPT3->DumpTable();
     // CO2 ->SetMaterialPropertiesTable(myMPT4);


// ------------- Volumes --------------

// The experimental Hall
//
  G4Box* expHall_box = new G4Box("World",fExpHall_x,fExpHall_y,fExpHall_z);

  G4LogicalVolume* expHall_log
    = new G4LogicalVolume(expHall_box,air,"World",0,0,0);

  G4VPhysicalVolume* expHall_phys
    = new G4PVPlacement(0,G4ThreeVector(),expHall_log,"World",0,false,0);
// tank gas
    //G4Tubs* nitrogentub_tub=new G4Tubs("Tub",0,fGas_R,fGas_h,0,360*degree);
  //G4LogicalVolume* nitrogentub_log = new G4LogicalVolume(nitrogentub_tub,CO2,"Tub",0,0,0);
  //G4VPhysicalVolume* nitrogentub_phys = new G4PVPlacement(0,G4ThreeVector(),nitrogentub_log,"Tub",expHall_log,false,0);
   G4VSolid* gas_tub1 = new G4Tubs("Tub1",0,fGas_R,fGas_h,0,360*degree);
   G4VSolid* gas_tub2 = new G4Tubs("Tub2",0,fGas_R,15*cm,0,360*degree);
   typedef CLHEP::HepRotation G4RotationMatrix;
   G4RotationMatrix* tubRot = new G4RotationMatrix;
   tubRot->rotateX(-M_PI/2.*rad);
   G4VSolid* gastub_tub = new G4UnionSolid("Tub",gas_tub1,gas_tub2,tubRot, G4ThreeVector(0,0.15*m,mirror_z));
   G4LogicalVolume* gastub_log = new G4LogicalVolume(gastub_tub,CO2,"Tub",0,0,0);
   G4VPhysicalVolume* gastub_phys = new G4PVPlacement(0,G4ThreeVector(),gastub_log,"Tub",expHall_log,false,0);
  //Al foil
    G4Tubs* Al_s = new G4Tubs("Al start",0,fGas_R,0.051*cm,0,360*degree);
    G4Tubs* Al_e = new G4Tubs("Al end",0,fGas_R,0.051*cm,0,360*degree);
    G4LogicalVolume* Al_s_log = new G4LogicalVolume(Al_s,Al,"Al foil window start",0,0,0);
    G4LogicalVolume* Al_e_log = new G4LogicalVolume(Al_e,Al,"Al foil window start",0,0,0);
   G4VPhysicalVolume* Al_s_phys = new G4PVPlacement(0,G4ThreeVector(0*cm,0*cm,-1.27/2*m),Al_s_log,"Al foil",expHall_log,false,0);
   G4VPhysicalVolume* _phys = new G4PVPlacement(0,G4ThreeVector(0*cm,0*cm,1.27/2*m),Al_e_log,"Al foil end",expHall_log,false,0);

   //Mirror
  G4Box* Mirror_box = new G4Box("Mirror", fMirror_x,fMirror_y,fMirror_z);
  G4LogicalVolume* Mirror_log
    = new G4LogicalVolume(Mirror_box, Al,"Mirror",0,0,0);
  typedef CLHEP::HepRotation G4RotationMatrix;
  G4RotationMatrix* xRot = new G4RotationMatrix;
  xRot -> rotateX(-45*degree);
  //xRot -> rotateZ(6*degree);
  
  G4VPhysicalVolume* Mirror_physics =
    new G4PVPlacement(xRot,G4ThreeVector(0,0,mirror_z),Mirror_log,"Mirror",gastub_log,false,0);
//not sure what does this do
 // G4VisAttributes* SurfaceVisAtt = new G4VisAttributes(G4Colour(0.0,0.0,1.0));
 // SurfaceVisAtt->SetVisibility(true);
 // SurfaceVisAtt->SetForceWireframe(true);
 // Mirror_log->SetVisAttributes(SurfaceVisAtt);


//  CherProtoSD* sensitiveMirror = new CherProtoSD("sensitiveMiror");
//  G4SDManager* sdman1 = G4SDManager::GetSDMpointer();
//  sdman1 ->AddNewDetector(sensitiveMirror);
//  Mirror_log->SetSensitiveDetector(sensitiveMirror);
  
//Sensitive Detector
    G4Box * SD_box = new G4Box("SensitiveDetector", 0.1/2*m,0.02*m,0.1/2*m);
  G4LogicalVolume* SD_log = new G4LogicalVolume(SD_box, air, "SD",0,0,0);
  G4VPhysicalVolume* SD_phys = new G4PVPlacement(0,G4ThreeVector(0,0.2*m,sd_z),SD_log,"SD",gastub_log,true,0);
  CherProtoSD* sensitive = new CherProtoSD("sensitive");
  G4SDManager* sdman = G4SDManager:: GetSDMpointer();
  sdman ->AddNewDetector(sensitive);
  SD_log->SetSensitiveDetector(sensitive);


//Mirror Surface
 // G4OpticalSurface* MirrorSurface = new G4OpticalSurface("MirrorSurface");
 // MirrorSurface -> SetType(dielectric_metal);
 // MirrorSurface -> SetFinish(polished);
 // MirrorSurface -> SetModel(glisur);

 // G4LogicalSkinSurface* mirrorSurface = new G4LogicalSkinSurface("MirrorSurface",Mirror_log,MirrorSurface);
 // G4OpticalSurface* opticalSurface = dynamic_cast <G4OpticalSurface*> (mirrorSurface->GetSurface(Mirror_log)->GetSurfaceProperty());
 // if (opticalSurface) opticalSurface->DumpInfo();

 // std::ifstream infile_mirror;
 // infile_mirror.open("mirror_reflectivity.txt");
 // std::vector<double> ephoton;
 // std::vector<double> reflectivity;
 // if(!infile_mirror.good()) 
 // {G4cout<<"can't find file mirror reflectivity"<<G4endl;
 //   exit(0);}
 // double c,d;
 // while(!infile_mirror.eof()){
 //   infile_mirror>>c>>d;
 //   ephoton.push_back((c/1239.84193)*eV);
 //   reflectivity.push_back(d/100);
 //   infile_mirror.ignore(100,'\n');
 // }
 // G4int num = reflectivity.size();
 // //const G4int num = 2;
 // //G4double ephoton[num] = {2.034*eV, 4.136*eV};
 // //  //OpticalSurface
 // //G4double reflectivity[num] = {0.2, 0.3};
 // //G4double efficiency[num]   = {0.2, 0.3};
 // G4MaterialPropertiesTable *myST2 = new G4MaterialPropertiesTable();

 // myST2->AddProperty("REFLECTIVITY", ephoton.data(), reflectivity.data(), num);

////  myST2->AddProperty("REFLECTIVITY", ephoton, reflectivity, num);
////  myST2->AddProperty("EFFICIENCY",   ephoton, efficiency,   num);

 // G4cout << "Mirror Surface G4MaterialPropertiesTable" << G4endl;
 // myST2->DumpTable();

 //  MirrorSurface->SetMaterialPropertiesTable(myST2);
//Mirror surface
 G4OpticalSurface* OpticalCO2Mirror = new G4OpticalSurface("MirrorSurface");
 OpticalCO2Mirror->SetModel(unified);
 OpticalCO2Mirror->SetType(dielectric_dielectric);
 OpticalCO2Mirror->SetFinish(polishedfrontpainted);
  
 std::ifstream infile_mirror;
 infile_mirror.open("mirror_reflectivity.txt");
 std::vector<double> ephoton;
 std::vector<double> reflectivity;
 if(!infile_mirror.good()) 
 {G4cout<<"can't find file mirror reflectivity"<<G4endl;
   exit(0);}
 double c,d;
 while(!infile_mirror.eof()){
   infile_mirror>>c>>d;
   ephoton.push_back((c/1239.84193)*eV);
   reflectivity.push_back(d/100);
   infile_mirror.ignore(100,'\n');
 }
 G4int num = reflectivity.size();
 
//const G4int num = 2;
//G4double ephoton[num] = {2.034*eV, 4.136*eV};
  //OpticalSurface
//G4double reflectivity[num] = {0.2, 0.3};
//G4double efficiency[num]   = {0.2, 0.3};
 
 G4MaterialPropertiesTable *myST2 = new G4MaterialPropertiesTable();
 myST2->AddProperty("REFLECTIVITY", ephoton.data(), reflectivity.data(), num);
 //myST2->AddProperty("REFLECTIVITY", ephoton, reflectivity, num);
 
 OpticalCO2Mirror->SetMaterialPropertiesTable(myST2);

 new G4LogicalBorderSurface("CO2/Mirror Surface",gastub_phys,Mirror_physics,OpticalCO2Mirror);
  //always return the physical World
  return expHall_phys;
}
