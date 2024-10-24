#include <cstdlib>
#include <iostream>
#include <fstream>
#include <getopt.h>
#include <cstring>
#include <cmath>
#include <iomanip>

#include "signal/signal.h"
#include "str2vec/str2vec.h"


// read info from .sig data file

using namespace std;

// print help
void help(){
  cout << "sig_info -- read info from .sig datafiles\n"
          "Usage: sig_info [options] <filename>\n"
          "Options:\n"
          " -h        -- write this help message and exit\n"
          " -H        -- human-friendly output\n"
          " -p <pars> -- comma- or space- separated parameters to be printed\n"
          "Parameters:\n"
          "    N     -- number of points\n"
          "    dt    -- time step\n"
          "    t0    -- relative time of the first sample\n"
          "    t0abs -- system time of trigger position\n"
          "    dtxN  -- time step times number of points\n"
  ;
}

int
main(int argc, char *argv[]){
  try {

    /* default values */
    std::vector<const char *> pars;
    bool hm = false;

    /* parse  options */
    opterr=0;
    while(1){
      int c = getopt(argc, argv, "+hHp:");
      if (c==-1) break;
      switch (c){
        case '?': throw Err() << "Unknown option: -" << (char)optopt;
        case ':': throw Err() << "No argument: -" << (char)optopt;
        case 'h': help(); return 0;
        case 'H': hm = true; break;
        case 'p': pars = str2cvec(optarg); break;
      }
    }
    argc-=optind;
    argv+=optind;
    optind=1;
    if (argc<1) { help(); return 0; }

    std::ifstream ff(argv[0]);
    Signal sig_h = read_signal_h(ff);
    argc-=-1;
    argv+=-1;

    if (pars.size()==0) throw Err() << "Parameters are not specified, use -p option\n";
    else if (hm) cout << "# Signal parameters:\n";
    for (int i=0; i<pars.size(); i++) {
      if      (strcasecmp(pars[i], "N")==0)     { if (hm) cout << "  points: "; cout << sig_h.points << "\n"; }
      else if (strcasecmp(pars[i], "dt")==0)    { if (hm) cout << "  dt: ";     cout << setprecision(8) << sig_h.dt << "\n"; }
      else if (strcasecmp(pars[i], "t0")==0)    { if (hm) cout << "  t0: ";     cout << sig_h.t0 << "\n"; }
      else if (strcasecmp(pars[i], "t0abs")==0) { if (hm) cout << "  t0abs: ";  cout << sig_h.t0abs_str << "\n"; }
      else if (strcasecmp(pars[i], "dtxN")==0)  { if (hm) cout << "  dtxN: ";   cout << sig_h.dt*sig_h.points << "\n"; }
      else if (strcasecmp(pars[i], "Nxdt")==0)  { if (hm) cout << "  Nxdt: ";   cout << sig_h.dt*sig_h.points << "\n"; }
      else throw Err() << "Unknown parameter: " << pars[i];
    }
  }
  catch (Err E){
    std::cerr << E.str() << "\n";
  }
}
