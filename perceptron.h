
#include <vector>

class perceptron {

float bias; //input bias
float sum;
float threshold;
float learningRate;
float weight1;
float weight2;
int inputLength;
std::vector<float> weights;

public:
    perceptron(float threshold, float learningRate, float bias, int inputLength);

    float thresholdActivation(int label, bool train, std::vector<float> inputs);
    void feedForward(std::vector<float> inputs, int label, bool train);
    void updateWeights(float label, std::vector<float> inputs, float o);
    float getBias();
    void setBias(float b);
    void setWeights(std::vector<float> w);
    float sigmoidActivation();
   
};