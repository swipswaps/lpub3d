/****************************************************************************
**
** Copyright (C) 2019 - 2020 Trevor SANDY. All rights reserved.
**
** This file may be used under the terms of the GNU General Public
** License version 2.0 as published by the Free Software Foundation
** and appearing in the file LICENSE.GPL included in the packaging of
** this file.  Please review the following information to ensure GNU
** General Public Licensing requirements will be met:
** http://www.trolltech.com/products/qt/opensource.html
**
** This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
** WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
**
****************************************************************************/

/****************************************************************************
 *
 * This class provides the options object passed between LPub3D, the Native
 * renderer and the 3DViewer.
 *
 * Please see lpub.h for an overall description of how the files in LPub
 * make up the LPub program.
 *
 ***************************************************************************/

#ifndef OPTIONS_H
#define OPTIONS_H

#include <QString>
#include <QStringList>

namespace Options
{
    enum Mt { PLI, CSI ,SMP};
}

class ViewerOptions
{

public:
  ViewerOptions()
  {
    ImageType      = Options::CSI;
    UsingViewpoint = false;
    ImageWidth     = 800 ;
    ImageHeight    = 600;
  }
  QString ViewerCsiKey;
  Options::Mt ImageType;
  QString ImageFileName;
  int ImageWidth;
  int ImageHeight;
  float CameraDistance;
  float FoV;
  float ZNear;
  float ZFar;
  float Latitude;
  float Longitude;
  bool UsingViewpoint;
};

class NativeOptions
{
public:
  NativeOptions()
  {
    ImageType         = Options::CSI;
    TransBackground   = true;
    HighlightNewParts = false;
    UsingViewpoint    = false;
    LineWidth         = 1.0;
    ExportMode        = -1; //NONE
    IniFlag           = -1; //NONE
  }
  QStringList ExportArgs;
  QString InputFileName;
  QString OutputFileName;
  QString ExportFileName;
  Options::Mt ImageType;
  int ExportMode;
  int IniFlag;
  float ImageWidth;
  float ImageHeight;
  float FoV;
  float ZNear;
  float ZFar;
  float Latitude;
  float Longitude;
  float CameraDistance;
  float LineWidth;
  bool HighlightNewParts;
  bool TransBackground;
  bool UsingViewpoint;
};

class Meta;
class Where;
class PgSizeData;
class PliPartGroupMeta;

class FindPageOptions
{

public:
    FindPageOptions(
            int             &_pageNum,
            Where           &_current,
            PgSizeData      &_pageSize,

            bool             _isMirrored,
            bool             _printing,
            int              _contStepNumber,
            int              _renderStepNumber  = 0,
            QString          _renderParentModel = "")
        :
          pageNum           (_pageNum),
          current           (_current),
          pageSize          (_pageSize),

          isMirrored        (_isMirrored),
          printing          (_printing),
          contStepNumber    (_contStepNumber),
          renderStepNumber  (_renderStepNumber),
          renderParentModel (_renderParentModel)
    {  }
    int           &pageNum;
    Where         &current;
    PgSizeData    &pageSize;

    bool           isMirrored;
    bool           printing;
    int            contStepNumber;
    int            renderStepNumber;
    QString        renderParentModel;
};

class DrawPageOptions
{

public:
    DrawPageOptions(
            Where                       &_current,
            QStringList                 &_csiParts,
            QStringList                 &_pliParts,
            QStringList                 &_bfxParts,
            QStringList                 &_ldrStepFiles,
            QStringList                 &_csiKeys,
            QHash<QString, QStringList> &_bfx,
            QList<PliPartGroupMeta>     &_pliPartGroups,

            int                          _stepNum,
            int                          _groupStepNumber,
            bool                         _isMirrored,
            bool                         _printing,
            bool                         _bfxStore2,
            bool                         _assembledCallout = false,
            bool                         _calledOut        = false)
        :
          current                       (_current),
          csiParts                      (_csiParts),
          pliParts                      (_pliParts),
          bfxParts                      (_bfxParts),
          ldrStepFiles                  (_ldrStepFiles),
          csiKeys                       (_csiKeys),
          bfx                           (_bfx),
          pliPartGroups                 (_pliPartGroups),

          stepNum                       (_stepNum),
          groupStepNumber               (_groupStepNumber),
          isMirrored                    (_isMirrored),
          printing                      (_printing),
          bfxStore2                     (_bfxStore2),
          assembledCallout              (_assembledCallout),
          calledOut                     (_calledOut)
    {  }
    Where                       &current;
    QStringList                 &csiParts;
    QStringList                 &pliParts;
    QStringList                 &bfxParts;
    QStringList                 &ldrStepFiles;
    QStringList                 &csiKeys;
    QHash<QString, QStringList> &bfx;
    QList<PliPartGroupMeta>     &pliPartGroups;

    int                          stepNum;
    int                          groupStepNumber;
    bool                         isMirrored;
    bool                         printing;
    bool                         bfxStore2;
    bool                         assembledCallout;
    bool                         calledOut;
};

#endif // OPTIONS_H
