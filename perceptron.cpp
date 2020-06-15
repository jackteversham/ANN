
#include "perceptron.h"
#include <vector>
#include <iostream>

using namespace std;

// float bias=0.0; //input bias
// int inputLength; //input vector
// std::vector<float> labels;
// float weight1;
// float weight2;
// float sum=0.0;

// float threshold = 0.0;
// float learningRate = 0.8;

 
perceptron::perceptron(float w1, float w2, float threshold, float learningRate):  weight1(w1), weight2(w2), threshold(threshold), learningRate(learningRate){
}

float perceptron::thresholdActivation(int label, bool train, std::vector<float> inputs){

    //cout<< inputs[0]<<" "<<inputs[1]<<" with label "<< label<<endl;
    //cout<< "SUM "<<sum<<endl;
    
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
           // output = 0.0; 
            updateWeights(label, inputs, 0); //pass in an output of 0
        }

       // output = 0.0;
        return 0; }
    //cout << bias<< " is the bias"<<endl;
    //cout << weights[i]<<" "<<endl;

   // sum=0;
    } 
 
void perceptron::feedForward(vector<float> inputs, int label, bool train){
    //sum += bias;
    sum = weight1*inputs[0] + weight2*inputs[1];
    // for(int i = 0; i< inputs.size(); i++){
    //     sum+=weights[i]*inputs[i]; //dot product stored in sum
    // }   
  //perceptron::thresholdActivation(threshold, label, train, inputs); //determine output

}

void perceptron::updateWeights(float label, vector<float> inputs, float o){
    //bias = bias + learningRate*(label-output)*1; //for bias term where 'input' is 1
    //cout << bias<< " is the bias"<<endl;
 //cout << "Label: "<< label<< " output: "<<output<<endl;
    //cout << "Delta 1: " <<learningRate*(label-o)*inputs[0]<< " Delta 2: "<< learningRate*(label-o)*inputs[1]<<endl; 
   // cout<< "Weights before: "<< weight1 << "  "<<weight2<<endl;
    weight1 += learningRate*(label-o)*inputs[0];
    weight2 += learningRate*(label-o)*inputs[1];
   // cout<< "Weights after: "<< weight1 << "  "<<weight2<<endl;

}

float perceptron::getOutput(){
    return output;
}
float perceptron::getBias(){
    return bias;
}

void perceptron::setBias(float b){
    bias = b;

}


