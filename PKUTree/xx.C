#define xx_cxx
#include "xx.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

void xx::Loop()
{
//   In a ROOT session, you can do:
//      Root > .L xx.C
//      Root > xx t
//      Root > t.GetEntry(12); // Fill t data members with entry number 12
//      Root > t.Show();       // Show values of entry 12
//      Root > t.Show(16);     // Read and show values of entry 16
//      Root > t.Loop();       // Loop on all entries
//

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch

   if (fChain == 0) return;
   Long64_t nentries = fChain->GetEntriesFast();

  Long64_t npp = fChain->GetEntries("theWeight>0.");
  Long64_t nmm = fChain->GetEntries("theWeight<0.");
  std::cout<< "numberofnp:" << npp << "  numberofnm:" <<nmm << std::endl;


	TFile * input1 = new TFile ("puweight.root");
        TH1* h = NULL;
        input1->GetObject("h2",h);


   Long64_t nbytes = 0, nb = 0;
    for (Long64_t jentry=0; jentry<nentries; jentry++) {
       // for (Long64_t jentry=0; jentry<10000;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
       nb = fChain->GetEntry(jentry);   nbytes += nb;
            // std::cout<<nb<<std::endl;
      // if (Cut(ientry) < 0) continue;

 
     if(jentry%100000==0) cout<<" "<<HLT_Ele1<<" "<<HLT_Mu1<<" "<<fabs(theWeight)/theWeight<<" "<<m_dataset<<" "<<jentry<<" "<<nentries<<endl;
//WA2jets_160425.root
//	 if(m_dataset=="fake_signal.root"){ scalef=1.0; }  
//	 if(m_dataset=="outtest_signal_160511.root") {scalef=1000.*25.62/float(npp-nmm)*fabs(theWeight)/theWeight;}
//	 if(m_dataset=="outsignal_160503.root") {scalef=1000.*0.4705/float(npp-nmm)*fabs(theWeight)/theWeight;}
//     if(m_dataset=="outsignal_160427.root") {scalef=1000.*0.2164/float(npp-nmm)*fabs(theWeight)/theWeight;}
//	 if(m_dataset=="outWA2jets_160425.root") {scalef=1000.*386.8/float(npp-nmm)*fabs(theWeight)/theWeight;}
//	 if(m_dataset=="outmuonsignal_30k.root") {scalef=1000.*0.1312/float(npp-nmm)*fabs(theWeight)/theWeight;}
//	 if(m_dataset=="MiniAodv2_Signal_2k_PKU.root") {scalef=1000.*0.05957/float(npp-nmm)*fabs(theWeight)/theWeight;}
//     if(m_dataset=="outSMOCT.root"){ scalef=1.0; }
//     if(m_dataset=="outSingleMuon_Run2016B.root"){ scalef=1.0; }
//     if(m_dataset=="outSingleMuon_Run2016C.root"){ scalef=1.0; }
//	 if(m_dataset=="outSingleMuon_Run2016D.root"){ scalef=1.0; }
//     if(m_dataset=="outSingleMuon_Run2016E-PromptReco-v2.root"){ scalef=1.0; }
// 	 if(m_dataset=="outSingleMuon_preICHEP.root"){ scalef=1.0; }
	 if(m_dataset=="outSMU.root"){ scalef=1.0; }
	 if(m_dataset=="outVBS_WGamma_signal.root") {scalef=1000*0.776/float(npp-nmm)*fabs(theWeight)/theWeight;}
	 if(m_dataset=="outLNuAJJ_EWK.root") {scalef=1000*0.776/float(npp-nmm)*fabs(theWeight)/theWeight;}
//	 if(m_dataset=="outST_s-channel.root"){ scalef=1000.*11.36*0.322/float(npp-nmm)*fabs(theWeight)/theWeight; }
     if(m_dataset=="outST_s.root"){ scalef=1000.*11.36*0.322/float(npp-nmm)*fabs(theWeight)/theWeight; }
//	 if(m_dataset=="outST_t-channel_antitop.root"){ scalef=1000.*80.95*0.322/float(npp-nmm)*fabs(theWeight)/theWeight; }
     if(m_dataset=="outST_t_anti.root"){ scalef=1000.*80.95*0.322/float(npp-nmm)*fabs(theWeight)/theWeight; }
//	 if(m_dataset=="outST_t-channel_top.root"){ scalef=1000.*136.02*0.322/float(npp-nmm)*fabs(theWeight)/theWeight; }
     if(m_dataset=="outST_t-top.root"){ scalef=1000.*136.02*0.322/float(npp-nmm)*fabs(theWeight)/theWeight; }
	 if(m_dataset=="outST_tW_antitop.root"){ scalef=1000.*35.85/float(npp-nmm)*fabs(theWeight)/theWeight; }   //10     
	 if(m_dataset=="outST_tW_top.root"){ scalef=1000.*35.85/float(npp-nmm)*fabs(theWeight)/theWeight; }      //9
     if(m_dataset=="outTTG.root"){ scalef=1000.*3.697/float(npp-nmm)*fabs(theWeight)/theWeight; }      //12
     if(m_dataset=="outTTJets.root"){ scalef=1000.*831.76/float(npp-nmm)*fabs(theWeight)/theWeight; }  //3
 //    if(m_dataset=="outTTbar.root"){ scalef=1000.*831.76/float(npp-nmm)*fabs(theWeight)/theWeight; }  //
	 if(m_dataset=="outWG.root"){ scalef=1000.*489.0/float(npp-nmm)*fabs(theWeight)/theWeight; }       //4
     if(m_dataset=="outWJets.root"){ scalef=1000.*61526.7/float(npp-nmm)*fabs(theWeight)/theWeight; }  //1
     if(m_dataset=="outWW.root"){ scalef=1000.*118.7/float(npp-nmm)*fabs(theWeight)/theWeight; }       //5
     if(m_dataset=="outWZ.root"){ scalef=1000.*47.13/float(npp-nmm)*fabs(theWeight)/theWeight; }       //8
     if(m_dataset=="outZG.root"){ scalef=1000.*117.864/float(npp-nmm)*fabs(theWeight)/theWeight; }     //6
     if(m_dataset=="outZZ.root"){ scalef=1000.*16.523/float(npp-nmm)*fabs(theWeight)/theWeight; }      //11
     if(m_dataset=="outZJets.root"){ scalef=1000.*5765.4/float(npp-nmm)*fabs(theWeight)/theWeight; }   //2
//	 if(m_dataset=="outWJets_MLM.root") {scalef=1000.*61526.7/float(npp-nmm)*fabs(theWeight)/theWeight;  }


//     if(m_dataset !="outSMOCT.root" && m_dataset !="outSMPROMPT.root" && m_dataset !="outSingleMuon_Run2016B.root" && m_dataset !="outSingleMuon_Run2016C.root" && m_dataset !="outSingleMuon_Run2016D.root" && m_dataset !="outSMU.root"  )  {
	if(m_dataset !="outSingleMuon_Run2016D.root" ) {  
	 pileupWeight=h->GetBinContent(h->GetXaxis()->FindBin(npT));
       // cout<<pileupWeight<<endl;
         }
             
 
   ExTree->Fill();

   }

   input1->Close();
}

