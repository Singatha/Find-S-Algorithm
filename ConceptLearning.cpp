#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>

/*
 * Author: Xhanti Singatha
 * Student Number: SNGXHA002
 * 
*/
using namespace std;

vector<string> split_string(std::string str){
   int len = str.size();
   vector<string> data;
               
   std::string str1 = "";
   std::string item = "";
               
   int counter = 0;
   for (int i = 0; i < len; i++){
      item = str.at(i);
      if (item.compare(" ") == 0){
         data.push_back(str1);
         str1 = "";
         counter++;
      }
                   
      else if (counter == 7){
         data.push_back(str.substr(i,len));
         break;
      }
                   
      else {
         str1 += item;
      }
                   
   }
               
   return data;
               
}

vector<string> target_concept(std::string filename){
   vector<string> hypothesis = {"0","0","0","0","0","0"};
   vector<string> temp;
               
   ifstream input;
   input.open(filename.c_str());
               
   std::string line;
    
   int counter = 0;
   while (!input.eof()){
      getline(input, line);
      temp = split_string(line);
      if (counter == 0){
         for (int i = 0; i < hypothesis.size(); i++){
            if (i+1 != hypothesis.size()){
               hypothesis[i] = temp[i+1];
            }
                 
            else {
               hypothesis[i] = temp[temp.size()-2];
            }
         }
         counter++;
      }
          
      else {
         for (int j = 0; j < hypothesis.size(); j++){
            if (j+1 != hypothesis.size()){
               if (hypothesis[j] == temp[j+1] && (temp[temp.size()-1].compare("Yes") == 0)){
                  continue;
               }
                    
               else if (hypothesis[j] != temp[j+1] && (temp[temp.size()-1].compare("Yes") == 0)){
                  hypothesis[j] = "?";
               }
            }
                 
            else {
               if (hypothesis[j] == temp[temp.size()-2] && (temp[temp.size()-1].compare("Yes") == 0)){
                  continue;
               }
                    
               else if (hypothesis[j] != temp[temp.size()-2] && (temp[temp.size()-1].compare("Yes") == 0)){
                  hypothesis[j] = "?";
               }
            }
         }
      } 
          
   }
   input.close();
   return hypothesis;
}

int main() {
   
   cout << "Mitchell Example" << "\n";
   vector<string> target_hypothesis1 = target_concept("training_examples.txt");
   cout << "<";
   for (int k = 0; k < target_hypothesis1.size(); k++){
       if (k == (target_hypothesis1.size()-1)){ 
          cout << target_hypothesis1[k];
       }
       
       else {
          cout << target_hypothesis1[k] << ", ";
       }
   }
   cout << ">" << "\n";
   
    
   return 0; 
}
