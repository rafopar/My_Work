#include <TF1.h>
#include <TH1D.h>
#include <TH2D.h>
#include <TLine.h>
#include <TFile.h>
#include <TCanvas.h>

void Drawing()
{
  TCanvas *c1 = new TCanvas("c1", "", 750, 750);

  TLine *line1 = new TLine();
  line1->SetLineColor(2);

  TF1 *f_lin1 = new TF1("f_lin1", "[0] + [1]*x", -1., 1.);
  
  TFile *file_in = new TFile("tridents_tridents.root", "Read");

  TH1D *h_Eemep1 = (TH1D*)file_in->Get("h_Eemep1");
  h_Eemep1->SetTitle("; E_{e^{-}} + E_{e^{+}} GeV");
  h_Eemep1->Draw();

  TH1D *h_Eemep2 = (TH1D*)file_in->Get("h_Eemep2");
  h_Eemep2->SetTitle("; E_{e^{-}} + E_{e^{+}} GeV");
  h_Eemep2->SetLineColor(2);
  h_Eemep2->Draw("Same");
  line1->DrawLine(0.85, 0., 0.85, h_Eemep1->GetMaximum());
  c1->Print("Eemep12.eps");
  c1->Print("Eemep12.pdf");
  c1->Print("Eemep12.gif");

  c1->SetLogz();
  line1->SetLineWidth(2);
  TH2D *h_Py_emep1 = (TH2D*)file_in->Get("h_Py_emep1");
  h_Py_emep1->SetTitle("; Py_{e^{-}} GeV; Py_{e^{+}} GeV");
  h_Py_emep1->Draw("colz");
  line1->DrawLine(-0.04, 0.003, -0.003, 0.003);
  line1->DrawLine(-0.003, 0.003, -0.003, 0.04);
  line1->DrawLine(0.003, -0.003, 0.04, -0.003);
  line1->DrawLine(0.003, -0.003, 0.003, -0.03);
  c1->Print("Py_ep_em1.eps");
  c1->Print("Py_ep_em1.pdf");
  c1->Print("Py_ep_em1.gif");

  const int n_rows = 5;
  const double y_min = 20.165;
  const double bl_width = 13.7;
  const double calo_dist = 1393.;
  double y_bl_lims_[n_rows + 1];
  for( int i = 0; i < n_rows + 1; i++ )
    {
      y_bl_lims_[i] = y_min + double(i)*bl_width;
    }

  TH1D *h_th_vert2 = (TH1D*)file_in->Get("h_th_vert2");
  h_th_vert2->SetTitle("; #theta_{vert} rad");
  h_th_vert2->Draw();
  for( int i = 0; i < n_rows + 1; i++ )
    {
      double th = atan(y_bl_lims_[i]/calo_dist);
      line1->DrawLine(th, 0., th, h_th_vert2->GetBinContent(h_th_vert2->FindBin(th)) );
      line1->DrawLine(-th, 0., -th, h_th_vert2->GetBinContent(h_th_vert2->FindBin(-th)) );

      if( i < n_rows )
	{
	  double th2 = atan(y_bl_lims_[i+1]/calo_dist);
	  cout<<"N of events in "<<i+1<<"-th bin is "<<h_th_vert2->Integral( h_th_vert2->FindBin(th), h_th_vert2->FindBin(th2) )<<endl;
	}
    }
  c1->Print("Ocupanices_On_Ecal2.eps");
  c1->Print("Ocupanices_On_Ecal2.pdf");
  c1->Print("Ocupanices_On_Ecal2.gif");

  TH1D *h_th_vert3 = (TH1D*)file_in->Get("h_th_vert3");
  h_th_vert3->SetTitle("; #theta_{vert} rad");
  h_th_vert3->Draw();
  for( int i = 0; i < n_rows + 1; i++ )
    {
      double th = atan(y_bl_lims_[i]/calo_dist);
      line1->DrawLine(th, 0., th, h_th_vert3->GetBinContent(h_th_vert3->FindBin(th)) );
      line1->DrawLine(-th, 0., -th, h_th_vert3->GetBinContent(h_th_vert3->FindBin(-th)) );

      if( i < n_rows )
	{
	  double th2 = atan(y_bl_lims_[i+1]/calo_dist);
	  cout<<"N of events in "<<i+1<<"-th bin is "<<h_th_vert3->Integral( h_th_vert3->FindBin(th), h_th_vert3->FindBin(th2) )<<endl;
	}
    }
  c1->Print("Ocupanices_On_Ecal3.eps");
  c1->Print("Ocupanices_On_Ecal3.pdf");
  c1->Print("Ocupanices_On_Ecal3.gif");

}
