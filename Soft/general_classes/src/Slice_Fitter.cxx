#include <TF1.h>
#include <TH1D.h>
#include <string>
#include <iostream>

#include </Work/Soft/general_classes/include/Slice_Fitter.h>

using namespace std;

ClassImp(TSlice_Fitter)

TSlice_Fitter::TSlice_Fitter()
{
  ff_Gaus = NULL;
  fh_2D = NULL;
  fn_slices = 0;
  f_fit_thresh = 0;
}

TSlice_Fitter::TSlice_Fitter(TH2D *h_inp_hist, std::string keyname, TF1* f_fit, int n_sl, double x_min, double x_max)
{
  fh_2D = h_inp_hist;
  ff_Gaus = f_fit;
  fn_slices = n_sl;
  fx_min = x_min;
  fx_max = x_max;
  fkey_name = keyname;
  fgr_mean = new TGraphErrors();
  fgr_sigm = new TGraphErrors();
}

void TSlice_Fitter::SetAll(TH2D *h_inp_hist, std::string keyname, TF1* f_fit, int n_sl, double x_min, double x_max)
{
  fh_2D = h_inp_hist;
  ff_Gaus = f_fit;
  fn_slices = n_sl;
  fx_min = x_min;
  fx_max = x_max;
  fkey_name = keyname;
  fgr_mean = new TGraphErrors();
  fgr_sigm = new TGraphErrors();
}

void TSlice_Fitter::Do_SliceFit()
{
  if( !(ff_Gaus && fh_2D && (fx_min < fx_max)) )
    {
      cout<<"something is not set properly check the following"<<endl;
      cout<<"ff_Gaus = "<<ff_Gaus<<endl;
      cout<<"fh_2D = "<<ff_Gaus<<endl;
      cout<<"fn_slices = "<<ff_Gaus<<endl;
      cout<<" fx_min   fx_max:   "<<fx_min<<"    "<<fx_max<<endl;
      cout<<"The program is exiting "<<endl;
      exit(1);
    }
  cout<<"starting the Slice Fit "<<endl;

  int l_bin = fh_2D->GetXaxis()->FindBin(fx_min);
  int r_bin = fh_2D->GetXaxis()->FindBin(fx_max);
  int n_gr = (r_bin + 1 - l_bin)/fn_slices;

  TH1D *h_proj_[fn_slices];

  double mean, sigm;
  double mean_err, sigm_err;

  int ind = 0;
  for( int i = 0; i < fn_slices; i++ )
    {
      h_proj_[i] = fh_2D->ProjectionY(Form("proj_%s_%d", fkey_name.c_str(), i), l_bin + n_gr*i + 1, l_bin + n_gr*(i+1) );
      h_proj_[i]->Draw();

      if( h_proj_[i]->GetEntries() > f_fit_thresh )
	{
      //if( i == 0 )
	  {
	    sigm = h_proj_[i]->GetRMS();
	  }
	  mean = h_proj_[i]->GetBinCenter(h_proj_[i]->GetMaximumBin());
	  ff_Gaus->SetParameters(h_proj_[i]->GetMaximum(), mean, sigm);
	  h_proj_[i]->Fit(ff_Gaus, "MeV", "", mean - 2*sigm, mean + 2*sigm);
	  
	  mean = ff_Gaus->GetParameter(1);
	  sigm = ff_Gaus->GetParameter(2);
	  mean_err = ff_Gaus->GetParError(1);
	  sigm_err = ff_Gaus->GetParError(2);
	  
	  double x_val = fh_2D->GetXaxis()->GetBinCenter( l_bin + n_gr*i + n_gr/2 );
	  
	  fgr_mean->SetPoint(ind, x_val, mean);
	  fgr_mean->SetPointError(ind, 0, mean_err);
	  fgr_sigm->SetPoint(ind, x_val, sigm);
	  fgr_sigm->SetPointError(ind, 0, sigm_err);
	  ind = ind + 1;
	}
    }
  fh_proj = &h_proj_[0];
}

TGraphErrors* TSlice_Fitter::GetGrMean()
{
  return fgr_mean;
}

TGraphErrors* TSlice_Fitter::GetGrSigm()
{
  return fgr_sigm;
}
