
#include <vector>

class perceptron {

float bias; //input bias
int inputLength; //input vector
std::vector<float> labels;
std::vector<float> weights;
float sum;
float output=0;
float threshold;
float learningRate;
float weight1;
float weight2;

public:
    perceptron(float w1, float w2, float threshold, float learningRate);

    float thresholdActivation(int label, bool train, std::vector<float> inputs);
    void feedForward(std::vector<float> inputs, int label, bool train);
    void updateWeights(float label, std::vector<float> inputs, float o);
    float getOutput();
    float getBias();
    void setBias(float b);
   
};