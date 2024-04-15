#include "uuid.h"

#include <random>

namespace FlexEngine
{

  static std::random_device s_RandomDevice;
  static std::mt19937_64 s_Engine(s_RandomDevice());
  static std::uniform_int_distribution<unsigned long long> s_UniformDistribution;

  UUID UUID::Generate()
  {
    return s_UniformDistribution(s_Engine);
  }

  UUID::UUID()
    : m_value(0)
  {
  }

  UUID::UUID(unsigned long long value)
    : m_value(value)
  {
  }

  UUID::UUID(const UUID& other)
    : m_value(other.m_value)
  {
  }

  UUID& UUID::operator=(const UUID& other)
  {
    m_value = other.m_value;
    return *this;
  }

  UUID::operator unsigned long long() const
  {
    return m_value;
  }

  unsigned long long UUID::Get() const
  {
    return m_value;
  }

  void UUID::Set(unsigned long long value)
  {
    m_value = value;
  }

  bool UUID::operator==(const UUID& other) const
  {
    return m_value == other.m_value;
  }

  bool UUID::operator!=(const UUID& other) const
  {
    return m_value != other.m_value;
  }

  bool UUID::operator<(const UUID& other) const
  {
    return m_value < other.m_value;
  }

  bool UUID::operator>(const UUID& other) const
  {
    return m_value > other.m_value;
  }

}