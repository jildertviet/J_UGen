// PluginJFunctionTrigger.cpp
// Jildert Viet (info@jildertviet.com)

#include "SC_PlugIn.hpp"
#include "JFunctionTrigger.hpp"

// static InterfaceTable* ft;

namespace JFunctionTrigger {

JFunctionTrigger::JFunctionTrigger() {
    mCalcFunc = make_calc_function<JFunctionTrigger, &JFunctionTrigger::next>();
    type = jevent::JFunctionTrigger;
    subID = in(0)[0];
    // init(); // readValues + create
    next(1); // Am I missing the first trigger if I don't do this?
}

// void JFunctionTrigger::clearUpdateArray(){
  // memset(bNeedsUpdate, 0x00, sizeof(bool)*NUM_BUSSES); // All false?
  // numToSend = 0;
// }

// JFunctionTrigger::~JFunctionTrigger(){

// }

void JFunctionTrigger::next(int inNumSamples) {
  // id,
  // trigger,
  // trigger,
  // targetID,
  // targetSubID,
  // functionID,
  // values
  const float* trig = in(1);
  for (int j = 0; j < inNumSamples; j++) {
      float curtrig = trig[j];
      if (curtrig > 0.f && prevtrig <= 0.f) {
          // Update
          float msg[5+3];
          for(int i=0; i<8; i++){
            msg[i] = in(2+i)[0];
          }
          SendNodeReply(&(this->mParent->mNode), encodedInt(), "/trigger", 8, &msg[0]);
      }
      prevtrig = curtrig;
  }
}

} // namespace JFunctionTrigger

PluginLoad(JFunctionTriggerUGens) {
    // Plugin magic
    ft = inTable;
    registerUnit<JFunctionTrigger::JFunctionTrigger>(ft, "JFunctionTrigger", false);
}
