#include "Board.h"

Board::Board(Graphics& gfx)
	:
	gfx(gfx)
{
}

void Board::DrawCell( const Location& loc, Color c)
{
	assert(loc.x >= 0);
	assert(loc.y >= 0);
	assert(loc.x < width);
	assert(loc.x < height);

	const int off_x = x + borderWidth + borderPadding;
	const int off_y = y + borderWidth + borderPadding;

	gfx.DrawRectDim((loc.x) * dimension + off_x + cellPadding , (loc.y) * dimension + off_y + cellPadding , dimension - 2* cellPadding, dimension -2 * cellPadding, c);
}

int Board::GetGridWidth() const
{
	return width;
}

int Board::GetGridHeight() const
{
	return height;
}

int Board::GetX() const
{
	return x;
}

int Board::GetY() const
{
	return y;
}

bool Board::IsInsideBoard(const Location& loc) const
{
	return loc.x >= 0 && loc.y >= 0 && loc.x < width && loc.y < height;
}

void Board::DrawBorder()
{
	const int top = y;
	const int left = x;
	const int bottom = top + borderWidth * 2 + borderPadding * 2 + (height) * dimension;
	const int right = left + borderWidth * 2 + borderPadding * 2 + (width ) * dimension;
	gfx.DrawRect(left, top, right, top + borderWidth, borderColor);
	gfx.DrawRect(left, top + borderWidth, left + borderWidth, bottom - borderWidth, borderColor);
	gfx.DrawRect(left, bottom - borderWidth, right, bottom, borderColor);
	gfx.DrawRect(right - borderWidth , top + borderWidth, right, bottom - borderWidth, borderColor);
}
