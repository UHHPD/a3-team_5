#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>


double poisson(double mu, int k) {
    double zaehl= pow(mu,k)*exp(-mu);
    double nenn=tgamma(k+1);
    return zaehl/nenn;
}

int main() {
    using namespace std;


    ifstream fin("datensumme.txt");
    ofstream fout("hist.txt");
    

    vector<int> zaehler(11);
    const int N = 234;
    const double mean=3.11538;

    int n_i;
    for(int i = 0 ; i < 234 ; ++i) {
        fin >> n_i;
        zaehler[n_i] += 1;
    }
    fin.close();

    for ( unsigned int k = 0 ; k < zaehler.size() ; ++k) {
      std :: cout << k << ":" << zaehler [k] << std :: endl ;
    } 
    for ( unsigned int k = 0 ; k < zaehler.size() ; ++k) {
      fout << k << " " << zaehler [k] << endl ;
    }

    fin.close();
    fout.close();

    ofstream fout2("histpoi.txt");
    for ( unsigned int k = 0 ; k < zaehler.size() ; ++k) {
      fout2 << k << " " << zaehler [k] << " " << N*poisson(mean,k) << endl ;
    }
    fout2.close();
}