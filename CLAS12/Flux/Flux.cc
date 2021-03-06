#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <iomanip>
#include <fstream>

using namespace std;

double N_EPA(double, double , double);
double N_Brem(double, double, double, double );

int main( int argc, char **argv)
{
  double Eb, Q2_max, Eg_min, Eg_max, A, N_e, rho, l_targ;
  
  const double N_A = 6.02214e+23;
  const double d0 = 15.; // target length in cm
  const double X0 = 929.; // rad length of H in cm;
  
  bool calc_virt_lumin = false;
  if( argc == 5 )
    {
      Eb = atof(argv[1]);
      Q2_max = atof(argv[2]);
      Eg_min = atof(argv[3]);
      Eg_max = atof(argv[4]);

      //cout<<" Eb =  "<<Eb<<" GeV      Q2_max = "<<Q2_max<<" GeV^2"<<endl;
    }
  else if( argc == 9 )
    {
      Eb = atof(argv[1]);
      Q2_max = atof(argv[2]);
      Eg_min = atof(argv[3]);
      Eg_max = atof(argv[4]);
      
      A = atof(argv[5]);
      N_e = atof(argv[6]);
      rho = atof(argv[7]);
      l_targ = atof(argv[8]);
      calc_virt_lumin = true;
    }
  else
    {
      cout<<"Please specify arguments correctly"<<endl;
      cout<<"It should be executed as"<<endl;
      cout<<"./Flux.exe Eb Q2_max Eg_min Eg_max "<<endl;
      cout<<"OR"<<endl;
      cout<<" ./Flux.exe Eb Q2_max Eg_min Eg_max A N_e rho l_targ"<<endl;
      cout<<"The program is exiting"<<endl;
      exit(1);
    }

  if( !(Eg_min>= 0 && Eg_min < Eg_max && Eg_max <= Eb) )
    {
      cout<<"Eg_min  "<<Eg_min<<"    Eg_max "<<Eg_max<<endl;
      cout<<"Eg min and/or max values were set incorrectly, please check them, The program is exiting"<<endl;
      exit(1);
    }
  

  ofstream out_dat("virtual_flux.dat");
  ofstream Eg_distr_dat("Eg_distr.dat");
  out_dat<<"Eb (GeV): "<<Eb<<endl;
  out_dat<<"Q2_max (GeV^2): "<<Q2_max<<endl;
  out_dat<<"Eg_min (GeV): "<<Eg_min<<endl;
  out_dat<<"Eg_max (GeV): "<<Eg_max<<endl;

  if( calc_virt_lumin )
    {
      out_dat<<"Target A: "<<A<<endl;
      out_dat<<"Number of beam e-: "<<N_e<<endl;
      out_dat<<"target density g*cm-3: "<<rho<<endl;
      out_dat<<"target length cm: "<<l_targ<<endl;
    }

  out_dat<<"================================================="<<endl;
  const int n_points = 1000;
  
  double tot_virt_Flux = 0;
  double tot_Bremstr = 0.;
  for( int i = 0; i < n_points; i++ )
    {
      double Eg = Eg_min + (Eg_max - Eg_min)*(double(i)+0.5)/double(n_points);
      double virt_flux = N_EPA(Eg, Eb, Q2_max);//*rho*l_targ*N_A;
      
      tot_virt_Flux = tot_virt_Flux + virt_flux;
      double Bremstr = N_Brem(Eg, Eb, d0, X0);

      tot_Bremstr = tot_Bremstr + Bremstr;
      
      Eg_distr_dat<<Eg<<setw(15)<<virt_flux<<setw(15)<<Bremstr<<endl;
    }
  tot_virt_Flux = tot_virt_Flux*(Eg_max - Eg_min)/double(n_points);
  tot_Bremstr = tot_Bremstr*(Eg_max - Eg_min)/double(n_points);
  
  out_dat<<"N_virt_gamma* in the Eg("<<Eg_min<<"-"<<Eg_max<<")GeV  = "<<tot_virt_Flux<<endl;
  out_dat<<"N_Bremsstrg_amma* in the Eg("<<Eg_min<<"-"<<Eg_max<<")GeV  = "<<tot_Bremstr<<endl;
    
  


  if( calc_virt_lumin )
    {
      double tot_virt_lumin = tot_virt_Flux*N_e*rho*l_targ*N_A/A;
      out_dat<<" total luminosity of virtual photons "<<tot_virt_lumin<<endl;
    }

}

double N_EPA(double Eg, double Eb, double Q2_max)
{
  const double alpha = 1./137.;
  const double PI = 3.14159265358979312;
  
  double x = Eg/Eb;     // Eg/Eb

  double me = 0.00051;
  double Q2_min = me*me*x*x/(1 - x);
  double flux =  (1/Eb)*alpha/(PI*x)*( (1 - x + x*x/2)*log(Q2_max/Q2_min) - (1 - x));
  if( flux > 0 )
    {return flux;}
  else{ return 0; }

}

double N_Brem(double Eg, double Eb, double d, double X0)
{
  // The factor 0.5 is because when one integrates over (l - x)*dx, then you get l^2/2
  return (0.5*d/X0)*(1/Eg)*((4./3.) - (4./3.)*(Eg/Eb) + Eg*Eg/(Eb*Eb));
} 
