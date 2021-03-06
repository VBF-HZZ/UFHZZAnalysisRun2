#ifndef HZZ4LPILEUP_H
#define HZZ4LPILEUP_H

//system includes
#include <memory>
#include <string>
#include <map>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <stdlib.h>
#include <cmath>
#include <iomanip>

#include "TROOT.h"
#include "TH1.h"
#include "TTree.h"
#include "TMath.h"
#include "TString.h"
#include "TLorentzVector.h"
#include "TLorentzRotation.h"

 // user include files 
 #include "FWCore/Framework/interface/Frameworkfwd.h"
 #include "FWCore/Framework/interface/EDAnalyzer.h"
 #include "FWCore/Framework/interface/Event.h"
 #include "FWCore/Framework/interface/MakerMacros.h"
 #include "FWCore/ParameterSet/interface/ParameterSet.h"
 #include "FWCore/ServiceRegistry/interface/Service.h"
 #include "CommonTools/UtilAlgos/interface/TFileService.h"


class HZZ4LPileUp
{

 public:

  HZZ4LPileUp();
  ~HZZ4LPileUp();

  void fillPUWeights();
  double getPUWeight(double nInteraction, std::string version);
  double weightTruePileupV07toIchep52X(double input);
  double weightTruePileupV07toHcp53X(double input);
  double weightTruePileupV10toIchep53X(double input);
  double weightTruePileupV10toHcp53X(double input);
  double weightTruePileupMoriond53X(double input);
  double weightTruePileupLegacy53X(double input);
  double weightTruePileupFall15_74X(double input);
  double weightTruePileupFall15_76X(double input);
  double weightTrue2011(double input);
  double weightTrue2011to2012(double input);

 private:

};


#endif


#ifndef HZZ4LPILEUP_CC
#define HZZ4LPILEUP_CC

HZZ4LPileUp::HZZ4LPileUp()
{

  //declarations

}


HZZ4LPileUp::~HZZ4LPileUp()
{

  //destructor ---do nothing

}

double HZZ4LPileUp::getPUWeight(double nInteraction, std::string version)
{
  
  using namespace std;

  if(version == "ICHEP52X") return weightTruePileupV07toIchep52X(nInteraction);
  else if(version == "ICHEP53X") return weightTruePileupV10toIchep53X(nInteraction);
  else if(version == "HCP52X") return weightTruePileupV07toHcp53X(nInteraction);
  else if(version == "HCP53X") return weightTruePileupV10toHcp53X(nInteraction);
  else if(version == "Moriond53X") return weightTruePileupMoriond53X(nInteraction);
  else if(version == "Legacy53X") return weightTruePileupLegacy53X(nInteraction);
  else if(version == "Fall15_74X") return weightTruePileupFall15_74X(nInteraction);
  else if(version == "Fall15_76X") return weightTruePileupFall15_76X(nInteraction);
  else{
    std::string msg;
    msg = "HZZ4LPileUp::getPUWeight() unknown version\n";
    msg += "Possibilities are ICHEP52X, ICHEP53X, HCP52X, HCP53X, Moriond53X, Legacy53X, Fall15_74X, Fall15_76X";
    cout << msg << endl;
  }  
  
  return 0;

}


double HZZ4LPileUp::weightTruePileupV07toIchep52X(double input){
  double w[60] = {
    2.59113e-07,
    1.77107e-05,
    0.0263017,
    1.66396,
    0.16421,
    0.754166,
    2.84622,
    5.57103,
    8.66558,
    11.5716,
    11.8712,
    12.8102,
    10.3421,
    8.91019,
    7.614,
    6.10397,
    4.52745,
    3.26031,
    2.39558,
    1.83297,
    1.47821,
    1.26728,
    1.14716,
    1.06707,
    0.98066,
    0.860877,
    0.708281,
    0.539789,
    0.37652,
    0.237298,
    0.1338,
    0.0671236,
    0.0299236,
    0.0118723,
    0.00420968,
    0.00134235,
    0.000389563,
    0.000104892,
    2.69214e-05,
    6.79674e-06,
    1.73307e-06,
    4.52553e-07,
    1.21124e-07,
    3.29924e-08,
    9.10616e-09,
    2.53998e-09,
    7.16146e-10,
    2.03786e-10,
    5.84308e-11,
    1.68192e-11,
    4.8434e-12,
    1.38959e-12,
    3.96112e-13,
    1.11358e-13,
    3.17245e-14,
    5.34916e-15,
    0,
    0,
    0,
    0};
  
  //return w[(int)floor(input+0.5)];
  return w[(int)floor(input)];
    
  /*   
        TH1F h("boh","boh",60,0.,60.); 
	 for(int k=0;k<60;k++){
	  h.SetBinContent(k+1,w[k]);
	   } 
	    return h.GetBinContent(h.FindBin(input));
  */
}


double HZZ4LPileUp::weightTruePileupV07toHcp53X(double input){
  double w[60] = {
    0.0447136,     
    0.11785,       
    0.23825,
    1.08447,
    0.102575,
    0.454605,
    1.79761,
    4.00271,
    6.83281,
    9.83701,
    10.7966,
    12.2356,
    10.0247,
    8.49395,
    7.1125,
    5.69527,
    4.31256,
    3.19305,
    2.42035,
    1.91666,
    1.58485,
    1.36297,
    1.21166,
    1.09466,
    0.978941,
    0.84653,
    0.699235,
    0.548996,
    0.408673,
    0.288194,
    0.193367,
    0.124653,
    0.0781124,
    0.0479268,
    0.0287763,
    0.0167744,
    0.00941834,
    0.00507877,
    0.00264364,
    0.00134612,
    0.000682678,
    0.000351412,
    0.0001864,
    0.00010259,
    5.87818e-05,
    3.5033e-05,
    2.17116e-05,
    1.39777e-05,
    9.36123e-06,
    6.53328e-06,
    4.76598e-06,
    3.64139e-06,
    2.92018e-06,
    2.4602e-06,
    2.17291e-06,
    2.01107e-06,
    1.94392e-06,
    1.9598e-06,
    2.0583e-06,
    2.24895e-06};

  return w[(int)floor(input)];
}


double HZZ4LPileUp::weightTruePileupV10toIchep53X(double input){
  double w[60] = {
    2.35693e-06,
    7.51928e-05,
    0.0263529,
    0.609947,
    0.737917,
    1.29365,
    0.994503,
    0.85454,
    1.01559,
    1.33243,
    1.72454,
    2.01264,
    2.00573,
    1.80333,
    1.56328,
    1.37452,
    1.24753,
    1.16481,
    1.11738,
    1.09701,
    1.08843,
    1.08796,
    1.09768,
    1.10763,
    1.09328,
    1.0339,
    0.92408,
    0.771537,
    0.59283,
    0.41266,
    0.256892,
    0.14188,
    0.0692543,
    0.029902,
    0.0114564,
    0.00391383,
    0.00120625,
    0.000341485,
    9.09127e-05,
    2.34008e-05,
    5.95438e-06,
    1.5122e-06,
    3.82094e-07,
    9.51794e-08,
    2.32205e-08,
    5.51698e-09,
    1.27267e-09,
    2.84346e-10,
    6.12799e-11,
    1.26731e-11,
    2.50309e-12,
    4.69797e-13,
    8.35153e-14,
    1.39452e-14,
    2.24718e-15,
    2.03841e-16,
    0,
    0,
    0,
    0};

  return w[(int)floor(input)];
}



double HZZ4LPileUp::weightTruePileupV10toHcp53X(double input){
  double w[60] = {
    0.409409,
    0.527276,
    0.39328,
    0.507892,
    0.48029,
    0.787701,
    0.632356,
    0.618033,
    0.806089,
    1.14018,
    1.5788,
    1.93507,
    1.957,
    1.73004,
    1.46737,
    1.28278,
    1.18189,
    1.13388,
    1.12578,
    1.14415,
    1.16048,
    1.1618,
    1.15318,
    1.13405,
    1.09239,
    1.01915,
    0.914837,
    0.786744,
    0.644879,
    0.502039,
    0.371688,
    0.263586,
    0.18067,
    0.120472,
    0.0780184,
    0.0486113,
    0.0289039,
    0.0163367,
    0.00879674,
    0.00456046,
    0.0023098,
    0.00115977,
    0.000583207,
    0.000294815,
    0.000149865,
    7.62892e-05,
    3.87537e-05,
    1.96105e-05,
    9.87744e-06,
    4.95418e-06,
    2.47913e-06,
    1.23919e-06,
    6.19751e-07,
    3.10125e-07,
    1.54934e-07,
    7.71425e-08,
    3.8182e-08,
    1.87455e-08,
    9.10765e-09,
    9.19802e-09};
  return w[(int)floor(input)];
}



double HZZ4LPileUp::weightTruePileupMoriond53X(double input){

  if(input > 60) return 1;
  /*
MINE
double w[60] = {
0.0267475,
0.071672,
0.197791,
0.73539,
0.0675561,
0.332503,
1.2733,
2.80297,
5.05402,
7.87603,
9.02517,
10.6565,
8.93995,
7.67852,
6.4791,
5.18187,
3.9396,
2.96556,
2.30097,
1.86549,
1.57628,
1.38144,
1.24622,
1.13968,
1.03593,
0.920125,
0.792323,
0.660149,
0.531762,
0.413859,
0.311682,
0.227698,
0.161568,
0.111231,
0.0741514,
0.047761,
0.0297469,
0.0179901,
0.0106459,
0.00623484,
0.0036649,
0.00220043,
0.00137754,
0.000917559,
0.00066385,
0.000528797,
0.000466423,
0.000453589,
0.000482511,
0.000556121,
0.000689284,
0.000912677,
0.0012855,
0.00191962,
0.00302559,
0.00502603,
0.00876846,
0.0160454,
0.0307618,
0.0616947};
  */

  //Emanuele
  double  w[60] = {
    0.246449,
    0.319829,
    0.332274,
    0.378928,
    0.324225,
    0.571133,
    0.445285,
    0.431313,
    0.594374,
    0.911241,
    1.3186,
    1.68813,
    1.75232,
    1.56782,
    1.33493,
    1.164,
    1.07775,
    1.0522,
    1.06937,
    1.11167,
    1.15048,
    1.17265,
    1.18182,
    1.17864,
    1.15641,
    1.11001,
    1.03986,
    0.949639,
    0.842786,
    0.724516,
    0.602474,
    0.484649,
    0.37676,
    0.2826,
    0.203926,
    0.141043,
    0.093534,
    0.059644,
    0.0367331,
    0.0220279,
    0.0129938,
    0.00763653,
    0.00454065,
    0.00277822,
    0.00178079,
    0.00120881,
    0.000871767,
    0.000664965,
    0.000531206,
    0.000439634,
    0.000373677,
    0.000323738,
    0.000284508,
    0.000252544,
    0.000225388,
    0.000201689,
    0.000180452,
    0.000161084,
    0.000143136,
    0.000265881
    
  };
  


 return w[(int)floor(input)];

}



double HZZ4LPileUp::weightTruePileupLegacy53X(double input){

  if(input > 60) return 1;

  double w[70] = {
    0.242421,
    0.314567,
    0.328551,
    0.341325,
    0.311977,
    0.560934,
    0.443155,
    0.444942,
    0.625725,
    0.940482,
    1.33114,
    1.67986,
    1.7303,
    1.54809,
    1.32353,
    1.15668,
    1.07105,
    1.04548,
    1.06319,
    1.10733,
    1.14954,
    1.17563,
    1.188,
    1.18718,
    1.16671,
    1.121,
    1.04977,
    0.956974,
    0.84729,
    0.727003,
    0.603974,
    0.485796,
    0.377733,
    0.283343,
    0.204364,
    0.14118,
    0.0934506,
    0.059445,
    0.0365081,
    0.0218306,
    0.012844,
    0.00753269,
    0.00447223,
    0.00273386,
    0.00175157,
    0.00118879,
    0.000857334,
    0.000653996,
    0.000522478,
    0.000432433,
    0.000367567,
    0.000318451,
    0.000279865,
    0.000248423,
    0.000221711,
    0.000198398,
    0.000177509,
    0.000158456,
    0.000140801,
    0.000261544,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    1};
  


 return w[(int)floor(input)];

}


double HZZ4LPileUp::weightTruePileupFall15_74X(double input){

  if(input > 50) return 1.0;

  double w[50] = {      
      126.337,
      153.753,
      108.762,
      32.4929,
      17.9949,
      3.34053,
      1.97929,
      2.5719,
      3.42167,
      3.33126,
      3.00845,
      2.65362,
      2.08864,
      1.39939,
      0.792047,
      0.386897,
      0.18109,
      0.0990121,
      0.0705014,
      0.0587098,
      0.0525807,
      0.0503863,
      0.051229,
      0.0538919,
      0.0574271,
      0.0613761,
      0.0657269,
      0.0706353,
      0.0757276,
      0.078729,
      0.0744712,
      0.0591124,
      0.038286,
      0.02139,
      0.0111463,
      0.0057112,
      0.00295235,
      0.00155243,
      0.000828797,
      0.000446272,
      0.000240566,
      0.000129006,
      6.85054e-05,
      3.59166e-05,
      1.85598e-05,
      9.44456e-06,
      1.16979e-05,
      8.50725e-06,
      1.49492e-05,
      1.0154e-05
  };  
      
 return w[(int)floor(input)];

}


double HZZ4LPileUp::weightTruePileupFall15_76X(double input){

  if(input > 50) return 1.0;

  double w[50] = {      
      0.541295,
      0.681438,
      1.05914,
      1.36561,
      1.6259,
      1.94201,
      1.45237,
      1.28815,
      1.38652,
      1.36718,
      1.26216,
      1.16109,
      1.0583,
      0.904563,
      0.70166,
      0.495698,
      0.334522,
      0.244202,
      0.213501,
      0.185225,
      0.120628,
      0.0549179,
      0.0187476,
      0.00537602,
      0.00152633,
      0.000509498,
      0.000207473,
      9.64441e-05,
      4.84226e-05,
      2.53744e-05,
      1.35337e-05,
      7.22056e-06,
      3.81235e-06,
      1.97863e-06,
      1.00433e-06,
      4.96044e-07,
      2.36999e-07,
      1.08774e-07,
      4.75968e-08,
      1.9715e-08,
      7.68935e-09,
      2.81756e-09,
      9.70956e-10,
      3.15813e-10,
      9.74324e-11,
      2.86468e-11,
      8.06565e-12,
      2.1444e-12,
      7.12649e-13,
      0
  };

 return w[(int)floor(input)];

}


double HZZ4LPileUp::weightTrue2011(double input){
  if(input>50) 
    return 1;

    
  double w[50];


  w[0]= 0.212929;
  w[1]= 0.0208114;
  w[2]= 0.0584048;
  w[3]= 0.538898;
  w[4]= 1.357;
  w[5]= 1.49913;
  w[6]= 1.42247;
  w[7]= 1.35904;
  w[8]= 1.29946;
  w[9]= 1.27925;
  w[10]= 1.37845;
  w[11]= 1.71246;
  w[12]= 1.5291;
  w[13]= 1.35234;
  w[14]= 1.22215;
  w[15]= 1.0155;
  w[16]= 1.01137;
  w[17]= 0.395465;
  w[18]= 0.230984;
  w[19]= 0.109883;
  w[20]= 0.0433739;
  w[21]= 0.0111497;
  w[22]= 0.00408801;
  w[23]= 0.00115678;
  w[24]= 0.000365505;
  w[25]= 0.000112391;
  w[26]= 3.83894e-05;
  w[27]= 1.60651e-05;
  w[28]= 4.81412e-06;
  w[29]= 1.39717e-06;
  w[30]= 1.92368e-06;
  w[31]= 4.10748e-06;
  w[32]= 2.33157e-05;
  w[33]= 4.0181e-05;
  w[34]= 4.87786e-05;
  w[35]= 0.00194128;
  w[36]= 8.97414e-05;
  w[37]= 1;
  w[38]= 1;
  w[39]= 0.000162709;
  w[40]= 1;
  w[41]= 1;
  w[42]= 1;
  w[43]= 1;
  w[44]= 1;
  w[45]= 1;
  w[46]= 1;
  w[47]= 1;
  w[48]= 1;
  w[49]= 1;


  TH1F h("boh","boh",50,0.,50.);
 
  for(int k=0;k<50;k++){
    h.SetBinContent(k+1,w[k]);
  }
 
  return h.GetBinContent(h.FindBin(input));

}




double HZZ4LPileUp::weightTrue2011to2012(double input){
  if(input>50) 
    return 1;
    
  double w[50];

  w[0]= 0.000443112;
  w[1]= 0.000248044;
  w[2]= 0.000273111;
  w[3]= 0.00109511;
  w[4]= 0.00195699;
  w[5]= 0.00480746;
  w[6]= 0.027013;
  w[7]= 0.074795;
  w[8]= 0.166231;
  w[9]= 0.309545;
  w[10]= 0.577657;
  w[11]= 1.12488;
  w[12]= 1.36899;
  w[13]= 1.56925;
  w[14]= 1.89846;
  w[15]= 2.20828;
  w[16]= 3.14112;
  w[17]= 1.87712;
  w[18]= 1.97062;
  w[19]= 2.07067;
  w[20]= 2.17791;
  w[21]= 1.7176;
  w[22]= 2.10953;
  w[23]= 2.0805;
  w[24]= 2.29498;
  w[25]= 2.42189;
  w[26]= 2.80303;
  w[27]= 3.94091;
  w[28]= 3.67917;
  w[29]= 2.26081;
  w[30]= 2.99726;
  w[31]= 3.76553;
  w[32]= 11.285;
  w[33]= 10.2781;
  w[34]= 6.73407;
  w[35]= 148.182;
  w[36]= 3.88144;
  w[37]= 1;
  w[38]= 1;
  w[39]= 1.48128;
  w[40]= 1;
  w[41]= 1;
  w[42]= 1;
  w[43]= 1;
  w[44]= 1;
  w[45]= 1;
  w[46]= 1;
  w[47]= 1;
  w[48]= 1;
  w[49]= 1;


  TH1F h("boh","boh",50,0.,50.);
 
  for(int k=0;k<50;k++){
    h.SetBinContent(k+1,w[k]);
  }
 
  return h.GetBinContent(h.FindBin(input));

}


#endif
