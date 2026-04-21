//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Tue Apr 21 21:38:02 2026 by ROOT version 6.36.10
// from TTree mydatatree3/tree containing our data
// found on file: ../execute/mydata4.root
//////////////////////////////////////////////////////////

#ifndef MyDataTree_h
#define MyDataTree_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

class MyDataTree {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.
   static constexpr Int_t kMaxvalue = 1;
   static constexpr Int_t kMaxerror = 1;

   // Declaration of leaf types
 //Datum           *datum;
   Double_t        value_;
   Double_t        error_;

   // List of branches
   TBranch        *b_datum_value_;   //!
   TBranch        *b_datum_error_;   //!

   MyDataTree(TTree *tree=0);
   virtual ~MyDataTree();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual bool     Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef MyDataTree_cxx
MyDataTree::MyDataTree(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("../execute/mydata4.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("../execute/mydata4.root");
      }
      f->GetObject("mydatatree3",tree);

   }
   Init(tree);
}

MyDataTree::~MyDataTree()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t MyDataTree::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t MyDataTree::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void MyDataTree::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("value_", &value_, &b_datum_value_);
   fChain->SetBranchAddress("error_", &error_, &b_datum_error_);
   Notify();
}

bool MyDataTree::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return true;
}

void MyDataTree::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t MyDataTree::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef MyDataTree_cxx
