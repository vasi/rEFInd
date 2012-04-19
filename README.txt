Brief Installation Instructions (Binary Package)
================================================

This is rEFInd, an EFI boot manager. The binary package includes the
following files and subdirectories:

   File                             Description
   -----------------------------    -----------------------------
   refind/refind_ia32.efi           The main IA32 rEFInd binary
   refind/refind_x64.efi            The main x86-64 rEFInd binary
   refind/refind.conf-sample        A sample configuration file
   refind/icons/                    Subdirectory containing icons
   README.txt                       This file
   LICENSE.txt                      The original rEFIt license
   COPYING.txt                      The rEFInd license
   docs/                            Documentation in HTML format

To install the binary package, you must first access your EFI System
Partition (ESP). You can then place the files from the refind subdirectory
in a subdirectory of the ESP's EFI directory. You may omit the .efi binary
for the type of computer you're NOT using, and you may optionally rename
the .efi file for the binary you are using. If this is an initial
installation, you should rename refind.conf-sample to refind.conf; but if
you're replacing an existing installation, you should leave your existing
refind.conf intact. The end result might include the following files on the
ESP:

 EFI/refind/refind_x64.efi
 EFI/refind/refind.conf
 EFI/refind/icons/

Unfortunately, dropping the files in the ESP is not sufficient; as
described in the docs/installing.html file, you must also tell your EFI
about rEFInd. Precisely how to do this varies with your OS or, if you
choose to do it through the EFI, your EFI implementation. In some cases you
may need to rename the EFI/refind directory as EFI/boot, and rename
refind_x86.efi to bootx64.efi (or refind_ia32.efi to bootia32.efi on 32-bit
systems). Consult the installing.html file for full details.

Brief Installation Instructions (Source Package)
================================================

rEFInd source code can be obtained from
https://sourceforge.net/projects/refind/. Consult the BUILDING.txt file in
the source code package for build instructions. Once  you've built the
source code, you should duplicate the directory tree described above by
copying the individual files and the icons directory to the ESP. Note that
the binary file created by the build process will be called "refind.efi".
You can use that name or rename it to include your architecture code, as
you see fit.
