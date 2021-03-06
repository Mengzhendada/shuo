//file CherProtoActionInitialization.hh

#ifndef CherProtoActionInitialization_h
#define CherProtoActionInitialization_h 1

#include "G4VUserActionInitialization.hh"

class CherProtoActionInitialization : public G4VUserActionInitialization
{
 public:
  CherProtoActionInitialization();
  virtual ~CherProtoActionInitialization();
  virtual void BuildForMaster() const;
  virtual void Build() const;

  virtual G4VSteppingVerbose* InitializeSteppingVerbose() const;
};
#endif
