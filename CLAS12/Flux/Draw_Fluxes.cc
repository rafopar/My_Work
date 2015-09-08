#include <TF1.h>
#include <TH1D.h>
#include <TH2D.h>
#include <fstream>
#include <iostream>
#include <TLatex.h>
#include <TCanvas.h>

using namespace std;

double N_EPA(double *x, double *par);
double N_Brem(double *x, double *par );

void Draw_Fluxes()
{
  const double Eg_min = 9.;
  const double Eg_max = 11.;
  const double Eb = 11.;
  const double Q2_max = 0.1;
  const double d0 = 15.;
  const double X0 = 929.;
  const double Mp = 0.9383;

  TLatex *lat1 = new TLatex();
  lat1->SetNDC();
  
  TCanvas *c1 = new TCanvas("c1", "", 750, 750);
  c1->SetLeftMargin(0.14);
  
  TF1 *f_EPA = new TF1("f_EPA", N_EPA, 2, Eg_max, 2);
  f_EPA->SetNpx(2500);

  TF1 *f_Brem = new TF1("f_Brem", N_Brem, 2., Eg_max, 3);
  
  f_EPA->SetParameters(Eb, Q2_max);
  f_EPA->SetTitle("; E_{#gamma} GeV; N_(#gamma)/1e");
  f_EPA->GetYaxis()->SetTitleOffset(2.1);
  f_EPA->SetLineColor(2);
  f_EPA->Draw();

  f_Brem->SetParameters(Eb, X0, d0);
  f_Brem->SetLineColor(4);
  f_Brem->Draw("Same");
  lat1->SetTextColor(2);
  lat1->DrawLatex(0.4, 0.81, "Virt. phot. Flux");
  lat1->SetTextColor(4);
  lat1->DrawLatex(0.4, 0.71, "Bremsstrahlung Flux");
  c1->Print("Virt_Brem_Fluxes.eps");
  c1->Print("Virt_Brem_Fluxes.pdf");
  c1->Print("Virt_Brem_Fluxes.gif");
  
  double Virt_Flux = f_EPA->Integral(Eg_min, Eg_max);
  double Brem_Flux = f_Brem->Integral(Eg_min, Eg_max);

  cout<<"Virt_Flux = "<<Virt_Flux<<endl;
  cout<<"Brem_Flux = "<<Brem_Flux<<endl;


  //=================== Calculate Fluxes in a fixed energy range intervals ====================
  const double W_width = 0.02; // GeV
  const double M_Pc1 = 4.38;  // GeV
  const double sigm_Pc1 = 0.205; // GeV
  const double M_Pc2 = 4.4498 ;  //GeV
  const double sigm_Pc2 = 0.039; // GeV
  
  const double W_min = M_Pc1 - 3*sigm_Pc1;
  const double W_max = 4.638517;

  ofstream out_dat("Flux_W.dat");
  
  int ind = 0;
  double W = W_min + 0.5*W_width;
  int str_w = 20;
  out_dat<<"  W | "<<setw(str_w)<<"Eg | "<<setw(str_w)<<"F_virt*Delta_W | "<<setw(str_w)<<"F_Brem*Delta_W | "
	 <<setw(str_w)<<"tot_Flux*Delta_W | "<<setw(str_w)<<"Tot_Lumin"<<endl;
  
  while( W < W_max )
    {
      double Eg = (W*W - Mp*Mp)/(2*Mp);

      // ========== In the following expression W/Mp is for converting dN/dEg -> dN/dW
      Virt_Flux = f_EPA->Eval(Eg)*(W/Mp)*W_width;
      Brem_Flux = f_Brem->Eval(Eg)*(W/Mp)*W_width;
      double tot_Flux = Virt_Flux + Brem_Flux;
      double tot_Lumin = tot_Flux*1.e35;

      out_dat<<"$"<<W<<"$ |"<<setw(str_w)<<Form("$%1.3f$ |", Eg)<<setw(str_w)<<Form("$%1.3e$ |", Virt_Flux)<<setw(str_w)<<
	Form("$%1.3e$ |", Brem_Flux)<<setw(str_w)<<Form("$%1.3e$ |", tot_Flux)<<setw(str_w)<<Form("$%1.3e$", tot_Lumin)<<endl;
           
      ind = ind + 1;
      W = W_min + (double(ind) + 0.5)*W_width;
    }
  
}

double N_EPA( double *xx, double *par )
{
  const double alpha = 1./137.;
  const double PI = 3.14159265358979312;

  double Eg = xx[0];
  double Eb = par[0];
  double Q2_max = par[1];
  
  double x = Eg/Eb;     // Eg/Eb

  double me = 0.00051;
  double Q2_min = me*me*x*x/(1 - x);
  double flux =  (1/Eb)*alpha/(PI*x)*( (1 - x + x*x/2)*log(Q2_max/Q2_min) - (1 - x));
  if( flux > 0 )
    {return flux;}
  else{ return 0; }
}

double N_Brem( double *x, double *par )
{
  // The factor 0.5 is because when one integrates over (l - x)*dx, then you get l^2/2
  double Eg = x[0];
  double Eb = par[0];
  double X0 = par[1];
  double d  = par[2];
  return (0.5*d/X0)*(1/Eg)*((4./3.) - (4./3.)*(Eg/Eb) + Eg*Eg/(Eb*Eb));
} 
