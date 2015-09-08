#include <TF1.h>
#include <TH1D.h>
#include <TH2D.h>
#include <TLine.h>
#include <TFile.h>
#include <TCanvas.h>

void Drawing()
{
  TCanvas *c1 = new TCanvas("c1", "", 750, 750);

  const int run = 5772;
  
  TFile *file_in = new TFile(Form("Analyze_tridents_%d.root", run), "Read");
  TFile *file_in_MC_BH = new TFile("Analyze_tridents_BH.root", "Read");
  
  TFile *file_in_MC_tritrig = new TFile("Analyze_tridents_tritrig.root", "Read");
  TFile *file_in_MC_tritrig_beamtri = new TFile("Analyze_tridents_tritrig_beamtri.root", "Read");

  TF1 *f_GPol3 = new TF1("f_GPol3", "[0]*TMath::Gaus(x, [1], [2]) + [3] + x*([4] + x*([5] + x*[6]))", 0., 2.5);
  
  TF1 *f_GExp = new TF1("f_GExp1", "[0]*TMath::Gaus(x, [1], [2]) + [3]*TMath::Exp([4]*x)", 0., 2.5);
  TF1 *f_Gaus = new TF1("f_Gaus", "[0]*TMath::Gaus(x, [1], [2])", 0., 2.5);
  f_Gaus->SetNpx(2500);
  TF1 *f_Pol3 = new TF1("f_Pol3", "[0] + x*([1] + x*([2] + x*[3]))", 0., 2.5);

  TH2D *h_Etot_Coplan_2 = (TH2D*)file_in->Get("h_Etot_Coplan_2");
  h_Etot_Coplan_2->GetYaxis()->SetTitleOffset(1.4);
  h_Etot_Coplan_2->SetTitle("; E_{bot} + E_{top} GeV; coplanarity deg");
  h_Etot_Coplan_2->Draw("colz");
  c1->Print(Form("Coplan_Etot2_%d.eps", run));
  c1->Print(Form("Coplan_Etot2_%d.pdf", run));
  c1->Print(Form("Coplan_Etot2_%d.gif", run));

  TH2D *h_Etot_Coplan_3 = (TH2D*)file_in->Get("h_Etot_Coplan_3");
  h_Etot_Coplan_3->GetYaxis()->SetTitleOffset(1.4);
  h_Etot_Coplan_3->SetTitle("; E_{bot} + E_{top} GeV; coplanarity deg");
  h_Etot_Coplan_3->Draw("colz");
  c1->Print(Form("Coplan_Etot3_%d.eps", run));
  c1->Print(Form("Coplan_Etot3_%d.pdf", run));
  c1->Print(Form("Coplan_Etot3_%d.gif", run));

  TH2D *h_Etot_Coplan_4 = (TH2D*)file_in->Get("h_Etot_Coplan_4");
  h_Etot_Coplan_4->GetYaxis()->SetTitleOffset(1.4);
  h_Etot_Coplan_4->SetTitle("; E_{bot} + E_{top} GeV; coplanarity deg");
  h_Etot_Coplan_4->Draw("colz");
  c1->Print(Form("Coplan_Etot4_%d.eps", run));
  c1->Print(Form("Coplan_Etot4_%d.pdf", run));
  c1->Print(Form("Coplan_Etot4_%d.gif", run));
  
  TH2D *h_Etot_Coplan_5 = (TH2D*)file_in->Get("h_Etot_Coplan_5");
  h_Etot_Coplan_5->GetYaxis()->SetTitleOffset(1.4);
  h_Etot_Coplan_5->SetTitle("; E_{bot} + E_{top} GeV; coplanarity deg");
  h_Etot_Coplan_5->Draw("colz");
  c1->Print(Form("Coplan_Etot5_%d.eps", run));
  c1->Print(Form("Coplan_Etot5_%d.pdf", run));
  c1->Print(Form("Coplan_Etot5_%d.gif", run));

  double fit_left_lim = 0.55;
  double fit_right_lim = 0.92;
  //f_GExp->SetParameters(376.89 , 0.799873, 0.0573349, 10, -1);
  f_GPol3->SetParameters(376.89 , 0.799873, 0.0573349, 0, 0, 0., 0);
  f_GPol3->SetParLimits(0, 50, 400);
  f_GPol3->SetParLimits(1, 0.7, 0.88);
  f_GPol3->SetParLimits(2, 0.01, 0.7);
  TH1D *h_PRoj_Etot_5 = (TH1D*)h_Etot_Coplan_5->ProjectionX("h_PRoj_Etot_5", 1,  h_Etot_Coplan_5->GetNbinsY());
  //h_PRoj_Etot_5->Fit(f_GExp, "MeV", "", 0.65, 1.);
  h_PRoj_Etot_5->Fit(f_GPol3, "MeV", "", fit_left_lim, fit_right_lim);

  double pars[7];
  f_GPol3->GetParameters(pars);
  f_Gaus->SetRange( fit_left_lim, fit_right_lim);
  f_Gaus->SetLineColor(4);
  f_Gaus->SetParameters(pars);
  f_Pol3->SetParameters(&pars[3]);
  f_Pol3->SetRange( fit_left_lim, fit_right_lim);
  f_Pol3->SetLineColor(3);
  f_Gaus->Draw("Same");
  f_Pol3->Draw("Same");
  c1->Print(Form("E_tot_Fit_5_%d.eps", run));
  c1->Print(Form("E_tot_Fit_5_%d.pdf", run));
  c1->Print(Form("E_tot_Fit_5_%d.gif", run));
  
  TH2D *h_Etot_Coplan_5_MC = (TH2D*)file_in_MC_BH->Get("h_Etot_Coplan_5");
  h_Etot_Coplan_5_MC->GetYaxis()->SetTitleOffset(1.4);
  h_Etot_Coplan_5_MC->SetTitle("; E_{bot} + E_{top} GeV; coplanarity deg");
  h_Etot_Coplan_5_MC->Draw("colz");
  c1->Print("Coplan_Etot5_MC.eps");
  c1->Print("Coplan_Etot5_MC.pdf");
  c1->Print("Coplan_Etot5_MC.gif");

  TH1D *h_PRoj_Etot_5_MC = (TH1D*)h_Etot_Coplan_5_MC->ProjectionX("h_PRoj_Etot_5_MC", 1,  h_Etot_Coplan_5_MC->GetNbinsY());

  h_PRoj_Etot_5_MC->Scale(h_PRoj_Etot_5->GetMaximum()/h_PRoj_Etot_5_MC->GetMaximum());
  h_PRoj_Etot_5->Draw();
  h_PRoj_Etot_5_MC->SetLineColor(2);
  h_PRoj_Etot_5_MC->Draw("Same");
  c1->Print(Form("Data_MC_BH_compare_%d.eps", run));
  c1->Print(Form("Data_MC_BH_compare_%d.pdf", run));
  c1->Print(Form("Data_MC_BH_compare_%d.gif", run));

  TH1D *h_Trid_Subtracted = (TH1D*)h_PRoj_Etot_5->Clone("h_Trid_Subtracted");
  h_Trid_Subtracted->Add(h_PRoj_Etot_5_MC, -1);
  h_Trid_Subtracted->Draw();
  c1->Print(Form("Subtracted_Tridents_%d.eps", run));
  c1->Print(Form("Subtracted_Tridents_%d.pdf", run));
  c1->Print(Form("Subtracted_Tridents_%d.gif", run));

  TH2D *h_Etot_Coplan_5_MC_trid = (TH2D*)file_in_MC_tritrig->Get("h_Etot_Coplan_5");
  h_Etot_Coplan_5_MC_trid->GetYaxis()->SetTitleOffset(1.4);
  h_Etot_Coplan_5_MC_trid->SetTitle("; E_{bot} + E_{top} GeV; coplanarity deg");
  h_Etot_Coplan_5_MC_trid->Draw("colz");
  c1->Print("Coplan_Etot5_MC_Trid.eps");
  c1->Print("Coplan_Etot5_MC_Trid.pdf");
  c1->Print("Coplan_Etot5_MC_Trid.gif");

  TH1D *h_PRoj_Etot_5_MC_trid = (TH1D*)h_Etot_Coplan_5_MC_trid->ProjectionX("h_PRoj_Etot_5_MC_trid", 1,  h_Etot_Coplan_5_MC_trid->GetNbinsY());
  h_PRoj_Etot_5_MC->Scale(0.9*h_PRoj_Etot_5_MC_trid->GetMaximum()/h_PRoj_Etot_5_MC->GetMaximum());
  h_PRoj_Etot_5_MC_trid->Draw();
  h_PRoj_Etot_5_MC->Draw("Same");
  c1->Print("MC_Trid_BH_Compare.eps");
  c1->Print("MC_Trid_BH_Compare.pdf");
  c1->Print("MC_Trid_BH_Compare.gif");

  h_PRoj_Etot_5_MC_trid->Scale(h_PRoj_Etot_5->GetMaximum()/h_PRoj_Etot_5_MC_trid->GetMaximum());
  h_PRoj_Etot_5_MC_trid->SetLineColor(2);
  h_PRoj_Etot_5->Draw();
  h_PRoj_Etot_5_MC_trid->Draw("Same");
  c1->Print(Form("Data_trid_Compare_%d.eps", run));
  c1->Print(Form("Data_trid_Compare_%d.pdf", run));
  c1->Print(Form("Data_trid_Compare_%d.gif", run));

  TH2D *h_Etot_Coplan_5_MC_tritrig_beamtri = (TH2D*)file_in_MC_tritrig_beamtri->Get("h_Etot_Coplan_5");
  h_Etot_Coplan_5_MC_tritrig_beamtri->GetYaxis()->SetTitleOffset(1.4);
  h_Etot_Coplan_5_MC_tritrig_beamtri->SetTitle("; E_{bot} + E_{top} GeV; coplanarity deg");
  h_Etot_Coplan_5_MC_tritrig_beamtri->Draw("colz");
  c1->Print("Coplan_Etot5_MC_Tritrig_Beamtri.eps");
  c1->Print("Coplan_Etot5_MC_Tritrig_Beamtri.pdf");
  c1->Print("Coplan_Etot5_MC_Tritrig_Beamtri.gif");

  TH1D *h_PRoj_Etot_5_MC_tritrig_beamtri = (TH1D*)h_Etot_Coplan_5_MC_tritrig_beamtri->ProjectionX("h_PRoj_Etot_5_MC_tritrig_beamtri", 1,  h_Etot_Coplan_5_MC_tritrig_beamtri->GetNbinsY());
  h_PRoj_Etot_5_MC->Scale(0.9*h_PRoj_Etot_5_MC_tritrig_beamtri->GetMaximum()/h_PRoj_Etot_5_MC->GetMaximum());
  h_PRoj_Etot_5_MC_tritrig_beamtri->Draw();
  h_PRoj_Etot_5_MC->Draw("Same");
  c1->Print("MC_Tritrig_Beamtri_BH_Compare.eps");
  c1->Print("MC_Tritrig_Beamtri_BH_Compare.pdf");
  c1->Print("MC_Tritrig_Beamtri_BH_Compare.gif");

  //h_PRoj_Etot_5_MC_tritrig_beamtri->Scale(h_PRoj_Etot_5->GetBinContent(h_PRoj_Etot_5->FindBin(0.9))
  //					  /h_PRoj_Etot_5_MC_tritrig_beamtri->GetBinContent(h_PRoj_Etot_5_MC_tritrig_beamtri->FindBin(0.9)));
  h_PRoj_Etot_5_MC_tritrig_beamtri->Scale(h_PRoj_Etot_5->GetMaximum()/h_PRoj_Etot_5_MC_tritrig_beamtri->GetMaximum());
  h_PRoj_Etot_5_MC_tritrig_beamtri->SetLineColor(2);
  h_PRoj_Etot_5->SetMaximum(h_PRoj_Etot_5_MC_tritrig_beamtri->GetMaximum());
  h_PRoj_Etot_5->Draw();
  h_PRoj_Etot_5_MC_tritrig_beamtri->Draw("Same");
  c1->Print(Form("Data_tritrig_beamtri_Compare_%d.eps", run));
  c1->Print(Form("Data_tritrig_beamtri_Compare_%d.pdf", run));
  c1->Print(Form("Data_tritrig_beamtri_Compare_%d.gif", run));
  
  TH2D *h_Etot_Coplan_7 = (TH2D*)file_in->Get("h_Etot_Coplan_7");
  h_Etot_Coplan_7->GetYaxis()->SetTitleOffset(1.4);
  h_Etot_Coplan_7->SetTitle("; E_{bot} + E_{top} GeV; coplanarity deg");
  h_Etot_Coplan_7->Draw("colz");
  c1->Print(Form("Coplan_Etot7_%d.eps", run));
  c1->Print(Form("Coplan_Etot7_%d.pdf", run));
  c1->Print(Form("Coplan_Etot7_%d.gif", run));

  fit_left_lim = 0.5;
  fit_right_lim = 0.95;
  f_GExp->SetParameters(376.89 , 0.799873, 0.0573349, 10, -1);
  f_GPol3->SetParameters(376.89 , 0.799873, 0.0573349, 0, 0, 0., 0);
  f_GPol3->SetParLimits(0, 50, 400);
  f_GPol3->SetParLimits(1, 0.7, 0.88);
  f_GPol3->SetParLimits(2, 0.01, 0.7);
  TH1D *h_PRoj_Etot_7 = (TH1D*)h_Etot_Coplan_7->ProjectionX("h_PRoj_Etot_7", (h_Etot_Coplan_7->GetYaxis())->FindBin(170),  (h_Etot_Coplan_7->GetYaxis())->FindBin(190));
  h_PRoj_Etot_7->Draw();
  //h_PRoj_Etot_7->Fit(f_GExp, "MeV", "", 0.65, 1.);
  //  h_PRoj_Etot_7->Fit(f_GExp, "MeV", "", fit_left_lim, fit_right_lim);
  f_GPol3->GetParameters(pars);
  f_Gaus->SetRange( fit_left_lim, fit_right_lim);
  f_Gaus->SetLineColor(4);
  f_Gaus->SetParameters(pars);
  f_Pol3->SetParameters(&pars[3]);
  f_Pol3->SetRange( fit_left_lim, fit_right_lim);
  f_Pol3->SetLineColor(3);
  //  f_Gaus->Draw("Same");
  //  f_Pol3->Draw("Same");

  c1->Print(Form("E_tot_Fit_7_%d.eps", run));
  c1->Print(Form("E_tot_Fit_7_%d.pdf", run));
  c1->Print(Form("E_tot_Fit_7_%d.gif", run));
  
  TH2D *h_Ecl_bot_top2 = (TH2D*)file_in->Get("h_Ecl_bot_top2");
  h_Ecl_bot_top2->SetTitle("; E_{bot} GeV; E_{top} GeV");
  h_Ecl_bot_top2->Draw("colz");
  c1->Print(Form("E_cl_bot_top2_%d.eps", run));
  c1->Print(Form("E_cl_bot_top2_%d.pdf", run));
  c1->Print(Form("E_cl_bot_top2_%d.gif", run));

  TH2D *h_Ecl_bot_top3 = (TH2D*)file_in->Get("h_Ecl_bot_top3");
  h_Ecl_bot_top3->SetTitle("; E_{bot} GeV; E_{top} GeV");
  h_Ecl_bot_top3->Draw("colz");
  c1->Print(Form("E_cl_bot_top3_%d.eps", run));
  c1->Print(Form("E_cl_bot_top3_%d.pdf", run));
  c1->Print(Form("E_cl_bot_top3_%d.gif", run));
  
  TH2D *h_Ecl_bot_top4 = (TH2D*)file_in->Get("h_Ecl_bot_top4");
  h_Ecl_bot_top4->SetTitle("; E_{bot} GeV; E_{top} GeV");
  h_Ecl_bot_top4->Draw("colz");
  c1->Print(Form("E_cl_bot_top4_%d.eps", run));
  c1->Print(Form("E_cl_bot_top4_%d.pdf", run));
  c1->Print(Form("E_cl_bot_top4_%d.gif", run));
  
  TH2D *h_Ecl_bot_top5 = (TH2D*)file_in->Get("h_Ecl_bot_top5");
  h_Ecl_bot_top5->SetTitle("; E_{bot} GeV; E_{top} GeV");
  h_Ecl_bot_top5->Draw("colz");
  c1->Print(Form("E_cl_bot_top5_%d.eps", run));
  c1->Print(Form("E_cl_bot_top5_%d.pdf", run));
  c1->Print(Form("E_cl_bot_top5_%d.gif", run));
  
  TH2D *h_delt_coord_trk_horiz_coord1 = (TH2D*)file_in->Get("h_delt_coord_trk_horiz_coord1");
  h_delt_coord_trk_horiz_coord1->SetTitle("; X_{cl} mm; X_{cl} - X_{tr} mm");
  h_delt_coord_trk_horiz_coord1->Draw("colz");
  c1->Print(Form("delt_coord_trk_horiz_coord1_%d.eps", run));
  c1->Print(Form("delt_coord_trk_horiz_coord1_%d.pdf", run));
  c1->Print(Form("delt_coord_trk_horiz_coord1_%d.gif", run));

  TH1D *h_Proj_delt_horiz1 = (TH1D*)h_delt_coord_trk_horiz_coord1->ProjectionY("h_Proj_delt_horiz1", h_delt_coord_trk_horiz_coord1->GetXaxis()->FindBin(-100),
									       h_delt_coord_trk_horiz_coord1->GetXaxis()->FindBin(-60));
  h_Proj_delt_horiz1->Draw();
  c1->Print(Form("Proj_delt_horiz1_%d.eps", run));
  c1->Print(Form("Proj_delt_horiz1_%d.pdf", run));
  c1->Print(Form("Proj_delt_horiz1_%d.gif", run));

  TH2D *h_delt_cord_trk_vert_coord1 = (TH2D*)file_in->Get("h_delt_cord_trk_vert_coord1");
  h_delt_cord_trk_vert_coord1->SetTitle("; Y_{cl} mm; Y_{cl} - Y_{tr} mm");
  h_delt_cord_trk_vert_coord1->Draw("colz");
  c1->Print(Form("delt_cord_trk_vert_coord1_%d.eps", run));
  c1->Print(Form("delt_cord_trk_vert_coord1_%d.pdf", run));
  c1->Print(Form("delt_cord_trk_vert_coord1_%d.gif", run));

   TH1D *h_Proj_delt_vert1 = (TH1D*)h_delt_cord_trk_vert_coord1->ProjectionY("h_Proj_delt_vert1", h_delt_cord_trk_vert_coord1->GetXaxis()->FindBin(-70),
									       h_delt_cord_trk_vert_coord1->GetXaxis()->FindBin(-50));
  h_Proj_delt_vert1->Draw();
  c1->Print(Form("Proj_delt_vert1_%d.eps", run));
  c1->Print(Form("Proj_delt_vert1_%d.pdf", run));
  c1->Print(Form("Proj_delt_vert1_%d.gif", run));

  TLine *line1 = new TLine();
  line1->SetLineColor(2);
  
  TH2D *h_cl_E_t1 = (TH2D*)file_in->Get("h_cl_E_t1");
  h_cl_E_t1->SetTitle("; E_{cl} GeV; t_{cl} ns");
  h_cl_E_t1->Draw("colz");
  line1->DrawLine(0., 35., 1.15, 35.);
  line1->DrawLine(0., 50., 1.15, 50.);
  c1->Print(Form("cl_E_t1_%d.eps", run));
  c1->Print(Form("cl_E_t1_%d.pdf", run));
  c1->Print(Form("cl_E_t1_%d.gif", run));
  
  TH2D *h_cl_E_t_MC_BH1 = (TH2D*)file_in_MC_BH->Get("h_cl_E_t1");
  h_cl_E_t_MC_BH1->SetTitle("; E_{cl} GeV; t_{cl} ns");
  h_cl_E_t_MC_BH1->Draw("colz");
  line1->DrawLine(0., 35., 1.15, 35.);
  line1->DrawLine(0., 50., 1.15, 50.);
  c1->Print("cl_E_t1_MC_BH.eps");
  c1->Print("cl_E_t1_MC_BH.pdf");
  c1->Print("cl_E_t1_MC_BH.gif");

  
  TH2D *h_cl_E_t_MC_tritrig_beamtri1 = (TH2D*)file_in_MC_tritrig_beamtri->Get("h_cl_E_t1");
  h_cl_E_t_MC_tritrig_beamtri1->SetTitle("; E_{cl} GeV; t_{cl} ns");
  h_cl_E_t_MC_tritrig_beamtri1->Draw("colz");
  line1->DrawLine(0., 35., 1.15, 35.);
  line1->DrawLine(0., 50., 1.15, 50.);
  c1->Print("cl_E_t1_MC_tritrig_beamtri.eps");
  c1->Print("cl_E_t1_MC_tritrig_beamtri.pdf");
  c1->Print("cl_E_t1_MC_tritrig_beamtri.gif");

}
