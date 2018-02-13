# ![LPub3D-Icon][lpub3d-icon] LPub3D
An LDraw™ editor for LEGO® style digital building instructions.

|[![GitHub release][gh-rel-badge]][gh-rel-url]|[![Travis-CI build status][travis-badge]][travis-url]|[![AppVeyor build status][appveyor-badge]][appveyor-url]|[![GitHub top language][gh-top-lang-badge]][gh-top-lang-url]|
|:-|:-:|:-:|-:|
|[![SourceForge weekly downloads][sf-dw-badge]][sf-dw-badge-url]|[![SourceForge total downloads][sf-dt-badge]][sf-dt-badge-url]|[![GitHub total downloads][gh-dl-badge]][gh-dl-url]|[![Maintained status][maintained-badge]](README.md "Last edited 10-02-2018")|
|[![GitHub commits (since latest release)][gh-comm-since-badge]][gh-comm-since-url]|[![GitHub issues][gh-issue-badge]][gh-issue-url]|[![GitHub pull requests][gh-pull-req-badge]][gh-pull-req-url]|[![GitHub last commit][gh-lst-commit-badge]][gh-lst-commit-url]|

**LPub3D** is an Open Source WYSIWYG editing application for creating LEGO® style digital building instructions.
LPub3D is developed and maintained by Trevor SANDY. It uses the LDraw parts library, the most comprehensive
library of digital Open Source LEGO® bricks available (www.ldraw.org/ ) and reads the LDraw LDR and MPD model file formats.

LPub3D provides three popular LDraw image renderers - custom adapted for tight integration and robust performance.
 - [LDGLite][ldglite] - console application, fast image rendering
 - [LDView][ldview] - console application, feature rich rendering and pov file generation
 - [LPub3D-Trace (POV-Ray)][povray] - console application, high quality image and feature rich image rendering

Portions of LPub3D are based on LPUB© 2007-2009 Kevin Clague, LeoCAD© 2015 Leonardo Zide and additional third party components. See [Credits][credits] for full details on contributing content.

### Screenshots

{% include slider.html selector="slider1" %}

### Compatibility
LPub3D runs on Debian, Red Hat and Arch derived Linux distros, macOS and Windows Operating Systems.
LPub3D is also available as a Linux 'no-install', multi-platform [AppImage][appimage-info-url].

### Downloads
 - [GitHub Releases][githubreleases]
 - [Sourceforge Releases][sfreleases]
 - [Open Build Service Releases][obsreleases] - Linux distributions

 {% include obs-linux-distributions.html %}

 macOS, Windows and AppImage distributions

 |[![Macos-Icon][macos-icon]][macos-url]||[![Windows-Icon][windows-icon]][windows-url]|[![Appimage-Icon][appimage-icon]][appimage-url]|

 - Click icon above to download distribution asset.

### Quick Links
 - [Build and package LPub3D from source][buildfromsource]
 - [Change log][changelog]
 - [Credits][credits]

### License
LPub3D is available for free under the [GNU Public License version 3.0 (GPLv3)][copying].

### Disclaimer
LEGO® is a trademark of the LEGO Group of companies which does not sponsor, authorize or endorse this application.

### Features
 - Integrated 3D Viewer powered by LeoCAD
 - Integrated image renderers (LDGlite, LDView and POV-Ray) - no more additional installs
 - Renderer config files accessible from the LPub3D user interface
 - Custom LDraw library LDConfig (part material) file can be passed to LDGlite and LDView renderers
 - Set ROTSTEP (step rotation) meta using 3D Viewer
 - Fade previous step's parts (Fadestep)
 - Unlimited part list (PLI) annotations
 - Split the BOM (divide parts over number of BOM occurrences)
 - Sort PLI/BOM by part size, colour and category
 - "Go To" page navigation and submodel display via drop-down dialogue
 - Automatically generate formatted cover pages
 - POV-Ray high-quality rendered instructions
 - LGEO high-quality rendering library support and auto detection
 - Customizable content page header and footer
 - Text and picture (e.g. logo) front and back page attributes
 - Print/Export preview
 - PDF, PNG, JPG and BMP export formats
 - Standard and custom page size options
 - On demand, software and LDraw archive library updates
 - All features from legacy LPub - enhanced and stabilized
 - Linux, Linux AppImage, macOS and Microsoft Windows distributions
 - Windows automated installer and portable distributions available
 - Full capabilities to [build and package from source][buildfromsource] or Cloud Continuous Integration Service
 - Automated build and deploy from Cloud CI Service: [Travis-CI][travis-url], [AppVeyor][appveyor-url] and [Open Build Service][obs-url]
 - [Docker][dockerinstall] container builds using [Docker Compose][dockercomposefile] available for [Arch][dockerarch], [Xenial][dockerxenial] and [Fedora 25][dockerfedora] Linux distros

[lpub3d-icon]:         https://raw.githubusercontent.com/trevorsandy/lpub3d/master/mainApp/images/lpub3d128.png

[appimage-icon]:       https://raw.githubusercontent.com/trevorsandy/lpub3d/master/builds/utilities/icons/appimage.png
[macos-icon]:          https://raw.githubusercontent.com/trevorsandy/lpub3d/master/builds/utilities/icons/macos.png
[windows-icon]:        https://raw.githubusercontent.com/trevorsandy/lpub3d/master/builds/utilities/icons/windows.png

[appimage-url]:        https://github.com/trevorsandy/lpub3d/releases/download/v2.1.0/LPub3D-2.1.0.0.775_20180213-x86_64.AppImage
[macos-url]:           https://github.com/trevorsandy/lpub3d/releases/download/v2.1.0/LPub3D-2.1.0.0.775_20180213-macos.dmg
[windows-url]:         https://github.com/trevorsandy/lpub3d/releases/download/v2.1.0/LPub3D-2.1.0.0.775_20180213.exe

[changelog]:           https://github.com/trevorsandy/lpub3d/blob/master/mainApp/docs/README.txt
[credits]:             https://github.com/trevorsandy/lpub3d/blob/master/mainApp/docs/CREDITS.txt
[copying]:             https://github.com/trevorsandy/lpub3d/blob/master/mainApp/docs/COPYING.txt
[buildfromsource]:     https://github.com/trevorsandy/lpub3d/blob/master/builds/utilities/README.md

[ldglite]:             https://github.com/trevorsandy/ldglite
[ldview]:              https://github.com/trevorsandy/ldview
[povray]:              https://github.com/trevorsandy/povray

[sfreleases]:          https://sourceforge.net/projects/lpub3d/files/2.1.0/
[githubreleases]:      https://github.com/trevorsandy/lpub3d/releases
[obsreleases]:         https://software.opensuse.org/download.html?project=home:trevorsandy&package=lpub3d
[travis-badge]:        https://img.shields.io/travis/trevorsandy/lpub3d.svg?label=travis
[travis-url]:          https://travis-ci.org/trevorsandy/lpub3d

[appveyor-badge]:      https://img.shields.io/appveyor/ci/trevorsandy/lpub3d.svg?label=appveyor
[appveyor-url]:        https://ci.appveyor.com/project/trevorsandy/lpub3d

[gh-rel-badge]:        https://img.shields.io/github/release/trevorsandy/lpub3d.svg
[gh-rel-url]:          https://github.com/trevorsandy/lpub3d/releases/latest

[gh-dl-badge]:         https://img.shields.io/github/downloads/trevorsandy/lpub3d/total.svg
[gh-dl-url]:           https://github.com/trevorsandy/lpub3d/releases/latest

[gh-issue-badge]:      https://img.shields.io/github/issues/trevorsandy/lpub3d.svg
[gh-issue-url]:        https://github.com/trevorsandy/lpub3d/issues

[gh-pull-req-badge]:   https://img.shields.io/github/issues-pr/trevorsandy/lpub3d.svg
[gh-pull-req-url]:     https://github.com/trevorsandy/lpub3d/pulls

[gh-lst-commit-badge]: https://img.shields.io/github/last-commit/trevorsandy/lpub3d.svg
[gh-lst-commit-url]:   https://github.com/trevorsandy/lpub3d/commits/master

[gh-top-lang-badge]:   https://img.shields.io/github/languages/top/trevorsandy/lpub3d.svg
[gh-top-lang-url]:     https://github.com/trevorsandy/lpub3d

[gh-comm-since-badge]: https://img.shields.io/github/commits-since/trevorsandy/lpub3d/latest.svg
[gh-comm-since-url]:   https://github.com/trevorsandy/lpub3d/commits/master

[sf-dw-badge]:         https://img.shields.io/sourceforge/dw/lpub3d.svg
[sf-dw-badge-url]:     https://sourceforge.net/projects/lpub3d

[sf-dt-badge]:         https://img.shields.io/sourceforge/dt/lpub3d.svg
[sf-dt-badge-url]:     https://sourceforge.net/projects/lpub3d

[maintained-badge]:    https://img.shields.io/maintenance/yes/2018.svg

[appimage-info-url]:   https://appimage.org/
[obs-url]:             https://build.opensuse.org/package/show/home:trevorsandy/lpub3d
[dockerinstall]:       https://www.docker.com/get-docker
[dockercomposefile]:   https://github.com/trevorsandy/lpub3d/blob/master/builds/linux/docker-compose/docker-compose-cibuild-linux.yml
[dockerarch]:          https://github.com/trevorsandy/lpub3d/blob/master/builds/linux/docker-compose/dockerfiles/Dockerfile-cibuild-archlinux
[dockerxenial]:        https://github.com/trevorsandy/lpub3d/blob/master/builds/linux/docker-compose/dockerfiles/Dockerfile-cibuild-ubuntu_xenial
[dockerfedora]:        https://github.com/trevorsandy/lpub3d/blob/master/builds/linux/docker-compose/dockerfiles/Dockerfile-cibuild-fedora_25

Copyright (c) 2015 - 2018 by Trevor SANDY