// PluginJBufferSender.cpp
// Jildert Viet (info@jildertviet.com)

#include "SC_PlugIn.hpp"
#include "JBufferSender.hpp"

namespace JBufferSender {

#define CHECK_BUFFER_DATA                                                                                              \
    if (!bufData) {                                                                                                    \
        if (this->mWorld->mVerbosity > -1 && !this->mDone && (this->m_failedBufNum != fbufnum)) {                      \
            Print("Buffer UGen: no buffer data\n");                                                                    \
            this->m_failedBufNum = fbufnum;                                                                            \
        }                                                                                                              \
        ClearUnitOutputs(this, nSamples);                                                                          \
        return;                                                                                                        \
    } else {                                                                                                           \
        if (bufChannels != numOutputs) {                                                                               \
            if (this->mWorld->mVerbosity > -1 && !this->mDone && (this->m_failedBufNum != fbufnum)) {                  \
                Print("Buffer UGen channel mismatch: expected %i, yet buffer has %i channels\n", numOutputs,           \
                      bufChannels);                                                                                    \
                this->m_failedBufNum = fbufnum;                                                                        \
            }                                                                                                          \
        }                                                                                                              \
    }

JBufferSender::JBufferSender() {
    mCalcFunc = make_calc_function<JBufferSender, &JBufferSender::next>();
    type = jevent::JBufferSender;
    // init();
    // next(1);
    ClearUnitOutputs(this, 1);
}

void JBufferSender::next(int nSamples) {
    if(!checkTrigger(nSamples)){
      return;
    }

    float fbufnum = in(0)[0]; // From PlayBuf cpp
    if (fbufnum != m_fbufnum) {
        uint32 bufnum = (int)fbufnum;
        World* world = mWorld;
        if (bufnum >= world->mNumSndBufs)
            bufnum = 0;
        m_fbufnum = fbufnum;
        m_buf = world->mSndBufs + bufnum;
    }
    const SndBuf* buf = m_buf;
    ACQUIRE_SNDBUF_SHARED(buf);

    const float* bufData __attribute__((__unused__)) = buf->data;
    uint32 bufChannels __attribute__((__unused__)) = buf->channels;
    uint32 bufSamples __attribute__((__unused__)) = buf->samples;
    uint32 bufFrames = buf->frames;
    // int mask __attribute__((__unused__)) = buf->mask;
    // int guardFrame __attribute__((__unused__)) = bufFrames - 2;

    int numOutputs = mNumOutputs;

    if(bufFrames > 2000 || bufFrames <= 0){
      cout << "Buffer > 2000 frames or 0 frames, not supported" << endl;
      return;
    }

    CHECK_BUFFER_DATA;

    float targetID = in(2)[0];
    float targetSubID = in(3)[0];

    float msg[bufFrames+2];
    msg[0] = targetID;
    msg[1] = targetSubID;
    memcpy(msg+2, bufData, bufFrames);
    SendNodeReply(&(this->mParent->mNode), 0, "/buffer", bufFrames+2, msg);

    RELEASE_SNDBUF_SHARED(buf);
}



} // namespace JBufferSender

PluginLoad(JBufferSenderUGens) {
    // Plugin magic
    ft = inTable;
    registerUnit<JBufferSender::JBufferSender>(ft, "JBufferSender", false);
}
