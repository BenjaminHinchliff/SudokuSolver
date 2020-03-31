#ifndef SUDOKU_FRAME_H
#define SUDOKU_FRAME_H

#include <array>

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif
#include <wx/spinctrl.h>

#include "SudokuBoard.h"

class SudokuFrame : public wxFrame
{
public:
    SudokuFrame(const wxString& title);

    void setFromBoard(const SudokuBoard& board);
    SudokuBoard getBoard() const;

private:
    void OnSolve(wxCommandEvent& event);

    std::array<wxTextCtrl*, 81> texts = { nullptr };
    wxBoxSizer* outer = nullptr;
    wxGridSizer* grid = nullptr;
};

enum
{
    ID_Solve = 1
};

#endif // !SUDOKU_FRAME_H
