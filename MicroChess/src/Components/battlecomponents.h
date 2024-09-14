#pragma once
#include <FlexEngine.h>
using namespace FlexEngine;

namespace ChronoShift
{
  //The Queued action (intent) of the character
  class Action
  { FLX_REFL_SERIALIZABLE
  public:
    int id;   //id of move
    FlexECS::EntityID target;
  };

  class MoveList 
  { FLX_REFL_SERIALIZABLE
  public:
    std::vector<int> move_list;
    //MoveList action_list;
  };

  class CharacterName 
  { FLX_REFL_SERIALIZABLE
  public:
    FlexECS::Scene::StringIndex character_name;
  };

  class CharacterHealth 
  { FLX_REFL_SERIALIZABLE
  public:
    int health;
  };

  class CharacterSpeed
  { FLX_REFL_SERIALIZABLE
  public:
    int current_speed;
    int base_speed;
  };

  class IsPlayer 
  { FLX_REFL_SERIALIZABLE
  public:
    bool is_player = true;
  };

}
