#include <TF1.h>
#include <TH1D.h>
#include <TH2D.h>
#include <TFile.h>
#include <TGraph.h>
#include <TCanvas.h>

void Slice_Fit_Matching()
{
  const int run = 5772;

  TCanvas *c1 = new TCanvas("c1", "", 750, 750);
  
  TF1 *f_Gaus = new TF1("f_Gaus", "[0]*TMath::Gaus(x, [1], [2])", -40., 40.);
  f_Gaus->SetNpx(2500);
  f_Gaus->SetParLimits(2, 0., 50.);

  TF1 *f_Pol5 = new TF1("f_Pol5", "[0] + x*( [1] + x*( [2] + x*( [3] + x*( [4] + x*[5] ) ) ) )", -300., 400.);
  
  TFile *file_in = new TFile(Form("Analyze_tridents_%d.root", run));
  TFile *file_out = new TFile(Form("Slices_Track_matching_%d.root", run), "Recreate");

  TH2D *h_delt_coord_trk_horiz_coord1 = (TH2D*)file_in->Get("h_delt_coord_trk_horiz_coord1");
  const int n_gr = 10;
  const int n_binsX = h_delt_coord_trk_horiz_coord1->GetNbinsX();
  const int n_slices = n_binsX/n_gr;
  TH1D *h_Proj_horiz_match1_[n_slices];

  TGraph *gr_mean = new TGraph(); gr_mean->SetMarkerColor(2); gr_mean->SetMarkerStyle(20); 
  TGraph *gr_sigm = new TGraph(); gr_sigm->SetMarkerColor(2); gr_sigm->SetMarkerStyle(20); 
  
  h_delt_coord_trk_horiz_coord1->Draw("colz");

  double mean;
  double sigm;
  for( int i = 0; i < n_slices; i++ )
    {
      h_Proj_horiz_match1_[i] = (TH1D*)h_delt_coord_trk_horiz_coord1->ProjectionY(Form("h_Proj_horiz_match1_%d", i), i*n_gr + 1, (i+1)*n_gr);
      if( i == 0 )
	{
	  mean = h_Proj_horiz_match1_[i]->GetBinCenter(h_Proj_horiz_match1_[i]->GetMaximumBin());
	  sigm = h_Proj_horiz_match1_[i]->GetRMS();
	}
      f_Gaus->SetParameters(h_Proj_horiz_match1_[i]->GetMaximum(), mean, 0.2*sigm );
      h_Proj_horiz_match1_[i]->Fit(f_Gaus, "MeV", "", mean -1.5*sigm, mean + 1.5*sigm);
      mean = f_Gaus->GetParameter(1);
      sigm = f_Gaus->GetParameter(2);

      double x_average = h_delt_coord_trk_horiz_coord1->GetXaxis()->GetBinCenter(i*n_gr + (n_gr)/2);
      
      gr_mean->SetPoint(i, x_average, mean);
      gr_sigm->SetPoint(i, x_average, sigm);
    }

  gDirectory->Write();
  gr_mean->Write("gr_mean");
  gr_sigm->Write("gr_sigm");
  gr_sigm->Draw("AP");
  gr_sigm->Fit(f_Pol5, "MeV", "", -300., 60.);
  TF1 *f_horiz_sigm_Left = (TF1*)f_Pol5->Clone("f_horiz_sigm_Left");
  f_horiz_sigm_Left->SetRange(-300., 60.);
  gr_sigm->Fit(f_Pol5, "MeV", "", 60., 360.);
  TF1 *f_horiz_sigm_Right = (TF1*)f_Pol5->Clone("f_horiz_sigm_Right");
  f_horiz_sigm_Right->SetRange(60., 360.);
  f_horiz_sigm_Left->Draw("Same");
  f_horiz_sigm_Right->Draw("Same");

  f_horiz_sigm_Left->Write();
  f_horiz_sigm_Right->Write();

  c1->Clear();
  gr_mean->Draw("AP");
  gr_mean->Fit(f_Pol5, "MeV", "", -300., 20);
  TF1 *f_horiz_mean_Left = (TF1*)f_Pol5->Clone("f_horiz_mean_Left");
  f_horiz_mean_Left->SetRange(-300., 20.);
  f_horiz_mean_Left->Write();
  gr_mean->Fit(f_Pol5, "MeV", "", 20., 360);
  TF1 *f_horiz_mean_Right = (TF1*)f_Pol5->Clone("f_horiz_mean_Right");
  f_horiz_mean_Right->SetRange(20., 360.);
  f_horiz_mean_Right->Write();
  f_horiz_mean_Left->Draw("Same");
  f_horiz_mean_Right->Draw("Same");
}
