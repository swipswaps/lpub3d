/****************************************************************************
**
** Copyright (C) 2007-2009 Kevin Clague. All rights reserved.
** Copyright (C) 2015 - 2019 Trevor SANDY. All rights reserved.
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
 * The editwindow is used to display the LDraw file to the user.  The Gui
 * portion of the program (see lpub.h) decides what files and line numbers
 * are displayed.  The edit window has as little responsibility as is
 * possible.  It does work the the syntax highlighter implemented in
 * highlighter.(h,cpp)
 *
 * Please see lpub.h for an overall description of how the files in LPub
 * make up the LPub program.
 *
 ***************************************************************************/

#ifndef EDITWINDOW_H
#define EDITWINDOW_H

#include <QMainWindow>
#include <QTextCursor>
#include <QTextEdit>
#include <QLineEdit>
#include <QGridLayout>
#include <QPushButton>

#include <QDialog>
#include <QLabel>

class QTextEdit;
class LDrawFile;
class Highlighter;
class QString;
class QAction;
class QMenu;

class QPaintEvent;
class QResizeEvent;
class QSize;


class QLineNumberArea;
class QTextEditor;
class QCheckBox;
class QFindReplace;
class QFindReplaceCtrls;

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
class EditWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit EditWindow(QMainWindow *parent = nullptr);
    QToolBar *editToolBar;

protected:

private:
    void createActions();
    void createMenus();
    void createToolBars();

    QTextEditor  *_textEdit;
    Highlighter  *highlighter;
    QString       fileName;    // of file currently being displayed

    QMenu    *editMenu;
    QAction  *topAct;
    QAction  *bottomAct;
    QAction  *cutAct;
    QAction  *copyAct;
    QAction  *pasteAct;
    QAction  *redrawAct;
    QAction  *updateAct;
    QAction  *delAct;
    QAction  *selAllAct;
    QAction  *findAct;

signals:
    void contentsChange(const QString &, int position, int charsRemoved, const QString &charsAdded);
    void redrawSig();
    void updateSig();

private slots:
    void contentsChange(int position, int charsRemoved, int charsAdded);
    // Maybe this helps resizing the editwindow (Jaco)
    void redraw();
    void update();
    void highlightCurrentLine();
    void topOfDocument();
    void bottomOfDocument();
    void showContextMenu(const QPoint &pt);

public slots:
    void displayFile(LDrawFile *, const QString &fileName);
    void showLine(int);
    void updateDisabled(bool);
    void disableActions();
    void pageUpDown(
      QTextCursor::MoveOperation op,
      QTextCursor::MoveMode      moveMode);

public:
    QTextEditor *textEdit() { return _textEdit; }
};

extern class EditWindow *editWindow;
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

class QTextEditor : public QTextEdit
{
    Q_OBJECT

public:
    explicit QTextEditor(QWidget *parent = nullptr);

    void lineNumberAreaPaintEvent(QPaintEvent *event);
    int getFirstVisibleBlockId();
    int lineNumberAreaWidth();
    QFindReplace *popUp;

public slots:
    void resizeEvent(QResizeEvent *e);

private slots:
    void updateLineNumberAreaWidth(int newBlockCount);
    void updateLineNumberArea(QRectF /*rect_f*/);
    void updateLineNumberArea(int /*slider_pos*/);
    void updateLineNumberArea(); 
    void findDialog();
    void showCharacters(
         QString findString,
         QString replaceString);

private:

    QWidget *lineNumberArea;

};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
class QLineNumberArea : public QWidget
{
public:
    QLineNumberArea(QTextEditor *editor) : QWidget(editor) {
        textEditor = editor;}

    QSize sizeHint() const {
        return QSize(textEditor->lineNumberAreaWidth(), 0);
    }

protected:
    void paintEvent(QPaintEvent *event){
        textEditor->lineNumberAreaPaintEvent(event);
    }

private:
    QTextEditor *textEditor;
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
class QFindReplace : public QDialog
{
    Q_OBJECT

public:
    explicit QFindReplace(QTextEditor *textEdit, const QString &selectedText, QWidget *parent = nullptr);

protected slots:
    void popUpClose();

protected:
    QFindReplaceCtrls *find;
    QFindReplaceCtrls *findReplace;
    void readFindReplaceSettings(QFindReplaceCtrls *fr);
    void writeFindReplaceSettings(QFindReplaceCtrls *fr);
};

class QFindReplaceCtrls : public QWidget
{
    Q_OBJECT

public:
    explicit QFindReplaceCtrls(QTextEditor *textEdit, QWidget *parent = nullptr);
    QTextEditor *_textEdit;
    QLineEdit   *textFind;
    QLineEdit   *textReplace;
    QLabel      *labelMessage;

    QPushButton *buttonFind;
    QPushButton *buttonFindNext;
    QPushButton *buttonFindPrevious;
    QPushButton *buttonFindAll;
    QPushButton *buttonFindClear;

    QPushButton *buttonReplace;
    QPushButton *buttonReplaceAndFind;
    QPushButton *buttonReplaceAll;
    QPushButton *buttonReplaceClear;

    QLabel      *label;

    QCheckBox   *checkboxCase;
    QCheckBox   *checkboxWord;
    QCheckBox   *checkboxRegExp;

    QPushButton *buttonCancel;
    bool        _findall;

public slots:
    void find(int direction = 0);

signals:
    void popUpClose();

protected slots:
    void findInText();
    void findInTextNext();
    void findInTextPrevious();
    void findInTextAll();

    void findClear();

    void replaceInText();
    void replaceInTextFind();
    void replaceInTextAll();

    void replaceClear();

    void textFindChanged();
    void textReplaceChanged();
    void validateRegExp(const QString &text);
    void regexpSelected(bool sel);

protected:
    void disableButtons();
    void showError(const QString &error);
    void showMessage(const QString &message);
};

#endif
