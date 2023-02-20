// PluginJRectangleS.cpp
// Jildert Viet (info@jildertviet.com)

#include "SC_PlugIn.hpp"
#include "JRectangleS.hpp"
#include <iostream>
using namespace std;

static InterfaceTable* ft;

namespace JRectangleS {

JRectangleS::JRectangleS() {
    mCalcFunc = make_calc_function<JRectangleS, &JRectangleS::next>();

    readValues();
    SendNodeReply(&(this->mParent->mNode), jevent::JRectangle, "/create", NUM_BUSSES, valuesToFloatArray());
    next(1);
}

void JRectangleS::clearUpdateArray(){
  memset(bNeedsUpdate, 0x00, sizeof(bool)*NUM_BUSSES); // All false?
  numToSend = 0;
}

JRectangleS::~JRectangleS(){
  cout << "Delete" << endl;
  SendNodeReply(&(this->mParent->mNode), -1, "/kill", 0, nullptr);
}

void JRectangleS::next(int inNumSamples) {
    const float* trig = in(0);
    for (int j = 0; j < inNumSamples; j++) {
        float curtrig = trig[j];
        if (curtrig > 0.f && prevtrig <= 0.f) {
            update();
        }
        prevtrig = curtrig;
    }
}

void JRectangleS::readValues(){
  for(int i=0; i<NUM_BUSSES; i++){
    // if(*values[i] != in(i+1)[0]){
    //   bNeedsUpdate[i] = true;
    //   numToSend++;
    // }
    if(values[i])
      *values[i] = in(i+1)[0];
  }
}

void JRectangleS::update(){
  readValues();
  // const float* locX = in(1);
  // const float* locY = in(2);
  float* valuesT = new float[4];
  memset(valuesT, 0x00, sizeof(float)*4);
  valuesT[0] = 3.14;
  int replyId = 0;

  // cout << in(1)[0] << ", " << in(2)[0] << endl;
  // Check all values vs. input busses: if changed, add to msg.

  SendNodeReply(&(this->mParent->mNode), replyId, "/update", NUM_BUSSES, valuesToFloatArray());
}

} // namespace JRectangleS

PluginLoad(JRectangleSUGens) {
    // Plugin magic
    ft = inTable;
    registerUnit<JRectangleS::JRectangleS>(ft, "JRectangleS", false);
}
