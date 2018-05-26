var SerialPort = require('serialport');
var port = new SerialPort('COM3', {
  baudRate: 9600
});



var distancia1 = 0;
var Sensor1Tmp = 0;
var Estado = 0;
var distancia2 = 0;
var Sensor2Tmp = 0;

port.on('data', function(data) {
 //console.log("Valor 1 " + distancia1 + " Valor 2 " + distancia2);
  for (var i = 0; i < data.length; i++) {
    switch (Estado) {
      case 0:
        if (data[i] == 100) {
          Estado = 1;
          Sensor1Tmp = 0;
        } else if (data[i] == 101) {
          Estado = 2;
          Sensor2Tmp = 0;
        }
        break;
      case 1:
        if (data[i] == 97) {
          distancia1 = Sensor1Tmp;
          Estado = 0;
          //console.log("El Valor es:" + Sensor1);
        } else {
          Sensor1Tmp = Sensor1Tmp * 10 + data[i];
        }
        break;
      case 2:
        if (data[i] == 99) {
          distancia2 = Sensor2Tmp;
          Estado = 0;
          //console.log("El Valor es:" + Sensor1);
        } else {

        Sensor2Tmp = Sensor2Tmp * 10 + data[i];



        }
        break;
    }

    var cantidad1 = new Array(100);
     var cantidad1 = [Sensor1Tmp];
  // cantidad1.unshift(Sensor1Tmp);
//  cantidad1.push(Sensor1Tmp);
    console.log(cantidad1);

    var cantida2 = new Array(100);
    var cantidad2 = [Sensor1Tmp];
    console.log(cantidad1);


    const Neurona = new brain.NeuralNetwork();

      Neurona.train([
        {input:{Sensor1Tmp}, output: {no_paso: 1}},
        {input:{Sensor1Tmp}, output: {paso: 1}},
      ]);








  }
});
