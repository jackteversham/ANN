
#include "perceptron.h"
#include <vector>
#include <iostream>

using namespace std;

float bias; //input bias
int inputLength; //input vector
std::vector<float> labels;
std::vector<float> weights;
float sum;
float output;
float learningRate = 0.08;

 
perceptron::perceptron(float bias, std::vector<float> labels, int inputLength):  bias(bias), labels(labels), inputLength(inputLength){
for(int i = 0; i < inputLength; i++){
    weights.push_back(0.5); //initilaise all weights to 0.5
}
}

void thresholdActivation(){
    if(sum>0) output = 1.0;
    output = 0.0;
    }

void feedForward(vector<float> inputs){
    cout << endl<<"HERE"<<endl;
    sum+= bias;
    for(int i = 0; i< inputs.size(); i++){
        sum+=weights[i]*inputs[i]; //dot product stored in sum
    }   
    thresholdActivation(); //determine output
}

void updateWeights(int label, vector<float> inputs){
    bias = bias + learningRate*(label-output); //for bias term where 'input' is 1
    for(int i = 0; i< inputs.size(); i++){
        weights[i] = weights[i] + learningRate*(label-output)*inputs[i];
    }
}

float getOutput(){
    return output;
}