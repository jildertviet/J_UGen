// PluginJEventBaseS.hpp
// Jildert Viet (info@jildertviet.com)

#pragma once

#include "JEventBase.hpp"
#include "SC_PlugIn.hpp"
#include "SC_Reply.h"
#include <iostream>
using namespace std;

static InterfaceTable *ft;

namespace JEventBaseS {

class JEventBaseS : public SCUnit, public JEventBase {
public:
  JEventBaseS() {}
  ~JEventBaseS() {
    cout << "Delete" << endl;
    SendNodeReply(&(this->mParent->mNode), subID, "/kill", 0, nullptr);
    // RTFree(this->mWorld, values);
    // RTFree(this->mWorld, busses);
  }
  void init(bool bCreate = true) {
    // std::cout << "X" << std::endl;
    subID = in(0)[0];
    // values =
    // (float **)RTAlloc(this->mWorld, in(24)[0] + NUM_VALUES * sizeof(float));
    // busses = (float *)RTAlloc(this->mWorld, in(24)[0] * sizeof(float));
    cout << "X" << endl;
    linkValues(in(24)[0]); // set numBusses
    cout << "Y" << endl;
    readValues();
    cout << "Z" << endl;
    if (bCreate)
      create();
  }
  void create() {
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
    SendNodeReply(&(this->mParent->mNode), subID, "/update", totalNumValues,
                  valuesToSend);
    // cout << "End update" << endl;
  }

  void readValues() {
    cout << "readValues" << endl;
    for (int i = 0; i < totalNumValues; i++) {
      if (values) {
        if (values[i])
          *values[i] = in(i + 2)[0];
      }
    }
    cout << "end readValues" << endl;
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
