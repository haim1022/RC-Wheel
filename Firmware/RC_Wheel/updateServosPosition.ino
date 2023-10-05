void updateServosPosition() {
  //Right servo
  if(_rightServoControls._value != 0) {
    if(_rightServoControls._value > 0) {
      rightServo.write(0);
    }
    else {
      rightServo.write(180);
    }
  }
  else {
    digitalWrite(RIGHT_WHEEL_MOTOR_PIN, HIGH); //This stops a faulty servo
  }
  //Left servo
  if(_leftServoControls._value != 0) {
    if(_leftServoControls._value > 0) {
      leftServo.write(0);
    }
    else {
      leftServo.write(180);
    }
  }
  else {
    digitalWrite(LEFT_WHEEL_MOTOR_PIN, HIGH); //This stops a faulty servo
  }
}

void setupServos() {
  rightServo.attach(RIGHT_WHEEL_MOTOR_PIN);
  _rightServoControls._value = 0;
  leftServo.attach(LEFT_WHEEL_MOTOR_PIN);
  _leftServoControls._value = 0;
}
