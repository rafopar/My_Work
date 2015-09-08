#ifndef __SLICEFITTER__
#define __SLICEFITTER__

#include "TObject.h"
#include <TF1.h>
#include <TH1D.h>
#include <TH2D.h>
#include <TGraphErrors.h>

class string;

class TSlice_Fitter : public TObject
{
 public:
  TSlice_Fitter();
  TSlice_Fitter(TH2D* inp_hist, const std::string keyname, TF1* fit_function, int n_slices, double x_min, double x_max);
  void SetAll(TH2D* inp_hist, const std::string keyname, TF1* fit_function, int n_slices, double x_min, double x_max);
  void Do_SliceFit();
  TGraphErrors *GetGrMean();
  TGraphErrors *GetGrSigm();
  void SetFitThreshold( double fit_thr ) {f_fit_thresh = fit_thr;};
  
  ClassDef(TSlice_Fitter, 1);
  
 private:
  double fx_min, fx_max; // makes fn_sclices between fx_min and fx_max
  TF1 *ff_Gaus;          // Tha Gaussian function to fit
  TH2D *fh_2D;
  std::string fkey_name; // Slice histogramse name with a fkey_name
  int fn_slices;         // number of slices
  TGraphErrors *fgr_mean;  // graph for mean values
  TGraphErrors *fgr_sigm;  // graph for sigma values
  TH1D **fh_proj;
  double f_fit_thresh;     // number of entries should be abouve the threshold to proceed to fit
};

#endif
