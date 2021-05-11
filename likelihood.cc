#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>


double poisson(double mu, int k) {
    double zaehl= pow(mu,k)*exp(-mu);
    double nenn=tgamma(k+1);
    return zaehl/nenn;
}

double prob(std::vector<int> daten, double mu) {
  double lik=1;
  for(int k : daten) {
    double fact=poisson(mu,k);
    lik*=fact;
  }
  return lik;
}

double likequot(std::vector<int> daten, double mu){
  double zaehl=prob(daten, mu);
  double nenn=1;
  for(int i:daten){
    nenn*=poisson(i, i);
  }
  return zaehl/nenn;
}

int main() {
    using namespace std;

    const int N = 234;

    vector<int> daten;
    ifstream fin("datensumme.txt");
    int n_i;
    for(int i = 0 ; i < 234 ; ++i) {
        fin >> n_i;
        daten.push_back(n_i);
    }
    fin.close();

    std :: cout <<prob(daten, 3.11538)<< std :: endl ;

    ofstream fout("likelihood.txt");
    ofstream fout2("nll.txt");
    ofstream fout3("deltanll.txt");

    for(int i = 0 ; i <= 60 ; ++i) {
      double mu = i/10.0;
      double l=prob(daten, mu);
      double nlogl=-2*log(l);
      double deltanll=nlogl+2*log(prob(daten, 3.11538));

      fout << mu << " " << l << std::endl;
      fout2 << mu << " " << nlogl << std::endl;
      fout3 << mu << " " << deltanll << std::endl;
    }
    fout.close();
    fout2.close();
    fout3.close();

    double lq=likequot(daten,3.11538);
    lq=-2*log(lq);

    std :: cout << "Likelihood Quotient: " <<lq<< std :: endl ;

    double z=(-2*log(lq)-233)/(sqrt(2*233));

    std :: cout << "Relative Abweichung: " << z << std :: endl ;


    
}