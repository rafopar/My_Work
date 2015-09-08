{
   gStyle->SetTitleH(0.08);

   TDatime da(2003,02,28,12,00,00);
   gStyle->SetTimeOffset(da.Convert());

   ct = new TCanvas("ct","Time on axis",0,0,600,600);
   ct->Divide(1,3);

   ht1 = new TH1F("ht1","ht1",30000,0.,200000.);
   ht2 = new TH1F("ht2","ht2",30000,0.,200000.);
   ht3 = new TH1F("ht3","ht3",30000,0.,200000.);
   for (Int_t i=1;i<30000;i++) {
      Float_t noise = gRandom->Gaus(0,120);
      ht1->SetBinContent(i,noise);
      ht2->SetBinContent(i,noise*noise);
      ht3->SetBinContent(i,noise*noise*noise);
   }

   ct->cd(1);
   ht1->GetXaxis()->SetLabelSize(0.06);
   ht1->GetXaxis()->SetTimeDisplay(1);
   ht1->GetXaxis()->SetTimeFormat("%d/%m/%y%F2000-02-28 13:00:01");
   ht1->Draw();

   ct->cd(2);
   ht2->GetXaxis()->SetLabelSize(0.06);
   ht2->GetXaxis()->SetTimeDisplay(1);
   ht2->GetXaxis()->SetTimeFormat("%d/%m/%y");
   ht2->Draw();

   ct->cd(3);
   ht3->GetXaxis()->SetLabelSize(0.06);
   TDatime dh(2001,9,23,15,00,00);
   ht3->GetXaxis()->SetTimeDisplay(1);
   ht3->GetXaxis()->SetTimeOffset(dh.Convert());
   ht3->Draw();
}

