// PluginJBufferSender.hpp
// Jildert Viet (info@jildertviet.com)

#pragma once

#include "SC_PlugIn.hpp"
#include "SC_Reply.h"
#include "JEventBaseS.hpp"

namespace JBufferSender {

class JBufferSender : public JEventBaseS::JEventBaseS {
public:
    JBufferSender();
    // ~JBufferSender();

    double m_phase;
     float m_prevtrig;
     float m_fbufnum;
     float m_failedBufNum;
     SndBuf* m_buf;
     double sc_loop(Unit* unit, double in, double hi, int loop);
private:
    // Calc function
    void next(int nSamples);

    // Member variables
};

} // namespace JBufferSender
