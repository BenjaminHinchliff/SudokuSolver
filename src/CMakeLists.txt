set(TARGT "SudokuSolver")

set(HEADERS
	"SudokuApp.h"
	"SudokuFrame.h"
	"SudokuBoard.h")

set(SRC
	"SudokuApp.cpp"
	"SudokuFrame.cpp"
	"SudokuBoard.cpp")

add_executable(${TARGT} "${SRC}" "${HEADERS}")

SET(wxWidgets_ROOT_DIR "$ENV{WXWIN}")
find_package(wxWidgets REQUIRED core base)
include(${wxWidgets_USE_FILE})
target_link_libraries(${TARGT} ${wxWidgets_LIBRARIES})