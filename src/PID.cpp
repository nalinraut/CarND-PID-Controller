#include "PID.h"
#include <algorithm>

using namespace std;

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_) {
  
  PID::Kp = Kp_;
  PID::Ki = Ki_;
  PID::Kd = Kd_;

  PID::p_error = 0.0;
  PID::d_error = 0.0;
  PID::i_error = 0.0;

  PID::prev_cte = 0.0;

  PID::count = 0;
  PID::error_sum = 0.0;
  PID::error_min = std::numeric_limits<double>::min();
  PID::error_max = std::numeric_limits<double>::max();



}

void PID::UpdateError(double cte) {
  
  PID::p_error = cte;
  PID::d_error = cte - PID::prev_cte;
  PID::i_error = PID::i_error + cte;

  PID::prev_cte =  cte;

  PID::error_sum = PID::error_sum + cte;
  PID::count++;

  if (cte > PID::error_max){ error_max= cte; }
  if (cte < PID::error_min){ error_min= cte; }


}

double PID::TotalError() {
  
  return -PID::p_error * PID::Kp  - PID::i_error*PID::Ki - PID::d_error*PID::Kd;  
}