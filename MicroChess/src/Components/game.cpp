#include "game.h"

namespace MicroChess
{

  FLX_REFL_REGISTER_START(IsWhite)
    FLX_REFL_REGISTER_PROPERTY(is_white)
  FLX_REFL_REGISTER_END;

  FLX_REFL_REGISTER_START(Board)
    FLX_REFL_REGISTER_PROPERTY(size)
  FLX_REFL_REGISTER_END;

  FLX_REFL_REGISTER_START(BoardTile)
  FLX_REFL_REGISTER_END;

  FLX_REFL_REGISTER_START(PiecePosition)
    FLX_REFL_REGISTER_PROPERTY(position)
  FLX_REFL_REGISTER_END;

  FLX_REFL_REGISTER_START(PieceType)
    FLX_REFL_REGISTER_PROPERTY(type)
  FLX_REFL_REGISTER_END;

  FLX_REFL_REGISTER_START(PieceStatus)
    FLX_REFL_REGISTER_PROPERTY(is_hovered)
    FLX_REFL_REGISTER_PROPERTY(is_dragged)
  FLX_REFL_REGISTER_END;

}