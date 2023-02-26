// PluginJEventBaseS.hpp
// Jildert Viet (info@jildertviet.com)

#pragma once

#include "SC_PlugIn.hpp"
#include "SC_Reply.h"
#include "JEventBase.hpp"
#include <iostream>
using namespace std;

static InterfaceTable* ft;

namespace JEventBaseS {

class JEventBaseS : public SCUnit, public JEventBase {
public:
    JEventBaseS(){

    }
    ~JEventBaseS(){
      cout << "Delete" << endl;
      SendNodeReply(&(this->mParent->mNode), subID, "/kill", 0, nullptr);
    }
    void init(){
      subID = in(0)[0];
      readValues();
      create();
    }
    void create(){
      SendNodeReply(&(this->mParent->mNode), encodedInt(), "/create", NUM_BUSSES, valuesToFloatArray());
    }
    bool checkTrigger(int inNumSamples){
      const float* trig = in(1);
      for (int j = 0; j < inNumSamples; j++) {
          float curtrig = trig[j];
          if (curtrig > 0.f && prevtrig <= 0.f) {
              prevtrig = curtrig;
              return true;
          }
          prevtrig = curtrig;
          return false;
      }
    }

    void update(){
      readValues();
      SendNodeReply(&(this->mParent->mNode), subID, "/update", NUM_BUSSES, valuesToFloatArray());
    }

    void readValues(){
      for(int i=0; i<NUM_BUSSES; i++){
        if(values[i])
          *values[i] = in(i+2)[0];
      }
    }

    int encodedInt(){
      char encodedBytes[4];
      encodedBytes[0] = (char)type;
      encodedBytes[1] = subID;
      int encodedInt;
      memcpy(&encodedInt, encodedBytes, sizeof(int));
      return encodedInt;
    }
    void next(int nSamples){
      if(checkTrigger(nSamples))
        update();
    }

    float prevtrig;
    // int cmdNameSize;
    // char* cmdName;
private:

    // Calc function
    // void next(int nSamples);
    // Member variables
};

} // namespace JEventBaseS
