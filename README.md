# project5-virtual-temperature-sensor-on-the-Arduino-board
This project is an implementation of a virtual temperature sensor on an Arduino board. It involves using voltage and current measurements to predict battery temperature instead of directly measuring it with a physical sensor.

Project Overview:

The project aims to predict the battery temperature based on environmental data without additional hardware sensors.
Uses voltage and current as input to estimate the temperature.
Dataset Description:

The dataset contains voltage values (3.873V - 4.2V), current values (-1.51A to 0.002A), and environmental temperature (24°C).
Model Training:

The data is split into 80% for training and 20% for testing.
Data normalization is performed before training.
Regression & Neural Network Models.

The trained neural network is converted to parameters (w and b values).
Random input values are generated and processed on the Arduino board.

Predicted temperatures range between 24°C to 27°C.
Some minor errors occur, but overall, the model performs well within this range.

The project successfully demonstrates temperature prediction using a neural network.
The Arduino board processes the model without needing additional temperature sensors.
The neural network is more accurate than linear regression and is chosen for implementation.
Team members
Raya Rezaie (401170575)
Amirmohammad Kooshky (40019673)
Mehrad Milanloo (99105775)
