#ifndef CONCLUSION_H
#define CONCLUSION_H
#include "Variable.h"
#include <vector>
using namespace std;


class Conclusion{
public:
  void setRuleList(std::vector<int> list);
  void setRuleNum(int n); //set rule number
  int getRuleNum();       //get rule number
  void setConclusion(string c); //set conclusion
  string getConclusion(); //get conclusion result
  // void setknowledgeBase(string c);
  // string getknowledgeBase();

private:
  std::vector<int> ruleList; // list of ints corresponding to our VariableList
  int ruleNum;
  string conclusion;
  string cancer;
};

#endif /* CONCLUSION_H */