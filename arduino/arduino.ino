#include <Arduino.h>

float W1[3][6] = {{-1.3599201440811157, 0.4730043113231659, 0.4874628782272339, 0.34043213725090027, 0.7712751626968384, 0.5910599827766418}, {2.1320865154266357, -0.26845452189445496, -0.04886510223150253, -0.8880676031112671, 0.3371613323688507, -0.9551156759262085}, {-0.3573693037033081, 0.1448008418083191, -0.40796273946762085, 0.3013378381729126, 0.6755868196487427, 0.11438494920730591}};
float b1[6] = {2.945068359375, 2.1410326957702637, -0.26389631628990173, 2.271608352661133, 2.4415271282196045, 1.943440556526184};
float W2[6] = {2.1176624298095703, 2.2715976238250732, -0.41542890667915344, 1.6780105829238892, 2.148237466812134, 1.8572229146957397};
float b2 = 1.391572117805481;

float scaler_mean[3] = {4.187419504017744, 0.6434546691812421, 24.0};
float scaler_std[3] = {0.04576498913931391, 0.6254070302957698, 1.0};

float relu(float x) {
    return x > 0 ? x : 0;
}

float predict(float voltage, float current, float ambient_temp) {
    float input[3] = {voltage, current, ambient_temp};

    for (int i = 0; i < 3; i++) {
        input[i] = (input[i] - scaler_mean[i]) / scaler_std[i];
    }

    float hidden[6];
    for (int i = 0; i < 6; i++) {
        hidden[i] = b1[i];
        for (int j = 0; j < 3; j++) {
            hidden[i] += input[j] * W1[j][i];
        }
        hidden[i] = relu(hidden[i]);
    }

    float output = b2;
    for (int i = 0; i < 6; i++) {
        output += hidden[i] * W2[i];
    }

    return output;
}

void setup() {
    Serial.begin(9600);
    Serial.println("Arduino Neural Network Ready!");
}

const unsigned long updateInterval = 5000;
unsigned long previousMillis = 0;

float voltage, current, ambient_temp;

float randomFloat(float minVal, float maxVal) {
    return minVal + ((float)rand() / RAND_MAX) * (maxVal - minVal);
}

void updateValues() {
    voltage = randomFloat(3.873, 4.2);
    current = randomFloat(-0.001, 1.51);
    ambient_temp = randomFloat(24, 24);
}

void printValues() {
    Serial.print("Voltage: ");
    Serial.print(voltage);
    Serial.print(" | Current: ");
    Serial.print(current);
    Serial.print(" | Temperature: ");
    Serial.println(ambient_temp);
}

void loop() {
    unsigned long currentMillis = millis();
    if (currentMillis - previousMillis >= updateInterval) {
        previousMillis = currentMillis;
        
        updateValues();
        printValues();
        float predicted_temp = predict(voltage, current, ambient_temp);
    
    Serial.print("Predicted Temperature: ");
    Serial.println(predicted_temp, 6);
    }
}
