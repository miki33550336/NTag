#include <math.h>
#include <string.h>
#include <stdlib.h>

#include <TFile.h>

#include <skroot.h>
#undef MAXHWSK
#include <skheadC.h>
#include <sktqC.h>
#include <skvectC.h>

#include "NTagROOT.hh"
#include "SKLibs.hh"

NTagROOT::NTagROOT(const char* inFileName, const char* outFileName, unsigned int verbose)
: NTagIO(inFileName, outFileName, verbose) { Initialize(); }

NTagROOT::~NTagROOT() { bonsai_end_(); }

void NTagROOT::OpenFile()
{
    skroot_open_read_(&lun);
    skroot_set_input_file_(&lun, fInFileName, strlen(fInFileName));
    skroot_init_(&lun);
}

void NTagROOT::CloseFile()
{
    skroot_close_(&lun);
    skroot_end_();
}

void NTagROOT::SetFitInfo()
{
    SetLowFitInfo();
}