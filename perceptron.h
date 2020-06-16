
#include <vector>

class perceptron {

float bias; //input bias
float sum;
float threshold;
float learningRate;
int inputLength;
std::vector<float> weights;

public:
    perceptron(float threshold, float learningRate, float bias, int inputLength);

    float thresholdActivation(const int label, bool train, std::vector<float> inputs);
    void feedForward(std::vector<float> inputs, const float label, bool train);
    void updateWeights(const float label, std::vector<float> inputs, float o);
    float getBias();
    void setBias(float b);
    void setWeights(std::vector<float> w);
    float sigmoidActivation();
   
};