
#include "perceptron.cpp"
#include <iostream>
#include <fstream>
using namespace std;
int main(int argc, char ** argv){
    
    int numPerceptrons = 2; //user defined
    int inputLength = 2; //length of input vector
    vector<float> inputs = {0,0,1,0,0,1,1,1}; //this has been flattened, 2 values represent the inputs to a single perceptron
    vector<float> labels = {0,1,1,0}; //XOR
    vector<float> labels1 = {0,1,1,1}; //OR
    vector<float> labels3 = {0,0,0,1}; //AND

    vector<float> outputs(numPerceptrons, 0.0);
   
    vector<float> biases;
    vector<perceptron> hiddenLayer1;


    perceptron p1(1, 0.8,0,inputLength);
    perceptron p2(0,0.8,0, inputLength);
    perceptron p3(0,0.8,0, inputLength);

 //TRAIN:
 ofstream out("Output.txt", true);
 out << "\nInput:   Hidden layer output:  Training Label:"<<endl;
 float output;
 int count = 0;
 for(int k = 0; k< 5; k++){
     cout <<"\n-----Training generation "<<k<<"-----"<<endl;
    count = 0;
    for(int i = 0; i < inputs.size(); i+=2){
        vector<float> in = {inputs[i], inputs[i+1]}; //iterate through the inputs, 2 at a time
           out<<in[0] << " "<<in[1]<<"\t\t\t\t\t\t\t";
        
                 p1.feedForward(in, labels3[count], true);
                 outputs[0] = p1.thresholdActivation(labels3[count], true, in);
           
                p2.feedForward(in, labels1[count], true);
                outputs[1] = p2.thresholdActivation(labels1[count], true, in);

                out <<  outputs[0]<< " "<<outputs[1]<<"\t\t\t\t\t\t\t\t";
    
           p3.feedForward(outputs, labels[count], true); //outputs of 1st hidden layer are inputs to output layer
          output =  p3.thresholdActivation(labels[count], true, outputs);
          out << "\t"<< output<<endl;
           count +=1;
    }
    
    }
    out.close();
    cout << endl<<endl;


    //predict new inputs:
    count = 0;
    for(int i = 0; i < inputs.size(); i+=2){
        vector<float> in = {inputs[i], inputs[i+1]}; //iterate through the inputs, 2 at a time
       cout << "Input: "<<in[0] << " "<<in[1]<<endl;
        
                 p1.feedForward(in,labels3[count], true); //feed perceptron 1 forward
                 outputs[0] = p1.thresholdActivation(labels3[count], false, in);

                p2.feedForward(in, labels1[count], true); ////feed perceptron 2 forward
                outputs[1] = p2.thresholdActivation(labels1[count], false, in); 
        
        p3.feedForward(outputs,labels[count], false); //outputs of 1st hidden layer are inputs to output layer
        float res = p3.thresholdActivation(labels[count], false, in);
        count +=1;
        cout << "Prediction: "<< res<<endl;
    }

    
    return 0;
}