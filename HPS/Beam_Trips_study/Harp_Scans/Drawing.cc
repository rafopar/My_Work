#include <TH1D.h>
#include <TH1D.h>
#include <TFile.h>
#include <TGraph.h>
#include <TCanvas.h>

void Drawing()
{
  TCanvas *c1 = new TCanvas("c1", "", 750, 750);

  TGraph *gr1 = new TGraph("2H02A_fit_time_depencence.dat", "%lg %*lg %*lg %*lg %*lg %*lg %*lg %*lg %lg");
  gr1->SetTimeDisplay(1);
}
