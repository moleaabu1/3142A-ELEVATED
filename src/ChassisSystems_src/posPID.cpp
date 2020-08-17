#include "ChassisSystems/posPID.h"

posPID::posPID() {}

posPID::posPID(double kP, double kD)
{
  m_kP = kP;
  m_kD = kD;
}

double posPID::calculatePower(double targetPos, double currentPos)
{
  m_kP = this->KP;
  m_kD = this->KD;
  m_error = targetPos - currentPos;

  m_derivative = m_error - m_prevError;

  m_power = (m_error * m_kP) + (m_derivative * m_kD);

  if (m_power > m_upperBound)
  {
    m_power = m_upperBound;
  }

  else if (m_power < m_lowerBound)
  {
    m_power = m_lowerBound;
  }
  m_prevError = m_error;
  return (m_power);
}
