
#include "perceptron.cpp"
#include <iostream>
using namespace std;
int main(int argc, char ** argv){
    
    int numPerceptrons = 5; //user defined
    int inputLength = 2;
    vector<float> inputs = {1,1,1,0,0,1,0,0}; //this has been flattened, 2 values represent the inputs to a single perceptron
    vector<float> labels = {0,1,1,0};
    vector<float> outputs(numPerceptrons, 0.0);
    float bias = 0;
    float result = 0;

    vector<perceptron> hiddenLayer1;
    vector<perceptron> outputLayer;

    for(int i = 0; i < numPerceptrons; i++){
        hiddenLayer1.push_back(perceptron(0.5, labels, inputLength));
    }

    outputLayer.push_back(perceptron(0.5, labels, numPerceptrons)); //input length = number of perceptrons in previous layer

    int count = 0;
    for(int i = 0; i < inputs.size(); i+=2){
        vector<float> in = {inputs[i], inputs[i+1]};
     
        for(int j = 0; j < numPerceptrons; j++){
            hiddenLayer1[j].feedForward(in);
            outputs[j] = hiddenLayer1[j].getOutput(); //returns output of perceptron after feed forward
        }
        outputLayer[0].feedForward(outputs); //outputs of 1st hidden layer are inputs to output layer
     
        //we must update the weights at this point before passing inthe next input
        outputLayer[0].updateWeights(labels[count], outputs);
        for(int j = 0; j < numPerceptrons; j++){
            hiddenLayer1[j].updateWeights(labels[count], in);
        }
        count +=1;
    }

    result = outputLayer[0].getOutput();
    cout <<endl<< result<<endl;
    

    

    



    


    
   




    return 0;
}