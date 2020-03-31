#include "SudokuFrame.h"

SudokuFrame::SudokuFrame(const wxString& title)
    : wxFrame(nullptr, wxID_ANY, title)
{
    Connect(ID_Solve, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(SudokuFrame::OnSolve));

    outer = new wxBoxSizer(wxHORIZONTAL);

    grid = new wxGridSizer(9, 9, 0, 0);
    
    
    wxFont font;
    font.SetPointSize(20);

    for (int i = 0; i < grid->GetCols() * grid->GetRows(); ++i)
    {
        texts[i] = new wxTextCtrl(this, wxID_ANY);
        texts[i]->SetMaxSize(wxSize(40, 40));
        texts[i]->SetMaxLength(1);
        texts[i]->SetFont(font);
        grid->Add(texts[i], 0, wxEXPAND);
    }

    outer->Add(grid);

    //wxPanel* panel = new wxPanel(this);
    wxButton* solve = new wxButton(this, ID_Solve, wxT("Solve"));
    outer->Add(solve, 0, wxRIGHT);

    SetSizer(outer);
    SetMinSize(wxSize(300, 300));
    SetSize(wxSize(500, 500));

    Centre();
}

void SudokuFrame::setFromBoard(const SudokuBoard& board)
{
    size_t i = 0;
    for (const auto& row : board.getBoard())
    {
        for (const auto& item : row)
        {
            texts[i++]->SetValue(item != 0 ? wxString::Format(wxT("%d"), item) : wxEmptyString);
        }
    }
}

SudokuBoard SudokuFrame::getBoard() const
{
    board_t boardBase;
    size_t i = 0;
    for (auto& row : boardBase)
    {
        for (int& item : row)
        {
            long number;
            if (!texts[i++]->GetValue().ToLong(&number))
            {
                item = 0;
            }
            else
            {
                item = static_cast<int>(number);
            }
        }
    }
    return SudokuBoard(boardBase);
}

void SudokuFrame::OnSolve(wxCommandEvent& WXUNUSED(event))
{
    SudokuBoard board(getBoard());
    board.solve();
    setFromBoard(board);
}