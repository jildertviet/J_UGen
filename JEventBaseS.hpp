// PluginJEventBaseS.hpp
// Jildert Viet (info@jildertviet.com)

#pragma once

#include "JEventBase.hpp"
#include "SC_PlugIn.hpp"
#include "SC_Reply.h"
#include <iostream>

// #define JV_SHAREDMEM
#ifdef JV_SHAREDMEM
#include "libsharedmemory.hpp"
#include <memory>
#endif

using namespace std;

static InterfaceTable *ft;

namespace JEventBaseS {

class JEventBaseS : public SCUnit, public JEventBase {
public:
  static void JEventBaseS_Ctor(JEventBaseS *unit) { cout << "Ctor!!!" << endl; }
  JEventBaseS() {}
  ~JEventBaseS() {
    cout << "Delete" << endl;
    SendNodeReply(&(this->mParent->mNode), subID, "/kill", 0, nullptr);
    // RTFree(this->mWorld, values);
    // RTFree(this->mWorld, busses);
  }
#ifdef JV_SHAREDMEM
  std::shared_ptr<lsm::SharedMemoryWriteStream> writer;
  string idString = "";
#endif

  void init(bool bCreate = true) {
    subID = in(0)[0];
    linkValues(in(24)[0]); // set numBusses
    readValues();
    if (bCreate)
      create();
  }
  void create() {
#ifdef JV_SHAREDMEM
    idString = "";
    idString += to_string((int)this->mParent->mNode.mID);
    idString += ",";
    idString += to_string(subID); // Don't need to send it, server (ofxJVisuals)
    // receives nodeID and subID
    // cout << idString << endl;

    // auto stream = std::make_shared<SharedMemoryWriteStream>(name, bufferSize,
    // isPersistent);
    writer = std::make_shared<lsm::SharedMemoryWriteStream>(
        idString, 265,
        true); // Allocate shared memory
#endif
    SendNodeReply(&(this->mParent->mNode), encodedInt(), "/create",
                  totalNumValues, valuesToFloatArray());
  }
  bool checkTrigger(int inNumSamples) {
    const float *trig = in(1);
    for (int j = 0; j < inNumSamples; j++) {
      float curtrig = trig[j];
      if (curtrig > 0.f && prevtrig <= 0.f) {
        prevtrig = curtrig;
        return true;
      }
      prevtrig = curtrig;
      return false;
    }
    return false;
  }

  void update() {
    // cout << "Update" << endl;
    readValues();
    valuesToFloatArray(); // Can't allocate memory dynamically?
#ifdef JV_SHAREDMEM
    // cout << "Write" << endl;
    writer->write(valuesToSend, 64);
#else
    SendNodeReply(&(this->mParent->mNode), subID, "/update", totalNumValues,
                  valuesToSend);
#endif
    // cout << "End update" << endl;
  }

  void readValues() {
    // cout << "readValues" << endl;
    for (int i = 0; i < totalNumValues; i++) {
      if (values) {
        if (values[i])
          *values[i] = in(i + 2)[0];
      }
    }
    // cout << "end readValues" << endl;
  }

  int encodedInt() {
    char encodedBytes[4];
    encodedBytes[0] = (char)type;
    encodedBytes[1] = subID;
    int encodedInt;
    memcpy(&encodedInt, encodedBytes, sizeof(int));
    return encodedInt;
  }

  void next(int nSamples) {
    if (checkTrigger(nSamples))
      update();
  }

  float prevtrig = 0.;
  // int cmdNameSize;
  // char* cmdName;
private:
  // Calc function
  // void next(int nSamples);
  // Member variables
};

} // namespace JEventBaseS
