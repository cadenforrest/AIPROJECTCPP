#ifndef CONCLUSION_H
#define CONCLUSION_H
#include "Variable-c_w424.h"
#include <vector>
using namespace std;


class Conclusion{
public:
  void setRuleList(std::vector<int> list);
  std::vector<int> getRuleList();
  void setRuleAnswers(std::vector<bool> list); 
  std::vector<bool> getRuleAnswers();
  
  void setRuleNum(int n); //set rule number
  int getRuleNum();       //get rule number
  void setConclusion(string c); //set conclusion
  string getConclusion(); //get conclusion result

  void setTreatment(std::string usertreatment);
  std::string getTreatment();

private:
  std::vector<int> ruleList; // list of ints corresponding to our VariableList
  std::vector<bool> ruleAnswers;
  int ruleNum;
  string conclusion;
  string cancer;
  std::string treatment;
};

#endif /* CONCLUSION_H */