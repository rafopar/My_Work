#include <TF1.h>
#include <TH1D.h>
#include <TH2D.h>
#include <TFile.h>
#include <TLine.h>
#include <TCanvas.h>
#include <TSystem.h>
#include <TMultiGraph.h>

#include "/Work/Soft/general_classes/include/Slice_Fitter.h"
#include </Work/Soft/general_classes/include/MyLinkDef.h>

void Draw_Matching()
{
  
  TCanvas *c1 = new TCanvas("c1", "", 750, 750);

  TLine *line1 = new TLine();
  line1->SetLineColor(2);
  line1->SetLineWidth(2);

  int run = 5772;
  
  // TFile *file_in_Uncorr = new TFile("Analyze_tridents_Euncorr_5772.root");
  // TFile *file_in_ECorr = new TFile("Analyze_tridents_Ecorr_5772.root");
  TFile *file_in_Uncorr = new TFile("test_EUncorr_5772.root");
  TFile *file_in_ECorr = new TFile("test_Ecorr_5772.root");

  
  TH2D *h_delt_cord_trk_horiz_Ecl_top_pos2 = (TH2D*)file_in_Uncorr->Get("h_delt_cord_trk_horiz_Ecl_top_pos2");
  TH2D *h_delt_cord_trk_horiz_Ecl_top_neg2 = (TH2D*)file_in_Uncorr->Get("h_delt_cord_trk_horiz_Ecl_top_neg2");
  TH2D *h_delt_cord_trk_horiz_Ecl_bot_pos2 = (TH2D*)file_in_Uncorr->Get("h_delt_cord_trk_horiz_Ecl_bot_pos2");
  TH2D *h_delt_cord_trk_horiz_Ecl_bot_neg2 = (TH2D*)file_in_Uncorr->Get("h_delt_cord_trk_horiz_Ecl_bot_neg2");

  h_delt_cord_trk_horiz_Ecl_top_pos2->SetTitle("; P_{pos} GeV; X_{cl} -X_{tr} mm");
  h_delt_cord_trk_horiz_Ecl_top_pos2->SetAxisRange(0.1, 0.8);
  h_delt_cord_trk_horiz_Ecl_top_pos2->Draw("colz");
  line1->DrawLine(0.1, 0., 0.8, 0.);
  c1->Print("delt_cord_trk_horiz_Ecl_top_pos2.eps");
  c1->Print("delt_cord_trk_horiz_Ecl_top_pos2.pdf");
  c1->Print("delt_cord_trk_horiz_Ecl_top_pos2.gif");

  h_delt_cord_trk_horiz_Ecl_top_neg2->SetTitle("; P_{neg} GeV; X_{cl} -X_{tr} mm");
  h_delt_cord_trk_horiz_Ecl_top_neg2->SetAxisRange(0.1, 0.8);
  h_delt_cord_trk_horiz_Ecl_top_neg2->Draw("colz");
  line1->DrawLine(0.1, 0., 0.8, 0.);
  c1->Print("delt_cord_trk_horiz_Ecl_top_neg2.eps");
  c1->Print("delt_cord_trk_horiz_Ecl_top_neg2.pdf");
  c1->Print("delt_cord_trk_horiz_Ecl_top_neg2.gif");

  h_delt_cord_trk_horiz_Ecl_bot_pos2->SetTitle("; P_{pos} GeV; X_{cl} -X_{tr} mm");
  h_delt_cord_trk_horiz_Ecl_bot_pos2->SetAxisRange(0.1, 0.8);
  h_delt_cord_trk_horiz_Ecl_bot_pos2->Draw("colz");
  line1->DrawLine(0.1, 0., 0.8, 0.);
  c1->Print("delt_cord_trk_horiz_Ecl_bot_pos2.eps");
  c1->Print("delt_cord_trk_horiz_Ecl_bot_pos2.pdf");
  c1->Print("delt_cord_trk_horiz_Ecl_bot_pos2.gif");

  h_delt_cord_trk_horiz_Ecl_bot_neg2->SetTitle("; P_{neg} GeV; X_{cl} -X_{tr} mm");
  h_delt_cord_trk_horiz_Ecl_bot_neg2->SetAxisRange(0.1, 0.8);
  h_delt_cord_trk_horiz_Ecl_bot_neg2->Draw("colz");
  line1->DrawLine(0.1, 0., 0.8, 0.);
  c1->Print("delt_cord_trk_horiz_Ecl_bot_neg2.eps");
  c1->Print("delt_cord_trk_horiz_Ecl_bot_neg2.pdf");
  c1->Print("delt_cord_trk_horiz_Ecl_bot_neg2.gif");

  
  TH2D *h_delt_cord_trk_horiz_Ecl_top_pos_ECorr2 = (TH2D*)file_in_ECorr->Get("h_delt_cord_trk_horiz_Ecl_top_pos2");
  TH2D *h_delt_cord_trk_horiz_Ecl_top_neg_ECorr2 = (TH2D*)file_in_ECorr->Get("h_delt_cord_trk_horiz_Ecl_top_neg2");
  TH2D *h_delt_cord_trk_horiz_Ecl_bot_pos_ECorr2 = (TH2D*)file_in_ECorr->Get("h_delt_cord_trk_horiz_Ecl_bot_pos2");
  TH2D *h_delt_cord_trk_horiz_Ecl_bot_neg_ECorr2 = (TH2D*)file_in_ECorr->Get("h_delt_cord_trk_horiz_Ecl_bot_neg2");

  h_delt_cord_trk_horiz_Ecl_top_pos_ECorr2->SetTitle("; P_{pos} GeV; X_{cl} -X_{tr} mm");
  h_delt_cord_trk_horiz_Ecl_top_pos_ECorr2->SetAxisRange(0.1, 0.8);
  h_delt_cord_trk_horiz_Ecl_top_pos_ECorr2->Draw("colz");
  line1->DrawLine(0.1, 0., 0.8, 0.);
  c1->Print("delt_cord_trk_horiz_Ecl_top_pos_ECorr2.eps");
  c1->Print("delt_cord_trk_horiz_Ecl_top_pos_ECorr2.pdf");
  c1->Print("delt_cord_trk_horiz_Ecl_top_pos_ECorr2.gif");

  h_delt_cord_trk_horiz_Ecl_top_neg_ECorr2->SetTitle("; P_{neg} GeV; X_{cl} -X_{tr} mm");
  h_delt_cord_trk_horiz_Ecl_top_neg_ECorr2->SetAxisRange(0.1, 0.8);
  h_delt_cord_trk_horiz_Ecl_top_neg_ECorr2->Draw("colz");
  line1->DrawLine(0.1, 0., 0.8, 0.);
  c1->Print("delt_cord_trk_horiz_Ecl_top_neg_ECorr2.eps");
  c1->Print("delt_cord_trk_horiz_Ecl_top_neg_ECorr2.pdf");
  c1->Print("delt_cord_trk_horiz_Ecl_top_neg_ECorr2.gif");

  h_delt_cord_trk_horiz_Ecl_bot_pos_ECorr2->SetTitle("; P_{pos} GeV; X_{cl} -X_{tr} mm");
  h_delt_cord_trk_horiz_Ecl_bot_pos_ECorr2->SetAxisRange(0.1, 0.8);
  h_delt_cord_trk_horiz_Ecl_bot_pos_ECorr2->Draw("colz");
  line1->DrawLine(0.1, 0., 0.8, 0.);
  c1->Print("delt_cord_trk_horiz_Ecl_bot_pos_ECorr2.eps");
  c1->Print("delt_cord_trk_horiz_Ecl_bot_pos_ECorr2.pdf");
  c1->Print("delt_cord_trk_horiz_Ecl_bot_pos_ECorr2.gif");

  h_delt_cord_trk_horiz_Ecl_bot_neg_ECorr2->SetTitle("; P_{neg} GeV; X_{cl} -X_{tr} mm");
  h_delt_cord_trk_horiz_Ecl_bot_neg_ECorr2->SetAxisRange(0.1, 0.8);
  h_delt_cord_trk_horiz_Ecl_bot_neg_ECorr2->Draw("colz");
  line1->DrawLine(0.1, 0., 0.8, 0.);
  c1->Print("delt_cord_trk_horiz_Ecl_bot_neg_ECorr2.eps");
  c1->Print("delt_cord_trk_horiz_Ecl_bot_neg_ECorr2.pdf");
  c1->Print("delt_cord_trk_horiz_Ecl_bot_neg_ECorr2.gif");

  TH1D *h_Delt_clust_top_bot1 = (TH1D*)file_in_ECorr->Get("h_Delt_clust_top_bot1");
  h_Delt_clust_top_bot1->SetTitle("; t_{bot} - t_{top} ns");
  h_Delt_clust_top_bot1->Draw();
  c1->Print("Delt_t_top_bot1.eps");
  c1->Print("Delt_t_top_bot1.pdf");
  c1->Print("Delt_t_top_bot1.gif");

  TH1D *h_Delt_clust_top_bot2 = (TH1D*)file_in_ECorr->Get("h_Delt_clust_top_bot2");
  h_Delt_clust_top_bot2->SetTitle("; t_{bot} - t_{top} ns");
  h_Delt_clust_top_bot2->Draw();
  c1->Print("Delt_t_top_bot2.eps");
  c1->Print("Delt_t_top_bot2.pdf");
  c1->Print("Delt_t_top_bot2.gif");

  TF1 *f_Gaus = new TF1("f_Gaus", "[0]*TMath::Gaus(x, [1], [2])", -45, 45);
  f_Gaus->SetParLimits(2, 0.001, 100);
  f_Gaus->SetNpx(2500);
  
  //gSystem->Load("/Work/Soft/general_classes/toollibs.so");

  TSlice_Fitter *sl_fit = new TSlice_Fitter(h_delt_cord_trk_horiz_Ecl_top_pos2, "h_delt_cord_trk_horiz_Ecl_top_pos2", f_Gaus, 20, 0.09, 0.77);

  sl_fit->SetFitThreshold(50.);
  sl_fit->Do_SliceFit();

  TGraphErrors *gr_mean_delt_cord_trk_horiz_Ecl_top_pos2 = sl_fit->GetGrMean();
  gr_mean_delt_cord_trk_horiz_Ecl_top_pos2->SetTitle("; P (GeV) ; X_{cl} - X_{tr} mm");
  gr_mean_delt_cord_trk_horiz_Ecl_top_pos2->SetMarkerStyle(20);
  gr_mean_delt_cord_trk_horiz_Ecl_top_pos2->SetMarkerColor(2);
  gr_mean_delt_cord_trk_horiz_Ecl_top_pos2->SetMaximum(10.);
  gr_mean_delt_cord_trk_horiz_Ecl_top_pos2->SetMinimum(0.);
  gr_mean_delt_cord_trk_horiz_Ecl_top_pos2->Draw("AP");
  c1->Print("mean_delt_cord_trk_horiz_Ecl_top_pos2.eps");
  c1->Print("mean_delt_cord_trk_horiz_Ecl_top_pos2.pdf");
  c1->Print("mean_delt_cord_trk_horiz_Ecl_top_pos2.gif");

  TGraphErrors *gr_sigm_delt_cord_trk_horiz_Ecl_top_pos2 = sl_fit->GetGrSigm();
  gr_sigm_delt_cord_trk_horiz_Ecl_top_pos2->SetTitle("; P (GeV) ; X_{cl} - X_{tr} mm");
  gr_sigm_delt_cord_trk_horiz_Ecl_top_pos2->SetMarkerStyle(20);
  gr_sigm_delt_cord_trk_horiz_Ecl_top_pos2->SetMarkerColor(2);
  gr_sigm_delt_cord_trk_horiz_Ecl_top_pos2->SetMaximum(20.);
  gr_sigm_delt_cord_trk_horiz_Ecl_top_pos2->SetMinimum(0.);
  gr_sigm_delt_cord_trk_horiz_Ecl_top_pos2->Draw("AP");
  c1->Print("sigm_delt_cord_trk_horiz_Ecl_top_pos2.eps");
  c1->Print("sigm_delt_cord_trk_horiz_Ecl_top_pos2.pdf");
  c1->Print("sigm_delt_cord_trk_horiz_Ecl_top_pos2.gif");
  

  sl_fit->SetAll(h_delt_cord_trk_horiz_Ecl_top_neg2, "h_delt_cord_trk_horiz_Ecl_top_neg2", f_Gaus, 20, 0.09, 0.77);
  sl_fit->Do_SliceFit();
  TGraphErrors *gr_mean_delt_cord_trk_horiz_Ecl_top_neg2 = sl_fit->GetGrMean();
  gr_mean_delt_cord_trk_horiz_Ecl_top_neg2->SetTitle("; P (GeV) ; X_{cl} - X_{tr} mm");
  gr_mean_delt_cord_trk_horiz_Ecl_top_neg2->SetMarkerStyle(20);
  gr_mean_delt_cord_trk_horiz_Ecl_top_neg2->SetMarkerColor(2);
  gr_mean_delt_cord_trk_horiz_Ecl_top_neg2->SetMaximum(5.);
  gr_mean_delt_cord_trk_horiz_Ecl_top_neg2->SetMinimum(10.);
  gr_mean_delt_cord_trk_horiz_Ecl_top_neg2->Draw("AP");
  c1->Print("mean_delt_cord_trk_horiz_Ecl_top_neg2.eps");
  c1->Print("mean_delt_cord_trk_horiz_Ecl_top_neg2.pdf");
  c1->Print("mean_delt_cord_trk_horiz_Ecl_top_neg2.gif");
  
  TGraphErrors *gr_sigm_delt_cord_trk_horiz_Ecl_top_neg2 = sl_fit->GetGrSigm();
  gr_sigm_delt_cord_trk_horiz_Ecl_top_neg2->SetTitle("; P (GeV) ; X_{cl} - X_{tr} mm");
  gr_sigm_delt_cord_trk_horiz_Ecl_top_neg2->SetMarkerStyle(20);
  gr_sigm_delt_cord_trk_horiz_Ecl_top_neg2->SetMarkerColor(2);
  gr_sigm_delt_cord_trk_horiz_Ecl_top_neg2->SetMaximum(20.);
  gr_sigm_delt_cord_trk_horiz_Ecl_top_neg2->SetMinimum(0.);
  gr_sigm_delt_cord_trk_horiz_Ecl_top_neg2->Draw("AP");
  c1->Print("sigm_delt_cord_trk_horiz_Ecl_top_neg2.eps");
  c1->Print("sigm_delt_cord_trk_horiz_Ecl_top_neg2.pdf");
  c1->Print("sigm_delt_cord_trk_horiz_Ecl_top_neg2.gif");

  
  sl_fit->SetAll(h_delt_cord_trk_horiz_Ecl_top_pos_ECorr2, "h_delt_cord_trk_horiz_Ecl_top_pos_ECorr2", f_Gaus, 15, 0.45, 0.77);
  sl_fit->Do_SliceFit();
  
  TGraphErrors *gr_mean_delt_cord_trk_horiz_Ecl_top_pos_ECorr2 = sl_fit->GetGrMean();
  gr_mean_delt_cord_trk_horiz_Ecl_top_pos_ECorr2->SetTitle("; P (GeV) ; X_{cl} - X_{tr} mm");
  gr_mean_delt_cord_trk_horiz_Ecl_top_pos_ECorr2->SetMarkerStyle(22);
  gr_mean_delt_cord_trk_horiz_Ecl_top_pos_ECorr2->SetMarkerColor(4);
  // gr_mean_delt_cord_trk_horiz_Ecl_top_pos_ECorr2->SetMaximum(10.);
  // gr_mean_delt_cord_trk_horiz_Ecl_top_pos_ECorr2->SetMinimum(0.);
  gr_mean_delt_cord_trk_horiz_Ecl_top_pos_ECorr2->Draw("AP");
  c1->Print("mean_delt_cord_trk_horiz_Ecl_top_pos_ECorr2.eps");
  c1->Print("mean_delt_cord_trk_horiz_Ecl_top_pos_ECorr2.pdf");
  c1->Print("mean_delt_cord_trk_horiz_Ecl_top_pos_ECorr2.gif");
  
  TGraphErrors *gr_sigm_delt_cord_trk_horiz_Ecl_top_pos_ECorr2 = sl_fit->GetGrSigm();
  gr_sigm_delt_cord_trk_horiz_Ecl_top_pos_ECorr2->SetTitle("; P (GeV) ; X_{cl} - X_{tr} mm");
  gr_sigm_delt_cord_trk_horiz_Ecl_top_pos_ECorr2->SetMarkerStyle(22);
  gr_sigm_delt_cord_trk_horiz_Ecl_top_pos_ECorr2->SetMarkerColor(4);
  // gr_sigm_delt_cord_trk_horiz_Ecl_top_pos_ECorr2->SetMaximum(22.);
  // gr_sigm_delt_cord_trk_horiz_Ecl_top_pos_ECorr2->SetMinimum(0.);
  gr_sigm_delt_cord_trk_horiz_Ecl_top_pos_ECorr2->Draw("AP");
  c1->Print("sigm_delt_cord_trk_horiz_Ecl_top_pos_ECorr2.eps");
  c1->Print("sigm_delt_cord_trk_horiz_Ecl_top_pos_ECorr2.pdf");
  c1->Print("sigm_delt_cord_trk_horiz_Ecl_top_pos_ECorr2.gif");
  

  sl_fit->SetAll(h_delt_cord_trk_horiz_Ecl_top_neg_ECorr2, "h_delt_cord_trk_horiz_Ecl_top_neg_ECorr2", f_Gaus, 15, 0.4, 0.77);
  sl_fit->Do_SliceFit();
  TGraphErrors *gr_mean_delt_cord_trk_horiz_Ecl_top_neg_ECorr2 = sl_fit->GetGrMean();
  gr_mean_delt_cord_trk_horiz_Ecl_top_neg_ECorr2->SetTitle("; P (GeV) ; X_{cl} - X_{tr} mm");
  gr_mean_delt_cord_trk_horiz_Ecl_top_neg_ECorr2->SetMarkerStyle(22);
  gr_mean_delt_cord_trk_horiz_Ecl_top_neg_ECorr2->SetMarkerColor(4);
  // gr_mean_delt_cord_trk_horiz_Ecl_top_neg_ECorr2->SetMaximum(10.);
  // gr_mean_delt_cord_trk_horiz_Ecl_top_neg_ECorr2->SetMinimum(0.);
  gr_mean_delt_cord_trk_horiz_Ecl_top_neg_ECorr2->Draw("AP");
  c1->Print("mean_delt_cord_trk_horiz_Ecl_top_neg_ECorr2.eps");
  c1->Print("mean_delt_cord_trk_horiz_Ecl_top_neg_ECorr2.pdf");
  c1->Print("mean_delt_cord_trk_horiz_Ecl_top_neg_ECorr2.gif");
  
  TGraphErrors *gr_sigm_delt_cord_trk_horiz_Ecl_top_neg_ECorr2 = sl_fit->GetGrSigm();
  gr_sigm_delt_cord_trk_horiz_Ecl_top_neg_ECorr2->SetTitle("; P (GeV) ; X_{cl} - X_{tr} mm");
  gr_sigm_delt_cord_trk_horiz_Ecl_top_neg_ECorr2->SetMarkerStyle(22);
  gr_sigm_delt_cord_trk_horiz_Ecl_top_neg_ECorr2->SetMarkerColor(4);
  // gr_sigm_delt_cord_trk_horiz_Ecl_top_neg_ECorr2->SetMaximum(10.);
  // gr_sigm_delt_cord_trk_horiz_Ecl_top_neg_ECorr2->SetMinimum(0.);
  gr_sigm_delt_cord_trk_horiz_Ecl_top_neg_ECorr2->Draw("AP");
  c1->Print("sigm_delt_cord_trk_horiz_Ecl_top_neg_ECorr2.eps");
  c1->Print("sigm_delt_cord_trk_horiz_Ecl_top_neg_ECorr2.pdf");
  c1->Print("sigm_delt_cord_trk_horiz_Ecl_top_neg_ECorr2.gif");

  TMultiGraph *mtgr_mean_top_pos = new TMultiGraph();
  mtgr_mean_top_pos->SetTitle("; P (GeV) ; #mu(X_{cl} - X_{tr}) mm");
  mtgr_mean_top_pos->Add(gr_mean_delt_cord_trk_horiz_Ecl_top_pos_ECorr2);
  mtgr_mean_top_pos->Add(gr_mean_delt_cord_trk_horiz_Ecl_top_pos2);
  mtgr_mean_top_pos->Draw("AP");
  mtgr_mean_top_pos->SetMaximum(10.);
  mtgr_mean_top_pos->SetMinimum(0.);
  
  c1->Print("mtgr_mean_top_pos2.eps");
  c1->Print("mtgr_mean_top_pos2.pdf");
  c1->Print("mtgr_mean_top_pos2.gif");

  TMultiGraph *mtgr_sigm_top_pos = new TMultiGraph();
  mtgr_sigm_top_pos->SetTitle("; P (GeV) ; #sigma(X_{cl} - X_{tr}) mm");
  mtgr_sigm_top_pos->Add(gr_sigm_delt_cord_trk_horiz_Ecl_top_pos_ECorr2);
  mtgr_sigm_top_pos->Add(gr_sigm_delt_cord_trk_horiz_Ecl_top_pos2);
  mtgr_sigm_top_pos->Draw("AP");
  mtgr_sigm_top_pos->SetMaximum(10.);
  mtgr_sigm_top_pos->SetMinimum(0.);
  c1->Print("mtgr_sigm_top_pos2.eps");
  c1->Print("mtgr_sigm_top_pos2.pdf");
  c1->Print("mtgr_sigm_top_pos2.gif");
  
  TMultiGraph *mtgr_mean_top_neg = new TMultiGraph();
  mtgr_mean_top_neg->SetTitle("; P (GeV) ; #mu(X_{cl} - X_{tr}) mm");
  mtgr_mean_top_neg->Add(gr_mean_delt_cord_trk_horiz_Ecl_top_neg_ECorr2);
  mtgr_mean_top_neg->Add(gr_mean_delt_cord_trk_horiz_Ecl_top_neg2);
  mtgr_mean_top_neg->Draw("AP");
  mtgr_mean_top_neg->SetMaximum(10.);
  mtgr_mean_top_neg->SetMinimum(0.);
  
  c1->Print("mtgr_mean_top_neg2.eps");
  c1->Print("mtgr_mean_top_neg2.pdf");
  c1->Print("mtgr_mean_top_neg2.gif");

  TMultiGraph *mtgr_sigm_top_neg = new TMultiGraph();
  mtgr_sigm_top_neg->SetTitle("; P (GeV) ; #sigma(X_{cl} - X_{tr}) mm");
  mtgr_sigm_top_neg->Add(gr_sigm_delt_cord_trk_horiz_Ecl_top_neg_ECorr2);
  mtgr_sigm_top_neg->Add(gr_sigm_delt_cord_trk_horiz_Ecl_top_neg2);
  mtgr_sigm_top_neg->Draw("AP");
  mtgr_sigm_top_neg->SetMaximum(10.);
  mtgr_sigm_top_neg->SetMinimum(0.);
  c1->Print("mtgr_sigm_top_neg2.eps");
  c1->Print("mtgr_sigm_top_neg2.pdf");
  c1->Print("mtgr_sigm_top_neg2.gif");


  //============================== Now Bottom =================================

  sl_fit->SetAll(h_delt_cord_trk_horiz_Ecl_bot_pos2, "h_delt_cord_trk_horiz_Ecl_bot_pos2", f_Gaus, 20, 0.09, 0.77);

  sl_fit->Do_SliceFit();

  TGraphErrors *gr_mean_delt_cord_trk_horiz_Ecl_bot_pos2 = sl_fit->GetGrMean();
  gr_mean_delt_cord_trk_horiz_Ecl_bot_pos2->SetTitle("; P (GeV) ; X_{cl} - X_{tr} mm");
  gr_mean_delt_cord_trk_horiz_Ecl_bot_pos2->SetMarkerStyle(20);
  gr_mean_delt_cord_trk_horiz_Ecl_bot_pos2->SetMarkerColor(2);
  // gr_mean_delt_cord_trk_horiz_Ecl_bot_pos2->SetMaximum(10.);
  // gr_mean_delt_cord_trk_horiz_Ecl_bot_pos2->SetMinimum(0.);
  gr_mean_delt_cord_trk_horiz_Ecl_bot_pos2->Draw("AP");
  c1->Print("mean_delt_cord_trk_horiz_Ecl_bot_pos2.eps");
  c1->Print("mean_delt_cord_trk_horiz_Ecl_bot_pos2.pdf");
  c1->Print("mean_delt_cord_trk_horiz_Ecl_bot_pos2.gif");

  TGraphErrors *gr_sigm_delt_cord_trk_horiz_Ecl_bot_pos2 = sl_fit->GetGrSigm();
  gr_sigm_delt_cord_trk_horiz_Ecl_bot_pos2->SetTitle("; P (GeV) ; X_{cl} - X_{tr} mm");
  gr_sigm_delt_cord_trk_horiz_Ecl_bot_pos2->SetMarkerStyle(20);
  gr_sigm_delt_cord_trk_horiz_Ecl_bot_pos2->SetMarkerColor(2);
  // gr_sigm_delt_cord_trk_horiz_Ecl_bot_pos2->SetMaximum(20.);
  // gr_sigm_delt_cord_trk_horiz_Ecl_bot_pos2->SetMinimum(0.);
  gr_sigm_delt_cord_trk_horiz_Ecl_bot_pos2->Draw("AP");
  c1->Print("sigm_delt_cord_trk_horiz_Ecl_bot_pos2.eps");
  c1->Print("sigm_delt_cord_trk_horiz_Ecl_bot_pos2.pdf");
  c1->Print("sigm_delt_cord_trk_horiz_Ecl_bot_pos2.gif");
  

  sl_fit->SetAll(h_delt_cord_trk_horiz_Ecl_bot_neg2, "h_delt_cord_trk_horiz_Ecl_bot_neg2", f_Gaus, 20, 0.09, 0.77);
  sl_fit->Do_SliceFit();
  TGraphErrors *gr_mean_delt_cord_trk_horiz_Ecl_bot_neg2 = sl_fit->GetGrMean();
  gr_mean_delt_cord_trk_horiz_Ecl_bot_neg2->SetTitle("; P (GeV) ; X_{cl} - X_{tr} mm");
  gr_mean_delt_cord_trk_horiz_Ecl_bot_neg2->SetMarkerStyle(20);
  gr_mean_delt_cord_trk_horiz_Ecl_bot_neg2->SetMarkerColor(2);
  gr_mean_delt_cord_trk_horiz_Ecl_bot_neg2->SetMaximum(5.);
  gr_mean_delt_cord_trk_horiz_Ecl_bot_neg2->SetMinimum(10.);
  gr_mean_delt_cord_trk_horiz_Ecl_bot_neg2->Draw("AP");
  c1->Print("mean_delt_cord_trk_horiz_Ecl_bot_neg2.eps");
  c1->Print("mean_delt_cord_trk_horiz_Ecl_bot_neg2.pdf");
  c1->Print("mean_delt_cord_trk_horiz_Ecl_bot_neg2.gif");
  
  TGraphErrors *gr_sigm_delt_cord_trk_horiz_Ecl_bot_neg2 = sl_fit->GetGrSigm();
  gr_sigm_delt_cord_trk_horiz_Ecl_bot_neg2->SetTitle("; P (GeV) ; X_{cl} - X_{tr} mm");
  gr_sigm_delt_cord_trk_horiz_Ecl_bot_neg2->SetMarkerStyle(20);
  gr_sigm_delt_cord_trk_horiz_Ecl_bot_neg2->SetMarkerColor(2);
  gr_sigm_delt_cord_trk_horiz_Ecl_bot_neg2->SetMaximum(20.);
  gr_sigm_delt_cord_trk_horiz_Ecl_bot_neg2->SetMinimum(0.);
  gr_sigm_delt_cord_trk_horiz_Ecl_bot_neg2->Draw("AP");
  c1->Print("sigm_delt_cord_trk_horiz_Ecl_bot_neg2.eps");
  c1->Print("sigm_delt_cord_trk_horiz_Ecl_bot_neg2.pdf");
  c1->Print("sigm_delt_cord_trk_horiz_Ecl_bot_neg2.gif");

  
  sl_fit->SetAll(h_delt_cord_trk_horiz_Ecl_bot_pos_ECorr2, "h_delt_cord_trk_horiz_Ecl_bot_pos_ECorr2", f_Gaus, 15, 0.45, 0.77);
  sl_fit->Do_SliceFit();
  
  TGraphErrors *gr_mean_delt_cord_trk_horiz_Ecl_bot_pos_ECorr2 = sl_fit->GetGrMean();
  gr_mean_delt_cord_trk_horiz_Ecl_bot_pos_ECorr2->SetTitle("; P (GeV) ; X_{cl} - X_{tr} mm");
  gr_mean_delt_cord_trk_horiz_Ecl_bot_pos_ECorr2->SetMarkerStyle(22);
  gr_mean_delt_cord_trk_horiz_Ecl_bot_pos_ECorr2->SetMarkerColor(4);
  // gr_mean_delt_cord_trk_horiz_Ecl_bot_pos_ECorr2->SetMaximum(10.);
  // gr_mean_delt_cord_trk_horiz_Ecl_bot_pos_ECorr2->SetMinimum(0.);
  gr_mean_delt_cord_trk_horiz_Ecl_bot_pos_ECorr2->Draw("AP");
  c1->Print("mean_delt_cord_trk_horiz_Ecl_bot_pos_ECorr2.eps");
  c1->Print("mean_delt_cord_trk_horiz_Ecl_bot_pos_ECorr2.pdf");
  c1->Print("mean_delt_cord_trk_horiz_Ecl_bot_pos_ECorr2.gif");
  
  TGraphErrors *gr_sigm_delt_cord_trk_horiz_Ecl_bot_pos_ECorr2 = sl_fit->GetGrSigm();
  gr_sigm_delt_cord_trk_horiz_Ecl_bot_pos_ECorr2->SetTitle("; P (GeV) ; X_{cl} - X_{tr} mm");
  gr_sigm_delt_cord_trk_horiz_Ecl_bot_pos_ECorr2->SetMarkerStyle(22);
  gr_sigm_delt_cord_trk_horiz_Ecl_bot_pos_ECorr2->SetMarkerColor(4);
  // gr_sigm_delt_cord_trk_horiz_Ecl_bot_pos_ECorr2->SetMaximum(22.);
  // gr_sigm_delt_cord_trk_horiz_Ecl_bot_pos_ECorr2->SetMinimum(0.);
  gr_sigm_delt_cord_trk_horiz_Ecl_bot_pos_ECorr2->Draw("AP");
  c1->Print("sigm_delt_cord_trk_horiz_Ecl_bot_pos_ECorr2.eps");
  c1->Print("sigm_delt_cord_trk_horiz_Ecl_bot_pos_ECorr2.pdf");
  c1->Print("sigm_delt_cord_trk_horiz_Ecl_bot_pos_ECorr2.gif");
  

  sl_fit->SetAll(h_delt_cord_trk_horiz_Ecl_bot_neg_ECorr2, "h_delt_cord_trk_horiz_Ecl_bot_neg_ECorr2", f_Gaus, 15, 0.4, 0.77);
  sl_fit->Do_SliceFit();
  TGraphErrors *gr_mean_delt_cord_trk_horiz_Ecl_bot_neg_ECorr2 = sl_fit->GetGrMean();
  gr_mean_delt_cord_trk_horiz_Ecl_bot_neg_ECorr2->SetTitle("; P (GeV) ; X_{cl} - X_{tr} mm");
  gr_mean_delt_cord_trk_horiz_Ecl_bot_neg_ECorr2->SetMarkerStyle(22);
  gr_mean_delt_cord_trk_horiz_Ecl_bot_neg_ECorr2->SetMarkerColor(4);
  // gr_mean_delt_cord_trk_horiz_Ecl_bot_neg_ECorr2->SetMaximum(10.);
  // gr_mean_delt_cord_trk_horiz_Ecl_bot_neg_ECorr2->SetMinimum(0.);
  gr_mean_delt_cord_trk_horiz_Ecl_bot_neg_ECorr2->Draw("AP");
  c1->Print("mean_delt_cord_trk_horiz_Ecl_bot_neg_ECorr2.eps");
  c1->Print("mean_delt_cord_trk_horiz_Ecl_bot_neg_ECorr2.pdf");
  c1->Print("mean_delt_cord_trk_horiz_Ecl_bot_neg_ECorr2.gif");
  
  TGraphErrors *gr_sigm_delt_cord_trk_horiz_Ecl_bot_neg_ECorr2 = sl_fit->GetGrSigm();
  gr_sigm_delt_cord_trk_horiz_Ecl_bot_neg_ECorr2->SetTitle("; P (GeV) ; X_{cl} - X_{tr} mm");
  gr_sigm_delt_cord_trk_horiz_Ecl_bot_neg_ECorr2->SetMarkerStyle(22);
  gr_sigm_delt_cord_trk_horiz_Ecl_bot_neg_ECorr2->SetMarkerColor(4);
  // gr_sigm_delt_cord_trk_horiz_Ecl_bot_neg_ECorr2->SetMaximum(10.);
  // gr_sigm_delt_cord_trk_horiz_Ecl_bot_neg_ECorr2->SetMinimum(0.);
  gr_sigm_delt_cord_trk_horiz_Ecl_bot_neg_ECorr2->Draw("AP");
  c1->Print("sigm_delt_cord_trk_horiz_Ecl_bot_neg_ECorr2.eps");
  c1->Print("sigm_delt_cord_trk_horiz_Ecl_bot_neg_ECorr2.pdf");
  c1->Print("sigm_delt_cord_trk_horiz_Ecl_bot_neg_ECorr2.gif");

  TMultiGraph *mtgr_mean_bot_pos = new TMultiGraph();
  mtgr_mean_bot_pos->SetTitle("; P (GeV) ; #mu(X_{cl} - X_{tr}) mm");
  mtgr_mean_bot_pos->Add(gr_mean_delt_cord_trk_horiz_Ecl_bot_pos_ECorr2);
  mtgr_mean_bot_pos->Add(gr_mean_delt_cord_trk_horiz_Ecl_bot_pos2);
  mtgr_mean_bot_pos->Draw("AP");
  // mtgr_mean_bot_pos->SetMaximum(10.);
  // mtgr_mean_bot_pos->SetMinimum(0.);
  
  c1->Print("mtgr_mean_bot_pos2.eps");
  c1->Print("mtgr_mean_bot_pos2.pdf");
  c1->Print("mtgr_mean_bot_pos2.gif");

  TMultiGraph *mtgr_sigm_bot_pos = new TMultiGraph();
  mtgr_sigm_bot_pos->SetTitle("; P (GeV) ; #sigma(X_{cl} - X_{tr}) mm");
  mtgr_sigm_bot_pos->Add(gr_sigm_delt_cord_trk_horiz_Ecl_bot_pos_ECorr2);
  mtgr_sigm_bot_pos->Add(gr_sigm_delt_cord_trk_horiz_Ecl_bot_pos2);
  mtgr_sigm_bot_pos->Draw("AP");
  // mtgr_sigm_bot_pos->SetMaximum(10.);
  // mtgr_sigm_bot_pos->SetMinimum(0.);
  c1->Print("mtgr_sigm_bot_pos2.eps");
  c1->Print("mtgr_sigm_bot_pos2.pdf");
  c1->Print("mtgr_sigm_bot_pos2.gif");
  
  TMultiGraph *mtgr_mean_bot_neg = new TMultiGraph();
  mtgr_mean_bot_neg->SetTitle("; P (GeV) ; #mu(X_{cl} - X_{tr}) mm");
  mtgr_mean_bot_neg->Add(gr_mean_delt_cord_trk_horiz_Ecl_bot_neg_ECorr2);
  mtgr_mean_bot_neg->Add(gr_mean_delt_cord_trk_horiz_Ecl_bot_neg2);
  mtgr_mean_bot_neg->Draw("AP");
  // mtgr_mean_bot_neg->SetMaximum(10.);
  // mtgr_mean_bot_neg->SetMinimum(0.);
  
  c1->Print("mtgr_mean_bot_neg2.eps");
  c1->Print("mtgr_mean_bot_neg2.pdf");
  c1->Print("mtgr_mean_bot_neg2.gif");

  TMultiGraph *mtgr_sigm_bot_neg = new TMultiGraph();
  mtgr_sigm_bot_neg->SetTitle("; P (GeV) ; #sigma(X_{cl} - X_{tr}) mm");
  mtgr_sigm_bot_neg->Add(gr_sigm_delt_cord_trk_horiz_Ecl_bot_neg_ECorr2);
  mtgr_sigm_bot_neg->Add(gr_sigm_delt_cord_trk_horiz_Ecl_bot_neg2);
  mtgr_sigm_bot_neg->Draw("AP");
  // mtgr_sigm_bot_neg->SetMaximum(10.);
  // mtgr_sigm_bot_neg->SetMinimum(0.);
  c1->Print("mtgr_sigm_bot_neg2.eps");
  c1->Print("mtgr_sigm_bot_neg2.pdf");
  c1->Print("mtgr_sigm_bot_neg2.gif");


  // ==================== Dependence ox X coordinate ========================
  
  TH2D *h_delt_cord_trk_horiz_Xcl_bot_pos2 = (TH2D*)file_in_Uncorr->Get("h_delt_cord_trk_horiz_Xcl_bot_pos2");
  h_delt_cord_trk_horiz_Xcl_bot_pos2->SetTitle("; X_{cl} mm; X_cl - X_tr mm");
  h_delt_cord_trk_horiz_Xcl_bot_pos2->Draw("colz");
  line1->DrawLine(-300., 0., 360., 0.);
  c1->Print(Form("delt_coord_horiz_Xcl_bot_pos2_%d.eps", run));
  c1->Print(Form("delt_coord_horiz_Xcl_bot_pos2_%d.pdf", run));
  c1->Print(Form("delt_coord_horiz_Xcl_bot_pos2_%d.gif", run));

  TH2D *h_delt_cord_trk_horiz_Xcl_bot_neg2 = (TH2D*)file_in_Uncorr->Get("h_delt_cord_trk_horiz_Xcl_bot_neg2");
  h_delt_cord_trk_horiz_Xcl_bot_neg2->SetTitle("; X_{cl} mm; X_cl - X_tr mm");
  h_delt_cord_trk_horiz_Xcl_bot_neg2->Draw("colz");
  line1->DrawLine(-300., 0., 360., 0.);
  c1->Print(Form("delt_coord_horiz_Xcl_bot_neg2_%d.eps", run));
  c1->Print(Form("delt_coord_horiz_Xcl_bot_neg2_%d.pdf", run));
  c1->Print(Form("delt_coord_horiz_Xcl_bot_neg2_%d.gif", run));

  TH2D *h_delt_cord_trk_horiz_Xcl_top_pos2 = (TH2D*)file_in_Uncorr->Get("h_delt_cord_trk_horiz_Xcl_top_pos2");
  h_delt_cord_trk_horiz_Xcl_top_pos2->SetTitle("; X_{cl} mm; X_cl - X_tr mm");
  h_delt_cord_trk_horiz_Xcl_top_pos2->Draw("colz");
  line1->DrawLine(-300., 0., 360., 0.);
  c1->Print(Form("delt_coord_horiz_Xcl_top_pos2_%d.eps", run));
  c1->Print(Form("delt_coord_horiz_Xcl_top_pos2_%d.pdf", run));
  c1->Print(Form("delt_coord_horiz_Xcl_top_pos2_%d.gif", run));

  TH2D *h_delt_cord_trk_horiz_Xcl_top_neg2 = (TH2D*)file_in_Uncorr->Get("h_delt_cord_trk_horiz_Xcl_top_neg2");
  h_delt_cord_trk_horiz_Xcl_top_neg2->SetTitle("; X_{cl} mm; X_cl - X_tr mm");
  h_delt_cord_trk_horiz_Xcl_top_neg2->Draw("colz");
  line1->DrawLine(-300., 0., 360., 0.);
  c1->Print(Form("delt_coord_horiz_Xcl_top_neg2_%d.eps", run));
  c1->Print(Form("delt_coord_horiz_Xcl_top_neg2_%d.pdf", run));
  c1->Print(Form("delt_coord_horiz_Xcl_top_neg2_%d.gif", run));


  //========================= Starting Slice Fitting =======================


  //=============== Pos Bottom ===========================
  sl_fit->SetAll(h_delt_cord_trk_horiz_Xcl_bot_pos2, "delt_cord_horiz_Xcl_bot_pos2", f_Gaus, 20, 40., 359.);
  sl_fit->Do_SliceFit();
  TGraphErrors *gr_mean_delt_cord_trk_horiz_Xcl_bot_pos_EUncorr2 = sl_fit->GetGrMean();
  gr_mean_delt_cord_trk_horiz_Xcl_bot_pos_EUncorr2->SetTitle("; X_{cl} mm; #mu(X_{cl} - x_{tr}) mm");
  gr_mean_delt_cord_trk_horiz_Xcl_bot_pos_EUncorr2->SetMarkerColor(2);
  gr_mean_delt_cord_trk_horiz_Xcl_bot_pos_EUncorr2->SetMarkerStyle(20);
  gr_mean_delt_cord_trk_horiz_Xcl_bot_pos_EUncorr2->Draw("AP");
  c1->Print(Form("gr_mean_delt_cord_trk_horiz_Xcl_bot_pos_EUncorr2_%d.eps", run));
  c1->Print(Form("gr_mean_delt_cord_trk_horiz_Xcl_bot_pos_EUncorr2_%d.pdf", run));
  c1->Print(Form("gr_mean_delt_cord_trk_horiz_Xcl_bot_pos_EUncorr2_%d.gif", run));
  
  TGraphErrors *gr_sigm_delt_cord_trk_horiz_Xcl_bot_pos_EUncorr2 = sl_fit->GetGrSigm();
  gr_sigm_delt_cord_trk_horiz_Xcl_bot_pos_EUncorr2->SetTitle("; X_{cl} mm; #sigma(X_{cl} - x_{tr}) mm");
  gr_sigm_delt_cord_trk_horiz_Xcl_bot_pos_EUncorr2->SetMarkerColor(2);
  gr_sigm_delt_cord_trk_horiz_Xcl_bot_pos_EUncorr2->SetMarkerStyle(20);
  gr_sigm_delt_cord_trk_horiz_Xcl_bot_pos_EUncorr2->Draw("AP");
  c1->Print(Form("gr_sigm_delt_cord_trk_horiz_Xcl_bot_pos_EUncorr2_%d.eps", run));
  c1->Print(Form("gr_sigm_delt_cord_trk_horiz_Xcl_bot_pos_EUncorr2_%d.pdf", run));
  c1->Print(Form("gr_sigm_delt_cord_trk_horiz_Xcl_bot_pos_EUncorr2_%d.gif", run));
 
  //=============== Neg Bottom ===========================
  sl_fit->SetAll(h_delt_cord_trk_horiz_Xcl_bot_neg2, "delt_cord_horiz_Xcl_bot_neg2", f_Gaus, 15, -281., 0.);
  sl_fit->Do_SliceFit();
  TGraphErrors *gr_mean_delt_cord_trk_horiz_Xcl_bot_neg_EUncorr2 = sl_fit->GetGrMean();
  gr_mean_delt_cord_trk_horiz_Xcl_bot_neg_EUncorr2->SetTitle("; X_{cl} mm; #mu(X_{cl} - x_{tr}) mm");
  gr_mean_delt_cord_trk_horiz_Xcl_bot_neg_EUncorr2->SetMarkerColor(2);
  gr_mean_delt_cord_trk_horiz_Xcl_bot_neg_EUncorr2->SetMarkerStyle(20);
  gr_mean_delt_cord_trk_horiz_Xcl_bot_neg_EUncorr2->Draw("AP");
  c1->Print(Form("gr_mean_delt_cord_trk_horiz_Xcl_bot_neg_EUncorr2_%d.eps", run));
  c1->Print(Form("gr_mean_delt_cord_trk_horiz_Xcl_bot_neg_EUncorr2_%d.pdf", run));
  c1->Print(Form("gr_mean_delt_cord_trk_horiz_Xcl_bot_neg_EUncorr2_%d.gif", run));
  
  TGraphErrors *gr_sigm_delt_cord_trk_horiz_Xcl_bot_neg_EUncorr2 = sl_fit->GetGrSigm();
  gr_sigm_delt_cord_trk_horiz_Xcl_bot_neg_EUncorr2->SetTitle("; X_{cl} mm; #sigma(X_{cl} - x_{tr}) mm");
  gr_sigm_delt_cord_trk_horiz_Xcl_bot_neg_EUncorr2->SetMarkerColor(2);
  gr_sigm_delt_cord_trk_horiz_Xcl_bot_neg_EUncorr2->SetMarkerStyle(20);
  gr_sigm_delt_cord_trk_horiz_Xcl_bot_neg_EUncorr2->Draw("AP");
  c1->Print(Form("gr_sigm_delt_cord_trk_horiz_Xcl_bot_neg_EUncorr2_%d.eps", run));
  c1->Print(Form("gr_sigm_delt_cord_trk_horiz_Xcl_bot_neg_EUncorr2_%d.pdf", run));
  c1->Print(Form("gr_sigm_delt_cord_trk_horiz_Xcl_bot_neg_EUncorr2_%d.gif", run));
  

  //=============== Pos Top ===========================
  sl_fit->SetAll(h_delt_cord_trk_horiz_Xcl_top_pos2, "delt_cord_horiz_Xcl_top_pos2", f_Gaus, 20, 40., 359.);
  sl_fit->Do_SliceFit();
  TGraphErrors *gr_mean_delt_cord_trk_horiz_Xcl_top_pos_EUncorr2 = sl_fit->GetGrMean();
  gr_mean_delt_cord_trk_horiz_Xcl_top_pos_EUncorr2->SetTitle("; X_{cl} mm; #mu(X_{cl} - x_{tr}) mm");
  gr_mean_delt_cord_trk_horiz_Xcl_top_pos_EUncorr2->SetMarkerColor(2);
  gr_mean_delt_cord_trk_horiz_Xcl_top_pos_EUncorr2->SetMarkerStyle(20);
  gr_mean_delt_cord_trk_horiz_Xcl_top_pos_EUncorr2->Draw("AP");
  c1->Print(Form("gr_mean_delt_cord_trk_horiz_Xcl_top_pos_EUncorr2_%d.eps", run));
  c1->Print(Form("gr_mean_delt_cord_trk_horiz_Xcl_top_pos_EUncorr2_%d.pdf", run));
  c1->Print(Form("gr_mean_delt_cord_trk_horiz_Xcl_top_pos_EUncorr2_%d.gif", run));
  
  TGraphErrors *gr_sigm_delt_cord_trk_horiz_Xcl_top_pos_EUncorr2 = sl_fit->GetGrSigm();
  gr_sigm_delt_cord_trk_horiz_Xcl_top_pos_EUncorr2->SetTitle("; X_{cl} mm; #sigma(X_{cl} - x_{tr}) mm");
  gr_sigm_delt_cord_trk_horiz_Xcl_top_pos_EUncorr2->SetMarkerColor(2);
  gr_sigm_delt_cord_trk_horiz_Xcl_top_pos_EUncorr2->SetMarkerStyle(20);
  gr_sigm_delt_cord_trk_horiz_Xcl_top_pos_EUncorr2->Draw("AP");
  c1->Print(Form("gr_sigm_delt_cord_trk_horiz_Xcl_top_pos_EUncorr2_%d.eps", run));
  c1->Print(Form("gr_sigm_delt_cord_trk_horiz_Xcl_top_pos_EUncorr2_%d.pdf", run));
  c1->Print(Form("gr_sigm_delt_cord_trk_horiz_Xcl_top_pos_EUncorr2_%d.gif", run));
 
  //=============== Neg Top ===========================
  sl_fit->SetAll(h_delt_cord_trk_horiz_Xcl_top_neg2, "delt_cord_horiz_Xcl_top_neg2", f_Gaus, 15, -281., 0.);
  sl_fit->Do_SliceFit();
  TGraphErrors *gr_mean_delt_cord_trk_horiz_Xcl_top_neg_EUncorr2 = sl_fit->GetGrMean();
  gr_mean_delt_cord_trk_horiz_Xcl_top_neg_EUncorr2->SetTitle("; X_{cl} mm; #mu(X_{cl} - x_{tr}) mm");
  gr_mean_delt_cord_trk_horiz_Xcl_top_neg_EUncorr2->SetMarkerColor(2);
  gr_mean_delt_cord_trk_horiz_Xcl_top_neg_EUncorr2->SetMarkerStyle(20);
  gr_mean_delt_cord_trk_horiz_Xcl_top_neg_EUncorr2->Draw("AP");
  c1->Print(Form("gr_mean_delt_cord_trk_horiz_Xcl_top_neg_EUncorr2_%d.eps", run));
  c1->Print(Form("gr_mean_delt_cord_trk_horiz_Xcl_top_neg_EUncorr2_%d.pdf", run));
  c1->Print(Form("gr_mean_delt_cord_trk_horiz_Xcl_top_neg_EUncorr2_%d.gif", run));
  
  TGraphErrors *gr_sigm_delt_cord_trk_horiz_Xcl_top_neg_EUncorr2 = sl_fit->GetGrSigm();
  gr_sigm_delt_cord_trk_horiz_Xcl_top_neg_EUncorr2->SetTitle("; X_{cl} mm; #sigma(X_{cl} - x_{tr}) mm");
  gr_sigm_delt_cord_trk_horiz_Xcl_top_neg_EUncorr2->SetMarkerColor(2);
  gr_sigm_delt_cord_trk_horiz_Xcl_top_neg_EUncorr2->SetMarkerStyle(20);
  gr_sigm_delt_cord_trk_horiz_Xcl_top_neg_EUncorr2->Draw("AP");
  c1->Print(Form("gr_sigm_delt_cord_trk_horiz_Xcl_top_neg_EUncorr2_%d.eps", run));
  c1->Print(Form("gr_sigm_delt_cord_trk_horiz_Xcl_top_neg_EUncorr2_%d.pdf", run));
  c1->Print(Form("gr_sigm_delt_cord_trk_horiz_Xcl_top_neg_EUncorr2_%d.gif", run));


  // ====================== Corrected Clusters ================================

  // ==================== Dependence ox X coordinate ========================
  
  TH2D *h_delt_cord_trk_horiz_Xcl_bot_pos_ECorr2 = (TH2D*)file_in_ECorr->Get("h_delt_cord_trk_horiz_Xcl_bot_pos2");
  h_delt_cord_trk_horiz_Xcl_bot_pos_ECorr2->SetTitle("; X_{cl} mm; X_cl - X_tr mm");
  h_delt_cord_trk_horiz_Xcl_bot_pos_ECorr2->Draw("colz");
  line1->DrawLine(-300., 0., 360., 0.);
  c1->Print(Form("delt_coord_horiz_Xcl_bot_pos_ECorr2_%d.eps", run));
  c1->Print(Form("delt_coord_horiz_Xcl_bot_pos_ECorr2_%d.pdf", run));
  c1->Print(Form("delt_coord_horiz_Xcl_bot_pos_ECorr2_%d.gif", run));

  TH2D *h_delt_cord_trk_horiz_Xcl_bot_neg_ECorr2 = (TH2D*)file_in_ECorr->Get("h_delt_cord_trk_horiz_Xcl_bot_neg2");
  h_delt_cord_trk_horiz_Xcl_bot_neg_ECorr2->SetTitle("; X_{cl} mm; X_cl - X_tr mm");
  h_delt_cord_trk_horiz_Xcl_bot_neg_ECorr2->Draw("colz");
  line1->DrawLine(-300., 0., 360., 0.);
  c1->Print(Form("delt_coord_horiz_Xcl_bot_neg_ECorr2_%d.eps", run));
  c1->Print(Form("delt_coord_horiz_Xcl_bot_neg_ECorr2_%d.pdf", run));
  c1->Print(Form("delt_coord_horiz_Xcl_bot_neg_ECorr2_%d.gif", run));

  TH2D *h_delt_cord_trk_horiz_Xcl_top_pos_ECorr2 = (TH2D*)file_in_ECorr->Get("h_delt_cord_trk_horiz_Xcl_top_pos2");
  h_delt_cord_trk_horiz_Xcl_top_pos_ECorr2->SetTitle("; X_{cl} mm; X_cl - X_tr mm");
  h_delt_cord_trk_horiz_Xcl_top_pos_ECorr2->Draw("colz");
  line1->DrawLine(-300., 0., 360., 0.);
  c1->Print(Form("delt_coord_horiz_Xcl_top_pos_ECorr2_%d.eps", run));
  c1->Print(Form("delt_coord_horiz_Xcl_top_pos_ECorr2_%d.pdf", run));
  c1->Print(Form("delt_coord_horiz_Xcl_top_pos_ECorr2_%d.gif", run));

  TH2D *h_delt_cord_trk_horiz_Xcl_top_neg_ECorr2 = (TH2D*)file_in_ECorr->Get("h_delt_cord_trk_horiz_Xcl_top_neg2");
  h_delt_cord_trk_horiz_Xcl_top_neg_ECorr2->SetTitle("; X_{cl} mm; X_cl - X_tr mm");
  h_delt_cord_trk_horiz_Xcl_top_neg_ECorr2->Draw("colz");
  line1->DrawLine(-300., 0., 360., 0.);
  c1->Print(Form("delt_coord_horiz_Xcl_top_neg_ECorr2_%d.eps", run));
  c1->Print(Form("delt_coord_horiz_Xcl_top_neg_ECorr2_%d.pdf", run));
  c1->Print(Form("delt_coord_horiz_Xcl_top_neg_ECorr2_%d.gif", run));
  
  //========================= Starting Slice Fitting =======================

  //=============== Pos Bottom ===========================
  sl_fit->SetAll(h_delt_cord_trk_horiz_Xcl_bot_pos_ECorr2, "delt_cord_horiz_Xcl_bot_pos_ECorr2", f_Gaus, 15, 50., 240.);
  sl_fit->Do_SliceFit();
  TGraphErrors *gr_mean_delt_cord_trk_horiz_Xcl_bot_pos_ECorr2 = sl_fit->GetGrMean();
  gr_mean_delt_cord_trk_horiz_Xcl_bot_pos_ECorr2->SetTitle("; X_{cl} mm; #mu(X_{cl} - x_{tr}) mm");
  gr_mean_delt_cord_trk_horiz_Xcl_bot_pos_ECorr2->SetMarkerColor(4);
  gr_mean_delt_cord_trk_horiz_Xcl_bot_pos_ECorr2->SetMarkerStyle(22);
  gr_mean_delt_cord_trk_horiz_Xcl_bot_pos_ECorr2->Draw("AP");
  c1->Print(Form("gr_mean_delt_cord_trk_horiz_Xcl_bot_pos_ECorr2_%d.eps", run));
  c1->Print(Form("gr_mean_delt_cord_trk_horiz_Xcl_bot_pos_ECorr2_%d.pdf", run));
  c1->Print(Form("gr_mean_delt_cord_trk_horiz_Xcl_bot_pos_ECorr2_%d.gif", run));
  
  TGraphErrors *gr_sigm_delt_cord_trk_horiz_Xcl_bot_pos_ECorr2 = sl_fit->GetGrSigm();
  gr_sigm_delt_cord_trk_horiz_Xcl_bot_pos_ECorr2->SetTitle("; X_{cl} mm; #sigma(X_{cl} - x_{tr}) mm");
  gr_sigm_delt_cord_trk_horiz_Xcl_bot_pos_ECorr2->SetMarkerColor(4);
  gr_sigm_delt_cord_trk_horiz_Xcl_bot_pos_ECorr2->SetMarkerStyle(22);
  gr_sigm_delt_cord_trk_horiz_Xcl_bot_pos_ECorr2->Draw("AP");
  c1->Print(Form("gr_sigm_delt_cord_trk_horiz_Xcl_bot_pos_ECorr2_%d.eps", run));
  c1->Print(Form("gr_sigm_delt_cord_trk_horiz_Xcl_bot_pos_ECorr2_%d.pdf", run));
  c1->Print(Form("gr_sigm_delt_cord_trk_horiz_Xcl_bot_pos_ECorr2_%d.gif", run));
 
  //=============== Neg Bottom ===========================
  sl_fit->SetAll(h_delt_cord_trk_horiz_Xcl_bot_neg_ECorr2, "delt_cord_horiz_Xcl_bot_neg_ECorr2", f_Gaus, 15, -200., 0.);
  sl_fit->Do_SliceFit();
  TGraphErrors *gr_mean_delt_cord_trk_horiz_Xcl_bot_neg_ECorr2 = sl_fit->GetGrMean();
  gr_mean_delt_cord_trk_horiz_Xcl_bot_neg_ECorr2->SetTitle("; X_{cl} mm; #mu(X_{cl} - x_{tr}) mm");
  gr_mean_delt_cord_trk_horiz_Xcl_bot_neg_ECorr2->SetMarkerColor(4);
  gr_mean_delt_cord_trk_horiz_Xcl_bot_neg_ECorr2->SetMarkerStyle(22);
  gr_mean_delt_cord_trk_horiz_Xcl_bot_neg_ECorr2->Draw("AP");
  c1->Print(Form("gr_mean_delt_cord_trk_horiz_Xcl_bot_neg_ECorr2_%d.eps", run));
  c1->Print(Form("gr_mean_delt_cord_trk_horiz_Xcl_bot_neg_ECorr2_%d.pdf", run));
  c1->Print(Form("gr_mean_delt_cord_trk_horiz_Xcl_bot_neg_ECorr2_%d.gif", run));
  
  TGraphErrors *gr_sigm_delt_cord_trk_horiz_Xcl_bot_neg_ECorr2 = sl_fit->GetGrSigm();
  gr_sigm_delt_cord_trk_horiz_Xcl_bot_neg_ECorr2->SetTitle("; X_{cl} mm; #sigma(X_{cl} - x_{tr}) mm");
  gr_sigm_delt_cord_trk_horiz_Xcl_bot_neg_ECorr2->SetMarkerColor(4);
  gr_sigm_delt_cord_trk_horiz_Xcl_bot_neg_ECorr2->SetMarkerStyle(22);
  gr_sigm_delt_cord_trk_horiz_Xcl_bot_neg_ECorr2->Draw("AP");
  c1->Print(Form("gr_sigm_delt_cord_trk_horiz_Xcl_bot_neg_ECorr2_%d.eps", run));
  c1->Print(Form("gr_sigm_delt_cord_trk_horiz_Xcl_bot_neg_ECorr2_%d.pdf", run));
  c1->Print(Form("gr_sigm_delt_cord_trk_horiz_Xcl_bot_neg_ECorr2_%d.gif", run));
  

  //=============== Pos Top ===========================
  sl_fit->SetAll(h_delt_cord_trk_horiz_Xcl_top_pos_ECorr2, "delt_cord_horiz_Xcl_top_pos_ECorr2", f_Gaus, 15, 50., 240.);
  sl_fit->Do_SliceFit();
  TGraphErrors *gr_mean_delt_cord_trk_horiz_Xcl_top_pos_ECorr2 = sl_fit->GetGrMean();
  gr_mean_delt_cord_trk_horiz_Xcl_top_pos_ECorr2->SetTitle("; X_{cl} mm; #mu(X_{cl} - x_{tr}) mm");
  gr_mean_delt_cord_trk_horiz_Xcl_top_pos_ECorr2->SetMarkerColor(4);
  gr_mean_delt_cord_trk_horiz_Xcl_top_pos_ECorr2->SetMarkerStyle(22);
  gr_mean_delt_cord_trk_horiz_Xcl_top_pos_ECorr2->Draw("AP");
  c1->Print(Form("gr_mean_delt_cord_trk_horiz_Xcl_top_pos_ECorr2_%d.eps", run));
  c1->Print(Form("gr_mean_delt_cord_trk_horiz_Xcl_top_pos_ECorr2_%d.pdf", run));
  c1->Print(Form("gr_mean_delt_cord_trk_horiz_Xcl_top_pos_ECorr2_%d.gif", run));
  
  TGraphErrors *gr_sigm_delt_cord_trk_horiz_Xcl_top_pos_ECorr2 = sl_fit->GetGrSigm();
  gr_sigm_delt_cord_trk_horiz_Xcl_top_pos_ECorr2->SetTitle("; X_{cl} mm; #sigma(X_{cl} - x_{tr}) mm");
  gr_sigm_delt_cord_trk_horiz_Xcl_top_pos_ECorr2->SetMarkerColor(4);
  gr_sigm_delt_cord_trk_horiz_Xcl_top_pos_ECorr2->SetMarkerStyle(22);
  gr_sigm_delt_cord_trk_horiz_Xcl_top_pos_ECorr2->Draw("AP");
  c1->Print(Form("gr_sigm_delt_cord_trk_horiz_Xcl_top_pos_ECorr2_%d.eps", run));
  c1->Print(Form("gr_sigm_delt_cord_trk_horiz_Xcl_top_pos_ECorr2_%d.pdf", run));
  c1->Print(Form("gr_sigm_delt_cord_trk_horiz_Xcl_top_pos_ECorr2_%d.gif", run));
 
  //=============== Neg Top ===========================
  sl_fit->SetAll(h_delt_cord_trk_horiz_Xcl_top_neg_ECorr2, "delt_cord_horiz_Xcl_top_neg_ECorr2", f_Gaus, 15, -200., 0.);
  sl_fit->Do_SliceFit();
  TGraphErrors *gr_mean_delt_cord_trk_horiz_Xcl_top_neg_ECorr2 = sl_fit->GetGrMean();
  gr_mean_delt_cord_trk_horiz_Xcl_top_neg_ECorr2->SetTitle("; X_{cl} mm; #mu(X_{cl} - x_{tr}) mm");
  gr_mean_delt_cord_trk_horiz_Xcl_top_neg_ECorr2->SetMarkerColor(4);
  gr_mean_delt_cord_trk_horiz_Xcl_top_neg_ECorr2->SetMarkerStyle(22);
  gr_mean_delt_cord_trk_horiz_Xcl_top_neg_ECorr2->Draw("AP");
  c1->Print(Form("gr_mean_delt_cord_trk_horiz_Xcl_top_neg_ECorr2_%d.eps", run));
  c1->Print(Form("gr_mean_delt_cord_trk_horiz_Xcl_top_neg_ECorr2_%d.pdf", run));
  c1->Print(Form("gr_mean_delt_cord_trk_horiz_Xcl_top_neg_ECorr2_%d.gif", run));
  
  TGraphErrors *gr_sigm_delt_cord_trk_horiz_Xcl_top_neg_ECorr2 = sl_fit->GetGrSigm();
  gr_sigm_delt_cord_trk_horiz_Xcl_top_neg_ECorr2->SetTitle("; X_{cl} mm; #sigma(X_{cl} - x_{tr}) mm");
  gr_sigm_delt_cord_trk_horiz_Xcl_top_neg_ECorr2->SetMarkerColor(4);
  gr_sigm_delt_cord_trk_horiz_Xcl_top_neg_ECorr2->SetMarkerStyle(22);
  gr_sigm_delt_cord_trk_horiz_Xcl_top_neg_ECorr2->Draw("AP");
  c1->Print(Form("gr_sigm_delt_cord_trk_horiz_Xcl_top_neg_ECorr2_%d.eps", run));
  c1->Print(Form("gr_sigm_delt_cord_trk_horiz_Xcl_top_neg_ECorr2_%d.pdf", run));
  c1->Print(Form("gr_sigm_delt_cord_trk_horiz_Xcl_top_neg_ECorr2_%d.gif", run));


  // =================== MultiGraphs ===================================

  //================== Bottoms ============================
  
  TMultiGraph *mtgr_mean_delt_cord_trk_horiz_Xcl_bot_pos2 = new TMultiGraph();
  mtgr_mean_delt_cord_trk_horiz_Xcl_bot_pos2->Add(gr_mean_delt_cord_trk_horiz_Xcl_bot_pos_ECorr2);
  mtgr_mean_delt_cord_trk_horiz_Xcl_bot_pos2->Add(gr_mean_delt_cord_trk_horiz_Xcl_bot_pos_EUncorr2);
  mtgr_mean_delt_cord_trk_horiz_Xcl_bot_pos2->Draw("AP");
  mtgr_mean_delt_cord_trk_horiz_Xcl_bot_pos2->SetTitle("; X_{cl} mm; #mu(X_{cl} - x_{tr}) mm");
  mtgr_mean_delt_cord_trk_horiz_Xcl_bot_pos2->SetMinimum(-9.5);
  mtgr_mean_delt_cord_trk_horiz_Xcl_bot_pos2->SetMaximum(4.);
  c1->Print(Form("mtgr_mean_delt_cord_trk_horiz_Xcl_bot_pos2_%d.eps", run));
  c1->Print(Form("mtgr_mean_delt_cord_trk_horiz_Xcl_bot_pos2_%d.pdf", run));
  c1->Print(Form("mtgr_mean_delt_cord_trk_horiz_Xcl_bot_pos2_%d.gif", run));

  TMultiGraph *mtgr_sigm_delt_cord_trk_horiz_Xcl_bot_pos2 = new TMultiGraph();
  mtgr_sigm_delt_cord_trk_horiz_Xcl_bot_pos2->Add(gr_sigm_delt_cord_trk_horiz_Xcl_bot_pos_ECorr2);
  mtgr_sigm_delt_cord_trk_horiz_Xcl_bot_pos2->Add(gr_sigm_delt_cord_trk_horiz_Xcl_bot_pos_EUncorr2);
  mtgr_sigm_delt_cord_trk_horiz_Xcl_bot_pos2->Draw("AP");
  mtgr_sigm_delt_cord_trk_horiz_Xcl_bot_pos2->SetTitle("; X_{cl} mm; #sigma(X_{cl} - x_{tr}) mm");
  mtgr_sigm_delt_cord_trk_horiz_Xcl_bot_pos2->SetMinimum(0.);
  mtgr_sigm_delt_cord_trk_horiz_Xcl_bot_pos2->SetMaximum(20.);
  c1->Print(Form("mtgr_sigm_delt_cord_trk_horiz_Xcl_bot_pos2_%d.eps", run));
  c1->Print(Form("mtgr_sigm_delt_cord_trk_horiz_Xcl_bot_pos2_%d.pdf", run));
  c1->Print(Form("mtgr_sigm_delt_cord_trk_horiz_Xcl_bot_pos2_%d.gif", run));
  
  TMultiGraph *mtgr_mean_delt_cord_trk_horiz_Xcl_bot_neg2 = new TMultiGraph();
  mtgr_mean_delt_cord_trk_horiz_Xcl_bot_neg2->Add(gr_mean_delt_cord_trk_horiz_Xcl_bot_neg_ECorr2);
  mtgr_mean_delt_cord_trk_horiz_Xcl_bot_neg2->Add(gr_mean_delt_cord_trk_horiz_Xcl_bot_neg_EUncorr2);
  mtgr_mean_delt_cord_trk_horiz_Xcl_bot_neg2->Draw("AP");
  mtgr_mean_delt_cord_trk_horiz_Xcl_bot_neg2->SetTitle("; X_{cl} mm; #mu(X_{cl} - x_{tr}) mm");
  mtgr_mean_delt_cord_trk_horiz_Xcl_bot_neg2->SetMinimum(-10.5);
  mtgr_mean_delt_cord_trk_horiz_Xcl_bot_neg2->SetMaximum(4.);
  c1->Print(Form("mtgr_mean_delt_cord_trk_horiz_Xcl_bot_neg2_%d.eps", run));
  c1->Print(Form("mtgr_mean_delt_cord_trk_horiz_Xcl_bot_neg2_%d.pdf", run));
  c1->Print(Form("mtgr_mean_delt_cord_trk_horiz_Xcl_bot_neg2_%d.gif", run));

  TMultiGraph *mtgr_sigm_delt_cord_trk_horiz_Xcl_bot_neg2 = new TMultiGraph();
  mtgr_sigm_delt_cord_trk_horiz_Xcl_bot_neg2->Add(gr_sigm_delt_cord_trk_horiz_Xcl_bot_neg_ECorr2);
  mtgr_sigm_delt_cord_trk_horiz_Xcl_bot_neg2->Add(gr_sigm_delt_cord_trk_horiz_Xcl_bot_neg_EUncorr2);
  mtgr_sigm_delt_cord_trk_horiz_Xcl_bot_neg2->Draw("AP");
  mtgr_sigm_delt_cord_trk_horiz_Xcl_bot_neg2->SetTitle("; X_{cl} mm; #sigma(X_{cl} - x_{tr}) mm");
  mtgr_sigm_delt_cord_trk_horiz_Xcl_bot_neg2->SetMinimum(0.);
  mtgr_sigm_delt_cord_trk_horiz_Xcl_bot_neg2->SetMaximum(20.);
  c1->Print(Form("mtgr_sigm_delt_cord_trk_horiz_Xcl_bot_neg2_%d.eps", run));
  c1->Print(Form("mtgr_sigm_delt_cord_trk_horiz_Xcl_bot_neg2_%d.pdf", run));
  c1->Print(Form("mtgr_sigm_delt_cord_trk_horiz_Xcl_bot_neg2_%d.gif", run));

  //================== Tops ============================
  
  TMultiGraph *mtgr_mean_delt_cord_trk_horiz_Xcl_top_pos2 = new TMultiGraph();
  mtgr_mean_delt_cord_trk_horiz_Xcl_top_pos2->Add(gr_mean_delt_cord_trk_horiz_Xcl_top_pos_ECorr2);
  mtgr_mean_delt_cord_trk_horiz_Xcl_top_pos2->Add(gr_mean_delt_cord_trk_horiz_Xcl_top_pos_EUncorr2);
  mtgr_mean_delt_cord_trk_horiz_Xcl_top_pos2->Draw("AP");
  mtgr_mean_delt_cord_trk_horiz_Xcl_top_pos2->SetTitle("; X_{cl} mm; #mu(X_{cl} - x_{tr}) mm");
  mtgr_mean_delt_cord_trk_horiz_Xcl_top_pos2->SetMinimum(-2.);
  mtgr_mean_delt_cord_trk_horiz_Xcl_top_pos2->SetMaximum(9.);
  c1->Print(Form("mtgr_mean_delt_cord_trk_horiz_Xcl_top_pos2_%d.eps", run));
  c1->Print(Form("mtgr_mean_delt_cord_trk_horiz_Xcl_top_pos2_%d.pdf", run));
  c1->Print(Form("mtgr_mean_delt_cord_trk_horiz_Xcl_top_pos2_%d.gif", run));

  TMultiGraph *mtgr_sigm_delt_cord_trk_horiz_Xcl_top_pos2 = new TMultiGraph();
  mtgr_sigm_delt_cord_trk_horiz_Xcl_top_pos2->Add(gr_sigm_delt_cord_trk_horiz_Xcl_top_pos_ECorr2);
  mtgr_sigm_delt_cord_trk_horiz_Xcl_top_pos2->Add(gr_sigm_delt_cord_trk_horiz_Xcl_top_pos_EUncorr2);
  mtgr_sigm_delt_cord_trk_horiz_Xcl_top_pos2->Draw("AP");
  mtgr_sigm_delt_cord_trk_horiz_Xcl_top_pos2->SetTitle("; X_{cl} mm; #sigma(X_{cl} - x_{tr}) mm");
  mtgr_sigm_delt_cord_trk_horiz_Xcl_top_pos2->SetMinimum(0.);
  mtgr_sigm_delt_cord_trk_horiz_Xcl_top_pos2->SetMaximum(20.);
  c1->Print(Form("mtgr_sigm_delt_cord_trk_horiz_Xcl_top_pos2_%d.eps", run));
  c1->Print(Form("mtgr_sigm_delt_cord_trk_horiz_Xcl_top_pos2_%d.pdf", run));
  c1->Print(Form("mtgr_sigm_delt_cord_trk_horiz_Xcl_top_pos2_%d.gif", run));
  
  TMultiGraph *mtgr_mean_delt_cord_trk_horiz_Xcl_top_neg2 = new TMultiGraph();
  mtgr_mean_delt_cord_trk_horiz_Xcl_top_neg2->Add(gr_mean_delt_cord_trk_horiz_Xcl_top_neg_ECorr2);
  mtgr_mean_delt_cord_trk_horiz_Xcl_top_neg2->Add(gr_mean_delt_cord_trk_horiz_Xcl_top_neg_EUncorr2);
  mtgr_mean_delt_cord_trk_horiz_Xcl_top_neg2->Draw("AP");
  mtgr_mean_delt_cord_trk_horiz_Xcl_top_neg2->SetTitle("; X_{cl} mm; #mu(X_{cl} - x_{tr}) mm");
  mtgr_mean_delt_cord_trk_horiz_Xcl_top_neg2->SetMinimum(-2.);
  mtgr_mean_delt_cord_trk_horiz_Xcl_top_neg2->SetMaximum(9.);
  c1->Print(Form("mtgr_mean_delt_cord_trk_horiz_Xcl_top_neg2_%d.eps", run));
  c1->Print(Form("mtgr_mean_delt_cord_trk_horiz_Xcl_top_neg2_%d.pdf", run));
  c1->Print(Form("mtgr_mean_delt_cord_trk_horiz_Xcl_top_neg2_%d.gif", run));

  TMultiGraph *mtgr_sigm_delt_cord_trk_horiz_Xcl_top_neg2 = new TMultiGraph();
  mtgr_sigm_delt_cord_trk_horiz_Xcl_top_neg2->Add(gr_sigm_delt_cord_trk_horiz_Xcl_top_neg_ECorr2);
  mtgr_sigm_delt_cord_trk_horiz_Xcl_top_neg2->Add(gr_sigm_delt_cord_trk_horiz_Xcl_top_neg_EUncorr2);
  mtgr_sigm_delt_cord_trk_horiz_Xcl_top_neg2->Draw("AP");
  mtgr_sigm_delt_cord_trk_horiz_Xcl_top_neg2->SetTitle("; X_{cl} mm; #sigma(X_{cl} - x_{tr}) mm");
  mtgr_sigm_delt_cord_trk_horiz_Xcl_top_neg2->SetMinimum(0.);
  mtgr_sigm_delt_cord_trk_horiz_Xcl_top_neg2->SetMaximum(20.);
  c1->Print(Form("mtgr_sigm_delt_cord_trk_horiz_Xcl_top_neg2_%d.eps", run));
  c1->Print(Form("mtgr_sigm_delt_cord_trk_horiz_Xcl_top_neg2_%d.pdf", run));
  c1->Print(Form("mtgr_sigm_delt_cord_trk_horiz_Xcl_top_neg2_%d.gif", run));

}

