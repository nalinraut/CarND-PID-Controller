# CarND-Controls-PID

[image1]: ./assets/pid.gif "PID implemented with the Sim"


![alt text][image1]
---

## PID Controller
The Proportional Integral Derivative controller is a very basic yet  a highly robust controller used
in large number of control systems. Here, the proportional value controls how much proportional effort will be applied to correct the error at that instance. 

![pid-controller](./assets/pid.png)


### P controller
The output signal is proportional to the input signal or the error in this case.
`u = Kp*e`. P controllers tend to oscillate and do not converge to a value. These are marginally stable. It was used to steer the car along the center using the cross track error. With only P-controller the car overshoots beyond the drivable path.

### PD controller
The output signal consists of a derivative term of the input signal in addition to the proportional term of the error.
To make the controller converge faster, derivative of error is used with the P controller. 
PD Controllers `u = Kp*e + Kd*(de/dt)`. In this case, the derivative is used to eliminate the accumulated error on the integral. If the actions are too fast, it will keep it under-control.


### PID Controller
For and controller, the step response needs to converge in 2% to 5% of the error margin. 
It is difficult to tune PD Controllers to such a precision. By summing up the errors over time,
the oscillations are damped to make the signal converge in the given error margin. Here, The tntegral factor was added to make the recovery operations smoother. It assures no osscilations of the car and that the car converges to desired path smoothly.


## Tuning PID Controller

First Kp was selected with observable overshoots by the car from the drivable path. To avoid overshooting Kd was tuned following which the car performed lapses without overshooting. Then the Ki was tuned without significant improvements in the convergence of the car to the drivable path. 

|Controller | Kp  | Ki | Kd |
|---|---|---|---|
|Steering| 0.08  | 0.0004  | 3.0  |



## Basic Build Instructions

1. Clone this repo.
2. Make a build directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./pid`. 

