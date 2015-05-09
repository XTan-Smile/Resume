/* This is a c++ version of resume of Xiao Tan
 * 
 * class PersonInfo
 *   private class School
 *   private clsdd Experience
 * 
 * Last modified: May 8, 2015
 * 
 * (c) Margaret Tan, Duke University
 */
#ifndef __RESUME_H__
#define __RESUME_H__

#include <iostream>
#include <string>
#include <vector>
#include "outputColor.h"

using std::string;
using std::vector;

class PersonInfo {
private:
  string name;
  string email;
  string phone;
  string language;

  class School {
  private:
      string schools[3];
      string locations[3];
      string major[3];
      string gradDate[3];
  public:
    School() {
    schools[2] = "Duke University (Duke)";
    schools[1] = "Chinese Academy of Sciences (CAS)";
    schools[0] = "Wuhan University of Technology (WUT)";

    locations[2] = "Durham NC, USA";
    locations[1] = "Beijing, China";
    locations[0] = "Wuhan, China";

    major[2] = "Master of Science in Electrical and Computer Engineering";
    major[1] = "Master of Engineering in Microelectronics and Solid State Electronics";
    major[0] = "Bachelor of Engineering in Communication Engineering (with extinct)";

    gradDate[2] = "May 2016";
    gradDate[1] = "July 2014";
    gradDate[0] = "June 2011";
  }
    // list attended schools
    void printSchool(const int num = 3) {
      // bold yellow
      std::cout << CYAN;
      std::cout << "EDUCATION" << std::endl;
      std::cout << RESET;      
      for (int i = num-1; i >= 0; i--) {
        std::cout << YELLOW;
        std::cout << schools[i] << ", " 
  		  << locations[i] << "    " 
  		  << gradDate[i] << std::endl;
        std::cout << RESET;
        std::cout << " - " << major[i] << std::endl;
      }
      std::cout << std::endl;
    }

    ~School() {}
  };

  class Experience {
  private:
    string exper[5];
    string timePeriod[5];
    string locations[5];
    vector<vector<string> > items;
  public:
    Experience() {
      exper[4] = "Divorce Rate Analysis";
      exper[3] = "Amazon Picking Challenge";
      exper[2] = "Machine Learning Algorithm Design";
      exper[1] = "Electrocardiogram (ECG) Signal Detection on Android Platform";
      exper[0] = "Electrocardiogram (ECG) Signal Analysis";

      timePeriod[4] = "March 2015";
      timePeriod[3] = "Jan 2015 - May 2015";
      timePeriod[2] = "Sept 2014 - May 2015";
      timePeriod[1] = "Feb 2014 - April 2014";
      timePeriod[0] = "Aug 2012 - Nov 2013";

      locations[4] = "Duke";
      locations[3] = "Duke";
      locations[2] = "Duke";
      locations[1] = "CAS";
      locations[0] = "CAS";

      items.resize(5);
      items[4].push_back("Adopt probit regression to analyze relationship between age difference and divorce rate");
      items[4].push_back("Implement a Gibbs sampling to approximate the joint distribution of all parameters");
      items[4].push_back("Analysis confidence interval for parameters");

      items[3].push_back("Implement object perception by iterative closest point (ICP) in Python");
      items[3].push_back("Design grasps for robot grippers");
      items[3].push_back("Implement collision-free path of the robot arms in simulation in Python");

      items[2].push_back("Design a revised algorithm for metric learning method of large margin nearest neighbor (LMNN)");
      items[2].push_back("Implement a speed-up version of LMNN");
      items[2].push_back("Implement LMNN in robot motion planning in Matlab and C++");

      items[1].push_back("Develop the user interface on Android cellphone to enhance customer experience");
      items[1].push_back("Implement real-time signal analysis on Android cellphone");

      items[0].push_back("Propose an empirical mode decomposition (EMD) based algorithm to implement noise removal");
      items[0].push_back("Propose an EMD-based algorithm to implement the signal feature extraction");
      items[0].push_back("Adopt a fitting method to evaluate the baseline wander in real time");
      items[0].push_back("Publish two papers");
    }
    void printExperience(const int num = 5) {
      // yellow
      std::cout << CYAN;
      std::cout << "EXPERIENCE" << std::endl;
      std::cout << RESET;
      for (int i = num-1; i >= 0; i--) {
        std::cout << YELLOW;
        std::cout << exper[i] << ", " 
  		  << locations[i] << "    " 
  		  << timePeriod[i] << std::endl;
        std::cout << RESET;
        for (int item = 0; item < items[i].size(); item++) {
	  std::cout << " - " << items[i][item] << std::endl;
        }
        std::cout << std::endl;
      }
    }
    ~Experience() {}
  };

  School attendedSchool;
  Experience experience;

public:
  PersonInfo() {
    name = "Xiao (Margaret) Tan";
    email = "Email: xiao.tan@duke.edu";
    language = "Programming language: C/C++, Java, Python, Matlab, R, Verilog";
  }
  void printPersonInfo() {
    std::cout << std::endl;
    std::cout << CYAN;
    std::cout << "INFOMATION" << std::endl;
    std::cout << RESET;
    std::cout << name << std::endl;
    std::cout << email << std::endl;
    std::cout << language << "\n" << std::endl;
  }
  void printEducation() {
    attendedSchool.printSchool();
  }
  void printExperience() {
    experience.printExperience();
  }
  ~PersonInfo() {}
};

#endif
