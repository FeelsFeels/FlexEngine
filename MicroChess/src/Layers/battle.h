#pragma once

#include <FlexEngine.h>
using namespace FlexEngine;

namespace ChronoShift
{
  using MoveEffect = std::function<void(FlexECS::Entity& user, std::vector<FlexECS::Entity> targets)>;
  struct Move {
    std::string name;
    std::string description;
    int id;
    int cost;
    MoveEffect effect;

    static Move GetMoveFromID(int move_id);
    static std::unordered_map<int, Move> move_index;
  };

  enum BattleState {
    BS_PLAYER_TURN,   //waiting for player input
    BS_ENEMY_TURN,
    BS_MOVE_SELECTION,
    BS_MOVE_EXECUTION,//Animation playing
    BS_PROCESSING,    //Speed stack moving around, showing who's next
  };

  class BattleSystem {
  public:
    BattleSystem();
    ~BattleSystem();

    void AddCharacter(FlexECS::Entity character);
    void BeginBattle();
    void Process();
    void WaitForMove();
    void ExecuteMove();

    BattleState GetState() { return m_battle_state; };

  private:
    std::vector<FlexECS::Entity> m_characters;
    std::list<FlexECS::Entity> m_speedstack;

    BattleState m_battle_state;
  };

  class BattleLayer : public FlexEngine::Layer
  {
  public:
    BattleLayer() : Layer("Battle Layer") {}
    ~BattleLayer() = default;

    virtual void OnAttach() override;
    virtual void OnDetach() override;
    virtual void Update() override;

  private:
    void SetupBattle();

    BattleSystem m_battlesystem;
  };



}
