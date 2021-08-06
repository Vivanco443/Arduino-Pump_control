# Arduino-Pump_control
In this proyect I control a water Pump of an establishment

The context

We have here an establishment that is located in a semi-rural town where somedays they get waterflow from the street and some other days they don´t. Everyday in morning they open the valve that closes the flow of water from the street and fill their no.1 tank or tinaco (they have two) the one that is located on the floor. Then when the tank no.1 is fill enough they start up a water pump that flows water three floors up, when they see water falling down of the no.2 tank they turn off the water pump and use water. They operate this way because the water flow from the street isn't enough to fill the up one tank directly.

Solution

We set some sensors in both water tanks, one at the top and one at the bothom but not so down, this way we'll know when water is about to finish and tun on or turn off the pump, in some cases, to close the valve. So, we have 4 sensors and 3 actuators 

SAT0    //  High Sensor, tank 0
SBT0    //  Low Sensor, tank 0
SAT1    //  High Sensor, tank 1
SBT1    //  Low Sensor, tank 1

EB 3    //  enable pump
EV1 4   //  enable valve 1
EV0 5   //  enable valve 0


On the last commit we have in the code, the propose was to set a mechanical valve between the waterflow entrance and the first tank, the lower one. Because of that we don´t have 2 elctrovalves anymore, otherwise just one now (the one that is between the first tank and the pump), we don´t need two sensors in the low tank, only the lower one.

our new map is the next one

SBT0    //  Low Sensor, tank 0
SAT1    //  High Sensor, tank 1
SBT1    //  Low Sensor, tank 1

EB 3    //  enable pump
EV1 4   //  enable valve 1
