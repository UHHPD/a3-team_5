#include <iostream>
#include <fstream>
#include <vector>


double poisson(double mu, int k) {
    double zaehl= pow(mu,k)*exp(-mu);
    double nenn=tgamma(k+1);
    return zaehl/nenn;
}

double prob(std::vector<int> daten, double mu) {
  double lik=1;
  for(int k : daten) {
    poisson
  }
  return 0;
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
}