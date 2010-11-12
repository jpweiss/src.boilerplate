%define major 0
%define minor 0
%define revision 0

Name: @rpm_package@
Summary: @summary@
Version: %{major}.%{minor}.%{revision}
## FIXME::[jpw] Alt:
#Version: @version@
Release: 1
## FIXME::[jpw] Alt:
#Release: 1jpw
Source: http://@master_server@/get/@package@-%{version}.tgz
URL: http://@master_server@/
##%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
## FIXME::[jpw] If you use this file with Autoconf, remove the block
## above and uncomment the following:
#Name: @rpm_package@
#Summary: @summary@
#Version: @PACKAGE_VERSION@
#Release: 1
#Source: @PACKAGE_URL@/files/v%{version}/@PACKAGE_TARNAME@-%{version}.tgz
#URL: @PACKAGE_URL@
##%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
License: @release_license@
Group: Development/Libraries
#Provides: @providesym@
#Requires: @reqname@


BuildRoot: %{_tmppath}/%{name}-buildroot
BuildArchitectures: @arch@
#BuildRequires: @pkgname@

Prefix: %{_prefix}
#Docdir: @doc_dir@/@package@
## FIXME::[jpw] For use with Autoconf [next 2 lines]; you may not need the
## first one.
#Prefix: @prefix@
#Docdir: @docdir@
@extra_headers@

%description
@description@

%prep
rm -rf %{buildroot}/*
%setup


%build
echo BuildRoot=%{buildroot}
%configure
#%configure $LOCALFLAGS
%{__make}

%postun

%post

%install
%makeinstall 
## FIXME::[jpw] For use with Autoconf [if rpm fails to do the right thing]:
#%{__make} install DESTDIR=%{buildroot}

%clean
rm -rf %{buildroot}/*

%files
    %defattr(-,root,root)
    %doc @doc_files@
    %{_bindir}/*
    %{_mandir}/*

%changelog
* Sun Jan 1 2010 John Weiss <jpwcandide@sourceforge.net> %{version}-%{release}
- Adapted from the original package/tarball/whatever.
