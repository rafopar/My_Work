#include <TF1.h>
#include <TH1D.h>
#include <TH2D.h>
#include <TFile.h>
#include <TGraph.h>
#include <TCanvas.h>
#include <TGraphErrors.h>

void Slice_Fit_Matching()
{
  const int run = 5772;

  TCanvas *c1 = new TCanvas("c1", "", 750, 750);
  
  TF1 *f_Gaus = new TF1("f_Gaus", "[0]*TMath::Gaus(x, [1], [2])", -40., 40.);
  f_Gaus->SetNpx(2500);
  f_Gaus->SetParLimits(2, 0.01, 50.);

  TF1 *f_Pol5 = new TF1("f_Pol5", "[0] + x*( [1] + x*( [2] + x*( [3] + x*( [4] + x*[5] ) ) ) )", -300., 400.);
  
  TFile *file_in = new TFile(Form("Analyze_tridents_%d.root", run));
  TFile *file_out = new TFile(Form("Slices_Track_matching_%d.root", run), "Recreate");

  TH2D *h_delt_coord_trk_horiz_coord1 = (TH2D*)file_in->Get("h_delt_coord_trk_horiz_coord1");
  const int n_gr = 10;
  int n_binsX = h_delt_coord_trk_horiz_coord1->GetNbinsX();
  int n_slices = n_binsX/n_gr;
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

  TH2D *h_delt_cord_trk_horiz_Ecl_bot2 = (TH2D*)file_in->Get("h_delt_cord_trk_horiz_Ecl_bot2");
  TH2D *h_delt_cord_trk_horiz_Ecl_top2 = (TH2D*)file_in->Get("h_delt_cord_trk_horiz_Ecl_top2");

  n_binsX = h_delt_cord_trk_horiz_Ecl_bot2->GetNbinsX();
  n_slices = n_binsX/n_gr;
  TH1D *h_Proj_horiz_match_bot2_[n_slices];
  TH1D *h_Proj_horiz_match_top2_[n_slices];

  TGraphErrors *gr_mean_bot_uncor2 = new TGraphErrors();
  TGraphErrors *gr_sigm_bot_uncor2 = new TGraphErrors();

  gr_mean_bot_uncor2->SetMarkerColor(2);
  gr_mean_bot_uncor2->SetMarkerStyle(20);
  gr_sigm_bot_uncor2->SetMarkerColor(2);
  gr_sigm_bot_uncor2->SetMarkerStyle(20);

  for( int i = 0; i < n_slices; i++ )
    {
      h_Proj_horiz_match_bot2_[i] = (TH1D*)h_delt_cord_trk_horiz_Ecl_bot2->ProjectionY(Form("h_Proj_horiz_match_bot2_%d", i), i*n_gr + 1, (i+1)*n_gr);
      h_Proj_horiz_match_bot2_[i]->Draw();
      if( i == 0 )
	{
	  mean = h_Proj_horiz_match_bot2_[i]->GetBinCenter(h_Proj_horiz_match1_[i]->GetMaximumBin());
	  sigm =h_Proj_horiz_match_bot2_[i] ->GetRMS();
	}
      f_Gaus->SetParameters( h_Proj_horiz_match_bot2_[i] ->GetMaximum(), mean, 0.5*sigm );
      h_Proj_horiz_match_bot2_[i]->Fit(f_Gaus, "MeV", "", mean -2.5*sigm*(1 - 1./(0.6*double(i)+1)), mean + 2.5*sigm*(1 - 1./(0.6*double(i)+1)));
      
      mean = f_Gaus->GetParameter(1);
      sigm = f_Gaus->GetParameter(2);
      double E_cl = h_delt_cord_trk_horiz_Ecl_bot2->GetXaxis()->GetBinCenter( i*n_gr + double(n_gr)/2.) ;
      double mean_err = f_Gaus->GetParError(1);
      double sigm_err = f_Gaus->GetParError(2);
      
      gr_mean_bot_uncor2->SetPoint(i, E_cl, mean);
      gr_mean_bot_uncor2->SetPointError(i, 0., mean_err);
      gr_sigm_bot_uncor2->SetPoint(i, E_cl, sigm);
      gr_sigm_bot_uncor2->SetPointError(i, 0., sigm_err);
    }

  gr_mean_bot_uncor2->Write("gr_mean_bot_uncor2");
  gr_sigm_bot_uncor2->Write("gr_sigm_bot_uncor2");

   TGraphErrors *gr_mean_top_uncor2 = new TGraphErrors();
  TGraphErrors *gr_sigm_top_uncor2 = new TGraphErrors();

  gr_mean_top_uncor2->SetMarkerColor(2);
  gr_mean_top_uncor2->SetMarkerStyle(20);
  gr_sigm_top_uncor2->SetMarkerColor(2);
  gr_sigm_top_uncor2->SetMarkerStyle(20);

  for( int i = 0; i < n_slices; i++ )
    {
      h_Proj_horiz_match_top2_[i] = (TH1D*)h_delt_cord_trk_horiz_Ecl_top2->ProjectionY(Form("h_Proj_horiz_match_top2_%d", i), i*n_gr + 1, (i+1)*n_gr);
      h_Proj_horiz_match_top2_[i]->Draw();
      if( i == 0 )
	{
	  mean = h_Proj_horiz_match_top2_[i]->GetBinCenter(h_Proj_horiz_match1_[i]->GetMaximumBin());
	  sigm =h_Proj_horiz_match_top2_[i] ->GetRMS();
	}
      f_Gaus->SetParameters( h_Proj_horiz_match_top2_[i] ->GetMaximum(), mean, 0.5*sigm );
      h_Proj_horiz_match_top2_[i]->Fit(f_Gaus, "MeV", "", mean -2.5*sigm*(1 - 1./(0.6*double(i)+1)), mean + 2.5*sigm*(1 - 1./(0.6*double(i)+1)));
      
      mean = f_Gaus->GetParameter(1);
      sigm = f_Gaus->GetParameter(2);
      double E_cl = h_delt_cord_trk_horiz_Ecl_top2->GetXaxis()->GetBinCenter( i*n_gr + double(n_gr)/2.) ;
      double mean_err = f_Gaus->GetParError(1);
      double sigm_err = f_Gaus->GetParError(2);
      
      gr_mean_top_uncor2->SetPoint(i, E_cl, mean);
      gr_mean_top_uncor2->SetPointError(i, 0., mean_err);
      gr_sigm_top_uncor2->SetPoint(i, E_cl, sigm);
      gr_sigm_top_uncor2->SetPointError(i, 0., sigm_err);
    }

  gr_mean_top_uncor2->Write("gr_mean_top_uncor2");
  gr_sigm_top_uncor2->Write("gr_sigm_top_uncor2");

  
  // ================= Fitting Corrected clusters =======================
  TFile *file_in_corr = new TFile("Analyze_tridents_5772_Ecorr.root");
  TH2D *h_delt_cord_trk_horiz_Ecl_bot_Ecorr2 = (TH2D*)file_in_corr->Get("h_delt_cord_trk_horiz_Ecl_bot2");
  TH2D *h_delt_cord_trk_horiz_Ecl_top_Ecorr2 = (TH2D*)file_in_corr->Get("h_delt_cord_trk_horiz_Ecl_top2");
  file_out->cd();
  
  n_binsX = h_delt_cord_trk_horiz_Ecl_bot_Ecorr2->GetNbinsX();
  n_slices = n_binsX/n_gr;
  TH1D *h_Proj_horiz_match_bot_Ecorr2_[n_slices];
  TH1D *h_Proj_horiz_match_top_Ecorr2_[n_slices];

  TGraphErrors *gr_mean_bot_Ecorr2 = new TGraphErrors();
  TGraphErrors *gr_sigm_bot_Ecorr2 = new TGraphErrors();

  gr_mean_bot_Ecorr2->SetMarkerColor(2);
  gr_mean_bot_Ecorr2->SetMarkerStyle(20);
  gr_sigm_bot_Ecorr2->SetMarkerColor(2);
  gr_sigm_bot_Ecorr2->SetMarkerStyle(20);

  for( int i = 0; i < n_slices; i++ )
    {
      h_Proj_horiz_match_bot_Ecorr2_[i] = (TH1D*)h_delt_cord_trk_horiz_Ecl_bot_Ecorr2->ProjectionY(Form("h_Proj_horiz_match_bot_Ecorr2_%d", i), i*n_gr + 1, (i+1)*n_gr);
      h_Proj_horiz_match_bot_Ecorr2_[i]->Draw();
      if( i == 0 )
	{
	  mean = h_Proj_horiz_match_bot_Ecorr2_[i]->GetBinCenter(h_Proj_horiz_match1_[i]->GetMaximumBin());
	  sigm =h_Proj_horiz_match_bot_Ecorr2_[i] ->GetRMS();
	}
      f_Gaus->SetParameters( h_Proj_horiz_match_bot_Ecorr2_[i] ->GetMaximum(), mean, 0.5*sigm );
      h_Proj_horiz_match_bot_Ecorr2_[i]->Fit(f_Gaus, "MeV", "", mean -2.5*sigm*(1 - 1./(0.6*double(i)+1)), mean + 2.5*sigm*(1 - 1./(0.6*double(i)+1)));
      
      mean = f_Gaus->GetParameter(1);
      sigm = f_Gaus->GetParameter(2);
      double E_cl = h_delt_cord_trk_horiz_Ecl_bot_Ecorr2->GetXaxis()->GetBinCenter( i*n_gr + double(n_gr)/2.) ;
      double mean_err = f_Gaus->GetParError(1);
      double sigm_err = f_Gaus->GetParError(2);
      
      gr_mean_bot_Ecorr2->SetPoint(i, E_cl, mean);
      gr_mean_bot_Ecorr2->SetPointError(i, 0., mean_err);
      gr_sigm_bot_Ecorr2->SetPoint(i, E_cl, sigm);
      gr_sigm_bot_Ecorr2->SetPointError(i, 0., sigm_err);
    }

  gr_mean_bot_Ecorr2->Write("gr_mean_bot_Ecorr2");
  gr_sigm_bot_Ecorr2->Write("gr_sigm_bot_Ecorr2");

   TGraphErrors *gr_mean_top_Ecorr2 = new TGraphErrors();
  TGraphErrors *gr_sigm_top_Ecorr2 = new TGraphErrors();

  gr_mean_top_Ecorr2->SetMarkerColor(2);
  gr_mean_top_Ecorr2->SetMarkerStyle(20);
  gr_sigm_top_Ecorr2->SetMarkerColor(2);
  gr_sigm_top_Ecorr2->SetMarkerStyle(20);

  for( int i = 0; i < n_slices; i++ )
    {
      h_Proj_horiz_match_top_Ecorr2_[i] = (TH1D*)h_delt_cord_trk_horiz_Ecl_top_Ecorr2->ProjectionY(Form("h_Proj_horiz_match_top_Ecorr2_%d", i), i*n_gr + 1, (i+1)*n_gr);
      h_Proj_horiz_match_top_Ecorr2_[i]->Draw();
      if( i == 0 )
	{
	  mean = h_Proj_horiz_match_top_Ecorr2_[i]->GetBinCenter(h_Proj_horiz_match1_[i]->GetMaximumBin());
	  sigm =h_Proj_horiz_match_top_Ecorr2_[i] ->GetRMS();
	}
      f_Gaus->SetParameters( h_Proj_horiz_match_top_Ecorr2_[i] ->GetMaximum(), mean, 0.5*sigm );
      h_Proj_horiz_match_top_Ecorr2_[i]->Fit(f_Gaus, "MeV", "", mean -2.5*sigm*(1 - 1./(0.6*double(i)+1)), mean + 2.5*sigm*(1 - 1./(0.6*double(i)+1)));
      
      mean = f_Gaus->GetParameter(1);
      sigm = f_Gaus->GetParameter(2);
      double E_cl = h_delt_cord_trk_horiz_Ecl_top_Ecorr2->GetXaxis()->GetBinCenter( i*n_gr + double(n_gr)/2.) ;
      double mean_err = f_Gaus->GetParError(1);
      double sigm_err = f_Gaus->GetParError(2);
      
      gr_mean_top_Ecorr2->SetPoint(i, E_cl, mean);
      gr_mean_top_Ecorr2->SetPointError(i, 0., mean_err);
      gr_sigm_top_Ecorr2->SetPoint(i, E_cl, sigm);
      gr_sigm_top_Ecorr2->SetPointError(i, 0., sigm_err);
    }

  gr_mean_top_Ecorr2->Write("gr_mean_top_Ecorr2");
  gr_sigm_top_Ecorr2->Write("gr_sigm_top_Ecorr2");

  
}
