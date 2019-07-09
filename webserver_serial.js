const SerialPort = require('serialport');
var express = require('express');
var path = require('path');
var app = express();
var portNumber = 3000;



var https = require('https');
var fs = require('fs');
//var app = require('express')();
var options = {
key: fs.readFileSync('./public/ssl/server.key'),
cert: fs.readFileSync('./public/ssl/server.crt')
};

/*
app.get('index.html', function (req, res) {
      res.send('Hola Mundo!!! Estamos usando https.');
});

https.createServer(options, app).listen(3001, function () {
      console.log('Iniciado!');
});

*/


var server = https.createServer(options, app).listen(portNumber, function () {
  console.log('App listening on port '+portNumber+'!');
});
var io = require('socket.io').listen(server);




const port = new SerialPort('/dev/ttyACM0', { baudRate: 9600 });
//READLINE
const Readline = require('@serialport/parser-readline');
const parser = port.pipe(new Readline({ delimiter: '\n' }));

//SET PUBLIC
app.use(express.static('public'));

//GET DIRECTORY
app.get('/', function (req, res) {
  res.sendFile(path.join(__dirname+'/public/index.html'));
});

// Read the port data SERIAL
port.on("open", () => {
  console.log('serial port open');
});

parser.on('data', data => {
  console.log(':::::>>>arduino:', data);
});

//INIT IO CONECTION
io.on('connection', function(socket) {
  //SOCKET IO DIRECTION
  socket.on('direction', function(data) {
    console.log(data.direction);
    //SET DATA TO SERIAL PORT
    port.write(data.direction, (err) => {
		if (err) {
		  return console.log('Error on write: ', err.message);
		}
		console.log('message written');
	});
  });
});

