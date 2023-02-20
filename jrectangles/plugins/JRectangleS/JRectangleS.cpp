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

    subID = in(0)[0];
    char encodedBytes[4];
    encodedBytes[0] = (char)jevent::JRectangle;
    encodedBytes[1] = subID;
    int encodedInt;
    memcpy(&encodedInt, encodedBytes, sizeof(int));
    readValues();
    SendNodeReply(&(this->mParent->mNode), encodedInt, "/create", NUM_BUSSES, valuesToFloatArray());
    next(1);
}

void JRectangleS::clearUpdateArray(){
  memset(bNeedsUpdate, 0x00, sizeof(bool)*NUM_BUSSES); // All false?
  numToSend = 0;
}

JRectangleS::~JRectangleS(){
  cout << "Delete" << endl;
  SendNodeReply(&(this->mParent->mNode), subID, "/kill", 0, nullptr);
}

void JRectangleS::next(int inNumSamples) {
    const float* trig = in(1);
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
      *values[i] = in(i+2)[0];
  }
}

void JRectangleS::update(){
  readValues();
  SendNodeReply(&(this->mParent->mNode), subID, "/update", NUM_BUSSES, valuesToFloatArray());
}

} // namespace JRectangleS

PluginLoad(JRectangleSUGens) {
    // Plugin magic
    ft = inTable;
    registerUnit<JRectangleS::JRectangleS>(ft, "JRectangleS", false);
}
