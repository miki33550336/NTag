#include <math.h>

#include <skheadC.h>
#include <sktqC.h>
#include <apmringC.h>
#include <geotnkC.h>

#include <NTagEventInfo.hh>
#include <SKIOLib.hh>

NTagEventInfo::NTagEventInfo(bool isData)
: bData(isData){}

NTagEventInfo::~NTagEventInfo() {}

void NTagEventInfo::Clear()
{
    np = 0;
    N200M = 0;
	broken = 0;
	vx = 0;
	vy = 0;
	vz = 0;
	bt = 1000000;
	lasthit = 0;
	trgofst= 0;
	firsthit = 0;
	firstflz = 0;
	timnsk = 0;
    T200M = -9999.;
    mctrue_nn = 0;

    for(int i = 0; i < MAXNP; i++){
        N10[i] = 0;
        N10n[i] = 0;
		dtn[i] = 0;
		spread[i] = 0;
        Nc[i] = 0;
        Ncluster[i] = 0;
        Nback[i] = 0;
        N300[i] = 0;
        N1300[i] = 0;
        N200[i] = 0;
        N50[i] = 0;
        N12[i] = 0;
        N20[i] = 0;
        trms[i] = 0.;
        trmsold[i] = 0.;
        mintrms_3[i] = 0.;
        mintrms_4[i] = 0.;
        mintrms_5[i] = 0.;
        mintrms_6[i] = 0.;
        phirms[i] = 0.;
        thetam[i] = 0.;
        dt[i] = 0.;
        Neff[i] = 0;
        ratio[i] = 0.;
        NhighQ[i] = 0;
        Nc1[i] = 0;
		goodn[i] = 0;
		realneutron[i] = 0;
		summedWeight[i] = 0;
		bsenergy[i] = 0.;
		bsvertex0[i] = 0.;
		bsvertex1[i] = 0.;
		bsvertex2[i] = 0.;
		bsgood[i] = 0.;
		g2d2[i] = 0.;
		nvx[i] = 0.;
		nvy[i] = 0.;
		nvz[i] = 0.;
        nwall[i] = 0.;
		tvx[i] = 0.;
		tvy[i] = 0.;
		tvz[i] = 0.;
		for(int j = 0; j < 9; j++){
			Nlow[j][i] = 0;
		}
    }
}



void NTagEventInfo::SetBranchAddressOfTree(TTree *tree, bool forTruth)
{
	tree->SetBranchAddress("np", &np);
	tree->SetBranchAddress("nrun", &nrun);
	tree->SetBranchAddress("nsub", &nsub);
	tree->SetBranchAddress("nev", &nev);
	tree->SetBranchAddress("broken", &broken);
	tree->SetBranchAddress("trgtype", &trgtype);
	tree->SetBranchAddress("lasthit", &lasthit);
	tree->SetBranchAddress("trgofst", &trgofst);
	tree->SetBranchAddress("firsthit", &firsthit);
	tree->SetBranchAddress("firstflz", &firstflz);
	tree->SetBranchAddress("timnsk", &timnsk);
	tree->SetBranchAddress("bt", &bt);
	tree->SetBranchAddress("N200M", &N200M);
	tree->SetBranchAddress("T200M", &T200M);
	tree->SetBranchAddress("vx", &vx);
	tree->SetBranchAddress("vy", &vy);
	tree->SetBranchAddress("vz", &vz);
	tree->SetBranchAddress("nvx", &nvx);
	tree->SetBranchAddress("nvy", &nvy);
	tree->SetBranchAddress("nvz", &nvz);
	tree->SetBranchAddress("tvx", &tvx);
	tree->SetBranchAddress("tvy", &tvy);
	tree->SetBranchAddress("tvz", &tvz);
	tree->SetBranchAddress("N10", &N10);
	tree->SetBranchAddress("N10n", &N10n);
	tree->SetBranchAddress("Nc", &Nc);
	tree->SetBranchAddress("Ncluster", &Ncluster);
	tree->SetBranchAddress("Nback", &Nback);
	tree->SetBranchAddress("N300", &N300);
	tree->SetBranchAddress("N12", &N12);
	tree->SetBranchAddress("N20", &N20);
	tree->SetBranchAddress("trms", &trms);
	tree->SetBranchAddress("trmsold", &trmsold);
	tree->SetBranchAddress("mintrms_3", &mintrms_3);
	tree->SetBranchAddress("mintrms_4", &mintrms_4);
	tree->SetBranchAddress("mintrms_5", &mintrms_5);
	tree->SetBranchAddress("mintrms_6", &mintrms_6);
	tree->SetBranchAddress("phirms", &phirms);
	tree->SetBranchAddress("thetam", &thetam);
	tree->SetBranchAddress("dt", &dt);
	tree->SetBranchAddress("dtn", &dtn);
	tree->SetBranchAddress("spread", &spread);
	tree->SetBranchAddress("Neff", &Neff);
	tree->SetBranchAddress("ratio", &ratio);
	tree->SetBranchAddress("Nc1", &Nc1);
	tree->SetBranchAddress("NhighQ", &NhighQ);
	tree->SetBranchAddress("Nlow1", &Nlow[0]);
	tree->SetBranchAddress("Nlow2", &Nlow[1]);
	tree->SetBranchAddress("Nlow3", &Nlow[2]);
	tree->SetBranchAddress("Nlow4", &Nlow[3]);
	tree->SetBranchAddress("Nlow5", &Nlow[4]);
	tree->SetBranchAddress("Nlow6", &Nlow[5]);
	tree->SetBranchAddress("Nlow7", &Nlow[6]);
	tree->SetBranchAddress("Nlow8", &Nlow[7]);
	tree->SetBranchAddress("Nlow9", &Nlow[8]);
	tree->SetBranchAddress("bsenergy", &bsenergy);
	tree->SetBranchAddress("bsvertex0", &bsvertex0);
	tree->SetBranchAddress("bsvertex1", &bsvertex1);
	tree->SetBranchAddress("bsvertex2", &bsvertex2);
	tree->SetBranchAddress("bsgood", &bsgood);
	tree->SetBranchAddress("tbsenergy", &tbsenergy);
	tree->SetBranchAddress("tbsvx", &tbsvx);
	tree->SetBranchAddress("tbsvy", &tbsvy);
	tree->SetBranchAddress("tbsvz", &tbsvz);
	tree->SetBranchAddress("tbsvt", &tbsvt);
	tree->SetBranchAddress("tbsgood", &tbsgood);
	tree->SetBranchAddress("g2d2", &g2d2);
	tree->SetBranchAddress("summedWeight",&summedWeight);

	if(forTruth)
		tree->SetBranchAddress("realneutron",&realneutron);
}

void NTagEventInfo::CreateBranchesToTree (TTree *tree, bool forTruth)
{
    tree->Branch("np", &np, "np/I");
    tree->Branch("nrun", &nrun, "nrun/I");
    tree->Branch("nsub", &nsub, "nsub/I");
    tree->Branch("nev", &nev, "nev/I");
    tree->Branch("broken", &broken, "broken/I");
    tree->Branch("trgtype", &trgtype, "trgtype/I");
    tree->Branch("lasthit", &lasthit, "lasthit/F");
    tree->Branch("trgofst", &trgofst, "trgofst/F");
    tree->Branch("firsthit", &firsthit, "firsthit/F");
    tree->Branch("firstflz", &firstflz, "firstflz/F");
    tree->Branch("timnsk", &timnsk, "timnsk/F");
    tree->Branch("bt", &bt, "bt/F");
    tree->Branch("N200M", &N200M, "N200M/I");
    tree->Branch("T200M", &T200M, "T200M/F");
	tree->Branch("vx", &vx, "vx/F");
	tree->Branch("vy", &vy, "vy/F");
	tree->Branch("vz", &vz, "vz/F");
	tree->Branch("nvx",	nvx, "nvx[np]/F");
	tree->Branch("nvy",	nvy, "nvy[np]/F");
	tree->Branch("nvz",	nvz, "nvz[np]/F");
	tree->Branch("nwall", nwall, "nwall[np]/F");
	tree->Branch("tvx",	tvx, "tvx[np]/F");
	tree->Branch("tvy",	tvy, "tvy[np]/F");
	tree->Branch("tvz",	tvz, "tvz[np]/F");
    tree->Branch("N10", N10, "N10[np]/I");
    tree->Branch("wall", &towall, "wall/F");
    tree->Branch("N10n", N10n, "N10n[np]/I");
    tree->Branch("Nc", Nc, "Nc[np]/I");
    tree->Branch("Ncluster", Ncluster, "Ncluster[np]/I");
    tree->Branch("Nc8", Nc8, "Nc8[np]/I");
    tree->Branch("Ncluster8", Ncluster8, "Ncluster8[np]/I");
    tree->Branch("Nc7", Nc7, "Nc7[np]/I");
    tree->Branch("Ncluster7", Ncluster7, "Ncluster7[np]/I");
    tree->Branch("Nback", Nback, "Nback[np]/I");
    tree->Branch("N300", N300, "N300[np]/I");
    tree->Branch("N200", N200, "N200[np]/I");
    tree->Branch("N50", N50, "N50[np]/I");
    tree->Branch("N1300", N1300, "N1300[np]/I");
    tree->Branch("N12", N12, "N12[np]/I");
    tree->Branch("N20", N20, "N20[np]/I");
    tree->Branch("trms", trms, "trms[np]/F");
    tree->Branch("trmsold", trmsold, "trmsold[np]/F");
    tree->Branch("trms40", trms40, "trms40[np]/F");
    tree->Branch("mintrms_3", mintrms_3, "mintrms_3[np]/F");
    tree->Branch("mintrms_4", mintrms_4, "mintrms_4[np]/F");
    tree->Branch("mintrms_5", mintrms_5, "mintrms_5[np]/F");
    tree->Branch("mintrms_6", mintrms_6, "mintrms_6[np]/F");
    tree->Branch("phirms", phirms, "phirms[np]/F");
    tree->Branch("thetam", thetam, "thetam[np]/F");
    tree->Branch("dt", dt, "dt[np]/F");
    tree->Branch("dtn", dtn, "dtn[np]/F");
    tree->Branch("spread", spread, "spread[np]/F");
    tree->Branch("Neff", Neff, "Neff[np]/I");
    tree->Branch("ratio", ratio, "ratio[np]/F");
    tree->Branch("Nc1", Nc1, "Nc1[np]/I");
    tree->Branch("NhighQ", NhighQ, "NhighQ[np]/I");
    tree->Branch("Nlow1", Nlow[0], "Nlow1[np]/I");
    tree->Branch("Nlow2", Nlow[1], "Nlow2[np]/I");
    tree->Branch("Nlow3", Nlow[2], "Nlow3[np]/I");
    tree->Branch("Nlow4", Nlow[3], "Nlow4[np]/I");
    tree->Branch("Nlow5", Nlow[4], "Nlow5[np]/I");
    tree->Branch("Nlow6", Nlow[5], "Nlow6[np]/I");
    tree->Branch("Nlow7", Nlow[6], "Nlow7[np]/I");
    tree->Branch("Nlow8", Nlow[7], "Nlow8[np]/I");
    tree->Branch("Nlow9", Nlow[8], "Nlow9[np]/I");
	tree->Branch("bsenergy", bsenergy, "bsenergy[np]/F");
	tree->Branch("bsvertex0", bsvertex0, "bsvertex0[np]/F");
	tree->Branch("bsvertex1", bsvertex1, "bsvertex1[np]/F");
	tree->Branch("bsvertex2", bsvertex2, "bsvertex2[np]/F");
	tree->Branch("bsgood", bsgood, "bsgood[np]/F");
	tree->Branch("tbsenergy", tbsenergy, "tbsenergy[np]/F");
	tree->Branch("tbsenergy2", tbsenergy2, "tbsenergy2[np]/F");
	tree->Branch("tbsvx", tbsvx, "tbsvx[np]/F");
	tree->Branch("tbsvy", tbsvy, "tbsvy[np]/F");
	tree->Branch("tbsvz", tbsvz, "tbsvz[np]/F");
	tree->Branch("tbsvt", tbsvt, "tbsvt[np]/F");
	tree->Branch("tbswall",	tbswall, "tbswall[np]/F");
	tree->Branch("tbsgood",	tbsgood, "tbsgood[np]/F");
	tree->Branch("tbsdirks", tbsdirks, "tbsdirks[np]/F");
	tree->Branch("tbspatlik", tbspatlik, "tbspatlik[np]/F");
	tree->Branch("tbsovaq",	tbsovaq, "tbsovaq[np]/F");
	tree->Branch("g2d2", g2d2, "g2d2[np]/F");
	tree->Branch("goodn", goodn, "goodn[np]/I");
	tree->Branch("beta14", beta14, "beta14[np]/F");
	tree->Branch("beta14_40", beta14_40, "beta14_40[np]/F");
	tree->Branch("beta1", beta1, "beta1[np]/F");
	tree->Branch("beta2", beta2, "beta2[np]/F");
	tree->Branch("beta3", beta3, "beta3[np]/F");
	tree->Branch("beta4", beta4, "beta4[np]/F");
	tree->Branch("beta5", beta5, "beta5[np]/F");
	tree->Branch("px", &px, "px/F");
	tree->Branch("py", &py, "py/F");
	tree->Branch("pz", &pz, "pz/F");
	tree->Branch("npx", npx, "npx[np]/F");
	tree->Branch("npy", npy, "npy[np]/F");
	tree->Branch("npz", npz, "npz[np]/F");
	tree->Branch("dirx", &dirx, "dirx/F");
	tree->Branch("diry", &diry, "diry/F");
	tree->Branch("dirz", &dirz, "dirz/F");
	tree->Branch("ndirx", ndirx, "ndirx[np]/F");
	tree->Branch("ndiry", ndiry, "ndiry[np]/F");
	tree->Branch("ndirz", ndirz, "ndirz[np]/F");
	tree->Branch("summedWeight", summedWeight, "summedWeight[np]/F");
	tree->Branch("ip0", &ip0, "ip0/I");
	tree->Branch("nring", &nring, "nring/I");
	tree->Branch("evis", &evis, "evis/F");

	if(forTruth){
		tree->Branch("mctrue_nn", &mctrue_nn, "mctrue_nn/I");
		tree->Branch("realneutron",realneutron, "realneutron[np]/I");
	}
}