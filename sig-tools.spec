Name:         sig-tools
Version:      1.0
Release:      alt1

%define libname SigLoad
%define libver  1.0

Summary:      Tools for working with SIG data format
Group:        System
URL:          https://github.com/slazav/sig-tools
License:      GPL

Packager:     Vladislav Zavjalov <slazav@altlinux.org>

Source:       %name-%version.tar
BuildPreReq:   rpm-build-tcl
BuildRequires: libfftw3-devel libjansson-devel libpng-devel tcl-blt-devel
BuildRequires: libgsl-devel
Requires:      libfftw3 tcl-xblt

%description
sig-tools -- tools for working with SIG data format

%prep
%setup -q

%build
%make

%install
%makeinstall

%files
%_bindir/*
%_tcllibdir/sig_load.so
%add_findreq_skiplist %_tcllibdir/sig_load.so
%dir %_tcldatadir/%libname-%libver
%_tcldatadir/%libname-%libver/pkgIndex.tcl

%changelog
