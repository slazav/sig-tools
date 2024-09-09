

This is a fork of a https://github.com/slazav/pico_osc.git project written by V.Zavjalov.
As a part of the original project, this fork contains only tools for processing .sig format, all device-related programs were excluded, 
Further is an original Readme.md file with the above-mentioned modifications.


## sig-tools -- programs for processing oscilloscope signals

### Folders:

* sig_filter  -- Program for processing signals recorded in .sig format.

I'm using a simple custom format SIG for recording signals. It contains a
text header and binary data from oscilloscope. There is also SIGF
variant written in frequency domain (it is possible to reduce frequency
range and make files a lot smaller). Sig_filter program
does a lot of operations with signals.

* sig_pngfig  -- Working with PNG spectrograms with fig wrapper. It is possible
to convert sig file to a png spectrogram with additional information
about original time and frequency range; put it in a fig file (for xfig
vector editor), manually mark some features and then use sig_filter to extract
data from sig files using these marks.

* sig_viewer  -- TCL viewer for signal (and text) files

* sig_python  -- a simple python library for reading sig files

* signals     -- signal examples

* modules -- I'm using my mapsoft2 build system with local set of modules.
See https://github.com/slazav/mapsoft2-libs
