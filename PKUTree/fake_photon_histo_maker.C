



void fake_photon_histo_maker() 
{
	TFile* f1 = new TFile("./outtree/outSMU.root","r");	
	TTree* t1 =(TTree*)f1->Get("demo");
	
	Long64_t nentries = t1->GetEntries();
	std::cout<<"nentries = "<<nentries<<std::endl;		

	t1->SetBranchStatus("nump",1);
	t1->SetBranchStatus("numm",1);
	t1->SetBranchStatus("lep",1);	

    Double_t nump ;
    Double_t numm ;
    Double_t ptlep1 ;

	t1->SetBranchAddress("nump",&nump);
	t1->SetBranchAddress("numm",&numm);
	t1->SetBranchAddress("ptlep1", &ptlep1);

	TFile* f2 = new TFile("temp_fake.root","recreate");
	TTree* t2 = new TTree("demo","demo");
	t2->Branch("nump1",&nump,"nump1/D");
	t2->Branch("numm1",&numm,"numm1/D");
	t2->Branch("ptlep1", &ptlep1, "ptlep1/D");

	for(Int_t i=0; i < nentries; i++)
	{
		t1->GetEntry(i);
		t2->Fill();
	}




	t2->Write();
}
