

#include "perceptron.cpp"
#include <iostream>
#include <fstream>
using namespace std;
int main(int argc, char ** argv){
    
    int inputLength = 3;
    vector<float> inputs = {1.30, 2.70, 0.80}; //input vector x
    //input layer
    perceptron p11(0,0.8,0,inputLength);
    perceptron p12(0,0.8,0,inputLength);
    perceptron p13(0,0.8,0, inputLength);

    //Hidden layer
    perceptron p21(0, 0.8, 0.1, inputLength);
    perceptron p22(0, 0.8, -0.3, inputLength);
    p21.setWeights({0.1, 0.2, 0.5});
    p22.setWeights({-0.4, 1.0, -0.6});
    
    //output layer
    perceptron p31(0, 0.8, 0, inputLength-1);

    vector<float> outputLayer1(inputLength,0);
    vector<float> outputLayer2(inputLength-1,0);
    float output;

    p31.setWeights({0.8, 1.0});
    p31.setBias(-0.3);

    const int MAX_ITERATIONS = 1000;

    for(int i = 0; i< MAX_ITERATIONS; i++){
        cout << output<< endl;
        p11.feedForward(inputs, 0, true);
        p12.feedForward(inputs, 1, true);
        p13.feedForward(inputs, 1, true);

        outputLayer1[0] = p11.thresholdActivation(1, true, inputs);
        outputLayer1[1] = p12.thresholdActivation(1, true, inputs);
        outputLayer1[2] = p13.thresholdActivation(1, true, inputs);

        // outputLayer1[0] = p11.sigmoidActivation();
        // outputLayer1[1] = p12.sigmoidActivation();
        // outputLayer1[2] = p13.sigmoidActivation();

        p21.feedForward(outputLayer1, 1, true); //label won't effect things
        p22.feedForward(outputLayer1, 1, true); //label won't effect things

        outputLayer2[0] = p21.sigmoidActivation();
        outputLayer2[1] = p22.sigmoidActivation();

        p31.feedForward(outputLayer2, 0.36, true);
        output = p31.sigmoidActivation();
        
        if (output == float(0.36)){
            cout << "FINISHED with output: "<<output<<" after "<<i<<" iterations."<<endl;
            break;
        }
        else{
            // p31.updateWeights(0.36, outputLayer2, output);
        }
        //hidden and output layers use sigmoid activation
    }

   cout << "output: "<<output<<endl;
   cout << "Output of hidden layer neuron 1: "<<outputLayer2[0]<<endl;
   cout << "Output of hidden layer neuron 2: "<<outputLayer2[1]<<endl;

   


return 0;
}