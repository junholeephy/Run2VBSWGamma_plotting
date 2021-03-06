{
#include "TAxis.h"
#include "TH2.h"
#include "TStyle.h"
#include "TCanvas.h"
#include "TNtupleD.h"
#include <stdio.h>
#include <stdlib.h>
#include <vector.h>

        int nPUMax=50;
        std::vector<double> result(nPUMax,0.);
        double s = 0.;

	TFile * input1 = new TFile ("MyDataPileupHistogram.root");
        TH1* h = NULL;
        input1.GetObject("pileup",h);

        double npuWinter15_25ns[50] = {
                0.000829312873542,
                0.00124276120498,
                0.00339329181587,
                0.00408224735376,
                0.00383036590008,
                0.00659159288946,
                0.00816022734493,
                0.00943640833116,
                0.0137777376066,
                0.017059392038,
                0.0213193035468,
                0.0247343174676,
                0.0280848773878,
                0.0323308476564,
                0.0370394341409,
                0.0456917721191,
                0.0558762890594,
                0.0576956187107,
                0.0625325287017,
                0.0591603758776,
                0.0656650815128,
                0.0678329011676,
                0.0625142146389,
                0.0548068448797,
                0.0503893295063,
                0.040209818868,
                0.0374446988111,
                0.0299661572042,
                0.0272024759921,
                0.0219328403791,
                0.0179586571619,
                0.0142926728247,
                0.00839941654725,
                0.00522366397213,
                0.00224457976761,
                0.000779274977993,
                0.000197066585944,
                7.16031761328e-05,
                0.0,
                0.0,
                0.0,
                0.0,
                0.0,
                0.0,
                0.0,
                0.0,
                0.0,
                0.0,
                0.0,
                0.0 };


         for(unsigned int npu = 0; npu < nPUMax; ++npu) {
              const double npu_estimated = h->GetBinContent(h->GetXaxis()->FindBin(npu));
            if(npuWinter15_25ns[npu]!=0) { result[npu] = npu_estimated / npuWinter15_25ns[npu];} else {result[npu]=0;}
              s += npu_estimated;
         }

        for(unsigned int npu = 0; npu < nPUMax; ++npu) {
              result[npu] /= s;
        }


        fout = new TFile("puweight.root", "RECREATE");
        TH1D *h2   = new TH1D("h2","",50,0,49);
        for(unsigned int npu = 0; npu < nPUMax; ++npu) {
            h2->SetBinContent(npu+1, result[npu]);
        }


   fout->cd();
   h2->Write();
   fout->Write();
   fout->Close();
   delete fout;

 }

}
