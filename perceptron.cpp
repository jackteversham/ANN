
#include "perceptron.h"
#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

perceptron::perceptron(float threshold, float learningRate, float bias, int inputLength): threshold(threshold), learningRate(learningRate), bias(bias), inputLength(inputLength){
    for(int i = 0; i < inputLength; i++){
        weights.push_back(1.0); 
    }
}

float perceptron::thresholdActivation(int label, bool train, std::vector<float> inputs){
    if(sum>threshold) {
        if(label != 1 && train == true){ //if the output is not what we expect and we are training
            //output = 1.0;
            updateWeights(label, inputs, 1); //parse in an output of 1
        }
        //output = 1.0;
        return 1;
        }
    else {
        if(label != 0 && train == true){
            updateWeights(label, inputs, 0); //pass in an output of 0
        }
        return 0; }
    } 
 
void perceptron::feedForward(vector<float> inputs, int label, bool train){
    sum = 0;
    sum += bias;
    for(int i = 0; i< inputs.size(); i++){
        sum += weights[i]*inputs[i];
    }

    //sum = weight1*inputs[0] + weight2*inputs[1];
}

void perceptron::updateWeights(float label, vector<float> inputs, float o){
    for(int i = 0; i< inputs.size(); i++){
        weights[i] += learningRate*(label-o)*inputs[i];
        
    }
   
    // weight1 += learningRate*(label-o)*inputs[0];
    // weight2 += learningRate*(label-o)*inputs[1];

}

float perceptron::sigmoidActivation(){
 
    return 1/(1+exp(-(sum)));
    

}


float perceptron::getBias(){
    return bias;
}

void perceptron::setBias(float b){
    bias = b;
}
void perceptron::setWeights(vector<float> w){
    weights = w;
}


