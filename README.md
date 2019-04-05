# CarND-Controls-PID

[image1]: ./assets/pid.gif "PID implemented with the Sim"


![alt text][image1]
---

## PID Controller
The Proportional Integral Derivative controller is a very basic yet  a highly robust controller used
in large number of control systems.

![pid-controller](./assets/pid.png)


### P controller
The output signal is proportional to the input signal or the error in this case.
`u = Kp*e`. P controllers tend to oscillate and do not converge to a value. These are marginally stable.

### PD controller
The output signal consists of a derivative term of the input signal in addition to the proportional term of the error.
To make the controller converge faster, derivative of error is used with the P controller. 
PD Controllers `u = Kp*e + Kd*(de/dt)` 


### PID Controller
For and controller, the step response needs to converge in 2% to 5% of the error margin. 
It is difficult to tune PD Controllers to such a precision. By summing up the errors over time,
the oscillations are damped to make the signal converge in the given error margin.


## Tuning PID Controller

|Controller | Kp  | Ki | Kd |
|---|---|---|---|
|Steering| 0.08  | 0.0004  | 3.0  |



## Basic Build Instructions

1. Clone this repo.
2. Make a build directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./pid`. 

