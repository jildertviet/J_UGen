#define NUM_BUSSES  32

class JEvent{
public:
  JEvent(){};
  float* values[NUM_BUSSES];

  float loc[3] = {0,0,0};
  float size[3] = {100, 100, 100};
  float color[3] = {255, 255, 255};
  float brightness = 1;
  float layerID = 2; // 11

  float speed = 1;
  float direction[3] = {1, 0, 0};
  float bMove = true;
  float lineWidth = 1;
  float bFill = true;

  float rotation[3] = {0, 0, 0};
};
