//Declare global constants
const servoVariableSendInterval = 50; //Milliseconds

//Declare global variables
var lastTimeBaseDataSent = new Date();

window.onload = () => {
  'use strict';

  if ('serviceWorker' in navigator) {
    navigator.serviceWorker
      .register('./sw.js');
  }
}

function sendData(data) {
  var xhttp = new XMLHttpRequest();
  xhttp.open("GET", data, true);
  xhttp.send();
}

function controlRobot(Direction) {
	sendData('data?' + Direction);
}