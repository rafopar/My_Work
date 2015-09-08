#include <TF1.h>
#include <TAxis.h>
#include <TLatex.h>
#include <TCanvas.h>

double El_corr(double *x, double *par);
double Pos_corr(double *x, double *par);

void Xcorr_Formula()
{
  TLatex *lat1 = new TLatex();
  lat1->SetNDC();
  lat1->SetTextColor(2);
  
  TCanvas *c1 = new TCanvas("c1", "", 750, 750);
  TF1 *f_el_corr = new TF1("f_el_corr", El_corr, 0., 1.1, 1);
  f_el_corr->SetTitle("Electrons ; E_{cl} GeV ; X_{cl} - X_{gen} mm");
  f_el_corr->SetParameter(0, -250);
  f_el_corr->Draw();
  f_el_corr->SetRange(0.1, 1.05);
  lat1->DrawLatex(0.6, 0.3, "X_{c} = -250 mm");
  c1->Print("F_el_corr.eps");
  c1->Print("F_el_corr.pdf");
  c1->Print("F_el_corr.gif");

  TCanvas *c2 = new TCanvas("c2", "", 750, 750);
  TF1 *f_pos_corr = new TF1("f_pos_corr", Pos_corr, 0., 1.1, 1);
  f_pos_corr->SetTitle("Positrons ; E_{cl} GeV ; X_{cl} - X_{gen} mm");
  f_pos_corr->SetParameter(0, 250);
  f_pos_corr->SetRange(0.1, 1.05);
  f_pos_corr->Draw();  
  lat1->DrawLatex(0.6, 0.3, "X_{c} = 250 mm");
  c2->Print("F_pos_corr.eps");
  c2->Print("F_pos_corr.pdf");
  c2->Print("F_pos_corr.gif");


}

double El_corr(double *x, double *par)
{
  double E = x[0];
  double x_c = par[0];

  double A_E = -0.0005813*E + 0.005738/sqrt(E) - 0.0309;
  double B_E = 0.02963*E - 4.289/sqrt(E) + 4.596;
  
  return x_c - (x_c - B_E)/(A_E + 1.);
}

double Pos_corr(double *x, double *par)
{
  double E = x[0];
  double x_c = par[0];

  double A_E = -0.0006243*E + 0.006799/sqrt(E) - 0.03141;
  double B_E = 0.0869*E + 2.965/sqrt(E) + 1.653;
  
  return x_c - (x_c - B_E)/(A_E + 1.);
}
