#include <iostream>
#include <fstream>
#include <string>

using namespace std;


int main(int argc,char **argv) {

  ifstream seqAf = ifstream(argv[1]);
  ifstream seqBf = ifstream(argv[2]);

  string seqA;
  string seqB;

  for(;!seqAf.eof();) {char c = seqAf.get(); if(!seqAf.eof()) seqA += c;}
  for(;!seqBf.eof();) {char c = seqBf.get(); if(!seqBf.eof()) seqB += c;}

  //cout << "seqA: " << seqA << endl;
  //cout << "seqB: " << seqB << endl;

  cout << "Load Complete" << endl;

  for(int n=32;n>=5;n--) {
    cout << "Processing substring length: " << n << endl;

    bool found=false;
    int count=0;
    for(int i=0;i<(seqA.size()-n);i++) {
      string search = seqA.substr(i,n);

      if(seqB.find(search) != string::npos) {found=true; cout << "Found: " << search << endl; count++;}
    }
    cout << endl <<  "Len " << n;
    if(found == false) cout << " found 0" << endl; else cout << " found " << count << endl;
    
  }
}
