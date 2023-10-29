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
    rightServo.write(90); //This stops a 360 servo
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
    leftServo.write(90); //This stops a 360 servo
  }
}

void setupServos() {
  rightServo.attach(RIGHT_WHEEL_MOTOR_PIN);
  _rightServoControls._value = 0;
  leftServo.attach(LEFT_WHEEL_MOTOR_PIN);
  _leftServoControls._value = 0;
}
