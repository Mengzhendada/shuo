//file CherProtoSteppingVerbose.hh

//class CherProtoSteppingVerbose;

#ifndef CherProtoSteppingVerbose_h
#define CherProtoSteppingVerbose_h 1

#include "G4SteppingVerbose.hh"

class CherProtoSteppingVerbose : public G4SteppingVerbose
{
public:
  CherProtoSteppingVerbose();
  ~CherProtoSteppingVerbose();

  virtual void StepInfo();
  virtual void TrackingStarted();
};

#endif
