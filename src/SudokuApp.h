#ifndef SUDOKU_APP_H
#define SUDOKU_APP_H

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

class SudokuApp : public wxApp
{
private:
    virtual bool OnInit();
};

#endif // !SUDOKU_APP_H
