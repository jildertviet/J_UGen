// PluginJBufferSender.cpp
// Jildert Viet (info@jildertviet.com)

#include "SC_PlugIn.hpp"
#include "JBufferSender.hpp"
#include "scsynthsend.h"
#include "SC_Node.h"
#include "SC_ReplyImpl.hpp"
#include "SC_HiddenWorld.h"

namespace JBufferSender {

#define GET_BUF_SHARED_CUSTOM \
float fbufnum = ((mInBuf[0])[0]);    ;                                                                                       \
  if (fbufnum < 0.f) {                                                                                               \
      fbufnum = 0.f; \
  } \
  if (fbufnum != m_fbufnum) {                                                                                  \
      uint32 bufnum = (int)fbufnum;                                                                                  \
      World* world = mWorld;                                                                                   \
      if (bufnum >= world->mNumSndBufs) {                                                                            \
          int localBufNum = bufnum - world->mNumSndBufs;                                                             \
          Graph* parent = mParent;                                                                             \
          if (localBufNum <= parent->localBufNum) {                                                                  \
              m_buf = parent->mLocalSndBufs + localBufNum;                                                     \
          } else {                                                                                                   \
              bufnum = 0;                                                                                            \
              m_buf = world->mSndBufs + bufnum;                                                                \
          }                                                                                                          \
      } else {                                                                                                       \
          m_buf = world->mSndBufs + bufnum;                                                                    \
      }                                                                                                              \
      m_fbufnum = fbufnum;                                                                                     \
  }                                                                                                                  \
  const SndBuf* buf = m_buf;                                                                                   \
  LOCK_SNDBUF_SHARED(buf);                                                                                           \
  const float* bufData __attribute__((__unused__)) = buf->data;                                                      \
  uint32 bufChannels __attribute__((__unused__)) = buf->channels;                                                    \
  uint32 bufSamples __attribute__((__unused__)) = buf->samples;                                                      \
  uint32 bufFrames = buf->frames;                                                                                    \
  int mask __attribute__((__unused__)) = buf->mask;                                                                  \
  int guardFrame __attribute__((__unused__)) = bufFrames - 2;

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
    targetID = in(2)[0];
    targetSubID = in(3)[0];

    ClearUnitOutputs(this, 1);

    cout << "End of const" << endl;
}

void JBufferSender::next(int nSamples) {
  if(!checkTrigger(nSamples)){
      return;
  }
  GET_BUF_SHARED_CUSTOM
  int numOutputs = mNumOutputs;
  CHECK_BUFFER_DATA

  if(bufFrames > 2000 || bufFrames <= 0){
    cout << "Buffer > 2000 frames or 0 frames, not supported" << endl;
    return;
  }

  small_scpacket packet;
  packet.adds("/buffer");
  packet.maketags(4);
  packet.addtag(',');
  packet.addtag('f');
  packet.addf(targetID);
  packet.addtag('f');
  packet.addf(targetSubID);
  packet.addtag('b');
  packet.addb((unsigned char*)bufData, bufFrames * sizeof(float));

  for (auto addr : *mWorld->hw->mUsers)
      SendReply(&addr, packet.data(), packet.size());
}



} // namespace JBufferSender

PluginLoad(JBufferSenderUGens) {
    // Plugin magic
    ft = inTable;
    registerUnit<JBufferSender::JBufferSender>(ft, "JBufferSender", false);
}
