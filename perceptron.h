
#include <vector>

class perceptron {

float bias; //input bias
int inputLength; //input vector
std::vector<float> labels;
std::vector<float> weights;
float sum;
float output;

public:
    perceptron(float bias, std::vector<float> labels, int inputLength);

    void thresholdActivation();
    void feedForward(std::vector<float> inputs);
    void updateWeights(int label, std::vector<float> inputs);
    float getOutput();
    float predict(std::vector<float> inputs);
};